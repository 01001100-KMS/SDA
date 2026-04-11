#include <iostream>
#include <string>
using namespace std;

#define MAX 100

struct Hewan {
    int id;
    string nama;
    string jenis;
    float harga;
};

int n = 0;

//  QUEUE (ANTRIAN) 
    Hewan antrian[MAX];
    int depan = -1, belakang = -1;

// STACK (RIWAYAT) 
    Hewan riwayat[MAX];
    int atas = -1;

// ===== SWAP =====
void tukarData(Hewan *a, Hewan *b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

// ===== TAMPIL DATA =====
void tampilData(Hewan *arr) {
    if (n == 0) {
        cout << "Data kosong!\n";
        return;
    }  cout << "\n=== DATA HEWAN ===\n";

    for (int i = 0; i < n; i++) {
        cout << "ID     : " << (arr+i)->id << endl;
        cout << "Nama   : " << (arr+i)->nama << endl;
        cout << "Jenis  : " << (arr+i)->jenis << endl;
        cout << "Harga  : " << (arr+i)->harga << endl;
        cout << "----------------------\n";
    }
}

// ===== TAMBAH DATA =====
void tambahData(Hewan *arr) {
    cout << "\nTambah Data\n";
    cout << "ID     : "; cin >> (arr+n)->id;
    cout << "Nama   : "; cin >> (arr+n)->nama;
    cout << "Jenis  : "; cin >> (arr+n)->jenis;
    cout << "Harga  : "; cin >> (arr+n)->harga;
    n++;
}

//  CARI NAMA (LINEAR)  
void cariNama(Hewan *arr, string cari) {
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

//  SORT ID 
void urutkanID(Hewan *arr) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if ((arr+j)->id > (arr+j+1)->id) {
                tukarData((arr+j), (arr+j+1));
            }
        }
    }
}

// FIBONACCI SEARCH 
int cariID(Hewan *arr, int n, int target) {
    int fib2 = 0, fib1 = 1, fib = fib1 + fib2;

    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;

    cout << "\nProses pencarian ID:\n";

    while (fib > 1) {
        int i = offset + fib2;
        if (i >= n) i = n - 1;

        cout << "Cek index ke-" << i 
             << " (ID: " << (arr+i)->id << ")\n";

        if ((arr+i)->id == target)
            return i;

        else if ((arr+i)->id < target) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        } else {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
    }

    if (fib1 && (arr+offset+1)->id == target)
        return offset + 1;

    return -1;
}

// SORT NAMA 
void urutkanNama(Hewan *arr) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if ((arr+j)->nama > (arr+j+1)->nama) {
                tukarData((arr+j), (arr+j+1));
            }
        }
    }
    cout << "Berhasil diurutkan berdasarkan nama!\n";
}

// SORT HARGA 
void urutkanHarga(Hewan *arr) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;

        for (int j = i+1; j < n; j++) {
            if ((arr+j)->harga < (arr+minIdx)->harga) {
                minIdx = j;
            }
        }

        tukarData((arr+i), (arr+minIdx));
    }
    cout << "Berhasil diurutkan berdasarkan harga!\n";
}

// FUNGSI TAMBAH ANTRIAN =
void tambahAntrian(Hewan h) {
    if (belakang == MAX - 1) {
        cout << "Antrian penuh!\n";
        return;
    }
    if (depan == -1) depan = 0;
    antrian[++belakang] = h;
}

// FUNGSI PANGGIL PASIEN
Hewan panggilPasien() {
    Hewan kosong = {-1, "", "", 0};

    if (depan == -1 || depan > belakang) {
        cout << "Antrian kosong!\n";
        return kosong;
    }

    return antrian[depan++];
}

// FUNGSI TAMBAH RIWAYAT
void tambahRiwayat(Hewan h) {
    if (atas == MAX - 1) {
        cout << "Riwayat penuh!\n";
        return;
    }
    riwayat[++atas] = h;
}

// FUNGSI HAPUS RIWAYAT 
void hapusRiwayatTerakhir() {
    if (atas == -1) {
        cout << "Riwayat kosong!\n";
        return;
    }
    cout << "Hapus riwayat: " << riwayat[atas].nama << endl;
    atas--;
}

