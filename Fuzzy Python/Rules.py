#Rules/Inferensi Fuzzy
rules = [
    #1
    FuzzyRule(
        premise=[
            ("Pelayanan", "Buruk"), 
            ("AND", "Kerapian", "Kurang"),
            ("AND", "Terlambat", "Sering"),
            ("AND", "Produk Terjual", "Sedikit"),
        ],
        consequence=[("Insentif", "Rendah")],
    ),
    #2
    FuzzyRule(
        premise=[
            ("Pelayanan", "Biasa"),
            ("AND", "Kerapian", "Cukup"),
            ("AND", "Terlambat", "Kadang"),
            ("AND", "Produk Terjual", "Sedang"),
        ],
        consequence=[("Insentif", "Menengah")],
    ),
    #3
     FuzzyRule(
        premise=[
            ("Pelayanan", "Bagus"),
            ("AND", "Kerapian", "Baik"),
            ("AND", "Terlambat", "Jarang"),
            ("AND", "Produk Terjual", "Banyak"),
        ],
        consequence=[("Insentif", "Tinggi")],
     ),
    #4
     FuzzyRule(
        premise=[
            ("Pelayanan", "Biasa"),
            ("AND", "Kerapian", "Cukup"),
            ("AND", "Terlambat", "Sering"),
            ("AND", "Produk Terjual", "Sedikit"),
        ],
        consequence=[("Insentif", "Menengah")],
     ),
    #5
     FuzzyRule(
        premise=[
            ("Pelayanan", "Buruk"),
            ("AND", "Kerapian", "Kurang"),
            ("AND", "Terlambat", "Kadang"),
            ("AND", "Produk Terjual", "Sedang"),
        ],
        consequence=[("Insentif", "Menengah")],
     ),
    #6
     FuzzyRule(
        premise=[
            ("Pelayanan", "Biasa"),
            ("AND", "Kerapian", "Kurang"),
            ("AND", "Terlambat", "Kadang"),
            ("AND", "Produk Terjual", "Banyak"),
        ],
        consequence=[("Insentif", "Menengah")],
     ),
    #7
     FuzzyRule(
        premise=[
            ("Pelayanan", "Buruk"),
            ("AND", "Kerapian", "Cukup"),
            ("AND", "Terlambat", "Sering"),
            ("AND", "Produk Terjual", "Sedang"),
        ],
        consequence=[("Insentif", "Menengah")],
     ),
    #8
     FuzzyRule(
        premise=[
            ("Pelayanan", "Buruk"),
            ("AND", "Kerapian", "Cukup"),
            ("AND", "Terlambat", "Kadang"),
            ("AND", "Produk Terjual", "Sedikit"),
        ],
        consequence=[("Insentif", "Menengah")],
     ),
    #9
     FuzzyRule(
        premise=[
            ("Pelayanan", "Biasa"),
            ("AND", "Kerapian", "Kurang"),
            ("AND", "Terlambat", "Sering"),
            ("AND", "Produk Terjual", "Sedang"),
        ],
        consequence=[("Insentif", "Menengah")],
     ),
    #10
     FuzzyRule(
        premise=[
            ("Pelayanan", "Biasa"),
            ("AND", "Kerapian", "Kurang"),
            ("AND", "Terlambat", "Sering"),
            ("AND", "Produk Terjual", "Sedikit"),
        ],
        consequence=[("Insentif", "Rendah")],
     ),
    #11
     FuzzyRule(
        premise=[
            ("Pelayanan", "Buruk"),
            ("AND", "Kerapian", "Cukup"),
            ("AND", "Terlambat", "Sering"),
            ("AND", "Produk Terjual", "Sedikit"),
        ],
        consequence=[("Insentif", "Rendah")],
     ),
    #12
     FuzzyRule(
        premise=[
            ("Pelayanan", "Buruk"),
            ("AND", "Kerapian", "Kurang"),
            ("AND", "Terlambat", "Kadang"),
            ("AND", "Produk Terjual", "Sedikit"),
        ],
        consequence=[("Insentif", "Rendah")],
     ),
    #13
     FuzzyRule(
        premise=[
            ("Pelayanan", "Buruk"),
            ("AND", "Kerapian", "Kurang"),
            ("AND", "Terlambat", "Sering"),
            ("AND", "Produk Terjual", "Sedang"),
        ],
        consequence=[("Insentif", "Rendah")],
     ),
    #14
     FuzzyRule(
        premise=[
            ("Pelayanan", "Bagus"),
            ("AND", "Kerapian", "Baik"),
            ("AND", "Terlambat", "Kadang"),
            ("AND", "Produk Terjual", "Sedang"),
        ],
        consequence=[("Insentif", "Tinggi")],
     ),
    #15
     FuzzyRule(
        premise=[
            ("Pelayanan", "Biasa"),
            ("AND", "Kerapian", "Cukup"),
            ("AND", "Terlambat", "Sering"),
            ("AND", "Produk Terjual", "Banyak"),
        ],
        consequence=[("Insentif", "Tinggi")],
     ),
    #16
     FuzzyRule(
        premise=[
            ("Pelayanan", "Bagus"),
            ("AND", "Kerapian", "Cukup"),
            ("AND", "Terlambat", "Sering"),
            ("AND", "Produk Terjual", "Sedang"),
        ],
        consequence=[("Insentif", "Tinggi")],
     ),
    #17
     FuzzyRule(
        premise=[
            ("Pelayanan", "Biasa"),
            ("AND", "Kerapian", "Baik"),
            ("AND", "Terlambat", "Jarang"),
            ("AND", "Produk Terjual", "Banyak"),
        ],
        consequence=[("Insentif", "Tinggi")],
     ),
    #18
     FuzzyRule(
        premise=[
            ("Pelayanan", "Biasa"),
            ("AND", "Kerapian", "Baik"),
            ("AND", "Terlambat", "Jarang"),
            ("AND", "Produk Terjual", "Sedang"),
        ],
        consequence=[("Insentif", "Tinggi")],
     ),
    #19
     FuzzyRule(
        premise=[
            ("Pelayanan", "Bagus"),
            ("AND", "Kerapian", "Cukup"),
            ("AND", "Terlambat", "Kadang"),
            ("AND", "Produk Terjual", "Banyak"),
        ],
        consequence=[("Insentif", "Tinggi")],
     ),
    #20
     FuzzyRule(
        premise=[
            ("Pelayanan", "Bagus"),
            ("AND", "Kerapian", "Cukup"),
            ("AND", "Terlambat", "Kadang"),
            ("AND", "Produk Terjual", "Sedang"),
        ],
        consequence=[("Insentif", "Menengah")],
     ),
    #21
     FuzzyRule(
        premise=[
            ("Pelayanan", "Biasa"),
            ("AND", "Kerapian", "Baik"),
            ("AND", "Terlambat", "Kadang"),
            ("AND", "Produk Terjual", "Sedang"),
        ],
        consequence=[("Insentif", "Menengah")],
     ),
    #22
     FuzzyRule(
        premise=[
            ("Pelayanan", "Biasa"),
            ("AND", "Kerapian", "Cukup"),
            ("AND", "Terlambat", "Jarang"),
            ("AND", "Produk Terjual", "Sedang"),
        ],
        consequence=[("Insentif", "Menengah")],
     ),
    #23
     FuzzyRule(
        premise=[
            ("Pelayanan", "Biasa"),
            ("AND", "Kerapian", "Cukup"),
            ("AND", "Terlambat", "Kadang"),
            ("AND", "Produk Terjual", "Banyak"),
        ],
        consequence=[("Insentif", "Menengah")],
     ),
]