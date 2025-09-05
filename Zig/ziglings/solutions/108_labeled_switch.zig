//
// You've heard of while loops in exercises 011,012,013 and 014
// You've also heard of switch expressions in exercises 030 and 31.
// You've also seen how labels can be used in exercise 063.
//
// By combining while loops and switch statements with continue and break statements
// one can create very concise State Machines.
//
// One such example would be:
//
//      pub fn main() void {
//          var op: u8 = 1;
//          while (true) {
//              switch (op) {
//                  1 => { op = 2; continue; },
//                  2 => { op = 3; continue; },
//                  3 => return,
//                  else => {},
//              }
//              break;
//          }
//          std.debug.print("This statement cannot be reached\n", .{});
//      }
//
// By combining all we've learned so far, we can now proceed with a labeled switch.
//
// A labeled switch is some extra syntactic sugar, which comes with all sorts of
// candy (performance benefits). Don't believe me? Directly to source https://github.com/ziglang/zig/pull/21367
//
// Here is the previous excerpt implemented as a labeled switch instead:
//
//      pub fn main() void {
//          foo: switch (@as(u8, 1)) {
//              1 => continue :foo 2,
//              2 => continue :foo 3,
//              3 => return,
//              else => {},
//          }
//          std.debug.print("This statement cannot be reached\n", .{});
//      }
//
// The flow of execution on this second case is:
//  1. The switch starts with value '1';
//  2. The switch evaluates to case '1' which in turn uses the continue statement
//     to re-evaluate the labeled switch again, now providing the value '2';
//  3. In the case '2' we repeat the same pattern as case '1'
//     but instead the value to be evaluated is now '3';
//  4. Finally we get to case '3', where we return from the function as a whole,
//     so the debug statement is never executed.
//  5. In this example, since the input does not have clear, exhaustive patterns and
//     can essentially be any 'u8' integer, we need to handle all cases not explicitly
//     covered by using the 'else => {}' branch as the default case.
//
//
const std = @import("std");

const PullRequestState = enum(u8) {
    Draft,
    InReview,
    Approved,
    Rejected,
    Merged,
};

pub fn main() void {
    // Oh no, your pull request keeps being rejected,
    // how would you fix it?
    pr: switch (PullRequestState.Draft) {
        PullRequestState.Draft => continue :pr PullRequestState.InReview,
        PullRequestState.InReview => continue :pr PullRequestState.Approved,
        PullRequestState.Approved => continue :pr PullRequestState.Merged,
        PullRequestState.Rejected => {
            std.debug.print("The pull request has been rejected.\n", .{});
            return;
        },
        PullRequestState.Merged => break :pr, // Would you know where to break to?
    }
    std.debug.print("The pull request has been merged.\n", .{});
}
