/* Ruler 1         2         3         4         5         6         7        */

/********************************** Headers ***********************************/

/* ------------------------ Inclusion of Std Headers ------------------------ */
#include <stdio.h>
#include <stdlib.h>
/* ------------------------ Inclusion of Own Headers ------------------------ */

#include "alien.h"
#include "custom_utilities.h"
#include "bullet.h"

/************************** Declarations of New Types *************************/

struct Alien {
  int x;
  int y;
  int color;
  char *alien[6];
  double time;
  int size_x;
  int size_y;
  int shoot_indicator; // 0 (No bullet), 1 (Launch bullet), 2 (Bullet moving)
  int ini_x;
  int ini_y;
  int fin_x;
  int fin_y;
  int dir;
  int alive;
};
///////////////////////// Definition of Public Methods ////////////////////////

/*FN****************************************************************************
 *
 *   Alien *New_Alien()
 *
 *   Purpose: Create a new alien in memory.
 *
 *   Plan:  Instance of an alien.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation
 *   May 22/2023  Jaime Avendaño   Corrections
 *   Apr 01/2023  Jaime Avendaño   Implementaton
 *******************************************************************************/
Alien *New_Alien() 
{ 
  return (Alien *)malloc(sizeof(Alien)); 
}


/*FN****************************************************************************
 *
 *   Alien *Construct_alien(char *alien[], int x, int y, double time, int size_x, 
                      int size_y, int color))
 *
 *   Purpose: Constructor of an alien object.
 *
 *   Plan:  Instance of an alien.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation
 *   May 22/2023  Jaime Avendaño   Corrections
 *   Apr 01/2023  Jaime Avendaño   Implementaton
 *******************************************************************************/
Alien *Construct_alien(char *alien[], int x, int y, double time, int size_x, 
                      int size_y, int color)
{
  Alien *ali_obj = New_Alien();
  Set_AlienX(ali_obj, x);
  Set_AlienY(ali_obj, y);
  Set_Aliencolor(ali_obj, color);
  Set_Alientime(ali_obj, time);
  Set_Alien_size_X(ali_obj, size_x);
  Set_Alien_size_Y(ali_obj, size_y);
  printcolor(color);
  Set_Alien(ali_obj, alien);
  return ali_obj;
}


/*FN****************************************************************************
 *
 *   void distx(Alien *this, int xf)
 *
 *   Purpose: Set alien pos in x after change.
 *
 *   Plan:  Movement.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation
 *   May 22/2023  Jaime Avendaño   Corrections
 *   Apr 01/2023  Jaime Avendaño   Implementaton
 *******************************************************************************/
void distx(Alien *this, int xf) 
{ 
  Set_AlienX(this, this->x + xf); 
}

/*FN****************************************************************************
 *
 *   void disty(Alien *this, int yf)
 *
 *   Purpose: Set alien pos in y after change.
 *
 *   Plan:  Movement.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation
 *   May 22/2023  Jaime Avendaño   Corrections
 *   Apr 01/2023  Jaime Avendaño   Implementaton
 *******************************************************************************/
void disty(Alien *this, int yf) 
{ 
  Set_AlienY(this, this->y + yf); 
}

int limAlien(Alien *this)
{
  if(Get_AlienDir(this) > 0 &&  
     Get_AlienX(this) + Get_Alien_size_X(this) > Get_AlienFinX(this))
  {
    Set_AlienDir(this, (int) Get_AlienDir(this) *-1);
    return 3;
  }
  else if(Get_AlienDir(this) < 0 &&  
     Get_AlienX(this) < Get_AlienIniX(this))
  {
    Set_AlienDir(this, (int) Get_AlienDir(this) *-1);
    return 2;
  }
  return 1;
}

/*FN****************************************************************************
 *
 *   int Alien_CollisionBullet(Alien *this, BULLET_T *bullet)
 *
 *   Purpose: Verify collision between a bullet and an alien (1 = true).
 *
 *   Plan:  Action and collisions.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 29/2023  D.F. Lopez       Documentation
 *   May 29/2023  D.F. Lopez       Implementation
 *******************************************************************************/
int Alien_CollisionBullet(Alien *this, BULLET_T *bullet)
{
  if( BulletPosition_get(bullet)[0] > Get_AlienX(this) &&
      BulletPosition_get(bullet)[0] < Get_AlienX(this) + Get_Alien_size_X(this) &&
      BulletPosition_get(bullet)[1] == Get_AlienY(this) + Get_Alien_size_Y(this))
  {
    return 1;
  }
  return 0;
}

