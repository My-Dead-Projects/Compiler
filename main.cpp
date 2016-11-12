#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> tokenize(std::string);
bool is_letter(char);
bool is_digit(char);

int main() {


    std::ofstream main;
    std::ifstream source;
    main.open("main.asm");
    source.open("source.code");

    std::string line;
    // Read in one line from source, and store it in line
    std::getline(source, line); // THIS IS NOT WORKING

    std::cout << "Line = " << line << std::endl;

    std::vector<std::string> tokenizedLine = tokenize(line);

    for (std::string tok : tokenizedLine) {
        std::cout << tok << std::endl;
    }

    main.close();
    source.close();

    return 0;
}

std::vector<std::string> tokenize(std::string line) {

    std::vector<std::string> tokens;

    for (int tokenStart = 0, tokenEnd = 0; tokenEnd < line.length(); tokenEnd++) {

        // If tokenEnd does not point to a valid character, this is the end of a token.
        if (not is_letter(line[tokenEnd]) and not is_digit(line[tokenEnd])) {

            // If the slice between tokenStart and tokenEnd is zero length, add the slice to tokens
            if (tokenEnd-tokenStart != 0) {
                tokens.push_back(line.substr(tokenStart, tokenEnd-tokenStart));
            }

            // Whether the token is zero length or not, we need to move tokenStart forward.
            tokenStart = tokenEnd + 1;
        }

        // If tokenEnd does point to a valid character, we will simply continue. tokenEnd will be incremented.
    }
    return tokens;
}

bool is_letter(char c) {
    return (tolower(c) >= 'a' and tolower(c) <= 'z');
}

bool is_digit(char c) {
    return (c >= '0' and c <= '9');
}
