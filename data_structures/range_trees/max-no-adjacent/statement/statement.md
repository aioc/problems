---
date: July 14th 2016
header-includes:
- \usepackage{fancyhdr}
- \usepackage{multicol}
- \usepackage{svg}
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

# Maximum Non-Adjacent Subsequence Sum

There is an array of $N$ integers. Initially, the i-th element (indexed starting at 1) is $A_i$.
A _non-adjacent subsequence_ of an array is a subset of elements such that no two adjacent elements of the array are in
the subset.
The _maximum non-adjacent subsequence sum_ (MNASM) of an array is the sum of the elements in the non-adjacent subsequence with
the largest sum.

For example, the MSANM of:

* [3, 2, 1] is 4: [**3**, 2, **1**].
* [20, 2, 3, 10, 6] is 30: [**20**, 2, 3, **10**, 6].
* [100, 100] is 100: [100, **100**].

You are tasked with facilitating $B$ operations. There are two types of operations:

* `U i x`: Update the value of the $i$-th element to $x$.
* `Q l r`: Query the MANSM of the subarray starting at the $l$-th element and ending
  at the $r$-th element, inclusive.


## Constraints

You are guaranteed that:

* $1 \leq N \leq 100\,000$.
* $1 \leq B \leq 100\,000$.
* There will be at least one query.
* Each element will be between $1$ and $10\,000$ inclusive before all updates, and after each update.
* $1 \leq l \leq r \leq N$, for each query.

\newpage

## Input

* The first line of input contains the two integers $N$ and $B$.
* The second line contains $N$ integers.
  The $i$-th integer (starting from 1) is $A_i$.
* Then, $B$ lines follow describing the operations. Each line begins with a character describing the type of query
  (`U` for update, and `Q` for query).
    * `U`: Two integers $i$ and $x$ follow, indicating that the $i$-th element is changed to $x$.
    * `Q`: Two integers $l$ and $r$ follow, querying the MSNASM of the subarray from the $l$-th to the $r$-th element
      inclusive.

## Output

The output should contain one line for each query. The $i$-th line should give the answer
to the $i$-th query.

## Sample Input
```
6 7
100 300 20 90 150 90
Q 1 6
U 2 10
Q 1 6
Q 3 5
U 6 30
Q 6 6
Q 3 4
```

## Sample Output
```
480
280
170
30
90
```

## Explanation

* For the 1st query: [100, **300**, 20, **90**, 150, **90**].
* For the 2nd query: [**100**, 10, 20, **90**, 150, **90**].
* For the 3rd query: [**20**, 90, **150**].
* For the 4th query: [**30**].
* For the 5th query: [20, **90**].
