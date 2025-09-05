// ----------------------------------------------------------------------------
// Quiz Time: Toggling, Setting, and Clearing Bits
// ----------------------------------------------------------------------------
//
// Another exciting thing about Zig is its suitability for embedded
// programming. Your Zig code doesn't have to remain on your laptop; you can
// also deploy your code to microcontrollers! This means you can write Zig to
// drive your next robot or greenhouse climate control system! Ready to enter
// the exciting world of embedded programming? Let's get started!
//
// ----------------------------------------------------------------------------
// Some Background
// ----------------------------------------------------------------------------
//
// A common activity in microcontroller programming is setting and clearing
// bits on input and output pins. This lets you control LEDs, sensors, motors
// and more! In a previous exercise (097_bit_manipulation.zig) you learned how
// to swap two bytes using the ^ (XOR - exclusive or) operator. This quiz will
// test your knowledge of bit manipulation in Zig while giving you a taste of
// what it's like to control registers in a real microcontroller. Included at
// the end are some helper functions that demonstrate how we might make our
// code a little more readable.
//
// Below is a pinout diagram for the famous ATmega328 AVR microcontroller used
// as the primary microchip on popular microcontroller platforms like the
// Arduino UNO.
//
//  ============ PINOUT DIAGRAM FOR ATMEGA328 MICROCONTROLLER ============
//                                _____ _____
//                               |     U     |
//                 (RESET) PC6 --|  1     28 |-- PC5
//                         PD0 --|  2     27 |-- PC4
//                         PD1 --|  3     26 |-- PC3
//                         PD2 --|  4     25 |-- PC2
//                         PD3 --|  5     24 |-- PC1
//                         PD4 --|  6     23 |-- PC0
//                         VCC --|  7     22 |-- GND
//                         GND --|  8     21 |-- AREF
//                     |-- PB6 --|  9     20 |-- AVCC
//                     |-- PB7 --| 10     19 |-- PB5 --|
//                     |   PD5 --| 11     18 |-- PB4 --|
//                     |   PD6 --| 12     17 |-- PB3 --|
//                     |   PD7 --| 13     16 |-- PB2 --|
//                     |-- PB0 --| 14     15 |-- PB1 --|
//                     |         |___________|         |
//                     \_______________________________/
//                                    |
//                                  PORTB
//
// Drawing inspiration from this diagram, we'll use the pins for PORTB as our
// mental model for this quiz on bit manipulation. It should be noted that
// in the following problems we are using ordinary variables, one of which we
// have named PORTB, to simulate modifying the bits of real hardware registers.
// But in actual microcontroller code, PORTB would be defined something like
// this:
//          pub const PORTB = @as(*volatile u8, @ptrFromInt(0x25));
//
// This lets the compiler know not to make any optimizations to PORTB so that
// the IO pins are properly mapped to our code.
//
// NOTE : To keep things simple, the following problems are given using type
// u4, so applying the output to PORTB would only affect the lower four pins
// PB0..PB3. Of course, there is nothing to prevent you from swapping the u4
// with a u8 so you can control all 8 of PORTB's IO pins.

const std = @import("std");
const print = std.debug.print;
const testing = std.testing;

