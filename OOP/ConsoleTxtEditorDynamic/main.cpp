#include <iostream>
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

// render text inside box and move cursor
void show_text(char* text, int len, int cur, int r, int c) {
    goto_xy(r + 1, c + 1);
    cout << "\033[43;30m";
    for (int i = 0; i < txt_w; ++i) {
        if (i < len) cout << text[i];
        else cout << ' ';
    }
    cout << "\033[0m";
    goto_xy(r + 1, c + 1 + cur);
    cout.flush();
}

int main() {
    char* text = new char[txt_w];
    int len = 0;
    int cur = 0;

    int row = 5, col = 10;

    draw_box(row, col);
    show_text(text, len, cur, row, col);

    bool run = true;
    while (run) {
        int ch = _getch();
        if (ch == 0 || ch == 224) {
            int ext = _getch();
            switch (ext) {
                case 75: if (cur > 0) cur--; break;           // left arrow
                case 77: if (cur < len) cur++; break;        // right arrow
                case 71: cur = 0; break;                     // home
                case 79: cur = len; break;                   // end
                case 83: if (cur < len) {                    // delete
                            for (int i = cur; i < len - 1; i++)
                                text[i] = text[i + 1];
                            len--;
                        }
                        break;
            }
        } else {
            if (ch == 13 || ch == 27) run = false; // enter or esc -> exit
            else if (ch == 8) { // backspace
                if (cur > 0) {
                    for (int i = cur - 1; i < len - 1; i++)
                        text[i] = text[i + 1];
                    cur--;
                    len--;
                }
            } else if (ch >= 32 && ch <= 126) {
                if (len < txt_w) {
                    for (int i = len; i > cur; i--)
                        text[i] = text[i - 1];
                    text[cur] = ch;
                    cur++;
                    len++;
                }
            }
        }
        show_text(text, len, cur, row, col);
    }

    goto_xy(row + 4, 0);
    cout << "\nfinal text: ";
    for (int i = 0; i < len; i++) cout << text[i];
    cout << endl;

    delete[] text; // free memory
    return 0;
}
