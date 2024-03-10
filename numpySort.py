import numpy as np
import time

name = "" # Ten file input

try:
    with open(name, "r") as file:
        n = int(file.readline())
except FileNotFoundError:
    exit(1)
except ValueError:
    exit(1)

with open(name, "r") as file:
    _ = file.readline() 
    real_numbers = [float(x) for x in file.readline().split()]

start_time = time.time()
np.sort(real_numbers)
end_time = time.time()
execution_time = end_time - start_time

print(execution_time * 1000)