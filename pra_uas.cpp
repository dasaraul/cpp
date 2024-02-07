#include<iostream>
#include<string>
#include <iomanip>

using namespace std;

struct dataMtr { //dataMtr.nOwner
    string nOwner;
    string jnsMtr;
    string PltMtr;
    int ccMotor;
};

struct lsService { //list
    int no;
    string nLayanan;
    int harga;
    int subtotal;
};

void posisi(int x, int y) {
    std::cout << "\033[" << y + 1 << ";" << x + 1 << "H";
}

void garis() {
        cout << "--========================================================================================--";
    }

void header() {
    cout << "\t\t\tJasa UPGRADE CVT & PORTING by Tams Garage" << endl;
    cout << "\t\t  --==Selamat Datang Di Tams Garage - CVT & PORTING==--" << endl << endl;
}

void tampilanAwal() {
    system("cls");
    header();
    garis();
    cout << endl;
    cout << endl << "Masukan Data Motor Anda :" << endl;
    cout << "1. Input Data & Jenis Motor" << endl;
    cout << "2. Hubungi Admin" << endl;
    cout << "3. Keluar" << endl;
    cout << "Masukan Pilihan : ";
}

void inputDataMotor(dataMtr &motor) {
    system("cls");
    header();
    cout << "-= Masukan Data Diri & Motor Anda =-" << endl;
        garis();
    cout << endl;
    cout << endl << "Masukan Nama Owner : ";
    getline(cin, motor.nOwner);

    cout << "Jenis Motor (matic/manual): ";
    getline(cin, motor.jnsMtr);

    cout << "Nomor Polisi Motor : ";
    getline(cin, motor.PltMtr);

    cout << "CC Motor : ";
    cin >> motor.ccMotor;

    cin.ignore();
        garis();
    cout << endl;
    system("cls");
}

void inputlsService(lsService &layanan, const dataMtr &motor) {
    header();
    cout << endl << "-= Layanan Paket Service Tams Garage =-" << endl;
        garis();
    cout << endl;
    cout << "1. Porting Polish Motor dibawah 150cc (Rp 550.000)" << endl;
    cout << "2. Upgrade CVT (Rp 650.000)" << endl;
    cout << "3. Porting Polish Motor diatas 150cc (Rp 850.000)" << endl;
    cout << "4. Service rutin motor Matic ) (Rp 200.000)" << endl;
        garis();
    cout << endl;

    cout << endl << "Masukan Layanan Yang Ingin DI Pilih (sesuaikan dengan cc motor anda): ";
    cin >> layanan.no;

    switch (layanan.no) {
        case 1:
            layanan.nLayanan = "Porting Polish Motor dibawah 150cc";
            layanan.harga = 550000;
            break;
        case 2:
            layanan.nLayanan = "Upgrade CVT";
            layanan.harga = 650000;
            break;
        case 3:
            layanan.nLayanan = "Porting Polish Motor diatas 150cc";
            layanan.harga = 850000;
            break;
        case 4:
            layanan.nLayanan = "Service rutin motor Matic )";
            layanan.harga = 200000;

            if (motor.jnsMtr == "matic" || motor.jnsMtr == "Matic") {
                layanan.harga += 50000;
            }

            if (motor.jnsMtr == "manual" || motor.jnsMtr == "Manual") {
            }
            break;
        default:
            cout << "!! NULL !!" << endl;
            break;
    }

    layanan.subtotal = layanan.harga;
}

void hasillsService(const dataMtr &motor, const lsService layanan[], int n) {
    system("cls");
    cout << "Nama Owner : " << motor.nOwner << endl << endl;

    cout << "List Layanan Service yang diambil" << endl;
        garis();
    cout << endl;
    cout << "No.\tLayanan Service\t\t\t\tHarga\t\t\tSubtotal" << endl;
        garis();
    cout << endl;

    int totalbayaran = 0;

    for (int byr = 0; byr < n; ++byr) {
        totalbayaran += layanan[byr].subtotal;

        cout << layanan[byr].no;
        posisi(8, 6);
        cout << layanan[byr].nLayanan;
        posisi(48, 7);
        cout << layanan[byr].harga;
        posisi(72, 8);
        cout << layanan[byr].subtotal << endl;
    }

        garis();
    cout << endl;
    cout << endl << "\t\t\t\t\t\t\tTotal     : " << totalbayaran << endl;

    int uangDibayarkan;
    cout << "\t\t\t\t\t\t\tUang Yang Dibayar    :   ";
    cin >> uangDibayarkan;

    int kembalian = uangDibayarkan - totalbayaran;
    cout << "\t\t\t\t\t\t\tUang Kembali : " << kembalian << endl;
}

void hubungiAdmin() {
    system("cls");
    header();
        garis();
    cout << endl;
    cout << "Hubungi Admin" << endl << endl;
    cout << "WhatsApp - 082210819939" << endl;
    cout << "Instagram - @tam.aspx" << endl;
    cout << "Telegram - @ImTamaa" << endl << endl;
        garis();
    cout << endl;
}

int main() {
    char ReInput;
    do {
        tampilanAwal();

        int noUrut;
        cin >> noUrut;

        switch (noUrut) {
            case 1: {
                cin.ignore();
                dataMtr motor;
                inputDataMotor(motor);

                int jmlLayanan;
                    header();
                cout << "-= Kami Menyediakan 4 Layanan, berikut layanan servis kami =-" << endl;
                    garis();
                cout << endl;
                cout << "Porting Polish Motor dibawah 150cc (Rp 550.000)" << endl;
                cout << "Upgrade CVT (Rp 650.000)" << endl;
                cout << "Porting Polish Motor diatas 150cc (Rp 850.000)" << endl;
                cout << "Service rutin motor Matic ) (Rp 200.000)" << endl;
                    garis();
                cout << endl << endl;
                cout << "Ingin servis apa saja yang diinginkan (pilih jumlah yang diinginkan): ";
                cin >> jmlLayanan;
                system("cls");

                lsService layanan[jmlLayanan];

                for (int lyn = 0; lyn < jmlLayanan; ++lyn) {
                    inputlsService(layanan[lyn], motor);
                }

                    header();
                hasillsService(motor, layanan, jmlLayanan);

                cout << "Ingin Input dari awal lagi? [Y / N] : ";
                cin >> ReInput;
                cin.ignore();
                break;
            }
            case 2:
                hubungiAdmin();
                cout << "Ingin Input dari awal lagi? [Y / N] : ";
                cin >> ReInput;
                cin.ignore();
                break;
            case 3:
                cout << "Terima kasih telah menggunakan layanan kami!" << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid." << endl;
                return 0;
        }
    }
    while (ReInput == 'Y' || ReInput == 'y');
    while (ReInput == 'N' || ReInput == 'n');
    return 0;
}
