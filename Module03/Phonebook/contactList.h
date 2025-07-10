#ifndef CONTACTLIST_H
#define CONTACTLIST_H
#include "contact.h"
#include <vector>
using namespace std;

class contactList {
private:
    vector<Contact> contacts;
public:
    void add(const Contact& contact);
    void remove(const string& name, const string& number);
    Contact* search(const string& name, const string& number, const string& email);
    //getter
    vector<Contact>& getContacts();
};

#endif // CONTACTLIST_H
