// 3. Modify your lexical analyzer to remove comments (// and /* */) and return the cleaned code.
#include <iostream>
#include <cstring>
using namespace std;

int isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_');
}

int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

int isKeyword(const char token[]) {
    return strcmp(token,"int")==0 || strcmp(token,"float")==0 ||
           strcmp(token,"if")==0 || strcmp(token,"else")==0 ||
           strcmp(token,"for")==0 || strcmp(token,"while")==0 ||
           strcmp(token,"return")==0;
}

int main() {
    char line[2000];
    bool inBlockComment = false;
    int identifierCount = 0;

    cout << "Enter C/C++ code (press Enter on empty line to finish):" << endl;

    while (true) {
        cin.getline(line, 2000);
        if (strlen(line) == 0) break;

        int len = strlen(line);
        char cleaned[2000];
        int ci = 0;

        for (int i = 0; i < len;) {
            if (!inBlockComment && i+1 < len && line[i]=='/' && line[i+1]=='/') break;
            if (!inBlockComment && i+1 < len && line[i]=='/' && line[i+1]=='*') { inBlockComment = true; i+=2; continue; }
            if (inBlockComment) {
                if (i+1 < len && line[i]=='*' && line[i+1]=='/') { inBlockComment=false; i+=2; }
                else i++;
                continue;
            }
            cleaned[ci++] = line[i++];
        }
        cleaned[ci] = '\0';

        int i = 0;
        char token[500];
        while (cleaned[i] != '\0') {
            if (cleaned[i]==' ' || cleaned[i]=='\t') { i++; continue; } // skip only spaces and tabs
            if (isLetter(cleaned[i])) {
                int t = 0;
                while (isLetter(cleaned[i]) || isDigit(cleaned[i])) token[t++] = cleaned[i++];
                token[t] = '\0';
                if (!isKeyword(token)) {
                    identifierCount++;
                    cout << "Identifier found: " << token << endl;
                }
                continue;
            }
            i++;
        }
    }

    cout << "Total Identifiers: " << identifierCount << endl;
    return 0;
}

