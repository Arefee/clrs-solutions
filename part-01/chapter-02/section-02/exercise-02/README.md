> Consider sorting $n$ numbers stored in array $A$ by first finding the
> smallest element of $A$ and exchanging it with the element in $A[1]$. Then
> find the second smallest element of $A$, and exchange it with $A[2]$.
> Continue in this manner for the first $n - 1$ elements of $A$. Write
> pseudocode for this algorithm, which is known as ***selection sort***. What
> loop invariant does this algorithm maintain? Why does it need to run for
> only the first $n - 1$ elements, rather than for all $n$ elements? Give the
> best-case and worst-case running times of selection sort in
> $\Theta$-notation.

## Pseudocode

```python
Selection-Sort(A)
  for i = 1 to A.length - 1
      min = i
      for j = i + 1 to A.length
          if A[j] < A[min]
              min = j
      swap(A[i], A[min])
```

## Loop invariants 

#### Outer loop

> At the start of each iteration of the outer **for** loop, the subarray
> $A[1..i - 1]$ is sorted and consists of the smallest $i - 1$ elements of $A$.

#### Inner loop

> At the start of each iteration of the inner **for** loop, $A[min]$ is the
> smallest element in $A[i..j-1]$.

## Why are $n - 1$ iterations sufficient?

When the first **for** loop terminates $i = A.length$.
According to the invariant the subarray $A[1..A.length - 1]$ is sorted and
consists of the smallest $A.length - 1$ elements of $A$. Therefore,
$A[A.length]$ is the biggest element and it is in the correct position, i.e.,
the array $A$ is sorted. This is why it suffices for the loop to do only
$A.length - 1$ iterations.

## Running times

The best-case running time is $\Theta(n^{2})$ and it occurs when the input
array is sorted.

The worst-case running time is $\Theta(n^{2})$ and it occurs when the input
array is reverse sorted.
