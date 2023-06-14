#include <iostream>
#include <string>
using namespace std;

class Penerbit {
public:
	string nama;

	Penerbit(string nama) {
		this->nama = nama;
	}
};

class Pengarang {
public:
	string nama;

	Pengarang(string nama) {
		this->nama = nama;
	}
};

class Buku {
public:
    string judul;
    int tahun;
    Penerbit* penerbit;
    Pengarang* pengarang;

    Buku(string judul, Penerbit* penerbit, Pengarang* pengarang) {
        this->judul = judul;
        this->penerbit = penerbit;
        this->pengarang = pengarang;
    }
};

int main() {
    const int MAX_BUKU = 100; // Jumlah maksimal buku yang dapat ditambahkan
    Buku* daftarBuku[MAX_BUKU]; // Array untuk menyimpan objek buku
    int jumlahBuku = 0; // Jumlah buku yang telah ditambahkan

    while (true) {
        cout << "Menu: " << endl;
        cout << "1. Tambah Buku" << endl;
        cout << "2. Lihat Buku" << endl;
        cout << "3. Hapus Buku" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";

        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
        case 0:
            cout << "Thank you!" << endl;
            return 0;
        case 1: {
            cout << "Tambah Buku" << endl;
            string judulBuku, namaPenerbit, namaPengarang;
            cout << "Judul Buku: ";
            cin.ignore();
            getline(cin, judulBuku);
            cout << "Nama Penerbit: ";
            cin.ignore();
            getline(cin, namaPenerbit);
            cout << "Nama Pengarang: ";
            getline(cin, namaPengarang);

            // Membuat objek penerbit dan pengarang
            Penerbit* penerbit = new Penerbit(namaPenerbit);
            Pengarang* pengarang = new Pengarang(namaPengarang);

            // Membuat objek buku dan menyimpannya di dalam array
            Buku* buku = new Buku(judulBuku, penerbit, pengarang);
            daftarBuku[jumlahBuku] = buku;
            jumlahBuku++;

            cout << "Buku berhasil ditambahkan!" << endl;
            break;
        }

        case 2: {
            cout << "Lihat Buku" << endl;
            if (jumlahBuku == 0) {
                cout << "Belum ada buku yang ditambahkan." << endl;
            }
            else {
                cout << "Daftar Buku: " << endl;
                for (int i = 0; i < jumlahBuku; i++) {
                    cout << "Buku " << (i + 1) << ":" << endl;
                    cout << "Judul: " << daftarBuku[i]->judul << endl;
                    cout << "Penerbit: " << daftarBuku[i]->penerbit->nama << endl;
                    cout << "Pengarang: " << daftarBuku[i]->pengarang->nama << endl;
                }
            }
            break;
        }
        case 3: {
            cout << "Hapus Buku" << endl;
            if (jumlahBuku == 0) {
                cout << "Belum ada buku yang ditambahkan." << endl;
            }
            else {
                int indeksBuku;
                cout << "Indeks Buku yang akan dihapus: ";
                cin >> indeksBuku;

                if (indeksBuku >= 1 && indeksBuku <= jumlahBuku) {
                    // Menghapus buku dari array dan menggeser elemen-elemen setelahnya
                    delete daftarBuku[indeksBuku - 1];
                    for (int i = indeksBuku - 1; i < jumlahBuku - 1; i++) {
                        daftarBuku[i] = daftarBuku[i + 1];
                    }

                    cout << "Buku berhasil dihapus." << endl;
                }
                else {
                    cout << "Indeks buku tidak valid." << endl;
                }
            }
            break;
        }

        default:
            cout << "Pilihan tidak valid." << endl;
            break;
        }
        cout << endl;
    }

    // Membersihkan memori
    for (int i = 0; i < jumlahBuku; i++) {
        delete daftarBuku[i];
    }

    return 0;
}