#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void search(string txt, string pat) {
    int m = pat.size(), n = txt.size();
    vector<int> badchar(256, -1);

    // Fill the bad character array
    for (int i = 0; i < m; i++) 
        badchar[(int)pat[i]] = i;

    int s = 0; // s is the shift of the pattern with respect to text
    while (s <= (n - m)) {
        int j = m - 1;

        // Keep reducing j while characters match
        while (j >= 0 && pat[j] == txt[s + j]) j--;

        if (j < 0) {
            cout << "Pattern found at index " << s << endl;
            // Shift pattern so that the next character in text aligns with its last occurrence
            s += (s + m < n) ? m - badchar[(unsigned char)txt[s + m]] : 1;
        } else {
            // Shift the pattern so the bad character in text aligns with its last occurrence in pattern
            s += max(1, j - badchar[(unsigned char)txt[s + j]]);
        }
    }
}

int main() {
    string txt, pat;
    cout << "Text: "; getline(cin, txt);
    cout << "Pattern: "; getline(cin, pat);
    search(txt, pat);
    return 0;
}