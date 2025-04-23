#include "app.hpp"

#include <iostream>

#include "domain/letter.hpp"
#include "utils.hpp"

using namespace std;

unordered_map<string, Hash> staffs = {{"admin", hash<string>{}("admin123")}};

string App::QUEUE_CSV_FILEPATH = "./letters.csv";
string App::STATUS_HISTORY_CSV_FILEPATH = "./letterStatusHistory.csv";

void App::run() { letterService.loadLetterQueueFromCSV(QUEUE_CSV_FILEPATH); }

void App::save() { letterService.saveLetterQueueToCSV(QUEUE_CSV_FILEPATH); }

bool App::loginStaff(std::unordered_map<std::string, Hash>& staffs) {
    string idPegawai;
    string password;

    cin.ignore();
    cout << "ID Pegawai : ";
    getline(cin, idPegawai);
    cout << "Password   : ";
    getline(cin, password);

    auto it = staffs.find(idPegawai);
    if (it != staffs.end() && it->second == hash<string>{}(password)) {
        cout << "Login successful!" << endl;
        return true;
    }

    cout << "Login failed! wrong ID or Password" << endl;
    return false;
}

void App::showApplicationTitleText() {
    cout << "-------------------------------------------------------" << endl;
    cout << "----Aplikasi Pengelolaan Surat Masuk & Keluar Kantor---" << endl;
    cout << "-------------------------------------------------------" << endl;
}

void App::showGuestTitleText() {
    showApplicationTitleText();
    cout << "-----------------" << endl;
    cout << "----- Guest -----" << endl;
    cout << "-----------------" << endl;
}

void App::showStaffTitleText() {
    showApplicationTitleText();
    cout << "-----------------" << endl;
    cout << "----- Staff -----" << endl;
    cout << "-----------------" << endl;
}

void App::showMainMenu() {
    clearScreen();
    showApplicationTitleText();
    cout << "1. Login Guest" << endl;
    cout << "2. Login Pegawai" << endl;
    cout << "3. Exit" << endl;

    int choice;
    cout << "Pilih menu : ";
    cin >> choice;

    if (choice == 1) {
        showGuestMenu();
    } else if (choice == 2) {
        showStaffLoginMenu();
    } else if (choice == 3) {
        cout << "\nExiting Program...\n";
        exit(0);
    } else {
        cout << "Input tidak valid" << endl;
        waitForContinueOrExit();
    }
}

void App::showGuestMenu() {
    clearScreen();
    showGuestTitleText();
    cout << "1. Kirim Surat ke Kantor" << endl;
    cout << "2. < Back" << endl;

    int choice;
    cout << "Pilih Menu : ";
    cin >> choice;

    if (choice == 1) {
        showGuestMenuSendLetter();
        waitForContinueOrExit();
        showGuestMenu();
    } else if (choice == 2) {
        showMainMenu();
    } else {
        cout << "Input tidak valid" << endl;
        waitForContinueOrExit();
        showGuestMenu();
    }
}

void App::showStaffLoginMenu() {
    clearScreen();
    showApplicationTitleText();
    cout << "-----------------" << endl;
    cout << "-- Staff Login --" << endl;
    cout << "-----------------" << endl;
    cout << "1. Login" << endl;
    cout << "2. < Back" << endl;

    int choice;
    cout << "Pilih Menu : ";
    cin >> choice;

    if (choice == 1) {
        if (loginStaff(staffs)) {
            waitForContinue();
            showStaffMenu();
        } else {
            waitForContinue();
            showStaffLoginMenu();
        }
    } else if (choice == 2) {
        showMainMenu();
    } else {
        cout << "Input tidak valid" << endl;
        waitForContinueOrExit();
        showGuestMenu();
    }

    showStaffMenu();
}

void App::showGuestMenuSendLetter() {
    clearScreen();
    showGuestTitleText();
    cout << "-----------------" << endl;
    cout << "-- Kirim Surat --" << endl;
    cout << "-----------------" << endl;

    string sender;
    string title;
    string content;

    cin.ignore();
    cout << "Pengirim    : ";
    getline(cin, sender);
    cout << "Judul Surat : ";
    getline(cin, title);
    cout << "Isi Surat   : ";
    getline(cin, content);

    Letter letter(sender, title, content);

    letterService.sendIncomingLetterToOffice(letter);

    cout << ">>>>>" << endl;
    cout << letter;
    cout << ">>>>>" << endl;
    cout << "-> Surat anda telah terkirim ke kantor kami!" << endl;
    cout << "-----------------------------------------" << endl;
    save();
}

void App::showStaffMenu() {
    clearScreen();
    showStaffTitleText();
    cout << "1. Lihat antrian surat masuk" << endl;
    cout << "2. Proses antrian surat masuk" << endl;
    cout << "3. Lihat history perubahan surat masuk" << endl;
    cout << "6. < Logout" << endl;

    int choice;
    cout << "Pilih Menu : ";
    cin >> choice;

    if (choice == 1) {
        try {
            letterService.showIncomingLettersQueue();
        } catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
        waitForContinueOrExit();
        showStaffMenu();
    } else if (choice == 2) {
        try {
            cout << "Mengambil surat dari antrian..." << endl;
            Letter letter = letterService.getIncomingLetter();

            char p;
            cout << letter << endl;
            cout << "Proses surat ini? (Y/N) : ";
            cin >> p;

            if (p == 'Y') {
                cout << "Surat " << letter.getId() << " Diproses..." << endl;
                cout << "Status diubah menjadi SELESAI..." << endl;
                cout << "Surat " << letter.getId()
                     << " Dikeluarkan dari antrian..." << endl;
                letterService.processIncomingLetter();
                save();
            } else if (p == 'N') {
                showStaffMenu();
            }

        } catch (const runtime_error& e) {
            cout << "Belum ada antrian surat masuk yang perlu diproses :)"
                 << endl;
        }
        waitForContinueOrExit();
        showStaffMenu();
    } else if (choice == 3) {
        try {
            cout << "Mengambil history perubahan status surat.." << endl;
            letterService.showIncomingLettersHistory();
        } catch (const runtime_error& e) {
            cout << "Belum ada surat masuk yang diproses :)" << endl;
        }
        waitForContinueOrExit();
        showStaffMenu();
    } else if (choice == 6) {
        showMainMenu();
    } else {
        cout << "Input tidak valid" << endl;
        waitForContinueOrExit();
        showStaffMenu();
    }
}
