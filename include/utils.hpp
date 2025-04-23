#pragma once

#include <string>
using namespace std;

void clearScreen();
string generateRandomIdWithPrefix(int length, string prefix);
int generateRandomInteger(int min, int max);
string  getCurrentTimestampString();
void waitForContinue();
void waitForContinueOrExit();
