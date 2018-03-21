#include <iostream>
#include <string>

using namespace std;

string Encode(string &str);

int main()
{
    string str;
    cout << "Input:\n";
    getline(cin, str);
    cout << Encode(str);
    return 0;
}

string Encode(string &str)
{
    // Variable for counting how many times does the first letter of the text appear.
    int counter = 0;
    // Get the key for the encoding.
    for (string::iterator it = str.begin(); it != str.end(); ++it)
    {
        // Check if it's the first letter
        // or if the first letter is lowercase check for the uppercase too
        // or if the first letter is uppercase check for the lowercase too.
        if (*it == *str.begin() || *it == *str.begin() - 32 || *it == *str.begin() + 32)
            ++counter;
    }
    // Encode every letter and only the letters.
    for (string::iterator it = str.begin(); it != str.end(); ++it)
    {
        if (*it > 96 && *it < 122)          // If it's lowercase and not z
            *it = *it + counter;            // encode it.
        else if (*it > 64 && *it < 90)      // If it's uppercase and not Z
            *it = *it + 32 + counter;       // make it lowercase and encode it.
        else if (*it == 122 || *it == 90)   // If it's z or Z
            *it = 96 + counter;             // set the iterator right before 'a' and encode it.
    }
    return str;
}