///////////////////////////SETTERS/////////////////////////////////////////////

/*FN****************************************************************************
 *
 *   Alien *Set_Alien(Alien *me, char *alien[])
 *
 *   Purpose: Setter of the alien model (string design).
 *
 *   Plan:  Setter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation
 *   May 22/2023  Jaime Avendaño   Corrections
 *   Apr 01/2023  Jaime Avendaño   Implementaton
 *******************************************************************************/
Alien *Set_Alien(Alien *me, char *alien[]) 
{
  print_figure(Get_AlienX(me), Get_AlienY(me), alien);
}

/*FN****************************************************************************
 *
 *   Alien *Set_AlienX(Alien *this, int x)
 *
 *   Purpose: Setter of the alien x position.
 *
 *   Plan:  Setter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation
 *   May 22/2023  Jaime Avendaño   Corrections
 *   Apr 01/2023  Jaime Avendaño   Implementaton
 *******************************************************************************/
Alien *Set_AlienX(Alien *this, int x) 
{
  this->x = x;
  return this;
}

/*FN****************************************************************************
 *
 *   Alien *Set_AlienY(Alien *this, int y)
 *
 *   Purpose: Setter of the alien x position.
 *
 *   Plan:  Setter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation
 *   May 22/2023  Jaime Avendaño   Corrections
 *   Apr 01/2023  Jaime Avendaño   Implementaton
 *******************************************************************************/
Alien *Set_AlienY(Alien *this, int y) 
{
  this->y = y;
  return this;
}

/*FN****************************************************************************
 *
 *   Alien *Set_Alientime(Alien *this, double time)
 *
 *   Purpose: Setter of the alien's timer.
 *
 *   Plan:  Setter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation
 *   May 22/2023  Jaime Avendaño   Corrections
 *   Apr 01/2023  Jaime Avendaño   Implementaton
 *******************************************************************************/
Alien *Set_Alientime(Alien *this, double time) 
{
  this->time = time;
  return this;
}

/*FN****************************************************************************
 *
 *   Alien *Set_Alien_size_X(Alien *this, int size_x)
 *
 *   Purpose: Setter of the alien's size x.
 *
 *   Plan:  Setter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation
 *   May 22/2023  Jaime Avendaño   Corrections
 *   Apr 01/2023  Jaime Avendaño   Implementaton
 *******************************************************************************/
Alien *Set_Alien_size_X(Alien *this, int size_x) 
{
  this->size_x = size_x;
  return this;
}

/*FN****************************************************************************
 *
 *   Alien *Set_Alien_size_Y(Alien *this, int size_y)
 *
 *   Purpose: Setter of the alien's size y.
 *
 *   Plan:  Setter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation
 *   May 22/2023  Jaime Avendaño   Corrections
 *   Apr 01/2023  Jaime Avendaño   Implementaton
 *******************************************************************************/
Alien *Set_Alien_size_Y(Alien *this, int size_y) 
{
  this->size_y = size_y;
  return this;
}

/*FN****************************************************************************
 *
 *   Alien *Set_Aliencolor(Alien *this, int color)
 *
 *   Purpose: Setter of the color to print the alien.
 *
 *   Plan:  Setter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation
 *   May 22/2023  Jaime Avendaño   Corrections
 *   Apr 01/2023  Jaime Avendaño   Implementaton
 *******************************************************************************/
Alien *Set_Aliencolor(Alien *this, int color) 
{
  this->color = color;
  return this;
}

/*FN****************************************************************************
 *
 *   Alien *Set_Alien_shoot_ind(Alien *this, int shoot_indicator)
 *
 *   Purpose: Setter of the shoot indicator.
 *
 *   Plan:  Setter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation
 *   May 22/2023  Jaime Avendaño   Corrections
 *   Apr 01/2023  Jaime Avendaño   Implementaton
 *******************************************************************************/
Alien *Set_Alien_shoot_ind(Alien *this, int shoot_indicator) 
{
  this->shoot_indicator = shoot_indicator;
  return this;
}

/*FN****************************************************************************
 *
 *   Alien *Set_AlienIniX(Alien *this, int ini_x) 
 *
 *   Purpose: Setter of the beginning boundary for x position.
 *
 *   Plan:  Setter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 26/2023  D.F. Lopez       Documentation
 *   May 26/2023  D.F. Lopez       Implementaton
 *******************************************************************************/
