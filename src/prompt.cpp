#include <iostream>
#include <string.h>
#include "../includes/prompt.h"

using std::string;

string Prompt::printText(string promptText) {
    std::cout << promptText;
}

string Prompt::checkInput() {
    std::getline(std::cin, promptOutput);
}

