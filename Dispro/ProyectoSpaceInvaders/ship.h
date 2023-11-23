#ifndef SHIP_H
#define SHIP_H

#include "alien.h"

// struct nave;
typedef struct {
  struct nave const *vptr;
  int color;
  int posx;
  int posy;
  int posFinx;
  int posFiny;
  int tamx;
  int tamy;
  char *apariencia[6];
  int alive;
} NuevaNave;

char *canonSprite[] = {"       █       ", "      ███      ", "  ███████████  ",
                       "███████████████", "███████████████", ""};
char *canonVoid[] = {"               ", "               ", "              ",
                       "               ", "               ", ""};

NuevaNave *New_Ship();
NuevaNave* Nave_ctor(NuevaNave *const me, char *apariencia[], int color, int posx,
               int posy, int tamx, int tamy);
NuevaNave *Clear_NuevaNave(NuevaNave *me, char *model[]);
void shipDistanciax(NuevaNave *const me, int nuevox);
void shipDistanciay(NuevaNave *const me, int nuevoy);
void setShipApariencia(NuevaNave *const me, char *apariencia[]);
char **getShipApariencia(NuevaNave *const me);
void setShipx(NuevaNave *const me, int posx);
int getShipx(NuevaNave *const me);
void setShipy(NuevaNave *const me, int posy);
int getShipy(NuevaNave *const me);
void setShipFinx(NuevaNave *const me);
int getShipFinx(NuevaNave *const me);
void setShipFiny(NuevaNave *const me);
int getShipFiny(NuevaNave *const me);
void setShipTamx(NuevaNave *const me, int posx);
int getShipTamx(NuevaNave *const me);
void setShipTamy(NuevaNave *const me, int posx);
int getShipTamy(NuevaNave *const me);
void setAlive(NuevaNave *const me, int alive1);
int getAlive(NuevaNave *const me);
void printSpaceship(NuevaNave *const me);
void shipGotoxy(NuevaNave *const me, int x, int y);
void PrintShipMatrix(NuevaNave *const me, char *reg[], int posx, int posy);
int shipCollition(NuevaNave *const me, Alien* alien);
int shipCollitionArr(NuevaNave *const me, Alien* alien[], int tam);

#endif