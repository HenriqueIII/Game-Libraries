#include <curses.h>

class Display{
public:
    Display(){
        initscr();
        raw();
        keypad(stdscr, true);
    }
    ~Display(){
        endwin();
    }
    void refresh();
    void clear();
    void write(const char *);
    int getC();
};

void Display::clear(){
    wclear(stdscr);
}

void Display::refresh(){
    wrefresh(stdscr);
}

void Display::write(const char * str){
    printw(str);
}

int Display::getC(){
    int c = getch();
    return c;
}