#include <ncurses.h>
#include <iostream>


int main() {

    initscr();                   
    printw("Hello world!\n");  
    refresh();                   
    getch();                     
    endwin();             

    return 0;
}