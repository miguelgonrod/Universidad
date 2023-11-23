/*
CÓDIGOS REALIZADOS POR:
- Miguel Gonzales
- Jaime Avendaño
- Daniel López
- Collin Sanchez
*/

/****************INCLUDE STD LIBRARIES**********************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/****************INCLUDE CUSTOM LIBRARIES**********************/
#include "alien.c"
#include "alien.h"
#include "bullet.c"
#include "bullet.h"
#include "custom_utilities.c"
#include "custom_utilities.h"
#include "ship.c"
#include "ship.h"
#include "nums.h"

/******** STRUCTURES AND TYPES OF THE PROGRAM **************/
const int lim_xi = 3;
const int lim_xf = 150;
const int lim_yi = 3;
const int lim_yf = 45;
const int num_type1 = 7;
const int num_type2 = 8;
const int num_type3 = 6;
const int size_type1 = 6;
const int size_type2 = 5;
const int size_type3 = 6;
const int tim_al = 3;
const int num_bullets = 5;
void printMenu();
/* --------------------- Finite state machine states -----------------*/
typedef enum {
  MOVING_RIGHT, // Automotic move to right until collision
  MOVING_LEFT   // Automatic move to left until collision
} ALIEN_STATE;

typedef enum {
  WAIT_LETTER, // Wait for letter to determinate move
  MOVE_UPPER,  // Move up once and return to wait letter
  MOVE_LOWER,  // Move down once and return to wait letter
  MOVE_LEFT,   // Move left once and return to wait letter
  MOVE_RIGHT,  // Move right once and return to wait letter
  EXIT,        // Escape if q is typed
  SHOOT        // Shoot a bullet
} SHIP_STATE;

typedef enum {
  CREATION, // Initialize new object
  MOVING,   // Bullet falling
  EXPLOSION, // Change animation
  DELETING,  // Delete when reached boundaries
  WAIT_ORDER, // Wait shoot message
} BULLET_STATE;

////////////////////////FUNCTION PROTOTYPES////////////////////////////

