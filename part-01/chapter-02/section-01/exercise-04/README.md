> Consider the problem of adding two $n$-bit binary integers, stored in two
> $n$-element arrays $A$ and $B$. The sum of the two integers should be stored
> in binary form in an $(n + 1)$-element array $C$. State the problem formally
> and write pseudocode for adding the two integers.

## Problem statement

**Input:** Two sequences of $n$ bits $A = \langle a_1, a_2,...,a_n \rangle$ and
$B = \langle b_1, b_2,...,b_n \rangle$, representing two binary integers $A'$
and $B'$.
**Output:** A sequence of $n + 1$ bits $C = \langle c_1, c_2,...,c_{n+1}
\rangle$, representing a binary integer $C'$ such that $C' = A' + B'$.

## Pseudocode

```
Add-Binary(A, B)
  let C[1 .. A.length + 1] be a new array
  carry = 0
  for i = C.length downto 2
      C[i]  = (A[i - 1] + B[i - 1] + carry) % 2
      carry = (A[i - 1] + B[i - 1] + carry) / 2
  C[i] = carry
  return C
```
