
#include <iostream>
#include <vector>
#include <limits>

#include "test_graphs.cpp"
#include "vertex.h"
#include "edge.h"
#include "graph.h"


using namespace std;


void show_menu() {
    cout << "GRAPH MENU\n" 
    "1. Test Simple Graph\n"
    "2. Test Binary Tree\n"
    "3. Simple Spanning Tree\n"
    "4. Choice 4\n"
    "5. Display Menu\n"
    "6. Quit\n" 
    << endl;
}


int main() {

    show_menu();
    while(1) {

        int menu_choice;
        int menu_max = 6;

        if(cin >> menu_choice && menu_choice <= menu_max && menu_choice >= 1) {

            switch (menu_choice) {
            case 1:

                cout << "simple_graph_test" << endl;
                simple_graph_test();
                break;
            case 2:
                cout << "bin_tree_test" << endl;
                bin_tree_test();
                break;  
            case 3:
                cout << "simple_span_tree" << endl;
                simple_span_tree_test();
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
                break;
            }

        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please choose a number between 1 - " << menu_max << endl;
            cout << endl;
        }
    }
    return 0;
}
