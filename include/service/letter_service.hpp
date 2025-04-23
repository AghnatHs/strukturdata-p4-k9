#pragma once

#include "domain/letter.hpp"
#include "domain/queue.hpp"
#include "domain/stack.hpp"

class LetterService {
   private:
    Queue<Letter> incomingLettersQueue;

    Stack<Letter> lettersHistory;
    Stack<string> lettersHistoryStr;

   public:
    LetterService();
    Letter getIncomingLetter();
    void processIncomingLetter();

    void sendIncomingLetterToOffice(Letter letter);
    void showIncomingLettersQueue();
    void showIncomingLettersHistory();

    void loadLetterQueueFromCSV(const string& filename);
    void saveLetterQueueToCSV(const string& filename);
};