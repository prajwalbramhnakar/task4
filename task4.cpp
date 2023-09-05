#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Task structure to store task details
struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

// Function to add a task to the list
void addTask(vector<Task>& taskList, const string& description) {
    Task newTask(description);
    taskList.push_back(newTask);
    cout << "Task added: " << description << endl;
}

// Function to view all tasks
void viewTasks(const vector<Task>& taskList) {
    cout << "Tasks:" << endl;
    for (size_t i = 0; i < taskList.size(); i++) {
        cout << i + 1 << ". ";
        if (taskList[i].completed) {
            cout << "[X] ";
        } else {
            cout << "[ ] ";
        }
        cout << taskList[i].description << endl;
    }
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& taskList, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= taskList.size()) {
        taskList[taskIndex - 1].completed = true;
        cout << "Task marked as completed: " << taskList[taskIndex - 1].description << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

// Function to remove a task from the list
void removeTask(vector<Task>& taskList, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= taskList.size()) {
        cout << "Task removed: " << taskList[taskIndex - 1].description << endl;
        taskList.erase(taskList.begin() + taskIndex - 1);
    } else {
        cout << "Invalid task number." << endl;
    }
}

int main() {
    vector<Task> taskList;

    while (true) {
        cout << "To-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 5) {
            break;
        }

        switch (choice) {
            case 1: {
                string taskDescription;
                cin.ignore(); // Clear the newline character
                cout << "Enter task description: ";
                getline(cin, taskDescription);
                addTask(taskList, taskDescription);
                break;
            }
            case 2:
                viewTasks(taskList);
                break;
            case 3: {
                int taskIndex;
                cout << "Enter the task number to mark as completed: ";
                cin >> taskIndex;
                markTaskCompleted(taskList, taskIndex);
                break;
            }
            case 4: {
                int taskIndex;
                cout << "Enter the task number to remove: ";
                cin >> taskIndex;
                removeTask(taskList, taskIndex);
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    cout << "Thank you for using the To-Do List Manager!" << endl;

    return 0;
}
