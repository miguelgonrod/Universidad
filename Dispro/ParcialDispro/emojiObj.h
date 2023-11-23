#ifndef EMOJIOBJ_H
#define EMOJIOBJ_H

typedef enum {
  MOVING,
  WAITING
} DELAY_STATE;

typedef struct{
    struct emojiObj const *vptr;
    char *emojiIcon[2];
    unsigned char positionX;
	unsigned char positionY;
	unsigned char deltaX;
	unsigned char deltaY;
    DELAY_STATE myState;
    clock_t my_begin_time;
    double delay;
} NuevoEmoji;

NuevoEmoji *New_emoji();
NuevoEmoji *Construct_emoji(char **emojiMatrix, unsigned char posx , unsigned char posy, unsigned char delX, unsigned char delY, double delay1);

void setEmoji(NuevoEmoji *const me, char *emojiMatrix[]);
void setPositionX(NuevoEmoji *const me, unsigned char posx);
void setPositionY(NuevoEmoji *const me, unsigned char posy);
void setDeltaX(NuevoEmoji *const me, unsigned char delx);
void setDeltaY(NuevoEmoji *const me, unsigned char dely);
void setDelay(NuevoEmoji *const me, double delay1);
void setState(NuevoEmoji *const me, DELAY_STATE myNewState);
void setBeginTime(NuevoEmoji *const me, clock_t beginTime);

char **getEmoji(NuevoEmoji *const me);
unsigned char getPositionX(NuevoEmoji *const me);
unsigned char getPositionY(NuevoEmoji *const me);
unsigned char getDeltaX(NuevoEmoji *const me);
unsigned char getDeltaY(NuevoEmoji *const me);
double getDelay(NuevoEmoji *const me);
DELAY_STATE getMyState(NuevoEmoji *const me);
clock_t getMyTime(NuevoEmoji *const me);

void drawEmojiElement( NuevoEmoji *const me);
void clearEmojiElement( NuevoEmoji *const me);

void collition(NuevoEmoji *const me, unsigned char width, unsigned char height);

void emojiDelayFunction(NuevoEmoji *const me);


#endif