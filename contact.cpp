#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

// Structure to represent a contact
struct Contact {
    string name;
    string phoneNumber;
    string emailAddress;
};

// Function prototypes
void addContact(vector<Contact>& contacts);
void viewContacts(const vector<Contact>& contacts);
void editContact(vector<Contact>& contacts);
void deleteContact(vector<Contact>& contacts);

int main() {
    vector<Contact> contacts;

    // Load contacts from a file (if available)
    ifstream inFile("contacts.txt");
    if (inFile.is_open()) {
        Contact contact;
        while (inFile >> contact.name >> contact.phoneNumber >> contact.emailAddress) {
            contacts.push_back(contact);
        }
        inFile.close();
    }

    int choice;
    do {
        cout << "Contact Management System" << endl;
        cout << "1. Add a new contact" << endl;
        cout << "2. View contacts" << endl;
        cout << "3. Edit a contact" << endl;
        cout << "4. Delete a contact" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                viewContacts(contacts);
                break;
            case 3:
                editContact(contacts);
                break;
            case 4:
                deleteContact(contacts);
                break;
            case 5:
                // Save contacts to a file before exiting
                ofstream outFile("contacts.txt");
                for (const Contact& contact : contacts) {
                    outFile << contact.name << " " << contact.phoneNumber << " " << contact.emailAddress << endl;
                }
                outFile.close();
                cout << "Contacts saved. Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 5);

    return 0;
}

void addContact(vector<Contact>& contacts) {
    Contact newContact;
    cout << "Enter name: ";
    cin.ignore(); // Clear the newline character from the buffer
    getline(cin, newContact.name);
    cout << "Enter phone number: ";
    getline(cin, newContact.phoneNumber);
    cout << "Enter email address: ";
    getline(cin, newContact.emailAddress);

    contacts.push_back(newContact);
    cout << "Contact added successfully." << endl;
}

void viewContacts(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts available." << endl;
    } else {
        cout << "Contact List:" << endl;
        for (const Contact& contact : contacts) {
            cout << "Name: " << contact.name << "\tPhone: " << contact.phoneNumber << "\tEmail: " << contact.emailAddress << endl;
        }
    }
}

void editContact(vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts available for editing." << endl;
        return;
    }

    string searchName;
    cout << "Enter the name of the contact to edit: ";
    cin.ignore(); // Clear the newline character from the buffer
    getline(cin, searchName);

    bool found = false;
    for (Contact& contact : contacts) {
        if (contact.name == searchName) {
            cout << "Enter new phone number: ";
            getline(cin, contact.phoneNumber);
            cout << "Enter new email address: ";
            getline(cin, contact.emailAddress);
            cout << "Contact edited successfully." << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Contact not found." << endl;
    }
}

void deleteContact(vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts available for deletion." << endl;
        return;
    }

    string searchName;
    cout << "Enter the name of the contact to delete: ";
    cin.ignore(); // Clear the newline character from the buffer
    getline(cin, searchName);

    auto it = find_if(contacts.begin(), contacts.end(), [searchName](const Contact& contact) {
        return contact.name == searchName;
    });

    if (it != contacts.end()) {
        contacts.erase(it);
        cout << "Contact deleted successfully." << endl;
    } else {
        cout << "Contact not found." << endl;
    }
}
