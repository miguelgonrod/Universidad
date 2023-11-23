/* Ruler 1         2         3         4         5         6         7        */

// COMPILE WITH:          gcc emoji.c conio.c -o emoji

/* emoji.c ********************************************************************/
/*                                                                            */
/*   +----+ +----+                          BOUNCING EMOJI                    */
/*   ++  ++ ++******                                                          */
/*    |  |   |**  **      This is a simple example of using an animation      */
/*    |  |   | *  *       in ANSI C. This source code with main function      */
/*    |  |   | *  *       together with "conio" library can be easily         */
/*    |******| *  *       used to implement animation with a SINGLE instance  */
/*    |**  **| *  *                                                           */
/*    ++*  ** **  *       DOCUMENTED BY: Ing. Juan-Carlos Giraldo, Ph.D.      */
/*     +**  ***  **                      jcgiraldo@javeriana.edu.co           */
/*      +**     **                                                            */
/*        *******         Bogota, D.C., May 31th, 2023.                       */
/*                                                                            */
/*          Copyright (C) Department de Electronics                           */
/*                        School of Engineering                               */
/*                        Pontificia Universidad Javeriana                    */
/*                        Bogota - Colombia - South America                   */
/*                                                                            */
/******************************************************************************/

/********************************** Headers ***********************************/

/* ------------------------ Inclusion of Std Headers ------------------------ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* ------------------------ Inclusion of Own Headers ------------------------ */

#include "conio.h"

#include "emojiObj.h"
#include "emojiObj.c"


/**************************** Definition of Emojis ****************************/

char *happy[2] = {
"\U0001F600", /* 😀 */
""
};

char *space_invader[2] = {
"\U0001F47E", /* 👾 */
""
};

char *alien[2] = {
"\U0001F47D", /* 👽 */
""
};



/******************* Prototype of Functions in Current File *******************/

void drawElement ( const char *[], char, char );
void clearElement( const char *[], char, char );
void Frame( char, char, char, char );
DELAY_STATE delayFunction(DELAY_STATE process_delay, double seconds, clock_t *begin_time);


/******************************* Main Function ********************************/

/*FN****************************************************************************
*
*   Purpose: Animate a single emoji through the screen
*
*   Plan:    Part 1: Clear object
*            Part 2: Update state
*            Part 3: Bounces if collided with a wall
*            Part 4: Draw current object based on state
*            Part 5: Freeze object in a given position
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE       COMMENT
*   -----------------------------------------------------------------------
*   Apr 20/2020  J.C.Giraldo       Initial implementation
*   May 31/2023  Miguel Gonzalez   Latest implementation
*
*******************************************************************************/

int main()
{
	srand(time(NULL));
	unsigned char width  = 2;
	unsigned char height = 1;

	unsigned char screenWidth;
	unsigned char screenHeight;

	NuevoEmoji *emoji1 = Construct_emoji(happy, 2, 2, 2, 1, 1);

	NuevoEmoji *emoji2 = Construct_emoji(space_invader, 5, 7, 2, 1, 3);

	NuevoEmoji *emoji3 = Construct_emoji(alien, 3, 3, 2, 2, 0.2);

	Get_Console_Size( &screenWidth, &screenHeight );
	screenWidth = ( screenWidth % 2 ? screenWidth-1 : screenWidth);
	Clear_Screen();
	for( int j = 1; j <= screenHeight; j++ )
		for( int i = 1; i <= screenWidth; i++ )
			gotoxy(i,j), printf( "\u253C" );

	Frame( 1, 1, screenWidth, screenHeight );

	Cursor( 0 );

	while( 1 ) {
		if (getMyState(emoji1) == MOVING) 
    	{
			/* Part 1: Clear object */
			clearEmojiElement( emoji1);
			
			/* Part 2: Update state */
			/* Part 3: Bounces if collided with a wall */
			collition(emoji1, screenWidth-width, screenHeight-height);

			/* Part 4: Draw current object based on state */
			drawEmojiElement( emoji1);
		}
		emojiDelayFunction(emoji1);

		if (getMyState(emoji2) == MOVING) 
    	{
			/* Part 1: Clear object */
			clearEmojiElement( emoji2);

			/* Part 2: Update state */
			/* Part 3: Bounces if collided with a wall */
			collition(emoji2, screenWidth-width, screenHeight-height);

			/* Part 4: Draw current object based on state */

			drawEmojiElement( emoji2);
		}
		emojiDelayFunction(emoji2);

		if (getMyState(emoji3) == MOVING) 
    	{
			/* Part 1: Clear object */
			clearEmojiElement( emoji3);
			
			/* Part 2: Update state */
			/* Part 3: Bounces if collided with a wall */
			collition(emoji3, screenWidth-width, screenHeight-height);

			/* Part 4: Draw current object based on state */
			drawEmojiElement( emoji3);
		}
		emojiDelayFunction(emoji3);


	}

	return 0;

}



/******************* Definition of Functions in Current File ******************/

/*FN****************************************************************************
*
*   void drawElement( const char *element[], char x, char y );
*
*   Purpose: Draw an element previously defined in strings
*
*   Plan:    Simple function that does not need a plan description
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Apr 07/2023  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

void drawElement( const char *element[], char x, char y )
{
	for( int i = 0, j = 0; element[i][0] != '\0'; i++, j++ ) {
		gotoxy( x, y + j );
		printf( "%s\n", element[i] );
	}

} /* drawElement */



/*FN****************************************************************************
*
*   void clearElement( const char *element[], char x, char y );
*
*   Purpose: Draw an element previously drawn with UNICODE
*
*   Plan:    Simple function that does not need a plan description
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Apr 07/2023  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

void clearElement( const char *element[], char x, char y )
{
	for( int i = 0, j = 0; element[i][0] != '\0'; i++, j++ ) {
		gotoxy( x, y + j );
		int width = strlen( element[0] ) / 3;
		for( int spaces = 0; spaces < width; spaces++ )
			printf( " " );
	}

} /* clearElement */



/*FN****************************************************************************
*
*   void Frame();
*
*   Purpose: Draw a frame with rounded corners
*
*   Register of Revisions (Debugging Process):
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 01/21  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

void Frame( char x, char y, char dx, char dy )
{
	gotoxy( x, y );
	printf( "\u256D" );

	gotoxy( x+1, y );
	for( int i=x+1; i<x+dx-1; i++ )
		printf( "\u2500" );

	gotoxy( x+dx-1, y );
	printf( "\u256E" );



	for( int j=y+1; j<y+dy-1; j++ ) {
		gotoxy( x, j );
		printf( "\u2502" );
	}

	for( int j=y+1; j<y+dy-1; j++ ) {
		gotoxy( x+dx-1, j );
		printf( "\u2502" );
	}



	gotoxy( x, y+dy-1 );
	printf( "\u2570" );

	gotoxy( x+1, y+dy-1 );
	for( int i=x+1; i<x+dx-1; i++ )
		printf( "\u2500" );

	gotoxy( x+dx-1, y+dy-1 );
	printf( "\u256F" );

} /* Frame */
