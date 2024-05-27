import init, * as wasm from "./wasm.js"

const WIDTH = 64;
const HEIGHT = 32;
const SCALE = 15;
const TICKS_PER_FRAME = 10;
let anim_frame = 0;

const canvas = document.getElementById("canvas");
canvas.width = WIDTH * SCALE;
canvas.height = HEIGHT * SCALE;

const ctx = canvas.getContext("2d");
ctx.fillStyle = "black";
ctx.fillRect(0, 0, WIDTH * SCALE, HEIGHT * SCALE);

const input = document.getElementById("fileinput");

async function run() {
    await init();
    let chip8 = new wasm.EmuWasm();

    document.addEventListener("keydown", function(event) {
        chip8.keypress(event, true)
    });
    document.addEventListener("keyup", function(event) {
        chip8.keypress(event, false)
    });
    document.addEventListener("change", function(event) {
        // Stop previous game from rendering, if one exists
        if (anim_frame != 0) {
            window.cancelAnimationFrame(anim_frame);
        }

        let file = event.target.files[0];
        if (!file) {
            alert("Failed to read file");
            return;
        }

        // Load in game as Uint8Array, send to .wasm, start main loop
        let fr = new FileReader();
        fr.onload = function(e) {
            let buffer = fr.result;
            const rom = new Uint8Array(buffer);
            chip8.reset();
            chip8.load_game(rom);
            mainloop(chip8);
        }
        fr.readAsArrayBuffer(file);
    }, false);
}

function mainloop(chip8) {
    // Only draw every few ticks
    for (let i = 0; i < TICKS_PER_FRAME; i++) {
        chip8.tick();
    }
    chip8.tick_timers();

    // Clear canvas before drawing
    ctx.fillStyle = "black";
    ctx.fillRect(0, 0, WIDTH * SCALE, HEIGHT * SCALE);
    // Set draw color back to white before rendering frame
    ctx.fillStyle = "white";
    chip8.draw_screen(SCALE);

    anim_frame = window.requestAnimationFrame(() => mainloop(chip8));
}


run().catch(console.error);
