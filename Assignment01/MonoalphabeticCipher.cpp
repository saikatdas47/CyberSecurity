#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string message, key;

    cout << "Enter the message: ";
    getline(cin, message);

  // transform(message.begin(), message.end(), message.begin(), ::toupper);

    cout << "Enter the key: ";
    getline(cin, key);

    //transform(key.begin(), key.end(), key.begin(), ::toupper);

    string extended_key = key;
    while (extended_key.length() < message.length()) {
        extended_key += key;
    }
    extended_key = extended_key.substr(0, message.length());

    string cipher_text = "";
    for (int i = 0; i < message.length(); ++i) {
        char c = (message[i] - 'A' + extended_key[i] - 'A') % 26 + 'A';
        cipher_text += c;
    }

    cout << "Encrypted Message: " << cipher_text << endl;

    return 0;
}