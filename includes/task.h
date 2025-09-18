#pragma once

#include <iostream>
#include <string>

using std::string;
using std::cout;

class Task {
    public: 
        string name;
        bool taskDone;

        bool taskComplete();
        string getStatus();

    Task(string taskName, bool isComplete) {
        name = taskName;
        taskDone = isComplete;
    }
};