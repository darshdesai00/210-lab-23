#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

// menu function
int main_menu() {
    int choice = 0;

    do {
        cout << endl;
        cout << "*** GOAT MANAGER 3001 ***" << endl;
        cout << " [1] Add a goat" << endl;
        cout << " [2] Delete a goat" << endl;
        cout << " [3] List goats" << endl;
        cout << " [4] Quit" << endl;
        cout << " Choice --> ";
        cin >> choice;

        if (choice < 1 || choice > 4) {
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice < 1 || choice > 4);

    return choice;   // ✅ END OF main_menu()
}                    // ← you were missing this brace!

// main function
int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();

    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    // this is the goat trip list
    list<Goat> trip;
    int choice;

    // main menu loop
    do {
        choice = main_menu();

           switch (choice) {
            case 1: 
                cout << "You chose to add a goat." << endl;
                break;
            case 2:
                cout << "You chose to delete a goat." << endl;
                break;
            case 3:
                cout << "You chose to list goats." << endl;
                break;
            case 4: 
                cout << "Goodbye :)" << endl;
        break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 4);

    return 0;
}