# Discrete Math — Grid Coverage with Length-3 Simple Paths

## 📘 Project Overview

This project is a coursework assignment for the *Discrete Mathematics* course at the **National Polytechnic University of Armenia**, developed using **C++** and the **Qt Framework**.

The aim of the project is to implement an algorithm that covers all edges of an `m x n` grid using only **simple paths of length 3**, such that:

* Every edge is covered exactly once.
* The entire grid is decomposed into such non-overlapping paths.

## 📌 Problem Statement

Given a rectangular `m x n` grid graph, cover all its edges using simple paths of length 3. Each such path consists of 3 consecutive edges (4 vertices). The grid must be fully covered with no overlapping or repeated edge usage.

### Conditions for Valid Coverage

The grid can be covered with paths of length 3 **if and only if** the number of edges is divisible by 3, which occurs in the following two cases:

1. Both `m` and `n` are divisible by 3.
2. Both `m` and `n` leave a remainder of 1 when divided by 3 (i.e. `m % 3 == 1` and `n % 3 == 1`).

## 🧮 Edge Count Formula

To determine if coverage is possible:

```
Edges = (m – 1) * n + (n – 1) * m
```

This must be divisible by 3.

## 📈 Algorithm Overview

Depending on the grid size:

* For the `(m % 3 == 0 && n % 3 == 0)` case:

  * Cover rows horizontally with length-3 chains.
  * Use leftover columns to create vertical chains.
* For the `(m % 3 == 1 && n % 3 == 1)` case:

  * Cover all rows horizontally and all columns vertically, adjusting for borders.

In all other cases, the grid **cannot** be covered using only 3-length simple chains.

## 🔧 Technologies Used

* **C++**
* **Qt Framework**

## 📷 Sample Output

Visualizations are generated using Qt, showing distinct colors for different chains. Example configurations such as `3x3` and `4x4` grids are provided.

## 🔗 Project Repository

👉 [GitHub Repository](https://github.com/NarekSardaryan2004/Discrete-math)

## 📚 References

* Ռ․ Ն․ Տոնոյան — Դիսկրետ մաթեմատիկայի դասընթաց
* Պ․ Ա․ Պետրոսյան, Վ․ Վ․ Մկրտչյան, Ռ․ Ռ․ Քամալյան — Գրաֆների տեսություն
