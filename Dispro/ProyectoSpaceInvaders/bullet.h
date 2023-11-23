#ifndef BULLET_H
#define BULLET_H

typedef struct BULLET_T BULLET_T;

/*
  A continuacion, Los prototipos de los metodos constructor, destructor
  y adicionalmente un metodo para crear el objeto inicializado

  BASADOS EN LAS PLANTILLAS DEL Ing. giraldo
*/
BULLET_T *Bullet_new();
BULLET_T *Bullet_new_initate(char *, int , int [2], int);
int Bullet_free(BULLET_T*);

/*
  A continuacion los metodos, SETTER y GETTER para cada uno de los atributos
  del objeto BULLET

  BASADOS EN LAS PLANTILLAS DEL Ing. giraldo
*/
BULLET_T* BulletColor_set(BULLET_T*, int);
int BulletColor_get(BULLET_T*);
BULLET_T* BulletPosition_set(BULLET_T*, int[2]);
int* BulletPosition_get(BULLET_T*);
BULLET_T* BulletDraw_set(BULLET_T*,char*);
char* BulletDraw_get(BULLET_T*);
BULLET_T* BulletTimeF_set(BULLET_T*, int);
int BulletTimeF_get(BULLET_T*);

/*
  Por ultimo, los prototipos de las acciones que tendra el objeto que seran:

  -Lim(); encargado de asegurarse que la bala no exceda los limites establecidos.
  -MoveBullet(); que se encargara de mover el cursor para poder realizar la animacion.
  -MySleep(); Una version de la funcion Sleep implementada con time.h .
  -Animation(); Funcion final encargada de realizar la animacion haciendo uso de todas las funciones
                mencionadas anteriormente.
*/
int BulletLim(int, int, int);
void MoveBullet(int, int);
void MySleep(int);
void BulletAnimation(BULLET_T *bullet, int , int );
void BulletUpAnimation(BULLET_T *bullet, int lmin, int lmax);

#endif