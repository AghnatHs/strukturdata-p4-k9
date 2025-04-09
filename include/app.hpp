#pragma once

#include "service/letter_service.hpp"

class App {
   private:
    LetterService letterService;

   public:
    void showApplicationTitleText();
    void showGuestTitleText();\
    void showStaffTitleText();

    void showMainMenu();
    void showGuestMenu();
    void showStaffLoginMenu();

    void showGuestMenuSendLetter();

    void showStaffMenu();
};
