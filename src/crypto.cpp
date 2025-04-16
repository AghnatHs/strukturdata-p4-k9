#include "crypto.hpp"

namespace Crypto {
string XORChiper(const string& text, char key) {
    string result = text;
    
    for (char& ch : result) {
        ch ^= key;
    }

    return result;
}
}  // namespace Crypto