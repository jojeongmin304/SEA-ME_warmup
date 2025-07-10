#ifndef CONTACT_H
#define CONTACT_H

#include <string>
using namespace std;


class Contact {
private:
    string name;
    string phoneNumber;
    string emailAddress;
    bool bookMark;
public:
    //setter
    bool setName(string name);
    bool setPhoneNumber(string phoneNum);
    bool setEmailAddress(string Email);

    //getter
    string getName() const;
    string getPhoneNum() const;
    string getEmail() const;

    //constructor
    Contact(string name, string phoneNum, string Email);

};

#endif // CONTACT_H
