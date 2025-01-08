//20210104158 C2
#include <iostream>
#include <string>

using namespace std;

int main() {
    string plaintext, keyword, ciphertext = "";
    
    // Input plaintext and keyword
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);  // Use getline to handle spaces
    cout << "Enter the keyword: ";
    cin >> keyword;

    int keyLength = keyword.length();
    int keyIndex = 0;

    for (int i = 0; i < plaintext.length(); i++) {
        char ch = plaintext[i];

        if (isalpha(ch)) { // Encrypt only alphabetic characters
            // Convert to lowercase for consistency
            char lowerCh = tolower(ch);
            char lowerKey = tolower(keyword[keyIndex % keyLength]);

            // Calculate the shift for encryption
            int plainIndex = lowerCh - 'a'; 
            int keyIndexShift = lowerKey - 'a';
            char encryptedChar = 'a' + (plainIndex + keyIndexShift) % 26;

            ciphertext += encryptedChar;
            keyIndex++; // Move to the next letter in the keyword
        } else {
            ciphertext += ch; // Leave non-alphabetic characters unchanged
        }
    }

    // Output the ciphertext
    cout << "Ciphertext: " << ciphertext << endl;

    return 0;
}
