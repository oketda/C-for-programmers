#include <iostream>
#include <vector>

using namespace std;

std::string escape(const string &input) {
    string output = "";
    vector<char> char_vector(input.begin(), input.end());

    for (const char &c: char_vector) {
        if (c == '<') {
            output += "&lt;";
        } else if (c == '>') {
            output += "&gt;";
        } else if (c == '&') {
            output += "&amp;";
        } else {
            output += c;
        }
    }
    return output;
}

void escape(string &input) {
    string test = input;
    
    for (size_t i = 0; i < input.size(); i++) {
        if (input[i] == '<') {
            input[i] = '&';
            input.insert(i+1, "lt;");
            i += 3;
        } else if (input[i] == '>') {
            input[i] = '&';
            input.insert(i+1, "gt;");
            i += 3;
        } else if (input[i] == '&') {
            input.insert(i+1, "amp;");
            i += 4;
        }
    }
    
}

main() {
    cout << escape("Escape these symbols: <<&>>") << endl;
    std::string text("Escape these symbols as well: >>&<<");
    escape(text);
    cout << text << endl;

}