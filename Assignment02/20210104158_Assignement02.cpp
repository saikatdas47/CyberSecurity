#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod; 
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}


long long modInverse(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;
    if (m == 1)
        return 0;

    while (a > 1) {
        
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
       
        x0 = x1 - q * x0;
        x1 = t;
    }

   
    if (x1 < 0)
        x1 += m0;

    return x1;
}

int main() {
  
    long long p = 17, q = 11; 
    long long n = p * q; 
    long long phi = (p - 1) * (q - 1); 
    long long e = 7; 
    long long d;

  
    d = modInverse(e, phi);

    cout << "Public Key: {" << e << ", " << n << "}\n";
    cout << "Private Key: {" << d << ", " << n << "}\n";

    
    long long message = 88; 
    cout << "Original Message: " << message << "\n";


    long long encryptedMessage = modExp(message, e, n);
    cout << "Encrypted Message: " << encryptedMessage << "\n";

   
    long long decryptedMessage = modExp(encryptedMessage, d, n);
    cout << "Decrypted Message: " << decryptedMessage << "\n";

    return 0;
}
