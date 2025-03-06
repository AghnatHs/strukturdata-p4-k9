#ifndef SURAT_H
#define SURAT_H

#include <string>
using namespace std;

class Surat {
   private:
    string id;
    string date;
    string content;
    string sender;
    string status;

   public:
    Surat(string id, string date, string content, string sender, string status);
    void show();
};
#endif