#include <iostream>
#include <string>
#include <optional>
#include <map>
#include <vector>

#include "includes/task.h"
#include "includes/prompt.h"

using std::string;
using std::cout;
using std::cin;

std::vector<Task> tasks;
Prompt prompt;

void printTask(Task& task) {
    cout << task.name << ": " << task.getStatus();
}

void createTaskPrompt() {
    string taskName = prompt.printText("Enter Task: ", true);

    tasks.emplace_back(taskName, false);
    Task& newTask = tasks.back();  // reference the most recently created task
    
    printTask(newTask);
}

int main() {
    createTaskPrompt();
    

    return 0;
}