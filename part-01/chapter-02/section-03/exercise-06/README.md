> Observe that the **while** loop of lines 5–7 of the *Insertion-Sort*
> procedure in Section 2.1 uses a linear search to scan (backward) through the
> sorted subarray $A[1 .. j - 1]$. Can we use a binary search
> (see [Exercise 2.3-5][]) instead to improve the overall worst-case running
> time of insertion sort to $\Theta(n\lg{n})$?

The goal of this **while** loop is to find the place where $A[j]$ should stand
and accommodate place for it, i.e., shift all scanned elements to the right by
$1$. By using binary search, we could find the place of $A[j]$ in
$\Theta(\lg{n})$ time, but the shifting would still be linear, causing a
worst-case running time of $\Theta(n^{2})$.

[Exercise 2.3-5]: /part-01/chapter-02/section-03/exercise-05/README.md
