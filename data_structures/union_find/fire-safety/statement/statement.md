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

# Fire Safety

In the concrete maze of the CBD, it was recently discovered that there is no universal fire safety coverage!
Construction of a safety system begins immediately: high pressure water mains are installed in some buildings, while pipes are built to connect them to other buildings.
Any building that contains a water main, or is connected to one by a series of pipes via other buildings, is considered _safe_.

Unfortunately, the safety inspection bureau has started doing spot checks immediately, giving companies no time to prepare, so they hire you to figure out which spot checks will be failed, given a schedule of the safety system rollout and inspections.


## Input
The first line of input will contain two space-separated integers, $N$ ($1 \leq N \leq 1,000,000$) and $Q$ ($1 \leq Q \leq 100,000$), the number of buildings in the CBD (numbered $1$ to $N$), and the length of the schedule, respectively.
Each of the following $Q$ lines will be of the form:

- `P i j`: a pipe is installed connecting buildings $i$ and $j$
- `M i`: a high pressure water main is installed in building $i$
- `C i`: a spot check is conducted in building $i$

## Output
For each input line describing a spot check, output a line containing a single integer `0` if the building fails the spot check, or `1` if it passes.

## Sample Input
```
4 7
P 1 2
C 1
P 1 3
M 2
C 3
P 1 4
C 4
```

## Sample Output
```
0
1
1
```

## Explanation
When the first check is conducted, there are no water mains installed, so building 1 fails the check.
By the second check, pipes have been installed connecting building 3 to building 2 via building 1, and there is a water main at building 2, so building 3 is safe.
Building 4 is also connected indirectly to the water main in building 2 when its check occurs, so it also passes.


