> Rewrite the *MERGE* procedure so that it does not use sentinels, instead
> stopping once either array $L$ or $R$ has had all its elements copied back
> to $A$ and then copying the remainder of the other array back into $A$.

```
Merge(A, p, q, r)
  n1 = q - p + 1
  n2 = r - q
  let L[1 .. n1] and R[1 .. n2] be new arrays
  for i = 1 to n1
      L[i] = A[p + i - 1]
  for j = 1 to n2
      R[j] = A[p + j]
  i = 1
  j = 1
  k = 1
  while i <= n1 and j <= n2
      if L[i] <= R[i]
          A[k] = L[i]
          i = i + 1
      else
          A[k] = R[j]
          j = j + 1
      k = k + 1
  while i <= n1
      A[k] = L[i]
      i = i + 1
      k = k + 1
  while j <= n2
      A[k] = R[j]
      j = j + 1
      k = k + 1
```
