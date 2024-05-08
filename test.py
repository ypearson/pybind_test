import time
import timeit
import numpy as np
from spatialmath import SE3

import pybind_test_module
import SomeObject_module
import worker_module

def compute_transform(object_common, reference_common):
    return reference_common.inv() * object_common

def test_spatialmath(n):
    # Creating random SE3 transforms
    object_common = [SE3.Rx(np.random.rand()) * SE3.Ry(np.random.rand()) * SE3.Tz(np.random.rand()) for _ in range(n)]
    reference_common = [SE3.Rx(np.random.rand()) * SE3.Ry(np.random.rand()) * SE3.Tz(np.random.rand()) for _ in range(n)]
    start_time = time.time()
    _ = [compute_transform(obj, ref) for obj, ref in zip(object_common, reference_common)]
    elapsed_time = time.time() - start_time
    print(f"SpatialMath Time: {1000*elapsed_time} ms")
    return elapsed_time

def test_eigen(n):
    # Generate random transformation matrices
    objects = [pybind_test_module.se3_random() for _ in range(n)]
    references = [pybind_test_module.se3_random() for _ in range(n)]
    start_time = time.time()
    _ = [pybind_test_module.compute_transform(obj, ref) for obj, ref in zip(objects, references)]
    elapsed_time = time.time() - start_time
    print(f"Eigen Time: {1000*elapsed_time} ms")
    return elapsed_time


# Create a large NumPy array to test
arr = np.random.rand(10000,1000)

def square_array_python(arr):
    return np.square(arr)

# Define wrapper functions for timing
def test_cpp():
    pybind_test_module.square_array(arr)

def test_python():
    square_array_python(arr)

def test_jthread_background_work():
    # Create a BackgroundWorker instance
    worker = worker_module.BackgroundWorker()

    # Let it run for a few seconds
    time.sleep(5)

    # Get the counter value
    print("Counter value:", worker.get_counter())

def test_functions_objects():
    # Create a Pet instance
    my_obj = SomeObject_module.SomeObject("Foo", "Tao")
    # Access and modify the properties
    print(my_obj.get_name())
    my_obj.set_name("Gou")
    print(my_obj.get_name())
    # Print type
    print(my_obj.get_type())

def test_functions():
    print("func_no_params:", pybind_test_module.func_no_params())
    print("func_one_param(5):", pybind_test_module.func_one_param(5))
    print("func_two_params(3, 4):", pybind_test_module.func_two_params(3, 4))

if __name__ == "__main__":

    n = 1000
    test_spatialmath(n)
    test_eigen(n)

    # Number of repetitions
    repetitions = 100

    # Timing the C++ implementation
    cpp_time = timeit.timeit(test_cpp, number=repetitions)
    print(f"C++ implementation takes {1000 * cpp_time / repetitions:.5f} ms per execution on average.")

    # Timing the Python implementation
    python_time = timeit.timeit(test_python, number=repetitions)
    print(f"Python implementation takes {1000 * python_time / repetitions:.5f} ms per execution on average.")

    print(f'C++ is faster by {(python_time)/cpp_time:.3f} X faster')

    test_functions()
    test_functions_objects()
    test_jthread_background_work()

    number_of_calls = 10000
    start_time = time.perf_counter()

    # Execute multiple calls
    for _ in range(number_of_calls):
        pybind_test_module.func_no_params()

    end_time = time.perf_counter()
    elapsed_time = end_time - start_time
    average_time = elapsed_time / number_of_calls

    print(f"Average time per function call over {number_of_calls} calls: {average_time*1e6} us")

