#include "bullet.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct BULLET_T {
  int Color;
  int Position[2];
  char *Draw;
  int TimeF;
  int state;
  clock_t previous;
};


/*FN****************************************************************************
 *
 *   BULLET_T *Bullet_new());
 *
 *   Purpose: Creation of a new bullet in memory.
 *
 *   Plan:  Use to instance objects of type bullet.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation and change name
 *   Apr 01/2023  Collin Sanchez   Implementaton
 *******************************************************************************/
BULLET_T *Bullet_new() 
{ 
  return (BULLET_T *)malloc(sizeof(BULLET_T)); 
}

/*FN****************************************************************************
 *
 *   BULLET_T *Bullet_new_initate(char *dr, int col, int pos[2], int time);
 *
 *   Purpose: Creation of a new bullet in memory.
 *
 *   Plan: Use to instance objects.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation and change name
 *   Apr 01/2023  Collin Sanchez   Implementaton
 *******************************************************************************/
BULLET_T *Bullet_new_initate(char *dr, int col, int pos[2], int time) 
{
  BULLET_T *temp = (BULLET_T *)malloc(sizeof(BULLET_T));

  temp->Draw = dr;
  temp->TimeF = time;
  temp->Color = col;
  temp->state = 1;

  for (int i = 0; i < 2; i++) {
    temp->Position[i] = pos[i];
  }

  return temp;
}

/*FN****************************************************************************
 *
 *   int Bullet_free(BULLET_T *this)
 *
 *   Purpose: Free bullet in memory.
 *
 *   Plan:  Use to instance objects.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation and change name
 *   Apr 01/2023  Collin Sanchez   Implementaton
 *******************************************************************************/
int Bullet_free(BULLET_T *this) {
  free(this);
  return 1;
}

//////////////////////////SETTERS AND GETTERS///////////////////////////////////

/*FN****************************************************************************
 *
 *   BULLET_T *BulletColor_set(BULLET_T *this, int x)
 *
 *   Purpose: Setter of the color of the bullet.
 *
 *   Plan:  Setter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation and change name
 *   Apr 01/2023  Collin Sanchez   Implementaton
 *******************************************************************************/
BULLET_T *BulletColor_set(BULLET_T *this, int x) 
{
  this->Color = x;
  return this;
}

/*FN****************************************************************************
 *
 *   int BulletColor_get(BULLET_T *this) 
 *
 *   Purpose: Getter of the color of the bullet.
 *
 *   Plan:  Getter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation and change name
 *   Apr 01/2023  Collin Sanchez   Implementaton
 *******************************************************************************/
int BulletColor_get(BULLET_T *this) 
{ 
  return this->Color; 
}

/*FN****************************************************************************
 *
 *   BULLET_T *BulletPosition_set(BULLET_T *this, int x[2])
 *
 *   Purpose: Setter of the position (x,y) of the bullet
 *
 *   Plan:  Setter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation and change name
 *   Apr 01/2023  Collin Sanchez   Implementaton
 *******************************************************************************/
BULLET_T *BulletPosition_set(BULLET_T *this, int x[2]) 
{
  for (int i = 0; i < 2; i++) 
  {
    this->Position[i] = x[i];
  }
  return this;
}

/*FN****************************************************************************
 *
 *   int *BulletPosition_get(BULLET_T *this)
 *
 *   Purpose: Getter of the position (x,y) of the bullet, via pointer.
 *
 *   Plan:  Getter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation and change name
 *   Apr 01/2023  Collin Sanchez   Implementaton
 *******************************************************************************/
int *BulletPosition_get(BULLET_T *this) 
{
  return this->Position; 
}

/*FN****************************************************************************
 *
 *   BULLET_T *BulletDraw_set(BULLET_T *this, char *x)
 *
 *   Purpose: Setter of the drawing (model) of the bullet.
 *
 *   Plan:  Setter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation and change name
 *   Apr 01/2023  Collin Sanchez   Implementaton
 *******************************************************************************/
BULLET_T *BulletDraw_set(BULLET_T *this, char *x) 
{
  this->Draw = x;
  return this;
}

/*FN****************************************************************************
 *
 *   char *BulletDraw_get(BULLET_T *this)
 *
 *   Purpose: Getter of the drawing (model) of the bullet.
 *
 *   Plan:  Getter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation and change name
 *   Apr 01/2023  Collin Sanchez   Implementaton
 *******************************************************************************/
char *BulletDraw_get(BULLET_T *this) 
{ 
  return this->Draw; 
}

/*FN****************************************************************************
 *
 *   BULLET_T *BulletTimeF_set(BULLET_T *this, int t) 
 *
 *   Purpose: Setter of the bullet's timer.
 *
 *   Plan:  Setter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation and change name
 *   Apr 01/2023  Collin Sanchez   Implementaton
 *******************************************************************************/
BULLET_T *BulletTimeF_set(BULLET_T *this, int t) 
{
  this->TimeF = t;
  return this;
}

/*FN****************************************************************************
 *
 *   int BulletTimeF_get(BULLET_T *this) 
 *
 *   Purpose: Getter of the bullet's timer.
 *
 *   Plan:  Getter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation and change name
 *   Apr 01/2023  Collin Sanchez   Implementaton
 *******************************************************************************/
int BulletTimeF_get(BULLET_T *this) 
{ 
  return this->TimeF; 
}

