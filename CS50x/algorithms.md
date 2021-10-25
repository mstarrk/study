# Algorithms.

## Searching.

It turns out that, with arrays, a computer can’t look at all of the elements at once.
Instead, a computer can only to look at them one at a time, though the order can be arbitrary

**Searching** is how we solve the problem of finding a particular value.
A simple case might have an input of some array of values,
and the output might simply be a bool, whether or not a particular value is in the array.

Today we’ll look at **algorithms for searching**.

To discuss them, we’ll consider **running time**, or **how long an algorithm takes to run given some size of input**.

### Big O notation.

![A graphic about algorithm's running time](https://cs50.harvard.edu/x/2021/notes/3/running_time.png)

Recall that **the red line is searching linearly, one page at a time;**
**the yellow line is searching two pages at a time**;
and **the green line is searching logarithmically**, dividing the problem in half each time.

And these running times are for the worst case, or the case where the value takes the longest to find
(on the last page, as opposed to the first page).

The more formal way to describe each of these running times is with **big O notation**, which we can think of as “on the order of”.
For example, if our algorithm is linear search, it will take approximately O(n) steps, read as “big O of n” or “on the order of n”.
In fact, even an algorithm that looks at two items at a time and takes n/2 steps has O(n).

This is because, as gets bigger and bigger, only the dominant factor, or largest term, n, matters.

In the chart above, if we zoomed out and changed the units on our axes,
we would see the red and yellow lines end up very close together.

A logarithmic running time is O(\log n), no matter what the base is, since this is just an approximation of what
fundamentally happens to running time if n is very large.

### There are some common running times:

    - O(n^2)
    - O(n \log n)
    - O(n) - (searching one page at a time, in order)
    - O(\log n) - (dividing the phone book in half each time)
    - O(1) - An algorithm that takes a **constant number of steps**, regardless of how big the problem is.

Computer scientists might also use **big Ω, big Omega notation, which is the lower bound of number of steps for our algorithm.**
**Big O is the upper bound** of number of steps, **or the worst case.**


### Linear search, binary search.

On stage, we have a few prop doors, with numbers hidden behind them. Since a computer can only look at
one element in an array at a time, we can only open one door at a time as well.

If we want to look for the number zero, for example, we would have to open one door at a time, and
if we didn’t know anything about the numbers behind the doors, the simplest algorithm would be going from left to right.

So, we might write **pseudocode for linear search** with:

```
For i from 0 to n–1
    If number behind i'th door
        Return true
Return false
```

* We label each of n doors from 0 to n–1, and check each of them in order.
* “Return false” is outside the for loop, since we only want to do that after we’ve looked behind all the doors.
* The big O running time for this algorithm would be O(n), and the lower bound, big Omega, would be Ω(1).

If we know that the numbers behind the doors are sorted, then we can start in the middle, and find our value more efficiently.

For **binary search, our algorithm might look like**:

```
If no doors
    Return false
If number behind middle door
    Return true
Else if number < middle door
    Search left half
Else if number > middle door
    Search right half
```

The upper bound for binary search is O(\log n), and the lower bound also Ω(1),
if the number we’re looking for is in the middle, where we happen to start.

With 64 light bulbs, we notice that linear search takes much longer than binary search, which only takes a few steps.
We turned off the light bulbs at a frequency of one hertz, or cycle per second,
and a processor’s speed might be measured in gigahertz, or billions of operations per second.

## Sorting.

If our input is an unsorted list of numbers, there are many algorithms
we could use to produce an output of a sorted list, where all the elements are in order.

With a sorted list, we can use binary search for efficiency, but it might take more time to write a sorting algorithm for
that efficiency, so sometimes we’ll encounter the tradeoff of time it takes a human to write a program compared to the time
it takes a computer to run some algorithm. Other tradeoffs we’ll see might be time and complexity, or time and memory usage.

### Selection sort.

Brian is backstage with a set of numbers on a shelf, in unsorted order:

```
6 3 8 5 2 7 4 1
```

Taking some numbers and moving them to their right place, Brian sorts the numbers pretty quickly.
Going step-by-step, Brian looks at each number in the list, remembering the smallest one we’ve seen so far.

He gets to the end, and sees that 1 is the smallest, and he knows that must go at the beginning,
so he’ll just swap it with the number at the beginning, 6:

```
6 3 8 5 2 7 4 1
–             –
1 3 8 5 2 7 4 6
```

Now Brian knows at least the first number is in the right place, so he can look for the smallest number among the rest,
and swap it with the next unsorted number (now the second number):

```
1 3 8 5 2 7 4 6
  –     –
1 2 8 5 3 7 4 6
```

And he repeats this again, swapping the next smallest, 3, with the 8:

```
1 2 8 5 3 7 4 6
    -   -
1 2 3 5 8 7 4 6
```

After a few more swaps, **we end up with a sorted list**.

This algorithm is called **selection sort**, and we can be a bit more specific with some pseudocode:

```
For i from 0 to n–1
    Find smallest item between i'th item and last item
    Swap smallest item with i'th item
```

    - The first step in the loop is to look for the smallest item in the unsorted part of the list,
    which will be between the i’th item and last item, since we know we’ve sorted up to the “i-1’th” item.
    - Then, we swap the smallest item with the i’th item, which makes everything up to the item at i sorted.

We look at a [visualization online](https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html) with animations for how the elements move for selection sort.

For this algorithm, we were looking at roughly all n elements to find the smallest, and making n passes to sort all the elements.

### Bubble sort.

We can try a different algorithm, **one where we swap pairs of numbers repeatedly, called bubble sort.**

Brian will look at the first two numbers, and swap them so they are in order:

```
6 3 8 5 2 7 4 1
– –
3 6 8 5 2 7 4 1
```

The next pair, 6 and 8, are in order, so we don’t need to swap them.
The next pair, 8 and 5, need to be swapped:

```
3 6 8 5 2 7 4 1
    – –
3 6 5 8 2 7 4 1
```

Brian continues until he reaches the end of the list:

```
3 6 5 2 8 7 4 1
        – –
3 6 5 2 7 8 4 1
          – –
3 6 5 2 7 4 8 1
            – –
3 6 5 2 7 4 1 8
              -
```

Our list isn’t sorted yet, but we’re slightly closer to the solution because the biggest value, 8, has been shifted all the way
to the right. And other bigger numbers have also moved to the right, or “bubbled up”.

Brian will make another pass through the list:

```
3 6 5 2 7 4 1 8
– –
3 6 5 2 7 4 1 8
  – –
3 5 6 2 7 4 1 8
    – –
3 5 2 6 7 4 1 8
      – –
3 5 2 6 7 4 1 8
        – –
3 5 2 6 4 7 1 8
          - –
3 5 2 6 4 1 7 8
            - -
```

    - Note that we didn’t need to swap the 3 and 6, or the 6 and 7.
    - But now, the next biggest value, 7, moved all the way to the right.

Brian will repeat this process a few more times, and more and more of the list becomes sorted, until we have a fully sorted list.

With selection sort, the best case with a sorted list would still take just as many steps as the worst case,
since we only check for the smallest number with each pass.

The pseudocode for bubble sort might look like:

```
Repeat until sorted
    For i from 0 to n–2
        If i'th and i+1'th elements out of order
            Swap them
```

    - Since we are comparing the i'th and i+1'th element, we only need to go up to n – 2 for i. Then, we swap the two elements if they’re out of order.
    - And we can stop as soon as the list is sorted, since we can just remember whether we made any swaps. If not, the list must be sorted already.

To determine the running time for bubble sort, we have n-1 comparisons in the loop, and at most n-1 loops, so we get n^2 – 2n + 2 steps total.

But the largest factor, or dominant term, is again n^2 as n gets larger and larger, so we can say that bubble sort has O(n^2).

So it turns out that fundamentally, selection sort and bubble sort have the same upper bound for running time.

The lower bound for running time here would be Ω(n), once we look at all the elements once.

### So our upper bounds for running time that we’ve seen are:

    - O(n^2) - selection sort, bubble sort.
    - O(n \log n)
    - O(n) - linear search.
    - O(\log n) - binary search.
    - O(1)

### And for lower bounds:

    - Ω(n^2) - selection sort.
    - Ω(n \log n)
    - Ω(n) - bubble sort.
    - Ω(\log n)
    - Ω(1) linear search, binary search.
    
### Merge sort.
