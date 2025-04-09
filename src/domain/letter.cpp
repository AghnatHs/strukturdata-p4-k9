#include "domain/letter.hpp"

#include <iomanip>

#include "utils.hpp"

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
    os << "Tanggal  : "
       << put_time(localtime(&letter.date), "%Y-%m-%d %H:%M:%S") << endl
       << endl;
    os << "Judul    : " << letter.title << endl;
    os << "Pengirim : " << letter.sender << endl;
    os << "Isi      : " << letter.content << endl;
    os << "Status   : " << letter.status << endl;
    os << "==============================================" << endl;
    return os;
}