import numpy as np
import matplotlib.pyplot as plt

steps = np.array([100, 1000, 10000, 100000])

experimental = np.array([
    7.910,
    25.722,
    78.486,
    252.770
])

# Theoretical prediction
theoretical = np.sqrt(2 * steps / np.pi)

plt.plot(
    steps,
    experimental,
    marker="o",
    label="Experimental"
)

plt.plot(
    steps,
    theoretical,
    marker="o",
    label="Theoretical"
)

plt.xscale("log")

plt.xlabel("Number of Steps")
plt.ylabel("Average Distance from Origin")
plt.title("Random Walk: Experimental vs Theoretical")

plt.legend()
plt.grid()

plt.show()