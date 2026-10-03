import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("clt_results.csv")

roll_counts = [10, 100, 1000, 10000]

for rolls in roll_counts:

    subset = data[data["rolls"] == rolls]

    plt.figure()

    plt.hist(
        subset["average"],
        bins=50
    )

    plt.xlabel("Sample Mean")
    plt.ylabel("Frequency")
    plt.title(f"Distribution of Sample Means ({rolls} rolls)")

    plt.grid()

    plt.show()