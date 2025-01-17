#ifndef phonebook_h
#define phonebook_h

#include <iostream>
#include <string>
#include <iomanip>


class PhoneBook {
private:
    Contact phonebook[8];
    int size;
public:
    PhoneBook();
    void addContact(Contact contact);
    void search(int  index);
    int getSize();
    void display();
};

void    addContact(Contact contact);
void    search(int  index);
int     getSize();
void    display();
#endif