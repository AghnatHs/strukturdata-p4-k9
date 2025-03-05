#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include <vector>

#include "surat.h"
using namespace std;

class QueueSurat {
   private:
    vector<Surat> daftar_surat;

   public:
    void enqueue(Surat surat);

    void index();
};
#endif