Alien *Set_AlienIniX(Alien *this, int ini_x) 
{
  this->ini_x = ini_x;
  return this;
}

/*FN****************************************************************************
 *
 *   Alien *Set_AlienIniY(Alien *this, int ini_y) 
 *
 *   Purpose: Setter of the beginning boundary for u position.
 *
 *   Plan:  Setter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 26/2023  D.F. Lopez       Documentation
 *   May 26/2023  D.F. Lopez       Implementaton
 *******************************************************************************/
Alien *Set_AlienIniY(Alien *this, int ini_y) 
{
  this->ini_y = ini_y;
  return this;
}

/*FN****************************************************************************
 *
 *   Alien *Set_AlienFinX(Alien *this, int fin_x) 
 *
 *   Purpose: Setter of the ending boundary for x position.
 *
 *   Plan:  Setter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 26/2023  D.F. Lopez       Documentation
 *   May 26/2023  D.F. Lopez       Implementaton
 *******************************************************************************/
Alien *Set_AlienFinX(Alien *this, int fin_x) 
{
  this->fin_x = fin_x;
  return this;
}

/*FN****************************************************************************
 *
 *   Alien *Set_AlienFinY(Alien *this, int fin_y) 
 *
 *   Purpose: Setter of the ending boundary for y position.
 *
 *   Plan:  Setter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 26/2023  D.F. Lopez       Documentation
 *   May 26/2023  D.F. Lopez       Implementaton
 *******************************************************************************/
Alien *Set_AlienFinY(Alien *this, int fin_y) 
{
  this->fin_y = fin_y;
  return this;
}

/*FN****************************************************************************
 *
 *   Alien *Set_AlienAlive(Alien *this, int alive)  
 *
 *   Purpose: Setter of the status, 1 is alive or 0 is dead.
 *
 *   Plan:  Setter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 26/2023  D.F. Lopez       Documentation
 *   May 26/2023  D.F. Lopez       Implementaton
 *******************************************************************************/
Alien *Set_AlienAlive(Alien *this, int alive) 
{
  this->alive = alive;
  return this;
}

/*FN****************************************************************************
 *
 *   Alien *Set_AlienDir(Alien *this, int dir)  
 *
 *   Purpose: Setter of the direction (positive -> right) or (negative -> left)
 *
 *   Plan:  Setter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 26/2023  D.F. Lopez       Documentation
 *   May 26/2023  D.F. Lopez       Implementaton
 *******************************************************************************/
Alien *Set_AlienDir(Alien *this, int dir) 
{
  this->dir = dir;
  return this;
}

/////////////////////////////////////GETTERS///////////////////////////////////

/*FN****************************************************************************
 *
 *   **Get_Alien(Alien *this)
 *
 *   Purpose: Getter of the alien drawing (model).
 *
 *   Plan:  Getter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation
 *   May 22/2023  Jaime Avendaño   Corrections
 *   Apr 01/2023  Jaime Avendaño   Implementaton
 *******************************************************************************/
char **Get_Alien(Alien *this) 
{ 
  return this->alien; 
}

/*FN****************************************************************************
 *
 *   **Get_AlienX(Alien *this)
 *
 *   Purpose: Getter of the alien x position.
 *
 *   Plan:  Getter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation
 *   May 22/2023  Jaime Avendaño   Corrections
 *   Apr 01/2023  Jaime Avendaño   Implementaton
 *******************************************************************************/
int Get_AlienX(Alien *this) 
{ 
  return this->x; 
}

/*FN****************************************************************************
 *
 *   int Get_AlienY(Alien *this)
 *
 *   Purpose: Getter of the alien y position.
 *
 *   Plan:  Getter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation
 *   May 22/2023  Jaime Avendaño   Corrections
 *   Apr 01/2023  Jaime Avendaño   Implementaton
 *******************************************************************************/
int Get_AlienY(Alien *this) 
{ 
  return this->y;
}

/*FN****************************************************************************
 *
 *   int Get_Alien_size_X(Alien *this)
 *
 *   Purpose: Getter of the alien's x size.
 *
 *   Plan:  Getter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation
 *   May 22/2023  Jaime Avendaño   Corrections
 *   Apr 01/2023  Jaime Avendaño   Implementaton
 *******************************************************************************/
int Get_Alien_size_X(Alien *this) 
{ 
  return this->size_x; 
}

/*FN****************************************************************************
 *
 *   int Get_Alien_size_Y(Alien *this)
 *
 *   Purpose: Getter of the alien's y size.
 *
 *   Plan:  Getter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation
 *   May 22/2023  Jaime Avendaño   Corrections
 *   Apr 01/2023  Jaime Avendaño   Implementaton
 *******************************************************************************/
