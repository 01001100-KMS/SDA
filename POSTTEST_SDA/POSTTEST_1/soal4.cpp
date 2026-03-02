//  Heiza Rizki Pratama
#include <iostream>
using namespace std;

// Fungsi menukar duit dapupu dan nabubu
void tukarSaldo(int *saldo1, int *saldo2) {
    int sementara = *saldo1;
    *saldo1 = *saldo2;
    *saldo2 = sementara;
}

int main() {
    int saldoDapupu, saldoNabubu;

    cout << "Masukkan saldo Dapupu: ";
    cin >> saldoDapupu;

    cout << "Masukkan saldo Nabubu20: ";
    cin >> saldoNabubu;

    cout << "\n=== Sebelum Ditukar ===" << endl;
    cout << "Saldo Dapupu = " << saldoDapupu << endl;
    cout << "Saldo Nabubu = " << saldoNabubu << endl;

    // tukar
    tukarSaldo(&saldoDapupu, &saldoNabubu);

    cout << "\n=== Setelah Ditukar ===" << endl;
    cout << "Saldo Dapupu = " << saldoDapupu << endl;
    cout << "Saldo Nabubu = " << saldoNabubu << endl;

    return 0;
}


// Ini outputnya bakal di balik ya 
// semisal nabubu punya 2000 dapupu 3000 nah
// dibalik jadi dapupu 3000 nabubu 2000