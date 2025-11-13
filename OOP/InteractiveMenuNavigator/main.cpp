#include <iostream>
#include <conio.h>
#include <array>

using namespace std;

int main() {

    string menu[] = {"new", "display", "display all", "exit"};
    int n = 4;
    int selected = 0;
    int startRow = 5, startCol = 10;
    cout << "\033[2J";
    cout.flush();
    while (true) {
        cout << "\033[1;1HUse up and down arrows in your keyboard, Enter to select, ESC to exit\n";
        for (int i = 0; i < n; i++) {
            int row = startRow + i;
            int col = startCol;
            cout << "\033[" << row << ";" << col << "H";

            if (i == selected)
                cout << "\033[31m> " << menu[i] << "\033[0m";
            else
                cout << "  " << menu[i];
        }
        cout.flush();
        int c = _getch();
        if (c == 0 || c == 224) {
            int code = _getch();
            if (code == 72)
                selected = (selected - 1 + n) % n;
            else if (code == 80)
                selected = (selected + 1) % n;
        }
        else if (c == 13) {
            cout << "\033[2J\033[H";
            cout << "You pressed " << menu[selected] << "\n";
            if (menu[selected] == "exit") {
                cout << "bye bye\n";
                break;
            } else {
                cout << "\n(press any key to return to menu)";
                _getch();
                cout << "\033[2J\033[H";
            }
        }
        else if (c == 27) {
            cout << "\033[2J\033[H";
            cout << "bye bye\n";
            break;
        }
    }
    cout << "\033[0m";
    return 0 ;}
