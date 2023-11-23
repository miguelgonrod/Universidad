//************************** CUSTOM HEADERS IMPORTS ***************************
#include "custom_utilities.h"
#include "nums.h"

/*FN****************************************************************************
 *
 *   void gotoxy(int x, int y);
 *
 *   Purpose: This function allow to move the cursor of the console to a
 *   specific position to print content.
 *
 *   Plan:    It will be used by all the classes that need drawings and
 *   displays.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE  COMMENT
 *   -----------------------------------------------------------------------
 *   Apr 23/2023  D.F. Lopez   Documentation
 *   Apr 01/2023  D.F. Lopez   Implementaton
 *******************************************************************************/
void gotoxy(int x, int y) { printf("%c[%d;%df", 0x1B, y, x); }

/*FN****************************************************************************
 *
 *   void print_figure(int x, int y, char *figura[]);
 *
 *   Purpose: This function draws a given char matrix taking advantage of
 *gotoxy.
 *
 *   Plan:    It will be used by all the classes that need drawings and
 *   displays.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE  COMMENT
 *   -----------------------------------------------------------------------
 *   Apr 23/2023  D.F. Lopez   Documentation
 *   Apr 01/2023  D.F. Lopez   Implementaton
 *******************************************************************************/
void print_figure(int x, int y, char *figura[]) {
  for (int i = 0; figura[i][0] != '\0'; i++) {
    gotoxy(x, y + i);
    printf("%s\n", figura[i]);
  }
}

/*FN****************************************************************************
 *
 *   void reset_terminal_mode()
 *
 *   Purpose: Reset terminal mode after the implementation of a conio custom
 *   terminal for reading keybord inputs in real time without interruptions.
 *
 *   Plan:    It will be used only once in the main after game is finished.
 *
 *   Based on:
 *https://stackoverflow.com/questions/448944/c-non-blocking-keyboard-input
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE  COMMENT
 *   -----------------------------------------------------------------------
 *   Apr 23/2023  D.F. Lopez   Documentation
 *   Apr 01/2023  D.F. Lopez   Implementaton
 *******************************************************************************/
void reset_terminal_mode() { tcsetattr(0, TCSANOW, &orig_termios); }

/*FN****************************************************************************
 *
 *   void set_conio_terminal_mode();
 *
 *   Purpose: This function changes the mode of the base terminal to read key-
 *   board inputs without interruptions or delays.
 *
 *
 *   Plan:    It will be used only once at the beginning of the main.
 *
 *   Based on:
 *https://stackoverflow.com/questions/448944/c-non-blocking-keyboard-input
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE  COMMENT
 *   -----------------------------------------------------------------------
 *   Apr 23/2023  D.F. Lopez   Documentation
 *   Apr 01/2023  D.F. Lopez   Implementaton
 *******************************************************************************/
void set_conio_terminal_mode() {
  struct termios new_termios;

  /* take two copies - one for now, one for later */
  tcgetattr(0, &orig_termios);
  memcpy(&new_termios, &orig_termios, sizeof(new_termios));

  /* register cleanup handler, and set the new terminal mode */
  atexit(reset_terminal_mode);
  cfmakeraw(&new_termios);
  tcsetattr(0, TCSANOW, &new_termios);
}

/*FN****************************************************************************
 *
 *   int kbhit()
 *
 *   Purpose: Read a keyboard hit and store the corresponding representation.
 *
 *
 *   Plan:    It will be used in the main to read keys and commands without
 *   interruptions or delays.
 *
 *   Based on:
 *https://stackoverflow.com/questions/448944/c-non-blocking-keyboard-input
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE  COMMENT
 *   -----------------------------------------------------------------------
 *   Apr 23/2023  D.F. Lopez   Documentation
 *   Apr 01/2023  D.F. Lopez   Implementaton
 *******************************************************************************/
int kbhit() {
  struct timeval tv = {0L, 0L};
  fd_set fds;
  FD_ZERO(&fds);
  FD_SET(0, &fds);
  return select(1, &fds, NULL, NULL, &tv) > 0;
}

