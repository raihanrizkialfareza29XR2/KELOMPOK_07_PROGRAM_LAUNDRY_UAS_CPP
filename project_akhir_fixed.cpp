#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

string generateIdMember() {
    string generate_id_member = "";
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        generate_id_member += 'A' + rand() % 26;
    }
    return generate_id_member;
}

string generateIdPelanggan() {
    string generate_id_pelanggan = "";
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        generate_id_pelanggan += 'A' + rand() % 26;
    }
    return generate_id_pelanggan;
}

struct Member {
    string id_member = generateIdMember();
    string username;
    string password;
    string alamat;
    string nomor_telepon;
};

struct Pelanggan {
    string id_pelanggan = generateIdPelanggan();
    string nama_pelanggan;
    string alamat_pelanggan;
    string nomor_telepon_pelanggan;
};

struct Laundry {
    int pilih;
    string nama;
    int jumlah;
    float harga;
    float bayar;
    float kembalian;
    float tagihan;
};


map<string, Member> members;
map<string, Pelanggan> pelanggans;
map<string, Laundry> laundries;

string generateIdTransaksi() {
    string id_transaksi = "";
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        id_transaksi += 'A' + rand() % 26;
    }
    return id_transaksi;
}

void registerMember() {
    Member m;
    cout << "\n";
    cout << "ID Member Anda: " << m.id_member << endl;
    cout << "Masukkan username: ";
    getline(cin, m.username);
    cout << "Masukkan password: ";
    getline(cin, m.password);
    cout << "Masukkan alamat: ";
    getline(cin, m.alamat);
    cout << "Masukkan nomor telepon: ";
    cin >> m.nomor_telepon;
    cin.ignore();
    members[m.username] = m;
    cout << "\n";
    cout << "Registrasi berhasil!\n";
    cout << "\n";
}

void registerPelanggan(string* nama_pelanggan) {
    Pelanggan p;
    cout << "\n";
    cout << "ID Pelanggan Anda: " << p.id_pelanggan << endl;
    cout << "Masukkan nama: ";
    getline(cin, p.nama_pelanggan);
    *nama_pelanggan = p.nama_pelanggan;
    cout << "Masukkan alamat: ";
    getline(cin, p.alamat_pelanggan);
    cout << "Masukkan nomor telepon: ";
    cin >> p.nomor_telepon_pelanggan;
    cin.ignore();
    pelanggans[p.nama_pelanggan] = p;
    cout << "\n";
    cout << "Registrasi Pelanggan Berhasil!\n";
    cout << "\n";
}

void pilihanmu(){
    cout << "\n";
    cout << "Pilihan Jenis Layanan Laundry: \n";
    cout << "<============================> \n";
    cout << "1. Laundry Kiloan \n";
    cout << "2. Laundry Dry Cleaning \n";
    cout << "3. Laundry + Setrika \n";
    cout << "4. Laundry Self Service \n";
    cout << "<============================> \n";
}

Member* login() {
    string username, password;
    cout << "Masukkan username: ";
    getline(cin, username);
    cout << "Masukkan password: ";
    getline(cin, password);
    if (members.find(username) != members.end() && members[username].password == password) {
        cout << "\n";
        cout << "Login Berhasil!\n";
        cout << "\n";
        return &members[username];
    } else {
        cout << "Login gagal!\n";
        cout << "\n";
        return nullptr;
    }
}

void prosesLaundry(Member* member) {
    Laundry l;
    cout << "Pilih Jenis laundry: ";
    cin >> l.pilih;
    cin.ignore();
    cout << "Nama Layanan Laundry : ";
    if(l.pilih == 1){
        l.nama = "Laundry Kiloan";
        cout << l.nama <<endl;
    }else if(l.pilih == 2){
        l.nama = "Laundry Dry Cleaning";
        cout << l.nama <<endl;
    }else if(l.pilih == 3){
        l.nama = "Laundry + Setrika";
        cout << l.nama <<endl;
    }else if(l.pilih == 4){
        l.nama = "Laundry Self Service";
        cout << l.nama;
    }
    cout << "Masukkan jumlah laundry: ";
    cin >> l.jumlah;
    cin.ignore();
    cout << "Harga Laundry: ";
    if(l.pilih == 1){
        l.harga = 20000;
        cout << l.harga <<endl;
    }else if(l.pilih == 2){
        l.harga = 30000;
        cout << l.harga <<endl;
    }else if(l.pilih == 3){
        l.harga = 40000;
        cout << l.harga <<endl;
    }else if(l.pilih == 4){
        l.harga = 50000;
        cout << l.harga <<endl;
    }
    laundries[member->username] = l;
}

