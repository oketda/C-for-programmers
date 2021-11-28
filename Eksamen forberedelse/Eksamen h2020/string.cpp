#include <iostream>
#include <vector>

using namespace std;

std::string spaces_to_underscore1(std::string input) {
    string output = "";
    vector<char> char_vector(input.begin(), input.end());

    for (const char &c : char_vector) {
        if (c == ' ') {
            output += "_";
        } else {
            output += c;
        }
    }

    return output;
}

void spaces_to_underscore2(std::string &input) {

    for (size_t i = 0; i < input.size(); i++) {
        if (input[i] == ' ') {
            input[i] = '_';
        }
    }
}

std::string spaces_to_underscore_or_character(std::string input, char *chr = nullptr) {
    string output = "";
    vector<char> char_vector(input.begin(), input.end());

    for (const char &c : char_vector) {
        if (c == ' ') {
            if (chr == nullptr) {
                output += "_";
            } else {
                output += *chr;
            }
        } else {
            output += c;
        }
    }

    return output;
}

main() {
    cout << spaces_to_underscore1("this is a string") << endl;
    string str("this is a string");
    spaces_to_underscore2(str);
    cout << str << endl;
    char chr('+');
    cout << spaces_to_underscore_or_character("this is a string", &chr) << endl;
    cout << spaces_to_underscore_or_character("this is a string", nullptr) << endl;
    cout << spaces_to_underscore_or_character("this is a string") << endl;
}