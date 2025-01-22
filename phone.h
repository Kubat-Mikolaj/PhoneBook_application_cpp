#ifndef PHONE_H
#define PHONE_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

// Klasa reprezentująca kontakt
class Contact 
{
private:
    std::string name;
    std::string surname;
    std::string phoneNumber;
    std::string email;

public:
    Contact(const std::string& name, const std::string& surname,
            const std::string& phoneNumber, const std::string& email);

    const std::string& getName() const;
    const std::string& getSurname() const;
    const std::string& getPhoneNumber() const;
    const std::string& getEmail() const;

    void display() const;

    friend std::ostream& operator<<(std::ostream& os, const Contact& contact);
};

// Struktura węzła drzewa
struct Node 
{
    Contact data;
    Node* left;
    Node* right;

    Node(const Contact& contact) : data(contact), left(nullptr), right(nullptr) {}
};

// Klasa reprezentująca książkę telefoniczną
class PhoneBook 
{
private:
    Node* root = nullptr;

    Node* insert(Node* node, const Contact& contact);
    void InOrderTraversal(Node* node) const;
    Node* search(Node* node, const std::string& keyword) const;

    // Pomocnicza metoda do zapisu kontaktów w pliku
    void saveToFileHelper(Node* node, std::ofstream& file) const;

public:
    void addContact(const Contact& contact);
    void displayContacts() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void searchContact(const std::string& keyword);
};

#endif
