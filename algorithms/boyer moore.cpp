#include <iostream>
#include <string>
using namespace std;

#define chars 256

void buildBadCharTable(string pattern, int badChar[]) {
    for (int i = 0; i < chars; i++){
        badChar[i] = -1;
    }
    for (int i = 0; i < pattern.size(); i++){
        badChar[(int)pattern[i]] = i;
    }
}

void boyerMooreSearch(string text, string pattern) {
    int m = pattern.size();
    int n = text.size();

    int badChar[chars];
    buildBadCharTable(pattern, badChar);

    int shift = 0;

    while (shift <= (n - m)) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[shift + j])
            j--;

        if (j < 0) {
            cout << "Pattern found at index " << shift << endl;
            shift += (shift + m < n) ? m - badChar[text[shift + m]] : 1;
        }
        else {
            shift += max(1, j - badChar[text[shift + j]]);
        }
    }
}

int main() {
    string text = "Findqueeninthismeizzqueenyouarequeenyayayay";
    string pattern = "queen";
    boyerMooreSearch(text, pattern);

    return 0;
}
