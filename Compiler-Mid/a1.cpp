// 1. Design a DFA that accepts all binary strings that end with 01. (Test case: 101,1101,100, 001)

#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cin >> input;

    int state = 0;

    for(int i = 0; i < input.length(); i++) {
        char c = input[i];
        if(c != '0' && c != '1') {
            cout << "Invalid";
            return 0;
        }

        if(state == 0) {
            if(c == '0') state = 1;
            else state = 0;
        }
        else if(state == 1) {
            if(c == '0') state = 1;
            else state = 2;
        }
        else if(state == 2) {
            if(c == '0') state = 1;
            else state = 0;
        }
    }

    if(state == 2) cout << "Accepted";
    else cout << "Rejected";

    return 0;
}
