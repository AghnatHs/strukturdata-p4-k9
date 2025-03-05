#include "queue.h"

void QueueSurat::enqueue(Surat surat) { this->daftar_surat.push_back(surat); };
void QueueSurat::index() {
    {
        if (this->daftar_surat.empty()) {
            cout << "Tidak ada surat." << endl;
        } else {
            for (int i = 0; i <= this->daftar_surat.size() - 1; i++) {
                this->daftar_surat[i].show();
                cout << "---------" << endl;
            }
        }
    }
}