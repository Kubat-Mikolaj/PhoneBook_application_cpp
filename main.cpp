/* 
#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>

// Klasa Contact
class Contact
{
    private:
    std::string name;
    std::string surname;
    std::string phone_number;
    std::string email;


    public:

    // Konstruktor do obiektu klasy Contact

    Contact(const std::string& name,
            const std::string& surname,
            const std::string& phone_number,
            const std::string& email
           ):
           name(name), surname(surname), phone_number(phone_number), email(email) {}

// Metoda do wypisywania danych kontaktu

// Gettery

    std::string getName() const { return name; }
    std::string getSurname() const { return surname; }
    std::string getPhoneNumber() const { return phone_number; }
    std::string getEmail() const { return email; }

// Wyświetlanie danych kontaktu

void Display() const
{
    
    std::cout <<"Imię: " <<name << "\nNazwisko: " << surname << "\nNumer Telefonu: "<< phone_number << "\nEmail: " << email << "\n";
}

// Definicja operatora <<
std::ostream& operator<<(std::ostream& os, const Contact& contact) 
{
    os << contact.name << "," 
       << contact.surname << "," 
       << contact.phoneNumber << "," 
       << contact.email;
    return os;
}


};

//Klasa PhoneBook

class PhoneBook
{
    private:

    std::vector<Contact> contacts; // Wektor do przechowywania listy kontaktów
    
    public:
    
    // Dodawanie kontaktu do PhoneBook
    void AddContact(const Contact& contact)
    {
        contacts.push_back(contact);
    }

    // Wyswietlanie kontaktów
    void DisplayContacts() const 
    {
        if(contacts.empty())
        {
            std::cout << "Brak kontaktów w książce telefonicznej.\n";
            return;
        }

        std::cout << "Lista kontaktów:\n";
        for(const auto& contact : contacts)
        {
            contact.Display();
        }

    }

    void SearchBySurname(const std::string& surname) const
    {
        bool found = false;

        for(const auto& contact : contacts)
        {
            if (contact.getSurname() == surname)
            {
                contact.Display();
                found = true;
            }
        }

        if (!found)
        {
            std::cout << "Nie znaleziono kontaktu o nazwisku: " << surname << "\n";
        }
    }

    // Sortowanie kontaktów po nazwisku
    void sortContactsBySurname() 
    {
        std::sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) 
        {
            return a.getSurname() < b.getSurname();
        });

    std::cout << "Kontakty zostały posortowane alfabetycznie po nazwisku." << std::endl;
    }


    // Usuwanie kontaktu - numer tel

    void RemoveByPhone(const std::string& phone_number)
    {
        auto it = std::find_if(contacts.begin(), contacts.end(), [&](const Contact& contact) 
        {
            return contact.getPhoneNumber() == phone_number; 
        });

        if (it != contacts.end())
        {
            std::cout<< "Usuwanie Kontaktu: \n";
            it->Display();
            contacts.erase(it);
            std::cout << "Kontakt został usunięty.\n";
        }
        else
        {
            std::cout<<"Nie znaleziono kontaktu o numerze telefonu: " << phone_number << '\n';
        }
    }



    //Zapisywanie kontaktów(danych) do pliku 

    void SaveToFile(const std::string& filename) const 
    {
    std::ofstream file(filename);  // Zmieniono std::ifstream na std::ofstream

    if (!file.is_open()) 
    {
        std::cerr << "Nie można otworzyć pliku do zapisu!" << '\n';
        return;
    }

    for (const auto& contact : contacts) 
    {
        file << contact << '\n';  // Użycie przeciążonego operatora <<
    }

    std::cout << "Kontakty zostały zapisane do pliku: " << filename << '\n';
    file.close();
}



    void LoadFromFile(const std::string& filename)
    {
        std::ifstream file(filename);

        if (!file.is_open())
        {
            std::cerr << "Nie można otworzyć pliku do odczytu!" << '\n';
        return;
        }

        contacts.clear();
        std::string line;

        while (std::getline(file, line))
        {
            std::istringstream ss(line);
            std::string name, surname, phone_number, email;

            std::getline(ss, name, ',');
            std::getline(ss, surname, ',');
            std::getline(ss, phone_number, ',');
            std::getline(ss, email, ',');

            contacts.emplace_back(name, surname, phone_number, email);
        }

        std::cout << "Kontakty zostały wczytane z pliku: " << filename << '\n';
        file.close();
    
    }


};





int main()
{

PhoneBook phoneBook;

    // Wczytanie kontaktów z pliku
    phoneBook.LoadFromFile("contacts.txt");

    // Wyświetlenie kontaktów
    std::cout << "Kontakty po wczytaniu z pliku:" << std::endl;
    phoneBook.DisplayContacts();

    // Dodanie nowego kontaktu
    phoneBook.AddContact(Contact("Jan", "Kowalski", "123-456-789", "jan.kowalski@example.com"));

    // Zapisanie kontaktów do pliku
    phoneBook.SaveToFile("contacts.txt");

    return 0;


}

*/


#include "phone.h"
#include <iostream>

void displayMenu() 
{
    std::cout << "\nKsiążka telefoniczna - MENU \n\n";
    std::cout << "1. Dodaj kontakt\n";
    std::cout << "2. Wyświetl kontakty\n";
    std::cout << "3. Zapisz kontakty do pliku\n";
    std::cout << "4. Wczytaj kontakty z pliku\n";
    std::cout << "5. Wyszukaj kontakt\n";
    std::cout << "6. Wyjście\n";
    std::cout << "Wybierz opcję: ";
}

int main() 
{
    PhoneBook phoneBook;
    int choice;

    phoneBook.addContact(Contact("John", "Doe", "123456789", "john.doe@example.com"));
    phoneBook.addContact(Contact("Jane", "Smith", "987654321", "jane.smith@example.com"));
    phoneBook.addContact(Contact("Alice", "Brown", "555666777", "alice.brown@example.com"));
    phoneBook.addContact(Contact("Bob", "Johnson", "111222333", "bob.johnson@example.com"));


    do 
    {
        displayMenu();
        std::cin >> choice;

        switch (choice) 
        {
            case 1: 
            {
                std::cin.ignore(); // Oczyszczenie strumienia wejściowego
                std::string name, surname, phoneNumber, email;

                std::cout << "Podaj imię: ";
                std::getline(std::cin, name);
                std::cout << "Podaj nazwisko: ";
                std::getline(std::cin, surname);
                std::cout << "Podaj numer telefonu: ";
                std::getline(std::cin, phoneNumber);
                std::cout << "Podaj email: ";
                std::getline(std::cin, email);

                phoneBook.addContact(Contact(name, surname, phoneNumber, email));
                break;
            }

            case 2:
            {
                phoneBook.displayContacts();
                break;
            }

            case 3: 
            {
                std::string filename;
                std::cout << "Podaj nazwę pliku do zapisu: ";
                std::cin >> filename;
                phoneBook.saveToFile(filename);
                break;
            }

            case 4: 
            {
                std::string filename;
                std::cout << "Podaj nazwę pliku do odczytu: ";
                std::cin >> filename;
                phoneBook.loadFromFile(filename);
                break;
            }

            case 5:
            {
                std::cin.ignore();
                std::string keyword;
                std::cout << "Podaj słowo do wyszukiwania: ";
                std::getline(std::cin, keyword);
                phoneBook.searchContact(keyword);
                break;
            }

            case 6:
            {
                std::cout << "Zamykanie programu...\n";
                break;
            }

            default:
            {
                std::cout << "Niepoprawna opcja. Spróbuj ponownie.\n";
            }
        }
    } while (choice != 6);

    return 0;
}
