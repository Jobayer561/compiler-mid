// Implement a Lexical Analyzer: 
// 1. Write a lexical analyzer that identifies the following tokens from input text: 
// ∙ Keywords: int, float, if, else 
// ∙ Identifiers 
// ∙ Numbers 
// ∙ Operators: + - * / = 
// Test on: 
// int x = y + 45; 
#include <iostream>
#include <cstring>
using namespace std;

int isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

int main() {
    char line[1000];
    cin.getline(line, 1000); 
    int i = 0;
    char token[100];
    int t;

    while (line[i] != '\0') {
        if (line[i] == ' ' || line[i] == '\t') {
            i++;
            continue; 
        }

        if (isLetter(line[i])) {
            t = 0;
            while (isLetter(line[i]) || isDigit(line[i])) {
                token[t++] = line[i++];
            }
            token[t] = '\0';

            if (strcmp(token,"int")==0 || strcmp(token,"float")==0 ||
                strcmp(token,"if")==0 || strcmp(token,"else")==0)
                cout << token << " : Keyword" << endl;
            else
                cout << token << " : Identifier" << endl;

            continue;
        }

        if (isDigit(line[i])) {
            t = 0;
            while (isDigit(line[i])) {
                token[t++] = line[i++];
            }
            token[t] = '\0';
            cout << token << " : Number" << endl;
            continue;
        }

        if (line[i]=='+' || line[i]=='-' || line[i]=='*' ||
            line[i]=='/' || line[i]=='=') {
            cout << line[i] << " : Operator" << endl;
            i++;
            continue;
        }

        if (line[i] == ';') {
            cout << line[i] << " : Semicolon" << endl;
            i++;
            continue;
        }

        i++;
    }

    return 0;
}

