import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("conway's_GOF_results.csv")

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