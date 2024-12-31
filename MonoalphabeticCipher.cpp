//20210104158 C2
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string message, key;

    // Input the message
    cout << "Enter the message: ";
    getline(cin, message);

    // Convert the message to uppercase
    transform(message.begin(), message.end(), message.begin(), ::toupper);

    // Input the key
    cout << "Enter the key: ";
    getline(cin, key);

    // Convert the key to uppercase
    transform(key.begin(), key.end(), key.begin(), ::toupper);

    // Generate the key to match the message length
    string extended_key = key;
    while (extended_key.length() < message.length()) {
        extended_key += key; // Repeat the key
    }
    extended_key = extended_key.substr(0, message.length()); // Ensure the key is exactly the same length as the message

    // Encrypt the message using the Vigenère cipher
    string cipher_text = "";
    for (int i = 0; i < message.length(); ++i) {
        char c = (message[i] - 'A' + extended_key[i] - 'A') % 26 + 'A'; // Encrypt each character
        cipher_text += c;
    }

    // Output the encrypted message (ciphertext)
    cout << "Encrypted Message: " << cipher_text << endl;

    return 0;
}