#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

const int box_w = 50;
const int txt_w = box_w - 2;

// bt7rk el cursor l ay mkan fl console
void goto_xy(int r, int c) {
    cout << "\033[" << r << ";" << c << "H";
}

// btrsm el box fl console bl color yellow background w border
void draw_box(int r, int c) {
    goto_xy(r, c);
    cout << '+';
    for (int i = 0; i < box_w - 2; ++i) cout << '-';
    cout << '+';

    goto_xy(r + 1, c);
    cout << '|';
    cout << "\033[43;30m"; // yellow bg, black text
    for (int i = 0; i < txt_w; ++i) cout << ' ';
    cout << "\033[0m";
    cout << '|';

    goto_xy(r + 2, c);
    cout << '+';
    for (int i = 0; i < box_w - 2; ++i) cout << '-';
    cout << '+';
}

// bta3ml render lel text fl box w t7ot el cursor f makan l sa7
void show_txt(const string &text, int cur, int r, int c) {
    goto_xy(r + 1, c + 1);
    cout << "\033[43;30m";
    for (int i = 0; i < txt_w; ++i) {
        if (i < (int)text.size()) cout << text[i];
        else cout << ' ';
    }
    cout << "\033[0m";
    goto_xy(r + 1, c + 1 + cur);
    cout.flush();
}

int main() {
    string text;
    text.reserve(txt_w);
    int cur = 0;

    int row = 5, col = 10;

    draw_box(row, col);
    show_txt(text, cur, row, col);

    bool run = true;
    while (run) {
        int ch = _getch();
        if (ch == 0 || ch == 224) { // extended keys
            int ext = _getch();
            switch (ext) {
                case 75: if (cur > 0) cur--; break; // left arrow
                case 77: if (cur < (int)text.size()) cur++; break; // right arrow
                case 71: cur = 0; break; // home
                case 79: cur = text.size(); break; // end
                case 83: // delete -> يمسح اللي على يمين cursor
                    if (cur < (int)text.size()) {
                        text.erase(cur, 1);
                    }
                    break;
            }
        } else {
            if (ch == 13 || ch == 27) run = false; // enter or esc -> exit
            else if (ch == 8) { // backspace
                if (cur > 0) {
                    text.erase(cur - 1, 1);
                    cur--;
                }
            }
            else if (ch >= 32 && ch <= 126) { // printable
                if ((int)text.size() < txt_w) {
                    text.insert(text.begin() + cur, ch);
                    cur++;
                }
            }
        }
        show_txt(text, cur, row, col);
    }

    goto_xy(row + 4, 0);
    cout << "\nfinal text: " << text << endl;

    return 0;
}
