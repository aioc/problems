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
- \rhead{}
- \cfoot{}
- \renewcommand{\headrulewidth}{0.0pt}
- \renewcommand{\footrulewidth}{0.0pt}
---

# Omo

Opal has reached the gates to strange kingdom of Omo, the land of bizzare, mythical and palindromic creatures called *doges*. In order to test Opal's worthiness of entering the kingdom, the great *doge god* of Omo decides to give her a challenge. In the challenge, Opal is given a word in the language of Omo, consisting of letters in the Omo alphabet. This word can be represented as an array of $N$ integers (numbered from $1$ to $N$) between 1 and 123454321 inclusive. 

Opal is given time to memorise the sequence, and then the doge god will give her $Q$ queries. The $i$-th query is of the form: *Is it possible to rearrange the letters in the subarray from $l_i$ to $r_i​$ inclusive, such that the resultant subarray is palindromic?*

Opal is a cybernetic being who possesses the magical power of infinite computation and infinite memory, so she completes the doge god's challenge instantly. Unfortunately, you are not. Can you complete it using a computer program instead?

## Input

The first line contains two integers, $N​$ and $Q​$. The second line contains $N​$ integers: the word that Opal is given.

Then, $Q$ lines follow. The $i$-th of these lines contains two integers: $l_i$ and $r_i$.

## Output

Output $Q$ lines. The $i$-th of these lines should contain the answer to the $i$-th query: either `YES` or `NO`.

## Sample Input

```
22 6
87 79 87 95 83 85 67 72 95 68 79 71 69 95 71 79 68 95 72 67 85 83
4 22
9 9
10 17
10 11
9 17
10 18
```

## Sample Output

```
YES
YES
NO
NO
YES
YES
```

\newpage

## Explanation

Converted via ASCII, the sample input reads: `WOW_SUCH_DOGE_GOD_HCUS`

1. For the first query, the substring is `_SUCH_DOGE_GOD_HCUS`. This string can be rearranged into `__SUCHDOGEGODHCUS__`, which is a palindrome.
2. For the second query, the substring is `_`. This is already a palindrome.
3. For the third query, the substring is `DOGE_GOD`. It is not possible to rearrange this into a palindrome.
4. For the fourth query, the substring is `DO`. It is not possible to rearrange this into a palindrome.
5. For the fifth query, the substring is `_DOGE_GOD`. This can be rearranged into `_DOGEGOD_`, which is a palindrome.
6. For the sixth query, the substring is `DOGE_GOD_`. This can be similarly rearranged into `_DOGEGOD_`.

## Subtasks and Constraints

You are guaranteed that:

- $1 \leq N \leq 100000$.
- $1 \leq Q \leq 100000$.
- The numbers in the array will be between 1 and 123454321 inclusive.
- $1 \leq l_i \leq r_i \leq N$, for each query.
