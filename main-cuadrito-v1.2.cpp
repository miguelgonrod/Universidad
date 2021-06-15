//Código de proeycto Cuadrito del grupo 04:
//-------------LIBRERIAS DEL PROGRAMA--------------------------------------------------------
#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <cstdlib>
#include <math.h>
#ifdef _WIN32
#include<windows.h>
#endif
using namespace std;
//--------------CONSTANTES Y ESTRUCTURAS------------------------------------------------------
FILE *archivoj;
FILE *reserva;
FILE *records;
FILE *informacion;
FILE *archivou;

const int MJug = 5; //Constante para el tamaño de puntos y gamertag
const int M_filas=39;
const int M_columnas=119;
const int MJ=20;
const int ML=15;

struct jugador
    {
        char nom_jugador [ML];
        char ape_jugador [ML];
        char gamertag[ML];
        int codigo=0;
        int partidas_ganadas=0;
        int juegos=0;
        char inicial;
        int mejor_puntaje=0;
        int puntos=0;
    };
//-----------------------PROTOTIPOS DE FUNCIONES-------------------------------------------------------
void tablero_inicial(int fila, int col,char tablero[][M_columnas]);  //mostrar el tablero inicial con asterisco de ayuda visual
void actualizar(int fila, int col, char tablero[][M_columnas]);  //mostrar el tablero tras actualización de movimiento de un jugador
void tu_turno(int fila, int col,int &turno,char tablero[][M_columnas],jugador partida[],int puntos[],bool &quedarse);  //lee coordenadas de movimiento, verifica y lo despliga, añadiendo puntos respectivos  //obtener la inicial de un nombre
bool valido(int x1,int x2,int y1, int y2); // verifica si las coordenadas son lineal y de largo 1
bool libre(int x,int y,char tablero[][M_columnas]); //verifica si el espacio aun esta libre
bool completo(int x,int y, int fila, int col,char tablero[][M_columnas]);  //verifica si un cuadro se ha llenado o completado por un jugador
bool faltan(char tablero[][M_columnas],int fila, int col);  //si aun existe casillas libres para el juego
void cuadrito_para(int turno, jugador partida[], int x, int y, int pos, char tablero[][M_columnas], int puntos[]);
void asig_puntos(jugador jugadores[], jugador partida[],int num, int puntos[], int num_jugadores);
//void ver_record(jugador jugadores[], int num_jugadores, int opt);
//void mostrar_exportar( int num_jugadores, jugador jugadores [], int opt);
void ganador(int puntos [], int num,jugador jugadores[], int turnos, int num_jugadores, jugador partida[]);
void jugada_maquina(int fila, int col,char tablero[][M_columnas], int puntos[], int &turno, jugador partida[],char tablero_pertenencia[][M_columnas] );//
void jugada_aleatoria(int filas, int col,char tablero[][M_columnas],char tablero_pertenencia[][M_columnas]);
void creacion_usuario(jugador gamer);
void borrado_usuario(jugador gamer, string gamertag);
void borrar();
int vectorizar(jugador jugadores[]);
void desv(jugador jugadores[], int num_jugadores);
void inicial(string nombres,char &inicial);
//-----------------------DESARROLLO DEL MAIN-----------------------------------------------------------

