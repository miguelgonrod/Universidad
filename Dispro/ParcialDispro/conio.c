/* Ruler 1         2         3         4         5         6         7        */

/********************************** Headers ***********************************/

/* ------------------------ Inclusion of Std Headers ------------------------ */

#include <stdio.h>     // Due to printf
#include <stdint.h>    // Due to uint8_t
#include <sys/ioctl.h> // Due to ioctl



/************************ Definition of Public Methods ************************/

/* ------------------------- Setting color of text -------------------------- */

/*FN****************************************************************************
*
*   void [color]();
*
*   Purpose: Set color
*
*   Register of Revisions (Debugging Process):
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 31/21  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

void Reset()       { printf("\033[0m"); }

void Light_Black() { printf("\033[0;30m"); }
void Light_Red()   { printf("\033[0;31m"); }
void Light_Green() { printf("\033[0;32m"); }
void Light_Yellow(){ printf("\033[0;33m"); }
void Light_Blue()  { printf("\033[0;34m"); }
void Light_Purple(){ printf("\033[0;35m"); }
void Light_Cyan()  { printf("\033[0;36m"); }
void Light_White() { printf("\033[0;37m"); }

void Dark_Black()  { printf("\033[1;30m"); }
void Dark_Red()    { printf("\033[1;31m"); }
void Dark_Green()  { printf("\033[1;32m"); }
void Dark_Yellow() { printf("\033[1;33m"); }
void Dark_Blue()   { printf("\033[1;34m"); }
void Dark_Purple() { printf("\033[1;35m"); }
void Dark_Cyan()   { printf("\033[1;36m"); }
void Dark_White()  { printf("\033[1;37m"); }

void Thin_Black()  { printf("\033[0;90m"); }
void Thin_Red()    { printf("\033[0;91m"); }
void Thin_Green()  { printf("\033[0;92m"); }
void Thin_Yellow() { printf("\033[0;93m"); }
void Thin_Blue()   { printf("\033[0;94m"); }
void Thin_Purple() { printf("\033[0;95m"); }
void Thin_Cyan()   { printf("\033[0;96m"); }
void Thin_White()  { printf("\033[0;97m"); }

void Bold_Black()  { printf("\033[1;90m"); }
void Bold_Red()    { printf("\033[1;91m"); }
void Bold_Green()  { printf("\033[1;92m"); }
void Bold_Yellow() { printf("\033[1;93m"); }
void Bold_Blue()   { printf("\033[1;94m"); }
void Bold_Purple() { printf("\033[1;95m"); }
void Bold_Cyan()   { printf("\033[1;96m"); }
void Bold_White()  { printf("\033[1;97m"); }

void Back_Black()  { printf("\033[40m"); }
void Back_Red()    { printf("\033[41m"); }
void Back_Green()  { printf("\033[42m"); }
void Back_Yellow() { printf("\033[43m"); }
void Back_Blue()   { printf("\033[44m"); }
void Back_Purple() { printf("\033[45m"); }
void Back_Cyan()   { printf("\033[46m"); }
void Back_White()  { printf("\033[47m"); }

/* -------------------------- Services in console --------------------------- */

/*FN****************************************************************************
*
*   void Clear_Screen();
*
*   Purpose: Clear screen with escape ansi sequence
*
*   Plan:    Simple function that does not need a plan description
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 31/2020  J.C.Giraldo  Documentation
*
*******************************************************************************/

void Clear_Screen()
{
printf("\033[H\033[J");

} /* Clear_Screen */



/*FN****************************************************************************
*
*   void gotoxy( uint8_t x, uint8_t y );
*
*   Purpose: Position cursor
*
*   Plan:    Simple function that does not need a plan description
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 31/2020  J.C.Giraldo  Documentation
*
*******************************************************************************/

void gotoxy( uint8_t x, uint8_t y )
{
printf( "\033[%d;%df", y, x );

} /* gotoxy */



/*FN****************************************************************************
*
*   void Cursor( int status );
*
*   Purpose: Show or hide cursor
*
*   Register of Revisions (Debugging Process):
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Jun 15/21  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

void Cursor( int status )
{
status ? printf( "\x1B[?25h" ) : printf( "\x1B[?25l" );

} /* Cursor */



/*FN****************************************************************************
*
*   void Set_Console_Size( uint8_t x, uint8_t y );
*
*   Purpose: Set console size
*
*   Plan:    Simple function that does not need a plan description
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 31/2020  J.C.Giraldo  Documentation
*
*******************************************************************************/

void Set_Console_Size( uint8_t x, uint8_t y )
{
printf( "\033[8;%d;%dt", y, x );

} /* Set_Console_Size */



/*FN****************************************************************************
*
*   void Get_Console_Size( uint8_t *x, uint8_t *y );
*
*   Purpose: Get console size
*
*   Plan:    Simple function that does not need a plan description
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 31/2020  J.C.Giraldo  Documentation
*
*******************************************************************************/

void Get_Console_Size( unsigned char *x, unsigned char *y )
{
struct winsize w;
ioctl( 0, TIOCGWINSZ, &w );
*x = w.ws_col;
*y = w.ws_row;

} /* Get_Console_Size */

