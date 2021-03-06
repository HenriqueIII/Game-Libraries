#include <iostream>
#include "curses.h"
#include "Display.h"

Display dsp;

Display::Display(){
    if(this!=&dsp){
        std::cerr << "The only instance of Display is \"dsp\"" << std::endl;
        exit(1);
    }
    int startx,starty;      //where window start
    int width = MAX_X+1, height=MAX_Y+1;      //dimension of window
    initscr();              //start curses mode
    cbreak();
    noecho();
    if(has_colors()==FALSE){
        endwin();
        std::cerr << "Your terminal does not support colors." << std::endl;
        exit(1);
    }
    start_color();
    initColor();
    cursorOff();
    foreground = WHITE;
    background = BLACK;
    width = width < COLS ? width : COLS;
    height = height < LINES ? height : LINES;

    starty = (LINES - height) / 2;
    startx = (COLS - width) / 2;
    //printw("%d %d\n", LINES, starty);
    //printw("%d %d", COLS, startx);
    my_win = newwin(height, width, starty, startx);
    //box(my_win,0,0);
    keypad(my_win, TRUE);
    refresh();
    wrefresh(my_win);
}

void Display::initColor(){
    // Iniciar todos os pares possiveis (128 pares).
    int colorpair;
    for (int bg=0; bg < 8; bg++){
        for(int fg=0; fg < 8; fg++){
            colorpair = colornum(fg, bg);
            init_pair(colorpair, curs_color(fg), curs_color(bg));
        }
    }
}
short Display::curs_color(int fg){
    // Converter numeros em constantes de cor do curses
    switch (7 & fg){
        case 0: /*000*/
            return (COLOR_BLACK);
        case 1: /*001*/
            return (COLOR_RED);
        case 2: /*010*/
            return (COLOR_GREEN);
        case 3: /*011*/
            return (COLOR_YELLOW);
        case 4: /*100*/
            return (COLOR_BLUE);
        case 5: /*101*/
            return (COLOR_MAGENTA);
        case 6: /*110*/
            return (COLOR_CYAN);
        case 7: /*111*/
            return (COLOR_WHITE);
    }
    return 0;
}
int Display::colornum(int fg, int bg){
    int B, bbb, ffff;
    B = 1 << 7;
    bbb = (7 & bg) << 4;
    ffff = 7 & fg;
    return (B | bbb | ffff);
}

int Display::is_bold(int fg){
    int i;

    i = 1 << 3;
    return (i & fg);
}

void Display::setForeground(int color){
    wattron(my_win, COLOR_PAIR(colornum(color,background)));
    if (is_bold(color))
        wattron(my_win,A_BOLD);
    foreground = color;
    wrefresh(my_win);
}

void Display::setBackground(int color){
    wattron(my_win, COLOR_PAIR(colornum(foreground, color)));
    background = color;
    wrefresh(my_win);
}

void Display::resetColor(){
    wattron(my_win, COLOR_PAIR(colornum(Display::WHITE, Display::BLACK)));
    wattroff(my_win, A_BOLD);
    background = Display::BLACK;
    foreground = Display::WHITE;
    wrefresh(my_win);
}

void Display::cursorOff(){
    curs_set(0);
}
void Display::cursorOn(){
    curs_set(1);
}
void Display::setCursor(int x, int y){
    wmove(my_win, y, x);
    wrefresh(my_win);
}
void Display::putc(int chr){
    waddch(my_win, chr);
    wrefresh(my_win);
}

void Display::putc(int x, int y, int chr, int color){
    setForeground(color);
    mvwaddch(my_win, y, x, chr);
    wrefresh(my_win);
}

void Display::puts(const char * str){
    wprintw(my_win, str);
    wrefresh(my_win);
}
void Display::windowClear(){
    wclear(my_win);
    wrefresh(my_win);
}

Display::~Display(){
    cursorOn();
    delwin(my_win);
    endwin();
}