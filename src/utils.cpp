#include "utils.hpp"

#include <cctype>
#include <iostream>
#include <random>
#include <string>

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

string generateRandomIdWithPrefix(int length, string prefix) {
    const string chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, chars.size() - 1);

    string id = "";
    for (int i = 0; i < length; ++i) {
        id += chars[distrib(gen)];
    }

    return prefix + "-" + id;
}

void waitForContinueOrExit() {
    cout << "/////////////////////////////////////////////////////////////"
         << endl;
    cout << "Ketik huruf apa saja untuk melanjutkan atau Q untuk keluar "
            "program... : ";
    string ch;
    cin >> ch;

    if (ch == "q" || ch == "Q") {
        cout << "\nExiting Program...\n";
        exit(0);
    }
}