#pragma once
#include <string>
using namespace std;

namespace Crypto {
string encrypt(const string& text, int shift);
string decrypt(const string& text, int shift);
}