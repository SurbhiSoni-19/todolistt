#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

// Function to add a task
void addTask(vector<Task>& tasks, const string& description) {
    tasks.push_back({description, false});
}

// Function to display all tasks
void viewTasks(const vector<Task>& tasks) {
    cout << "\nTo-Do List:" << endl;
    if (tasks.empty()) {
        cout << "No tasks added yet!" << endl;
        return;
    }
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << (tasks[i].completed ? "[Completed] " : "[Pending] ") << tasks[i].description << endl;
    }
}

// Function to mark a task as completed
void markTaskAsCompleted(vector<Task>& tasks, int taskNumber) {
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].completed = true;
        cout << "Task " << taskNumber << " marked as completed!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

// Function to remove a task
void removeTask(vector<Task>& tasks, int taskNumber) {
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task " << taskNumber << " removed!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

int main() {
    vector<Task> tasks;
    int choice;
    string description;
    int taskNumber;

    do {
        cout << "\nTo-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To handle the newline character after choice input

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, description);
                addTask(tasks, description);
                break;

            case 2:
                viewTasks(tasks);
                break;

            case 3:
                cout << "Enter task number to mark as completed: ";
                cin >> taskNumber;
                markTaskAsCompleted(tasks, taskNumber);
                break;

            case 4:
                cout << "Enter task number to remove: ";
                cin >> taskNumber;
                removeTask(tasks, taskNumber);
                break;

            case 5:
                cout << "Exiting the program..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}