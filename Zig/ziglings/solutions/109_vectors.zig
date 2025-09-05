// So far in Ziglings, we've seen how for loops can be used to
// repeat calculations across an array in several ways.
//
// For loops are generally great for this kind of task, but
// sometimes they don't fully utilize the capabilities of the
// CPU.
//
// Most modern CPUs can execute instructions in which SEVERAL
// calculations are performed WITHIN registers at the SAME TIME.
// These are known as "single instruction, multiple data" (SIMD)
// instructions. SIMD instructions can make code significantly
// more performant.
//
// To see why, imagine we have a program in which we take the
// square root of four (changing) f32 floats.
//
// A simple compiler would take the program and produce machine code
// which calculates each square root sequentially. Most registers on
// modern CPUs have 64 bits, so we could imagine that each float moves
// into a 64-bit register, and the following happens four times:
//
//            32 bits   32 bits
//          +-------------------+
// register |    0    |    x    |
//          +-------------------+
//
//                    |
//           [SQRT instruction]
//                    V
//
//          +-------------------+
//          |    0    | sqrt(x) |
//          +-------------------+
//
// Notice that half of the register contains blank data to which
// nothing happened. What a waste! What if we were able to use
// that space instead? This is the idea at the core of SIMD.
//
// Most modern CPUs contain specialized registers with at least 128 bits
// for performing SIMD instructions. On a machine with 128-bit SIMD
// registers, a smart compiler would probably NOT issue four sqrt
// instructions as above, but instead pack the floats into a single
// 128-bit register, then execute a single "packed" sqrt
// instruction to do ALL the square root calculations at once.
//
// For example:
//
//
//             32 bits   32 bits   32 bits   32 bits
//           +---------------------------------------+
// register  |   4.0   |   9.0   |  25.0   |  49.0   |
//           +---------------------------------------+
//
//                              |
//                  [SIMD SQRT instruction]
//                              V
//
//           +---------------------------------------+
// register  |   2.0   |   3.0   |   5.0   |   7.0   |
//           +---------------------------------------+
//
// Pretty cool, right?
//
// Code with SIMD instructions is usually more performant than code
// without SIMD instructions. Zig cares a lot about performance,
// so it has built-in support for SIMD! It has a data structure that
// directly supports SIMD instructions:
//
//                        +-----------+
//                        |  Vectors  |
//                        +-----------+
//
// Operations performed on vectors in Zig will be done in parallel using
// SIMD instructions, whenever possible.
//
// Defining vectors in Zig is straightforwards. No library import is needed.
const v1 = @Vector(3, i32){ 1, 10, 100 };
const v2 = @Vector(3, f32){ 2.0, 3.0, 5.0 };

// Vectors support the same builtin operators as their underlying base types.
const v3 = v1 + v1; // {   2,  20,  200};
const v4 = v2 * v2; // { 4.0, 9.0, 25.0};

// Intrinsics that apply to base types usually extend to vectors.
const v5: @Vector(3, f32) = @floatFromInt(v3); // { 2.0,  20.0,  200.0}
const v6 = v4 - v5; // { 2.0, -11.0, -175.0}
const v7 = @abs(v6); // { 2.0,  11.0,  175.0}

// We can make constant vectors, and reduce vectors.
const v8: @Vector(4, u8) = @splat(2); // { 2, 2, 2, 2}
const v8_sum = @reduce(.Add, v8); // 8
const v8_min = @reduce(.Min, v8); // 2

// Fixed-length arrays can be automatically assigned to vectors (and vice-versa).
const single_digit_primes = [4]i8{ 2, 3, 5, 7 };
const prime_vector: @Vector(4, i8) = single_digit_primes;

// Now let's use vectors to simplify and optimize some code!
//
// Ewa is writing a program in which they frequently want to compare
// two lists of four f32s. Ewa expects the lists to be similar, and
// wants to determine the largest pairwise difference between the lists.
//
// Ewa wrote the following function to figure this out.

fn calcMaxPairwiseDiffOld(list1: [4]f32, list2: [4]f32) f32 {
    var max_diff: f32 = 0;
    for (list1, list2) |n1, n2| {
        const abs_diff = @abs(n1 - n2);
        if (abs_diff > max_diff) {
            max_diff = abs_diff;
        }
    }
    return max_diff;
}

// Ewa heard about vectors in Zig, and started writing a new vector
// version of the function, but has got stuck!
//
// Help Ewa finish the vector version! The examples above should help.

const Vec4 = @Vector(4, f32);
fn calcMaxPairwiseDiffNew(a: Vec4, b: Vec4) f32 {
    const abs_diff_vec = @abs(a - b);
    const max_diff = @reduce(.Max, abs_diff_vec);
    return max_diff;
}

// Quite the simplification! We could even write the function in one line
// and it would still be readable.
//
// Since the entire function is now expressed in terms of vector operations,
// the Zig compiler will easily be able to compile it down to machine code
// which utilizes the all-powerful SIMD instructions and does a lot of the
// computation in parallel.

const std = @import("std");
const print = std.debug.print;

pub fn main() void {
    const l1 = [4]f32{ 3.141, 2.718, 0.577, 1.000 };
    const l2 = [4]f32{ 3.154, 2.707, 0.591, 0.993 };
    const mpd_old = calcMaxPairwiseDiffOld(l1, l2);
    const mpd_new = calcMaxPairwiseDiffNew(l1, l2);
    print("Max difference (old fn): {d: >5.3}\n", .{mpd_old});
    print("Max difference (new fn): {d: >5.3}\n", .{mpd_new});
}