pub fn main() !void {
    var PORTB: u4 = 0b0000; // only 4 bits wide for simplicity

    // ------------------------------------------------------------------------
    // Quiz
    // ------------------------------------------------------------------------

    // See if you can solve the following problems. The last two problems throw
    // you a bit of a curve ball. Try solving them on your own. If you need
    // help, scroll to the bottom of main to see some in depth explanations on
    // toggling, setting, and clearing bits in Zig.

    print("Toggle pins with XOR on PORTB\n", .{});
    print("-----------------------------\n", .{});
    PORTB = 0b1100;
    print("  {b:0>4} // (initial state of PORTB)\n", .{PORTB});
    print("^ {b:0>4} // (bitmask)\n", .{0b0101});
    PORTB ^= (1 << 2) | (1 << 0); // What's wrong here?
    checkAnswer(0b1001, PORTB);

    newline();

    PORTB = 0b1100;
    print("  {b:0>4} // (initial state of PORTB)\n", .{PORTB});
    print("^ {b:0>4} // (bitmask)\n", .{0b0011});
    PORTB ^= (1 << 1) | (1 << 0); // What's wrong here?
    checkAnswer(0b1111, PORTB);

    newline();

    print("Set pins with OR on PORTB\n", .{});
    print("-------------------------\n", .{});

    PORTB = 0b1001; // reset PORTB
    print("  {b:0>4} // (initial state of PORTB)\n", .{PORTB});
    print("| {b:0>4} // (bitmask)\n", .{0b0100});
    PORTB = PORTB | (1 << 2); // What's missing here?
    checkAnswer(0b1101, PORTB);

    newline();

    PORTB = 0b1001; // reset PORTB
    print("  {b:0>4} // (reset state)\n", .{PORTB});
    print("| {b:0>4} // (bitmask)\n", .{0b0100});
    PORTB |= (1 << 2); // What's missing here?
    checkAnswer(0b1101, PORTB);

    newline();

    print("Clear pins with AND and NOT on PORTB\n", .{});
    print("------------------------------------\n", .{});

    PORTB = 0b1110; // reset PORTB
    print("  {b:0>4} // (initial state of PORTB)\n", .{PORTB});
    print("& {b:0>4} // (bitmask)\n", .{0b1011});
    PORTB = PORTB & ~@as(u4, 1 << 2); // What character is missing here?
    checkAnswer(0b1010, PORTB);

    newline();

    PORTB = 0b0111; // reset PORTB
    print("  {b:0>4} // (reset state)\n", .{PORTB});
    print("& {b:0>4} // (bitmask)\n", .{0b1110});
    PORTB &= ~@as(u4, 1 << 0); // What's missing here?
    checkAnswer(0b0110, PORTB);

    newline();
    newline();
}

// ************************************************************************
//                    IN-DEPTH EXPLANATIONS BELOW
// ************************************************************************
//
//
//
//
//
//
//
//
//
//
//
// ------------------------------------------------------------------------
// Toggling bits with XOR:
// ------------------------------------------------------------------------
// XOR stands for "exclusive or". We can toggle bits with the ^ (XOR)
// bitwise operator, like so:
//
//
// In order to output a 1, the logic of an XOR operation requires that the
// two input bits are of different values. Therefore, 0 ^ 1 and 1 ^ 0 will
// both yield a 1 but 0 ^ 0 and 1 ^ 1 will output 0. XOR's unique behavior
// of outputting a 0 when both inputs are 1s is what makes it different from
// the OR operator; it also gives us the ability to toggle bits by putting
// 1s into our bitmask.
//
// - 1s in our bitmask operand, can be thought of as causing the
//   corresponding bits in the other operand to flip to the opposite value.
// - 0s cause no change.
//
//                            The 0s in our bitmask preserve these values
// -XOR op- ---expanded---    in the output.
//            _______________/
//           /       /
//   1100   1   1   0   0
// ^ 0101   0   1   0   1 (bitmask)
// ------   -   -   -   -
// = 1001   1   0   0   1 <- This bit was already cleared.
//              \_______\
//                       \
//                         We can think of these bits having flipped
//                         because of the presence of 1s in those columns
//                         of our bitmask.
//
// Now let's take a look at setting bits with the | operator.
//
//
//
//
//
// ------------------------------------------------------------------------
// Setting bits with OR:
// ------------------------------------------------------------------------
// We can set bits on PORTB with the | (OR) operator, like so:
//
// var PORTB: u4 = 0b1001;
// PORTB = PORTB | 0b0010;
// print("PORTB: {b:0>4}\n", .{PORTB}); // output: 1011
//
// -OR op-  ---expanded---
//                    _ Set only this bit.
//                   /
//   1001   1   0   0   1
// | 0010   0   0   1   0 (bitmask)
// ------   -   -   -   -
// = 1011   1   0   1   1
//           \___\_______\
//                        \
//                          These bits remain untouched because OR-ing with
//                          a 0 effects no change.
//
// ------------------------------------------------------------------------
// To create a bitmask like 0b0010 used above:
//
// 1. First, shift the value 1 over one place with the bitwise << (shift
// left) operator as indicated below:
//           1 << 0 -> 0001
//           1 << 1 -> 0010  <-- Shift 1 one place to the left
//           1 << 2 -> 0100
//           1 << 3 -> 1000
//
// This allows us to rewrite the above code like this:
//
// var PORTB: u4 = 0b1001;
// PORTB = PORTB | (1 << 1);
// print("PORTB: {b:0>4}\n", .{PORTB}); // output: 1011
//
// Finally, as in the C language, Zig allows us to use the |= operator, so
// we can rewrite our code again in an even more compact and idiomatic
// form: PORTB |= (1 << 1)

