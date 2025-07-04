#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

//class of making a contact(declaratives)
class Contact{
private:
    string name;
    string phoneNumber;
    string nickName;
    bool isBookmarked;
public:
    Contact(string name, string phonenumber, string nickname);
    string getName() const {return name;}
    string getPhoneNumber() const {return phoneNumber;}
    string getNickName() const {return nickName;}
    void display() const;
    void setBookmark(bool status);
    bool getBookmarked() const {return isBookmarked;}
};

//class of managing contacts(declaratives)
class phoneBook{
private:
    vector<Contact> contacts;
public:
    void add(const Contact& contact); //object of Contact class as parameter
    void search(const string& name);
    void remove(const string& phoneNumber);
    void bookmark(const string& phonmber);
    void Exit(); 
    static bool compareName(const Contact &a, const Contact &b) {
        return a.getName() < b.getName(); //compare by name
    }
};

//implementation of Contact member functions
Contact::Contact(string name, string phonenumber, string nickname){
    this->name = name;
    this->phoneNumber = phoneNumber;
    this->nickName = nickname;
    this->isBookmarked = false; //default value
}
void Contact::display() const {
    cout << "name: " << name << endl;
    cout << "phoneNumber: " << phoneNumber << endl;
    cout << "nickName: " << nickName << endl;
    cout << "Bookmark: " << (isBookmarked ? "Yes" : "No") << endl << endl; //Ternary operator
}
void Contact::setBookmark(bool status) {
    isBookmarked = status;
}


//Implementation of phoneBook member functinos
void phoneBook::add(const Contact& contact) {
    contacts.push_back(contact);
    cout << "new contact added!" << endl;
    contact.display();
    // sort contacts by name
    sort(contacts.begin(), contacts.end(), phoneBook::compareName );
}
void phoneBook::search(const string& name) {  //to show every phone number with index
    int index = 0;
    for (Contact& c : contacts) {
        if (c.getBookmarked())
            cout << "Bookmarked Contact: " << c.getName() << " Phone Number: " << c.getPhoneNumber() << endl;
    }
    for (Contact & c : contacts) {
        cout << index << " Name: " << c.getName() << " Phone Number: " << c.getPhoneNumber() << endl;
        index++;
    }
    for (const Contact& c : contacts) {
        if (c.getName() == name) {
            c.display();
            return;
        }
    }
    cout << "Contact with name: " << name << " not found." << endl;
    return;
}

void phoneBook::remove(const string& phoneNumber) {
    for (int i = 0; i < contacts.size(); i++) {
        if (contacts[i].getPhoneNumber() == phoneNumber) {  //to find the contact with given phonenumber
            contacts[i].display();
            contacts.erase(contacts.begin() + i);
            cout << "Contact: " << phoneNumber << " removed." << endl;
            return;
        }
    }
}

void phoneBook::bookmark(const string& phoneNumber) {

    for (Contact& c: contacts) {
        if (c.getPhoneNumber() == phoneNumber) {
            c.setBookmark(true);
            cout << "Contact: " << phoneNumber << "bookmarked. " << endl;
            return;
        }
    }
}


int main() {
    cout << "Hi this is a old phone book program." << endl;
    phoneBook pb;
    string name, phoneNumber, nickName;
    int choice;
    cout << "Choose a function: " << endl 
    << "1. Add Contact, " << endl
    << "2. Search Contact, " << endl
    << "3. Remove Contact, " << endl
    << "4. Bookmark Contact, " << endl
    << "5. Exit " << endl;
    while(true) {
        cout << "Select a function: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter phoneNumber(8 digit in Series): ";
            cin >> phoneNumber;
            cout << "Enter nuckName: ";
            cin >> nickName;
            pb.add(Contact(name, phoneNumber, nickName));
        }
        else if (choice == 2) {
            cout << "Enter name to search: ";
            cin >> name;
            pb.search(name);
        }
        else if (choice == 3) {
            cout << "Enter phoneNumber to remove: ";
            cin >> phoneNumber;
            pb.remove(phoneNumber);
        }
        else if (choice == 4) {
            cout << "Enter phoneNumber to bookmark: ";
            cin >> phoneNumber;
            pb.bookmark(phoneNumber);
        }
        else if (choice == 5) {
            pb.Exit();
            break;
        }
        else {
            cout << "Invalid choice, please try again." << endl;
        }
    }
    cout << "Program Over." << endl;
    return 0;
}