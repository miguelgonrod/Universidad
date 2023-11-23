#include <stdio.h>
#include "ship.h"

NuevaNave *New_Ship() { return (NuevaNave *)malloc(sizeof(NuevaNave)); }

NuevaNave *Nave_ctor(NuevaNave * const me, char *apariencia[], int color, int posx, int posy, int tamx, int tamy){
    for(int i = 0; apariencia[i][0] != '\0'; i++){
        me->apariencia[i] = apariencia[i];
    }
    me->color = color;
    me->posx = posx;
    me->posy = posy;
    me->tamx = tamx;
    me->tamy = tamy;
    //Print_NuevaNave(me, apariencia);
    me->alive = 1;
    me->posFinx = me->posx + me->tamx;
    me->posFiny = me->posy + me->tamy;
    return me;
}

NuevaNave *Clear_NuevaNave(NuevaNave *me, char *model[]) {
  print_figure(getShipx(me), getShipy(me), model);
}

/******************************* shipDistanciax Function ********************************/

/*FN****************************************************************************
*
*   Purpose: To call setx method with the new position in x axis
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

void shipDistanciax(NuevaNave * const me, int nuevox)
{
    setShipx(me, me->posx + nuevox);
}

/******************************* shipDistanciay Function ********************************/

/*FN****************************************************************************
*
*   Purpose: To call sety method with the new position in y axis
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

void shipDistanciay(NuevaNave * const me, int nuevoy)
{
    setShipy(me, me->posy + nuevoy);
}

/******************************* setShipApariencia Function *****************************/

/*FN****************************************************************************
*
*   Purpose: To set a new value for the apariencia attribute
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

void setShipApariencia(NuevaNave * const me, char *apariencia[]){
    for(int i = 0; i != '\0'; i++){
      me->apariencia[i] = apariencia[i];
    }
}

/******************************* getShipApariencia Function *****************************/

/*FN****************************************************************************
*
*   Purpose: To return the value allocated in the apariencia attribute
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

char** getShipApariencia(NuevaNave * const me){
    return me->apariencia;
}

/******************************* setShipx Function ********************************/

/*FN****************************************************************************
*
*   Purpose: To set a new value for the posx attribute
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

void setShipx(NuevaNave * const me, int posx){
    me->posx = posx;
    setShipFinx(me);
}

/******************************* getShipx Function ********************************/

/*FN****************************************************************************
*
*   Purpose: To return the value allocated in the posx attribute
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

int getShipx(NuevaNave * const me){
    return me->posx;
}

/******************************* setShipy Function ********************************/

/*FN****************************************************************************
*
*   Purpose: To set a new value for the attribute posy
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

void setShipy(NuevaNave * const me, int posy){
    me->posy = posy;
    setShipFiny(me);
}

/******************************* getShipy Function ********************************/

/*FN****************************************************************************
*
*   Purpose: To return the value allocated in the posy attribute
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

int getShipy(NuevaNave * const me){
    return me->posy;
}

/******************************* setShipFinx Function ********************************/

/*FN****************************************************************************
*
*   Purpose: To set the final position in x axis of the ship
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

void setShipFinx(NuevaNave *const me){
    me->posFinx = me->posx + me->tamx;
}

/******************************* getShipFinx Function ********************************/

/*FN****************************************************************************
*
*   Purpose: To get the final position in x axis of the ship
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

int getShipFinx(NuevaNave *const me){
    return me->posFinx;
}

/******************************* setShipFiny Function ********************************/

/*FN****************************************************************************
*
*   Purpose: To set the final position in y axis of the ship
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

void setShipFiny(NuevaNave *const me){
    me->posFiny = me->posy + me->tamy;
}

/******************************* getShipFiny Function ********************************/

/*FN****************************************************************************
*
*   Purpose: To get the final position in y axis of the ship
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

int getShipFiny(NuevaNave *const me){
    return me->posFiny;
}

/******************************* setShipTamx Function ********************************/

/*FN****************************************************************************
*
*   Purpose: To set a new value for the attribute tamx
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   May 22/2023  Daniel Lopez  Documentation
*   May 22/2023  Daniel Lopez  Initial implementation
*
*******************************************************************************/

void setShipTamx(NuevaNave * const me, int tamx){
    me->tamx = tamx;
}

/******************************* getShipTamx Function ********************************/

/*FN****************************************************************************
*
*   Purpose: To return the value allocated in the tamx attribute
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   May 22/2023  Daniel Lopez  Documentation
*   May 22/2023  Daniel Lopez  Initial implementation
*
*******************************************************************************/

int getShipTamx(NuevaNave * const me){
    return me->tamx;
}

/******************************* setShipTamy Function ********************************/

/*FN****************************************************************************
*
*   Purpose: To set a new value for the attribute tamy
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   May 22/2023  Daniel Lopez  Documentation
*   May 22/2023  Daniel Lopez  Initial implementation
*
*******************************************************************************/