int main ()
{
    int num;
    int filas=9*2-1, columnas=9*2-1;
    int nivel=0;
    int opt=0;
    int turno=0, libres, puntos [MJug];
    char tablero [M_filas][M_columnas];
    char tablero_doc [M_filas][M_columnas];
    char iniciales[MJug];
    char apoyo[ML];
    bool diponible = true;
    jugador jugadores [MJ];
    jugador partida[5];
    jugador gamer;
    int ultimo_codigo = 0;
    string gamertag [MJug];
    string nom_aux;
    char tablero_pertenencia[M_filas][M_columnas];
    //temporal 1
    bool valido = false;
    bool libre = false;
    bool hay_mov = true;
    bool pausa = true;
    bool quedarse = true;
    int num_jugadores=20;
    int posv, yo, j;
    int auxi;
    setlocale(LC_ALL,"");
    num_jugadores=vectorizar(jugadores);
    do
    {
        cout<<"Bienvenido al juego de cuadrito"<<endl;
        cout<<"menú: "<<endl;
        cout<<"1) Jugar \n\t  2) Configurar dificultad \n\t  3) Administrar jugadores \n\t  4) Estadísticas \n\t 5) Salir \n\t"<<endl;
        cout<<"\tSu selección: ";
        cin>>opt;
        if (opt==1)
        {
            do
            {
                cout<<"Bienvenido al menu de cuadrito"<<endl;
                cout<<"menú: "<<endl;
                cout<<"1) Contra la máquina \n\t  2) Multijugador \n\t  3) Instrucciones \n\t  4) Salir y volver al menu principal \n\t"<<endl;
                cout<<"\tSu selección: ";
                cin>>opt;
                if (opt==1)
                {
                   cout<<"Digite un nombre usuario: ";
                   cin>> nom_aux;
                   strcpy(apoyo,nom_aux.c_str());
                   for(int a=0; a<num_jugadores; a++)
                    {
                        if(strcmp(jugadores[a].gamertag,apoyo)==0)
                        {
                            for(int i=0;i<ML;i++){
                                partida[0].gamertag[i]= apoyo[i];
                            }
                        }
                        else if(a==num_jugadores-1)
                        {
                            cout<<"Jugador no hallado"<<endl;
                                cout<<"1)Cree el jugador con el mismo gamertag"<<endl;
                                cout<<"2)presione cualquier otro número para cambiar de gamertag"<<endl;
                                cin>>opt;
                                if(opt==1){
                                    creacion_usuario(gamer);
                                    num_jugadores = vectorizar(jugadores);
                                    partida[0]=jugadores[num_jugadores-1];
                                    break;
                                }else{
                                    break;
                                }
                        }
                    }
                   iniciales[0]='u';
                   iniciales[1]='m';
                   for(int i=0;i<filas; i++)
                    {
                        for(int j=0;j<columnas;j++)
                        {
                            tablero_pertenencia[i][j]=' ';
                        }
                    }
                   tablero_inicial(filas,columnas,tablero);
                    cout<<"\n";
                    srand(time(0));
                    turno=rand()%2;
                    if(turno=1)
                    {
                        jugada_aleatoria(filas,columnas,tablero,tablero_pertenencia);
                        borrar();
                        actualizar(filas,columnas,tablero);
                        turno++;
                    }

                    while(faltan(tablero,filas,columnas)&& quedarse)
                    {
                        turno=turno%2;
                        if(turno==0){
                            tu_turno(filas,columnas,turno,tablero,partida,puntos,quedarse);
                            borrar();
                            actualizar(filas,columnas,tablero);
                        }
                        if(turno==1){
                            jugada_maquina(filas,columnas,tablero,puntos,turno,partida,tablero_pertenencia);
                            borrar();
                            actualizar(filas,columnas,tablero);
                        }
                        turno++;
                    }
                    desv(jugadores, num_jugadores);
                }
                else if (opt==2)
                {
                    cout<<"Digite el número de jugadores de esta partida: ";
                    cin>> num;
                    for(int i=0;i<num; i++)
                    {
                        cout<<"Digite el gamertag del usuario:";
                        cin>> nom_aux;
                        strcpy(apoyo,nom_aux.c_str());
                        //comprobación de existencia
                        for(int a=0; a<num_jugadores; a++)
                        {
                            if(strcmp(jugadores[a].gamertag,apoyo)==0)
                            {
                                cout<<"Jugador existente, puede proseguir"<<endl;
                                partida[i]=jugadores[a];
                                cout<<partida[i].inicial;
                                break;
                            }
                            else if(a==num_jugadores-1)
                            {
                                cout<<"Jugador no hallado"<<endl;
                                cout<<"1)Cree el jugador con el mismo gamertag"<<endl;
                                cout<<"2)presione cualquier otro número para cambiar de gamertag"<<endl;
                                cin>>opt;
                                if(opt==1){
                                    creacion_usuario(gamer);
                                    num_jugadores = vectorizar(jugadores);
                                    partida[i]=jugadores[num_jugadores-1];
                                    cout<<partida[i].inicial;
                                    break;
                                }else{
                                    break;
                                }

                            }
                        }
                    }
                    for(int i=0;i<num;i++)  //ciclo de obtención de iniciales
                    {

                        cout<<"Incial jugador #"<<i<<" :"<<partida[i].inicial<<endl;  //mostrar iniciales de jugadores
                    }

                    num_jugadores=vectorizar(jugadores);
                    tablero_inicial(filas, columnas,tablero);
                    while(faltan(tablero,filas, columnas) && (quedarse == true)) //ciclo de juego
                    {
                        tu_turno(filas,columnas,turno,tablero,partida,puntos,quedarse);
                        borrar();
                        actualizar(filas, columnas,tablero);
                        turno++;  //guía para contadores ,vectores y cuadros completados
                        if(turno>= num)  //reasignacion de turno
                        {
                            turno=0;
                        }
                    }
                    if(quedarse== false)
                    {
                        cout<<"Se ha pausado/salido del juego"<<endl;
                    }
                    else
                    {
                        cout<<"Ha finalizado el juego"<<endl;
                        for(int i=0;i<num;i++){
                            cout<<"Puntos del jugador "<<partida[i].nom_jugador<<": "<<puntos[i]<<endl;
                        }
                        asig_puntos(jugadores,partida,num,puntos,num_jugadores);
                        ganador(puntos,num,jugadores,turno,num_jugadores,partida);
                    }
                    desv(jugadores, num_jugadores);
                }
                else if (opt==3)
                {
                    cout << "Intrucciones de juego: "<<endl;
                    cout << "1) Complete la mayor cantidad de cuadros para ganar. "<<endl;
                    cout << "2) Si completa un cuadro recibe un turno extra."<<endl;
                    cout << "3) Los movimientos se realizan por posiciones en x1, y1, x2, y2 cuyo origen está en la esquina superior izuquierda."<<endl;
                    cout << "4) Los movimientos son válidos si y solo si no se superponen a otros, son continuos y en espacios válidos. "<<endl;
                    break;
                }
            }while (opt!=4);
        }
        else if (opt==2)
        {
            do
            {
                cout<<"Bienvenido al menu de escogencia de dificultad"<<endl;
                cout<<"menú: "<<endl;
                cout<<"1) Principiante \n\t  2) Intermedio \n\t  3) Avanzado \n\t  4) Libre \n\t 5) Salir y volver al menu principal \n\t"<<endl;
                cout<<"\tSu selección: ";
                cin>>opt;
                if (opt==1)
                {
                    filas=9*2-1;
                    columnas=9*2-1;
                    break;
                }
                else if (opt==2)
                {
                    filas=16*2-1;
                    columnas=16*2-1;
                    break;
                }
                else if (opt==3)
                {
                    filas=16*2-1;
                    columnas=30*2-1;
                    break;
                }
                else if (opt==4)
                {
                    cout <<"¿Cuantas filas desea tener? maximo 20"<<endl;
                    cin >> auxi;
                    if(auxi>20 || auxi<=0)
                    {
                        cout<< "Porfavor dijite menos de 20 filas o mas de 0 filas"<<endl;
                        cin >> filas;
                        filas = filas*2-1;
                    }
                    else
                    {
                        filas=auxi*2-1;
                    }
                    cout <<"¿Cuantas columnas desea tener? maximo 60"<<endl;
                    cin >> auxi;
                    if(auxi>60 || auxi<=0)
                    {
                        cout<< "Porfavor dijite menos de 60 columnas o mas de 0 columnas"<<endl;
                        cin >> columnas;
                        columnas = columnas*2-1;
                    }
                    else
                    {
                        columnas=auxi*2-1;
                    }
                    break;
                }
            } while(opt!=5);
        }
        else if (opt==3)
        {
            cout<<"\t1)Crear jugador \n\t2)Eliminar Jugador \n\tOtro numero para volver al menu"<<endl;
            cin>> opt;
            if(opt == 1)
            {
                creacion_usuario(gamer);
            }
            else if(opt == 2)
            {
                cout<<"Digite el gamertag a crear:";
                //cin>> nom_aux;
                getline(cin>>ws,nom_aux);
                borrado_usuario(gamer,nom_aux);
            }
            cout<<"Regresando al menú"<<endl;
        }
        else if (opt==4)
        {
            cout<<"Mostrado y exportacion:\n\t1)Mejores puntajes\n\t2)Ver info del jugador\n\t3)Reporte mejores puntajes3\n\t4)Reporte mejores puntajes\n\tOtra opción para volver al menú"<<endl;
            cin>> opt;
            switch(opt)
            {
            case 1:
                //ver_record(jugadores,num_jugadores,opt);
                break;
            case 2:
                //mostrar_exportar(num_jugadores,jugadores,opt);
                break;
            case 3:
                //ver_record(jugadores,num_jugadores,opt);
                break;
            case 4:
                //mostrar_exportar(num_jugadores,jugadores,opt);
                break;
            default:
                cout<<"Redireccionando al menú"<<endl;
            }
            cout<<"Volviendo al menú"<<endl;
        }
    }while (opt!=5);
    cout<<"Gracias por jugar"<<endl;
    return 0;

}
/*---------------------------------------------------------------------------------------------------------
                                    DEFINICIÓN DE FUNCIONES
---------------------------------------------------------------------------------------------------------*/
//___________________________________________JUGABILIDAD__________________________________________________

