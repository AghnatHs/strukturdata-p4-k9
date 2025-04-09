#pragma once

#include "domain/letter.hpp"
#include "domain/queue.hpp"

class LetterService {
   private:
    Queue<Letter> incomingLettersQueue;

   public:
    LetterService();
    Letter getIncomingLetter();
    void processIncomingLetter();

    void sendIncomingLetterToOffice(Letter letter);
    void showIncomingLettersQueue();
};