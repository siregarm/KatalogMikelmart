# Program Katalog Mikelmart
# Oleh Mikail A. Siregar (X-G)

from datetime import datetime
import time

catalog = {
    "1.1": {"Nama": "[F&B] Kripik M-tella", "Harga": 5000},
    "1.2": {"Nama": "[F&B] Sandwich Sarikue", "Harga": 7500},
    "1.3": {"Nama": "[F&B] Permen Yipi", "Harga": 2000},
    "1.4": {"Nama": "[F&B] Telur 6 pack", "Harga": 50000},
    "1.5": {"Nama": "[F&B] Susu Bluefield", "Harga": 8000},
    "1.6": {"Nama": "[F&B] Yoghurt Si Mory", "Harga": 12000},
    "2.1": {"Nama": "[MED] Sanadol Xtra", "Harga": 35000},
    "2.2": {"Nama": "[MED] Piapet Digest", "Harga": 60000},
    "3.1": {"Nama": "[TOYS] Mobil Coldwheels", "Harga": 24000},
    "3.2": {"Nama": "[TOYS] VoYu Peiling 3M", "Harga": 80000}
}

print(f">{'=' * 48}<")
print(f">{" SELAMAT DATANG DI MIKELMART ":-^48}<")
print(f">{'=' * 48}<\n")

while True:
    
    cart = []

    print(f"{"KATALOG":^50}")
    print('=' * 50)
    print(f"{"Kode":^6}|{"Nama":^31}|{"Harga":^11}")
    print('=' * 50)

    for kode, data in catalog.items():
        print(f"{kode:^6}|{data["Nama"]:<31}|{f"Rp{data["Harga"]}":<11}")

    print('=' * 50)

    while True:
        
        choice = input("\n> Pilihan Barang (Kode): ")
        if choice not in catalog.keys():
            print("\n~ Barang tersebut tidak tersedia!")
            continue

        ammount = int(input("\n> Jumlah barang (int): "))
        name = catalog[choice]["Nama"]
        price = catalog[choice]["Harga"]
        subtotal = ammount * price

        to_cart = {
            "Kode": choice,
            "Nama": name,
            "Harga": price,
            "Jumlah": ammount,
            "Subtotal": subtotal
        }
        cart.append(to_cart)

        print(f"\n~ {name} (Rp{price}) sebanyak {ammount} (Rp{subtotal}) ditambahkan.")

        again = input("\n> Apakah ingin membeli lagi? (Y/N): ").upper()
        if again != "Y":
            break

    total_pay = 0
    for item in cart:
        total_pay += item["Subtotal"]

    if total_pay >= 500000:
        discount = 25
    elif total_pay >= 350000:
        discount = 20
    elif total_pay >= 200000:
        discount = 10
    elif total_pay >= 100000:
        discount = 5
    else:
        discount = 0

    discount_price = total_pay * discount / 100
    final_pay = total_pay - discount_price

    time.sleep(2)

    time_purchase = datetime.now().strftime("%d-%m-%y %H-%M-%S")

    print()
    print('=' * 69)
    print(f"{"MIKELMART":^65}")
    print(f"{"BILL PEMBAYARAN PELANGGAN":^65}")
    print('=' * 69)
    print(f"{"Waktu Pembelanjaan":<30}: {time_purchase}\n")

    print(f"{'Kode':^7}|{'Nama Barang':^23}|{'Harga':^10}|{'Qty':^6}|{'Subtotal':^12}")
    print('-' * 69)

    for item in cart:
        print(
            f"{item['Kode']:<7}|"
            f"{item['Nama']:<23}|"
            f"Rp{item['Harga']:>8,}|"
            f"{item['Jumlah']:>6}|"
            f"  Rp{item['Subtotal']:>10,}"
        )
    print('-' * 69)

    print(f"{'Total Belanja':<30}:   Rp{total_pay:>36,}")
    print(f"{'Diskon':<30}:{discount:>39}%")
    print(f"{'Potongan Diskon':<30}:   Rp{discount_price:>36,.0f}")
    print("-" * 69)
    print(f"{'TOTAL BAYAR':<30}:   Rp{final_pay:>36,.0f}")

    while True:
        payment = int(input("\n> Uang pembayaran: Rp"))
        if payment >= final_pay:
            pay_return = payment - final_pay
            break
        else:
            print("\n~ Saldo anda tidak mencukupi!")

    print(f"Uang Dibayar            : Rp{payment:>10,.0f}")
    print(f"Kembalian               : Rp{pay_return:>10,.0f}")

    print("=" * 69)
    print(f"{"TERIMAKASIH TELAH BERBELANJA DI MIKELMART":^69}")
    print("=" * 69)

    buy_again = input("\nApakah ingin melakukan transaksi lagi? (Y/N): ").upper()

    if buy_again == "N":
        print("\nProgram kasir selesai.")
        print("Terima kasih!\n")
        print("~ Nama : Mikail Aidan Siregar")
        print("~ Kelas: X-G")
        break