// So now we've covered how to toggle and set bits. What about clearing
// them? Well, this is where Zig throws us a curve ball. Don't worry we'll
// go through it step by step.
//
//
//
//
//
// ------------------------------------------------------------------------
// Clearing bits with AND and NOT:
// ------------------------------------------------------------------------
// We can clear bits with the & (AND) bitwise operator, like so:

// PORTB = 0b1110; // reset PORTB
// PORTB = PORTB & 0b1011;
// print("PORTB: {b:0>4}\n", .{PORTB}); // output -> 1010
//
// - 0s clear bits when used in conjunction with a bitwise AND.
// - 1s do nothing, thus preserving the original bits.
//
// -AND op- ---expanded---
//                __________ Clear only this bit.
//               /
//   1110   1   1   1   0
// & 1011   1   0   1   1 (bitmask)
// ------   -   -   -   -
// = 1010   1   0   1   0 <- This bit was already cleared.
//           \_______\
//                    \
//                      These bits remain untouched because AND-ing with a
//                      1 preserves the original bit value whether 0 or 1.
//
// ------------------------------------------------------------------------
// We can use the ~ (NOT) operator to easily create a bitmask like 1011:
//
//  1. First, shift the value 1 over two places with the bit-wise << (shift
//     left) operator as indicated below:
//          1 << 0 -> 0001
//          1 << 1 -> 0010
//          1 << 2 -> 0100 <- The 1 has been shifted two places to the left
//          1 << 3 -> 1000
//
//  2. The second step in creating our bitmask is to invert the bits
//          ~0100 -> 1011
//     in C we would write this as:
//          ~(1 << 2) -> 1011
//
//     But if we try to compile ~(1 << 2) in Zig, we'll get an error:
//          unable to perform binary not operation on type 'comptime_int'
//
//     Before Zig can invert our bits, it needs to know the number of
//     bits it's being asked to invert.
//
//     We do this with the @as (cast as) built-in like this:
//          @as(u4, 1 << 2) -> 0100
//
//     Finally, we can invert our new mask by placing the NOT ~ operator
//     before our expression, like this:
//          ~@as(u4, 1 << 2) -> 1011
//
//     If you are offput by the fact that you can't simply invert bits like
//     you can in languages such as C without casting to a particular size
//     of integer, you're not alone. However, this is actually another
//     instance where Zig is really helpful because it protects you from
//     difficult to debug integer overflow bugs that can have you tearing
//     your hair out. In the interest of keeping things sane, Zig requires
//     you simply to tell it the size of number you are inverting. In the
//     words of Andrew Kelley, "If you want to invert the bits of an
//     integer, zig has to know how many bits there are."
//
//     For more insight into the Zig team's position on why the language
//     takes the approach it does with the ~ operator, take a look at
//     Andrew's comments on the following github issue:
//     https://github.com/ziglang/zig/issues/1382#issuecomment-414459529
//
// Whew, so after all that what we end up with is:
//          PORTB = PORTB & ~@as(u4, 1 << 2);
//
// We can shorten this with the &= combined AND and assignment operator,
// which applies the AND operator on PORTB and then reassigns PORTB. Here's
// what that looks like:
//          PORTB &= ~@as(u4, 1 << 2);
//

