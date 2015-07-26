> Consider linear search again (see Exercise 2.1-3). How many elements of the
> input sequence need to be checked on the average, assuming that the element
> being searched for is equally likely to be any element in the array? How
> about in the worst case? What are the average-case and worst-case running
> times of linear search in $\Theta$-notation? Justify your answers.

## Best-case

The best-case occurs when the element we are looking for is the first in the
array. This means that the only "steps" that have to be performed are:
initializing the loop variable, checking the loop condition, checking the
**if** condition and returning, i.e., a constant number of "steps". This means
that the best-case running time is $\Theta(1)$.

## Average-case

Since any of the array elements is equally likely to be the one we are
searching for, on average we would have to search half of the array. This
implies $\frac{n}{2}$ order of growth, which is still $\Theta(n)$.

## Worst-case

The worst-case is when the element we are looking for is not in the array. Then
we would have to iterate through all of its elements to make sure that this is
the case. The running time is $\Theta(n)$.
