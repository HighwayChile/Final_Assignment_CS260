#include <iostream>
#include <vector>
#include <limits>

#include "vertex.cpp"
#include "edge.cpp"
#include "vertex.h"
#include "edge.h"


using namespace std;


void show_menu() {
    cout << "Welcome to the menu\n" 
    "1. Choice 1\n"
    "2. Choice 2\n"
    "3. Choice 3\n"
    "4. Choice 4\n"
    "5. Display Menu\n"
    "6. Quit\n" 
    << endl;
}


int main() {

    // What do I want to do for the main???
    // break time.
    show_menu();
    while(1) {

        int menu_choice;

        if(cin >> menu_choice) {
            cin.ignore();

            switch (menu_choice) {
            case 1:
                cout << "case 1 chosen" << endl;
                break;
            case 2:
                cout << "case 2 chosen" << endl;
                break;  
            case 3:
                cout << "case 3 chosen" << endl;
                break;
            case 4:
                cout << "case 4 chosen" << endl;
                break;
            case 5:
                cout << "case 5 chosen(Display Menu)" << endl;
                show_menu();
                break;
            case 6:
                cout << "case 6 chosen(Quit)" << endl;
                system("pause");
                return 0;
                break;  
            
            default:
                // cout << "PLEASE CHOOSE VALID INPUT" << endl;
                break;
            }

        }
    }
    return 0;
}
