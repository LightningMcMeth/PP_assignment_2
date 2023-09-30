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
private:
    int indexSpecifier[3];

public:

    static void splitIntoArr(std::string userInput) {

        std::vector<int> nums;
        std::istringstream gamer(userInput);

        int number;

        while (gamer >> number)
        {
            nums.push_back(number);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            indexSpecifier[i] = gamer[i];
        }
    }

    static void deleteString(std::vector<std::vector<std::string>>& userText) {

        int lineIndex = indexSpecifier[0], int startIndex = indexSpecifier[1], int numOfChars = indexSpecifier[2];

        if (lineIndex >= 0 && lineIndex < userText.size()) {

            if (startIndex >= 0 && startIndex + numofChars < userText[lineIndex].size()) {
                userText[lineIndex].erase(startIndex, startIndex + numOfChars);
            }
            else {
                std::cerr << "\nerror: invalid line indices\n";
            }
        }
        else {
            std::cerr << "\nerror: out of bounds index\n";
        }
    }
};

int main()
{
    TextEditor userText(1);
    std::string textInput;
    int cmdType;

    std::string filename;

    while (1) {

        std::cout << "\nChoose a command (99 for vector info): ";
        std::cin >> cmdType

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

            userText.printText()
            std::cout << "\n";

            break;
        case 3:

            userText.addNewline()
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
        case 8

            std::cout << "\nSpecify line, starting index, and number of characters: "
            std::getline(cin, textInput);

            LineEditor::SplitIntoArr(textInput);
            LineEditor::deleteString(userText.userTextD);

            std::cout << "\nString deleted: " << textInput;

            break;
        case 97
            exit(0);
            break;
        case 99
            std::cout << "\nsize of vector: " << userText.userTextD.size() << "\n";
            break;
        default:
            break;
        }
    }
}
