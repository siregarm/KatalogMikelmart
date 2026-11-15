
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>

using namespace std;

// Program Katalog Mikelmart
// Oleh Mikail A. Siregar (X-G)

// Struktur data barang
struct Barang {
    string kode;
    string nama;
    int harga;
};

// Struktur data keranjang
struct Item {
    string kode;
    string nama;
    int harga;
    int jumlah;
    int subtotal;
};

// Format angka dengan pemisah ribuan
string formatRupiah(long long angka) {
    string s = to_string(angka);
    string hasil = "";

    int hitung = 0;

    for (int i = s.length() - 1; i >= 0; i--) {
        hasil = s[i] + hasil;
        hitung++;

        if (hitung % 3 == 0 && i != 0) {
            hasil = "," + hasil;
        }
    }

    return hasil;
}

// Menampilkan waktu transaksi
string waktuSekarang() {
    time_t sekarang = time(0);
    tm* waktu = localtime(&sekarang);

    char buffer[30];
    strftime(buffer, sizeof(buffer), "%d-%m-%y %H-%M-%S", waktu);

    return string(buffer);
}

int main() {

    vector<Barang> catalog = {
        {"1.1", "[F&B] Kripik M-tella", 5000},
        {"1.2", "[F&B] Sandwich Sarikue", 7500},
        {"1.3", "[F&B] Permen Yipi", 2000},
        {"1.4", "[F&B] Telur 6 pack", 50000},
        {"1.5", "[F&B] Susu Bluefield", 8000},
        {"1.6", "[F&B] Yoghurt Si Mory", 12000},
        {"2.1", "[MED] Sanadol Xtra", 35000},
        {"2.2", "[MED] Piapet Digest", 60000},
        {"3.1", "[TOYS] Mobil Coldwheels", 24000},
        {"3.2", "[TOYS] VoYu Peiling 3M", 80000}
    };

    cout << ">" << string(48, '=') << "<" << endl;
    cout << ">" << setw(40) << "SELAMAT DATANG DI MIKELMART" << setw(9) << "<" << endl;
    cout << ">" << string(48, '=') << "<\n" << endl;

    while (true) {

        vector<Item> cart;

        // Menampilkan katalog
        cout << setw(27) << "KATALOG" << endl;
        cout << string(50, '=') << endl;

        cout << setw(6) << "Kode" << "|"
             << setw(31) << "Nama" << "|"
             << setw(11) << "Harga" << endl;

        cout << string(50, '=') << endl;

        for (const Barang& b : catalog) {
            cout << setw(6) << b.kode << "|"
                 << left << setw(31) << b.nama << "|"
                 << right << setw(11) << "Rp" + formatRupiah(b.harga)
                 << endl;
        }

        cout << string(50, '=') << endl;

        // Proses pembelian
        while (true) {

            string choice;
            cout << "\n> Pilihan Barang (Kode): ";
            cin >> choice;

            int index = -1;

            for (int i = 0; i < catalog.size(); i++) {
                if (catalog[i].kode == choice) {
                    index = i;
                    break;
                }
            }

            if (index == -1) {
                cout << "\n~ Barang tersebut tidak tersedia!" << endl;
                continue;
            }

            int amount;

            cout << "\n> Jumlah barang (int): ";
            cin >> amount;

            if (amount <= 0) {
                cout << "\n~ Jumlah barang harus lebih dari 0!" << endl;
                continue;
            }

            string name = catalog[index].nama;
            int price = catalog[index].harga;
            int subtotal = amount * price;

            Item toCart = {
                choice,
                name,
                price,
                amount,
                subtotal
            };

            cart.push_back(toCart);

            cout << "\n~ " << name
                 << " (Rp" << formatRupiah(price)
                 << ") sebanyak " << amount
                 << " (Rp" << formatRupiah(subtotal)
                 << ") ditambahkan." << endl;

            string again;

            cout << "\n> Apakah ingin membeli lagi? (Y/N): ";
            cin >> again;

            if (again != "Y" && again != "y") {
                break;
            }
        }

        // Menghitung total belanja
        int totalPay = 0;

        for (const Item& item : cart) {
            totalPay += item.subtotal;
        }

        // Menghitung diskon
        int discount = 0;

        if (totalPay >= 500000) {
            discount = 25;
        }
        else if (totalPay >= 350000) {
            discount = 20;
        }
        else if (totalPay >= 200000) {
            discount = 10;
        }
        else if (totalPay >= 100000) {
            discount = 5;
        }

        int discountPrice = totalPay * discount / 100;
        int finalPay = totalPay - discountPrice;

        string timePurchase = waktuSekarang();

        // Mencetak struk
        cout << endl;
        cout << string(69, '=') << endl;

        cout << setw(37) << "MIKELMART" << endl;
        cout << setw(47) << "BILL PEMBAYARAN PELANGGAN" << endl;

        cout << string(69, '=') << endl;

        cout << left << setw(30) << "Waktu Pembelanjaan"
             << ": " << timePurchase << "\n\n";

        cout << setw(7) << "Kode" << "|"
             << setw(23) << "Nama Barang" << "|"
             << setw(10) << "Harga" << "|"
             << setw(6) << "Qty" << "|"
             << setw(12) << "Subtotal" << endl;

        cout << string(69, '-') << endl;

        for (const Item& item : cart) {

            cout << left
                 << setw(7) << item.kode << "|"
                 << setw(23) << item.nama << "|"
                 << "Rp" << right << setw(8)
                 << formatRupiah(item.harga) << "|"
                 << setw(6) << item.jumlah << "|"
                 << "  Rp" << setw(10)
                 << formatRupiah(item.subtotal)
                 << endl;
        }

        cout << string(69, '-') << endl;

        cout << left << setw(30) << "Total Belanja"
             << ": Rp" << right << setw(36)
             << formatRupiah(totalPay) << endl;

        cout << left << setw(30) << "Diskon"
             << ":" << right << setw(39)
             << discount << "%" << endl;

        cout << left << setw(30) << "Potongan Diskon"
             << ": Rp" << right << setw(36)
             << formatRupiah(discountPrice) << endl;

        cout << string(69, '-') << endl;

        cout << left << setw(30) << "TOTAL BAYAR"
             << ": Rp" << right << setw(36)
             << formatRupiah(finalPay) << endl;

        // Proses pembayaran
        int payment;
        int payReturn;

        while (true) {

            cout << "\n> Uang pembayaran: Rp";
            cin >> payment;

            if (payment >= finalPay) {
                payReturn = payment - finalPay;
                break;
            }
            else {
                cout << "\n~ Saldo anda tidak mencukupi!" << endl;
            }
        }

        cout << left << setw(24) << "Uang Dibayar"
             << ": Rp" << right << setw(10)
             << formatRupiah(payment) << endl;

        cout << left << setw(24) << "Kembalian"
             << ": Rp" << right << setw(10)
             << formatRupiah(payReturn) << endl;

        cout << string(69, '=') << endl;

        cout << setw(55)
             << "TERIMAKASIH TELAH BERBELANJA DI MIKELMART"
             << endl;

        cout << string(69, '=') << endl;

        // Transaksi berikutnya
        string buyAgain;

        cout << "\nApakah ingin melakukan transaksi lagi? (Y/N): ";
        cin >> buyAgain;

        if (buyAgain == "N" || buyAgain == "n") {

            cout << "\nProgram kasir selesai." << endl;
            cout << "Terima kasih!\n" << endl;

            cout << "~ Nama : Mikail Aidan Siregar" << endl;
            cout << "~ Kelas: X-G" << endl;

            break;
        }
    }

    return 0;
}