#include <iostream>

using namespace::std;

struct Birthdate{
    int day;
    int month;
    int year;
};

struct Person{
    string name;
    Birthdate birthdate;
};

Person persons[50];
Person person = {};
int n = 0;

int readDay(){
    int day = 0;
    do {
        cout << "Day:";
        cin >> day;
        if (day < 0 || day > 31 ) {
            cout << "Wrong day!" << endl;
        }
    } while (day < 0 || day > 31);

    return day;
}

int readMonth() {
    int month = 0;
    do {
        cout << "Month:";
        cin >> month;
        if (month < 0 || month > 12) {
            cout << "Wrong month!" << endl;
        }
    } while (month < 0 || month > 12);
    return month;
}

int readYear() {
    int year = 0;
    do {
        cout << "Year:";
        cin >> year;
        if (year < 0 || year > 2023) {
            cout << "Wrong year!" << endl;
        }
    } while (year < 0 || year > 2023);
    return year;
}

void inputPersons(){
    int option = 1;
    do {
        cout << "Enter the name:";
        cin >> person.name;
        cout << "Hello, " << person.name;
        cout << endl;
        cout << "Enter your birthdate";
        cout << endl;
        person.birthdate.day = readDay();
        person.birthdate.month = readMonth();
        person.birthdate.year = readYear();
        persons[n] = person;
        n++;
        cout << "1 - continue, 0 - finish input:";
        cin >> option;
    } while(option == 1);
}

void displayPerson(Person person) {
    cout << "----------------" << endl;
    cout << "Name: " << person.name << endl;
    cout << "Birthdate: " << person.birthdate.day << "." << person.birthdate.month << "." << person.birthdate.year << endl;
}

int main() {

    inputPersons();

    for (int i = 0; i < n; i++) {
        displayPerson(persons[i]);
    }

    int day;
    cout << "Introduce the day of the month:" << endl;
    cin >> day;
    for (int i = 0; i < n; i++) {
        if (persons[i].birthdate.day == day) {
            displayPerson(persons[i]);
        }
    }


    int month;
    cout << "Introduce the month of the year:" << endl;
    cin >> month;
    for (int i = 0; i < n; i++) {
        if (persons[i].birthdate.month == month) {
            displayPerson(persons[i]);
        }
    }

    int year;
    cout << "Introduce the year:" << endl;
    cin >> year;
    for (int i = 0; i < n; i++) {
        if (persons[i].birthdate.year == year) {
            displayPerson(persons[i]);
        }
    }

    return 0;
}
