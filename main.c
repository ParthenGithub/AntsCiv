#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define LEVEL_HEIGHT 60 
#define LEVEL_WIDTH 100 /* on terminal it will be x2 wider  */

#define GAME_NAME "[Ant's Civilisation]"

static int ise_sizes_even(int height, int width)
{
    if (height % 2 == 0 && width % 4 == 0)
        return 1;
    else
        return 0;
}

void init_ncurses()
{
    initscr();
    curs_set(0);
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    /* Stupid, but works. TODO: rewrite it */
    start_color();
    /*           name       text color      background */
    init_pair(COLOR_WHITE,  COLOR_WHITE,    COLOR_BLACK);
    init_pair(COLOR_GREEN,  COLOR_GREEN,    COLOR_BLACK);
    init_pair(COLOR_YELLOW, COLOR_YELLOW,   COLOR_BLACK);
    init_pair(COLOR_BLUE,   COLOR_BLUE,     COLOR_BLACK);
    init_pair(COLOR_CYAN,   COLOR_CYAN,     COLOR_BLACK);
    init_pair(COLOR_MAGENTA,COLOR_MAGENTA,  COLOR_BLACK);
    init_pair(COLOR_BLACK,  COLOR_BLACK,    COLOR_BLACK);
    init_pair(COLOR_RED,    COLOR_RED,      COLOR_BLACK);
}

void init_main_screen(const int width, const char *game_name)
{
    /* Drawing main window decorations*/
    box(stdscr, 0, 0);
    mvwprintw(stdscr, 0, (width-(strlen(game_name)))/2 + 2, game_name);
    refresh();
}


int main() {
    int term_height, term_width;
    init_ncurses();
    
    
    getmaxyx(stdscr, term_height, term_width);
    
    if (!ise_sizes_even(term_height, term_width)) {
        char *string = "ERROR: The terminal width must be divisible by 4, and the height by 2.\n"
        "Your terminal sizes: %dx%d\n";
        endwin();
        fprintf(stderr, string, term_width, term_height);
        return 1;
    } 
    
    init_main_screen(term_width, GAME_NAME);

    getch();
    endwin();
    return 0;
}

