#include <iostream>
#include <string>
#include <optional>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>

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

void createTask() {
    prompt.printText("Enter Task Name: ");
    const string userInput = prompt.checkInput();

    tasks.emplace_back(userInput, false);
    Task& newTask = tasks.back();  // reference the most recently created task
    
    printTask(newTask);
}

void deleteTask() {
    prompt.printText("Enter Task Name: ");
    const string userInput = prompt.checkInput();

    auto it = std::find_if(
        tasks.begin(),
        tasks.end(),
        [&](const Task& t){ return t.name == userInput; }
    );

    if (it != tasks.end()) {
        tasks.erase(it);
        std::cout << "Task \"" << userInput << "\" deleted!" << std::endl;
    } else {
        std::cout << "Task not found!" << std::endl;
    }
}

void homePrompt() {
    std::map<string, std::function<void()>> commands = {
        {"add", createTask},
        {"delete", deleteTask}
    };

    prompt.printText("===DASHBOARD===\n");
    prompt.printText("1. Create new task: add\n2. Delete a task: delete\n>");

    string userInput = prompt.checkInput();

    if (commands.count(userInput)) {
        commands[userInput]();
    } else
    {
        prompt.printText("Command not found!: " + userInput);
        return;
    }
    
}

int main() {
    homePrompt();

    return 0;
}