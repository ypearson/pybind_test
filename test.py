import time
import pybind_test_module

def test_functions():
    print("func_no_params:", pybind_test_module.func_no_params())
    print("func_one_param(5):", pybind_test_module.func_one_param(5))
    print("func_two_params(3, 4):", pybind_test_module.func_two_params(3, 4))

if __name__ == "__main__":
    test_functions()

    number_of_calls = 10000
    start_time = time.perf_counter()

    # Execute multiple calls
    for _ in range(number_of_calls):
        pybind_test_module.func_no_params()

    end_time = time.perf_counter()
    elapsed_time = end_time - start_time
    average_time = elapsed_time / number_of_calls

    print(f"Average time per function call over {number_of_calls} calls: {average_time*1e6} us")

