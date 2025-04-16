#include "domain/letter.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>

#include "crypto.hpp"
#include "utils.hpp"

Letter::Letter(string sender, string title, string content)
    : id{generateRandomIdWithPrefix(8, "SURAT")},
      date{time(nullptr)},
      status{"PENDING"},
      sender{sender},
      title{title},
      content{Crypto::encrypt(content, 15)} {}

string Letter::getId() { return id; }

string Letter::getFormattedDate() const {
    ostringstream oss;
    oss << put_time(std::localtime(&date), "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

void Letter::changeStatus(string newStatus) { status = newStatus; }

ostream& operator<<(ostream& os, const Letter& letter) {
    os << "==================== Surat ====================" << endl;
    os << "ID       : " << letter.id << endl;
    os << "Tanggal  : " << letter.getFormattedDate() << endl << endl;
    os << "Judul    : " << letter.title << endl;
    os << "Pengirim : " << letter.sender << endl;
    os << "Isi      : " << Crypto::decrypt(letter.content, 15) << endl;
    os << "Status   : " << letter.status << endl;
    os << "================================================" << endl;
    return os;
}