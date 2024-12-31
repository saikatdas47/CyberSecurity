//20210104158 C2 
#include <iostream>
#include <string>
using namespace std;
 
int main() {
    // Step 1: Get user input for the message and key
    string message;
    string key;

    cout << "Enter the message: ";
    getline(cin, message);  // Use getline to allow spaces in the message

    cout << "Enter the key: ";
    cin >> key;

    int cols = key.length(); // Number of columns is the length of the key
    int rows = (message.length() + cols - 1) / cols; // Calculate number of rows based on message length and key length

    // Step 2: Create a 2D array and fill it row-wise with the message
    char matrix[rows][cols];
    int index = 0;

    // Fill the matrix with message characters
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (index < message.length()) {
                matrix[i][j] = message[index];
                index++;
            } else {
                matrix[i][j] = ' '; // Fill empty spaces if message length is shorter than the matrix size
            }
        }
    }

    // Step 3: Print the initial matrix (before transformation)
    cout << "\nInitial Matrix (Row-wise):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Step 4: Convert key to integer indices for easier manipulation
    int key_int[cols];
    for (int i = 0; i < cols; i++) {
        key_int[i] = key[i] - '1';  // Convert '1', '2', '3', '4' to 0, 1, 2, 3
    }

    // Step 5: Create a transformed matrix based on the key
    char transformed_matrix[rows][cols];
    for (int j = 0; j < cols; j++) {
        int column_index = key_int[j];
        for (int i = 0; i < rows; i++) {
            transformed_matrix[i][j] = matrix[i][column_index];
        }
    }

    // Step 6: Print the transformed matrix
    cout << "\nTransformed Matrix (Columns reordered based on key):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << transformed_matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Step 7: Construct the encrypted message by reading row-wise from the transformed matrix
    string encrypted_message = "";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            encrypted_message += transformed_matrix[i][j];
        }
    }

    // Step 8: Output the final encrypted message
    cout << "\nEncrypted message: " << encrypted_message << endl;

    return 0;
}
