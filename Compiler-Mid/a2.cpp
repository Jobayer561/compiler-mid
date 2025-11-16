// Construct a DFA that accepts binary strings containing an even number of 1s. (TC: 1110, 10101,  1100111. 
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int state = 0;
    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
        if(c != '0' && c != '1') {
            cout << "Invalid input";
            return 0;
        }

        if(c == '0') continue; 
        else if(c == '1') state = 1 - state;

    if(state == 0) cout << "Accepted";
    else cout << "Rejected";

    return 0;
}