void setShipTamy(NuevaNave * const me, int tamy){
    me->tamy = tamy;
}

/******************************* getShipTamy Function ********************************/

/*FN****************************************************************************
*
*   Purpose: To return the value allocated in the tamy attribute
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   May 22/2023  Daniel Lopez  Documentation
*   May 22/2023  Daniel Lopez  Initial implementation
*
*******************************************************************************/

int getShipTamy(NuevaNave * const me){
    return me->tamy;
}

void setAlive(NuevaNave *const me, int alive1){
    me->alive = alive1;
}

int getAlive(NuevaNave *const me){
    return me->alive;
}

/******************************* printSpaceship Function ****************************/

/*FN****************************************************************************
*
*   Purpose: To call the PrintMatrix method
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

void printSpaceship(NuevaNave * const me){
    PrintShipMatrix(me, me->apariencia, me->posx, me->posy);
}

/******************************* shipGotoxy Function ********************************/

/*FN****************************************************************************
*
*   Purpose: To print in screen the string in an specific position
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

void shipGotoxy(NuevaNave * const me, int x, int y) {
  printf("\x1b[1;%dm%c[%d;%df", me->color ,0x1B, y, x);
  return;
}

/******************************* PrintShipMatrix Function *******************************/

/*FN****************************************************************************
*
*   Purpose: To call the gotoxy function while printing in screen the calue allocated *            in the apariencia attribute
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   apr 02/2023  Miguel Gonzalez  Documentation
*   Apr 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

void PrintShipMatrix(NuevaNave * const me, char *reg[], int posx, int posy) {
  for (int i = 0; i < 5; i++) {
    shipGotoxy(me, posx, posy + i);
    printf("%s\n", reg[i]);
  }
  return;
}

/******************************* shipCollition Function *******************************/

/*FN****************************************************************************
*
*   Purpose: Check if the ship collides with an alien
*
*   Register of Revisions:
*
*   DATE         RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Jun 02/2023  Miguel Gonzalez  Documentation
*   Jun 02/2023  Miguel Gonzalez  Initial implementation
*
*******************************************************************************/

int shipCollition(NuevaNave *const me, Alien* alien){
    gotoxy(1,31);
    if((((Get_AlienX(alien) >= getShipx(me) && Get_AlienX(alien) + Get_Alien_size_X(alien) <= getShipFinx(me)) &&
       ((Get_AlienY(alien) >= getShipy(me) && Get_AlienY(alien) + Get_Alien_size_Y(alien) <= getShipFiny(me)) ||
       ((Get_AlienY(alien) >= getShipy(me) - 2)))) ||
       ((Get_AlienX(alien) >= getShipx(me) - 3 && Get_AlienX(alien) + Get_Alien_size_X(alien) - 4 <= getShipFinx(me)) &&
       ((Get_AlienY(alien) >= getShipy(me) && Get_AlienY(alien) + Get_Alien_size_Y(alien) <= getShipFiny(me)) ||
       ((Get_AlienY(alien) >= getShipy(me) + 4))))) && Get_AlienAlive(alien))
    {
        Set_AlienAlive(alien, 0);
        setShipApariencia(me, canonVoid);
        Set_Alien(alien, alien_del); 
        me->alive = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}

int shipCollitionArr(NuevaNave *const me, Alien* alien[], int tam){
    for(int numAlien = 0; numAlien < tam; numAlien++){
        if((((Get_AlienX(alien[numAlien]) >= getShipx(me) && Get_AlienX(alien[numAlien]) + Get_Alien_size_X(alien[numAlien]) <= getShipFinx(me)) &&
       ((Get_AlienY(alien[numAlien]) >= getShipy(me) && Get_AlienY(alien[numAlien]) + Get_Alien_size_Y(alien[numAlien]) <= getShipFiny(me)) ||
       ((Get_AlienY(alien[numAlien]) >= getShipy(me) - 2)))) ||
       ((Get_AlienX(alien[numAlien]) >= getShipx(me) - 3 && Get_AlienX(alien[numAlien]) + Get_Alien_size_X(alien[numAlien]) - 4 <= getShipFinx(me)) &&
       ((Get_AlienY(alien[numAlien]) >= getShipy(me) && Get_AlienY(alien[numAlien]) + Get_Alien_size_Y(alien[numAlien]) <= getShipFiny(me)) ||
       ((Get_AlienY(alien[numAlien]) >= getShipy(me) + 4))))) && Get_AlienAlive(alien[numAlien]))
        {
            Set_AlienAlive(alien[numAlien], 0);
            setShipApariencia(me, canonVoid);
            Set_Alien(alien[numAlien], alien_del); 
            me->alive = 0;
            return 1;
        }
    }
    return 0;
}
