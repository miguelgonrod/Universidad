/* Ruler 1         2         3         4         5         6         7        */

#ifndef	CONIO_H
#define CONIO_H

/********************************** Headers ***********************************/

/* ------------------------ Inclusion of Std Headers ------------------------ */

#include <stdint.h>

#include "conio.c"

/*********************** Prototypes of Public Functions ***********************/

/* ------------------------- Setting color of text -------------------------- */

void Reset();

void Light_Black();
void Light_Red();
void Light_Green();
void Light_Yellow();
void Light_Blue();
void Light_Purple();
void Light_Cyan();
void Light_White();

void Dark_Black();
void Dark_Red();
void Dark_Green();
void Dark_Yellow();
void Dark_Blue();
void Dark_Purple();
void Dark_Cyan();
void Dark_White();

void Thin_Black();
void Thin_Red();
void Thin_Green();
void Thin_Yellow();
void Thin_Blue();
void Thin_Purple();
void Thin_Cyan();
void Thin_White();

void Bold_Black();
void Bold_Red();
void Bold_Green();
void Bold_Yellow();
void Bold_Blue();
void Bold_Purple();
void Bold_Cyan();
void Bold_White();

void Back_Black();
void Back_Red();
void Back_Green();
void Back_Yellow();
void Back_Blue();
void Back_Purple();
void Back_Cyan();
void Back_White();

/* -------------------------- Services in console --------------------------- */

void Clear_Screen();
void gotoxy( uint8_t, uint8_t );
void Cursor( int );
void Set_Console_Size( uint8_t, uint8_t );
void Get_Console_Size( uint8_t *, uint8_t * );

#endif /* CONIO_H */
