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

    int key;

   public:
    Letter();
    Letter(string sender, string title, string content);
    Letter(string sender, string title, string content, int key);  // from csv
    friend ostream &operator<<(ostream &os, const Letter &letter);

    string getId() const;
    string getFormattedDate() const;
    void changeStatus(string newStatus);

    string serializeToCSV() const;
    static Letter fromCSV(const string &line);
};
