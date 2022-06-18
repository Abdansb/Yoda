import matplotlib.pyplot as plt
import numpy as np
from fuzzy_expert.variable import FuzzyVariable
from fuzzy_expert.rule import FuzzyRule
from fuzzy_expert.inference import DecompositionalInference

#Input Himpunan Fuzzy
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
    "Produk_Terjual": FuzzyVariable(
        universe_range=(0, 900),
        terms={
            "Sedikit": ('trapmf', 0, 0, 300, 500),
            "Sedang": ('trimf', 350, 500, 650),
            "Banyak": ('trapmf', 500, 700, 900, 900),
        },
    ),
    #
    "Insentif": FuzzyVariable(
        universe_range=(0, 1000),
        terms={
            "Rendah": ('trapmf', 0, 0, 100, 500),
            "Menengah": ('trimf', 100, 500, 900),
            "Tinggi": ('trapmf', 500, 900, 1000, 1000),
        },
    ),
}


#Rules/Inferensi Fuzzy
rules = [
    #1
    FuzzyRule(
        premise=[
            ("Pelayanan", "Buruk"), ("AND", "Kerapian", "Kurang"), ("AND", "Terlambat", "Sering"), ("AND", "Produk_Terjual", "Sedikit"),
        ], consequence=[("Insentif", "Rendah")],
    ),
    #2
    FuzzyRule(
        premise=[
            ("Pelayanan", "Biasa"), ("AND", "Kerapian", "Cukup"), ("AND", "Terlambat", "Kadang"), ("AND", "Produk_Terjual", "Sedang"),
        ], consequence=[("Insentif", "Menengah")],
    ),
    #3
    FuzzyRule(
        premise=[
            ("Pelayanan", "Bagus"), ("AND", "Kerapian", "Baik"), ("AND", "Terlambat", "Jarang"), ("AND", "Produk_Terjual", "Banyak"),
        ], consequence=[("Insentif", "Tinggi")],
     ),
]


#Defuzzyfikasi & Variabelnya
model = DecompositionalInference(
    and_operator="min",
    or_operator="max",
    implication_operator="Rc",
    composition_operator="max-min",
    production_link="max",
    defuzzification_operator="cog",
)

#Input data dan visualisasi Fuzzy
plt.figure(figsize=(10, 6))
model.plot(
    variables=variables,
    rules=rules,
    Pelayanan=70,
    Kerapian=80,
    Terlambat=10,
    Produk_Terjual=800,
)
plt.show()


"""plt.figure(figsize=(6, 2.5))
plt.grid(True)
plt.title('Pelayanan')
variables["Pelayanan"].plot()

plt.figure(figsize=(6, 2.5))
plt.grid(True)
plt.title('Kerapian')
variables["Kerapian"].plot()

plt.figure(figsize=(6, 2.5))
plt.grid(True)
plt.title('Keterlambatan dalam sebulan')
plt.xlabel('Akumulasi waktu (Jam)')
variables["Terlambat"].plot()

plt.figure(figsize=(6, 2.5))
plt.grid(True)
plt.title('Produk_Terjual')
plt.xlabel('Jumlah Barang')
variables["Produk_Terjual"].plot()

plt.figure(figsize=(6, 2.5))
plt.grid(True)
variables["Insentif"].plot()
plt.show()"""