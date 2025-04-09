#pragma once

#include <ctime>
#include <string>
using namespace std;

class Letter {
   private:
    string id;
    time_t date;
    string title;
    string content;
    string sender;
    string status;

   public:
    Letter(string sender, string title, string content);
    friend ostream &operator<<(ostream &os, const Letter &letter);
};
