#include <curses.h>
#include <string>
using namespace std;
WINDOW *ventanaPrincipal;
WINDOW *ventanaBox1;
WINDOW *ventanaBox2;
WINDOW *ventanaBox3;
int main(){
    int MaxY, MaxX;
    initscr();
    getmaxyx(stdscr, MaxY, MaxX);
    if (!has_colors()){
        endwin();
        return 1;
    } // Fin If
    cbreak();
    noecho();
    nonl();
    intrflush(ventanaPrincipal, FALSE);
    keypad(ventanaPrincipal, TRUE);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    ventanaPrincipal = newwin(MaxY, MaxX, 0, 0);
    ventanaBox1 = newwin(MaxY - 9, (MaxX / 3) - 2, 6, 2);
    ventanaBox2 = newwin(3, MaxX - 4, 2, 2);
    ventanaBox3 = newwin(MaxY - 9, ((MaxX * 2) / 3) - 3, 6, (MaxX / 3) + 2);
    wbkgd(ventanaPrincipal, COLOR_PAIR(1));
    wbkgd(ventanaBox1, COLOR_PAIR(1));
    wbkgd(ventanaBox2, COLOR_PAIR(1));
    wbkgd(ventanaBox3, COLOR_PAIR(1));
    refresh();
    box(ventanaBox1, 0, 0);
    box(ventanaBox2, 0, 0);
    box(ventanaBox3, 0, 0);
    //start_color();
    init_pair(2, COLOR_BLACK, COLOR_CYAN);
    attrset(COLOR_PAIR(2));
    // Imprimir Texto de la Ventana Principal
    wattron(ventanaPrincipal, COLOR_PAIR(2));
    mvwprintw(ventanaPrincipal, 0, 1, "YaST @ g185");
    mvwprintw(ventanaPrincipal, 0, 0, " ");
    for (int i = 12; i < MaxX - 18; i++){
        mvwprintw(ventanaPrincipal, 0, i, " ");
    } // Fin For  
    mvwprintw(ventanaPrincipal, 0, MaxX - 18, "Press F1 for Help");
    mvwprintw(ventanaPrincipal, 0, MaxX, " ");
    wattroff(ventanaPrincipal, COLOR_PAIR(2));
    mvwprintw(ventanaPrincipal, MaxY - 2, 2, "[");
    mvwprintw(ventanaPrincipal, MaxY - 2, MaxX - 8, "[");
    init_pair(3, COLOR_YELLOW, COLOR_BLUE);
    attrset(COLOR_PAIR(3));
    wattron(ventanaPrincipal, COLOR_PAIR(3));
    mvwprintw(ventanaPrincipal, MaxY - 2, 3, "H");
    mvwprintw(ventanaPrincipal, MaxY - 2, MaxX - 7, "Q");
    wattroff(ventanaPrincipal, COLOR_PAIR(3));
    mvwprintw(ventanaPrincipal, MaxY - 2, 4, "elp]");
    mvwprintw(ventanaPrincipal, MaxY - 2, MaxX - 6, "uit]");
    // Imprimir Texto de la Primera Caja
    init_pair(6, COLOR_YELLOW, COLOR_CYAN);
    attrset(COLOR_PAIR(6));
    wattron(ventanaBox1, COLOR_PAIR(6)); 
    mvwprintw(ventanaBox1, 1, 1, "Software");
    for (int i = 9; i < (MaxX / 3) - 3; i++){
        mvwprintw(ventanaBox1, 1, i, " ");
    }
    wattroff(ventanaBox1, COLOR_PAIR(6));
    mvwprintw(ventanaBox1, 2, 1, "Hardware");
    mvwprintw(ventanaBox1, 3, 1, "System");
    mvwprintw(ventanaBox1, 4, 1, "Network Devices");
    mvwprintw(ventanaBox1, 5, 1, "Network Services");
    mvwprintw(ventanaBox1, 6, 1, "Security and Users");
    mvwprintw(ventanaBox1, 7, 1, "Misc");
    // Imprimir Texto de la Segunda Caja
    init_pair(4, COLOR_YELLOW, COLOR_BLUE);
    attrset(COLOR_PAIR(4));
    wattron(ventanaBox2, COLOR_PAIR(4));   
    mvwprintw(ventanaBox2, 1, 1, "YaSTZ Control Center");
    wattroff(ventanaBox2, COLOR_PAIR(4));
    // Imprimir Texto de la Tercera Caja
    init_pair(5, COLOR_YELLOW, COLOR_BLUE);
    attrset(COLOR_PAIR(5));
    wattron(ventanaBox3, COLOR_PAIR(5)); 
    mvwprintw(ventanaBox3, 1, 1, "Patch CD Update");
    wattroff(ventanaBox3, COLOR_PAIR(5));  
    mvwprintw(ventanaBox3, 2, 1, "Installation into Directory");
    mvwprintw(ventanaBox3, 3, 1, "Online Update");
    mvwprintw(ventanaBox3, 4, 1, "Install and Remove Software");
    mvwprintw(ventanaBox3, 5, 1, "Change Source of Installation");
    mvwprintw(ventanaBox3, 6, 1, "System Update");
    // Refrescamiento de las Ventanas
    touchwin(ventanaPrincipal);
    wrefresh(ventanaPrincipal);
    touchwin(ventanaBox1);
    wrefresh(ventanaBox1);
    touchwin(ventanaBox2);
    wrefresh(ventanaBox2);
    touchwin(ventanaBox3);
    wrefresh(ventanaBox3);
    getchar();
    endwin();
    return 0;
} // Fin Main