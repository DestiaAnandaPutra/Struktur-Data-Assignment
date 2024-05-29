# <h1 align="center">Laporan Praktikum Modul 9 Graph and Tree </h1>
<p align="center">Destia Ananda Putra</p>
<p align="center">2311102176</p>
<p align="center">IF 11 E</p>

# Graph
  Graf adalah struktur data yang terdiri dari sekumpulan simpul (node atau vertex) dan sekumpulan busur (edge) yang menghubungkan pasangan simpul tersebut. Graf dapat digolongkan menjadi beberapa jenis, seperti graf berarah (directed graph) di mana busurnya memiliki arah, dan graf tak berarah (undirected graph) di mana busurnya tidak memiliki arah. Graf juga bisa berbobot (weighted graph), di mana setiap busur memiliki bobot tertentu yang mungkin merepresentasikan jarak, biaya, atau nilai lainnya[1]. 

# Tree
  Pohon(Tree) adalah jenis khusus dari graf yang tidak mengandung siklus dan memiliki satu simpul akar (root) serta simpul-simpul lainnya yang terhubung dalam hierarki. Setiap simpul dalam pohon dapat memiliki sejumlah anak, tetapi setiap anak hanya memiliki satu induk. Pohon biner adalah jenis pohon di mana setiap simpul memiliki paling banyak dua anak, yaitu anak kiri dan anak kanan. Pohon banyak digunakan dalam berbagai aplikasi, termasuk struktur data seperti heap, BST (Binary Search Tree), dan representasi hierarki data seperti file system[2]. 

# Guided
## Guided 1
```C++
#include <iostream> 
#include <iomanip> 
using namespace std; 
 
string simpul[7] = { 
    "Ciamis",  
    "Bandung",  
    "Bekasi",  
    "tasikmalaya", 
    "Cianjur",  
    "Purwokerto",  
    "Yogyakarta"  
}; 
 
int busur[7][7] = { 
    {0, 7, 8, 0, 0, 0, 0}, 
    {0, 0, 5, 0, 0, 15, 0}, 
    {0, 6, 0, 0, 5, 0, 0}, 
    {0, 5, 0, 0, 2, 4, 0}, 
    {23, 0, 0, 10, 0, 0, 8}, 
    {0, 0, 0, 0, 7, 0, 3}, 
    {0, 0, 0, 0, 9, 4, 0} 
}; 
 
 
void tampilGraph(){ 
    for (int baris = 0; baris <7; baris ++){ 
        cout <<" " << setiosflags (ios::left)<<setw (15) 
        << simpul [baris] << " : "; 
        for (int kolom = 0; kolom<7; kolom++){ 
            if (busur[baris][kolom]!=0){ 
                cout << " " << simpul[kolom]<< "(" << busur[baris][kolom] 
<< ")"; 
            } 
        } 
        cout << endl; 
    }       
} 
 
int main(){ 
    tampilGraph(); 
    return 0; 
} 
```
<p align="justify">Kode di atas digunakan untuk menjalankan sebuah program graph. Isi program ini dimulai dari adanya array string simpul[7]. Array simpul ini menyimpan nama-nama kota yang akan menjadi node (simpul) pada graf. Kemudian ada matriks int busur[7][7], matriks busur ini mewakili berat (weight) dari busur (edge) antara simpul-simpul tersebut. Jika busur[i][j] bernilai 0, berarti tidak ada busur langsung dari simpul i ke simpul j. Dibawahnya ada prosedur void tampilGraph(), Fungsi ini digunakan untuk menampilkan graf dalam bentuk yang mudah dibaca. Perulangan for pertama akan melakukan iterasi melalui setiap simpul (baris). Perulangan for kedua akan melakukan iterasi melalui setiap kemungkinan simpul tujuan (kolom) dari simpul saat ini. Kondisi if (busur[baris][kolom] != 0) akan memeriksa apakah ada busur dari simpul saat ini ke simpul tujuan. Lalu akhirnya program akan menampilkan nama simpul tujuan dan berat busur yang menghubungkan simpul-simpul tersebut. Akhirnya, fungsi main() memanggil tampilGraph() untuk menampilkan graf dan kemudian mengembalikan nilai 0 yang menunjukkan bahwa program telah berakhir dengan sukses.</p>

