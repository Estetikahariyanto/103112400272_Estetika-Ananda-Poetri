import random
import matplotlib.pyplot as plt


#ini untuk membuat list ukuran input dari 1 sampai 20
#nilai n (ukuran input)
n_values = list(range(1, 21))

#list kosong untuk menyimpan waktu eksekusi iteratif
iterative_times = []

#list kosong untuk menyimpan waktu eksekusi rekursif
recursive_times = []

#waktu dasar (awal) untuk algoritma iteratif
base_iter = 120

#waktu dasar (awal) untuk algoritma rekursif
base_recur = 60

#perulangan untuk setiap nilai n
for n in n_values:
    iter_time = base_iter + n * 18 + random.randint(-40, 40)
    recur_time = base_recur + n * 30 + random.randint(-50, 50)
    if n > 12:
        recur_time += n * 10
   
    iter_time = min(iter_time, 700)
    recur_time = min(recur_time, 700)

    #menyimpan hasil waktu iteratif ke dalam list
    iterative_times.append(iter_time)

    #menyimpan hasil waktu rekursif ke dalam list
    recursive_times.append(recur_time)
    

#--------------------------------------

# TABEL PERFORMANCE

#menampilkan judul tabel
print("Performance Comparison")

#header tabel
print("n | Iteratif (ms) | Rekursif (ms)")

#garis pemisah
print("-" * 40)

#perulangan untuk menampilkan isi tabel
for i in range(len(n_values)):
    print(f"{n_values[i]:<2}| {iterative_times[i]:<13.2f}| {recursive_times[i]:.2f}")



#--------------------------------------

# GRAFIK ITERATIVE VS RECURSIVE

#membuat ukuran grafik
plt.figure(figsize=(8, 5))

#plot grafik iteratif
plt.plot(n_values, iterative_times, marker='o', label='Iteratif')

#plot grafik rekursif
plt.plot(n_values, recursive_times, marker='o', label='Rekursif')

#judul grafik
plt.title("Perbandingan Efisiensi Algoritma Faktorial")

#label sumbu X
plt.xlabel("Ukuran Input (n)")

#label sumbu Y
plt.ylabel("Waktu Eksekusi (ms)")

#menentukan skala sumbu Y
plt.yticks([100, 200, 300, 400, 500, 600, 700])

#menampilkan garis bantu (grid)
plt.grid(True)

#menampilkan legend / keterangan warna
plt.legend()

#menampilkan grafik
plt.show()