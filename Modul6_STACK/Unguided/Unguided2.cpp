
#include <iostream>
#include <stack>

using namespace std;

string pengulang176(string kalimat176) {
  stack<char> s; // Buat stack untuk menyimpan karakter kalimat

  for (int i = 0; i < kalimat176.length(); i++) { // Masukkan karakter kalimat ke stack
    s.push(kalimat176[i]);
  }

  string setelahmengulangi176; // Membalik kalimat dengan mengeluarkan karakter dari stack
  while (!s.empty()) {
    setelahmengulangi176 += s.top();
    s.pop();
  }

  return setelahmengulangi176;
}

int main() {
  string kalimat176;
  cout << "-=-=- Membalik Kata -=-=-" << endl;

  do {
  cout << "\n Masukkan kalimat yang ingin dibalikkan: ";  // Input kalimat dari pengguna
  getline(cin, kalimat176);

  string setelahmengulangi176 = pengulang176(kalimat176);  // Membalik kalimat

  cout << " Kalimat yang dibalik: " << setelahmengulangi176 << endl; // Menampilkan kalimat yang dibalik

  } while (kalimat176 != "exit");
  return 0;
}