// FUNGSI TAMPIL ANTRIAN 
void tampilAntrian() {
    if (depan == -1 || depan > belakang) {
        cout << "Antrian kosong!\n";
        return;
    }

    Hewan *ptr = &antrian[depan];

    cout << "\n=== ANTRIAN ===\n";
    for (int i = depan; i <= belakang; i++) {
        cout << "ID   : " << ptr->id << endl;
        cout << "Nama : " << ptr->nama << endl;
        cout << "------------------\n";
        ptr++;
    }
}
// fungsi tampil riwayat
void tampilRiwayat() {
    if (atas == -1) {
        cout << "Riwayat kosong!\n";
        return;
    }

    Hewan *ptr = &riwayat[0];

    cout << "\n=== RIWAYAT ===\n";
    for (int i = 0; i <= atas; i++) {
        cout << "ID   : " << ptr->id << endl;
        cout << "Nama : " << ptr->nama << endl;
        cout << "------------------\n";
        ptr++;
    }
}

// fungsi LIHAT STATUS 
    void lihatStatus() {
    if (depan != -1 && depan <= belakang)
        cout << "Pasien terdepan: " << antrian[depan].nama << endl;
    else
        cout << "Antrian kosong\n";

    if (atas != -1)
        cout << "Riwayat terakhir: " << riwayat[atas].nama << endl;
    else
        cout << "Riwayat kosong\n";
}

// main
int main() {
    Hewan data[100];
    Hewan *ptr = data;

    int pilihan;
    string namaCari;
    int idCari;

    do {
        cout << "\n=== PAWCARE PETSHOP ===\n";
        cout << "1. Tampil Data\n";
        cout << "2. Tambah Data\n";
        cout << "3. Cari Nama\n";
        cout << "4. Cari ID\n";
        cout << "5. Urutkan Nama\n";
        cout << "6. Urutkan Harga\n";
        cout << "7. Masuk Antrian\n";
            cout << "8. Panggil Pasien\n";
        cout << "9. Tampil Antrian\n";
             cout << "10. Tampil Riwayat\n";
         cout << "11. Hapus Riwayat\n";
        cout << "12. Lihat Status\n";
          cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

     switch (pilihan) {
            case 1: tampilData(ptr); break;
            case 2: tambahData(ptr); break;

      case 3:
                cout << "Masukkan nama: "; cin >> namaCari;
                cariNama(ptr, namaCari);
                break;

      case 4: {
                cout << "Masukkan ID: "; cin >> idCari;
                urutkanID(ptr);
                int hasil = cariID(ptr, n, idCari);

                if (hasil != -1) {
                    cout << "\nData ditemukan!\n";
                    cout << "Nama: " << (ptr+hasil)->nama << endl;
                } else {
                    cout << "Data tidak ditemukan!\n";
                }
                break;
            }

     case 5: urutkanNama(ptr); break;
     case 6: urutkanHarga(ptr); break;

        case 7: {
                cout << "Masukkan ID hewan: "; cin >> idCari;
                for (int i = 0; i < n; i++) {
                    if ((ptr+i)->id == idCari) {
                        tambahAntrian(*(ptr+i));
                    }
                }
                break;
            }

        case 8: {
                Hewan h = panggilPasien();
                if (h.id != -1) {
                    cout << "Dipanggil: " << h.nama << endl;
                    tambahRiwayat(h);
                }
                break;
            }

            case 9: tampilAntrian(); break;
            case 10: tampilRiwayat(); break;
            case 11: hapusRiwayatTerakhir(); break;
            case 12: lihatStatus(); break;

        }

    } while (pilihan != 0);

    return 0;
}
// PENJELASAN TAMBAHAN TIAP PROGRAM
// QUEUE (ANTRIAN)
//    - Menggunakan konsep FIFO (First In First Out).
//    - tambahAntrian() : menambahkan data ke belakang antrian.
//    - panggilPasien() : mengambil data dari depan antrian.
//    - Digunakan untuk sistem antrian pemeriksaan hewan.

// STACK (RIWAYAT)
//    - Menggunakan konsep LIFO (Last In First Out).
//    - tambahRiwayat() : menambahkan data ke stack.
//    - hapusRiwayatTerakhir() : menghapus data terakhir.
//    - Digunakan untuk menyimpan riwayat tindakan.

//  STATUS
//    - lihatStatus() menampilkan:
//      - Data paling depan di antrian
//      - Data terakhir di riwayat
//    - Tidak menghapus data (hanya melihat).

//  ALUR PROGRAM
//    - User menambahkan data hewan.
//    - Hewan dapat dimasukkan ke dalam antrian.
//    - Hewan dipanggil dari antrian untuk diperiksa.
//    - Setelah diperiksa, data masuk ke riwayat.
//    - Riwayat dapat dilihat atau dihapus.