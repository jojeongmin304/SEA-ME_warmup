#include "contactList.h"
#include <vector>
using namespace std;

void contactList::add(const Contact& contact) {
    contacts.push_back(contact);}

Contact* contactList::search(const string& name, const string& number, const string& email) {
    for (Contact& c : contacts) {
        if (c.getName() == name || c.getPhoneNum() == number || c.getEmail() == email) {return &c;}
    }
    return nullptr;
}

void contactList::remove(const string& name, const string& number) {
    for (int i = 0; i < contacts.size(); ) {
        if (contacts[i].getName() == name || contacts[i].getPhoneNum() == number)
            contacts.erase(contacts.begin() + i);
        else
            ++i;
    }
}

vector<Contact>& contactList::getContacts() {
    return contacts;
}
