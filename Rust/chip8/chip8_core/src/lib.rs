use rand::random;

const FONTSET_SIZE: usize = 80;

const FONTSET: [u8; FONTSET_SIZE] = [
    0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
    0x20, 0x60, 0x20, 0x20, 0x70, // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
    0x90, 0x90, 0xF0, 0x10, 0x10, // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
    0xF0, 0x10, 0x20, 0x40, 0x40, // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90, // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
    0xF0, 0x80, 0x80, 0x80, 0xF0, // C
    0xE0, 0x90, 0x90, 0x90, 0xE0, // D
    0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
    0xF0, 0x80, 0xF0, 0x80, 0x80, // F
];

pub const SCREEN_WIDTH: usize = 64;
pub const SCREEN_HEIGHT: usize = 32;

const RAM_SIZE: usize = 4096;
const NUM_REGS: usize = 16;
const STACK_SIZE: usize = 16;
const NUM_KEYS: usize = 16;

const START_ADDR: u16 = 0x200; // pc starts at address 0x200 (512 bytes offset)

pub struct Emulator {
    pc: u16, // program counter
    ram: [u8; RAM_SIZE],
    screen: [bool; SCREEN_WIDTH * SCREEN_HEIGHT],
    v_reg: [u8; NUM_REGS], // general purpose registers
    i_reg: u16,            // register for indexing into RAM
    sp: u16,               // stack pointer
    stack: [u16; STACK_SIZE],
    keys: [bool; NUM_KEYS],
    dt: u8, //delay timer
    st: u8, // sound timer
}

impl Emulator {
    pub fn new() -> Self {
        let mut new_emu = Self {
            pc: START_ADDR,
            ram: [0; RAM_SIZE],
            screen: [false; SCREEN_WIDTH * SCREEN_HEIGHT],
            v_reg: [0; NUM_REGS],
            i_reg: 0,
            sp: 0,
            stack: [0; STACK_SIZE],
            keys: [false; NUM_KEYS],
            dt: 0,
            st: 0,
        };
        new_emu.ram[..FONTSET_SIZE].copy_from_slice(&FONTSET);
        new_emu
    }

    pub fn reset(&mut self) {
        self.pc = START_ADDR;
        self.ram = [0; RAM_SIZE];
        self.screen = [false; SCREEN_WIDTH * SCREEN_HEIGHT];
        self.v_reg = [0; NUM_REGS];
        self.i_reg = 0;
        self.sp = 0;
        self.stack = [0; STACK_SIZE];
        self.keys = [false; NUM_KEYS];
        self.dt = 0;
        self.st = 0;
        self.ram[..FONTSET_SIZE].copy_from_slice(&FONTSET);
    }

    pub fn tick(&mut self) {
        let op = self.fetch(); // fetch
        self.execute(op);
    }

    pub fn tick_timers(&mut self) {
        if self.dt > 0 {
            self.dt -= 1;
        }

        if self.st > 0 {
            if self.st == 1 {
                //BEEP
            }
            self.st -= 1;
        }
    }

    fn push(&mut self, val: u16) {
        self.stack[self.sp as usize] = val;
        self.sp += 1;
    }

    fn pop(&mut self) -> u16 {
        self.sp -= 1;
        self.stack[self.sp as usize]
    }

    fn fetch(&mut self) -> u16 {
        let higher_byte = self.ram[self.pc as usize] as u16;
        let lower_byte = self.ram[(self.pc + 1) as usize] as u16;
        let op = (higher_byte << 8) | lower_byte;

        self.pc += 2;
        op
    }

