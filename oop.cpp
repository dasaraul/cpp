#include <iostream>
#include <cstring>
using namespace std;

class lsFakultas {

private:
    char* fakultas;
    char* prodi;
    char akreditas;
    int jml_mhs;

public:
    lsFakultas(const char* fak, const char* pr, char ak, int jml);
    ~lsFakultas();
    void list();
};

lsFakultas :: lsFakultas(const char* fak, const char* pr, char ak, int jml) {
    fakultas = new char[strlen(fak)];
    strcpy(fakultas, fak);

    prodi = new char[strlen(pr) + 1];
    strcpy(prodi, pr);

    akreditas = ak;
    jml_mhs = jml;
}

lsFakultas::~lsFakultas() {
    delete[] fakultas;
    delete[] prodi;
}

void lsFakultas::list() {
    cout << "Fakultas " << fakultas << endl;
    cout << "Prodi                  : " << prodi << endl;
    cout << "Akreditasi             : " << akreditas << endl;
    cout << "Jumlah Mahasiswa       : " << jml_mhs << endl << endl;
}

int main() {
    system("cls");
    lsFakultas fakultasekonomi("Fakultas Ekonomi dan Bisnis. Perhotelan", "Perhotelan", 'A', 50);
    lsFakultas fakultasbahasa("Fakultas Bahasa dan Sastra. Sastra & Bahasa Asing", "Sastra & Bahasa Asing", 'A', 50);
    lsFakultas fakultasbiologi("Fakultas Biologi", "Biologi", 'A', 50);
    lsFakultas fakultastki("Fakultas Teknologi Komunikasi dan Informatika", "Sistem Informasi", 'A', 50);
    lsFakultas fakultashukum("Fakultas Hukum", "Hukum", 'A', 50);
    lsFakultas fakultaskesehatan("Fakultas Ilmu Kesehatan", "Kebidanan", 'A', 50);

    fakultasekonomi.list();
    fakultasbahasa.list();
    fakultasbiologi.list();
    fakultastki.list();
    fakultashukum.list();
    fakultaskesehatan.list();

    return 0;
}