/*FN****************************************************************************
 *
 *   int kbhit()
 *
 *   Purpose: Read a keyboard hit and store the corresponding representation.
 *
 *
 *   Plan:    It will be used in the main to read keys and commands without
 *   interruptions or delays.
 *
 *   Based on:
 https://stackoverflow.com/questions/448944/c-non-blocking-keyboard-input

 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE  COMMENT
 *   -----------------------------------------------------------------------
 *   Apr 23/2023  D.F. Lopez   Documentation
 *   Apr 01/2023  D.F. Lopez   Implementaton
 *******************************************************************************/
int getch() {
  int r;
  unsigned char c;
  if ((r = read(0, &c, sizeof(c))) < 0) {
    return r;
  } else {
    return c;
  }
}

/*FN****************************************************************************
 *
 *   void printcolor( int color );
 *
 *   Purpose: This function sets the color of the alien based from the Alien's
 *            attribute color as it is a number, a switch case was created
 *            for each option and it prints the code so the desired color is
 *            applied
 *
 *   Plan:    It will be used in the "Draw" methods to print using a given
 *color.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE  COMMENT
 *   -----------------------------------------------------------------------
 *   Apr 23/2023  D.F. Lopez   Changed library
 *   Apr 02/2023  J.H.Avendaño Documentation
 *
 *******************************************************************************/
void printcolor(int color) {
  switch (color) {
  case 0:
    printf("\e[0;30m"); // Black
    break;
  case 1:
    printf("\e[0;31m"); // Red
    break;
  case 2:
    printf("\e[0;32m"); // Green
    break;
  case 3:
    printf("\e[0;33m"); // Yellow
    break;
  case 4:
    printf("\e[0;34m"); // Blue
    break;
  case 5:
    printf("\e[0;35m"); // Magenta
    break;
  case 6:
    printf("\e[0;36m"); // Cyan
    break;
  case 7:
    printf("\e[0;37m"); // White
    break;
  }
}

/*FN****************************************************************************
 *
 *   void PrintQuad(int x, int y, int height, int width, char letras[])
 *
 *   Purpose: This method sets the color of the alien based from the Alien's
 *            attribute color as it is a number, a switch case was created
 *            for each option and it prints the code so the desired color is
 *            applied
 *
 *   Plan:    It will be used in the beggining of the program to create the
 *   interface.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE  COMMENT
 *   -----------------------------------------------------------------------
 *   Apr 23/2023  D.F. Lopez   Changed library
 *   Apr 02/2023  J.H.Avendaño Documentation
 *
 *******************************************************************************/
void PrintQuad(int x, int y, int height, int width, char letras[]) {
  char cor_ul[] = "\u250f"; // Corner up-left ┏
  char cor_ur[] = "\u2513"; // Corner up-right ┓
  char cor_dr[] = "\u251B"; // Corner down-right ┛
  char cor_dl[] = "\u2517"; // Corner down-left  ┗
  char bor_ve[] = "\u2503"; // Vertical border ┃
  char bor_ho[] = "\u2501"; // Horizontal border ━

  int len = strlen(letras);

  gotoxy(x, y);
  printf("%s", cor_ul);
  gotoxy(x + 1, y);
  for (int i = 0; i < width; i++) {
    printf("%s", bor_ho);
  }

  gotoxy(x, y + 1);

  for (int j = 1; j <= height; j++) {
    printf("%s", bor_ve);
    gotoxy(x, y + j);
  }

  gotoxy(x, y + height);
  printf("%s", cor_dl);

  gotoxy(x + 1, y + height);
  for (int i = 0; i < width; i++) {
    printf("%s", bor_ho);
  }

  gotoxy(x + width, y);
  printf("%s", cor_ur);
  gotoxy(x + width, y + 1);
  for (int j = 2; j <= height; j++) {
    printf("%s", bor_ve);
    gotoxy(x + width, y + j);
  }
  gotoxy(x + width, y + height);
  printf("%s", cor_dr);

  gotoxy((x + (width / 2) - (len / 2)), y + 1);
  printf("%s", letras);
}

/*FN****************************************************************************
*
*   DELAY_STATE delay_fst_func(DELAY_STATE process_delay, double seconds,
*                           clock_t *begin_time)
*
*   Purpose: Implementation of a finite state machine for delays without
*   interruption that is independent of the class/object
*
*   Plan:   For implementing while using object instances related to moves.
*
*   Base on:
*   https://www.tutorialspoint.com/c_standard_library/c_function_clock.htm
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Apr 23/2023  D.F. Lopez   Documentation
*   Apr 23/2023  C.A. Sanchez   Implementaton
******************************************************************************

*/

