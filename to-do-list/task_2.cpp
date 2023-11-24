#include <iostream>
#include <vector>

using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

void clear_screen() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");    
    #endif
}

void show_menu() {
    cout << "===== To-Do List Manager =====\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
}

void add_task(const string& task) {
    tasks.push_back({task, false});
    cout << "Task added successfully!\n";
}

void view_tasks() {
    cout << "===== Tasks =====\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        string status = tasks[i].completed ? "Completed" : "Pending";
        cout << i + 1 << ". " << tasks[i].description << " - " << status << "\n";
    }
}

void mark_completed(size_t index) {
    if (index >= 1 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task index.\n";
    }
}

void remove_task(size_t index) {
    if (index >= 1 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed successfully!\n";
    } else {
        cout << "Invalid task index.\n";
    }
}

int main() {
    while (true) {
        clear_screen();
        show_menu();

        cout << "Enter your choice (1-5): ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string task;
                cout << "Enter the task: ";
                cin.ignore();
                getline(cin, task);
                add_task(task);
                break;
            }
            case 2:
                view_tasks();
                break;
            case 3: {
                size_t index;
                cout << "Enter the task index to mark as completed: ";
                cin >> index;
                mark_completed(index);
                break;
            }
            case 4: {
                size_t index;
                cout << "Enter the task index to remove: ";
                cin >> index;
                remove_task(index);
                break;
            }
            case 5:
                cout << "Exiting the To-Do List Manager. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }

        cout << "Press Enter to continue...";
        cin.ignore(); 
        cin.get();    
    }

    return 0;
}