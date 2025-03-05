#include <iostream>
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
    string toString() { return this->id; };
};

int main() {
    Surat surat("test", "test", "test", "Test");
    cout << surat.toString() << endl;
}