### Guided 2
```C++
`#include <iostream> 
using namespace std; 
 
// PROGRAM BINARY TREE 
// Deklarasi Pohon 
struct Pohon { 
    char data; 
    Pohon *left, *right, *parent; //pointer 
}; 
 
//pointer global 
Pohon *root; 
 
// Inisialisasi 
void init() { 
    root = NULL; 
} 
 
bool isEmpty() { 
    return root == NULL; 
} 
 
Pohon *newPohon(char data) { 
    Pohon *node = new Pohon(); 
    node->data = data; 
    node->left = NULL; 

    node->right = NULL; 
    node->parent = NULL; 
    return node; 
} 
 
void buatNode(char data) { 
    if (isEmpty()) { 
        root = newPohon(data); 
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << 
endl; 
    } else { 
        cout << "\nPohon sudah dibuat" << endl; 
    } 
} 
 
Pohon *insertLeft(char data, Pohon *node) { 
    if (isEmpty()) { 
        cout << "\nBuat tree terlebih dahulu!" << endl; 
        return NULL; 
    } else { 
        if (node->left != NULL) { 
            cout << "\nNode " << node->data << " sudah ada child kiri!" 
<< endl; 
            return NULL; 
        } else { 
            Pohon *baru = newPohon(data); 
            baru->parent = node; 
            node->left = baru; 
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl; 
            return baru; 
        } 
    } 
} 
 
Pohon *insertRight(char data, Pohon *node) { 
    if (isEmpty()) { 
        cout << "\nBuat tree terlebih dahulu!" << endl; 
        return NULL; 
    } else { 
        if (node->right != NULL) { 
            cout << "\nNode " << node->data << " sudah ada child kanan!" 
<< endl; 
            return NULL; 
        } else { 
            Pohon *baru = newPohon(data); 
            baru->parent = node; 
            node->right = baru; 
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl; 
 
            return baru; 
        } 
    } 
} 
 
void update(char data, Pohon *node) { 
    if (isEmpty()) { 
        cout << "\nBuat tree terlebih dahulu!" << endl; 
    } else { 
        if (!node) 
            cout << "\nNode yang ingin diganti tidak ada!!" << endl; 
        else { 
            char temp = node->data; 
            node->data = data; 
            cout << "\nNode " << temp << " berhasil diubah menjadi " << 
data << endl; 
        } 
    } 
} 
 
void retrieve(Pohon *node) { 
    if (isEmpty()) { 
        cout << "\nBuat tree terlebih dahulu!" << endl; 
    } else { 
        if (!node) 
            cout << "\nNode yang ditunjuk tidak ada!" << endl; 
        else { 
            cout << "\nData node : " << node->data << endl; 
        } 
    } 
} 
 
void find(Pohon *node) { 
    if (isEmpty()) { 
        cout << "\nBuat tree terlebih dahulu!" << endl; 
    } else { 
        if (!node) 
            cout << "\nNode yang ditunjuk tidak ada!" << endl; 
        else { 
            cout << "\nData Node : " << node->data << endl; 
            cout << "Root : " << root->data << endl; 
 
            if (!node->parent) 
                cout << "Parent : (tidak punya parent)" << endl; 
            else 
                cout << "Parent : " << node->parent->data << endl; 
 
            if (node->parent != NULL && node->parent->left != node && 
node->parent->right == node) 
                cout << "Sibling : " << node->parent->left->data << endl; 
 
            else if (node->parent != NULL && node->parent->right != node 
&& node->parent->left == node) 
                cout << "Sibling : " << node->parent->right->data << 
endl; 
            else 
                cout << "Sibling : (tidak punya sibling)" << endl; 
 
            if (!node->left) 
                cout << "Child Kiri : (tidak punya Child kiri)" << endl; 
            else 
                cout << "Child Kiri : " << node->left->data << endl; 
 
            if (!node->right) 
                cout << "Child Kanan : (tidak punya Child kanan)" << 
endl; 
            else 
                cout << "Child Kanan : " << node->right->data << endl; 
        } 
    } 
} 
 
