#include <bits/stdc++.h>
using namespace std;

class Surat {
   private:
    string id;
    string date;
    string content;
    string status;

   public:
    Surat(string id, string date, string content, string status) {
        this->id = id;
        this->date = date;
        this->content = content;
        this->status = status;
    };
    void show () {
        cout << "ID: " << id << ", Tanggal: " << date << ", Status: " << status << ", Perihal " << content << endl;
    }
    string toString() { return this->id; };

};

class QueueSurat {
    private:
        vector<Surat> daftar_surat;
    public:
    void tambahSurat(Surat surat){
        daftar_surat.push_back(surat);
    }

    void hapusSurat() {
        if (!daftar_surat.empty()) {
            cout << "Menghapus surat: " << daftar_surat.front().toString() << endl;
            daftar_surat.erase(daftar_surat.begin());
        } else {
            cout << "Tidak ada surat untuk dihapus." << endl;
        }
    }
    void cetakSemuaSurat(){
        if(daftar_surat.empty()){
            cout << "Tidak ada surat."<< endl;
        }
        else{
            for(int i=0; i<=daftar_surat.size()-1 ;i++){
                daftar_surat[i].show();
            }
        }

        
    }
    
};
int main() {
    QueueSurat queue;
    Surat surat("test", "test", "test", "Test");
    Surat surat2("a", "b", "c", "d");
    queue.tambahSurat(surat);
    queue.tambahSurat(surat2);
    queue.cetakSemuaSurat();
    queue.hapusSurat();
    queue.cetakSemuaSurat();
    cout << surat.toString() << endl;
}