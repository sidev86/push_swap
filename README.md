<h1>push_swap</h1>


<h2>Description</h2>

The push_swap project is a sorting algorithm challenge designed to work with two stacks: a and b. The goal is to sort the numbers in stack a in ascending order using the fewest possible operations. The stack initially contains a set of random, non-duplicated integers, while stack b starts empty. You must use a predefined set of operations to manipulate the elements between these stacks.

<h2>Operations</h2>

Here is a list of operations available to manipulate the stacks:

<ul>
  <li>sa: Swap the first two elements at the top of stack a.</li>
  <li>sb: Swap the first two elements at the top of stack b.</li>
  <li>pa: Push the top element of stack b onto stack a.</li>
  <li>pb: Push the top element of stack a onto stack b.</li>
  <li>ra: Rotate stack a (shift all elements up, the first becomes the last).</li>
  <li>rb: Rotate stack b.</li>
  <li>rra: Reverse rotate stack a (shift all elements down, the last becomes the first).</li>
  <li>rrb: Reverse rotate stack b.</li>
</ul>

<h2>Usage</h2>

The program takes a list of integers as input and outputs a sequence of operations required to sort stack a. 
Example usage:

```bash
$ ./push_swap 2 1 3 6 5 8
sa
pb pb
pb sa
pa pa
pa
```


<h2>Usage</h2>
