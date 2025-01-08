#include <iostream>
#include <algorithm>
#include <string>
#include "Array.h"
using namespace std;

class Contact {
private:
    string name;
    string phoneNumber;
    string email;

public:
    Contact(const string& name = "", const string& phoneNumber = "", const string& email = "")
        : name(name), phoneNumber(phoneNumber), email(email) {}

    string getName() const {
     return name; 
    }
    string getPhoneNumber() const {
        return phoneNumber;
    }
    string getEmail() const { 
        return email;
    }

    void setName(const string& newName) {
        name = newName;
    }
    void setPhoneNumber(const string& newPhoneNumber) {
        phoneNumber = newPhoneNumber; 
    }
    void setEmail(const string& newEmail) {
        email = newEmail; 
    }

    void printContact() const {
        cout << "Имя: " << name
             << ", Телефон: " << phoneNumber
             << ", Email: " << email << endl;
    }
};

class PhoneBook {
private:
    Array<Contact> contacts;

public:
    void addContact(const Contact& contact) {
        contacts.add(contact);
        sortContactsName();
        cout << "Контакт успешно добавлен!" << endl;
    }

    void removeContact(const string& name) {
        for (int i = 0; i < contacts.size(); i++) {
            if (contacts.at(i).getName() == name) {
                contacts.removeAt(i);
                cout << "Контакт успешно удалён!" << endl;
                return;
            }
        }
        cout << "Контакт не найден!" << endl;
    }

    void searchContacts(const string& q) {
        bool temp = false;
        for (int i = 0; i < contacts.size(); i++) {
            if (contacts.at(i).getName().find(q) != string::npos ||
                contacts.at(i).getPhoneNumber().find(q) != string::npos) {
                contacts.at(i).printContact();
                temp = true;
            }
        }
        if (!temp) {
            cout << "Ничего не найдено." << endl;
        }
    }

    void editContact() {
        string input;
        cout << "Введите имя или номер для поиска контакта: ";
        cin.ignore();
        getline(cin, input);

        for (int i = 0; i < contacts.size(); i++) {
            if (contacts.at(i).getName().find(input) != string::npos ||
                contacts.at(i).getPhoneNumber().find(input) != string::npos) {

                char choice;
                cout << "Контакт найден!" << endl;
                contacts.at(i).printContact();

                cout << "Что вы хотите изменить?" << endl
                     << "1. Имя" << endl
                     << "2. Номер телефона" << endl
                     << "3. Email" << endl
                     << "4. Всё" << endl;
                cin >> choice;

                string n;
                cin.ignore();
                switch (choice) {
                case '1':
                    cout << "Введите новое имя: ";
                    getline(cin, n);
                    contacts.at(i).setName(n);
                    cout << "Имя успешно изменено!" << endl;
                    break;
                case '2':
                    cout << "Введите новый номер телефона: ";
                    getline(cin, n);
                    contacts.at(i).setPhoneNumber(n);
                    cout << "Номер телефона успешно изменён!" << endl;
                    break;
                case '3':
                    cout << "Введите новый email: ";
                    getline(cin, n);
                    contacts.at(i).setEmail(n);
                    cout << "Email успешно изменён!" << endl;
                    break;
                case '4':
                    cout << "Введите новое имя: ";
                    getline(cin, n);
                    contacts.at(i).setName(n);

                    cout << "Введите новый номер телефона: ";
                    getline(cin, n);
                    contacts.at(i).setPhoneNumber(n);

                    cout << "Введите новый email: ";
                    getline(cin, n);
                    contacts.at(i).setEmail(n);
                    cout << "Имя, номер и email успешно изменены!" << endl;
                    break;
                default:
                    cout << "Неверный выбор!" << endl;
                }
                return;
            }
        }
        cout << "Контакт не найден!" << endl;
    }

    void printContacts() {
        if (contacts.size() == 0) {
            cout << "Нет контактов." << endl;
            return;
        }
        for (int i = 0; i < contacts.size(); i++) {
            contacts.at(i).printContact();
        }
    }

    void sortContactsName() {
        for (int i = 0; i < contacts.size() - 1; i++) {
            for (int j = i + 1; j < contacts.size(); j++) {
                if (contacts.at(i).getName() > contacts.at(j).getName()) {
                    swap(contacts[i], contacts[j]);
                }
            }
        }
    }

    int size() const {
        return contacts.size();
    }

    Contact& at(int index) {
        return contacts[index];
    }
};

int main() {
    PhoneBook phonebook;

    while (true) {
        int operation;
        cout << "==============================" << endl
             << "   Телефонная книга " << endl
             << "==============================" << endl;
        cout << "1. Добавить контакт" << endl
             << "2. Удалить контакт" << endl
             << "3. Изменить контакт" << endl
             << "4. Найти контакт" << endl
             << "5. Показать все контакты" << endl
             << "6. Выход" << endl;
        do {
            cout << "Выберите опцию: ";
            cin >> operation;
        } while (operation < 1 || operation > 6);

        if (operation == 1) {
            string name, phone, email;
            cout << "Введите имя: ";
            cin.ignore();
            getline(cin, name);
            cout << "Введите номер телефона: ";
            getline(cin, phone);
            cout << "Введите email: ";
            getline(cin, email);

            phonebook.addContact(Contact(name, phone, email));
        } else if (operation == 2) {
            string name;
            cout << "Введите имя для удаления: ";
            cin.ignore();
            getline(cin, name);
            phonebook.removeContact(name);
        } else if (operation == 3) {
            phonebook.editContact();
        } else if (operation == 4) {
            string query;
            cout << "Введите строку для поиска (имя или номер): ";
            cin.ignore();
            getline(cin, query);

            phonebook.searchContacts(query);
        } else if (operation == 5) {
            cout << "Все контакты:" << endl;
            phonebook.printContacts();
        } else if (operation == 6) {
            cout << "Спасибо за использование телефонной книги!" << endl;
            break;
        }
    }

    return 0;
}
