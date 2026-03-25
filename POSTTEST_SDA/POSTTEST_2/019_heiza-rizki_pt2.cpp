#include <iostream>
#include <string>
using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    float harga;
};

int n = 0;

// swapping
void swapPointer(Hewan *a, Hewan *b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

// read
void tampilData(Hewan *arr) {
    if (n == 0) {
        cout << "Data kosong!\n";
        return;
    }

    cout << "\n=== DATA HEWAN ===\n";
    for (int i = 0; i < n; i++) {
        cout << "ID     : " << (arr+i)->id << endl;
        cout << "Nama   : " << (arr+i)->nama << endl;
        cout << "Jenis  : " << (arr+i)->jenis << endl;
        cout << "Harga  : " << (arr+i)->harga << endl;
        cout << "----------------------\n";
    }
}

// create
void tambahData(Hewan *arr) {
    cout << "\nTambah Data\n";
    cout << "ID     : "; cin >> (arr+n)->id;
    cout << "Nama   : "; cin >> (arr+n)->nama;
    cout << "Jenis  : "; cin >> (arr+n)->jenis;
    cout << "Harga  : "; cin >> (arr+n)->harga;
    n++;
}

// linear s
void linearSearch(Hewan *arr, string cari) {
    bool ketemu = false;

    cout << "\nProses pencarian:\n";
    for (int i = 0; i < n; i++) {
        cout << "Cek index ke-" << i 
             << " (" << (arr+i)->nama << ")\n";

        if ((arr+i)->nama == cari) {
            cout << "\nData ditemukan!\n";
            cout << "ID    : " << (arr+i)->id << endl;
            cout << "Nama  : " << (arr+i)->nama << endl;
            cout << "Jenis : " << (arr+i)->jenis << endl;
            cout << "Harga : " << (arr+i)->harga << endl;
            ketemu = true;
        }
    }

    if (!ketemu) {
        cout << "Data tidak ditemukan!\n";
    }
}

// sort id f fibonnaci
void sortByID(Hewan *arr) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if ((arr+j)->id > (arr+j+1)->id) {
                swapPointer((arr+j), (arr+j+1));
            }
        }
    }
}

// fs (fibonnaci search)
int fibonacciSearch(Hewan *arr, int n, int target) {
    int fib2 = 0;
    int fib1 = 1;
    int fib = fib1 + fib2;

    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;

    cout << "\nProses Fibonacci Search:\n";

    while (fib > 1) {
        int i = offset + fib2;

        if (i >= n)
            i = n - 1;

        cout << "Cek index ke-" << i 
             << " (ID: " << (arr+i)->id << ")\n";

        if ((arr+i)->id == target)
            return i;

        else if ((arr+i)->id < target) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
    }

    if (fib1 && (arr+offset+1)->id == target)
        return offset + 1;

    return -1;
}

// bb sort (bubble)
void bubbleSort(Hewan *arr) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if ((arr+j)->nama > (arr+j+1)->nama) {
                swapPointer((arr+j), (arr+j+1));
            }
        }
    }
    cout << "Berhasil diurutkan berdasarkan nama!\n";
}

// selection sort w harga
void selectionSort(Hewan *arr) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;

        for (int j = i+1; j < n; j++) {
            if ((arr+j)->harga < (arr+minIdx)->harga) {
                minIdx = j;
            }
        }

        swapPointer((arr+i), (arr+minIdx));
    }
    cout << "Berhasil diurutkan berdasarkan harga!\n";
}

// main
int main() {
    Hewan data[100];
    Hewan *ptr = data;

    int pilihan;
    string cariNama;
    int cariID;

    do {
        cout << "\n=== PAWCARE PETSHOP ===\n";
        cout << "1. Tampil Data\n";
        cout << "2. Tambah Data\n";
        cout << "3. Cari Nama (Linear Search)\n";
        cout << "4. Cari ID (Fibonacci Search)\n";
        cout << "5. Urutkan Nama (Bubble Sort)\n";
        cout << "6. Urutkan Harga (Selection Sort)\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilData(ptr);
                break;

            case 2:
                tambahData(ptr);
                break;

            case 3:
                cout << "Masukkan nama: ";
                cin >> cariNama;
                linearSearch(ptr, cariNama);
                break;

            case 4:
                cout << "Masukkan ID: ";
                cin >> cariID;

                sortByID(ptr);

                int hasil;
                hasil = fibonacciSearch(ptr, n, cariID);

                if (hasil != -1) {
                    cout << "\nData ditemukan!\n";
                    cout << "ID    : " << (ptr+hasil)->id << endl;
                    cout << "Nama  : " << (ptr+hasil)->nama << endl;
                    cout << "Jenis : " << (ptr+hasil)->jenis << endl;
                    cout << "Harga : " << (ptr+hasil)->harga << endl;
                } else {
                    cout << "Data tidak ditemukan!\n";
                }
                break;

            case 5:
                bubbleSort(ptr);
                break;

            case 6:
                selectionSort(ptr);
                break;
        }

    } while (pilihan != 0);

    return 0;
}