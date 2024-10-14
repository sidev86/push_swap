<h1>push_swap</h1>


<h2>Description</h2>

The push_swap project is a sorting algorithm challenge designed to work with two stacks: a and b. The goal is to sort the numbers in stack a in ascending order using the fewest possible operations. The stack initially contains a set of random, non-duplicated integers, while stack b starts empty. You must use a predefined set of operations to manipulate the elements between these stacks.

<h2>Operations</h2>

Here is a list of operations available to manipulate the stacks:

<ul>
  <li><strong><code>sa</code></strong>: Swap the first two elements at the top of stack a.</li>
  <li><strong><code>sb</code></strong>: Swap the first two elements at the top of stack b.</li>
  <li><strong><code>pa</code></strong>: Push the top element of stack b onto stack a.</li>
  <li><strong><code>pb</code></strong>: Push the top element of stack a onto stack b.</li>
  <li><strong><code>ra</code></strong>: Rotate stack a (shift all elements up, the first becomes the last).</li>
  <li><strong><code>rb</code></strong>: Rotate stack b.</li>
  <li><strong><code>rra</code></strong>: Reverse rotate stack a (shift all elements down, the last becomes the first).</li>
  <li><strong><code>rrb</code></strong>: Reverse rotate stack b.</li>
</ul>

<h2>Project Rules</h2>

<ul>
  <li>The program must minimize the number of operations needed to sort the stack.</li>
  <li>Every instructions is printed separated on a newline.</li>
  <li>There's a limit in number of operations allowed based on the number of elements that are in the stack</li>
</ul>


<h2>Usage</h2>

The program takes a list of integers as input and outputs a sequence of operations required to sort stack a. <br>
Here you have an example:

```bash
$ ./push_swap 2 1 3 6 5
ra
pb
rra
pb
sa
ra
pa
pa
```

<h2>Bonus (checker)</h2>

This optional part of the project include a checker program. The checker verifies that the sequence of operations generated by push_swap correctly sorts stack a, reads the instructions from standard input and verifies that after all the operations, stack a is sorted and stack b is empty.
<br>

<h3>How it works</h3>
The checker program verifies if the push_swap instructions correctly sort stack a. It accepts a list of integers as input, representing stack a (e.g., ./checker 3 2 1 0). After inputting the arguments, it waits for instructions via standard input, one per line, which you can end by pressing Ctrl + D (Linux/macOS) or Ctrl + Z (Windows). The program then executes the instructions on stack a and stack b.<br>Finally, it outputs "OK" if stack a is sorted in ascending order and stack b is empty; otherwise, it prints "KO" or "Error" for invalid instructions.
<br><br>
Example usage:

```bash
$ ./checker 3 2 1 0
rra
pb
sa
rra
pa
# (Press Ctrl + D to signal EOF)
OK
```



<h2>The Visualizer</h2>

![push swap visualizer](https://raw.githubusercontent.com/sidev86/push_swap/master/visualizer.gif)


The visualizer is a useful program that shows the sorting process and counts the number of operations needed to sort the stack
<br>
<h3>Link</h3>
<a href="https://github.com/o-reo/push_swap_visualizer">push_swap visualizer</a>


<h2>Compilation Instructions</h2>

Type <strong><code>make</code></strong> to generate the executable <strong><code>push_swap</code></strong>

For the checker type <strong><code>make bonus</code></strong> to generate the executable <strong><code>checker</code></strong>








