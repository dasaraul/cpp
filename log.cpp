#include <iostream>
using namespace std;

void log(int hasil)
{
    cout << "jumlah prodi ialah: " << hasil << endl;
}

int main()
{
    system("clear");
    int jmlh_prodi{};
    cout << "Masukan Jumlah prodi: ";
    cin >> jmlh_prodi;

    log(jmlh_prodi);
    if (jmlh_prodi > 53)
    {
        cout << "Banyak" << endl
             << endl;
    }
    else if (jmlh_prodi > 33)
    {
        cout << "Lumayan Banyak" << endl
             << endl;
    }
    else if (jmlh_prodi > 23)
    {
        cout << "Sedikit" << endl
             << endl;
    }
    else if (jmlh_prodi > 13)
    {
        cout << "Sangat Sedikit" << endl
             << endl;
    }
    else
    {
        cout << "Abis" << endl
             << endl;
    }

    // string Y;
    // cout << "ingin lanjut? Y/n(default N): ";
    // cin >> Y;

    // if (Y != "Y")
    // {
    //     return 0;
    // }
    string Y;
    cout << "ingin lanjut? Y/n(default Y): ";
    // getline(cin, Y);
    cin >> Y;

    if (Y.empty() || Y != "Y")
    {
        return 0;
    }

    cout << endl << "berikut: " << endl;
    for (int bil = 1; bil <= 12; bil++)
    {
        cout << bil << " ";
    }
    cout << endl << endl;
    return 0;
}
