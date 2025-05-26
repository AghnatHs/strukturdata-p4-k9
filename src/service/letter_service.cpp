#include "service/letter_service.hpp"

#include <algorithm>
#include <fstream>
#include <vector>

#include "utils.hpp"

LetterService::LetterService() {};

Letter LetterService::getIncomingLetter() {
    return incomingLettersQueue.peek();
};

Letter LetterService::getLastProcessedLetter() {
    string top = lettersHistoryStr.top();
    size_t pos = top.find(" | ");
    string id;
    if (pos != string::npos) {
        id = top.substr(0, pos);
    }
    return *findLetterById(id);
}

void LetterService::processIncomingLetter(string newStatus) {
    Letter letter = incomingLettersQueue.peek();

    letter.changeStatus(newStatus);
    lettersHistoryStr.push(letter.getId() + " | " + "PENDING" + " --> " +
                           newStatus + " | " + getCurrentTimestampString());

    storeLetterToMap(letter);

    incomingLettersQueue.dequeue();
};

void LetterService::sendIncomingLetterToOffice(Letter letter) {
    incomingLettersQueue.enqueue(letter);
};
void LetterService::showIncomingLettersQueue() { incomingLettersQueue.print(); }
void LetterService::showIncomingLettersHistory() { lettersHistoryStr.print(); }
void LetterService::sendOutgoingLetter(Letter letter) {
    outgoingLettersQueue.enqueue(letter);
};

void LetterService::showOutgoingLettersQueue(Letter letter) {
    outgoingLettersQueue.print();
}
void LetterService::storeLetterToMap(const Letter& letter) {
    lettersHistoryMap[letter.getId()] = letter;
}

Letter* LetterService::findLetterById(const string& id) {
    auto it = lettersHistoryMap.find(id);
    if (it != lettersHistoryMap.end()) {
        return &it->second;
    }
    return nullptr;
}

void LetterService::loadLetterQueueFromCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        Letter letter = Letter::fromCSV(line);
        incomingLettersQueue.enqueue(letter);
    }

    file.close();
}

void LetterService::saveLetterQueueToCSV(const string& filename) {
    ofstream file(filename, ios::out | ios::trunc);
    if (!file.is_open()) return;

    Queue<Letter> tempQueue = incomingLettersQueue;

    while (!tempQueue.isEmpty()) {
        Letter letter = tempQueue.peek();
        file << letter.serializeToCSV() << endl;
        tempQueue.dequeue();
    }

    file.close();
}

void LetterService::loadLettersFromCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        Letter letter = Letter::fromCSV(line);
        storeLetterToMap(letter);
    }

    file.close();
}

void LetterService::saveLettersToCSV(const string& filename) {
    ofstream file(filename, ios::out | ios::trunc);
    if (!file.is_open()) return;

    map<string, Letter> tempMap = lettersHistoryMap;

    for (const auto& pair : tempMap) {
        const Letter& letter = pair.second;
        file << letter.serializeToCSV() << endl;
    }

    file.close();
}

void LetterService::loadLetterHistoryStrFromCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return;

    vector<string> lines;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }

    for (auto it = lines.rbegin(); it != lines.rend(); ++it) {
        lettersHistoryStr.push(*it);
    }

    file.close();
}

void LetterService::saveLetterHistoryStrToCsv(const string& filename) {
    ofstream file(filename, ios::out | ios::trunc);
    if (!file.is_open()) return;

    Stack<string> tempLetterHistoryStr = lettersHistoryStr;

    while (!tempLetterHistoryStr.isEmpty()) {
        file << tempLetterHistoryStr.top() << endl;
        tempLetterHistoryStr.pop();
    }

    file.close();
}

void LetterService::loadOutgoingLetterQueueFromCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        Letter letter = Letter::fromCSV(line);
        outgoingLettersQueue.enqueue(letter);
    }

    file.close();
}

void LetterService::saveOutgoingLetterQueueToCSV(const string& filename) {
    ofstream file(filename, ios::out | ios::trunc);
    if (!file.is_open()) return;

    Queue<Letter> tempQueue = outgoingLettersQueue;

    while (!tempQueue.isEmpty()) {
        Letter letter = tempQueue.peek();
        file << letter.serializeToCSV() << endl;
        tempQueue.dequeue();
    }

    file.close();
}

void LetterService::showAllLettersSortedByDate(string sorted) {
    vector<Letter> letters;
    for (const auto& [id, letter] : lettersHistoryMap) {
        letters.push_back(letter);
    }

    sort(letters.begin(), letters.end(),
         [sorted](const Letter& a, const Letter& b) {
             if (sorted == "ASCENDING") {
                 return a.getDate() < b.getDate();
             } else if (sorted == "DESCENDING") {
                 return a.getDate() > b.getDate();
             } else {
                 return a.getDate() < b.getDate();
             }
         });

    for (const auto& letter : letters) {
        cout << letter << endl;
    }
}

void LetterService::showAllLettersSortedByStatus() {
    vector<Letter> letters;
    for (const auto& [id, letter] : lettersHistoryMap) {
        letters.push_back(letter);
    }

    sort(letters.begin(), letters.end(), [](const Letter& a, const Letter& b) {
        return a.getStatus() < b.getStatus();
    });

    for (const auto& letter : letters) {
        cout << letter << endl;
    }
}

void LetterService::showAllLettersSortedByProcessedAt() {
    vector<Letter> letters;
    for (const auto& [id, letter] : lettersHistoryMap) {
        letters.push_back(letter);
    }

    sort(letters.begin(), letters.end(), [](const Letter& a, const Letter& b) {
        if (a.getProcessedAt().has_value() && b.getProcessedAt().has_value()) {
            return a.getProcessedAt().value() < b.getProcessedAt().value();
        }

        if (!a.getProcessedAt().has_value()) return false;
        if (!b.getProcessedAt().has_value()) return true;

        return false;
    });

    for (const auto& letter : letters) {
        cout << letter << endl;
    }
}

void LetterService::undoLastProcessedLetter() {
    if (lettersHistoryStr.isEmpty()) {
        cout << "Tidak ada riwayat surat yang bisa di-undo.\n";
        return;
    }

    string top = lettersHistoryStr.top();
    size_t pos = top.find(" | ");
    if (pos == string::npos) {
        cout << "Format riwayat tidak valid.\n";
        return;
    }

    string id = top.substr(0, pos);

    auto it = lettersHistoryMap.find(id);
    if (it == lettersHistoryMap.end()) {
        cout << "Surat tidak ditemukan dalam riwayat.\n";
        return;
    }

    Letter& letter = it->second;
    letter.changeStatus("PENDING");

    incomingLettersQueue.enqueueFront(letter);

    lettersHistoryStr.pop();
    lettersHistoryMap[letter.getId()] = letter;
    cout << "Surat dengan ID " << id
         << " telah di-undo, status menjadi PENDING, dan dikembalikan ke "
            "depan antrian.\n";
}
