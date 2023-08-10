#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {

    // Arguments check
    if (argc < 3)
    {
        cout << "Usage: " << argv[0] << " filename word1 word2 word3 ..." << endl;
        return 1;
    }
    string fileName = argv[1];
    vector<string> wordsToDelete;

    // Filling vector with words from argument
    for (int i = 2; i < argc; ++i)
    {
        wordsToDelete.push_back(argv[i]);
    }

    // Opening file
    ifstream file(fileName);
    if (!file.is_open())
    {
        cout << "Error opening file " << fileName << endl;
        return 1;
    }

    vector<string> lines;
    string line;

    // Remove lines
    while (getline(file, line))
    {
        for (const string& word : wordsToDelete)
        {
            size_t pos = line.find(word);
            while (pos != string::npos)
            {
                line.erase(pos, word.length());
                pos = line.find(word, pos);
            }
        }
        lines.push_back(line); // Store the modified line
    }

    // Close file
    file.close();

    // Saving file
    ofstream outfile(fileName);
    if (!outfile.is_open()) {
        cout << "Error opening file " << fileName << " for writing" << endl;
        return 1;
    }

    for (const string& line : lines) {
        outfile << line << endl;
    }

    cout << "Done." << endl;

    return 0;
}
