#include "service/letter_service.hpp"

LetterService::LetterService() {};

Letter LetterService::getIncomingLetter() {
    return incomingLettersQueue.peek();
};

void LetterService::processIncomingLetter() { incomingLettersQueue.dequeue(); };

void LetterService::sendIncomingLetterToOffice(Letter letter) {
    incomingLettersQueue.enqueue(letter);
};
void LetterService::showIncomingLettersQueue() { incomingLettersQueue.print(); }