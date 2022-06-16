
import matplotlib.pyplot as plt
import numpy as np

from fuzzy_expert.variable import FuzzyVariable

variables = {
    "Pelayanan": FuzzyVariable(
        universe_range=(0, 100),
        terms={
            "Buruk": ('trapmf', 0, 0, 15, 40),
            "Biasa": ('trimf', 25, 50, 75),
            "Bagus": ('trapmf', 60, 85, 100, 100),
        },
    ),
    "Kerapian": FuzzyVariable(
        universe_range=(0, 100),
        terms={
            "Kurang": ('trapmf', 0, 0, 40, 60),
            "Cukup": ('trimf', 40, 60, 80),
            "Baik": ('trapmf', 60, 80, 100, 100),
        },
    ),
    #
    "Terlambat": FuzzyVariable(
        universe_range=(0, 30),
        terms={
            "Jarang": ('trapmf', 0, 0, 2.5, 7.5),
            "Kadang": ('trimf', 2.5, 10, 17.5),
            "Sering": ('trapmf', 12.5, 17.5, 30, 30),
        },
    ),
    #
    "Produk Terjual": FuzzyVariable(
        universe_range=(0, 900),
        terms={
            "Sedikit": ('trapmf', 0, 0, 300, 500),
            "Sedang": ('trimf', 350, 500, 650),
            "Sering": ('trapmf', 500, 700, 900, 900),
        },
    ),
}

plt.figure(figsize=(10, 2.5))
variables["Produk Terjual"].plot()
plt.show()