import numpy as np
from numba import njit, prange


# Numba is an open source JIT compiler that translates a subset of
# Python and NumPy code into fast machine code.

@njit(parallel=True)
def sum_array(arr):
    total = 0.0
    # prange is used for parallel loops
    for i in prange(arr.shape[0]):
        total += arr[i]
    return total

# Creating a large array
data = np.random.rand(10000000)

# Call the function
result = sum_array(data)
print(result)
