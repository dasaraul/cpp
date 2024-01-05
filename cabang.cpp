#include <iostream>
using namespace std;

int main() {
    int nilai;
    char predikat;

    cout << "Masukkan nilai (0-100): ";
    cin >> nilai;

    if (nilai >= 0 && nilai <= 45) {
        predikat = 'E';
    } else if (nilai >= 46 && nilai <= 59) {
        predikat = 'D';
    } else if (nilai >= 60 && nilai <= 74) {
        predikat = 'C';
    } else if (nilai >= 75 && nilai <= 84) {
        predikat = 'B';
    } else if (nilai >= 85 && nilai <= 100) {
        predikat = 'A';
    } else {
        cout << "Nilai tidak valid. Masukkan nilai antara 0 hingga 100." << endl;
        return 1;
    }

    cout << "predikat: " << predikat << " -> ";

    if (predikat == 'E' || predikat == 'D') {
        cout << "Tidak lulus";
    } else {
        cout << "Lulus";
        if (predikat == 'A') {
            cout << " (Memuaskan)";
        }
    }

    cout << endl;

    return 0;
}
