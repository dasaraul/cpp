#include <iostream>
#include <cmath>
#include <string>

using namespace std;

    void dataDiri() {
        cout << "Nama   : Muhammad Akbar Hadi Pratama" << endl;
        cout << "NPM    : 237006516058" << endl;
        cout << "Prodi  : Sistem Informasi" << endl;
    }

    void LuasLing() {
        double jari;
        cout << "Masukkan jari-jari lingkaran: ";
        cin >> jari;
        double luasLing = 3.14 * jari * jari;
        cout << "Luas lingkaran adalah: " << luasLing << endl;
    }

    void LuasSg() {
        double alas, tinggi;
        cout << "Masukkan panjang alas segitiga: ";
        cin >> alas;
        cout << "Masukkan tinggi segitiga: ";
        cin >> tinggi;
        double luasSg = 0.5 * alas * tinggi;
        cout << "Luas segitiga adalah: " << luasSg << endl;
    }

    void LuasP() {
        double sisi;
        cout << "Masukkan panjang sisi persegi: ";
        cin >> sisi;
        double luasSg = sisi * sisi;
        cout << "Luas persegi adalah: " << luasSg << endl;
    }

    void LuasPp() {
        double panjang, lebar;
        cout << "Masukkan panjang persegi panjang: ";
        cin >> panjang;
        cout << "Masukkan lebar persegi panjang: ";
        cin >> lebar;
        double luasPp = panjang * lebar;
        cout << "Luas persegi panjang adalah: " << luasPp << endl;
    }

    bool lanjutbre() {
        string lanjut;
        cout << "Lanjutkan? (y/n): ";
        cin >> lanjut;
        return (lanjut == "y" || lanjut == "Y");
    }

int main() {
    while (true) {
        int pilian;

        cout << endl << "=====================================";
        cout << endl << "Selamat Datang : " << endl;
        dataDiri();
        cout << "=====================================" << endl;
        cout << endl << "Pilihan perhitungan luas bangun:"<< endl;
        cout << "1. Lingkaran"<< endl;
        cout << "2. Segitiga"<< endl;
        cout << "3. Persegi"<< endl;
        cout << "4. Persegi Panjang"<< endl;
        cout << "5. Keluar"<< endl;
        cout << "Masukkan pilihan (1-5): ";
        cin >> pilian;

        if (pilian == 5) {
            break;
        }

        switch (pilian) {
            case 1:
                LuasSg();
                break;
            case 2:
                LuasP();
                break;
            case 3:
                LuasLing();
                break;
            case 4:
                LuasPp();
                break;
            default:
                cout << "Silakan masukkan angka 1-5! " << endl;
                break;
        }

        if (!lanjutbre()) {
            break;
        }
    }

    return 0;
}
