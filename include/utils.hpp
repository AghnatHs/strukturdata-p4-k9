#pragma once

#include <string>
using namespace std;

void clearScreen();
string generateRandomIdWithPrefix(int length, string prefix);
string  getCurrentTimestampString();
void waitForContinueOrExit();
