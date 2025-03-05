#include <iostream>

#include "queue.h"
#include "surat.h"
using namespace std;

int main() {
    QueueSurat queue;
    Surat surat("ID1", "2025-03-05", "ini isi 1", "UNREAD");
    Surat surat2("ID2", "2025-03-05", "ini isi 2", "UNREAD");
    queue.enqueue(surat);
    queue.enqueue(surat2);
    queue.index();
}