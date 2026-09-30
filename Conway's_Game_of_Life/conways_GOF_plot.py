import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("conway's_GOF_results.csv")

# Graph 1: Population vs Generation for every initial density

for density in data["density"].unique():
    subset = data[data["density"] == density]

    plt.plot(
        subset["generation"],
        subset["average"],
        label=f"{density}%"
    )

plt.xlabel("Generation")
plt.ylabel("Average Population")
plt.title("Game of Life: Population vs Generation")
plt.legend(title="Density")
plt.grid()

plt.show()


# Graph 2: Initial Density vs Final Population

plt.figure()

final = data[data["generation"] == 19]

plt.plot(
    final["density"],
    final["average"],
    marker="o"
)

plt.xlabel("Initial Density (%)")
plt.ylabel("Average Population at Generation 19")
plt.title("Initial Density vs Final Population")
plt.grid()

plt.show()