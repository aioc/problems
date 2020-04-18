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

# InstaHarvest

Gwendoline is in charge of the world's largest apple growing operation. Her orchard consists of $N$ evenly spaced apple trees in a line, numbered from $1$ to $N$.
Initially, there are no apples on any of the trees.
Each day, every tree grows exactly one apple.
On some days, Gwendoline uses her InstaHarvest harvester to harvest some of the apple trees. Its state-of-the-art technology can instantly harvest all the apples from a contiguous range of trees.
Gwendoline needs to know how many apples actually get harvested each time she uses her harvester, so she hires you, an expert in the field, to calculate this for her.

## Input
The first line of input will contain two space-separated integers $N$ ($1 \leq N \leq 1,000,000,000$) and $Q$ ($1 \leq Q \leq 100,000$), the number of apple trees in Gwendolines orchard, and the number of harvest operations, respectively.
The next $Q$ lines will each contain three space-separated integers $d_i$ $a_i$ $b_i$, the day of the harvest operation, the first apple tree that is harvested, and the last apple tree that is harvested, respectively ($1 \leq d_i \leq 1,000,000,000$ [harvest season can be very long], $1 \leq a_i \leq b_i \leq N$). All $d_i$ are guaranteed to be in non-decreasing order.

## Output
Output $Q$ lines, the ith of which contains the number of apples that are harvested in harvest operation $i$.


## Sample Input
```
30 4
1 10 19
1 15 24
3 5 25
4 1 30
```

## Sample Output
```
10
5
48
57
```

## Explanation
On the first day, each tree has grown one apple. Harvesting trees 10 through 19 yields 10 apples, and immediately harvesting trees 15 through 24 gives a further 5 (since trees 15 through 19 are already empty).

On the third day, trees 5-9 and 25 each have 3 apples, and trees 10-24 have 2 apples. This gives a harvest of 48 apples.

On the fourth day, trees 5-25 each have 1 apple, and trees 1-4 and 26-30 have 4, giving 57 apples.
