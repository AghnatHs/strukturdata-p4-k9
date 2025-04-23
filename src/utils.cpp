#include "utils.hpp"

#include <cctype>
#include <chrono>
#include <ctime>
#include <iostream>
#include <random>
#include <sstream>
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

int generateRandomInteger(int min, int max) {
    static std::mt19937 rng(
        static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

string getCurrentTimestampString() {
    using namespace std::chrono;
    auto now = system_clock::now();
    time_t now_c = system_clock::to_time_t(now);
    char buffer[100];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&now_c));
    return string(buffer);
}

void waitForContinue() {
    cout << "Ketik huruf apa saja untuk melanjutkan : ";
    string ch;
    cin >> ch;
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