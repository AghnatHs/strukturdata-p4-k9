#include "app.hpp"

#include <iostream>

#include "domain/letter.hpp"
#include "utils.hpp"

using namespace std;

void App::showApplicationTitleText() {
    cout << "-------------------------------------------------------" << endl;
    cout << "----Aplikasi Pengelolaan Surat Masuk & Keluar Kantor---" << endl;
    cout << "-------------------------------------------------------" << endl;
}

void App::showGuestTitleText() {
    this->showApplicationTitleText();
    cout << "-----------------" << endl;
    cout << "----- Guest -----" << endl;
    cout << "-----------------" << endl;
}

void App::showStaffTitleText() {
    this->showApplicationTitleText();
    cout << "-----------------" << endl;
    cout << "----- Staff -----" << endl;
    cout << "-----------------" << endl;
}

void App::showMainMenu() {
    clearScreen();
    this->showApplicationTitleText();
    cout << "1. Login Guest" << endl;
    cout << "2. Login Pegawai" << endl;
    cout << "3. Exit" << endl;

    int choice;
    cout << "Pilih menu: ";
    cin >> choice;

    if (choice == 1) {
        this->showGuestMenu();
    } else if (choice == 2) {
        this->showStaffLoginMenu();
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
    this->showGuestTitleText();
    cout << "1. Kirim Surat ke Kantor" << endl;
    cout << "2. < Back" << endl;

    int choice;
    cout << "Pilih Menu: ";
    cin >> choice;

    if (choice == 1) {
        this->showGuestMenuSendLetter();
        waitForContinueOrExit();
        this->showGuestMenu();
    } else if (choice == 2) {
        this->showMainMenu();
    } else {
        cout << "Input tidak valid" << endl;
        waitForContinueOrExit();
        this->showGuestMenu();
    }
}

void App::showStaffLoginMenu() {
    clearScreen();
    this->showApplicationTitleText();
    cout << "-----------------" << endl;
    cout << "-- Staff Login --" << endl;
    cout << "-----------------" << endl;

    string idPegawai;
    string password;

    cin.ignore();
    cout << "ID Pegawai : ";
    getline(cin, idPegawai);
    cout << "Password : ";
    getline(cin, password);

    this->showStaffMenu();
}

void App::showGuestMenuSendLetter() {
    clearScreen();
    this->showGuestTitleText();
    cout << "-----------------" << endl;
    cout << "-- Kirim Surat --" << endl;
    cout << "-----------------" << endl;

    string sender;
    string title;
    string content;

    cin.ignore();
    cout << "Pengirim : ";
    getline(cin, sender);
    cout << "Judul Surat : ";
    getline(cin, title);
    cout << "Isi Surat : ";
    getline(cin, content);

    Letter letter(sender, title, content);

    letterService.sendIncomingLetterToOffice(letter);

    cout << ">>>>>" << endl;
    cout << letter;
    cout << ">>>>>" << endl;
    cout << "-> Surat anda telah terkirim ke kantor kami!" << endl;
    cout << "-----------------------------------------" << endl;
}

void App::showStaffMenu() {
    clearScreen();
    this->showStaffTitleText();
    cout << "1. Lihat daftar surat masuk" << endl;
    cout << "6. < Back" << endl;

    int choice;
    cout << "Pilih Menu: ";
    cin >> choice;

    if (choice == 1) {
        try {
            this->letterService.showIncomingLettersQueue();
        } catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
        waitForContinueOrExit();
        this->showStaffMenu();
    } else if (choice == 6) {
        this->showMainMenu();
    } else {
        cout << "Input tidak valid" << endl;
        waitForContinueOrExit();
        this->showStaffMenu();
    }
}
