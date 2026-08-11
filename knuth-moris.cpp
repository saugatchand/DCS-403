#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Spam Word Filter in a Chat App
// Using the Knuth-Morris-Pratt (KMP) Algorithm

// Build the LPS (Longest Prefix Suffix) array
vector<int> buildLPS(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);

    int len = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// KMP Search Function
bool containsWord(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();

    if (m == 0)
        return false;

    vector<int> lps = buildLPS(pattern);

    int i = 0; // Index for text
    int j = 0; // Index for pattern

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;

            if (j == m) {
                return true; // Pattern found
            }
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return false;
}

int main() {
    vector<string> bannedWords = {
        "spamlink",
        "freegift",
        "clickhere"
    };

    string chatMessage = "hey guys check this out clickhere for a surprise!";

    bool isSpam = false;

    for (const string& word : bannedWords) {
        if (containsWord(chatMessage, word)) {
            cout << "Message blocked: contains banned word \"" << word << "\"" << endl;
            isSpam = true;
            break;
        }
    }

    if (!isSpam) {
        cout << "Message allowed: " << chatMessage << endl;
    }

    return 0;
}