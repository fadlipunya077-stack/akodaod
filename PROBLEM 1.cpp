#include <iostream>

// Fungsi buatan sendiri untuk melakukan simulasi eliminasi astronot
void simulasiEliminasi(int N, int K) {
    // Array untuk menyimpan nomor astronot (maksimal 1000 astronot)
    int astronot[1000];
    
    // Inisialisasi daftar astronot dari nomor 1 hingga N
    for (int i = 0; i < N; i++) {
        astronot[i] = i + 1;
    }
    
    int sisaAstronot = N;
    int indeksAwal = 0; // Perhitungan dimulai dari astronot pertama
    
    std::cout << "Urutan astronot yang dieliminasi:\n";
    
    // Proses eliminasi hingga tersisa 1 astronot
    while (sisaAstronot > 1) {
        // Cari indeks astronot yang akan dieliminasi menggunakan aritmetika modulo
        int targetIndeks = (indeksAwal + K - 1) % sisaAstronot;
        
        // Simpan nomor astronot yang dieliminasi
        int tereliminasi = astronot[targetIndeks];
        std::cout << tereliminasi << " ";
        
        // Aturan perubahan nilai K berdasarkan nomor astronot tereliminasi
        if (tereliminasi % 2 == 0) {
            K += 2; // Jika nomor genap, K bertambah 2
        } else {
            K -= 1; // Jika nomor ganjil, K berkurang 1
        }
        
        // Batas minimal nilai K adalah 2
        if (K < 2) {
            K = 2;
        }
        
        // Hapus astronot yang dieliminasi dengan menggeser elemen array ke kiri
        for (int i = targetIndeks; i < sisaAstronot - 1; i++) {
            astronot[i] = astronot[i + 1];
        }
        
        sisaAstronot--;
        
        // Perhitungan berikutnya dimulai dari posisi astronot setelah yang dieliminasi
        indeksAwal = targetIndeks;
    }
    
    std::cout << "\n\nAstronot terakhir yang bertahan: " << astronot[0] << "\n";
}

int main() {
    int N, K;
    
    std::cout << "=== Problem 1: The Last Astronaut ===\n";
    std::cout << "Masukkan jumlah astronot (N): ";
    std::cin >> N;
    std::cout << "Masukkan nilai hitungan awal (K): ";
    std::cin >> K;
    
    if (N <= 0 || K <= 0) {
        std::cout << "Input harus berupa bilangan bulat positif.\n";
        return 0;
    }
    
    std::cout << "\n";
    simulasiEliminasi(N, K);
    
    return 0;
}
