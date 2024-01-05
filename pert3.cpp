#include <iostream>
using namespace std;

int main()
{
    string nama;
    system("clear");
    cout << "Masukkan nama Anda: ";
    getline(cin, nama);
    cout << "Halo, " << nama << "!" << endl;
    return 0;
}
