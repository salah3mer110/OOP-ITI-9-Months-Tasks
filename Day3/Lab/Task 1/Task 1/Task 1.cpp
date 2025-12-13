#include <iostream>
#include <array>
#include <conio.h>

using namespace std;

int main()
{
    array<string, 4> arr = { "New", "Display", "Display all", "Exit" };
    int choice = 0;

    while (true) {
        cout << "\033[0;15HEmployee Form\n";
        cout << "------------------------------------------------\n";
        //print
        for (int i = 0; i < arr.size(); i++) {
            if (i == choice)
                cout << "\033[" << i + 4 << ";7H\033[31m" << i + 1 << ". " << arr[i] << "\033[0m\n";
            else
                cout << "\033[" << i + 4 << ";7H" << i + 1 << ". " << arr[i] << "\n";
        }
        int key = _getch();
        if (key == 27) {//exit
            system("cls");
            cout << "bye bye :)\n";
            return 0;
        }

        switch (key) {
        case 80://down 
            if (choice < 3) {
                choice++;
                system("cls");
            }
            break;
        case 72: //up
            if (choice > 0) {
                choice--;
                system("cls");
            }
            break;
        case 13: //enter
            if (choice == 3) {//exit
                system("cls");
                cout << "bye bye :)\n";
                return 0;
            }
            system("cls");
            cout << "You have selected: " << arr[choice] << endl;
                return 0;
        }
    }
}
