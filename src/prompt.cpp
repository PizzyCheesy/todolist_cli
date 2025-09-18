#include <iostream>
#include <string.h>
#include "../includes/prompt.h"

using std::string;

string Prompt::printText(string promptText, bool returnValue) {
    std::cout << promptText;
            if (returnValue) {
                std::getline(std::cin, promptOutput);
                return promptOutput;
            }
    return "";
}

