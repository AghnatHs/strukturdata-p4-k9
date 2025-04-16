#include "crypto.hpp"

namespace Crypto {
string encrypt(const string& text, int shift) {
    string result = text;

    for (char& c : result) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + shift) % 26 + base;
        }
    }
    return result;
}
string decrypt(const string& text, int shift) {
    std::string result = text;

    for (char& c : result) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base - shift + 26) % 26 + base;
        }
    }
    return result;
}
}  // namespace Crypto