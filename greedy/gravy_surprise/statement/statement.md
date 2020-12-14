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
- \lhead{\textsl{Alpha Trial Exam I -- 2020}}
- \rhead{\thepage}
- \cfoot{}
- \renewcommand{\headrulewidth}{0.0pt}
- \renewcommand{\footrulewidth}{0.0pt}
---

# Gravy Surprise

Input File | Output File | Time Limit | Memory Limit
--- | --- | --- | ---
standard input | standard output | 1 second | 256 MiB

Your PHUN team has just come up with a proof that P=NP. The prize is a guaranteed reserve position for the IOI, and a very long bar of CruelerSurprise chocolate.
The bar of chocolate is made up of a single row of $N$ chocolate squares, where each square has a different flavour.
Some of the flavours are divine, but some are not so tasty. Last time you tried this chocolate, you snapped off 3 squares which turned out to be broccoli, rhubarb and gravy flavour, leaving you less than impressed.

Being good teammates, you collectively agree that the bar of chocolate should be divided up so that no one person has to suffer.
You wish to break the chocolate bar in $K$-1 places, forming $K$ pieces--one for each team member.
A piece consists of one or more squares. Each square is assigned a tastiness rating. The tastiness of a piece is the sum of the tastiness ratings for each square in it.

You are not sure which of the $K$ pieces you will receive, so you wish to ensure that the minimum tastiness amongst all the pieces is as high as possible.
Your task is to determine what this minimum tastiness is.

## Input

The first line of input will contain two integers $N$ and $K$, representing the total number of pieces in the chocolate bar ($1 \leq N \leq  100\,000$), and the number of people in your team ($1 \leq K \leq N$).

The second line of input will contain $N$ additional lines of input, describing each square of the chocolate bar in order from left to right.
Each integer will be between $1$ and $100\,000$ inclusive, representing the tastiness rating of that particular square.

## Output

Your output should consist of a single line containing a single integer: the maximum value of the lowest tastiness rating amongst the $K$ pieces that can be achieved.

Note: We suggest making use of `long long int` as the answer can be quite large.

## Subtasks and Constraints

Additional constraints for each subtask are given below.

Subtask | Points | Additional constraints
:---: | :---: | -------------------------------------------------------------
1 | 16 | $K = 2$ 
2 | 30 | $K = 3$ 
3 | 32 | $N \leq 100$ 
4 | 8  | $N \leq 1000$ 
5 | 14 | No further constraints apply.


## Sample Input 1
```
5 2
9 7 3 7 4
```

## Sample Output 1
```
14
```

## Sample Input 2

```
8 4
2 1 3 1 1 1 1 2
```

## Sample Output 2

```
3
```

## Explanation

In Sample Input 1, the chocolate bar has five squares, and needs to be split into two pieces. The best way to split it is between the second and third squares, giving two pieces with tastiness rating 16 and 14 respectively. In this case the lowest tastiness rating is 14.

In Sample Input 2, this chocolate bar can be perfectly divided into four pieces each with a tastiness rating of 3.
