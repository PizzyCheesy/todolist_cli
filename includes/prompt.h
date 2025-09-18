#include <iostream>

class Prompt {
    private:
        std::string promptText;
        std::string promptOutput;

    public:
        std::string printText (std::string promptText, bool returnValue);
};