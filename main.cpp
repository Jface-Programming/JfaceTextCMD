#include <iostream>
#include <fstream>
using namespace std;

int main() {
    bool loop = true;
    while (loop == true) {
        string operation;
        cout << "do you want to create a new file[N|Y]" << endl;
        cin >> operation;
        cout << endl;
        if (operation == "y") {
            string fileName;
            cout << "please enter a directory and file name" << endl;
            cin >> fileName;
            ofstream mainFile(fileName);
            string currentLineData;
            bool writeLine = true;
            while (writeLine == true) {
                getline(cin, currentLineData);
                if (currentLineData == "exit") {
                    writeLine = false;
                    mainFile.close();
                } else {
                    mainFile << currentLineData << endl;;
                    cout << endl;
                }
            }
        } else if (operation == "n") {
            string inputFileName;
            cin >> inputFileName;
            cout << endl;
            ifstream mainFile(inputFileName);
            while (!mainFile.eof()) {
                string currentLineData;
                getline(mainFile, currentLineData);
                cout << currentLineData << endl;
            }
        } else if (operation == "exit") {
            return 0;
        }
    }
    return 0;
}