////////////////////// MAIN FOR BASIC INSTANCES //////////////////////
int main(void) 
{
  // ------------------- Variables declarations ----------------------
  int dir_ali = 0;
  int num_x_ali = 1;
  int step_ali = 0;
  int change_ali;
  int pos_bala[2] = {};
  int exit_flag = 1;
  int y_alien, x_alien;
  int scores[3] ={0,0,0};
  int cur_bullet = 0;

  clock_t begin_time_alien = clock();
  clock_t type2_alien_time[num_type2];
  clock_t type1s_alien_time[num_type1];
  clock_t type3s_alien_time[num_type3];
  clock_t begin_time_cannon = clock();
  clock_t begin_time_bullet[num_bullets];
  // -------------------- States declarations -------------------------
  ALIEN_STATE alien_fst = MOVING_RIGHT;
  SHIP_STATE ship_fst = WAIT_LETTER;
  DELAY_STATE alien_timer = FLAG;
  DELAY_STATE ship_timer = FLAG;
  DELAY_STATE bullets_timer[num_bullets];
  BULLET_STATE bullets_fst[num_bullets];
  ALIEN_STATE type1_alien_fst = MOVING_RIGHT;
  DELAY_STATE type1_alien_timer = FLAG;
  ALIEN_STATE type2_alien_fst[num_type2];
  DELAY_STATE type2_alien_timer[num_type2];
  ALIEN_STATE type1s_alien_fst[num_type1];
  DELAY_STATE type1s_alien_timer[num_type1];
  ALIEN_STATE type3s_alien_fst[num_type3];
  DELAY_STATE type3s_alien_timer[num_type3];

  //______________________Main menu________________________________---

  printMenu();

  // ______________________Preparation of terminal_____________________
  int var = system("clear");
  int offset_bullet = 26;
  set_conio_terminal_mode();
  printcolor(4);
  PrintQuad(1, 1, lim_yf + 2, lim_xf + 2,
            "Space Invaders Minimalist by Miguel, Daniel, Jaime and Collin");
  print_figure(lim_xf/2-20,3,score);
  print_score(5,scores, lim_xf/2 - offset_bullet, 0);
  ////////////////////// OBJECT DECLARATIONS ///////////////////////////
  // -------------------- Alien object instances ---------------------------
  // Single alien complete move
  y_alien = 24;
  Alien *ali_obj = Construct_alien(alien, 5, y_alien, 1.0 , 5, 3, 2);
  Set_AlienAlive(ali_obj, 1);

  // Single alien with limits
  y_alien = 21;
  Alien *ali_type_1 = Construct_alien(alien1, 21, y_alien, 3.0 , 6, 3, 2);
  Set_AlienIniX(ali_type_1, lim_xi + 6);
  Set_AlienIniY(ali_type_1, 11);
  Set_AlienFinX(ali_type_1, lim_xf - 6);
  Set_AlienFinY(ali_type_1, 14);
  Set_AlienDir(ali_type_1, 1);
  Set_AlienAlive(ali_type_1, 1);

  // Alien array for the third row.
  Alien *ali_type_2s[num_type2];
  y_alien = 17;
  for(int i=0; i < num_type2; i++)
  {
    x_alien = lim_xi + 1 + i*(lim_xf-lim_xi)/num_type2;
    ali_type_2s[i] = Construct_alien(alien, x_alien, y_alien, tim_al,
                                    size_type2, 3, 2);
    Set_AlienIniX(ali_type_2s[i], x_alien);
    Set_AlienFinX(ali_type_2s[i], (x_alien + (lim_xf-lim_xi)/num_type2));
    Set_AlienIniY(ali_type_2s[i], y_alien);
    Set_AlienFinY(ali_type_2s[i], y_alien);
    Set_AlienDir(ali_type_2s[i], 1);
    Set_AlienAlive(ali_type_2s[i], 1);
    type2_alien_fst[i] = MOVING_RIGHT;
    type2_alien_timer[i] = WAITING;
    type2_alien_time[i] = clock();
  }

  // Alien array for second row.
  Alien *ali_type_1s[num_type1];
  y_alien = 13;
  for(int i=0; i < num_type1; i++)
  {
    x_alien = lim_xi + 1 + i*(lim_xf-lim_xi)/num_type1;
    ali_type_1s[i] = Construct_alien(alien1, x_alien, y_alien, tim_al,
                                    size_type2, 3, 2);
    Set_AlienIniX(ali_type_1s[i], x_alien);
    Set_AlienFinX(ali_type_1s[i], (x_alien + (lim_xf-lim_xi)/num_type2));
    Set_AlienIniY(ali_type_1s[i], y_alien);
    Set_AlienFinY(ali_type_1s[i], y_alien);
    Set_AlienDir(ali_type_1s[i], 1);
    Set_AlienAlive(ali_type_1s[i], 1);
    type1s_alien_fst[i] = MOVING_RIGHT;
    type1s_alien_timer[i] = WAITING;
    type1s_alien_time[i] = clock();
  }

  // Alien array for first row.
  Alien *ali_type_3s[num_type3];
  y_alien = 9;
  for(int i=0; i < num_type3; i++)
  {
    x_alien = lim_xi + 1 + i*(lim_xf-lim_xi)/num_type3;
    ali_type_3s[i] = Construct_alien(alien3, x_alien, y_alien, tim_al,
                                    size_type2, 3, 2);
    Set_AlienIniX(ali_type_3s[i], x_alien);
    Set_AlienFinX(ali_type_3s[i], (x_alien + (lim_xf-lim_xi)/num_type3));
    Set_AlienIniY(ali_type_3s[i], y_alien);
    Set_AlienFinY(ali_type_3s[i], y_alien);
    Set_AlienDir(ali_type_3s[i], 1);
    Set_AlienAlive(ali_type_3s[i], 1);
    type3s_alien_fst[i] = MOVING_RIGHT;
    type3s_alien_timer[i] = WAITING;
    type3s_alien_time[i] = clock();
  }




  // --------------------- Ship object instances -------------------------
  printcolor(3);
  NuevaNave *starship = New_Ship();
  Nave_ctor(starship, canonSprite, 3, (lim_xf-15)/2, 35, 15, 5);
  printSpaceship(starship);

  // --------------------- Bullet instances -------------------------------
  BULLET_T *bullets_ship[num_bullets];
  for(int i=0; i<num_bullets; i++)
  {
    bullets_fst[i] = WAIT_ORDER;
  }

  // ********************** MAIN LOOP OF THE PROGRAM *******************
  while (exit_flag) {

    srand(time(NULL));
    // Timer verification for single alien
    if (alien_timer == FLAG && Get_AlienAlive(ali_obj) == 1)
    {
      // ________________ First Finite State Machine (Alien) _____________
      printcolor(Get_Aliencolor(ali_obj));
      switch (alien_fst)
      {
      case MOVING_RIGHT:
        Set_Alien(ali_obj, alien2);
        distx(ali_obj, 1);
        if (Get_AlienX(ali_obj) + Get_Alien_size_X(ali_obj) >= lim_xf &&
            Get_AlienY(ali_obj) + Get_Alien_size_Y(ali_obj) < lim_yf)
        {
          Set_Alien(ali_obj, alien2);
          Set_Alien(ali_obj, alien);
          alien_fst = MOVING_LEFT;
        }
        else
        {
          Set_Alien(ali_obj, alien);
          alien_fst = MOVING_RIGHT;
        }
        break;

      case MOVING_LEFT:
        Set_Alien(ali_obj, alien2);
        distx(ali_obj, -1);
        if (Get_AlienX(ali_obj) <= lim_xi && Get_AlienY(ali_obj) < lim_yf) {
          Set_Alien(ali_obj, alien2);
          Set_Alien(ali_obj, alien);
          alien_fst = MOVING_RIGHT;
        } else {
          Set_Alien(ali_obj, alien);
          alien_fst = MOVING_LEFT;
        }
        break;
      }
      printcolor(7);
    }
    alien_timer =
        delay_fst_func(alien_timer, Get_Alientime(ali_obj), &begin_time_alien);

    // Timer verification for the ship
    if (ship_timer == FLAG)
    {
      // _____________ Second  Finite State Machine (Cannon)______________
      printcolor(3);
      switch (ship_fst)
      {
        // Wait until a key is pressed and identify the case
        case WAIT_LETTER:
          shipCollition(starship, ali_obj);
          shipCollition(starship, ali_type_1);
          shipCollitionArr(starship, ali_type_2s, num_type2);
          shipCollitionArr(starship, ali_type_1s, num_type1);
          shipCollitionArr(starship, ali_type_3s, num_type3);
          if(getAlive(starship) == 0)
          {
            Clear_NuevaNave(starship, canonVoid);
            return 0;
          }
          if (kbhit())
          {
            
            
            char var = getch();
            switch (var)
            {
              case 'a':
                if(getShipx(starship) > lim_yi )
                {
                  ship_fst = MOVE_LEFT;
                  Clear_NuevaNave(starship, canonVoid);
                }
                break;
              case 'w':
                if(getShipy(starship) > lim_xi )
                {
                  ship_fst = MOVE_LOWER;
                  Clear_NuevaNave(starship, canonVoid);
                }
                break;
              case 'd':
                if(getShipx(starship) + getShipTamx(starship) - 1 < lim_xf )
                {
                  ship_fst = MOVE_RIGHT;
                  Clear_NuevaNave(starship, canonVoid);
                }
                break;
              case 's':
                if(getShipy(starship) + getShipTamy(starship) < lim_yf )
                {
                  ship_fst = MOVE_UPPER;
                  Clear_NuevaNave(starship, canonVoid);
                }
                break;
              case 'q':
                ship_fst = EXIT;
                break;
              // Shoot single bullet
              case 'f':
                for(int b = 0; b < num_bullets; b++)
                {
                  if(bullets_fst[b] == WAIT_ORDER)
                  {
                    bullets_fst[b] = CREATION;
                    system("play -q \"Sounds/shoot.mp3\" -t alsa &");
                    break;
                  }
                }
                break;
              default:
                printSpaceship(starship);
              break;
            }
          }
          break;

        case MOVE_UPPER:
          shipDistanciay(starship, 1);
          Clear_NuevaNave(starship, canonVoid);
          printSpaceship(starship);
          ship_fst = WAIT_LETTER;
          break;

        case MOVE_LOWER:
          shipDistanciay(starship, -1);
          Clear_NuevaNave(starship, canonVoid);
          printSpaceship(starship);
          ship_fst = WAIT_LETTER;
          break;

        case MOVE_LEFT:
          shipDistanciax(starship, -1);
          Clear_NuevaNave(starship, canonVoid);
          printSpaceship(starship);
          ship_fst = WAIT_LETTER;
          break;

        case MOVE_RIGHT:
          shipDistanciax(starship, 1);
          Clear_NuevaNave(starship, canonVoid);
          printSpaceship(starship);
          ship_fst = WAIT_LETTER;
          break;

        case EXIT:
          exit_flag = 0;
          break;
        }
        printcolor(7);
      }
    ship_timer = delay_fst_func(ship_timer, 0.1, &begin_time_cannon);

    // Timer verification for single bullet
    for(int b=0; b<num_bullets; b++)
    {
      if (bullets_fst[b] != WAIT_ORDER)
      {
        if(bullets_timer[b] == FLAG)
        {
        // _____________ Third Finite State Machine (Multiple Bullets)__________
          switch (bullets_fst[b])
          {
            case CREATION:
              pos_bala[0] = getShipx(starship) + 7;
              pos_bala[1] = getShipy(starship) - 1;
              bullets_ship[b] = Bullet_new_initate("^", 3, pos_bala, 1000);
              bullets_fst[b] = MOVING;
              break;
            case MOVING:
              printcolor(BulletColor_get(bullets_ship[b]));
              // Verify collision for single alien
              if(Alien_CollisionBullet(ali_obj, bullets_ship[b]) && Get_AlienAlive(ali_obj))
              {
                Set_AlienAlive(ali_obj, 0);
                bullets_fst[b] = EXPLOSION;
                Set_Alien(ali_obj, alien_del);
                print_score(1,scores,lim_xf/2 - offset_bullet, 0);
              }
              // Verify collision for single alien (the one with limits)
              if(Alien_CollisionBullet(ali_type_1, bullets_ship[b]) && Get_AlienAlive(ali_type_1))
              {
                Set_AlienAlive(ali_type_1, 0);
                bullets_fst[b] = EXPLOSION;
                Set_Alien(ali_type_1, alien2);
                print_score(2,scores, lim_xf/2 - offset_bullet, 0);
              }
              // Verify collision for third row of aliens
              for(int type2=0; type2 < num_type2; type2++)
              {
                if(Alien_CollisionBullet(ali_type_2s[type2], bullets_ship[b]) && Get_AlienAlive(ali_type_2s[type2]))
                {
                  Set_AlienAlive(ali_type_2s[type2], 0);
                  bullets_fst[b] = EXPLOSION;
                  Set_Alien(ali_type_2s[type2], alien_del);
                  print_score(1,scores, lim_xf/2 - offset_bullet, 0);
                }
              }
              // Verify collision for second row of aliens
              for(int type1=0; type1 < num_type1; type1++)
              {
                if(Alien_CollisionBullet(ali_type_1s[type1], bullets_ship[b]) && Get_AlienAlive(ali_type_1s[type1]))
                {
                  Set_AlienAlive(ali_type_1s[type1], 0);
                  bullets_fst[b] = EXPLOSION;
                  Set_Alien(ali_type_1s[type1], alien2);
                  print_score(2,scores, lim_xf/2 - offset_bullet, 0);
                }
              }
              // Verify collision for first row of aliens
              for(int type3=0; type3 < num_type3; type3++)
              {
                if(Alien_CollisionBullet(ali_type_3s[type3], bullets_ship[b]) && Get_AlienAlive(ali_type_3s[type3]))
                {
                  Set_AlienAlive(ali_type_3s[type3], 0);
                  bullets_fst[b] = EXPLOSION;
                  Set_Alien(ali_type_3s[type3], alien_del);
                  print_score(3,scores, lim_xf/2 - offset_bullet, 0);
                }
              }
              // Verify if bullet is out of bounds
              if (BulletLim(BulletPosition_get(bullets_ship[b])[1] + 1, lim_yi + 6, lim_yf) == 1)
              {
                bullets_fst[b] = EXPLOSION;
              }
              else
              {
                BulletUpAnimation(bullets_ship[b], lim_yi, lim_yf);
              }
              break;
            case EXPLOSION:
              gotoxy(BulletPosition_get(bullets_ship[b])[0], BulletPosition_get(bullets_ship[b])[1]);
              printf("֎");
              bullets_fst[b] = DELETING;
              system("play -v 0.08 -q \"Sounds/explosion.mp3\" -t alsa &");
            break;
            case DELETING:
              gotoxy(BulletPosition_get(bullets_ship[b])[0], BulletPosition_get(bullets_ship[b])[1]);
              printf(" ");
              Bullet_free(bullets_ship[b]);
              bullets_fst[b] = WAIT_ORDER;
              break;

            default:
              Bullet_free(bullets_ship[b]);
              break;
          }
        }
        bullets_timer[b] = delay_fst_func(bullets_timer[b], BulletTimeF_get(bullets_ship[b])/1000,
                                      &begin_time_bullet);
      }
    }
    if(type1_alien_timer == FLAG && Get_AlienAlive(ali_type_1) == 1)
    {
      printcolor(Get_Aliencolor(ali_type_1));
      // ______________Fourth Finite State Machine (ALien with limits)_________
      switch (type1_alien_fst)
      {
      case MOVING_RIGHT:
        Set_Alien(ali_type_1, alien2);
        distx(ali_type_1, Get_AlienDir(ali_type_1));
        if( limAlien(ali_type_1) == 1)
        {
          Set_Alien(ali_type_1, alien1);
          type1_alien_fst = MOVING_RIGHT;
        }
        else if( limAlien(ali_type_1) == 3)
        {
          Set_Alien(ali_type_1, alien1);
          type1_alien_fst = MOVING_LEFT;
        }

        break;
      case MOVING_LEFT:
        Set_Alien(ali_type_1, alien2);
        distx(ali_type_1, Get_AlienDir(ali_type_1));
        if( limAlien(ali_type_1) == 1)
        {
          Set_Alien(ali_type_1, alien1);
          type1_alien_fst = MOVING_LEFT;
        }
        else if( limAlien(ali_type_1) == 2)
        {
          Set_Alien(ali_type_1, alien1);
          type1_alien_fst = MOVING_RIGHT;
        }
        break;
      }
    }
    type1_alien_timer =
        delay_fst_func(type1_alien_timer, Get_Alientime(ali_type_1), &begin_time_alien);


    //_______________________ Fifth FSM for third alien row mov______________
    for(int type2=0; type2 < num_type2; type2++)
    {
      // Validate timer and verify if alien is alive
      if(type2_alien_timer[type2] == FLAG && Get_AlienAlive(ali_type_2s[type2]) == 1)
      {
        printcolor(Get_Aliencolor(ali_type_2s[type2]));
        switch (type2_alien_fst[type2])
        {
        case MOVING_RIGHT:
          Set_Alien(ali_type_2s[type2], alien_del);
          distx(ali_type_2s[type2], Get_AlienDir(ali_type_2s[type2]));
          if( limAlien(ali_type_2s[type2]) == 1)
          {
            Set_Alien(ali_type_2s[type2], alien);
            type2_alien_fst[type2] = MOVING_RIGHT;
          }
          else if( limAlien(ali_type_2s[type2]) == 3)
          {
            Set_Alien(ali_type_2s[type2], alien);
            type2_alien_fst[type2] = MOVING_LEFT;
          }

          break;
        case MOVING_LEFT:
          Set_Alien(ali_type_2s[type2], alien_del);
          distx(ali_type_2s[type2], Get_AlienDir(ali_type_2s[type2]));
          if( limAlien(ali_type_2s[type2]) == 1)
          {
            Set_Alien(ali_type_2s[type2], alien);
            type2_alien_fst[type2] = MOVING_LEFT;
          }
          else if( limAlien(ali_type_2s[type2]) == 2)
          {
            Set_Alien(ali_type_2s[type2], alien);
            type2_alien_fst[type2] = MOVING_RIGHT;
          }
          break;
        }
      }
      type2_alien_timer[type2] =  delay_fst_func(type2_alien_timer[type2],
                                  Get_Alientime(ali_type_2s[type2]), &type2_alien_time[type2]);
    }

    //_______________________ Sixth FSM for second alien row mov______________
    for(int type1=0; type1 < num_type1; type1++)
    {
      // Validate timer and verify if alien is alive
      if(type1s_alien_timer[type1] == FLAG && Get_AlienAlive(ali_type_1s[type1]) == 1)
      {
        printcolor(Get_Aliencolor(ali_type_1s[type1]));
        switch (type1s_alien_fst[type1])
        {
        case MOVING_RIGHT:
          Set_Alien(ali_type_1s[type1], alien2);
          distx(ali_type_1s[type1], Get_AlienDir(ali_type_1s[type1]));
          if( limAlien(ali_type_1s[type1]) == 1)
          {
            Set_Alien(ali_type_1s[type1], alien1);
            type1s_alien_fst[type1] = MOVING_RIGHT;
          }
          else if( limAlien(ali_type_1s[type1]) == 3)
          {
            Set_Alien(ali_type_1s[type1], alien1);
            type1s_alien_fst[type1] = MOVING_LEFT;
          }

          break;
        case MOVING_LEFT:
          Set_Alien(ali_type_1s[type1], alien2);
          distx(ali_type_1s[type1], Get_AlienDir(ali_type_1s[type1]));
          if( limAlien(ali_type_1s[type1]) == 1)
          {
            Set_Alien(ali_type_1s[type1], alien1);
            type1s_alien_fst[type1] = MOVING_LEFT;
          }
          else if( limAlien(ali_type_1s[type1]) == 2)
          {
            Set_Alien(ali_type_1s[type1], alien1);
            type1s_alien_fst[type1] = MOVING_RIGHT;
          }
          break;
        }
      }
      type1s_alien_timer[type1] =  delay_fst_func(type1s_alien_timer[type1],
                                  Get_Alientime(ali_type_1s[type1]), &type1s_alien_time[type1]);
    }

    //_______________________ Seventh FSM for first alien row mov______________
    for(int type3=0; type3 < num_type3; type3++)
    {
      // Validate timer and verify if alien is alive
      if(type3s_alien_timer[type3] == FLAG && Get_AlienAlive(ali_type_3s[type3]) == 1)
      {
        printcolor(Get_Aliencolor(ali_type_3s[type3]));
        switch (type3s_alien_fst[type3])
        {
        case MOVING_RIGHT:
          Set_Alien(ali_type_3s[type3], alien2);
          distx(ali_type_3s[type3], Get_AlienDir(ali_type_3s[type3]));
          if( limAlien(ali_type_3s[type3]) == 1)
          {
            Set_Alien(ali_type_3s[type3], alien3);
            type3s_alien_fst[type3] = MOVING_RIGHT;
          }
          else if( limAlien(ali_type_3s[type3]) == 3)
          {
            Set_Alien(ali_type_3s[type3], alien3);
            type3s_alien_fst[type3] = MOVING_LEFT;
          }

          break;
        case MOVING_LEFT:
          Set_Alien(ali_type_3s[type3], alien2);
          distx(ali_type_3s[type3], Get_AlienDir(ali_type_3s[type3]));
          if( limAlien(ali_type_3s[type3]) == 1)
          {
            Set_Alien(ali_type_3s[type3], alien3);
            type3s_alien_fst[type3] = MOVING_LEFT;
          }
          else if( limAlien(ali_type_3s[type3]) == 2)
          {
            Set_Alien(ali_type_3s[type3], alien3);
            type3s_alien_fst[type3] = MOVING_RIGHT;
          }
          break;
        }
      }
      type3s_alien_timer[type3] =  delay_fst_func(type3s_alien_timer[type3],
                                  Get_Alientime(ali_type_3s[type3]), &type3s_alien_time[type3]);
    }
  }
  reset_terminal_mode();
  var = system("clear");
  gotoxy(1, 1);
  printf("Please close the terminal...\n");
  return 0;
} /*main*/


