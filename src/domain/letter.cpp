#include "domain/letter.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

#include "crypto.hpp"
#include "utils.hpp"

Letter::Letter(string sender, string title, string content)
    : id{generateRandomIdWithPrefix(8, "SURAT")},
      date{time(nullptr)},
      status{"PENDING"},
      sender{sender},
      title{title},
      content{content} {
    this->key = rand() % 27 + 1;
    this->content = Crypto::encrypt(this->content, this->key);
}

string Letter::getId() { return id; }

string Letter::getFormattedDate() const {
    ostringstream oss;
    oss << put_time(std::localtime(&date), "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

string Letter::serializeToCSV() const {
    // Format: id,date,title,content,sender,status
    return id + "," + to_string(date) + "," + title + "," + content + "," +
           sender + "," + status;
}

Letter Letter::fromCSV(const string& line) {
    vector<string> tokens;
    string token;
    stringstream ss(line);

    while (getline(ss, token, ',')) {
        tokens.push_back(token);
    }

    Letter letter(tokens[4], tokens[2], tokens[3]);
    letter.id = tokens[0];
    letter.date = stoi(tokens[1]);
    letter.status = tokens[5];

    return letter;
}

void Letter::changeStatus(string newStatus) { status = newStatus; }

ostream& operator<<(ostream& os, const Letter& letter) {
    os << "==================== Surat ====================" << endl;
    os << "ID       : " << letter.id << endl;
    os << "Tanggal  : " << letter.getFormattedDate() << endl << endl;
    os << "Judul    : " << letter.title << endl;
    os << "Pengirim : " << letter.sender << endl;
    os << "Isi      : " << Crypto::decrypt(letter.content, letter.key) << endl;
    os << "Status   : " << letter.status << endl;
    os << "================================================" << endl;
    return os;
}