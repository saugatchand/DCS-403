#include <iostream>
#include <string>
using namespace std;

int main() {
    // 1. Create
    string s = "Hello";
    cout << "1. Create        -> s = \"" << s << "\"" << endl;

    // 2. Input
    // string s;
    // getline(cin, s);   // reads a full line (including spaces) from user
    cout << "2. Input         -> getline(cin, s);  (reads a line from user, skipped here for demo)" << endl;

    // 3. Output
    cout << "3. Output        -> cout << s;  => " << s << endl;

    // 4. Access
    cout << "4. Access        -> s[0] = '" << s[0] << "', s.at(0) = '" << s.at(0) << "'" << endl;

    // 5. Update
    s[0] = 'A';
    cout << "5. Update        -> after s[0]='A', s = \"" << s << "\"" << endl;

    // 6. Length / Size
    cout << "6. Length/Size   -> s.length() = " << s.length() << ", s.size() = " << s.size() << endl;

    // 7. Empty
    cout << "7. Empty         -> s.empty() = " << (s.empty() ? "true" : "false") << endl;

    // 8. Append
    s.append(" World");
    cout << "8. Append        -> after s.append(\" World\"), s = \"" << s << "\"" << endl;

    // 9. Concatenate
    string s1 = "Foo";
    string s2 = "Bar";
    string s3 = s1 + s2;
    cout << "9. Concatenate   -> s1 + s2 = \"" << s3 << "\"" << endl;

    // 10. Insert
    s.insert(5, "ABC");
    cout << "10. Insert       -> after s.insert(5, \"ABC\"), s = \"" << s << "\"" << endl;


    // 11. Erase
    string a = "Hello World";
    cout << "11. Erase        -> before: \"" << a << "\"" << endl;
    a.erase(5, 6); // erase(pos, count)
    cout << "                    after a.erase(5,6): \"" << a << "\"" << endl;

    // 12. Replace
    string b = "Hello World";
    b.replace(0, 5, "Hi");   // replace(pos, len, newStr)
    cout << "12. Replace      -> b.replace(0,5,\"Hi\") -> \"" << b << "\"" << endl;

    // 13. Find
    string c = "I love cats";
    size_t pos = c.find("cats");
    cout << "13. Find         -> c.find(\"cats\") -> index " << pos << endl;

    // 14. Compare
    string x1 = "apple", x2 = "banana";
    int cmp = x1.compare(x2);
    cout << "14. Compare      -> x1.compare(x2) -> " << cmp
         << (cmp < 0 ? " (x1 < x2)" : cmp > 0 ? " (x1 > x2)" : " (equal)") << endl;

    // 15. Substring
    string d = "Programming";
    string sub = d.substr(3, 4); // substr(pos, len)
    cout << "15. Substring    -> d.substr(3,4) -> \"" << sub << "\"" << endl;

    // 16. Reverse
    string e = "Hello";
    reverse(e.begin(), e.end());
    cout << "16. Reverse      -> reverse(e) -> \"" << e << "\"" << endl;

    // 17. Sort
    string f = "dcba";
    sort(f.begin(), f.end());
    cout << "17. Sort         -> sort(f) -> \"" << f << "\"" << endl;

    // 18. Traverse
    string g = "abc";
    cout << "18. Traverse     -> for(char c : g) -> ";
    for (char ch : g) cout << ch << " ";
    cout << endl;

    // 19. Clear
    string h = "Some text";
    h.clear();
    cout << "19. Clear        -> h.clear() -> \"" << h << "\" (empty: "
         << (h.empty() ? "true" : "false") << ")" << endl;

    // 20. Swap
    string s1swap = "First", s2swap = "Second";
    cout << "20. Swap         -> before: s1=\"" << s1swap << "\", s2=\"" << s2swap << "\"" << endl;
    s1swap.swap(s2swap);
    cout << "                    after s1.swap(s2): s1=\"" << s1swap << "\", s2=\"" << s2swap << "\"" << endl;

    return 0;
}