// ------------------------------------------------------------------------
// Conclusion
// ------------------------------------------------------------------------
//
// While the examples in this quiz have used only 4-bit wide variables,
// working with 8 bits is no different. Here's an example where we set
// every other bit beginning with the two's place:

// var PORTD: u8 = 0b0000_0000;
// print("PORTD: {b:0>8}\n", .{PORTD});
// PORTD |= (1 << 1);
// PORTD = setBit(u8, PORTD, 3);
// PORTD |= (1 << 5) | (1 << 7);
// print("PORTD: {b:0>8} // set every other bit\n", .{PORTD});
// PORTD = ~PORTD;
// print("PORTD: {b:0>8} // bits flipped with NOT (~)\n", .{PORTD});
// newline();
//
// // Here we clear every other bit beginning with the two's place.
//
// PORTD = 0b1111_1111;
// print("PORTD: {b:0>8}\n", .{PORTD});
// PORTD &= ~@as(u8, 1 << 1);
// PORTD = clearBit(u8, PORTD, 3);
// PORTD &= ~@as(u8, (1 << 5) | (1 << 7));
// print("PORTD: {b:0>8} // clear every other bit\n", .{PORTD});
// PORTD = ~PORTD;
// print("PORTD: {b:0>8} // bits flipped with NOT (~)\n", .{PORTD});
// newline();

// ----------------------------------------------------------------------------
// Here are some helper functions for manipulating bits
// ----------------------------------------------------------------------------

// Functions for setting, clearing, and toggling a single bit
fn setBit(comptime T: type, byte: T, comptime bit_pos: T) !T {
    return byte | (1 << bit_pos);
}

test "setBit" {
    try testing.expectEqual(setBit(u8, 0b0000_0000, 3), 0b0000_1000);
}

fn clearBit(comptime T: type, byte: T, comptime bit_pos: T) T {
    return byte & ~@as(T, (1 << bit_pos));
}

test "clearBit" {
    try testing.expectEqual(clearBit(u8, 0b1111_1111, 0), 0b1111_1110);
}

fn toggleBit(comptime T: type, byte: T, comptime bit_pos: T) T {
    return byte ^ (1 << bit_pos);
}

test "toggleBit" {
    var byte = toggleBit(u8, 0b0000_0000, 0);
    try testing.expectEqual(byte, 0b0000_0001);
    byte = toggleBit(u8, byte, 0);
    try testing.expectEqual(byte, 0b0000_0000);
}

// ----------------------------------------------------------------------------
// Some additional functions for setting, clearing, and toggling multiple bits
// at once with a tuple because, hey, why not?
// ----------------------------------------------------------------------------
//

fn createBitmask(comptime T: type, comptime bits: anytype) !T {
    comptime var bitmask: T = 0;
    inline for (bits) |bit| {
        if (bit >= @bitSizeOf(T)) return error.BitPosTooLarge;
        if (bit < 0) return error.BitPosTooSmall;

        bitmask |= (1 << bit);
    }
    return bitmask;
}

test "creating bitmasks from a tuple" {
    try testing.expectEqual(createBitmask(u8, .{0}), 0b0000_0001);
    try testing.expectEqual(createBitmask(u8, .{1}), 0b0000_0010);
    try testing.expectEqual(createBitmask(u8, .{2}), 0b0000_0100);
    try testing.expectEqual(createBitmask(u8, .{3}), 0b0000_1000);
    //
    try testing.expectEqual(createBitmask(u8, .{ 0, 4 }), 0b0001_0001);
    try testing.expectEqual(createBitmask(u8, .{ 1, 5 }), 0b0010_0010);
    try testing.expectEqual(createBitmask(u8, .{ 2, 6 }), 0b0100_0100);
    try testing.expectEqual(createBitmask(u8, .{ 3, 7 }), 0b1000_1000);

    try testing.expectError(error.BitPosTooLarge, createBitmask(u4, .{4}));
}

