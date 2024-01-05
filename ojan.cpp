#include <iostream>
#include <string>

using namespace std;

class mahasiswa
{
public:
    string Nama;
    string NPM;
    string Prodi;

    void getInput()
    {
        system("cls");
        cout << "Masukkan Nama  : ";
        getline(cin, Nama);

        cout << "Masukkan NPM   : ";
        getline(cin, NPM);

        cout << "Masukkan Prodi : ";
        getline(cin, Prodi);
    }

    void display()
    {
        cout << "Nama   : " << Nama << endl;
        cout << "NPM    : " << NPM << endl;
        cout << "Prodi  : " << Prodi << endl;
    }
};

int main()
{
    mahasiswa mhs;

    mhs.getInput();
    cout << endl
         << "================";
    cout << endl
         << "Selamat Datang : " << endl;
    mhs.display();

    return 0;
}
