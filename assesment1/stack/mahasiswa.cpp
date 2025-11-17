#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX = 6;

struct Mahasiswa {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

class StackMahasiswa {
private:
    Mahasiswa data[MAX];
    int top;
public:
    StackMahasiswa() { createStack(); }

    void createStack() { top = -1; }

    bool isEmpty() const { return top == -1; }

    bool isFull() const { return top == MAX - 1; }

    bool push(const Mahasiswa &m) {
        if (isFull()) return false;
        top++;
        data[top] = m;
        return true;
    }

    bool pop(Mahasiswa &out) {
        if (isEmpty()) return false;
        out = data[top];
        top--;
        return true;
    }

    bool update(int posisi1based, const Mahasiswa &m) {
        if (isEmpty()) return false;
        int idx = posisi1based - 1;
        if (idx < 0 || idx > top) return false;
        data[idx] = m;
        return true;
    }

    void view() const {
        if (isEmpty()) {
            cout << "Stack kosong.\n";
            return;
        }
        cout << left << setw(4) << "No" 
             << setw(20) << "Nama" 
             << setw(12) << "NIM" 
             << setw(8) << "Tugas" 
             << setw(8) << "UTS" 
             << setw(8) << "UAS"
             << setw(10) << "NilAkhir" << '\n';
        cout << string(70, '-') << '\n';
        for (int i = 0; i <= top; ++i) {
            cout << setw(4) << (i+1)
                 << setw(20) << data[i].Nama
                 << setw(12) << data[i].NIM
                 << setw(8) << fixed << setprecision(2) << data[i].NilaiTugas
                 << setw(8) << data[i].NilaiUTS
                 << setw(8) << data[i].NilaiUAS
                 << setw(10) << nilaiAkhir(data[i])
                 << '\n';
        }
    }

    void searchNilaiAkhir(float minVal, float maxVal) const {
        bool found = false;
        cout << "Hasil pencarian nilai akhir antara " << minVal << " dan " << maxVal << ":\n";
        cout << left << setw(4) << "No" 
             << setw(20) << "Nama" 
             << setw(12) << "NIM" 
             << setw(10) << "NilAkhir" << '\n';
        cout << string(48, '-') << '\n';
        for (int i = 0; i <= top; ++i) {
            float na = nilaiAkhir(data[i]);
            if (na >= minVal && na <= maxVal) {
                found = true;
                cout << setw(4) << (i+1)
                     << setw(20) << data[i].Nama
                     << setw(12) << data[i].NIM
                     << setw(10) << fixed << setprecision(2) << na << '\n';
            }
        }
        if (!found) cout << "Tidak ada mahasiswa dalam rentang tersebut.\n";
    }

    static float nilaiAkhir(const Mahasiswa &m) {
        return 0.2f * m.NilaiTugas + 0.4f * m.NilaiUTS + 0.4f * m.NilaiUAS;
    }

    int size() const { return top + 1; }
    int capacity() const { return MAX; }
    int getTopIndex() const { return top; }
};

void inputMahasiswa(Mahasiswa &m) {
    cout << "Masukkan Nama: ";
    getline(cin >> ws, m.Nama);
    cout << "Masukkan NIM: ";
    getline(cin, m.NIM);
    cout << "Masukkan Nilai Tugas: ";
    cin >> m.NilaiTugas;
    cout << "Masukkan Nilai UTS: ";
    cin >> m.NilaiUTS;
    cout << "Masukkan Nilai UAS: ";
    cin >> m.NilaiUAS;
}

void printMenu() {
    cout << "\n=== MENU STACK MAHASISWA ===\n";
    cout << "1. Create Stack (reset)\n";
    cout << "2. Push (tambah mahasiswa)\n";
    cout << "3. Pop (hapus top)\n";
    cout << "4. Update (update posisi tertentu)\n";
    cout << "5. View (lihat semua)\n";
    cout << "6. Search Nilai Akhir (rentang)\n";
    cout << "7. Info kapasitas & size\n";
    cout << "0. Exit\n";
    cout << "Pilih: ";
}

int main() {
    StackMahasiswa stack;
    int pilih;
    do {
        printMenu();
        if (!(cin >> pilih)) {
            cout << "Input tidak valid. Keluar.\n";
            break;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (pilih) {
            case 1: {
                stack.createStack();
                cout << "Stack di-reset.\n";
                break;
            }
            case 2: {
                if (stack.isFull()) {
                    cout << "Stack penuh. Tidak bisa push.\n";
                } else {
                    Mahasiswa m;
                    inputMahasiswa(m);
                    if (stack.push(m)) cout << "Push berhasil.\n";
                    else cout << "Push gagal.\n";
                }
                break;
            }
            case 3: {
                Mahasiswa popped;
                if (stack.pop(popped)) {
                    cout << "Pop berhasil. Data yang di-pop:\n";
                    cout << "Nama: " << popped.Nama << ", NIM: " << popped.NIM
                         << ", NilAkhir: " << fixed << setprecision(2) << StackMahasiswa::nilaiAkhir(popped) << '\n';
                } else {
                    cout << "Stack kosong. Tidak bisa pop.\n";
                }
                break;
            }
            case 4: {
                if (stack.isEmpty()) {
                    cout << "Stack kosong. Tidak ada yang di-update.\n";
                } else {
                    cout << "Masukkan posisi (1 = bottom ... " << stack.size() << " = current top): ";
                    int pos;
                    cin >> pos;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    Mahasiswa m;
                    cout << "Masukkan data pengganti untuk posisi " << pos << ":\n";
                    inputMahasiswa(m);
                    if (stack.update(pos, m)) cout << "Update berhasil.\n";
                    else cout << "Update gagal. Posisi tidak valid.\n";
                }
                break;
            }
            case 5: {
                stack.view();
                break;
            }
            case 6: {
                float minv, maxv;
                cout << "Masukkan nilai min: ";
                cin >> minv;
                cout << "Masukkan nilai max: ";
                cin >> maxv;
                stack.searchNilaiAkhir(minv, maxv);
                break;
            }
            case 7: {
                cout << "Ukuran saat ini: " << stack.size() << "\n";
                cout << "Kapasitas: " << stack.capacity() << "\n";
                cout << "Top index: " << stack.getTopIndex() << "\n";
                break;
            }
            case 0:
                cout << "Keluar.\n";
                break;
            default:
                cout << "Pilihan tidak dikenal.\n";
        }
    } while (pilih != 0);

    return 0;
}
