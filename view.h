#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
using namespace std;

class View {
   public:
    void showApplicationTitleText();

    void showAndHandleMainMenu();
    void showAndHandleGuest();
    void showAndHandleLoginPegawai();

    void showAndHandleKirimSurat();
};

#endif