void prosesLaundry_pelanggan(string nama_pelanggan) {
    Laundry l;
    cout << "Pilih Jenis laundry: ";
    cin >> l.pilih;
    cin.ignore();
    if(l.pilih == 1){
        l.nama = "Laundry Kiloan";
    }else if(l.pilih == 2){
        l.nama = "Laundry Dry Cleaning";
    }else if(l.pilih == 3){
        l.nama = "Laundry + Setrika";
    }else if(l.pilih == 4){
        l.nama = "Laundry Self Service";
    }
    cout << "Anda telah memilih: " << l.nama << endl;  // Menampilkan nilai l.nama
    cout << "Masukkan jumlah laundry: ";
    cin >> l.jumlah;
    cin.ignore();
    cout << "Harga Laundry: ";
    cout << "\n";
    if(l.pilih == 1){
        l.harga = 20000;
    }else if(l.pilih == 2){
        l.harga = 30000;
    }else if(l.pilih == 3){
        l.harga = 40000;
    }else if(l.pilih == 4){
        l.harga = 50000;
    }
    cout << l.harga;
    laundries[nama_pelanggan] = l;
}



float hitungTotal(Member* member) {
    return laundries[member->username].jumlah * laundries[member->username].harga;
}

float hitungTotal_pelanggan(string nama_pelanggan) {
    return laundries[nama_pelanggan].jumlah * laundries[nama_pelanggan].harga;
}

float pembayaran(Member* member) {
    laundries[member->username].tagihan = laundries[member->username].jumlah * laundries[member->username].harga;
    cout << "\n";
    cout << "Total Tagihan Anda: Rp" << laundries[member->username].tagihan;
    cout << "\n";
    do {
        cout << "Bayar: ";
        cin >> laundries[member->username].bayar;
        cin.ignore();
        laundries[member->username].kembalian = laundries[member->username].bayar - laundries[member->username].tagihan;
        if(laundries[member->username].bayar < laundries[member->username].tagihan){
            cout << "Mohon Maaf, Uang Anda Kurang " << laundries[member->username].kembalian << "Rupiah \n"; 
        }
    } while(laundries[member->username].bayar < laundries[member->username].tagihan);
    if(laundries[member->username].bayar == laundries[member->username].tagihan){
        cout << "Uang Anda Pas! \n";
    }else{
        cout << "Kembalian: " << laundries[member->username].kembalian << "Rupiah \n";
    }
    cout << "\n";
    cout << "Terima Kasih Telah Menggunakan Layanan Kami";
}

float pembayaran_pelanggan(string nama_pelanggan) {
    laundries[nama_pelanggan].tagihan = laundries[nama_pelanggan].jumlah * laundries[nama_pelanggan].harga;
    cout << "\n";
    cout << "Total Tagihan Anda: Rp" << laundries[nama_pelanggan].tagihan<<endl;
    cout << "\n";
    do {
        cout << "Bayar: ";
        cin >> laundries[nama_pelanggan].bayar;
        cin.ignore();
        laundries[nama_pelanggan].kembalian = laundries[nama_pelanggan].bayar - laundries[nama_pelanggan].tagihan;
        if(laundries[nama_pelanggan].bayar < laundries[nama_pelanggan].tagihan){
            cout << "Mohon Maaf, Uang Anda Kurang " << laundries[nama_pelanggan].kembalian << "Rupiah \n"; 
        }
    } while(laundries[nama_pelanggan].bayar < laundries[nama_pelanggan].tagihan);
    if(laundries[nama_pelanggan].bayar == laundries[nama_pelanggan].tagihan){
        cout << "Uang Anda Pas! \n";
    }else{
        cout << "Kembalian: " << laundries[nama_pelanggan].kembalian << "Rupiah \n";
    }
    cout << "\n";
    cout << "Terima Kasih Telah Menggunakan Layanan Kami";
    cout << "" <<endl;
}

