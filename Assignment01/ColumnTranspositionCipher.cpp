#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string message;
    cout << "Enter the message: ";
    getline(cin, message); 

    string key;
    cout << "Enter the key: ";
    cin >> key;

    message.erase(remove(message.begin(), message.end(), ' '), message.end());

    int rows = (message.size() + key.size() - 1) / key.size();
    int cols = key.size();

    vector< vector<char> > grid(rows, vector<char>(cols, ' '));
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (index < message.size()) {
                grid[i][j] = message[index++];
            }
        }
    }

    cout << "\nOriginal grid:\n";
    for (int i = 0; i < key.length(); i++) {
        cout << key[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    vector< pair<char, int> > keyIndex;
    for (int i = 0; i < cols; i++) {
        keyIndex.push_back(make_pair(key[i], i));
    }
    sort(keyIndex.begin(), keyIndex.end());

    vector< vector<char> > rearrangedGrid(rows, vector<char>(cols, ' '));
    for (int i = 0; i < cols; i++) {
        int originalCol = keyIndex[i].second;
        for (int j = 0; j < rows; j++) {
            rearrangedGrid[j][i] = grid[j][originalCol];
        }
    }

    cout << "\nRearranged grid:\n";
    sort(key.begin(), key.end());
    for (int i = 0; i < key.length(); i++) {
        cout << key[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << rearrangedGrid[i][j] << " ";
        }
        cout << endl;
    }

    string encryptedMessage;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            if (rearrangedGrid[j][i] != ' ') {
                encryptedMessage += rearrangedGrid[j][i];
            }
        }
    }

    cout << "\nEncrypted message: " << encryptedMessage << endl;

    return 0;
}