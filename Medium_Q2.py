import numpy as np
from collections import defaultdict

# Define all 2x2 binary matrices (16 total)
def generate_all_matrices():
    matrices = []
    for i in range(16):
        bin_str = format(i, '04b')
        matrix = np.array([[int(bin_str[0]), int(bin_str[1])],
                           [int(bin_str[2]), int(bin_str[3])]])
        matrices.append(matrix)
    return matrices

# Check if a matrix is singular
def is_singular(matrix):
    return np.linalg.det(matrix) == 0

# Build index map and transition probabilities
matrices = generate_all_matrices()
index_map = {tuple(m.flatten()): i for i, m in enumerate(matrices)}
singular_set = set(i for i, m in enumerate(matrices) if is_singular(m))
nonsingular_set = set(range(16)) - singular_set

# Transition matrix (Markov chain over 16 states)
P = np.zeros((16, 16))

for i, mat in enumerate(matrices):
    if i in singular_set:
        P[i, i] = 1  # absorbing state
    else:
        for pos in range(4):  # flip each bit
            new_mat = mat.copy()
            r, c = divmod(pos, 2)
            new_mat[r, c] ^= 1  # flip 0 to 1 or 1 to 0
            j = index_map[tuple(new_mat.flatten())]
            P[i, j] += 0.25  # uniform probability

# Fundamental matrix computation
from numpy.linalg import inv

Q_indices = sorted(list(nonsingular_set))
Q = P[np.ix_(Q_indices, Q_indices)]
I = np.eye(len(Q))
N = inv(I - Q)

# Expected number of steps from the identity matrix (index 3)
identity_index = index_map[(1, 0, 0, 1)]
start_index_in_Q = Q_indices.index(identity_index)
expected_steps = N[start_index_in_Q].sum()
print(f"Expected steps to singularity from identity matrix: {expected_steps:.3f}")
