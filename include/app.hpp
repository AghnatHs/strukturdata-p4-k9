#pragma once

#include <unordered_map>

#include "service/letter_service.hpp"
using namespace std;
using Hash = size_t;

class App {
   private:
    LetterService letterService;

   public:
    static string QUEUE_CSV_FILEPATH;
    static string STATUS_HISTORY_CSV_FILEPATH;

    void run();
    void save(); 

    bool loginStaff(unordered_map<string, Hash> &staffs);

    void showApplicationTitleText();
    void showGuestTitleText();
    void showStaffTitleText();

    void showMainMenu();
    void showGuestMenu();
    void showStaffLoginMenu();

    void showGuestMenuSendLetter();
    void showGuestMenuFindLetter();

    void showStaffMenu();
};