//________________________________ASPECTOS RELACIONADOS A JUGABILIDAD____________________________________
/*void obtener_inicial(int num, string nombres[],char iniciales[])
{
    string nom_tem;
    for(int i=0;i<num;i++)  //ciclo para obtener iniciales
    {
        nom_tem= nombres[i];
        iniciales[i]= nom_tem[0];  //uso de la inicial de la cadena para llenado
        for(int j= 0; j<i;j++)
        {
            while(iniciales[j]==iniciales[i])
            {
                cout<<"Digite un nuevo nombre para el jugador:"<<i+1<<endl;
                cin>>nombres[i];
                nom_tem= nombres[i];
                iniciales[i]= nom_tem[0];
            }
        }
    }
    return;
}*/

void tablero_inicial(int fila, int col,char tablero[][M_columnas])
{
    for(int i=0; i<fila; i++)  //llenado inicial de la matriz de juego y tablero
    {
        if(i%2==0)
        {
            for(int j=0; j<col; j++)
            {
                if(j%2==0)
                {
                    tablero[i][j]='*';
                    cout<<tablero[i][j]<<" ";
                }
                else
                {
                    tablero[i][j]=' ';
                    cout<<tablero[i][j]<<" ";
                }
            }
        }
        else
        {
            for(int j=0; j<col; j++)
            {
                tablero[i][j]=' ';
                cout<<tablero[i][j]<<" ";

            }
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    return;
}

void actualizar(int fila, int col, char tablero[][M_columnas])
{
    for(int k=0; k<fila; k++)  //llenado y actualización de la matriz
    {
        for(int l=0; l<col;l++)
        {
            cout<<tablero[k][l]<<" ";
        }
        cout<<endl;
    }
    return;
}

bool valido(int x1,int x2,int y1, int y2)
{
    int cf,cc;
    cf=pow((x2-x1),2);
    cc=pow((y2-y1),2);
    if(cf > 1 || cc > 1)  //si los coordenadas suman más para ser continuas, se descartan
    {
        return false;
    }
    if(cf == 1 && cc == 1)  //si los dos coordenadas son iguales
    {
        return false;
    }
    return true;
}

bool libre(int x,int y, char tablero[][M_columnas])
{
    if(tablero[x][y]==' ') //verifica si el espacio está libre
    {
        return true;
    }
    return false;
}

bool completo(int x,int y,int fila, int col,char tablero[][M_columnas],int &pos)
{
    pos= 0;  //indicador de victoria con las coordenadas: 1 arriba, 2 abajo, 3 derecha y 4 izquierda
    if(tablero[x][y]=='-'  && x!=0 && x!=fila)
    {
        if((tablero[x+1][y-1]=='|' && tablero[x+1][y+1]== '|' && tablero[x+2][y]=='-')&&(tablero[x-1][y-1]=='|' && tablero[x-1][y+1]== '|' && tablero[x-2][y]=='-'))
        {
            pos = 5;
            return true;
        }
        if((tablero[x+1][y-1]=='|' && tablero[x+1][y+1]== '|' && tablero[x+2][y]=='-') )
        {
            pos = 2;
            return true;
        }
        if((tablero[x-1][y-1]=='|' && tablero[x-1][y+1]== '|' && tablero[x-2][y]=='-') )
        {
            pos = 1;
            return true;
        }
    }
    else if(tablero[x][y]=='-'  && x==0)
    {
        if((tablero[x+1][y-1]=='|' && tablero[x+1][y+1]== '|' && tablero[x+2][y]=='-') )
        {
            pos = 2;
            return true;
        }
    }
    else if(tablero[x][y]=='-' && x== fila)
    {
        if((tablero[x-1][y-1]=='|' && tablero[x-1][y+1]== '|' && tablero[x-2][y]=='-') )
        {
            pos = 1;
            return true;
        }
    }
    else if(tablero[x][y]=='|' && y!=0 && y!=col)
    {

        if((tablero[x][y+2]=='|' && tablero[x+1][y+1]=='-' && tablero[x-1][y+1]=='-')&&tablero[x][y-2]=='|' && tablero[x+1][y-1]=='-' && tablero[x-1][y-1]=='-')
        {
            pos = 6;
            return true;
        }
        if(tablero[x][y+2]=='|' && tablero[x+1][y+1]=='-' && tablero[x-1][y+1]=='-')
        {
            pos = 3;
            return true;
        }
        if(tablero[x][y-2]=='|' && tablero[x+1][y-1]=='-' && tablero[x-1][y-1]=='-')
        {
            pos = 4;
            return true;
        }
    }
    else if(tablero[x][y]=='|' && y==0)
    {
        if(tablero[x][y+2]=='|' && tablero[x+1][y+1]=='-' && tablero[x-1][y+1]=='-')
        {
            pos = 3;
            return true;
        }
    }
    else if(tablero[x][y]=='|' && y== col)
    {
        if(tablero[x][y-2]=='|' && tablero[x+1][y-1]=='-' && tablero[x-1][y-1]=='-')
        {
            pos = 4;
            return true;
        }
    }
    return false;  //si no ha completado ningún cuadrodo no manda nada
}

void cuadrito_para(int turno, jugador partida[], int x, int y, int pos,  char tablero[][M_columnas], int puntos[])
{
    cout<<"Se ha completado un cuadro, el jugador "<<partida[turno].nom_jugador<<" obtiene un punto y otro turno"<<endl;
    switch(pos)  //donde va ubicada la inicial para el cuadro completado
    {
        case 1:
            tablero[x-1][y]= partida[turno].inicial;
        break;
        case 2:
            tablero[x+1][y]= partida[turno].inicial;
        break;
        case 3:
            tablero[x][y+1]= partida[turno].inicial;
        break;
        case 4:
            tablero[x][y-1]= partida[turno].inicial;
        break;
        case 5:
            tablero[x+1][y]= partida[turno].inicial;
            tablero[x-1][y]= partida[turno].inicial;
            puntos[turno]+=1;
        break;
        case 6:
            tablero[x][y+1]= partida[turno].inicial;
            tablero[x][y-1]= partida[turno].inicial;
            puntos[turno]+=1;
        break;
        default:
            cout<<"Ha ocurrido un error durante el turno"<<endl;
    }
    return;
}

bool faltan(char tablero[][M_columnas],int fila, int col)
{
   for(int c=1;c<fila;c=c+2)
   {
       for(int d=1;d<col;d=d+2)
       {
           if(tablero[c][d]==' ')
           {
               return true; // si aún hay espacios continua el juego
           }
       }
   }
   return false;  //sino parar el juego
}
//===
void asig_puntos(jugador jugadores[], jugador partida[],int num, int puntos[], int num_jugadores)
{
    for (int in=0; in<num; in++)
    {
        for (int j=0; j<num_jugadores;j++)
        {
        if(strcmp(partida[in].gamertag,jugadores[j].gamertag)==0)
            {
                jugadores[j].juegos=jugadores[j].juegos+1;
                jugadores[j].puntos=jugadores[j].puntos+puntos[in];

                break;
            }
            else if(j==num_jugadores-1)
            {
                cout<<"Ha ocurrido un problema en la asignación de datos"<<endl;
            }
        }
    }
    cout<< "Asignación completa, gracias por jugar"<<endl;
    return;
}
void ganador(int puntos [], int num,jugador jugadores[], int turnos, int num_jugadores, jugador partida[])
{
    jugador vencedor;
    int puntaje_aux=0, puntero;

    for (int i=0; i<num_jugadores; i++)
    {
        if(puntaje_aux<puntos[i]){
            puntaje_aux=puntos[i];
            puntero=i;
        }
    }
    partida[puntero].partidas_ganadas++;
    for (int a=0;a<num_jugadores;a++)
    {
        if(strcmp(partida[puntero].gamertag,jugadores[a].gamertag)==0)
        {
          jugadores[a]=partida[puntero];
          cout<<"Ganador: "<<jugadores[a].nom_jugador<<" o "<<jugadores[a].gamertag<<endl;
          cout<<"---------------------------------Felicitaciones---------------------------------------"<<endl;
           break;
        }
    }

    return;
}
void tu_turno(int fila, int col,int &turno,char tablero[][M_columnas],jugador partida[],int puntos[],bool &quedarse)
{
    int x1,x2,y1,y2,x,y,pos;
    bool gan;
    cout<<"Es el turno del jugador: "<<partida[turno].nom_jugador<<endl;  //lectura de coordenadas
    cout<<"Digite la coordena x1: ";
    cin>> x1;
    cout<<"Digite la coordena y1: ";
    cin>> y1;
    cout<<"Digite la coordena x2: ";
    cin>> x2;
    cout<<"Digite la coordena y2: ";
    cin>> y2;
    cout<<endl;
    if(x1 <=0 || x2<=0 || y1<=0 || y2<=0)  //condición de salida del juego
    {
        quedarse = false;
    }
    else
    {
        x= x1+x2-2;  //asignación para coordenada de matriz tablero
        y= y1+y2-2;
        while(!(valido(x1,x2,y1,y2)) || !(libre(x,y,tablero)))  //verificación de coordenadas, si son válidas
        {
            cout<<"Movimiento inválido, vuelva a digitar su movimiento por favor: "<<endl;
            cout<<"Digite la coordena x1: ";
            cin>> x1;
            cout<<"Digite la coordena y1: ";
            cin>> y1;
            cout<<"Digite la coordena x2: ";
            cin>> x2;
            cout<<"Digite la coordena y2: ";
            cin>> y2;
            cout<<endl;
            x= x1+x2-2;
            y= y1+y2-2;
        }
        if(x%2 == 0 && y%2 !=0)  //asignación de movimiento de acuerdo a posicion en la matriz
        {
            tablero[x][y]= '-';
        }
        else
        {
            tablero[x][y]='|';
        }
        gan = completo(x,y,fila, col,tablero,pos);  //si se ha completado un cuadro
        if(gan==true)
        {
            cuadrito_para( turno,  partida,  x,  y,  pos,  tablero,  puntos);
            puntos[turno]+=1;  //suma de puntos
            turno--; //para repetición de turno
        }
    }
    return;
}

void jugada_aleatoria(int filas, int col,char tablero[][M_columnas],char tablero_pertenencia[][M_columnas])
{
    int fila, columna;
    do
    {
        fila=rand()%filas;
        columna=rand()%col;
    }
    while((fila%2==0 && columna%2==0)||(fila%2!=0 && columna%2!=0));
    if(fila%2==0 && columna%2!=0)
    {
        tablero[fila][columna]='-';
        tablero_pertenencia[fila][columna]='m';
    }
    else if(fila%2!=0 && columna%2==0)
    {
        tablero[fila][columna]='|';
        tablero_pertenencia[fila][columna]='m';
    }
    return;
}

void jugada_maquina(int fila, int col,char tablero[][M_columnas], int puntos[], int &turno, jugador partida[],char tablero_pertenencia[][M_columnas])
{
    int contador_llenos=0, pos;
    bool salir=false, gan=false;
    for(int i=0; i<fila; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(tablero_pertenencia[i][j]=='u'){
                if((i)%2==0 && (j)%2!=0){
                    if(tablero_pertenencia[i+1][j-1]=='u'&&tablero_pertenencia[i+1][j+1]=='u'&&tablero_pertenencia[i+2][j]==' '){
                        tablero_pertenencia[i+2][j]='m';
                        tablero[i+2][j]='-';
                        contador_llenos++;
                        salir=true;
                        gan = completo(i+2,j,fila, col,tablero,pos);
                        if(gan)
                        {
                            cuadrito_para( turno,  partida,  i+2,  j,  pos,  tablero,  puntos);
                            puntos[turno]+=1;  //suma de puntos
                            turno--; //para repetición de turno
                        }
                        break;
                    }else if(tablero_pertenencia[i+1][j-1]==' '&&tablero_pertenencia[i+1][j+1]=='u'&&tablero_pertenencia[i+2][j]=='u'){
                        tablero_pertenencia[i+1][j-1]='m';
                        tablero[i+1][j-1]='|';
                        contador_llenos++;
                        salir=true;
                        gan = completo(i+1,j-1,fila, col,tablero,pos);
                        if(gan)
                        {
                            cuadrito_para( turno,  partida,  i+1,j-1,  pos,  tablero,  puntos);
                            puntos[turno]+=1;  //suma de puntos
                            turno--; //para repetición de turno
                        }
                        break;
                    }else if(tablero_pertenencia[i+1][j-1]=='u'&&tablero_pertenencia[i+1][j+1]==' '&&tablero_pertenencia[i+2][j]=='u'){
                        tablero_pertenencia[i+1][j+1]='m';
                        tablero[i+1][j+1]='|';
                        contador_llenos++;
                        salir=true;
                        gan = completo(i+1,j+1,fila, col,tablero,pos);
                        if(gan)
                        {
                            cuadrito_para( turno,  partida,  i+1,j+1,  pos,   tablero,  puntos);
                            puntos[turno]+=1;  //suma de puntos
                            turno--; //para repetición de turno
                        }
                        break;
                    }
                }else if(i%2!=0&&j%2==0){
                        if(tablero_pertenencia[i-1][j+1]==' '&&tablero_pertenencia[i][j+2]=='u'&&tablero_pertenencia[i+1][j+1]=='u'){
                            tablero_pertenencia[i-1][j+1]='m';
                            tablero[i-1][j+1]='-';
                            contador_llenos++;
                            salir=true;
                            gan = completo(i-1,j+1,fila, col,tablero,pos);
                            if(gan)
                            {
                                cuadrito_para( turno,  partida,  i-1,j+1,  pos,  tablero,  puntos);
                                puntos[turno]+=1;  //suma de puntos
                                turno--; //para repetición de turno
                            }
                            break;
                        }
                    }
            }
            if(tablero_pertenencia[i][j]=='m')
            {
                if((i)%2==0 && (j)%2!=0)
                {
                    if(tablero[i+1][j-1]==' ')
                    {
                        tablero_pertenencia[i+1][j-1]='m';
                        tablero[i+1][j-1]='|';
                        contador_llenos++;
                        salir=true;
                        gan = completo(i+1,j-1,fila, col,tablero,pos);
                        if(gan)
                        {
                            cuadrito_para( turno,  partida,  i+1,j-1,  pos,  tablero,  puntos);
                            puntos[turno]+=1;  //suma de puntos
                            turno--; //para repetición de turno
                        }
                        break;
                    }
                    else if(tablero[i+1][j+1]==' ')
                    {
                        tablero_pertenencia[i+1][j+1]='m';
                        tablero[i+1][j+1]='|';
                        contador_llenos++;
                        salir=true;
                        gan = completo(i+1,j+1,fila, col,tablero,pos);
                        if(gan)
                        {
                            cuadrito_para( turno,  partida,  i+1,j+1,  pos,  tablero,  puntos);
                            puntos[turno]+=1;  //suma de puntos
                            turno--; //para repetición de turno
                        }
                        break;
                    }
                    else if(tablero[i+2][j]==' ')
                    {
                        tablero_pertenencia[i+2][j]='m';
                        tablero[i+2][j]='-';
                        contador_llenos++;
                        salir=true;
                        gan = completo(i+2,j,fila, col,tablero,pos);
                        if(gan)
                        {
                            cuadrito_para( turno,  partida,  i+2,j,  pos,  tablero,  puntos);
                            puntos[turno]+=1;  //suma de puntos
                            turno--; //para repetición de turno
                        }
                        break;
                    }
                    else if(tablero[i-1][j-1]==' ')
                    {
                        tablero_pertenencia[i-1][j-1]='m';
                        tablero[i-1][j-1]='|';
                        contador_llenos++;
                        salir=true;
                        gan = completo(i-1,j-1,fila, col,tablero,pos);
                        if(gan)
                        {
                            cuadrito_para( turno,  partida,  i-1,j-1,  pos,  tablero,  puntos);
                            puntos[turno]+=1;  //suma de puntos
                            turno--; //para repetición de turno
                        }
                        break;
                    }
                    else if(tablero[i-1][j+1]==' ')
                    {
                        tablero_pertenencia[i-1][j+1]='m';
                        tablero[i-1][j+1]='|';
                        contador_llenos++;
                        salir=true;
                        gan = completo(i-1,j+1,fila, col,tablero,pos);
                        if(gan)
                        {
                            cuadrito_para( turno,  partida,  i-1,j+1,  pos,  tablero,  puntos);
                            puntos[turno]+=1;  //suma de puntos
                            turno--; //para repetición de turno
                        }
                        break;
                    }
                    else if(tablero[i-2][j]==' ')
                    {
                        tablero_pertenencia[i-2][j]='m';
                        tablero[i-2][j]='-';
                        contador_llenos++;
                        salir=true;
                        gan = completo(i-2,j,fila, col,tablero,pos);
                        if(gan)
                        {
                            cuadrito_para( turno,  partida, i-2,j,  pos,  tablero,  puntos);
                            puntos[turno]+=1;  //suma de puntos
                            turno--; //para repetición de turno
                        }
                        break;
                    }
                }
                else if(i%2!=0&&j%2==0)
                {
                    if(tablero[i-1][j+1]==' ')
                    {
                        tablero_pertenencia[i-1][j+1]='m';
                        tablero[i-1][j+1]='-';
                        contador_llenos++;
                        salir=true;
                        gan = completo(i-1,j+1,fila, col,tablero,pos);
                        if(gan)
                        {
                            cuadrito_para( turno,  partida,i-1,j+1,  pos,  tablero,  puntos);
                            puntos[turno]+=1;  //suma de puntos
                            turno--; //para repetición de turno
                        }
                        break;
                    }
                    else if(tablero[i][j+2]==' ')
                    {
                        tablero_pertenencia[i][j+2]='m';
                        tablero[i][j+2]='|';
                        contador_llenos++;
                        salir=true;
                        gan = completo(i,j+2,fila, col,tablero,pos);
                        if(gan)
                        {
                            cuadrito_para( turno,  partida,  i,j+2,  pos,  tablero,  puntos);
                            puntos[turno]+=1;  //suma de puntos
                            turno--; //para repetición de turno
                        }
                        break;
                    }
                    else if(tablero[i+1][j+1]==' ')
                    {
                        tablero_pertenencia[i+1][j+1]='m';
                        tablero[i+1][j+1]='-';
                        contador_llenos++;
                        salir=true;
                        gan = completo(i+1,j+1,fila, col,tablero,pos);
                        if(gan)
                        {
                            cuadrito_para( turno,  partida,  i+1,j+1,  pos,  tablero,  puntos);
                            puntos[turno]+=1;  //suma de puntos
                            turno--; //para repetición de turno
                        }
                        break;
                    }
                    else if(tablero[i-1][j-1]==' ')
                    {
                        tablero_pertenencia[i-1][j-1]='m';
                        tablero[i-1][j-1]='-';
                        contador_llenos++;
                        salir=true;
                        gan = completo(i-1,j-1,fila, col,tablero,pos);
                        if(gan)
                        {
                            cuadrito_para( turno,  partida,  i-1,j-1,  pos,  tablero,  puntos);
                            puntos[turno]+=1;  //suma de puntos
                            turno--; //para repetición de turno
                        }
                        break;
                    }
                    else if(tablero[i][j-2]==' ')
                    {
                        tablero_pertenencia[i][j-2]='m';
                        tablero[i][j-2]='|';
                        contador_llenos++;
                        salir=true;
                        gan = completo(i,j-2,fila, col,tablero,pos);
                        if(gan)
                        {
                            cuadrito_para( turno,  partida,  i,j-2,  pos,  tablero,  puntos);
                            puntos[turno]+=1;  //suma de puntos
                            turno--; //para repetición de turno
                        }
                        break;
                    }
                    else if(tablero[i+1][j-1]==' ')
                    {
                        tablero_pertenencia[i+1][j-1]='m';
                        tablero[i+1][j-1]='-';
                        contador_llenos++;
                        salir=true;
                        gan = completo(i+1,j-1,fila, col,tablero,pos);
                        if(gan)
                        {
                            cuadrito_para( turno,  partida,  i+1,j-1,  pos,  tablero,  puntos);
                            puntos[turno]+=1;  //suma de puntos
                            turno--; //para repetición de turno
                        }
                        break;

                    }
                }
            }
            if(salir)
            {
                break;
            }
        }
    }
    if(contador_llenos==0 && faltan(tablero,fila,col))
    {
        jugada_aleatoria(fila,col,tablero,tablero_pertenencia);
    }
    return;
}
void borrar()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
//_______________________________________EXPORTACIÓN Y ARCHIVOS__________________________________________
void creacion_usuario(jugador gamer)
{
    jugador aux;
    string nom;
    int contador=0;
    int cod;
    cout<<"Digite el nombre del jugador: ";
    getline(cin>>ws,nom);
    strcpy(aux.nom_jugador,nom.c_str());
    cout<<"Digite el apellido del jugador: ";
    getline(cin>>ws,nom);
    strcpy(aux.ape_jugador,nom.c_str());
    cout<<"Digite el gamertag: ";
    getline(cin>>ws,nom);
    strcpy(aux.gamertag,nom.c_str());
    archivoj = fopen("lista_jugadores.txt","r+");
    archivou = fopen("ultimo_cod.txt","r+");
    if(archivoj == NULL)
    {
        archivoj = fopen("lista_jugadores.txt","w");
        fclose(archivoj);
        archivoj = fopen("lista_jugadores.txt","r+");
    }
    if(archivou == NULL)
    {
        archivou = fopen("ultimo_cod.txt","w");
        fclose(archivou);
        archivou = fopen("ultimo_cod.txt","r+");
    }

    fread(&gamer, sizeof(gamer),1,archivoj);
    fread(&cod, sizeof(cod),1,archivou);

    while(!feof(archivoj))
    {
        contador++;
        int j=0;
        for(int i=0;i<ML;i++){
                if(aux.gamertag[i]==gamer.gamertag[i]){
                    j++;
                }
        }
        if(j==ML)
        {
        cout<<"El jugador existe, puede continuar"<<endl;
        fclose(archivoj);
        return;
        }
        fread(&gamer, sizeof(gamer),1,archivoj);

    }
    if(contador <= 20)
    {
           cout<<"Jugador no existente, se procederá a la creación del nuevo jugador:"<<endl;
            aux.codigo = cod;
            cod++;
            inicial(aux.gamertag,aux.inicial);
            fwrite(&aux,sizeof(aux),1,archivoj);
            fseek(archivou,0,SEEK_SET);
            fwrite(&cod,sizeof(cod),1,archivou);
            cout<<"Jugador creado correctamente..."<<endl;
            cout<<"Codigo del jugador:"<< aux.codigo<<endl;

    }
    else
    {
        cout<<"Memoria llena, borre jugadores para crear uno nuevo, o acceda con uno ya creado"<<endl;
    }
    _fcloseall();
    return;
}
void borrado_usuario(jugador gamer, string gamertag)
{
    char comparar[ML]={' '};
    bool comprobar = false;
    int j=0;
    strcpy(comparar,gamertag.c_str());
    archivoj = fopen("lista_jugadores.txt","r+");
    if(archivoj == NULL)
    {
        fclose(archivoj);
        cout<<"Archivo inexistente, no hay jugadores creados"<<endl;
    }
    else
    {
        reserva = fopen("reserva.txt","w");
        fclose(reserva);
        reserva = fopen("reserva.txt","r+");
        fread(&gamer, sizeof(gamer),1,archivoj);
        while(!feof(archivoj))
        {
            if(!(strcmp(gamer.gamertag,comparar)==0))
            {
                fwrite(&gamer, sizeof(gamer),1,reserva);
            }
            else
            {
                comprobar = true;
            }
            fread(&gamer, sizeof(gamer),1,archivoj);
        }
        _fcloseall();
        remove("lista_jugadores.txt");
        rename("reserva.txt","lista_jugadores.txt");
        if(comprobar)
        {
            cout<<"Eliminación correctamente realizada"<<endl;
        }
        else
        {
            cout<<"Archivo reescrito pero jugador a borrar no hallado"<<endl;
        }
    }
    return;
}
/*void ver_record(jugador jugadores[], int num_jugadores, int opt)
{
    char nombre[]= "MejoresPuntajes_";
    char fin[] =".txt";
    char doc[50]="";
    int aux;
    jugador comparacion [MJ];
    jugador auxiliar;
    int pos=5;
    int con = 0;
    char date[30]; //arreglo char para la fecha
    time_t actual; //variable requerida para manejo de tiempo
    struct tm * timeinfo; //estructura requerida para el manejo de tiempo
    for (int a=0; a<num_jugadores; a++)
    {
        comparacion[a]=jugadores[a];
    }

    for (int i=0; i<num_jugadores-1; i++)
    {
        for(int j=0; j<num_jugadores-i-1; j++)
        {
            if(comparacion[j].mejor_puntaje<comparacion[j+1].mejor_puntaje)
            {
                auxiliar=comparacion[j];
                comparacion[j]=comparacion[j+1];
                comparacion [j+1]=auxiliar;
            }
        }
    }

    if (opt==1)
    {
        if(num_jugadores<5)
        {
            pos=num_jugadores;
        }
        for (int k=0; k<pos; k++)
        {
            cout<<"Mejores puntajes: "<< k+1 << ") "<<comparacion[k].nom_jugador<< ": "<<comparacion[k].puntos;
            cout<<"Con un mejor puntaje de partida de : "<<comparacion [k].mejor_puntaje;
        }
    }
    else
    {
        time(&actual); //lectura de tiempo
        timeinfo = localtime( &actual); //cambio de formato de tiempo
        strcpy(date,ctime(&actual)); //cambio a char para ser copiado en date
        strcat(doc,nombre);
        strcat(doc,date);
        strcat(doc,fin);
        for(int i=40; i<44; i++)
        {
            doc[i]= fin[con];
            con++;
        }
        //doc[19]=doc[23]=doc[26]=doc[35]='_';
        doc[29]=doc[32]=',';
        //cout<<doc;
        records = fopen(doc, "w"); //creo el archivo desde ceros
        fclose(records);
        records = fopen(doc, "r+");
        for (int b=0;b<pos;b++)
        {
            auxiliar = comparacion [b];
            fwrite(&auxiliar, sizeof(auxiliar),1,records);
        }
        fclose(records);
    }
    return;
}*/
/*void mostrar_exportar( int num_jugadores, jugador jugadores [], int opt)
{
    char nombre[]= "InformaJugador_";
    char fin[] =".txt";
    char cod [50]="";
    char date[30]; //arreglo char para la fecha
    time_t actual; //variable requerida para manejo de tiempo
    struct tm * timeinfo; //estructura requerida para el manejo de tiempo
    int pos;
    char alias [ML];
    string gamertag;
    bool perdido=true;
    int aux;
    int con = 0;
    jugador asistente;

    while (perdido)
    {
        cout << "Digite el gamertag del jugador que quiere buscar"<<endl;
        cin >> gamertag;
        strcpy(alias,gamertag.c_str());
        for (int j=0;j<num_jugadores;j++)
        {
            if(alias==jugadores[j].gamertag)
            {
                aux=j;
                perdido=false;
                break;
            }
        }
    }

    if(opt==4)
    {
        time(&actual); //lectura de tiempo
        timeinfo = localtime( &actual); //cambio de formato de tiempo
        strcpy(date,ctime(&actual)); //cambio a char para ser copiado en date
        strcat(cod,nombre);
        strcat(cod,date);
        strcat(cod,fin);
        for(int i=40; i<44; i++)
        {
            cod[i]= fin[con];
            con++;
        }
        cod[29]=cod[32]=',';
        informacion = fopen(cod, "w"); //creo el archivo desde ceros
        fclose(informacion);
        informacion = fopen(cod, "r+");
        asistente=jugadores[aux];
        fwrite(&asistente, sizeof(asistente),1,informacion);
        fclose(informacion);
    }
    else
    {
        cout<<"El jugador se llama "<<jugadores[aux].nom_jugador<<jugadores[aux].ape_jugador;
        cout<<"con el gamertag"<<jugadores[aux].gamertag<<"y tiene un puntaje maximo en el juego de: "<<jugadores[aux].mejor_puntaje<<endl;
    }

    return;
}*/
int vectorizar(jugador jugadores[]){
    jugador gamer;
    int liar=0;
    archivoj = fopen("lista_jugadores.txt","r+");
    if(archivoj == NULL)
    {
        archivoj = fopen("lista_jugadores.txt","w");
        fclose(archivoj);
        archivoj = fopen("lista_jugadores.txt","r+");
    }
    /*for(int i=0; !feof(archivoj);i++)
    {
        fread(&jugadores[i], sizeof(jugadores[i]),1,archivoj);
        liar = i;
    }*/
    while(!feof(archivoj)){
        fread(&jugadores[liar], sizeof(jugadores[liar]),1,archivoj);
        liar++;
    }
    fclose(archivoj);
    return liar+1;
}
void desv(jugador jugadores[], int num_jugadores)
{
    jugador gamer;
    archivoj = fopen("lista_jugadores.txt","r+");
    for(int i=0;i<num_jugadores;i++)
    {
        fwrite(&jugadores[i], sizeof(jugadores[i]),1,archivoj);
    }
    fclose(archivoj);
    return ;
}
void inicial(string nombres,char &inicial)
{
        inicial= nombres[0];  //uso de la inicial de la cadena para llenado
        cout<<inicial;
    return;
}