void cetakStruk(Member* member) {
    string id_transaksi = generateIdTransaksi();
    ofstream file;
    file.open(member->username + "_struk.txt");
    file << "ID Transaksi: " << id_transaksi << endl;
    file << "Nama Customer: " << member->username << endl;
    file << "Alamat: " << member->alamat << endl;
    file << "Nomor Telepon: " << member->nomor_telepon << endl;
    file << "Nama Layanan Laundry: " << laundries[member->username].nama << endl;
    file << "Jumlah Kilo: " << laundries[member->username].jumlah << endl;
    file << "Harga per Laundry: Rp" << laundries[member->username].harga << endl;
    file << "Total Tagihan: " << laundries[member->username].tagihan << endl;
    file << "Total Bayar: " << laundries[member->username].bayar << endl;
    if(laundries[member->username].bayar < laundries[member->username].tagihan){
        file << "Mohon Maaf, Uang Anda Kurang " << laundries[member->username].kembalian << "Rupiah \n"; 
    }else if(laundries[member->username].bayar == laundries[member->username].tagihan){
        file << "Uang Anda Pas! \n";
    }else{
        file << "Kembalian: " << laundries[member->username].kembalian << "Rupiah \n";
    }
    file << "\n";
    file << "Terima Kasih Telah Menggunakan Layanan Kami";
    file.close();
}

void cetakStruk_pelanggan(string nama_pelanggan) {
    string id_transaksi = generateIdTransaksi();
    ofstream file;
    file.open(nama_pelanggan + "_struk.txt");
    file << "ID Transaksi: " << id_transaksi << endl;
    file << "Nama Customer: " << nama_pelanggan << endl;
    file << "Alamat: " << pelanggans[nama_pelanggan].alamat_pelanggan << endl;
    file << "Nomor Telepon: " << pelanggans[nama_pelanggan].alamat_pelanggan << endl;
    file << "Nama Layanan Laundry: " << laundries[nama_pelanggan].nama << endl;
    file << "Jumlah Kilo: " << laundries[nama_pelanggan].jumlah << endl;
    file << "Harga per Laundry: Rp" << laundries[nama_pelanggan].harga << endl;
    file << "Total Tagihan: " << laundries[nama_pelanggan].tagihan << endl;
    file << "Total Bayar: " << laundries[nama_pelanggan].bayar << endl;
    if(laundries[nama_pelanggan].bayar < laundries[nama_pelanggan].tagihan){
        file << "Mohon Maaf, Uang Anda Kurang " << laundries[nama_pelanggan].kembalian << "Rupiah \n"; 
    }else if(laundries[nama_pelanggan].bayar == laundries[nama_pelanggan].tagihan){
        file << "Uang Anda Pas! \n";
    }else{
        file << "Kembalian: " << laundries[nama_pelanggan].kembalian << "Rupiah \n";
    }
    file << "\n";
    file << "Terima Kasih Telah Menggunakan Layanan Kami";
    file.close();
}


int main() {

    string opsi, nama_pelanggan;
    string ulangi;
    Member* loggedInMember = nullptr;
    bool isRegistered = false;
    do {
        cout << "\n";
        if (!loggedInMember && !isRegistered) {
            cout << "Apakah Anda Ingin Mendaftar Sebagai Member? (y/t): ";
            getline(cin, opsi);
            if(opsi == "y"){
                registerMember();
                loggedInMember = login();
            } else if(opsi == "t"){
                registerPelanggan(&nama_pelanggan);
                isRegistered = true;
            }
        }
        if (loggedInMember) {
            pilihanmu();
            prosesLaundry(loggedInMember);
            float total = hitungTotal(loggedInMember);
            pembayaran(loggedInMember);
            cetakStruk(loggedInMember);
            cout<<""<<endl;
            cout << "Struk telah dicetak ke file '" << loggedInMember->username << "_struk.txt'\n";
        } else if (isRegistered) {
            pilihanmu();
            prosesLaundry_pelanggan(nama_pelanggan);
            float total = hitungTotal_pelanggan(nama_pelanggan);
            pembayaran_pelanggan(nama_pelanggan);
            cetakStruk_pelanggan(nama_pelanggan);
            cout << "Struk telah dicetak ke file '" << nama_pelanggan << "_struk.txt'\n"; 
        } else {
            return 0;
        }
        cout << "Apakah Anda ingin mengulangi proses laundry? (y/t): ";
        cin >> ulangi;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (ulangi == "y");
    return 0;
}

