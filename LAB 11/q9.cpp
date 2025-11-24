#include <iostream>
#include <string>
using namespace std;

int badCharTable[256];

void buildBadCharTable(const string &pattern) {
    for(int i = 0; i < 256; i++)
        badCharTable[i] = -1;
    for(int i = 0; i < pattern.size(); i++)
        badCharTable[(int)pattern[i]] = i;
}

int boyerMooreSearch(const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();
    if(m == 0) return 0;
    if(n < m) return -1;
    buildBadCharTable(pattern);
    int shift = 0;
    while(shift <= n - m) {
        int j = m - 1;
        while(j >= 0 && pattern[j] == text[shift + j])
            j--;
        if(j < 0)
            return shift;
        int skip = j - badCharTable[(int)text[shift + j]];
        if(skip < 1) skip = 1;
        shift += skip;
    }
    return -1;
}

int main() {
    string logText = "INFO: Server started\nERROR: Connection failed\nINFO: Retrying...";
    string pattern = "ERROR";
    int index = boyerMooreSearch(logText, pattern);
    if(index != -1)
        cout << "Pattern found at index: " << index << endl;
    else
        cout << "Pattern not found." << endl;
    return 0;
}
