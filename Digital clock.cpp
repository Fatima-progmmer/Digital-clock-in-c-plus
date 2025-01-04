#include<iostream>
#include<conio.h>
#include<windows.h>
#include<time.h>

using namespace std;

// Digit Declarations - These are ASCII art numbers using block character (219)
char d0[5][3] = {
    {(char)219, (char)219, (char)219},
    {(char)219, ' ', (char)219},
    {(char)219, ' ', (char)219},
    {(char)219, ' ', (char)219},
    {(char)219, (char)219, (char)219}
};

char d1[5][3] = {
    {' ', ' ', (char)219},
    {' ', ' ', (char)219},
    {' ', ' ', (char)219},
    {' ', ' ', (char)219},
    {' ', ' ', (char)219}
};

char d2[5][3] = {
    {(char)219, (char)219, (char)219},
    {' ', ' ', (char)219},
    {(char)219, (char)219, (char)219},
    {(char)219, ' ', ' '},
    {(char)219, (char)219, (char)219}
};

char d3[5][3] = {
    {(char)219, (char)219, (char)219},
    {' ', ' ', (char)219},
    {(char)219, (char)219, (char)219},
    {' ', ' ', (char)219},
    {(char)219, (char)219, (char)219}
};

char d4[5][3] = {
    {(char)219, ' ', (char)219},
    {(char)219, ' ', (char)219},
    {(char)219, (char)219, (char)219},
    {' ', ' ', (char)219},
    {' ', ' ', (char)219}
};

char d5[5][3] = {
    {(char)219, (char)219, (char)219},
    {(char)219, ' ', ' '},
    {(char)219, (char)219, (char)219},
    {' ', ' ', (char)219},
    {(char)219, (char)219, (char)219}
};

char d6[5][3] = {
    {(char)219, (char)219, (char)219},
    {(char)219, ' ', ' '},
    {(char)219, (char)219, (char)219},
    {(char)219, ' ', (char)219},
    {(char)219, (char)219, (char)219}
};

char d7[5][3] = {
    {(char)219, (char)219, (char)219},
    {' ', ' ', (char)219},
    {' ', ' ', (char)219},
    {' ', ' ', (char)219},
    {' ', ' ', (char)219}
};

char d8[5][3] = {
    {(char)219, (char)219, (char)219},
    {(char)219, ' ', (char)219},
    {(char)219, (char)219, (char)219},
    {(char)219, ' ', (char)219},
    {(char)219, (char)219, (char)219}
};

char d9[5][3] = {
    {(char)219, (char)219, (char)219},
    {(char)219, ' ', (char)219},
    {(char)219, (char)219, (char)219},
    {' ', ' ', (char)219},
    {(char)219, (char)219, (char)219}
};

// Colon separator
char ep[5][3] = {
    {' ', ' ', ' '},
    {' ', (char)219, ' '},
    {' ', ' ', ' '},
    {' ', (char)219, ' '},
    {' ', ' ', ' '}
};

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printDigit(int no, int x, int y) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 3; j++) {
            gotoxy(x + j, y + i);
            switch(no) {
                case 0: cout << d0[i][j]; break;
                case 1: cout << d1[i][j]; break;
                case 2: cout << d2[i][j]; break;
                case 3: cout << d3[i][j]; break;
                case 4: cout << d4[i][j]; break;
                case 5: cout << d5[i][j]; break;
                case 6: cout << d6[i][j]; break;
                case 7: cout << d7[i][j]; break;
                case 8: cout << d8[i][j]; break;
                case 9: cout << d9[i][j]; break;
                case 10: cout << ep[i][j]; break;
            }
        }
    }
}

void draw_border(int x = 0, int y = 0) {
    char v = 186;
    char h = 205;
    char tr = 187;
    char br = 188;
    char tl = 201;
    char bl = 200;
    int width = 50;
    int height = 11;
    
    gotoxy((width/2) + x - 11, y);
    cout << "C U R R E N T  T I M E";
    
    for(int i = 0; i <= height; i++) {
        for(int j = 0; j <= width; j++) {
            gotoxy(j + x, i + y);
            if(i == 0 && j == 0) cout << tl;
            else if(i == height && j == 0) cout << bl;
            else if(i == 0 && j == width) cout << tr;
            else if(i == height && j == width) cout << br;
            else if(i == 0 || i == height) cout << h;
            else if(j == 0 || j == width) cout << v;
        }
    }
}

void printDate(int x, int y) {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    
    gotoxy(x, y);
    cout << ltm->tm_mday << "/" 
         << ltm->tm_mon + 1 << "/" 
         << ltm->tm_year + 1900;
}

// Main function with AM/PM and date additions
int main() {
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);

    int gap = 4;
    int posX;
    int posY = 8;

    while(1) {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        
        // Convert to 12-hour format
        int hour = ltm->tm_hour;
        string period = (hour >= 12) ? "PM" : "AM";
        hour = (hour > 12) ? hour - 12 : hour;
        hour = (hour == 0) ? 12 : hour;
        
        int min = ltm->tm_min;
        int sec = ltm->tm_sec;

        system("cls");
        draw_border(9, 4);
        posX = 15;

        if(kbhit()) {
            char ch = getch();
            if(ch == 27) {
                break;
            }
        }

        // Print hours
        if(hour < 10) {
            printDigit(0, posX, posY);
            printDigit(hour, posX + gap, posY);
            posX += (gap * 2);
        } else {
            printDigit(hour/10, posX, posY);
            printDigit(hour%10, posX + gap, posY);
            posX += (gap * 2);
        }

        printDigit(10, posX, posY);
        posX += gap;

        // Print minutes
        if(min < 10) {
            printDigit(0, posX, posY);
            printDigit(min, posX + gap, posY);
            posX += (gap * 2);
        } else {
            printDigit(min/10, posX, posY);
            printDigit(min%10, posX + gap, posY);
            posX += (gap * 2);
        }

        printDigit(10, posX, posY);
        posX += gap;

        // Print seconds
        if(sec < 10) {
            printDigit(0, posX, posY);
            printDigit(sec, posX + gap, posY);
        } else {
            printDigit(sec/10, posX, posY);
            printDigit(sec%10, posX + gap, posY);
        }

        // Print AM/PM
        gotoxy(posX + gap + 4, posY + 2);
        cout << period;

        // Print date below the time
        printDate(posX - 10, posY + 6);

        Sleep(1000);
    }
    return 0;
}