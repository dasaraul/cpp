#include <iostream>
using namespace std;

    float luasSg(float alas, float tinggi) {
    return tinggi * alas / 2;
}

int main() {

    float tinggi, alas;

            cout << "Masukkan sisi  :   ";
            cin >> alas;
            cout << "Tinggi         :   ";
            cin >> tinggi;
            cout << "Luas Bujur Sangkar: " << luasSg(tinggi, alas) << endl;
    return 0;
    }

