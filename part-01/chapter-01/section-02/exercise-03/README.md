> What is the smallest value of $n$ such that an algorithm whose running time
> is $100n^2$ runs faster than an algorithm whose running time is $2^n$ on the
> same machine?

The smallest value of $n$ such that

$$
    100n^2 < 2^n
$$

is $0$.

The smallest value $n_0$ of $n$ such that

$$
    \forall n \geq n_0: 100n^2 < 2^n
$$

is $15$.
