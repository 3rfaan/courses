//
// Now that we are familiar with the principles of multi-threading,
// let's boldly venture into a practical example from mathematics.
// We will determine the circle number PI with sufficient accuracy.
//
// There are different methods for this, and some of them are several
// hundred years old. For us, the dusty procedures are surprisingly well
// suited to our exercise. Because the mathematicians of the time didn't
// have fancy computers with which we can calculate something like this
// in seconds today.
// Whereby, of course, it depends on the accuracy, i.e. how many digits
// after the decimal point we are interested in.
// But these old procedures can still be tackled with paper and pencil,
// which is why they are easier for us to understand.
// At least for me. ;-)
//
// So let's take a mental leap back a few years.
// Around 1672 (if you want to know and read about it in detail, you can
// do so on Wikipedia, for example), various mathematicians once again
// discovered a method of approaching the circle number PI.
// There were the Scottish mathematician Gregory and the German
// mathematician Leibniz, and even a few hundred years earlier the Indian
// mathematician Madhava. All of them independently developed the same
// formula, which was published by Leibniz in 1682 in the journal
// "Acta Eruditorum".
// This is why this method has become known as the "Leibniz series",
// although the other names are also often used today.
// We will not go into the formula and its derivation in detail, but
// will deal with the series straight away:
//
//        4     4     4     4     4
//  PI = --- - --- + --- - --- + --- ...
//        1     3     5     7     9
//
// As you can clearly see, the series starts with the whole number 4 and
// approaches the circle number by subtracting and adding smaller and
// smaller parts of 4. Pretty much everyone has learned PI = 3.14 at school,
// but very few people remember other digits, and this is rarely necessary
// in practice. Because either you don't need the precision, or you use a
// calculator in which the number is stored as a very precise constant.
// But at some point this constant was calculated and we are doing the same
// now. The question at this point is, how many partial values do we have
// to calculate for which accuracy?
//
// The answer is chewing, to get 8 digits after the decimal point we need
// 1,000,000,000 partial values. And for each additional digit we have to
// add a zero.
// Even fast computers - and I mean really fast computers - get a bit warmer
// on the CPU when it comes to really many digits. But the 8 digits are
// enough for us for now, because we want to understand the principle and
// nothing more, right?
//
// As we have already discovered, the Leibniz series is a series with a
// fixed distance of 2 between the individual partial values. This makes
// it easy to apply a simple loop to it, because if we start with n = 1
// (which is not necessarily useful now) we always have to add 2 in each
// round.
// But wait! The partial values are alternately added and subtracted.
// This could also be achieved with one loop, but not very elegantly.
// It also makes sense to split this between two CPUs, one calculates
// the positive values and the other the negative values. And so we can
// simply start two threads and add everything up at the end and we're
// done.
// We just have to remember that if only the positive or negative values
// are calculated, the distances are twice as large, i.e. 4.
//
// So that the whole thing has a real learning effect, the first thread
// call is specified and you have to make the second.
// But don't worry, it will work out. :-)
//
const std = @import("std");

pub fn main() !void {
    const count = 1_000_000_000;
    var pi_plus: f64 = 0;
    var pi_minus: f64 = 0;

    {
        // First thread to calculate the plus numbers.
        const handle1 = try std.Thread.spawn(.{}, thread_pi, .{ &pi_plus, 5, count });
        defer handle1.join();

        // Second thread to calculate the minus numbers.
        const handle2 = try std.Thread.spawn(.{}, thread_pi, .{ &pi_minus, 3, count });
        defer handle2.join();
    }
    // Here we add up the results.
    std.debug.print("PI ≈ {d:.8}\n", .{4 + pi_plus - pi_minus});
}

fn thread_pi(pi: *f64, begin: u64, end: u64) !void {
    var n: u64 = begin;
    while (n < end) : (n += 4) {
        pi.* += 4 / @as(f64, @floatFromInt(n));
    }
}
// If you wish, you can increase the number of loop passes, which
// improves the number of digits.
//
// But be careful:
// In order for parallel processing to really show its strengths,
// the compiler must be given the "-O ReleaseFast" flag when it
// is created. Otherwise the debug functions slow down the speed
// to such an extent that seconds become minutes during execution.
//
// And you should remove the formatting restriction in "print",
// otherwise you will not be able to see the additional digits.