// Penelusuran (Traversal) 
// preOrder 
void preOrder(Pohon *node) { 
    if (isEmpty()) 
        cout << "\nBuat tree terlebih dahulu!" << endl; 
    else { 
        if (node != NULL) { 
            cout << " " << node->data << ", "; 
            preOrder(node->left); 
            preOrder(node->right); 
        } 
    } 
} 
 
// inOrder 
void inOrder(Pohon *node) { 
    if (isEmpty()) 
        cout << "\nBuat tree terlebih dahulu!" << endl; 
    else { 
        if (node != NULL) { 
            inOrder(node->left); 
            cout << " " << node->data << ", "; 
            inOrder(node->right); 
        } 
    } 
} 
 
// postOrder 
void postOrder(Pohon *node) { 
 
 
    if (isEmpty()) 
        cout << "\nBuat tree terlebih dahulu!" << endl; 
    else { 
        if (node != NULL) { 
            postOrder(node->left); 
            postOrder(node->right); 
            cout << " " << node->data << ", "; 
        } 
    } 
} 
 
// Hapus Node Tree 
void deleteTree(Pohon *node) { 
    if (isEmpty()) 
        cout << "\nBuat tree terlebih dahulu!" << endl; 
    else { 
        if (node != NULL) { 
            if (node != root) { 
                if (node->parent->left == node) 
                    node->parent->left = NULL; 
                else if (node->parent->right == node) 
                    node->parent->right = NULL; 
            } 
            deleteTree(node->left); 
            deleteTree(node->right); 
 
            if (node == root) { 
                delete root; 
                root = NULL; 
            } else { 
                delete node; 
            } 
        } 
    } 
} 
 
// Hapus SubTree 
void deleteSub(Pohon *node) { 
    if (isEmpty()) 
        cout << "\nBuat tree terlebih dahulu!" << endl; 
    else { 
        deleteTree(node->left); 
        deleteTree(node->right); 
        cout << "\nNode subtree " << node->data << " berhasil dihapus." 
<< endl; 
    } 
} 
 
// Hapus Tree 
void clear() {  
 
 
    if (isEmpty()) 
        cout << "\nBuat tree terlebih dahulu!!" << endl; 
    else { 
        deleteTree(root); 
        cout << "\nPohon berhasil dihapus." << endl; 
    } 
} 
 
// Cek Size Tree 
int size(Pohon *node) { 
    if (isEmpty()) { 
        cout << "\nBuat tree terlebih dahulu!!" << endl; 
        return 0; 
    } else { 
        if (!node) { 
            return 0; 
        } else { 
            return 1 + size(node->left) + size(node->right); 
        } 
    } 
} 
 
// Cek Height Level Tree 
int height(Pohon *node) { 
    if (isEmpty()) { 
        cout << "\nBuat tree terlebih dahulu!" << endl; 
        return 0; 
    } else { 
        if (!node) { 
            return 0; 
        } else { 
            int heightKiri = height(node->left); 
            int heightKanan = height(node->right); 
 
            if (heightKiri >= heightKanan) { 
                return heightKiri + 1; 
            } else { 
                return heightKanan + 1; 
            } 
        } 
    } 
} 
 
// Karakteristik Tree 
void characteristic() { 
    int s = size(root); 
    int h = height(root); 
    cout << "\nSize Tree : " << s << endl; 
    cout << "Height Tree : " << h << endl; 
    if (h != 0) 
 
 
        cout << "Average Node of Tree : " << s / h << endl; 
    else 
        cout << "Average Node of Tree : 0" << endl; 
} 
 
