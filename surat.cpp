#include "surat.h"

#include <iostream>
using namespace std;

Surat::Surat(string id, string date, string content, string sender,
             string status) {
    this->id = id;
    this->date = date;
    this->content = content;
    this->sender = sender;
    this->status = status;
};

void Surat::show() {
    cout << "Surat No\t: " << this->id << endl;
    cout << "Date\t\t: " << this->date << endl;
    cout << "Content\t\t: " << this->content << endl;
    cout << "Sender\t\t: " << this->sender << endl;
    cout << "Status\t\t: " << this->status << endl;
}