    fn execute(&mut self, op: u16) {
        let nibbles = (
            ((op & 0xF000) >> 12) as u8,
            ((op & 0x0F00) >> 8) as u8,
            ((op & 0x00F0) >> 4) as u8,
            (op & 0x000F) as u8,
        );

        match nibbles {
            /* NOP */ (0, 0, 0, 0) => return,
            /* CLS */
            (0, 0, 0xE, 0) => self.screen = [false; SCREEN_WIDTH * SCREEN_HEIGHT],
            /* RET */
            (0, 0, 0xE, 0xE) => {
                let ret_addr = self.pop();
                self.pc = ret_addr;
            }
            /* JMP */
            (1, _, _, _) => {
                let nnn = op & 0xFFF;
                self.pc = nnn;
            }
            /* CALL */
            (2, _, _, _) => {
                let nnn = op & 0xFFF;
                self.push(self.pc);
                self.pc = nnn;
            }
            /* SKIP if VX == NN */
            (3, _, _, _) => {
                let x = nibbles.1 as usize;
                let nn = (op & 0xFF) as u8;
                if self.v_reg[x] == nn {
                    self.pc += 2;
                }
            }
            /* SKIP if VX != NN */
            (4, _, _, _) => {
                let x = nibbles.1 as usize;
                let nn = (op & 0xFF) as u8;
                if self.v_reg[x] != nn {
                    self.pc += 2;
                }
            }
            /* SKIP if VX == VY */
            (5, _, _, 0) => {
                let x = nibbles.1 as usize;
                let y = nibbles.2 as usize;
                if self.v_reg[x] == self.v_reg[y] {
                    self.pc += 2;
                }
            }
            /* SET VX = NN */
            (6, _, _, _) => {
                let x = nibbles.1 as usize;
                let nn = (op & 0xFF) as u8;
                self.v_reg[x] = nn;
            }
            /* ADD VX += NN */
            (7, _, _, _) => {
                let x = nibbles.1 as usize;
                let nn = (op & 0xFF) as u8;
                self.v_reg[x] = self.v_reg[x].wrapping_add(nn);
            }
            /* SET VX = VY */
            (8, _, _, 0) => {
                let x = nibbles.1 as usize;
                let y = nibbles.2 as usize;
                self.v_reg[x] = self.v_reg[y];
            }
            /* OR VX |= VY */
            (8, _, _, 1) => {
                let x = nibbles.1 as usize;
                let y = nibbles.2 as usize;
                self.v_reg[x] |= self.v_reg[y];
            }
            /* AND VX &= VY */
            (8, _, _, 2) => {
                let x = nibbles.1 as usize;
                let y = nibbles.2 as usize;
                self.v_reg[x] &= self.v_reg[y];
            }
            /* XOR VX ^= VY */
            (8, _, _, 3) => {
                let x = nibbles.1 as usize;
                let y = nibbles.2 as usize;
                self.v_reg[x] ^= self.v_reg[y];
            }
            /* ADD VX += VY (setting OF flag) */
            (8, _, _, 4) => {
                let x = nibbles.1 as usize;
                let y = nibbles.2 as usize;

                let (new_vx, carry) = self.v_reg[x].overflowing_add(self.v_reg[y]);
                let new_vf = if carry { 1 } else { 0 };

                self.v_reg[x] = new_vx;
                self.v_reg[0xF] = new_vf; // setting overflow flag in VF flag register at 0xF
            }
            /* SUB VX -= VY (setting N flag) */
            (8, _, _, 5) => {
                let x = nibbles.1 as usize;
                let y = nibbles.2 as usize;

                let (new_vx, borrow) = self.v_reg[x].overflowing_sub(self.v_reg[y]);
                let new_vf = if borrow { 0 } else { 1 };

                self.v_reg[x] = new_vx;
                self.v_reg[0xF] = new_vf;
            }
            /* SHR VX >>= 1 */
            (8, _, _, 6) => {
                let x = nibbles.1 as usize;
                let lsb = self.v_reg[x] & 1; // least significant bit that gets dropped to store in VF
                                             // flag register
                self.v_reg[x] >>= 1;
                self.v_reg[0xF] = lsb;
            }
            /* SUB VX = VY - VX */
            (8, _, _, 7) => {
                let x = nibbles.1 as usize;
                let y = nibbles.2 as usize;

                let (new_vx, borrow) = self.v_reg[y].overflowing_sub(self.v_reg[x]);
                let new_vf = if borrow { 0 } else { 1 };

                self.v_reg[x] = new_vx;
                self.v_reg[0xF] = new_vf;
            }
            /* SHL VX <<= 1 */
            (8, _, _, 0xE) => {
                let x = nibbles.1 as usize;
                let msb = (self.v_reg[x] >> 7) & 1; // most significant bit that gets dropped to
                                                    // store in VF flag register
                self.v_reg[x] <<= 1;
                self.v_reg[0xF] = msb;
            }
            /* SKIP if VX != VY */
            (9, _, _, 0) => {
                let x = nibbles.1 as usize;
                let y = nibbles.2 as usize;
                if self.v_reg[x] != self.v_reg[y] {
                    self.pc += 2;
                }
            }
            /* SET I = NNN */
            (0xA, _, _, _) => {
                let nnn = op & 0xFFF;
                self.i_reg = nnn; // setting I register to index into RAM to NNN
            }
            /* JMP V0 + NNN */
            (0xB, _, _, _) => {
                let nnn = op & 0xFFF;
                self.pc = (self.v_reg[0] as u16) + nnn; // move pc to sum of value in V0 plus raw
                                                        // value 0xNNN
            }
            /* RNG VX = rand() & NN */
            (0xC, _, _, _) => {
                let x = nibbles.1 as usize;
                let nn = (op & 0xFF) as u8;
                let rng: u8 = random();
                self.v_reg[x] = rng & nn;
            }
            /* DRAW */
            (0xD, _, _, _) => {
                let x = nibbles.1 as usize;
                let y = nibbles.2 as usize;
                // Get (x,y) coords for sprite
                let x_coord = self.v_reg[x] as u16;
                let y_coord = self.v_reg[y] as u16;
                // Last nibble determines row high of sprite
                let num_rows = nibbles.3;
                // Keep track if any pixels were flipped
                let mut flipped = false;
                // Iterating over each row of sprite
                for y_line in 0..num_rows {
                    // Determine memory address where row data is stored
                    let addr = self.i_reg + y_line as u16;
                    let pixels = self.ram[addr as usize];
                    // Iterate over each column in sprite's row
                    for x_line in 0..8 {
                        // Mask to fetch current pixel's bit, only flip if 1
                        if (pixels & (0b1000_0000 >> x_line)) != 0 {
                            // Sprites wrap around screen, modulo is applied
                            let x = (x_coord + x_line) as usize % SCREEN_WIDTH;
                            let y = (y_coord + y_line) as usize % SCREEN_HEIGHT;
                            // Pixel's index for 1D screen array
                            let idx = x + SCREEN_WIDTH * y;
                            // Check if pixel is flipped and set it
                            flipped != self.screen[idx];
                            self.screen[idx] ^= true;
                        }
                    }
                }
                // Populate VF register
                if flipped {
                    self.v_reg[0xF] = 1;
                } else {
                    self.v_reg[0xF] = 0;
                }
            }
            _ => unimplemented!("Unimplemented opcode: {:04x}", op),
        }
    }
}
