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

# Oddjobs

There are $N$ interns who have practically done nothing all day, other than raiding the snacks and
playing table tennis. No more! You, their manager have exactly $N$ jobs that need doing.
Thus you have decided to assign one intern to each of the jobs.

You've determined for each intern, how many mistakes they will make for each job you might assign them.
Not really wanting to make more work for yourself, you've decided to assign interns to job so as to minimise the
total number of mistakes made.

## Input

The first line of input will contain the single integer $N$ ($1 \leq N \leq 15$), the number of interns (and the number
of jobs).

$N$ lines follow, each containing $N$ integers.
On the $i$-th line, the $j$-th integer denotes the number of mistakes the $i$-th intern will make doing the $j$-th job.

Each intern will make somewhere bewteen 10 and 100 mistakes on any given job.

## Output

Output the fewest total mistakes you can achieve if you assign jobs to interns optimally.

## Sample Input
```
3
80 50 30
40 50 70
20 20 10
```

## Sample Output
```
90
```

## Explanation

You can assign:

- The first intern to the third job, leading to 30 mistakes.
- The second intern to the first job, leading to 40 mistakes.
- The third intern to the second job, leading to 20 mistakes.

This gives a total of 90 mistakes, which is the least you can do.
