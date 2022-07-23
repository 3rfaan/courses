# How does Quicksort work?

The algorithm is working as follows:

- Take the value in the **middle** of the array, and move it to the **front** (by swapping). This value is the **pivot**.

- Loop through the rest of the array. Each time you see a value _less than the pivot_, swap it to closer to the _front of the array_. Specifically we have an index (named **last**) that keeps track of where the last lesser value was swapped to. Each time we find a lesser value we _increment_ it to find a spot to put that value.

- When you reach the end, the array consists of:
  - the pivot
  - all values less than the pivot
  - all values greater than or equal to the pivot
- Swap the pivot with the location of the last found lesser value.

At this point you know have a sub-array on either side of the pivot. To the left you have the values less than the pivot, to the right all values greater than or equal to the pivot. So you know that the pivot is in exactly the correct spot for the final sorted array. You also know that no values from either sub-array will need to swap with those on the other side. So you can now:

- sort the left sub-array with the same algorithm
- sort the right sub-array with the same algorithm.

Each time you recurse, you have smaller sub-arrays, so the next level of recursion is quicker. Also each time, you move one element into the correct position, before going deeper. Eventually you reach the point where there is only zero or one element in a sub-array, which of course means that sub-array is already sorted. What you end up with at any level is an element in the right spot, with a sorted sub-array of lesser values to the left, and a sorted sub-array of greater or equal values to the right, so you know the whole (sub-)array at that level is sorted.
