#include <iostream>
#include <string>
using namespace std;

// Trie

// Trie Node
struct TrieNode {
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
};

int main() {

    TrieNode* root = new TrieNode();

    // Insert Words
    string words[] = {"CAT", "CAR", "DOG"};

    for (string word : words) {

        TrieNode* current = root;

        for (char ch : word) {
            int index = ch - 'A';

            if (current->child[index] == nullptr) {
                current->child[index] = new TrieNode();
            }

            current = current->child[index];
        }

        current->isEnd = true;
    }

    // Search Word
    string searchWord = "CAT";
    TrieNode* current = root;

    bool found = true;

    for (char ch : searchWord) {
        int index = ch - 'A';

        if (current->child[index] == nullptr) {
            found = false;
            break;
        }

        current = current->child[index];
    }

    if (found && current->isEnd)
        cout << searchWord << " Found" << endl;
    else
        cout << searchWord << " Not Found" << endl;

    return 0;
}