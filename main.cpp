#include <iostream>
#include <string>
#include <optional>
#include <map>
#include <vector>
#include <algorithm>

#include "includes/task.h"
#include "includes/prompt.h"

using std::string;
using std::cout;
using std::cin;

std::vector<Task> tasks;
Prompt prompt;

void printTask(Task& task) {
    cout << task.name << ": " << task.getStatus() << "\n";
}

void createTask(string taskName) {
    tasks.emplace_back(taskName, false);
    Task& newTask = tasks.back();  // reference the most recently created task
    
    printTask(newTask);
}

void deleteTask(const string& name) {
    auto it = std::find_if(
        tasks.begin(),
        tasks.end(),
        [&](const Task& t){ return t.name == name; }
    );

    if (it != tasks.end()) {
        tasks.erase(it);
        std::cout << "Task \"" << name << "\" deleted!" << std::endl;
    } else {
        std::cout << "Task not found!" << std::endl;
    }
}

void homePrompt() {
    
}

int main() {


    return 0;
}