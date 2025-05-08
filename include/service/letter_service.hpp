#pragma once

#include <map>

#include "domain/letter.hpp"
#include "domain/queue.hpp"
#include "domain/stack.hpp"

class LetterService {
   private:
    Queue<Letter> incomingLettersQueue;

    map<string, Letter> lettersHistoryMap; // contains all Letters, unprocessed, processed and so on
    Stack<string> lettersHistoryStr; // contains status changed of letter

   public:
    LetterService();
    Letter getIncomingLetter();
    void processIncomingLetter(string newStatus);

    void sendIncomingLetterToOffice(Letter letter);
    void showIncomingLettersQueue();
    void showIncomingLettersHistory();

    void storeLetterToMap(const Letter& letter);
    Letter* findLetterById(const string& id);

    void loadLetterQueueFromCSV(const string& filename);
    void saveLetterQueueToCSV(const string& filename);
    
    void loadLettersFromCSV(const string& filename);
    void saveLettersToCSV(const string& filename);

    void loadLetterHistoryStrFromCSV(const string& filename);
    void saveLetterHistoryStrToCsv(const string& filename);
};