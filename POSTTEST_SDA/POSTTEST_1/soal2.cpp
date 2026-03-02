//  Heiza Rizki Pratama
#include <iostream>
#include <iomanip>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    int jumlah;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlah;

    Mahasiswa mhs[jumlah];  

    cout << "\n=== Input Data Mahasiswa ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama : ";
        cin >> mhs[i].nama;
        cout << "NIM  : ";
        cin >> mhs[i].nim;
        cout << "IPK  : ";
        cin >> mhs[i].ipk;
    }

    
    cout << "\n=== Data Mahasiswa ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "\nNama : " << mhs[i].nama << endl;
        cout << "NIM  : " << mhs[i].nim << endl;
        cout << "IPK  : " << fixed << setprecision(2) << mhs[i].ipk << endl;
    }

    // Cari IPK tertinggi + hitung rata-rata
    int indeksTertinggi = 0;
    float totalIPK = 0;

    for (int i = 0; i < jumlah; i++) {
        totalIPK += mhs[i].ipk;

        if (mhs[i].ipk > mhs[indeksTertinggi].ipk) {
            indeksTertinggi = i;
        }
    }

    float rataRata = totalIPK / jumlah;

    cout << "\n=== Mahasiswa dengan IPK Tertinggi ===\n";
    cout << "Nama : " << mhs[indeksTertinggi].nama << endl;
    cout << "NIM  : " << mhs[indeksTertinggi].nim << endl;
    cout << "IPK  : " << mhs[indeksTertinggi].ipk << endl;

    cout << "\nRata-rata IPK Mahasiswa: " << rataRata << endl;

    return 0;
}