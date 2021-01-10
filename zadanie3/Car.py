import random as r
import time as t
from datetime import datetime


class Car:
    def __init__(self):
        self.keep_running = True
        self.speed = 0
        self.steering_angle = 0
        self.engine_temperature = 0

    # Function updates speed of the car every 2 seconds
    def update_speed(self):
        while self.keep_running:
            self.speed = r.randrange(0, 171)
            t.sleep(2)

    # Function updates steering angle of the car every 2 seconds
    def update_steering_angle(self):
        while self.keep_running:
            self.steering_angle = r.randrange(-450, 450)
            t.sleep(2)

    # Function updates engine temperature of the car every 10 seconds
    def update_engine_temperature(self):
        while self.keep_running:
            self.engine_temperature = r.randrange(0, 100)
            t.sleep(10)

    # Function prints car speed every second in JSON format
    def print_speed(self):
        while self.keep_running:
            print(f'{{"time": "{datetime.now().strftime("%d %b %y %H:%M:%S")}", "speed": {self.speed}}}')
            t.sleep(1)

    # Function prints car steering angle every 4 seconds in JSON format
    def print_steering_angle(self):
        while self.keep_running:
            print(f'{{"time": "{datetime.now().strftime("%d %b %y %H:%M:%S")}", "steeringAngle": {self.steering_angle}}}')
            t.sleep(4)

    # Function prints car engine temperature every 10 seconds in JSON format
    def print_engine_temperature(self):
        while self.keep_running:
            print(f'{{"time": "{datetime.now().strftime("%d %b %y %H:%M:%S")}", "engineTemperature": {self.engine_temperature}}}')
            t.sleep(10)

