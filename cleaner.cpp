#include <bits/stdc++.h>
using namespace std;


int main() {
    // Call in the data.

    ifstream data("old_words.txt");

    string curr;
    string firstWord;

    string result = "";

    while(getline(data, curr)) {
        firstWord = curr.substr(0, curr.find(','));
        result += firstWord + '\n';
    }

    ofstream output("words.txt");

    output << result;

    // Add every word to the list.
}