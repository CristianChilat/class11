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

// age
// who is older
// who is younger
// persons older than
// persons in alphabetical order
// persons order by age
// persons with same age


int dateDifference (Birthdate firstDate, Birthdate secondDate) {
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30 , 31, 31, 30, 31 ,30, 31};
    int month = 0;
    int daysPassedFirstDate = 0;
    while (month < firstDate.month) {
        daysPassedFirstDate += daysInMonth[month - 1];
        month++;
    }
    daysPassedFirstDate += firstDate.day;

    month = 0;
    int daysPassedSecondDate = 0;
    while(month < secondDate.month) {
        daysPassedSecondDate += daysInMonth[month - 1];
        month++;
    }
    daysPassedSecondDate += secondDate.day;
    daysPassedSecondDate += (secondDate.year -  firstDate.year) * 365;

    for (int year = firstDate.year - 1; year <= secondDate.year - 1; year++) {
        if (year % 4 == 0 && year % 100 != 0) {
            daysPassedSecondDate++;
        }
    }

    return daysPassedSecondDate - daysPassedFirstDate;
}

// Jan = 31
// Feb = 28

// Start Date = 31.01.2023 => 31 = 31
// End date = 01.02.2023 => 32 = 1 * 31 + 1

// Start Date = 31.01.2023 => 31 = 31
// End date = 05.02.2023 => 36 = 1 * 31 + 5

// Start Date = 10.01.2023 => 10 = 10
// End date = 15.03.2023 => ? = 1 * 31 + 1 * 28 + 15

int main() {

//    Birthdate startDate = {.day = 20, .month = 4, .year = 2006};
//    Birthdate endDate = {.day = 20, .month = 11, .year = 2023};
//
//    cout << dateDifference(startDate, endDate);

//    inputPersons();
//    displayAllPersons();
//
//    int day;
//    cout << "Introduce the day of the month:" << endl;
//    cin >> day;
//    searchPersonByDay(day);
//
//
//    int month;
//    cout << "Introduce the month of the year:" << endl;
//    cin >> month;
//    searchPersonByMonth(month);
//
//    int year;
//    cout << "Introduce the year:" << endl;
//    cin >> year;
//    searchPersonByYear(year);
//
//
//    Birthdate birthdate;
//    birthdate = inputPersonBirthdate();
//    searchPersonByBirthdate(birthdate);

    persons[0] = {
            .name = "Cristi",
            .birthdate = {
                    .day = 20,
                    .month = 4,
                    .year = 2006
            }
    };

    persons[1] = {
            .name = "Sergiu",
            .birthdate = {
                    .day = 23,
                    .month = 7,
                    .year = 1984
            }
    };

    persons[2] = {
            .name = "Cristina",
            .birthdate = {
                    .day = 24,
                    .month = 9,
                    .year = 1985
            }
    };

    Birthdate currentDate = {.day = 20, .month = 11, .year = 2023};

    int youngestPersonIndex = 0;
    int oldestPersonIndex = 0;
    for (int i = 0; i < 3; i++) {
        cout << persons[i].name << " = " << dateDifference(persons[i].birthdate, currentDate) << endl;
        if (dateDifference(persons[youngestPersonIndex].birthdate, persons[i].birthdate) > 0){
            youngestPersonIndex = i;
        }

        if (dateDifference(persons[oldestPersonIndex].birthdate, persons[i].birthdate) < 0){
            oldestPersonIndex = i;
        }
    }

    cout << "The youngest person is: " << persons[youngestPersonIndex].name << " = " << dateDifference(persons[youngestPersonIndex].birthdate, currentDate) << endl;
    cout << "The oldest person is: " << persons[oldestPersonIndex].name << " = " << dateDifference(persons[oldestPersonIndex].birthdate, currentDate) << endl;



    return 0;
}
