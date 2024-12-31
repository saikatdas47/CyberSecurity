#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to calculate gcd
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute (a^b) % mod using exponentiation by squaring
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod; // In case base is greater than mod
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

// Function to compute modular inverse using Extended Euclidean Algorithm
long long modInverse(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;
    if (m == 1)
        return 0;

    while (a > 1) {
        // q is quotient
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        // Update x0 and x1
        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}

int main() {
    // RSA Key Setup
    long long p = 17, q = 11; // Two prime numbers
    long long n = p * q; // n = p * q
    long long phi = (p - 1) * (q - 1); // Euler's Totient Function
    long long e = 7; // Public exponent
    long long d; // Private exponent

    // Compute the private key (d) such that e * d ≡ 1 (mod phi)
    d = modInverse(e, phi);

    cout << "Public Key: {" << e << ", " << n << "}\n";
    cout << "Private Key: {" << d << ", " << n << "}\n";

    // Encryption/Decryption Example
    long long message = 88; // Message to be encrypted (must be less than n)
    cout << "Original Message: " << message << "\n";

    // Encrypt the message
    long long encryptedMessage = modExp(message, e, n);
    cout << "Encrypted Message: " << encryptedMessage << "\n";

    // Decrypt the message
    long long decryptedMessage = modExp(encryptedMessage, d, n);
    cout << "Decrypted Message: " << decryptedMessage << "\n";

    return 0;
}
