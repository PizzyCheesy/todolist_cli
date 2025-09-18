#include <iostream>
#include <string>
#include <optional>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>

#include "includes/task.h"
#include "includes/prompt.h"

using std::string;
using std::cout;
using std::cin;

std::vector<Task> tasks;
Prompt prompt;

void homePrompt();

void createTask() {
    prompt.printText("Enter Task Name: ");
    const string userInput = prompt.checkInput();

    tasks.emplace_back(userInput, false);
    Task& newTask = tasks.back();  // reference the most recently created task
    
    std::cout << "Created a task: " << newTask.name << "\n";
    homePrompt();
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

    homePrompt();
}

void printTasks() {
    auto *pTasks = &tasks;
    std::vector<Task> completedTasks;
    std::vector<Task> incompleteTasks;
    
    for(Task& task : *pTasks) {
        if (task.taskDone == true) {
            completedTasks.emplace_back(task.name, task.taskDone);
        } else {
            incompleteTasks.emplace_back(task.name, task.taskDone);
        }
    }

    // Example output:
    std::cout << "Incomplete: ";
    for (const auto& task : incompleteTasks) std::cout << task.name << ", ";
    std::cout << "\n";

    std::cout << "Complete: ";
    for (const auto& task : completedTasks) std::cout << task.name << " ";
    std::cout << "\n";

    homePrompt();
}

void checkComplete() {
    prompt.printText("What task have you completed?: ");
    string userInput = prompt.checkInput();

    auto it = std::find_if(
        tasks.begin(),
        tasks.end(),
        [&](const Task& t){ return t.name == userInput; }
    );

    if (it != tasks.end()) {
        it->taskDone = true;  // ✅ mark task complete
        std::cout << userInput << " has been completed!\n";
    } else {
        std::cout << "Task not found!\n";
    }

    homePrompt();
}

void exitProgram() {
    std::exit(0);
}

void homePrompt() {
    std::map<string, std::function<void()>> commands = {
        {"add", createTask},
        {"delete", deleteTask},
        {"ls", printTasks},
        {"check", checkComplete},
        {"exit", exitProgram}
    };

    prompt.printText("===DASHBOARD===\n");
    prompt.printText("1. Create new task: add\n2. Delete a task: delete\n3. List all tasks: ls\n4. Mark a task complete: check\n5. Exit program: exit\n>");

    string userInput = prompt.checkInput();

    if (commands.count(userInput)) {
        commands[userInput]();
    } else
    {
        prompt.printText("Command not found!: " + userInput + "\nPlease try again\n");
        homePrompt();
    }
    
}

int main() {
    homePrompt();

    return 0;
}