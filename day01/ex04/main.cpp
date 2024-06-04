#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: ./replace filename s1 s2\n";
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream inFile(filename.c_str());
    if (!inFile) {
        std::cerr << "Error: Unable to open input file\n";
        return 1;
    }

    std::string new_name = filename + ".replace";
    std::ofstream outFile(new_name.c_str());
    if (!outFile) {
        std::cerr << "Error: Unable to create output file\n";
        return 1;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        std::string word;
        std::string newLine;
        while (iss >> word) {
            if (word == s1)
                newLine += s2 + " ";
            else
                newLine += word + " ";
        }
        newLine = newLine.substr(0, newLine.length() - 1); // remove the trailing space
        outFile << newLine << '\n';
    }
    inFile.close();
    outFile.close();
}