/*FN****************************************************************************
 *
 *   BULLET_T *BulletState_set(BULLET_T *this, int s)
 *
 *   Purpose: Setter of the bullet state.
 *
 *   Plan:  Setter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation and change name
 *   Apr 01/2023  Collin Sanchez   Implementaton
 *******************************************************************************/
BULLET_T *BulletState_set(BULLET_T *this, int s) 
{
  this->state = s;
  return this;
}

/*FN****************************************************************************
 *
 *  int BulletState_get(BULLET_T *this) 
 *
 *   Purpose: Getter of the bullet state.
 *
 *   Plan:  Getter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation and change name
 *   Apr 01/2023  Collin Sanchez   Implementaton
 *******************************************************************************/
int BulletState_get(BULLET_T *this) 
{ 
  return this->state; 
}

/*FN****************************************************************************
 *
 *  int BulletLim(int y, int min, int max)
 *
 *   Purpose: Validate if the bullet is inside the boundaries.
 *
 *   Plan:  Collision checker with wall.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation and change name
 *   Apr 01/2023  Collin Sanchez   Implementaton
 *******************************************************************************/
int BulletLim(int y, int min, int max) {
  if (y >= min && y <= max) {
    return 0;
  } else {
    return 1;
  }
}

/*FN****************************************************************************
 *
 *  void MoveBullet(int x, int y) 
 *
 *   Purpose: Gotoxy variant for the bullet.
 *
 *   Plan:  Movement.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation and change name
 *   Apr 01/2023  Collin Sanchez   Implementaton
 *******************************************************************************/
void MoveBullet(int x, int y) 
{
  printf("%c[%d;%df", 0x1B, y, x); 
}

/*FN****************************************************************************
 *
 *  void MoveBullet(int x, int y) 
 *
 *   Purpose:Custom sleep based on clock function
 *
 *   Plan:  Movement.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation
 *   Apr 01/2023  Collin Sanchez   Implementaton
 *******************************************************************************/
void MySleep(int time) {
  int mils = 1000 * time;
  clock_t s_time = clock();

  while (clock() < s_time + mils) {
    ;
  }
}

/*FN****************************************************************************
 *
 *   void BulletAnimation(BULLET_T *bullet, int lmin, int lmax)
 *
 *   Purpose: Animation according states given.
 *
 *   Plan:  Movement.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation and change name
 *   Apr 01/2023  Collin Sanchez   Implementaton
 *******************************************************************************/
void BulletAnimation(BULLET_T *bullet, int lmin, int lmax) {

  switch (bullet->state) {
  case 1: {
    if (BulletLim(BulletPosition_get(bullet)[1] - 1, lmin, lmax) == 0) {
      MoveBullet(BulletPosition_get(bullet)[0], BulletPosition_get(bullet)[1]);
      printf(" ");
      BulletPosition_get(bullet)[1]--;
      MoveBullet(BulletPosition_get(bullet)[0], BulletPosition_get(bullet)[1]);
      printf("\x1b[38;5;%dm", BulletColor_get(bullet));
      printf("%s\n", BulletDraw_get(bullet));
      // MySleep(TimeF_get(bullet));
      bullet->previous = clock();
      bullet->state = 3;
    } else {
      MoveBullet(BulletPosition_get(bullet)[0], BulletPosition_get(bullet)[1] + 1);
      printf(" \n");
    }

    break;
  }
  case 2: {
    if (BulletLim(BulletPosition_get(bullet)[1] + 1, lmin, lmax) == 0) {
      MoveBullet(BulletPosition_get(bullet)[0], BulletPosition_get(bullet)[1]);
      printf(" ");
      BulletPosition_get(bullet)[1]++;
      MoveBullet(BulletPosition_get(bullet)[0], BulletPosition_get(bullet)[1]);
      printf("\x1b[38;5;%dm", BulletColor_get(bullet));
      printf("%s\n", BulletDraw_get(bullet));
      bullet->previous = clock();
      bullet->state = 3;
    } else {
      MoveBullet(BulletPosition_get(bullet)[0], BulletPosition_get(bullet)[1]);
      printf(" \n");
    }
    break;
  }
  case 3: {
    if (bullet->previous + 1000 * (bullet->TimeF) > clock()) {
      bullet->state = 3;
    } else {
      bullet->state = 2;
    }

    break;
  }
  }
}

/*FN****************************************************************************
 *
 *   void BulletAnimation(BULLET_T *bullet, int lmin, int lmax)
 *
 *   Purpose: Animation according states given.
 *
 *   Plan:  Movement.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation
 *   May 23/2023  D.F. Lopez       Implementaton
 *******************************************************************************/
void BulletUpAnimation(BULLET_T *bullet, int lmin, int lmax)
{
    MoveBullet(BulletPosition_get(bullet)[0], BulletPosition_get(bullet)[1]);
    printf(" ");
    int pos[2];
    pos[0] = BulletPosition_get(bullet)[0];
    pos[1] = BulletPosition_get(bullet)[1] - 1;
    BulletPosition_set(bullet, pos);
    MoveBullet(BulletPosition_get(bullet)[0], BulletPosition_get(bullet)[1]);
    printf("\x1b[38;5;%dm", BulletColor_get(bullet));
    printf("%s\n", BulletDraw_get(bullet));
}