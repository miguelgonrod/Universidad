#include <stdio.h>

#include "emojiObj.h"

/******************************* New_emoji Function ********************************/

/*FN****************************************************************************
*
*   Purpose: To allocate the new emoji object memory
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

NuevoEmoji *New_emoji(){
    return (NuevoEmoji *)malloc(sizeof(NuevoEmoji));
}

/******************************* Construct_emoji Function ********************************/

/*FN****************************************************************************
*
*   Purpose: To initialize the object with its attributes
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

NuevoEmoji *Construct_emoji(char *emojiMatrix[], unsigned char posx , unsigned char posy, unsigned char delX, unsigned char delY, double delay1){
    NuevoEmoji *emojiNew = New_emoji();
    for(int line = 0; line <= 1; line++){
        emojiNew->emojiIcon[line] = emojiMatrix[line];
    }

    emojiNew->positionX = posx;
    emojiNew->positionY = posy;
    emojiNew->deltaX = delX;
    emojiNew->deltaY = delY;
    emojiNew->delay = delay1;

    emojiNew->myState = MOVING;
    emojiNew->my_begin_time = clock();

    return emojiNew;
}

/******************************* setEmoji Function ********************************/

/*FN****************************************************************************
*
*   Purpose: Set a new icon to the emojiIcon attribute
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

void setEmoji(NuevoEmoji *const me, char *emojiMatrix[]){
    for(int line = 0; emojiMatrix[line][0] != '\0'; line++){
        me->emojiIcon[line] = emojiMatrix[line];
    }
}

/******************************* setPositionX Function ********************************/

/*FN****************************************************************************
*
*   Purpose: Set a new value to the positionX attribute
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

void setPositionX(NuevoEmoji *const me, unsigned char posx){
    me->positionX = posx;
}

/******************************* setPositionY Function ********************************/

/*FN****************************************************************************
*
*   Purpose: Set a new value to the positionY attribute
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

void setPositionY(NuevoEmoji *const me, unsigned char posy){
    me->positionY = posy;
}

/******************************* setDeltaX Function ********************************/

/*FN****************************************************************************
*
*   Purpose: Set a new value to the deltaX attribute
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

void setDeltaX(NuevoEmoji *const me, unsigned char delx){
    me->deltaX = delx;
}

/******************************* setDeltaY Function ********************************/

/*FN****************************************************************************
*
*   Purpose: Set a new value to the deltaY attribute
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

void setDeltaY(NuevoEmoji *const me, unsigned char dely){
    me->deltaY = dely;
}

/******************************* setDelay Function ********************************/

/*FN****************************************************************************
*
*   Purpose: Set a new value to the delay attribute
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

void setDelay(NuevoEmoji *const me, double delay1){
    me->delay = delay1;
}

/******************************* setState Function ********************************/

/*FN****************************************************************************
*
*   Purpose: Set a new value to the myState attribute
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

void setState(NuevoEmoji *const me, DELAY_STATE myNewState){
    me->myState = myNewState;
}

/******************************* setBeginTime Function ********************************/

/*FN****************************************************************************
*
*   Purpose: Set a new value to the my_begin_time attribute
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

void setBeginTime(NuevoEmoji *const me, clock_t beginTime){
    me->my_begin_time = beginTime;
}

/******************************* getEmoji Function ********************************/

/*FN****************************************************************************
*
*   Purpose: Return the value allocated in emojiIcon attribute
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

char **getEmoji(NuevoEmoji *const me){
    return me->emojiIcon;
}

/******************************* getPositonX Function ********************************/

/*FN****************************************************************************
*
*   Purpose: Return the value allocated in positonX attribute
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

unsigned char getPositionX(NuevoEmoji *const me){
    return me->positionX;
}

/******************************* getPositionY Function ********************************/

/*FN****************************************************************************
*
*   Purpose: Return the value allocated in positionY attribute
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

unsigned char getPositionY(NuevoEmoji *const me){
    return me->positionY;
}

/******************************* getDeltaX Function ********************************/

/*FN****************************************************************************
*
*   Purpose: Return the value allocated in deltaX attribute
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

unsigned char getDeltaX(NuevoEmoji *const me){
    return me->deltaX;
}

/******************************* getDeltaY Function ********************************/

/*FN****************************************************************************
*
*   Purpose: Return the value allocated in deltaY attribute
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

unsigned char getDeltaY(NuevoEmoji *const me){
    return me->deltaY;
}

/******************************* getDelay Function ********************************/

/*FN****************************************************************************
*
*   Purpose: Return the value allocated in delay attribute
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

double getDelay(NuevoEmoji *const me){
    return me->delay;
}

/******************************* getMyState Function ********************************/

/*FN****************************************************************************
*
*   Purpose: Return the value allocated in myState attribute
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

DELAY_STATE getMyState(NuevoEmoji *const me){
    return me->myState;
}

/******************************* getMyTime Function ********************************/

/*FN****************************************************************************
*
*   Purpose: Return the value allocated in my_begin_time attribute
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

clock_t getMyTime(NuevoEmoji *const me){
    return me->my_begin_time;
}

/******************************* drawEmojiElement Function ********************************/

/*FN****************************************************************************
*
*   Purpose: This function makes sure that the emoji is printed exactly in its x and y position with its size
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

void drawEmojiElement(NuevoEmoji *const me)
{
	for( int i = 0, j = 0; me->emojiIcon[i][0] != '\0'; i++, j++ ) {
		gotoxy( me->positionX, me->positionY + j );
		printf( "%s\n", me->emojiIcon[i] );
	}

} 

/******************************* clearEmojiElement Function ********************************/

/*FN****************************************************************************
*
*   Purpose: This function clears the icon to subsequently allow the code to print it without leaving a trace
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

void clearEmojiElement(NuevoEmoji *const me)
{
    int j = 0;
	for( int i = 0; me->emojiIcon[i][0] != '\0'; i++) {
		gotoxy( me->positionX, me->positionY + j );
		int width = strlen( me->emojiIcon[0] ) / 3;
		for( int spaces = 0; spaces < width; spaces++ )
			printf( " " );
        j++;
	}

    me->positionX = me->positionX + me->deltaX;
    me->positionY = me->positionY + me->deltaY;

} 

/******************************* collition Function ********************************/

/*FN****************************************************************************
*
*   Purpose: This function keeps verifying if the emoji collides with any of the map borders to make the bounce
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

void collition(NuevoEmoji *const me, unsigned char width, unsigned char height){
    if( ! (me->positionX > 2 && me->positionX < width ) ){
		me->deltaX = me->deltaX * -1;
    }

	if( ! (me->positionY > 2 && me->positionY < height ) ){
		me->deltaY = me->deltaY * -1;
    }
}

/******************************* emojiDelayFunction Function ********************************/

/*FN****************************************************************************
*
*   Purpose: This function calculates the timer of the emoji and it actual state calculating its velocitymyS
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

void emojiDelayFunction(NuevoEmoji *const me){
  	clock_t current;
  	switch (me->myState) {
		case MOVING:
			me->my_begin_time = clock();
			me->myState = WAITING;
			break;
		case WAITING:
			current = clock();
			if (((double)(current - me->my_begin_time) / CLOCKS_PER_SEC) > me->delay) {
			    me->myState = MOVING;
			} else {
                me->myState = WAITING;
			}
			break;
  	}
}
