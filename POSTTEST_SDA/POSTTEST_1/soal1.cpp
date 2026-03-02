//  Heiza Rizki Pratama
#include <iostream>
using namespace std;

/*
Analisis Kompleksitas Waktu Algoritma:

Best Case (Tmin(n)):
Tmin​(n)=c1+c2n+c3(n−1)+c5

Elemen minimum sudah berada di index pertama
Perbandingan tetap dilakukan sebanyak (n-1) kali
Tidak ada assignment ke min di dalam if
Kompleksitas waktu: O(n)

Worst Case (Tmax(n)):
Tmax​(n)=c1+c2n+c3(n−1)+c4(n−1)+c5

Elemen minimum berada di index terakhir
Perbandingan dan assignment dilakukan sebanyak (n-1) kali
Kompleksitas waktu: O(n)

Kesimpulan:
Best Case  : O(n)
Worst Case : O(n)
*/

#include <iostream>
using namespace std;

// Fungsi mencari minimum + index + jumlah kemunculan
int cariMinimum(int A[], int n, int &indexMin, int &jumlahMuncul) {
    int min = A[0];
    indexMin = 0;
    jumlahMuncul = 1;

    for(int i = 1; i < n; i++) {
        if(A[i] < min) {
            min = A[i];
            indexMin = i;
            jumlahMuncul = 1; 
        }
        else if(A[i] == min) {
            jumlahMuncul++; // tambah kalau nilainya sama
        }
    }
    return min;
}

int main() {
    int n;

    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    int A[n];

    cout << "\nMasukkan elemen array:\n";
    for(int i = 0; i < n; i++) {
        cout << "Elemen ke-" << i << " : ";
        cin >> A[i];
    }

    cout << "\nIsi array: ";
    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    int indexMin, jumlahMuncul;

    int minimum = cariMinimum(A, n, indexMin, jumlahMuncul);

    cout << "\n\nNilai minimum = " << minimum << endl;
    cout << "Indeks pertama minimum = " << indexMin << endl;
    cout << "Jumlah kemunculan minimum = " << jumlahMuncul << endl;

    return 0;
}
