#include <string>
#include <algorithm>
#include <iostream>
#include <cctype>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 3) return 1; //error
    string cmd = argv[1];

    string sentence;
    for (int i = 2; i < argc; i++) {
        sentence += string(argv[i]);
        if (i < argc -1) {
            sentence += " ";  //word separator
        }
    }

    if (cmd == "up") { //uppercase
        for (char &c : sentence) {
            c = toupper(c);
        }
    }
    else if (cmd == "down") { //lowercase
        for (char &c : sentence) {
            c = tolower(c);
        }
    }
    else {
        cout << "Wrong command" << endl;
        
        return 1;
    }
    //print changed string
    cout << sentence << endl;
    
    return 0;
}