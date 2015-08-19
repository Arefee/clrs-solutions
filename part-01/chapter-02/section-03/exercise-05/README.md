> Referring back to the searching problem (see [Exercise 2.1-3][]), observe
> that if the sequence $A$ is sorted, we can check the midpoint of the sequence
> against $\nu$ and eliminate half of the sequence from further consideration.
> The ***binary search*** algorithm repeats this procedure, halving the size
> of the remaining portion of the sequence each time. Write pseudocode, either
> iterative or recursive, for binary search. Argue that the worst-case running
> time of binary search is $\Theta(\lg{n})$.

## Pseudocode

```
Binary-Search(A, v)
  lower = 1
  upper = A.length
  while lower <= upper
      middle = (lower + upper) / 2
      if A[middle] < v
          upper = middle - 1
      else if A[middle] > v
          lower = middle + 1
      else
          return middle
  return NIL
```

## Worst-case running time

Let $n$ be the number of elements in the subarray $A[lower..upper]$. At each
iteration of the **while** loop we are cutting $n$ in half until it gets to
$0$ (using integer division) or we find $\nu$. The worst-case occurs when
$\nu$ is not in $A$. In this case the number of the **while** loop iterations
will equal the number of times we have to divide $n$ by $2$ till it goes to
$0$, which is $\lfloor \lg{n} \rfloor + 1$. Therefore, the worst-case running
time of ***binary search*** is $\Theta(\lg{n})$.

[Exercise 2.1-3]: /part-01/chapter-02/section-01/exercise-03/README.md
