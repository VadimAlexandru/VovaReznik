#include <iostream>
#include <fstream>
#include <regex>

using namespace std;
int main() {
    //read mask
    string mask;
    cout << "input mask: ";
    cin >> mask;
    if(mask.length()) {
       mask = regex_replace(mask, regex("@"), "[a-z]");
    } else {
        cout << "Input Error" << endl;
        return 1;
    }

    //filter words
    ifstream handler("/home/local/CLionProjects/VovaReznik/words.txt");
    string word;
    vector <string> words;
    int total_words = 0, filtered_words = 0;
    while (handler >> word) {
        total_words ++;
        if(regex_match(word, regex(mask))) {
            words.push_back(word);
        }
    }

    // output
    ofstream output("/home/local/CLionProjects/VovaReznik/output.txt");
    reverse(words.begin(), words.end());
    for(const auto &l : words) {
        cout << l << endl;
        output << l << endl;
    }

    // finish info
    cout << words.size() << " words written." << " Total words: " << total_words << endl;
    return 0;
}
