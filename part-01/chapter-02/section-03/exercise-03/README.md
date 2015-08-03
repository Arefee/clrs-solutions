> Use mathematical induction to show that when $n$ is an exact power of $2$,
> the solution of the recurrence
> 
> $$
>     T(n) = 
>     \begin{cases}
>         2             & \text{if } n = 2, \\[2ex]
>         2T(n / 2) + n & \text{if } n = 2^{k}, \text{for } k > 1
>     \end{cases}
> $$
> 
> is $T(n) = n\lg{n}$

## Base case

For $n = 2$ (since $T(n)$ is defined only for $n = 2^{i}, i \ge 1$)

$$
    T(2) = 2 = 2 \cdot 1 = 2\lg{2}
$$

## Inductive hypothesis

Assume that $T(2^{i}) = 2^{i}\lg{2^{i}}$ for some fixed $i \ge 1$.

## Inductive step

Let $n = 2^{i + 1}$. Then

$$
\begin{aligned}
    T(2^{i + 1}) &= 2T(2^{i}) + 2^{i + 1}               \\
                 &= 2 \cdot 2^{i}\lg{2^{i}} + 2^{i + 1} \\
                 &= 2^{i + 1}i + 2^{i + 1}              \\
                 &= 2^{i + 1}(i + 1)                    \\
                 &= 2^{i + 1}\lg{2^{i + 1}}
\end{aligned}
$$
