#pragma once

#include <ctime>
#include <optional>
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
    optional<time_t> processedAt;

    int key;

   public:
    Letter();
    Letter(string sender, string title, string content);
    Letter(string sender, string title, string content, int key);  // from csv
    friend ostream &operator<<(ostream &os, const Letter &letter);

    time_t getDate() const;
    string getId() const;
    string getFormattedDate() const;
    string getFormattedProcessedAt() const;
    void changeStatus(string newStatus);

    string serializeToCSV() const;
    static Letter fromCSV(const string &line);

    string getStatus() const;
    optional<time_t> getProcessedAt() const;
};
