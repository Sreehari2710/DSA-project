#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

class User {
public:
    string firstName;
    string lastName;
    int age;
    string gender;

    User() {} ;

    User(string firstName, string lastName, int age, string gender) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;
        this->gender = gender;
    }
};

// MAP user-name to USER
map<string, User> mapUserName;

// MAPPING ONE FRIEND TO ANOTHER FRIEND
map<string, set<string>> Friends;

void addUser(string userName, User user) {
    if (mapUserName.find(userName) == mapUserName.end()) {
        mapUserName[userName] = user;
    } else {
        cout << "UserName Already Taken" << endl;
    }
}

void makeThemFriend(string userName1, string userName2) {
    Friends[userName1].insert(userName2); // mapping 1st friend to another
    Friends[userName2].insert(userName1);
}

void displayAllUser() {
    for (auto &i : mapUserName) {
        cout << "UserName: " << i.first << " "
             << "Name: " << i.second.firstName << " " << i.second.lastName << " "
             << "Age: " << i.second.age << " "
             << "Gender: " << i.second.gender << endl;
    }
}

void displayAllFriendships() {
    for (auto &i : Friends) {
        cout << i.first << ":\n";
        set<string> friends = i.second;
        for (auto &j : friends) {
            cout << j << " ";
        }
        cout << "\n";
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add User\n";
        cout << "2. Make Friends\n";
        cout << "3. Display All Users\n";
        cout << "4. Display All Friendships\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string userName, firstName, lastName, gender;
            int age;
            cout << "Enter username: ";
            cin >> userName;
            cout << "Enter first name: ";
            cin >> firstName;
            cout << "Enter last name: ";
            cin >> lastName;
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter gender: ";
            cin >> gender;

            User user(firstName, lastName, age, gender);
            addUser(userName, user);
        } else if (choice == 2) {
            string userName1, userName2;
            cout << "Enter first username: ";
            cin >> userName1;
            cout << "Enter second username: ";
            cin >> userName2;

            if (mapUserName.find(userName1) != mapUserName.end() && mapUserName.find(userName2) != mapUserName.end()) {
                makeThemFriend(userName1, userName2);
            } else {
                cout << "One or both usernames do not exist." << endl;
            }
        } else if (choice == 3) {
            displayAllUser();
        } else if (choice == 4) {
            displayAllFriendships();
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
