#include <iostream>
#include <string>
#include "../includes/task.h"

using std::string;
using std::cout;

string Task::getStatus() {
    return taskDone ? "complete" : "incomplete";
}

bool Task::taskComplete() {
    return taskDone = true;
}