void printMenu()
{
  char *mainMenu[] = {" $$$$$$\\                                                $$$$$$\\                                    $$\\                               ",
                      "$$  __$$\\                                               \\_$$  _|                                   $$ |                              ",
                      "$$ /  \\__| $$$$$$\\   $$$$$$\\   $$$$$$$\\  $$$$$$\\          $$ |  $$$$$$$\\ $$\\    $$\\ $$$$$$\\   $$$$$$$ | $$$$$$\\   $$$$$$\\   $$$$$$$\\ ",
                      "\\$$$$$$\\  $$  __$$\\  \\____$$\\ $$  _____|$$  __$$\\         $$ |  $$  __$$\\$$\\  $$  |\\____$$\\ $$  __$$ |$$  __$$\\ $$  __$$\\ $$  _____|",
                      " \\____$$\\ $$ /  $$ | $$$$$$$ |$$ /      $$$$$$$$ |        $$ |  $$ |  $$ |\\$$\\$$  / $$$$$$$ |$$ /  $$ |$$$$$$$$ |$$ |  \\__|\\$$$$$$\\  ",
                      "$$\\   $$ |$$ |  $$ |$$  __$$ |$$ |      $$   ____|        $$ |  $$ |  $$ | \\$$$  / $$  __$$ |$$ |  $$ |$$   ____|$$ |       \\____$$\\ ",
                      "\\$$$$$$  |$$$$$$$  |\\$$$$$$$ |\\$$$$$$$\\ \\$$$$$$$\\       $$$$$$\\ $$ |  $$ |  \\$  /  \\$$$$$$$ |\\$$$$$$$ |\\$$$$$$$\\ $$ |      $$$$$$$  |",
                      " \\______/ $$  ____/  \\_______| \\_______| \\_______|      \\______|\\__|  \\__|   \\_/    \\_______| \\_______| \\_______|\\__|      \\_______/ ",
                      "          $$ |                                                                                                                       ",
                      "          $$ |                                                                                                                       ",
                      "          \\__|                                                                                                                       ",
                      ""};
  system("clear");

  for (int i = 0; mainMenu[i][0] != '\0'; i++) {
    printf("%s\n", mainMenu[i]);
  }
  system("sleep 2");
} /* printMenu */