int main() { 
    init(); 
    buatNode('A'); 
 
    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, 
*nodeJ; 
 
    nodeB = insertLeft('B', root); 
    nodeC = insertRight('C', root); 
    nodeD = insertLeft('D', nodeB); 
    nodeE = insertRight('E', nodeB); 
    nodeF = insertLeft('F', nodeC); 
    nodeG = insertLeft('G', nodeE); 
    nodeH = insertRight('H', nodeE); 
    nodeI = insertLeft('I', nodeG); 
    nodeJ = insertRight('J', nodeG); 
 
    update('Z', nodeC); 
    update('C', nodeC); 
    retrieve(nodeC); 
    find(nodeC); 
    cout << "\nPreOrder :" << endl; 
    preOrder(root); 
    cout << "\n" << endl; 
    cout << "InOrder :" << endl; 
    inOrder(root); 
    cout << "\n" << endl; 
    cout << "PostOrder :" << endl; 
    postOrder(root); 
    cout << "\n" << endl; 
    characteristic(); 
    deleteSub(nodeE); 
    cout << "\nPreOrder :" << endl; 
    preOrder(root); 
    cout << "\n" << endl; 
    characteristic(); 
}
```
<p align="justify">Program ini adalah implementasi sederhana dari Pohon Biner dalam C++. Fitur-fiturnya mencakup inisialisasi pohon, pembuatan, penambahan, pengubahan, dan pengambilan informasi tentang node, serta penelusuran pohon. Program juga dapat menghapus node atau pohon, menghitung ukuran dan tinggi pohon, serta menampilkan karakteristik pohon. Keseluruhannya, program ini memberikan fondasi untuk manipulasi pohon biner dan dapat dikembangkan lebih lanjut sesuai kebutuhan.

## Unguided 

## Unguided 1 

```c++
#include <iostream>
#include <vector> // library ini digunakan untuk fungsi vector
#include <iomanip> // library ini digunakan untuk fungsi setw()

//Nama : Destia Ananda Putra
//NIM  : 2311102176

using namespace std;

int main() {
    int Destia_2311102176; // variabel ini digunakan untuk menyimpan jumlah simpul
    cout << "-=-=-=- Destia' Program Grafis Jarak Kota -=-=-=-\n";

    do {
    cout << "\nsilahkan masukan jumlah simpul (0 to exit): "; cin >> Destia_2311102176;

    vector<string> cities(Destia_2311102176); // vector ini digunakan untuk menyimpan nama-nama simpul
    cout << "\nMasukan Nama Simpul" << endl;
    for (int i = 0; i < Destia_2311102176; ++i) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> cities[i]; 
    }

    vector<vector<int>> Matrix_2176(Destia_2311102176, vector<int>(Destia_2311102176)); // vector ini digunakan untuk menyimpan jarak antar simpul, vector<int> ini digunakan untuk menyimpan jarak antar simpul
    cout << "\nSilahkan Masukan Bobot Antar Simpul\n";
    for (int i = 0; i < Destia_2311102176; ++i) {
        for (int j = 0; j < Destia_2311102176; ++j) { // perulangan ini digunakan untuk menginput jarak antar simpul
            cout << cities[i] << " --> " << cities[j] << " = ";
            cin >> Matrix_2176[i][j]; // Matrix_2176 ini digunakan untuk menyimpan jarak antar simpul, i adalah simpul asal dan j adalah simpul tujuan
        }
    }

    cout << "\n-=-=-=-=-=- Grafik Jarak Kota -=-=-=-=-=-";
    cout << "\n           ";
    for (const auto& city : cities) { // barisan ini digunakan untuk menampilkan nama-nama simpul, const auto& digunakan untuk mengambil nilai dari vector cities
        cout << setw(10) << city;
    }
    cout << '\n';

    for (int i = 0; i < Destia_2311102176; ++i) { // perulangan ini digunakan untuk menampilkan jarak antar simpul
        cout << setw(10) << cities[i];
        for (int j = 0; j < Destia_2311102176; ++j) {
            cout << setw(10) << Matrix_2176[i][j]; // perulangan ini digunakan untuk Matrix_2176[i][j]
        }
        cout << '\n';
    }
    } while (Destia_2311102176 != 0); // perulangan ini digunakan untuk mengulang program jika Destia_2311102176 tidak sama dengan 0
    cout << "Hope it helps!";
    return 0;
}
```
#### Output Unguided 1:
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/2cc0b089-3e23-4b67-807e-75fbc8e0f409)</br>
<p align="justify">Kode di atas digunakan untuk menjalankan sebuah program graph yang menghitung jarak dari sebuah kota ke kota lainnya. Isi program ini dimulai langsung di fungsi int main(), di mana dalam fungsi tersebut ada int Destia_2311102176 yang digunakan untuk deklarasi variabel untuk menyimpan jumlah simpul (kota). Lalu, ada perulangan do { ... } while (Jordan_2311102176 != 0); sebagai loop yang memungkinkan pengguna untuk mengulangi proses hingga mereka memasukkan 0 untuk keluar. Selanjutnya ada vector cities  Selanjutnya ada vector> Matrix_2176  sebagai matriks 2D untuk menyimpan jarak antara setiap pasangan kota dan loop bersarang for untuk meminta pengguna memasukkan jarak antara setiap pasangan kota. Matrix_2176[i][j] menyimpan jarak dari kota i ke kota j. Lalu, ada juga loop for dengan const auto& city digunakan untuk menampilkan nama-nama kota sebagai header kolom dengan lebar kolom yang diatur oleh setw(10). Lalu, ada loop for digunakan untuk menampilkan setiap baris matriks jarak dan setw(10) digunakan untuk memastikan setiap nilai jarak rata dalam kolom yang sama. Kode ini ditutupi dengan loop do-while yang memungkinkan pengguna mengulangi proses atau keluar dengan memasukkan 0. Pesan penutup "Hope it helps!" dan pengembalian 0 menandakan akhir eksekusi program

### Unguided 2 

```C++
#include <iostream>
#include <iomanip>

