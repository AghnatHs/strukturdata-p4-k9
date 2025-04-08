#include "view.h"

#include "utils.h"

void View::showApplicationTitleText() {
    cout << "-------------------------------------------------------" << endl;
    cout << "----Aplikasi Pengelolaan Surat Masuk & Keluar Kantor---" << endl;
    cout << "-------------------------------------------------------" << endl;
}

// Bootstrapper
void View::showAndHandleMainMenu() {
    clearScreen();
    this->showApplicationTitleText();
    cout << "1. Login Guest" << endl;
    cout << "2. Login Pegawai" << endl;
    cout << "3. Exit" << endl;

    int choice;
    cout << "Pilih menu: ";
    cin >> choice;

    if (choice == 1) {
        this->showAndHandleGuest();
    } else if (choice == 2) {
        this->showAndHandleLoginPegawai();
    } else if (choice == 3) {
        cout << "\nExiting Program...\n";
        exit(0);
    } else {
        cout << "Input tidak valid" << endl;
        waitForContinueOrExit();
    }
}

void View::showAndHandleGuest() {
    clearScreen();
    this->showApplicationTitleText();
    cout << "-----------------" << endl;
    cout << "----- Guest -----" << endl;
    cout << "-----------------" << endl;
    cout << "1. Kirim Surat" << endl;
    cout << "2. < Back" << endl;

    int choice;
    cout << "Pilih Menu: ";
    cin >> choice;

    if (choice == 1) {
        this->showAndHandleKirimSurat();
        waitForContinueOrExit();
        this->showAndHandleGuest();
    } else if (choice == 2) {
        this->showAndHandleMainMenu();
    } else {
        cout << "Input tidak valid" << endl;
        waitForContinueOrExit();
        this->showAndHandleGuest();
    }
}

// TODO : implemented
void View::showAndHandleLoginPegawai() {
    clearScreen();
    cout << "NOT IMPLEMENTED YET" << endl;
    /* this->showApplicationTitleText();
    cout << "-----------------" << endl;
    cout << "- Login Pegawai -" << endl;
    cout << "-----------------" << endl;

    string username;
    string password;
    cout << "Username : ";
    cin >> username;
    cout << "Password : ";
    cin >> password; */
}

// TODO : implemented
void View::showAndHandleKirimSurat() {
    cout << "--- KIRIM SURAT" << endl;
    cout << "Contohnya aja udah dikirim" << endl;
    cout << "--- END" << endl;
}
