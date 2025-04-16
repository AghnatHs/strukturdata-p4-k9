#include "service/letter_service.hpp"

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