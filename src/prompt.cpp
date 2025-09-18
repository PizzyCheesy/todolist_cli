#include <iostream>
#include <string.h>
#include "../includes/prompt.h"

using std::string;

string Prompt::printText(string promptText) {
    std::cout << promptText;
    return promptText;
}

string Prompt::checkInput() {
    std::getline(std::cin, promptInput);
    return promptInput;
}

