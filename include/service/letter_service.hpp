#pragma once

#include "domain/letter.hpp"
#include "domain/queue.hpp"

class LetterService {
   private:
    Queue<Letter> incomingLettersQueue;

   public:
    void sendIncomingLetterToOffice(Letter letter);
    void showIncomingLettersQueue(); 
};