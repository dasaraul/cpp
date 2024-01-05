//class data mahasiswa yang menggunakan Constructor & Destructor
//pdf pertemuan 12 & 13 pada webkuliah

#include <iostream>
using namespace std;

class dataMhs {
public:
    // Constructor
    dataMhs() {
        cout << endl << "Constructor - Data Mahasiswa" << endl;
    }

    // Destructor
    ~dataMhs() {
        cout << endl << "Destructor - Data Pribadi Mahasiswa" << endl;
        cout << "Hobi   :   Turu" << endl;
        cout << "Umur   :   19" << endl;
        cout << "TTL    :   Tangerang - 29 Februari" << endl;
    }

    void datamhs() {
        cout << "Nama   :   " << "Muhammad Akbar Hadi Pratama" << endl;
        cout << "NIM    :   " << "237006516058" << endl;
        cout << "Prodi  :   " << "Sistem Informasi" << endl;
    }
};

int main() {
    dataMhs show;
    show.datamhs();
    return 0;
}