DELAY_STATE delay_fst_func(DELAY_STATE process_delay, double seconds,
                           clock_t *begin_time) {
  DELAY_STATE state;
  clock_t current;
  switch (process_delay) {
  case FLAG:
    (*begin_time) = clock();
    state = WAITING;
    //gotoxy(5, 10);
    //printf("Just executed the flag: Waited (%f)", seconds);
    break;
  case WAITING:
    current = clock();
    if (((double)(current - *begin_time) / CLOCKS_PER_SEC) > seconds) {
      state = FLAG;
      // gotoxy(5, 10);
      // printf("Just launched the flag");
    } else {
      // gotoxy(5, 10);
      // printf("WAITING");
    }
    break;
  }
  return state;
}
void print_score(int alientype,int scores[], int x, int y){
  switch(alientype){
    case 1:
       scores[2]++;
      if(scores[2]>9){
        scores[2]=0;
        scores[1]++;
        if(scores[1]>9){
          scores[1]=0;
          scores[0]++;
          print_num(32 + x,3 + y,scores[0]);
          print_num(36 + x,3 + y,scores[1]);
          print_num(40 + x,3 + y,scores[2]);
        }else{
          print_num(36 + x,3 + y,scores[1]);
          print_num(40 + x,3 + y,scores[2]);
        }
      }else{
        print_num(40 + x,3 + y,scores[2]);
      }
      break;
    case 2:
       scores[2]+=2;
      if(scores[2]>9){
        scores[2]=0;
        scores[1]++;
        if(scores[1]>9){
          scores[1]=0;
          scores[0]++;
          print_num(32 + x,3 + y,scores[0]);
          print_num(36 + x,3 + y,scores[1]);
          print_num(40 + x,3 + y,scores[2]);
        }else{
          print_num(36 + x,3 + y,scores[1]);
          print_num(40 + x,3 + y,scores[2]);
        }
      }else{
        print_num(40 + x,3 + y,scores[2]);
      }
      break;
    case 3:
      scores[2]+=3;
      if(scores[2]>9){
        scores[2]=0;
        scores[1]++;
        if(scores[1]>9){
          scores[1]=0;
          scores[0]++;
          print_num(32 + x,3 + y,scores[0]);
          print_num(36 + x,3 + y,scores[1]);
          print_num(40 + x,3 + y,scores[2]);
        }else{
          print_num(36 + x,3 + y,scores[1]);
          print_num(40 + x,3 + y,scores[2]);
        }
      }else{
        print_num(40 + x,3 + y,scores[2]);
      }
      break;
    case 4:
      scores[1]+=3;
      if(scores[2]>9){
        scores[2]=0;
        scores[1]++;
        if(scores[1]>9){
          scores[1]=0;
          scores[0]++;
          print_num(32 + x,3 + y,scores[0]);
          print_num(36 + x,3 + y,scores[1]);
          print_num(40 + x,3 + y,scores[2]);
        }else{
          print_num(36 + x,3 + y,scores[1]);
          print_num(40 + x,3 + y,scores[2]);
        }
      }else{
        print_num(40 + x,3 + y,scores[2]);
      }
      break;
    case 5:
      
      for(int i=28+x;i<44+x;i+=4){
       print_figure(i,3,zero);
      }
      break;
    
    
  }

  
}
void print_num(int x, int y, int num){
  switch(num){
    case 0:
      print_figure(x,y,zero);
      break;
    case 1:
      print_figure(x,y,one);
      break;
    case 2:
      print_figure(x,y,two);
      break;
    case 3:
      print_figure(x,y,three);
      break;
    case 4:
      print_figure(x,y,four);
      break;
    case 5:
      print_figure(x,y,five);
      break;
    case 6:
      print_figure(x,y,six);
      break;
    case 7:
      print_figure(x,y,seven);
      break;
    case 8:
      print_figure(x,y,eight);
      break;
    case 9:
      print_figure(x,y,nine);
      break;
    
  }
}
