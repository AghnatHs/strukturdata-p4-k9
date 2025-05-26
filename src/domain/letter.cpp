#include "domain/letter.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

#include "crypto.hpp"
#include "utils.hpp"

Letter::Letter()
    : id(""),
      date(time(nullptr)),
      title(""),
      content(""),
      sender(""),
      receiver(""),
      status("PENDING"),
      key(0),
      processedAt(nullopt) {}

Letter::Letter(string sender, string receiver, string title, string content)
    : id{generateRandomIdWithPrefix(8, "SURAT")},
      date{time(nullptr)},
      status{"PENDING"},
      sender{sender},
      receiver{receiver},
      title{title},
      content{content},
      processedAt(nullopt) {
    this->key = generateRandomInteger(1, 26);
    this->content = Crypto::encrypt(this->content, this->key);
}

Letter::Letter(string sender, string receiver, string title, string content, int key)
    : id{generateRandomIdWithPrefix(8, "SURAT")},
      date{time(nullptr)},
      status{"PENDING"},
      sender{sender},
      receiver{receiver},
      title{title},
      content{content},
      key{key},
      processedAt(nullopt) {}

time_t Letter::getDate() const { return date; }

string Letter::getId() const { return id; }

string Letter::getFormattedDate() const {
    ostringstream oss;
    oss << put_time(std::localtime(&date), "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

string Letter::getFormattedProcessedAt() const {
    if (!processedAt.has_value()) {
        return "Belum diproses";
    }
    std::ostringstream oss;
    std::tm* tmPtr = localtime(&processedAt.value());
    if (tmPtr == nullptr) {
        return "Waktu tidak valid";
    }
    oss << put_time(tmPtr, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

string Letter::serializeToCSV() const {
    string processedAtStr =
        processedAt.has_value() ? to_string(processedAt.value()) : "";
    // Format: id,date,title,content,sender,status, key
    return id + "," + to_string(date) + "," + title + "," + content + "," +
           sender + "," + status + "," + to_string(key) + "," + processedAtStr + "," + receiver;
}

Letter Letter::fromCSV(const string& line) {
    vector<string> tokens;
    string token;
    stringstream ss(line);

    while (getline(ss, token, ',')) {
        tokens.push_back(token);
    }

    Letter letter(tokens[4], tokens[8], tokens[2], tokens[3], stoi(tokens[6]));
    letter.id = tokens[0];
    letter.date = stoi(tokens[1]);
    letter.status = tokens[5];

    if (tokens.size() > 7 && !tokens[7].empty()) {
        letter.processedAt = static_cast<time_t>(stol(tokens[7]));
    }

    return letter;
}

void Letter::changeStatus(string newStatus) {
    status = newStatus;
    if (!processedAt.has_value()) {
        processedAt = time(nullptr);
    }
}

ostream& operator<<(ostream& os, const Letter& letter) {
    os << "==================== Surat ====================" << endl;
    os << "ID       : " << letter.id << endl;
    os << "Tanggal  : " << letter.getFormattedDate() << endl << endl;
    os << "Judul    : " << letter.title << endl;
    os << "Pengirim : " << letter.sender << endl;
    os << "Penerima : " << letter.receiver << endl;
    os << "Isi      : " << Crypto::decrypt(letter.content, letter.key) << endl;
    os << "Status   : " << letter.status << endl << endl;
    os << "Diproses : " << letter.getFormattedProcessedAt() << endl;
    os << "================================================" << endl;
    return os;
}

string Letter::getStatus() const {
    return status;
}

optional<time_t> Letter::getProcessedAt() const {
    return processedAt;
}