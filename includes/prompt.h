#pragma once

#include <iostream>

class Prompt {
    private:
        std::string promptText;
        std::string promptInput;

    public:
        std::string printText (std::string promptText);
        std::string checkInput ();
};