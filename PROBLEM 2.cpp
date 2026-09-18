#include <iostream>

// Fungsi buatan sendiri untuk menghitung panjang array karakter (string)
int hitungPanjangString(const char str[]) {
    int panjang = 0;
    while (str[panjang] != '\0') {
        panjang++;
    }
    return panjang;
}

// Fungsi buatan sendiri untuk mengubah huruf kecil ke huruf besar (UPPERCASE)
char keHurufBesar(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    return c;
}

// Fungsi buatan sendiri untuk mendapatkan nilai alfabet (A=1, B=2, ..., Z=26)
int dapatkanNilaiAlfabet(char c) {
    char h = keHurufBesar(c);
    if (h >= 'A' && h <= 'Z') {
        return h - 'A' + 1;
    }
    return 0; // Jika bukan huruf
}

// Fungsi buatan sendiri untuk mengonversi nilai 1-26 kembali menjadi karakter 'A'-'Z'
char konversiNilaiKeHuruf(int nilai) {
    return 'A' + (nilai - 1);
}

// Fungsi utama untuk melakukan enkripsi pesan
void enkripsiSandi(const char pesanAsli[], char pesanHasil[]) {
    int N = hitungPanjangString(pesanAsli);
    if (N == 0) {
        pesanHasil[0] = '\0';
        return;
    }

    // Huruf pertama tidak mengalami perubahan
    pesanHasil[0] = keHurufBesar(pesanAsli[0]);

    // Proses pergeseran untuk huruf-huruf berikutnya
    for (int i = 1; i < N; i++) {
        char currentChar = keHurufBesar(pesanAsli[i]);
        char prevChar = keHurufBesar(pesanAsli[i - 1]);

        int nilaiCurrent = dapatkanNilaiAlfabet(currentChar);
        int nilaiPrev = dapatkanNilaiAlfabet(prevChar);

        // Jika ada karakter non-huruf, abaikan pergeseran
        if (nilaiCurrent == 0) {
            pesanHasil[i] = pesanAsli[i];
            continue;
        }

        // Geser nilai karakter saat ini sebanyak nilai karakter sebelumnya
        int nilaiBaru = nilaiCurrent + nilaiPrev;

        // Jika nilai melebihi 26, kembali lagi dari A (putar batas alfabet)
        if (nilaiBaru > 26) {
            nilaiBaru -= 26;
        }

        pesanHasil[i] = konversiNilaiKeHuruf(nilaiBaru);
    }

    // Menandai akhir string
    pesanHasil[N] = '\0';
}

int main() {
    char pesanAsli[1000];
    char pesanTerenkripsi[1000];

    std::cout << "=== Problem 2: Alien-In-The-Middle ===\n";
    std::cout << "Masukkan pesan asli (tanpa spasi): ";
    std::cin >> pesanAsli;

    enkripsiSandi(pesanAsli, pesanTerenkripsi);

    std::cout << "Pesan terenkripsi: " << pesanTerenkripsi << "\n";

    return 0;
}
