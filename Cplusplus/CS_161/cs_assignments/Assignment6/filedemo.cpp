// This demo demonstrates reading a file one char at a time.
// Written by: Colin Goble
// Sources: None
// Date: 3-Aug-2007

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main ()
{
    // Declarations
    string reply;
    string inputFileName;
    ifstream inputFile;
    char character;

    cout << "Input file name: ";
    getline(cin, inputFileName);

    // Open the input file.
    inputFile.open(inputFileName.c_str());      // Need .c_str() to convert a C++ string to a C-style string
    // Check the file opened successfully.
    if ( ! inputFile.is_open()) {
        cout << "Unable to open input file." << endl;
        cout << "Press enter to continue...";
        getline(cin, reply);
        exit(1);
    }

    // This section reads and echo's the file one character (byte) at a time.
    while (inputFile.peek() != EOF) {
        inputFile.get(character);
        cout << character;
    }
    cout << "\nEnd of file reached\n" << endl;

    // Close the input file stream
    inputFile.close();
    cout << "Press enter to continue...";
    getline(cin, reply);
    return 0;	
}

