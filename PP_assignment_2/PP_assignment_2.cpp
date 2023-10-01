#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class TextEditor {
public:
    std::vector<std::vector<std::string>> userTextD;

    TextEditor(int initialSize) {
        userTextD.resize(initialSize);
    }

    void appendText(const std::string& text) {
        userTextD.back().push_back(text);
    }

    void printText() {
        for (const std::vector<std::string>& line : userTextD) 
        {
            if (!line.empty()) {
                for (const std::string& words : line) {
                    std::cout << words;
                }
                std::cout << std::endl;
            }
        }
    }

    void addNewline() {
        userTextD.push_back({});
    }
};

class FileManager {
public:
    static void writeToFile(const std::string& fileName, std::vector<std::vector<std::string>>& userText) {
        std::ofstream file(fileName);

        if (file.is_open()) {
            for (const std::vector<std::string>& line : userText)
            {

                if (!line.empty()) {
                    for (const std::string& words : line)
                    {
                        file << words;
                    }
                    file << '\n';
                }
                //file << '\n';
            }
            std::cout << "Text written to file successfully.\n";
        }
        else {
            std::cerr << "Error opening file.\n";
        }
    }

    static void readFromFile(const std::string& fileName, std::vector<std::vector<std::string>>& userText) {
        std::ifstream file(fileName);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line))
            {
                userText.push_back({ line });
            }
            std::cout << "File read successfully.\n";
        }
        else {
            std::cerr << "Error opening file or file doesn't exist.\n";
        }
    }
};

class LineEditor {
public:

    static std::vector<size_t> splitIntoVector(const std::string& userInput) {

        std::vector<size_t> tokens;
        std::istringstream intString(userInput);
        std::string token;
        
        while (std::getline(intString, token, ' '))
        {
            tokens.push_back(std::stoul(token));
        }

        return tokens;
    }

    static void deleteString(size_t lineIndex, size_t startIndex, size_t numOfChars, std::vector<std::vector<std::string>>& userText) {

        if (lineIndex >= 0 && lineIndex < userText.size()) {

            std::cout << userText[lineIndex][0].size() << "fuck my ass.\n";
            if (startIndex >= 0 && startIndex + numOfChars < userText[lineIndex][0].size()) {
                userText[lineIndex][0].erase(userText[lineIndex][0].begin() + startIndex, userText[lineIndex][0].begin() + startIndex + numOfChars);
            }
            else {
                std::cerr << "\nerror: invalid line indices\n";
            }
        }
        else {
            std::cerr << "\nerror: out of bounds line index\n";
        }
    }
};

int main()
{
    TextEditor userText(1);
    std::string textInput;
    std::vector<size_t> indexSpecifier;
    int cmdType;

    std::string filename;

    int testing = userText.userTextD.size();

    while (1) {

        std::cout << "\nChoose a command (Line: " << userText.userTextD.size() << "): ";
        std::cin >> cmdType;

        switch (cmdType)
        {
        case 1:

            std::cin.ignore();
            std::cout << "\nEnter text to append: ";

            std::getline(std::cin, textInput);
            userText.appendText(textInput);

            std::cout << "\nText appended: " + textInput;

            break;
        case 2:

            userText.printText();
            std::cout << "\n";

            break;
        case 3:

            userText.addNewline();
            std::cout << "\nNewline added.";

            break;
        case 4:

            std::cin.ignore();
            std::cout << "\nInput file name: ";
            std::getline(std::cin, filename);

            FileManager::writeToFile(filename, userText.userTextD);

            std::cout << "\ntext written to file.";

            break;
        case 5:

            std::cin.ignore();
            std::cout << "\nInput file name: ";
            std::getline(std::cin, filename);

            FileManager::readFromFile(filename, userText.userTextD);

            std::cout << "\ntext read from file.";

            break;
        case 8:
            //error: vector subscript out of range.
            std::cin.ignore();
            std::cout << "\nSpecify line, starting index, and number of characters: ";
            std::getline(std::cin, textInput);

            indexSpecifier = LineEditor::splitIntoVector(textInput);
            LineEditor::deleteString(indexSpecifier[0],indexSpecifier[1], indexSpecifier[2], userText.userTextD);

            std::cout << "\nString deleted: " << textInput;

            break;
        case 9:
        {
            /*
            std::cin.ignore();
            std::cout << "\n -- Test --- Specify line, starting index, and number of characters: ";
            std::getline(std::cin, textInput);

            std::vector<int> indices = LineEditor::splitIntoVector(textInput);

            for (int token : indices) {
                std::cout << token << " ";
            }
            */
        }
            break;
        case 97:
            exit(0);
            break;
        case 99:
            std::cout << "\nsize of vector: " << userText.userTextD.size() << "\n";
            break;
        default:
            break;
        }
    }
}
