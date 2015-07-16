> How can we modify almost any algorithm to have a good best-case running time?

We could pick one instance of the problem and add an **if** statement that
solves that specific instance by instantly returning the correct answer. This
way we could get the best-case running time of any algorithm down to
$\Theta(n + m)$, where $n$ is the length of the input and $m$ is the length of
the output.
