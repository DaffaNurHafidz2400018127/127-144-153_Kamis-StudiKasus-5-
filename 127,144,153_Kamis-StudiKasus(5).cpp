#include <iostream>
using namespace std;

class MataKuliah {
public:
    string namaMatkul;
    int sks;
};

class Mahasiswa {
public:
    string nama;
    string nim;
    MataKuliah matkul[100];
    int jumlahMatkul;

    void inputData() {
        cout << "| Masukkan Nama Mahasiswa\t: ";
        cin.ignore();
        getline(cin, nama);

        cout << "| Masukkan NIM\t\t\t: ";
        getline(cin, nim);

        cout << "| Masukkan jumlah mata kuliah\t: ";
        cin >> jumlahMatkul;
    	cout<<"+===============================================+"<<endl;

        for (int i = 0; i < jumlahMatkul; i++) {
            cout << "Masukkan nama mata kuliah ke-" << i + 1 << "\t\t: ";
            cin.ignore();
            getline(cin, matkul[i].namaMatkul);

            cout << "Masukkan jumlah SKS mata kuliah ke- " << i + 1 << "\t: ";
            cin >> matkul[i].sks;
        }
    }

    int totalSKS(int index = 0) {
        if (index == jumlahMatkul) return 0;
        return matkul[index].sks + totalSKS(index + 1);
    }
};

int main() {
    const int HARGA_PER_SKS = 125000;
    const float DISKON = 0.15;
	cout<<"+===============================================+"<<endl;
	cout<<"|\tPROGRAM MRNGHITUNG UKT MAHASISWA\t|"<<endl;
	cout<<"+===============================================+"<<endl;
    Mahasiswa mhs;
    mhs.inputData();

    int totalSks = mhs.totalSKS();
    int totalBiaya = totalSks * HARGA_PER_SKS;
    float potongan = totalBiaya * DISKON;
    float totalAkhir = totalBiaya - potongan;

    cout << "\n\n=== Ringkasan Pembayaran ===" << endl;
    cout << "\nTotal SKS         : " << totalSks << endl;
    cout << "Total pembayaran  : Rp " << totalAkhir << endl;

    return 0;
}

