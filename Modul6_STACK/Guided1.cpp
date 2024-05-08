#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull () {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull ()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    } 
}

void popArrayBuku () {
    if (isEmpty ()) {
        cout << "Tidak ada data yang dihapus"<< endl;
    } else {
        arrayBuku [top - 1] = "";
        top--;
    }
}

void peekArrayBuku (int posisi){
    if (isEmpty ()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        cout << "Data pada posisi " << posisi << " adalah: " << arrayBuku[posisi - 1] << endl;
    }
}

void destroyArrayBuku () {
    for (int i = top - 1; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku () {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        cout << "Data buku yang ada:" << endl;
        for (int i = top - 1; i >= 0; i--){
            cout << arrayBuku[i] << endl;
        }
    }
}

int main () {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya data = " << top << endl;

    cetakArrayBuku();

    cout << "\n";

    destroyArrayBuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;

    cetakArrayBuku();

    return 0;
}
