> ★ Describe a $\Theta(n\lg{n})$-time algorithm that, given a set $S$ of $n$
> integers and another integer $x$, determines whether or not there exist two
> elements in $S$ whose sum is exactly $x$.

## Description

Assume that $S$ is an array of $n$ elements (otherwise, we could iterate over it an store its elements in an array in linear time). First we sort $S$ in
$\Theta(n\lg{n})$ time. Then we iterate over its $n$ elements and for each of
them look for $x - S[i]$ in $S$ (where $S[i]$ is the current element) using
binary search. If any of the lookups succeeds, return true, otherwise, false.
This leads to a $\Theta(n\lg{n})$ running time, since we sort in
$\Theta(n\lg{n})$ and the **for** loop makes $n$ iterations, each of them
taking $\Theta(\lg{n})$, i.e., $\Theta(n\lg{n})$.

## Pseudocode

```
2-Sum(S, x)
  Merge-Sort(S)
  for i = 1 to S.length
      if Binary-Search(S, x - S[i]) != NIL
          return true
  return false
```

## Bonus

Another way of solving it in $\Theta(n\lg{n})$ without the use of binary
search.

```
2-Sum(S, x)
  Merge-Sort(S)
  i = 1
  j = S.length
  while i < j
      if S[i] + S[j] < x
          ++i
      else if S[i] + S[j] > x
          --j
      else
          return true
  return false

```
