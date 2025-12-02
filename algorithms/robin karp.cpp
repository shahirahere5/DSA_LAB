#include <iostream>
#include <string>
using namespace std;

#define d 256   // ASCII base

void rabinKarp(string text, string pattern, int q) {

    int n = text.length();
    int m = pattern.length();

    int p = 0;   // hash of pattern
    int t = 0;   // hash of text window
    int h = 1;   // multiplier (d^(m-1))

    // Compute h = d^(m-1) % q
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Compute hash of pattern and first window
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide pattern over text
    for (int i = 0; i <= n - m; i++) {

        // Compare hash values
        if (p == t) {

            bool match = true;

            // Check characters one by one
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }

            if (match)
                cout << "Pattern found at index " << i << endl;
        }

        // Compute next window hash
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            if (t < 0)
                t += q;   // convert negative to positive
        }
    }
}

int main() {

    string text = "ABAAABCDBBABCDDEBCABC";
    string pattern = "ABC";

    int q = 101;   // prime number

    rabinKarp(text, pattern, q);

    return 0;
}
