//  Heiza Rizki Pratama
#include <iostream>
#include <iomanip> // untuk format
using namespace std;

void tampilArray(int* arr, int n) {
    int* ptr = arr;

    cout << "--------------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Index ke-" << i 
             << " | Nilai = " << setw(2) << *ptr
            << " | Alamat = " << ptr << endl;
        ptr++;
    }
    cout << "--------------------------------------------------" << endl;
}

// membalikkan array menggunakan pointer
void reverseArray(int* arr, int n) {
    int* awal = arr;
    int* akhir = arr + n - 1;
    int temp;

    while (awal < akhir) {
        temp = *awal;
        *awal = *akhir;
        *akhir = temp;

        awal++;
        akhir--;
    }
}

int main() {
    int angka[7] = {2, 3, 5, 7, 11, 13, 17};
    int n = 7;

    cout << "Alamat awal array : " << angka << endl;

    cout << "\n=== SEBELUM DIBALIK ===" << endl;
    tampilArray(angka, n);

    reverseArray(angka, n);

    cout << "\n=== SETELAH DIBALIK ===" << endl;
    tampilArray(angka, n);

    return 0;
}