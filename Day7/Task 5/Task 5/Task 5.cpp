#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;

int main()
{
    int numOfLines, lineLength;
    cin >> numOfLines >> lineLength;

    char** lines = new char* [numOfLines];
    for (int i = 0; i < numOfLines; i++) {
        lines[i] = new char[lineLength + 1];
        for (int j = 0; j < lineLength; j++)
            lines[i][j] = ' ';

        lines[i][0] = '\0';
    }

    int currLine = 0;
    int cursor = 0;

    while (true) {
        system("cls");

        cout << "\033[36m";
        for (int i = 0; i < numOfLines; i++)
            cout << lines[i] << "\n";
        cout << "\033[0m";

        cout << "\033[H";
        cout << "\033[" << currLine + 1 << ";" << cursor + 1 << "H";

        int length = strlen(lines[currLine]);
        int key = _getch();

        if (key >= 32 && key <= 126) {
            if (cursor < lineLength) {
                lines[currLine][cursor] = key;
                if (cursor == length) lines[currLine][cursor + 1] = '\0';
                cursor++;
            }
        }
        else {
            if (key == 0 || key == 224) key = _getch();

            switch (key) {
            case 75:
                if (cursor > 0) cursor--;
                break;
            case 77:
                if (cursor < strlen(lines[currLine])) cursor++;
                break;
            case 71:
                cursor = 0;
                break;
            case 79:
                cursor = strlen(lines[currLine]);
                break;
            case 83:
                if (cursor < strlen(lines[currLine])) {
                    for (int i = cursor; i < strlen(lines[currLine]); i++)
                        lines[currLine][i] = lines[currLine][i + 1];
                }
                break;
            case 80:
                if (currLine < numOfLines - 1) {
                    currLine++;
                    if (cursor > strlen(lines[currLine]))
                        cursor = strlen(lines[currLine]);
                }
                break;
            case 72:
                if (currLine > 0) {
                    currLine--;
                    if (cursor > strlen(lines[currLine]))
                        cursor = strlen(lines[currLine]);
                }
                break;
            case 27:
                for (int i = 0; i < numOfLines; i++) delete[] lines[i];
                delete[] lines;
                return 0;
            }
        }
    }
}
