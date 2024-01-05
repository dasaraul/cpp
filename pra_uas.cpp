#include<iostream>
#include<string>

using namespace std;

struct dataMtr {
    string nOwner;
    string jnsMtr;
    string PltMtr;
    int ccMotor;
};

struct lsService {
    int no;
    string nLayanan;
    int harga;
    int subtotal;
};

void garis () {
    {
        cout << "--========================================================================================--";
    }
    cout << endl;
}

void tampilanAwal() {
    cout << "Jasa UPGRADE CVT & PORTING by Tams Garage" << endl;
    garis();
    cout << "Selamat Datang Di Tams Garage - CVT & PORTING" << endl << endl;
    cout << "Masukan Data Motor Anda :" << endl;
    cout << "1. Input Data & Jenis Motor" << endl;
    cout << "2. Hubungi Admin" << endl;
    cout << "3. Keluar" << endl;
    cout << "Masukan Pilihan : ";
}

void inputDataMotor(dataMtr &motor) {
    system("cls"); 
    cout << "-= Masukan Data Diri & Motor Anda =-" << endl;
    garis();
    cout << "Masukan Nama Owner : ";
    getline(cin, motor.nOwner);

    cout << "Jenis Motor (matic/manual): ";
    getline(cin, motor.jnsMtr);

    cout << "Nomor Polisi Motor : ";
    getline(cin, motor.PltMtr);

    cout << "CC Motor : ";
    cin >> motor.ccMotor;

    cin.ignore(); 
    garis();
}

void inputlsService(lsService &layanan, const dataMtr &motor) {
    system("cls"); 
    cout << "-= Layanan Paket Service Tams Garage =-" << endl;
    garis();
    cout << "1. Porting Polish Motor dibawah 150cc (Rp 550.000)" << endl;
    cout << "2. Upgrade CVT (Rp 650.000)" << endl;
    cout << "3. Porting Polish Motor diatas 150cc (Rp 850.000)" << endl;
    cout << "4. Service rutin motor Matic (include bersihin blok cvt & sekitarnya) (Rp 200.000)" << endl;
    garis();

    cout << "Masukan Layanan Yang Ingin DI Pilih (sesuaikan dengan cc motor anda): ";
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
            layanan.nLayanan = "Service rutin motor Matic (include bersihin blok cvt & sekitarnya)";
            layanan.harga = 200000;

            if (motor.jnsMtr == "matic" || motor.jnsMtr == "Matic") {
                layanan.harga += 50000;
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
    cout << "No.\t\t\tLayanan Service\t\t\tHarga\t\t\tSubtotal" << endl;
    garis();

    int totalPembayaran = 0;

    for (int i = 0; i < n; ++i) {
        totalPembayaran += layanan[i].subtotal;

        cout << layanan[i].no << "\t" << layanan[i].nLayanan << "\t" << layanan[i].harga << "\t\t" << layanan[i].subtotal << endl;
    }

    garis();
    cout << endl << "\t\t\t\t\tTotal Pembayaran     : " << totalPembayaran << endl;

    int uangDibayarkan;
    cout << "\t\t\t\t\tUang Yang Dibayar    : ";
    cin >> uangDibayarkan;

    int uangKembali = uangDibayarkan - totalPembayaran;

    cout << "\t\t\t\t\tUang Kembali : " << uangKembali << endl;
}

void hubungiAdmin() {
    system("cls"); 
    cout << "Hubungi Admin" << endl;
    garis();
    cout << "WhatsApp - 082210819939" << endl;
    cout << "Instagram - @tam.aspx" << endl;
    cout << "Telegram - @ImTamaa" << endl;
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
                cout << "-= Kami Menyediakan 4 Layanan, berikut layanan servis kami =-" << endl << endl;
                cout << "Porting Polish Motor dibawah 150cc (550000)" << endl;
                cout << "Upgrade CVT (650000)" << endl;
                cout << "Porting Polish Motor diatas 150cc (850000)" << endl;
                cout << "Service rutin motor Matic (include bersihin blok cvt & sekitarnya) (200000)" << endl ;
                garis();
                cout << "Ingin layanan apa saja yang diinginkan (pilih 1 apabila hanya 1 saja atau bisa pilih beberapa): ";
                cin >> jmlLayanan;

                lsService layanan[jmlLayanan];

                for (int i = 0; i < jmlLayanan; ++i) {
                    inputlsService(layanan[i], motor);
                }

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
    } while (ReInput == 'Y' || ReInput == 'y');

    return 0;
}
