> Consider the ***searching problem***:
> 
> **Input:** A sequence of $n$ numbers $A = \langle a_1, a_2,..., a_n \rangle$
> and a value $\nu$.  
> **Output:** An index $i$ such that $v = A[i]$ or the special value $NIL$ if
> $\nu$ does not appear in $A$.
> 
> Write pseudocode for ***linear search***, which scans through the sequence,
> looking for $\nu$. Using a loop invariant, prove that your algorithm is
> correct. Make sure that your loop invariant fulfills the three necessary
> properties.

## Pseudocode

```python
Linear-Search(A, v)
  for i = 1 to A.length
      if A[i] == v
          return i
  return NIL
```

## Loop invariant

> At the start of each iteration of the **for** loop, $\nu$ does not appear in
> $A[1..i - 1]$.

### Initialization

For $i = 1$ the array $A[1..0]$ is the empty array and trivially $\nu$ is not
in it.

### Maintenance

Let $i = k$, i.e., we are about to enter the $k$th iteration, and the loop
invariant holds, i.e., $\nu$ is not in $A[1..k - 1]$. If we get to the next
iteration, then $A[k] \ne \nu$, because otherwise we would return in the body
of the **if** statement. Then for $i = k + 1$ we have that $A[k] \ne \nu$ and $A[j] \ne \nu, \forall j = 1,...,k - 1$. Therefore,
$A[j] \ne \nu, \forall j = 1,...,k$, i.e., the invariant holds for $i = k + 1$.

### Termination

The loop could terminate becase of the return in the **if** statement. If this
is the case, then $\exists i: A[i] = \nu$ and the algorithm would return $i$,
i.e., it is correct.

Another way for the loop to terminate is when $i = A.length + 1$. Then by the
loop invariant, we have that $A[j] \ne \nu, \forall j = 1,...,A.length$. In
this case the algorithm would return $NIL$, i.e., it is again correct.
