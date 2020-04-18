---
date: July 14th 2016
header-includes:
- \usepackage{fancyhdr}
- \usepackage{multicol}
- \setlength{\textheight}{225mm}
- \setlength{\textwidth}{150mm}
- \setlength{\oddsidemargin}{6.6mm}
- \setlength{\evensidemargin}{6.6mm}
- \setlength{\topmargin}{-5.4mm}
- \pagestyle{fancy}
- \lhead{}
- \rhead{\thepage}
- \cfoot{}
- \renewcommand{\headrulewidth}{0.0pt}
- \renewcommand{\footrulewidth}{0.0pt}
---

# Big Range Queries and Updates

There is an array of $N$ integers. Initially, all elements have value zero. We will perform range queries and updates in this array.

You want to support the following updates:

* **A**dd $v_i$ to all elements of the array between $l_i$ and $r_i$ inclusive.
* **S**et all elements of the array between $l_i$ and $r_i$ inclusive to the value $v_i$.

You want to support the following queries:

* What is the **T**otal sum of a range? That is what is the sum of A$[l_i \dots r_i]​$?
* What is the **M**ax value of a range A$[l_i \dots r_i]​$?

## Input

The first line contains two integers, $N$ and $Q$. Then $Q$ lines follow, each of one of the following forms:

* A $l_i$ $r_i$ $v_i$
* S $l_i$ $l_i$ $r_i$ $v_i$
* T $l_i$ $r_i$ 
* M $l_i​$ $r_i​$

These correspond to the 2 updates followed by the 2 queries in the above described order. You are guaranteed there is at least one query, and that is there is at least one line starting with **T** or **M**.

## Output

One line for each **T** or **M** query. For **T** queries, the sum of the current values of $A$ between$[l_i, r_i]$. For **M** queries, the max of the current values of A between $[l_i, r_i]$.


## Constraints

You are guaranteed that:

* $1 \leq N \leq 10^9​$.
* $1 \leq Q \leq 10^5$.
* $0 \leq v_i \leq 10^4​$.
* $0 \leq l_i \leq r_i \leq N-1$, for each query.

\newpage

## Sample Input

```
3 8
A 0 1 3
T 0 2
S 1 2 4
T 0 2
M 0 0
M 0 1
A 1 1 1
T 0 2
```

## Sample Output

```
6
11
3
4
12
```

