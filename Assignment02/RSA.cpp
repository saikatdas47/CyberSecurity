#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to calculate gcd (Greatest Common Divisor) using the Euclidean algorithm
long long gcd(long long a, long long b) {
    while (b != 0) { // Continue until b becomes 0
        long long temp = b; // Store b temporarily
        b = a % b; // Update b as the remainder of a divided by b
        a = temp; // Update a with the previous value of b
    }
    return a; // Return the greatest common divisor
}

// Function to compute (a^b) % mod using the efficient method of exponentiation by squaring
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1; // Initialize the result
    base = base % mod; // Reduce the base modulo mod to simplify calculations
    while (exp > 0) { // Loop until the exponent becomes 0
        if (exp % 2 == 1) { // If the exponent is odd
            result = (result * base) % mod; // Multiply the base with the result modulo mod
        }
        base = (base * base) % mod; // Square the base and take modulo mod
        exp = exp / 2; // Halve the exponent
    }
    return result; // Return the result
}

// Function to compute modular inverse using the Extended Euclidean Algorithm
long long modInverse(long long a, long long m) {
    long long m0 = m, t, q; // Store the original value of m
    long long x0 = 0, x1 = 1; // Initialize coefficients for the Extended Euclidean Algorithm
    if (m == 1) // If mod is 1, the modular inverse does not exist
        return 0;

    while (a > 1) { // Continue until a becomes 1
        q = a / m; // Calculate the quotient
        t = m; 
        m = a % m; // Update m to the remainder of a divided by m
        a = t; // Update a to the previous value of m
        t = x0; 
        x0 = x1 - q * x0; // Update x0
        x1 = t; // Update x1
    }

    if (x1 < 0) // Ensure x1 is positive
        x1 += m0;

    return x1; // Return the modular inverse
}

int main() {
    long long p = 17, q = 11; // Two prime numbers selected for RSA
    long long n = p * q; // Compute n = p * q
    long long phi = (p - 1) * (q - 1); // Compute Euler's Totient Function φ(n) = (p-1)(q-1)
    long long e = 7; // Choose a public exponent e such that 1 < e < φ(n) and gcd(e, φ(n)) = 1
    long long d; // Declare the private key (d)

    d = modInverse(e, phi); // Compute the private key d such that (e * d) ≡ 1 (mod φ(n))

    // Display the public and private keys
    cout << "Public Key: {" << e << ", " << n << "}\n";
    cout << "Private Key: {" << d << ", " << n << "}\n";

    long long message = 88; // Define a message to encrypt (must be less than n)
    cout << "Original Message: " << message << "\n";

    // Encrypt the message using the formula: c = (message^e) % n
    long long encryptedMessage = modExp(message, e, n);
    cout << "Encrypted Message: " << encryptedMessage << "\n";

    // Decrypt the message using the formula: m = (c^d) % n
    long long decryptedMessage = modExp(encryptedMessage, d, n);
    cout << "Decrypted Message: " << decryptedMessage << "\n";

    return 0;
}