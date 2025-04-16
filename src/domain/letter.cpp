#include "domain/letter.hpp"

#include <iomanip>
#include <sstream>

#include "utils.hpp"

string Letter::getId() { return id; }

string Letter::getFormattedDate() const {
    ostringstream oss;
    oss << put_time(std::localtime(&date), "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

void Letter::changeStatus(string newStatus) { status = newStatus; }

Letter::Letter(string sender, string title, string content)
    : id{generateRandomIdWithPrefix(8, "SURAT")},
      date{time(nullptr)},
      status{"PENDING"},
      sender{sender},
      title{title},
      content{content} {}

ostream& operator<<(ostream& os, const Letter& letter) {
    os << "==================== Surat ====================" << endl;
    os << "ID       : " << letter.id << endl;
    os << "Tanggal  : " << letter.getFormattedDate() << endl << endl;
    os << "Judul    : " << letter.title << endl;
    os << "Pengirim : " << letter.sender << endl;
    os << "Isi      : " << letter.content << endl;
    os << "Status   : " << letter.status << endl;
    os << "================================================" << endl;
    return os;
}