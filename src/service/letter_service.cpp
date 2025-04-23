#include "service/letter_service.hpp"

#include <fstream>

#include "utils.hpp"

LetterService::LetterService() {};

Letter LetterService::getIncomingLetter() {
    return incomingLettersQueue.peek();
};

void LetterService::processIncomingLetter() {
    Letter letter = incomingLettersQueue.peek();

    letter.changeStatus("SELESAI");
    lettersHistoryStr.push(letter.getId() + " | " + "PENDING" + " --> " +
                           "SELESAI | " + getCurrentTimestampString());

    lettersHistory.push(letter);

    incomingLettersQueue.dequeue();
};

void LetterService::sendIncomingLetterToOffice(Letter letter) {
    incomingLettersQueue.enqueue(letter);
};
void LetterService::showIncomingLettersQueue() { incomingLettersQueue.print(); }
void LetterService::showIncomingLettersHistory() { lettersHistoryStr.print(); }

void LetterService::loadLettersFromCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        Letter letter = Letter::fromCSV(line);
        incomingLettersQueue.enqueue(letter);
    }

    file.close();
}

void LetterService::saveLettersToCSV(const string& filename) {
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