#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    struct
    {
        char nim[20];
        char nama[25];
        char prodi[25];
        char nTugas[20];
    } dataMhs;

    system("clear");
    cout << "Masukan NIM    :   ";
    cin >> dataMhs.nim;
    cout << "Masukan Nama   :   " << endl;
    cin.ignore();
    cin.getline(dataMhs.nama, sizeof(dataMhs.nama)); // saya pakai getline agar inputan bisa buat spasi
    cout << "Masukan Prodi  :   ";
    cin.ignore();
    cin.getline(dataMhs.prodi, sizeof(dataMhs.prodi));
    cout << "Masukan nilai  :   ";
    cin >> dataMhs.nTugas;

    cout << endl << "Data Mahasiswa :   " << endl;
    cout << "NIM            :   " << dataMhs.nim << endl;
    cout << "Nama           :   " << dataMhs.nama << endl;
    cout << "Prodi          :   " << dataMhs.prodi << endl;
    cout << "Nilai Tugas    :   " << dataMhs.nTugas << endl;
    return 0;
}