fn setBits(byte: u8, bits: anytype) !u8 {
    const bitmask = try createBitmask(u8, bits);
    return byte | bitmask;
}

test "setBits" {
    try testing.expectEqual(setBits(0b0000_0000, .{0}), 0b0000_0001);
    try testing.expectEqual(setBits(0b0000_0000, .{7}), 0b1000_0000);

    try testing.expectEqual(setBits(0b0000_0000, .{ 0, 1, 2, 3, 4, 5, 6, 7 }), 0b1111_1111);
    try testing.expectEqual(setBits(0b1111_1111, .{ 0, 1, 2, 3, 4, 5, 6, 7 }), 0b1111_1111);

    try testing.expectEqual(setBits(0b0000_0000, .{ 2, 3, 4, 5 }), 0b0011_1100);

    try testing.expectError(error.BitPosTooLarge, setBits(0b1111_1111, .{8}));
    try testing.expectError(error.BitPosTooSmall, setBits(0b1111_1111, .{-1}));
}

fn clearBits(comptime byte: u8, comptime bits: anytype) !u8 {
    const bitmask: u8 = try createBitmask(u8, bits);
    return byte & ~@as(u8, bitmask);
}

test "clearBits" {
    try testing.expectEqual(clearBits(0b1111_1111, .{0}), 0b1111_1110);
    try testing.expectEqual(clearBits(0b1111_1111, .{7}), 0b0111_1111);

    try testing.expectEqual(clearBits(0b1111_1111, .{ 0, 1, 2, 3, 4, 5, 6, 7 }), 0b000_0000);
    try testing.expectEqual(clearBits(0b0000_0000, .{ 0, 1, 2, 3, 4, 5, 6, 7 }), 0b000_0000);

    try testing.expectEqual(clearBits(0b1111_1111, .{ 0, 1, 6, 7 }), 0b0011_1100);

    try testing.expectError(error.BitPosTooLarge, clearBits(0b1111_1111, .{8}));
    try testing.expectError(error.BitPosTooSmall, clearBits(0b1111_1111, .{-1}));
}

fn toggleBits(comptime byte: u8, comptime bits: anytype) !u8 {
    const bitmask = try createBitmask(u8, bits);
    return byte ^ bitmask;
}

test "toggleBits" {
    try testing.expectEqual(toggleBits(0b0000_0000, .{0}), 0b0000_0001);
    try testing.expectEqual(toggleBits(0b0000_0000, .{7}), 0b1000_0000);

    try testing.expectEqual(toggleBits(0b1111_1111, .{ 0, 1, 2, 3, 4, 5, 6, 7 }), 0b000_0000);
    try testing.expectEqual(toggleBits(0b0000_0000, .{ 0, 1, 2, 3, 4, 5, 6, 7 }), 0b1111_1111);

    try testing.expectEqual(toggleBits(0b0000_1111, .{ 0, 1, 2, 3, 4, 5, 6, 7 }), 0b1111_0000);
    try testing.expectEqual(toggleBits(0b0000_1111, .{ 0, 1, 2, 3 }), 0b0000_0000);

    try testing.expectEqual(toggleBits(0b0000_0000, .{ 0, 2, 4, 6 }), 0b0101_0101);

    try testing.expectError(error.BitPosTooLarge, toggleBits(0b1111_1111, .{8}));
    try testing.expectError(error.BitPosTooSmall, toggleBits(0b1111_1111, .{-1}));
}

// ----------------------------------------------------------------------------
// Utility functions
// ----------------------------------------------------------------------------

fn newline() void {
    print("\n", .{});
}

fn checkAnswer(expected: u4, answer: u4) void {
    if (expected != answer) {
        print("*************************************************************\n", .{});
        print("= {b:0>4} <- INCORRECT! THE EXPECTED OUTPUT IS {b:0>4}\n", .{ answer, expected });
        print("*************************************************************\n", .{});
    } else {
        print("= {b:0>4}", .{answer});
    }
    newline();
}