//Nama : Destia Ananda Putra
//NIM  : 2311102176

using namespace std;

struct Pohon
{
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

void init() // inisialisasi
{
    root = NULL;
}

bool isEmpty() // cek apakah tree kosong
{
    return root == NULL;
}

void buatNode(char data) // membuat node root
{
    if (isEmpty())
    {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\nNode " << data << " berhasil dibuat sebagai root!" << endl;
    }
    else
    {
        cout << "\nTree sudah ada!" << endl;
    }
}

Pohon *findNode(Pohon *node, char data) // mencari node
{
    if (node == NULL) return NULL;
    if (node->data == data) return node;

    Pohon *foundNode = findNode(node->left, data);
    if (foundNode == NULL)
        foundNode = findNode(node->right, data);

    return foundNode;
}

Pohon *insertLeft(char data, Pohon *node) // menambah child kiri
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}

Pohon *insertRight(char data, Pohon *node) // menambah child kanan
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}

void update(char data, Pohon *node) // mengupdate node
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        }
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

void find(Pohon *node) // mencari node dan menampilkan informasi node
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\nData Node: " << node->data << endl;
            cout << "Root: " << root->data << endl;
            if (!node->parent)
                cout << "Parent: (tidak punya parent)" << endl;
            else
                cout << "Parent: " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << "Sibling: " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling: " << node->parent->right->data << endl;
            else
                cout << "Sibling: (tidak punya sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri: (tidak punya child kiri)" << endl;
            else
                cout << "Child Kiri: " << node->left->data << endl;
            if (!node->right)
                cout << "Child Kanan: (tidak punya child kanan)" << endl;
            else
                cout << "Child Kanan: " << node->right->data << endl;
        }
    }
}

void printChild(Pohon *node) // menampilkan child
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else if (!node)
    {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
    }
    else
    {
        if (node->left)
        {
            cout << "Child Kiri: " << node->left->data << endl;
        }
        else
        {
            cout << "Child Kiri: (tidak ada)" << endl;
        }

        if (node->right)
        {
            cout << "Child Kanan: " << node->right->data << endl;
        }
        else
        {
            cout << "Child Kanan: (tidak ada)" << endl;
        }
    }
}

void printDescendants(Pohon *node) // menampilkan descendants
{
    void preOrder(Pohon * node);

    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else if (!node)
    {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
    }
    else
    {
        cout << "Descendants dari node " << node->data << " : ";
        if (node->left) preOrder(node->left);
        if (node->right) preOrder(node->right);
        cout << endl;
    }
}

