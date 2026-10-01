import numpy as np
import matplotlib.pyplot as plt

points = np.array([1000, 10000, 100000, 1000000])

error = np.array([
    0.038824,
    0.014156,
    0.003931,
    0.001358
])

# Theoretical 1/sqrt(N) curve
theoretical = 1 / np.sqrt(points)

plt.plot(points, error, marker="o", label="Experimental error")
plt.plot(points, theoretical, marker="o", label="1/sqrt(N)")

plt.xscale("log")

plt.xlabel("Number of Points")
plt.ylabel("Error")
plt.title("Monte Carlo π: Error vs Number of Samples")

plt.legend()
plt.grid()

plt.show()