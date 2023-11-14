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

Birthdate inputPersonBirthdate(){
    Birthdate personBirthdate;
    cout << "Enter your birthdate";
    cout << endl;
    personBirthdate.day = readDay();
    personBirthdate.month = readMonth();
    personBirthdate.year = readYear();
    return personBirthdate;
}

string inputPersonName(){
    string personName;
    cout << "Enter the name:";
    cin >> personName;
    cout << "Hello, " << personName;
    cout << endl;
    return personName;
}

void inputPersons(){
    int option = 1;
    do {
        person.name = inputPersonName();
        person.birthdate = inputPersonBirthdate();
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

void displayAllPersons(){
    for (int i = 0; i < n; i++) {
        displayPerson(persons[i]);
    }
}

void searchPersonByDay(int dayToSearch){
    for (int i = 0; i < n; i++) {
        if (persons[i].birthdate.day == dayToSearch) {
            displayPerson(persons[i]);
        }
    }
}

void searchPersonByMonth(int monthToSearch){
    for (int i = 0; i < n; i++) {
        if (persons[i].birthdate.month == monthToSearch) {
            displayPerson(persons[i]);
        }
    }
}

void searchPersonByYear(int yearToSearch){
    for (int i = 0; i < n; i++) {
        if (persons[i].birthdate.year == yearToSearch) {
            displayPerson(persons[i]);
        }
    }
}

void searchPersonByBirthdate(Birthdate personBirthdate){
    for (int i = 0; i < n; i++) {
        if (
                persons[i].birthdate.year == personBirthdate.year
                &&
                persons[i].birthdate.month == personBirthdate.month
                &&
                persons[i].birthdate.day == personBirthdate.day
        ) {
            displayPerson(persons[i]);
        }
    }
}

int main() {

    inputPersons();
    displayAllPersons();

    int day;
    cout << "Introduce the day of the month:" << endl;
    cin >> day;
    searchPersonByDay(day);


    int month;
    cout << "Introduce the month of the year:" << endl;
    cin >> month;
    searchPersonByMonth(month);

    int year;
    cout << "Introduce the year:" << endl;
    cin >> year;
    searchPersonByYear(year);


    Birthdate birthdate;
    birthdate = inputPersonBirthdate();
    searchPersonByBirthdate(birthdate);

    return 0;
}