// Cek Size Tree
int size(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node)
{
    if (node != NULL)
    {
        cout << " " << node->data << ", ";
        preOrder(node->left);
        preOrder(node->right);
    }
}


// inOrder
void inOrder(Pohon *node = root)
{
    if (node != NULL)
    {
        inOrder(node->left);
        cout << " " << node->data << ", ";
        inOrder(node->right);
    }
}

// postOrder
void postOrder(Pohon *node = root)
{
    if (node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        cout << " " << node->data << ", ";
    }
    cout << endl;
}

// Karakteristik Tree
void characteristic()
{
    cout << "\n Size Tree : " << size() << endl;
    cout << " Height Tree : " << height() << endl;
    cout << " Average Node of Tree : " << size() / height() << endl;
}

int main()
{
    init();
    char Choice_2176, Data_2176, Direction_2176, ParentData_2176;
    Pohon *node;

    cout << "\n-=-=-=-=-=- WELCOME TO Destia TREE PROGRAM -=-=-=-=-=-\n";

    do
    {
        cout << "\nMenu: ";
        cout << "\n1. Buat Node Root";
        cout << "\n2. Tambah Child (kiri/kanan)";
        cout << "\n3. Update Node";
        cout << "\n4. Characteristics";
        cout << "\n5. Find Node";
        cout << "\n6. PreOrder Traversal";
        cout << "\n7. InOrder Traversal";
        cout << "\n8. PostOrder Traversal";
        cout << "\n9. Print Child";
        cout << "\n0. Print Descendants";
        cout << "\nPick your choice: "; cin >> Choice_2176;

        switch (Choice_2176)
        {
        case '1': // case ini digunakan untuk membuat node root
            cout << "\nOke sip, mulai dari root! Input data untuk rootnya: ";
            cin >> Data_2176;
            buatNode(Data_2176);
            break;

        case '2': // case ini digunakan untuk menambah child
            cout << "\nMasukkan data untuk child: ";
            cin >> Data_2176;
            cout << "\nChild yang diinput berada di posisi (Left (L/l) / Right (R/r)): ";
            cin >> Direction_2176;
            cout << "\nMasukkan data dari parent node: ";
            cin >> ParentData_2176;
            node = findNode(root, ParentData_2176);
            if (node == NULL)
            {
                cout << "\nNode dengan data " << ParentData_2176 << " tidak ditemukan!" << endl;
            }
            else
            {
                if (Direction_2176 == 'L' || Direction_2176 == 'l')
                {
                    insertLeft(Data_2176, node);
                }
                else if (Direction_2176 == 'R' || Direction_2176 == 'r')
                {
                    insertRight(Data_2176, node);
                }
                else
                {
                    cout << "\nHah! Pilihan tidak valid!" << endl;
                }
            }
            break;

        case '3': // case ini digunakan untuk mengupdate node
            cout << "\nMasukkan data baru untuk diupdate: ";
            cin >> Data_2176;
            cout << "\nMasukkan data dari node yang ingin diupdate: ";
            cin >> ParentData_2176;
            node = findNode(root, ParentData_2176);
            if (node == NULL)
            {
                cout << "\nNode dengan data " << ParentData_2176 << " tidak ditemukan!" << endl;
            }
            else
            {
                update(Data_2176, node);
            }
            break;

        case '4': // case ini digunakan untuk menampilkan karakteristik tree
            cout << "\nKarakteristik dari tree ini:";
            characteristic();
            break;

        case '5': // case ini digunakan untuk mencari node
            cout << "\nMasukkan data dari node yang ingin dicari: ";
            cin >> ParentData_2176;
            node = findNode(root, ParentData_2176);
            if (node == NULL)
            {
                cout << "\nNode dengan data " << ParentData_2176 << " tidak ditemukan!" << endl;
            }
            else
            {
                find(node);
            }
            break;

        case '6': // case ini digunakan untuk preOrder traversal
            cout << "\nPreOrder Traversal: ";
            preOrder(root);
            cout << endl;
            break;

        case '7': // case ini digunakan untuk inOrder traversal
            cout << "\nInOrder Traversal: ";
            inOrder(root);
            cout << endl;
            break;

        case '8': // case ini digunakan untuk postOrder traversal
            cout << "\nPostOrder Traversal: ";
            postOrder(root);
            cout << endl;
            break;

        case '9': // case ini digunakan untuk print child
            cout << "\nMasukkan data dari node yang ingin melihat child: ";
            cin >> ParentData_2176;
            node = findNode(root, ParentData_2176);
            if (node == NULL)
            {
                cout << "\nNode dengan data " << ParentData_2176 << " tidak ditemukan!" << endl;
            }
            else
            {
                printChild(node);
            }
            break;

        case '0': // case ini digunakan untuk print descendants
            cout << "\nMasukkan data dari node yang ingin melihat descendants: ";
            cin >> ParentData_2176;
            node = findNode(root, ParentData_2176);
            if (node == NULL)
            {
                cout << "\nNode dengan data " << ParentData_2176 << " tidak ditemukan!" << endl;
            }
            else
            {
                printDescendants(node);
            }
            break;

        default:
            cout << "\nWhat is this? I can't read this." << endl;
            break;
        }
    } while (Choice_2176 != '!');
    cout << "\nWelp! You decided to quit, so, goodbye!" << endl;

    return 0;
}
```
### Output Unguided 2
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/ed9e2663-b594-4b47-93c2-7b33db44e1b0)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/ffd3f0bf-2750-4b27-87db-27f01a6ee39b)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/1f9d2a9a-a3b8-4fb8-a3cb-58ed19e9eeb9)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/f66ce662-894f-4581-ba09-333661359684)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/78e187da-afbf-4734-903a-6b333277ad37)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/e5c022fd-ea6e-4e35-9735-e138309e9b70)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/ff5922a2-20a9-45a6-88d5-343237dd05de)</br>
<p align="justify">Kode di atas digunakan untuk menjalankan sebuah program tree. Program ini dimulai dari adanya struct Pohon, di mana struktur Pohon merepresentasikan node dalam pohon biner. Setiap node memiliki data untuk menyimpan nilai, left untuk menunjuk ke child kiri, right untuk menunjuk ke child kanan, parent untuk menunjuk ke parent node. Variabel global root menunjuk ke root dari pohon, sedangkan baru digunakan untuk membuat node baru. Adapun fungsi dan prosedur yang membangun program ini, pertama ada void init() untuk menginisialisasi pohon dengan mengatur root ke NULL dan bool isEmpty() untuk mengembalikan true jika pohon kosong (root adalah NULL), sebaliknya mengembalikan false. Adapun fungsi lain yang digunakan pada fungsi int main()
<p align="justify">Fungsi main menginisialisasi pohon, menampilkan menu kepada pengguna, dan melakukan operasi yang dipilih oleh pengguna. Loop do-while memastikan menu tetap muncul sampai pengguna memilih untuk keluar. Setiap case dalam switch-case menangani operasi yang sesuai berdasarkan input pengguna.

## Kesimpulan
<p align="justify">Graph dan tree adalah struktur data penting dalam C++ yang digunakan untuk memodelkan hubungan antar entitas data. Graph bersifat lebih umum, di mana entitas (disebut vertex) dapat terhubung secara bebas satu sama lain melalui koneksi (disebut edge). Relasi antar entitas bebas ditentukan sesuai kebutuhan. Sebagai contoh, graph dapat digunakan untuk memodelkan jaringan sosial, di mana pengguna terhubung dengan pengguna lain melalui pertemanan.</p>
<p align="justify">Di sisi lain, tree memiliki struktur yang lebih hierarkis. Entitas (disebut node) terhubung secara berjenjang, membentuk hubungan parent-child. Setiap node maksimal memiliki satu parent node, kecuali node paling atas (root) yang tidak memiliki parent. Struktur ini membuat tree sangat efisien untuk pencarian dan pengurutan data. Sebagai contoh, tree dapat digunakan untuk merepresentasikan struktur file directory dalam sistem operasi.</p>

## Refrensi
[1] Zheng Li dkk, C++ Programming. Republic State of China: De Gruyter, 2019.

 









