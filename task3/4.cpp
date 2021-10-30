#include <iostream>
#include <string>

using namespace std;

int main() {
    //a)
    string word1;
    string word2;
    string word3;

    cout << "Write 3 words" << endl;
    cin >> word1;
    cin >> word2;
    cin >> word3;

    //b)
    string sentence = word1 + " " + word2 + " " + word3 + ".";
    cout << sentence << endl;

    //c)
    cout << "Length of " << word1 << " is " << word1.length() << endl;
    cout << "Length of " << word2 << " is " << word2.length() << endl;
    cout << "Length of " << word3 << " is " << word3.length() << endl;
    cout << "Length of " << sentence << " is " << sentence.length() << endl;

    //d)
    string sentence2 = sentence;

    //e)
    if (sentence2.length() >= 12) {
        for (size_t i = 10; i <= 12; i++) {
            sentence2[i] = 'x';
        }
        cout << "Sentence 1 " << sentence << endl;
        cout << "Sentence 2 " << sentence2 << endl;
    } else {
        cout << "Word is shorter than 12 characters" << endl;
    }

    //f)
    if (sentence.length() >= 5) {
        string sentence_start = sentence.substr(0, 5);
        cout << "sentence_start: " << sentence_start << endl;
    } else {
        cout << "Word is shorter than 5 characters" << endl;
    }

    //g)
    if (sentence.find("hallo") != string::npos) {
        cout << "Sentence includes word 'hallo'" << endl;
    } else {
        cout << "Sentence does not include word 'hallo'" << endl;
    }

    //h
    int occurences = 0;
    for (size_t i = 0; i < sentence.length()-1; i++) {
        if (sentence[i] == 'e' && sentence[i+1] == 'r') {
            occurences++;
        }
    }
    cout << "the word 'er' is found " << occurences << " time(s) in the sentence";

}