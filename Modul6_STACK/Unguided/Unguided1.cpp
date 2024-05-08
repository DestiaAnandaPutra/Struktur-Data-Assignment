
#include <iostream>
#include <stack>

using namespace std;

bool Palindrome_176(string kalimat176)
{
  for (int i = 0; i < kalimat176.length(); i++)
  { // Konversi kalimat ke huruf kecil
    kalimat176[i] = tolower(kalimat176[i]);
  }

  stack<char> s; // Buat stack untuk menyimpan karakter kalimat

  for (int i = 0; i < kalimat176.length(); i++)
  { // Masukkan karakter kalimat ke stack
    s.push(kalimat176[i]);
  }

  for (int i = 0; i < kalimat176.length() / 2; i++)
  { // Bandingkan karakter dari depan dan belakang kalimat
    if (kalimat176[i] != s.top())
    {
      return false;
    }
    s.pop();
  }

  return true;
}

int main()
{
  string kalimat176;
  cout << "-=-=- DESTIA -=-=-" << endl;

  do
  {
    cout << "\n Masukkan kalimat: "; // Input kalimat dari pengguna
    getline(cin, kalimat176);

    if (Palindrome_176(kalimat176))
    { // Periksa apakah kalimat palindrom atau bukan
      cout << " Kalimat " << kalimat176 << " adalah : Palindrom!" << endl;
    }
    else
    {
      cout << " Kalimat " << kalimat176 << " bukan : Palindrom!" << endl;
    }

  } while (kalimat176 != "exit");
  return 0;
}
