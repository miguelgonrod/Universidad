#ifndef UTILITIES_H
#define UTILITIES_H

//************************ STANDARD LIBRARIES IMPORTS **************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

//************************** STRUCTURE DECLARATIONS ****************************
struct termios orig_termios;
typedef enum {
  FLAG,   // Indicates to start the process due to timer finished
  WAITING // Not interrupting wait that block delay the specified process
} DELAY_STATE;

//************************** FUNCTIONS PROTOTYPES ******************************
void gotoxy(int x, int y);
void print_figure(int x, int y, char *figure[]);
void print_score(int alientype ,int scores[], int x, int y);
void print_num(int x, int y, int num);
void reset_terminal_mode();
void set_conio_terminal_mode();
int kbhit();
int getch();
void printcolor(int color);
void PrintQuad(int x, int y, int height, int width, char letras[]);
DELAY_STATE delay_fst_func(DELAY_STATE process_delay, double seconds,
                           clock_t *begin_time);

#endif /* UTILITIES_H */