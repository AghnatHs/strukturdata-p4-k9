#include "utils.h"

void clearScreen() { cout << "\033[2J\033[1;1H"; }  // ANSI escape codes

void waitForContinueOrExit() {
    cout << "Tekan tombol apa saja untuk melanjutkan atau Q untuk keluar program... : ";
    string ch;
    cin >> ch;

    if (ch == "q" || ch == "Q") {
        cout << "\nExiting Program...\n";
        exit(0);
    }
}
