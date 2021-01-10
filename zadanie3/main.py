import Car
import signal
from concurrent.futures import ThreadPoolExecutor

# This program creates Car object and runs threads which are responsible for printing and updating
# that object's properties. Printing is done at different rates depending on the property. Updating also
# happens at different rates. The updated values are random.
test_car = Car.Car()


# Function handles keyboard interrupt and shuts down running threads
def keyboard_interrupt_handler(signal, frame):
    print("Ctrl-C")
    print("Waiting for threads to finish")
    test_car.keep_running = False


# Thread pool responsible for printing car parameters
print_thread_executor = ThreadPoolExecutor(max_workers=3)
print_speed_thread = print_thread_executor.submit(test_car.print_speed)
print_angle_thread = print_thread_executor.submit(test_car.print_steering_angle)
print_temperature_thread = print_thread_executor.submit(test_car.print_engine_temperature)

# Thread pool responsible for updating car parameters
update_thread_executor = ThreadPoolExecutor(max_workers=3)
update_speed_thread = update_thread_executor.submit(test_car.update_speed)
update_angle_thread = update_thread_executor.submit(test_car.update_steering_angle)
update_temperature_thread = update_thread_executor.submit(test_car.update_engine_temperature)


# capture SIGINT signal and exit program
signal.signal(signal.SIGINT, keyboard_interrupt_handler)

while test_car.keep_running:
    pass
