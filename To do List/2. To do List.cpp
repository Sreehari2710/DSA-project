#include <iostream> // Include standard input-output library
#include <vector>   // Include vector library
#include <string>   // Include string library

using namespace std;

class Task {
public:
    string description;
    string category;
    bool completed;

    Task(string description, string category) {
        this->description = description;
        this->category = category;
        this->completed = false;
    }
};

vector<Task> NotesAdded;

void displayTasks() {
    if (NotesAdded.empty()) {
        cout << "Please add some tasks first to view.\n";
        return;
    }

    cout << "\nTasks:\n";
    for (int i = 0; i < NotesAdded.size(); i++) {
        cout << i + 1 << ". " << NotesAdded[i].description << " [" << NotesAdded[i].category << "] "
             << (NotesAdded[i].completed ? "(Completed)" : "(Pending)") << "\n";
    }
}

void markTaskAsCompleted() {
    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= NotesAdded.size()) {
        NotesAdded[taskNumber - 1].completed = true;
    } else {
        cout << "Invalid Task Number\n";
    }
}

void deleteTask() {
    int taskNumber;
    cout << "Enter the task number to delete: ";
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= NotesAdded.size()) {
        NotesAdded.erase(NotesAdded.begin() + taskNumber - 1);
    } else {
        cout << "Invalid Task Number\n";
    }
}

void filterTaskByCategory() {
    string category;
    cout << "Enter the category to filter by: ";
    cin >> category;

    if (NotesAdded.empty()) {
        cout << "Please add some tasks first to view.\n";
        return;
    }

    cout << "\nTasks:\n";
    for (int i = 0; i < NotesAdded.size(); i++) {
        if (NotesAdded[i].category == category) {
            cout << i + 1 << ". " << NotesAdded[i].description << " [" << NotesAdded[i].category << "] "
                 << (NotesAdded[i].completed ? "(Completed)" : "(Pending)") << "\n";
        }
    }
}

void addTask() {
    string description;
    string category;
    cout << "Enter the description: ";
    cin.ignore();
    getline(cin, description);
    cout << "Enter the category: ";
    getline(cin, category);

    Task task(description, category);
    NotesAdded.push_back(task);
}

void displayMenu() {
    int choice; // Variable to store the user's menu choice
    do {
        cout << "\nMenu:\n"
             << "1. Add Task\n"
             << "2. View Tasks\n"
             << "3. Mark Task as Completed\n"
             << "4. Delete Task\n"
             << "5. Filter Tasks by Category\n"
             << "6. Exit\n"
             << "Enter your choice: ";
        cin >> choice; // Read the user's choice

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                markTaskAsCompleted();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                filterTaskByCategory();
                break;
            case 6:
                cout << "Goodbye! Please do the tasks on time.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6); // Loop until the user chooses to exit
}

int main() {
    displayMenu(); // Display the menu to the user
    return 0; // End of the program
}