int Get_Alien_size_Y(Alien *this) 
{ 
  return this->size_y; 
}

/*FN****************************************************************************
 *
 *   int Get_Aliencolor(Alien *this)
 *
 *   Purpose: Getter of the alien's color.
 *
 *   Plan:  Getter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation
 *   May 22/2023  Jaime Avendaño   Corrections
 *   Apr 01/2023  Jaime Avendaño   Implementaton
 *******************************************************************************/
int Get_Aliencolor(Alien *this) 
{ 
  return this->color; 
}

/*FN****************************************************************************
 *
 *   int Get_Alien_shoot_indicator(Alien *this)
 *
 *   Purpose: Getter of the alien's shotter state.
 *
 *   Plan:  Getter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation
 *   May 22/2023  Jaime Avendaño   Corrections
 *   Apr 01/2023  Jaime Avendaño   Implementaton
 *******************************************************************************/
int Get_Alien_shoot_ind(Alien *this) 
{ 
  return this->shoot_indicator; 
}

/*FN****************************************************************************
 *
 *   double Get_Alientime(Alien *this) 
 *
 *   Purpose: Getter of the alien's timer.
 *
 *   Plan:  Getter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 25/2023  D.F. Lopez       Documentation
 *   May 22/2023  Jaime Avendaño   Corrections
 *   Apr 01/2023  Jaime Avendaño   Implementaton
 *******************************************************************************/
double Get_Alientime(Alien *this) 
{ 
  return this->time; 
}

/*FN****************************************************************************
 *
 *   int Get_AlienIniX(Alien *this)  
 *
 *   Purpose: Getter of the alien's beginning limit in x position for animation.
 *
 *   Plan:  Getter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 26/2023  D.F. Lopez       Documentation
 *   May 26/2023  D.F. Lopez       Implementaton
 *******************************************************************************/
int Get_AlienIniX(Alien *this) 
{ 
  return this->ini_x; 
}

/*FN****************************************************************************
 *
 *   int Get_AlienIniY(Alien *this) 
 *
 *   Purpose: Getter of the alien's beginning limit in y position for animation.
 *
 *   Plan:  Getter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 26/2023  D.F. Lopez       Documentation
 *   May 26/2023  D.F. Lopez       Implementaton
 *******************************************************************************/
int Get_AlienIniY(Alien *this) 
{ 
  return this->ini_y; 
}

/*FN****************************************************************************
 *
 *   int Get_AlienFinY(Alien *this)  
 *
 *   Purpose: Getter of the alien's ending limit in x position for animation.
 *
 *   Plan:  Getter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 26/2023  D.F. Lopez       Documentation
 *   May 26/2023  D.F. Lopez       Implementaton
 *******************************************************************************/
int Get_AlienFinX(Alien *this) 
{ 
  return this->fin_x; 
}
/*FN****************************************************************************
 *
 *   int Get_AlienFinY(Alien *this)  
 *
 *   Purpose: Getter of the alien's ending limit in y position for animation.
 *
 *   Plan:  Getter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 26/2023  D.F. Lopez       Documentation
 *   May 26/2023  D.F. Lopez       Implementaton
 *******************************************************************************/
int Get_AlienFinY(Alien *this) 
{ 
  return this->fin_y; 
}

/*FN****************************************************************************
 *
 *   int Get_AlienAlive(Alien *this)   
 *
 *   Purpose: Getter of the status of the alien where 0 is dead and 1 is alive.
 *
 *   Plan:  Getter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 26/2023  D.F. Lopez       Documentation
 *   May 26/2023  D.F. Lopez       Implementaton
 *******************************************************************************/
int Get_AlienAlive(Alien *this) 
{ 
  return this->alive; 
}

/*FN****************************************************************************
 *
 *   int Get_AlienAlive(Alien *this)   
 *
 *   Purpose: Getter of the direction of the alien. If it is positive, it goes
 *   right. Otherwise, it goes left.
 *
 *   Plan:  Getter.
 *
 *   Register of Revisions:
 *
 *   DATE         RESPONSIBLE         COMMENT
 *   -----------------------------------------------------------------------
 *   May 26/2023  D.F. Lopez       Documentation
 *   May 26/2023  D.F. Lopez       Implementaton
 *******************************************************************************/
int Get_AlienDir(Alien *this) 
{ 
  return this->dir; 
}
