#include <iostream>
#include <fstream>
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

    void writeToFile(const std::string& fileName) {
        std::ofstream file(fileName);

        if (file.is_open()) {
            for (const std::vector<std::string>& line : userTextD)
            {
                for (const std::string& words : line) 
                {
                    file << words;
                }
                file << '\n';
            }
            std::cout << "Text written to file successfully.\n";
        }
        else {
            std::cerr << "Error opening file.\n";
        }
    }

    void readFromFile(const std::string& fileName) {
        std::ifstream file(fileName);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) 
            {
                userTextD.push_back({line});
            }
            std::cout << "File read successfully.\n";
        }
        else {
            std::cerr << "Error opening file or file doesn't exist.\n";
        }
    }
};

class FileManager {
public:
    static void writeToFile(const std::string& fileName, std::vector<std::vector<std::string>>& userText) {
        std::ofstream file(fileName);

        if (file.is_open()) {
            for (const std::vector<std::string>& line : userText)
            {
                for (const std::string& words : line)
                {
                    file << words;
                }
                file << '\n';
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

int main()
{
    TextEditor userText(100);
    std::string textInput;
    int cmdType;

    std::string filename;

    while (1) {

        std::cout << "\nChoose a command: ";
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

            std::cout << "\nInput file name: ";
            std::getline(std::cin, filename);

            FileManager::writeToFile(filename, userText.userTextD);

            std::cout << "\ntext written to file.";
            break;
        case 5:

            std::cout << "\nInput file name: ";
            std::getline(std::cin, filename);

            FileManager::readFromFile(filename, userText.userTextD);

            std::cout << "\ntext read from file.";
            break;
        case 6:
            break;
        default:
            break;
        }
    }
}
