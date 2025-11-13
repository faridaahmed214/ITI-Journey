#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
    int size;
    cout << "enter magic box size ";
    cin >> size;

    if (size % 2 == 0) {
        cout << "please enter an odd number";
    } else {
        cout << "\033[2J";
        int row = 1;
        int column = (size + 1) / 2;
        int startRow = 5;
        int startCol = 40;

        for (int i = 1; i <= size * size; i++) {
            int screenRow = startRow + (row - 1) * 2;
            int screenCol = startCol + (column - 1) * 6;
            int color = (i % 7) + 1;

            cout << "\033[" << screenRow << ";" << screenCol << "H";
            cout << "\033[3" << color << "m" << i << "\033[0m";
            cout.flush();
            usleep(150000);

            if ((i % size) != 0) {
                row--;
                column--;
                if (row < 1) row = size;
                if (column < 1) column = size;
            } else {
                row++;
                if (row > size) row = 1;
            }
        }

        cout << "\033[0m";
        cout << "\033[" << (startRow + size * 2) << ";0H";
    }

    return 0;
}
