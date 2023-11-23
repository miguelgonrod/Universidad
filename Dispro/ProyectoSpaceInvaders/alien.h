/* Ruler 1         2         3         4         5         6         7        */

#ifndef ALIEN
#define ALIEN

#include "custom_utilities.h"
/******************** Declaration of Class with Attributes ********************/
typedef struct Alien Alien;

/************************ Prototypes of Public Methods ************************/

/******************************** Constructor ********************************/

Alien New_alien();
Alien *Construct_alien(char *alien[], int , int, double, int, int, int);

/****************************** SETTERS & GETTERS ****************************/

Alien *Set_Alien(Alien *me, char *alien[]);
Alien *Set_AlienX(Alien *, int);
Alien *Set_AlienY(Alien *, int);
Alien *Set_Alientime(Alien *, double);
Alien *Set_Alien_size_X(Alien *, int);
Alien *Set_Alien_size_Y(Alien *, int);
Alien *Set_Aliencolor(Alien *, int);
Alien *Set_Alien_shoot_ind(Alien *, int);
Alien *Set_AlienIniX(Alien *, int);
Alien *Set_AlienIniY(Alien *, int);
Alien *Set_AlienFinX(Alien *, int);
Alien *Set_AlienFinY(Alien *, int);
Alien *Set_AlienAlive(Alien *, int);
Alien *Set_AlienDir(Alien *, int);

char **Get_Alien(Alien *);
int Get_AlienX(Alien *);
int Get_AlienY(Alien *);
double Get_Alientime(Alien *);
int Get_Alien_size_X(Alien *);
int Get_Alien_size_Y(Alien *);
int Get_Aliencolor(Alien *);
int Get_Alien_shoot_ind(Alien *);
int Get_AlienIniX(Alien *);
int Get_AlienIniY(Alien *);
int Get_AlienFinX(Alien *);
int Get_AlienFinY(Alien *);
int Get_AlienAlive(Alien *);
int Get_AlienDir(Alien *);

/************************** Actions for the Alien **************************/
void distx(Alien *, int);
void disty(Alien *, int);
int limAlien(Alien *);

/************************* Alien models*/
char *alien[] = {"⢀⡴⣿⢦⡀", 
                 "⢈⢝⠭⡫⡁", 
                 ""};/*10 points*/
char *alien1[] = {"⣆⡵⣤⡴⣅⡆", 
                  "⢘⠟⠛⠛⢟", 
                  ""};/*20 points*/ 
char *alien3[] = {"⣴⡶⢿⡿⢶⣦", 
                  "⣉⠽⠫⠝⠯⣉", ""};
char *alien2[] = {"      ", 
                  "      ", 
                  ""};/*30 points*/
char *alien_del[] = {"     ",
                     "     ",
                     ""};
char *ovni[]={"⢀⡴⣾⢿⡿⣷⢦⡀",
              "⠉⠻⠋⠙⠋⠙⠟⠉",
              ""};/*300 points*/
char *explosion[]={
          "\\|/ ",
          "/|\\ ",
          ""};

#endif /* Alien */