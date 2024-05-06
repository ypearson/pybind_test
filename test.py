import time
import pybind_test_module
import SomeObject_module
import worker_module

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

