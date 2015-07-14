> Suppose we are comparing implementations of insertion sort and merge sort on
> the same machine. For inputs of size $n$, insertion sort runs in $8n^2$
> steps, while merge sort runs in $64n\lg{n}$ steps. For which values of $n$
> does insertion sort beat merge sort?

We have to solve for non-negative $n$ the inequality

$$
\begin{align*}
    8n^2 &< 64n\lg{n} \\
    n^2 &< 8n\lg{n} \\
    n &< 8\lg{n}
\end{align*}
$$

which holds for $\forall{n} \in \{2, 3, ..., 43\}$.
