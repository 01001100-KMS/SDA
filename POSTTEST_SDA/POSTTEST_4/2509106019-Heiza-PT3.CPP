#include <iostream>
#include <string>
using namespace std;

#define MAX 100

struct Hewan {
    int id;
    string nama;
    string jenis;
    float harga;
    Hewan* next;
};

int n = 0;

//  QUEUE 
    Hewan* headAntrian = nullptr;
    Hewan* tailAntrian = nullptr;

// STACK 
    Hewan* topRiwayat = nullptr;

// SWAP
void tukarData(Hewan *a, Hewan *b) {
    int   tId    = a->id;    a->id    = b->id;    b->id    = tId;
    string tNama  = a->nama;  a->nama  = b->nama;  b->nama  = tNama;
    string tJenis = a->jenis; a->jenis = b->jenis; b->jenis = tJenis;
    float tHarga  = a->harga; a->harga = b->harga; b->harga = tHarga;
}

// TAMPIL DATA
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

// TAMBAH DATA 
void tambahData(Hewan *arr) {
    cout << "\nTambah Data\n";
    cout << "ID     : "; cin >> (arr+n)->id;
    cout << "Nama   : "; cin >> (arr+n)->nama;
    cout << "Jenis  : "; cin >> (arr+n)->jenis;
    cout << "Harga  : "; cin >> (arr+n)->harga;
    (arr+n)->next = nullptr;
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

// FUNGSI ENQUEUE
void enqueue(Hewan h) {
    Hewan* node  = new Hewan;
    node->id     = h.id;
    node->nama   = h.nama;
    node->jenis  = h.jenis;
    node->harga  = h.harga;
    node->next   = nullptr;

    if (tailAntrian == nullptr) {
        headAntrian = tailAntrian = node;
    } else {
        tailAntrian->next = node;
        tailAntrian       = node;
    }
    cout << "Hewan berhasil masuk antrian!\n";
}

void tambahAntrian(Hewan h) {
    enqueue(h);
}

// FUNGSI DEQUEUE
Hewan dequeue() {
    Hewan kosong = {-1, "", "", 0, nullptr};

    if (headAntrian == nullptr) {
        cout << "Antrian kosong! (Underflow)\n";
        return kosong;
    }

    Hewan* temp  = headAntrian;
    Hewan  data  = *temp;
    data.next    = nullptr;

    headAntrian  = headAntrian->next;
    if (headAntrian == nullptr) tailAntrian = nullptr;

    delete temp;
    return data;
}

// Wrapper dequeue
Hewan panggilPasien() {
    return dequeue();
}

// FUNGSI PEEK ANTRIAN
void peekAntrian() {
    if (headAntrian == nullptr) {
        cout << "Antrian kosong! (Underflow)\n";
        return;
    }
    cout << "\n=== PEEK ANTRIAN (Node Terdepan) ===\n";
    cout << "ID    : " << headAntrian->id    << endl;
    cout << "Nama  : " << headAntrian->nama  << endl;
    cout << "Jenis : " << headAntrian->jenis << endl;
    cout << "Harga : " << headAntrian->harga << endl;
}

// FUNGSI TAMPIL ANTRIAN
void tampilAntrian() {
    if (headAntrian == nullptr) {
        cout << "Antrian kosong!\n";
        return;
    }

    Hewan *ptr = headAntrian;

    cout << "\n=== ANTRIAN ===\n";
    while (ptr != nullptr) {
        cout << "ID   : " << ptr->id   << endl;
        cout << "Nama : " << ptr->nama << endl;
        cout << "------------------\n";
        ptr = ptr->next;
    }
}


// FUNGSI PUSH
void push(Hewan h) {
    Hewan* node  = new Hewan;
    node->id     = h.id;
    node->nama   = h.nama;
    node->jenis  = h.jenis;
    node->harga  = h.harga;
    node->next   = topRiwayat;
    topRiwayat   = node;
}

// Wrapper push
void tambahRiwayat(Hewan h) {
    push(h);
}

// FUNGSI POP
void pop() {
    if (topRiwayat == nullptr) {
        cout << "Riwayat kosong! (Underflow)\n";
        return;
    }
    cout << "Hapus riwayat: " << topRiwayat->nama << endl;
    Hewan* temp = topRiwayat;
    topRiwayat  = topRiwayat->next;
    delete temp;
}

// Wrapper pop compatibility on menu
void hapusRiwayatTerakhir() {
    pop();
}

// FUNGSI PEEK RIWAYAT
void peekRiwayat() {
    if (topRiwayat == nullptr) {
        cout << "Riwayat kosong! (Underflow)\n";
        return;
    }
    cout << "\n=== PEEK RIWAYAT (Node Teratas) ===\n";
    cout << "ID    : " << topRiwayat->id    << endl;
    cout << "Nama  : " << topRiwayat->nama  << endl;
    cout << "Jenis : " << topRiwayat->jenis << endl;
    cout << "Harga : " << topRiwayat->harga << endl;
}

// fungsi tampil riwayat
void tampilRiwayat() {
    if (topRiwayat == nullptr) {
        cout << "Riwayat kosong!\n";
        return;
    }

    Hewan *ptr = topRiwayat;

    cout << "\n=== RIWAYAT ===\n";
    while (ptr != nullptr) {
        cout << "ID   : " << ptr->id   << endl;
        cout << "Nama : " << ptr->nama << endl;
        cout << "------------------\n";
        ptr = ptr->next;
    }
}

// fungsi LIHAT STATUS 
    void lihatStatus() {
    if (headAntrian != nullptr)
        cout << "Pasien terdepan: " << headAntrian->nama << endl;
    else
        cout << "Antrian kosong\n";

    if (topRiwayat != nullptr)
        cout << "Riwayat terakhir: " << topRiwayat->nama << endl;
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
        cout << "7. Masuk Antrian (Enqueue)\n";
            cout << "8. Panggil Pasien (Dequeue)\n";
        cout << "9. Tampil Antrian\n";
             cout << "10. Tampil Riwayat\n";
         cout << "11. Hapus Riwayat (Pop)\n";
        cout << "12. Lihat Status\n";
        cout << "13. Peek Antrian\n";
        cout << "14. Peek Riwayat\n";
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

            case 9:  tampilAntrian();        break;
            case 10: tampilRiwayat();        break;
            case 11: hapusRiwayatTerakhir(); break;
            case 12: lihatStatus();          break;
            case 13: peekAntrian();          break;
            case 14: peekRiwayat();          break;

        }

    } while (pilihan != 0);

    return 0;
}