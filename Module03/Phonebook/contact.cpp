#include "contact.h"
#include <string>

using namespace std;

bool Contact::setName(string name) {
    if (!name.empty()) {
        for(auto& c : name) {
            if(c < 65 || c > 122) return false;
        }
        return true;
    }
    else
        return true;
}
bool Contact::setPhoneNumber(string phoneNum) {
    if (!phoneNum.empty()) {
        for(auto& c : phoneNum) {
            if (c < 45 || c > 57) return false;
        }
        return true;
    }
    else
        return true;
}
bool Contact::setEmailAddress(string Email) {
    if (!Email.empty()) {
        for (auto& c : Email) {
            if (c == '@') return true;
        }
        return false;
    }
    else
        return true;
}

//getter
string Contact::getName() const {return this->name;}
string Contact::getPhoneNum() const {return phoneNumber;}
string Contact::getEmail() const {return emailAddress;}

//constructor (bookmark is false basically)
Contact::Contact(string name, string phoneNum, string Email) : name(name), phoneNumber(phoneNum), emailAddress(Email) {}


