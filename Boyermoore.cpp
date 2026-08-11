#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int CHAR_SIZE = 256;

// Build the Bad Character Table
void buildBadCharTable(const string &pattern, vector<int> &badChar)
{
    for (int i = 0; i < CHAR_SIZE; i++)
        badChar[i] = -1;

    for (int i = 0; i < pattern.length(); i++)
        badChar[(unsigned char)pattern[i]] = i;
}

void boyerMooreSearch(const string &text, const string &pattern)
{
    int n = text.length();
    int m = pattern.length();

    vector<int> badChar(CHAR_SIZE);
    buildBadCharTable(pattern, badChar);

    int shift = 0;

    while (shift <= (n - m))
    {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[shift + j])
            j--;

        if (j < 0)
        {
            cout << "Pattern found at index: "
                 << shift << endl;

            shift += (shift + m < n)
                         ? m - badChar[(unsigned char)text[shift + m]]
                         : 1;
        }
        else
        {
            shift += max(1, j - badChar[(unsigned char)text[shift + j]]);
        }
    }
}

int main()
{
    string text = "ABAAABCD";
    string pattern = "ABC";

    boyerMooreSearch(text, pattern);

    return 0;
}