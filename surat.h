#ifndef SURAT_H
#define SURAT_H

#include <string>
using namespace std;

class Surat {
   private:
    string id;
    string date;
    string content;
    string status;

   public:
    Surat(string id, string date, string content, string status);
    void show();
};
#endif