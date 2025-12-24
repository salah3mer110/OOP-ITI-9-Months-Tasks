#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int size;
    cout << "Enter line length" << endl;
    cin >> size;
    char *line=new char[size];
    for (int i = 0; i < size; i++)
        line[i] = ' ';

    int cursor = 0;
    int length = 0;

    while (true)
    {
        system("cls");
        cout << "\033[36m";
        for (int i = 0; i < size; i++)
            cout << line[i];
        cout << "\033[0m";

        cout << "\033[H";
        cout << "\033[1;" << cursor + 1 << "H";

        int key = _getch();

        if (key >= 32 && key <= 126)
        {
            line[cursor] = key;
            if (cursor < size - 1) cursor++;
            if (length < size) length++;
        }
        else
        {
            if (key == 0 || key == 224) key = _getch();

            switch (key)
            {
            case 75: // left
                if (cursor > 0) cursor--;
                break;
            case 77: // right
                if (cursor < length) cursor++;
                break;
            case 71: // home
                cursor = 0;
                break;
            case 79: // end
                cursor = length;
                break;
            case 83: // delete
                if (cursor < length)
                {
                    for (int i = cursor; i < length - 1; i++)
                        line[i] = line[i + 1];
                    line[length - 1] = ' ';
                    length--;
                }
                break;
            }
        }
    }
}
