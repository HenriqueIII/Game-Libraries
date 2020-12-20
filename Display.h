#include <curses.h>

class Display{
    int maxX=0, maxY=0;
public:
    Display(){
        initscr();
        raw();
        keypad(stdscr, true);
        noecho();
        getmaxyx(stdscr, maxY, maxX);
    }
    ~Display(){
        endwin();
    }
    int getmaxX() const{
        return maxX;
    }
    int getmaxY() const{
        return maxY;
    }
    void refresh();
    void clear();
    void write(const char *);
    void write(const char);
    int getC();
    int attributeOn(chtype);
    int attributeOff(chtype);
    void moveC(int, int);

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

void Display::write(const char ch){
    printw("%c", ch);
}

int Display::getC(){
    int c = getch();
    return c;
}
int Display::attributeOn(chtype attr){
    return attron(attr);
}

int Display::attributeOff(chtype attr){
    return attroff(attr);
}

void Display::moveC(int yY, int xX){
    move(yY, xX);
}
