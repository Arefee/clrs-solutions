> We can express insertion sort as a recursive procedure as follows. In order
> to sort $A[1..n]$, we recursively sort $A[1..n - 1]$ and then insert $A[n]$
> into the sorted array $A[1..n - 1]$. Write a recurrence for the running time
> of this recursive version of insertion sort.

If the array has only one element, then it is already sorted and we have
nothing to do (i.e. $\Theta(1)$). Otherwise, the running time is the running
time of the algorithm for the first $n - 1$ elements of the array
(i.e. $T(n - 1)$) plus the time to insert the last element into the sorted
$A[1..n - 1]$ (i.e. $\Theta(n - 1) \equiv \Theta(n)$).

$$
    T(n) = 
    \begin{cases}
        \Theta(1)            & \text{if } n = 1, \\[2ex]
        T(n - 1) + \Theta(n) & \text{otherwise}
    \end{cases}
$$
