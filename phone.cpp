#include "phone.h"
#include <sstream>
#include <algorithm>

// Implementacja metod klasy Contact
Contact::Contact(const std::string& name, const std::string& surname,
                 const std::string& phoneNumber, const std::string& email)
    : name(name), surname(surname), phoneNumber(phoneNumber), email(email) {}

const std::string& Contact::getName() const 
{
    return name;
}

const std::string& Contact::getSurname() const 
{
    return surname;
}

const std::string& Contact::getPhoneNumber() const 
{
    return phoneNumber;
}

const std::string& Contact::getEmail() const 
{
    return email;
}

void Contact::display() const 
{
    std::cout << name << " " << surname << " | " 
              << phoneNumber << " | " << email << '\n';
}

std::ostream& operator<<(std::ostream& os, const Contact& contact) 
{
    os << contact.name << "," 
       << contact.surname << "," 
       << contact.phoneNumber << "," 
       << contact.email;
    return os;
}

// Implementacja metod klasy PhoneBook
void PhoneBook::addContact(const Contact& contact) 
{
    root = insert(root, contact);
}

void PhoneBook::displayContacts() const 
{
    InOrderTraversal(root);
}

void PhoneBook::saveToFile(const std::string& filename) const 
{
    std::ofstream file(filename);

    if (!file.is_open()) 
    {
        std::cerr << "Nie można otworzyć pliku do zapisu!" << '\n';
        return;
    }

    saveToFileHelper(root, file);

    std::cout << "Kontakty zostały zapisane do pliku: " << filename << '\n';
    file.close();
}

void PhoneBook::saveToFileHelper(Node* node, std::ofstream& file) const
{
    if (node != nullptr) 
    {
        saveToFileHelper(node->left, file);
        file << node->data << '\n';
        saveToFileHelper(node->right, file);
    }
}

void PhoneBook::loadFromFile(const std::string& filename) 
{
    std::ifstream file(filename);

    if (!file.is_open()) 
    {
        std::cerr << "Nie można otworzyć pliku do odczytu!" << '\n';
        return;
    }

    std::string line;
    while (std::getline(file, line)) 
    {
        std::istringstream iss(line);
        std::string name, surname, phoneNumber, email;

        if (std::getline(iss, name, ',') &&
            std::getline(iss, surname, ',') &&
            std::getline(iss, phoneNumber, ',') &&
            std::getline(iss, email)) 
        {
            Contact contact(name, surname, phoneNumber, email);
            addContact(contact); // Wstawienie kontaktu do drzewa
        }
    }

    std::cout << "Kontakty zostały wczytane z pliku: " << filename << '\n';
    file.close();
}

void PhoneBook::searchContact(const std::string& keyword)
{
    Node* result = search(root, keyword);
    if (result != nullptr) 
    {
        result->data.display(); // Wyświetlamy znaleziony kontakt
    } 
    else 
    {
        std::cout << "Nie znaleziono kontaktu: " << keyword << std::endl;
    }
}

Node* PhoneBook::insert(Node* node, const Contact& contact)
{
    if (node == nullptr) 
    {
        return new Node(contact);
    }

    if (contact.getSurname() < node->data.getSurname() || 
       (contact.getSurname() == node->data.getSurname() && 
        contact.getName() < node->data.getName())) 
    {
        node->left = insert(node->left, contact); // Wstawianie do lewego poddrzewa
    } 
    else 
    {
        node->right = insert(node->right, contact); // Wstawianie do prawego poddrzewa
    }

    return node;
}

void PhoneBook::InOrderTraversal(Node* node) const
{
    if (node != nullptr) 
    {
        InOrderTraversal(node->left);
        node->data.display(); // Wyświetlanie kontaktu
        InOrderTraversal(node->right);
    }
}

Node* PhoneBook::search(Node* node, const std::string& keyword) const
{
    if (node == nullptr) 
    {
        return nullptr;
    }

    if (node->data.getName() == keyword || node->data.getSurname() == keyword) 
    {
        return node;
    }

    if (keyword < node->data.getSurname()) 
    {
        return search(node->left, keyword); // Szukamy w lewym poddrzewie
    } 
    else 
    {
        return search(node->right, keyword); // Szukamy w prawym poddrzewie
    }
}
