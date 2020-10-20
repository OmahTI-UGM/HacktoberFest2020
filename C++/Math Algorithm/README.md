# Math Algorithm

This folder includes 3 math algorithms:
1. `matrix_exp.cpp` for finding n-th term of linear reccurence relation efficiently
Input:
```
N
A_11 A_12 ... A_1N
A_21 A_22 ... A_2N
 ...  ... ...  ...
A_N1 A_N2 ... A_NN
v_1 v_2 v_3 ... v_N
Q
n_1
n_2
...
n_Q
```
where:
- `A` is the reccurence matrix of size NxN
- `v` is the first N known value of the reccurence relation F, i.e. `v_k = F_k`
for `k = 1..N`
Output: `F_(n_k)` for every `n_k` in input. Since the number could grow very large, it will be modulo 1.000.000.007

2. `convex_hull.cpp` for finding convex hull from a set of points
Input:
```
N
X_1 Y_1
X_2 Y_2
...
X_N Y_N
```
where `X_k` and `Y_k` is the k-th point.
Output: 
The set of points in the convex hull.

3. `n_choose_k.cpp` for calculate N choose K
Input:
```
Q
N_1 K_1
N_2 K_2
...
N_Q K_Q
```
Output:
`C(N, K)` for every N and K in input. Since the number could grow very large, it will be modulo 1.000.000.007