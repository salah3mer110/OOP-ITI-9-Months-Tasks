#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int numOfLines, lineLength;
    cout << "Enter number of lines:\n";
    cin >> numOfLines;
    cout << "Enter line length:\n";
    cin >> lineLength;

    char** lines = new char* [numOfLines];
    int* lengths = new int[numOfLines]; 

    for (int i = 0; i < numOfLines; i++) {
        lines[i] = new char[lineLength];
        for (int j = 0; j < lineLength; j++)
            lines[i][j] = ' ';
        lengths[i] = 0;
    }

    int currLine = 0;
    int cursor = 0;

    while (true) {
        system("cls");

        cout << "\033[36m";
        for (int i = 0; i < numOfLines; i++) {
            for (int j = 0; j < lineLength; j++)
                cout << lines[i][j];
            cout << "\n";
        }
        cout << "\033[0m";

        cout << "\033[" << currLine + 1 << ";" << cursor + 1 << "H";

        int key = _getch();
        int length = lengths[currLine];

        if (key >= 32 && key <= 126) {
            if (cursor < lineLength) {
                lines[currLine][cursor] = key;

                if (cursor == length)
                    lengths[currLine]++;

                if (cursor < lineLength - 1)
                    cursor++;
            }
        }
        else {
            if (key == 0 || key == 224) key = _getch();

            switch (key) {
            case 75://left
                if (cursor > 0) cursor--;
                break;
            case 77://rigt
                if (cursor < lengths[currLine]) cursor++;
                break;
            case 71://Home
                cursor = 0;
                break;
            case 79://end
                cursor = lengths[currLine];
                if (cursor >= lineLength) cursor = lineLength - 1;
                break;
            case 83://delete
                if (cursor < lengths[currLine]) {
                    for (int i = cursor; i < lengths[currLine] - 1; i++)
                        lines[currLine][i] = lines[currLine][i + 1];
                    lines[currLine][lengths[currLine] - 1] = ' ';
                    lengths[currLine]--;
                }
                break;
            case 80://down
                if (currLine < numOfLines - 1) {
                    currLine++;
                    if (cursor > lengths[currLine])
                        cursor = lengths[currLine];
                }
                break;
            case 72://up
                if (currLine > 0) {
                    currLine--;
                    if (cursor > lengths[currLine])
                        cursor = lengths[currLine];
                }
                break;
            case 27://esc
                for (int i = 0; i < numOfLines; i++)
                    delete[] lines[i];
                delete[] lines;
                delete[] lengths;
                return 0;
            }
        }
    }
}
