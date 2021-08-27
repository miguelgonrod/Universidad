#include <iostream>

using namespace std;

void menu1()
{
    cout<<"\n\t\tMENU DE EJEMPLO\n\n";
    cout<<" 1. Opcion 1              "<<endl;
    cout<<" 2. Opcion 2              "<<endl;
	cout<<" 3. Opcion 3              "<<endl;
	cout<<" 4. Opcion 4              "<<endl;
	cout<<" 5. Opcion 5              "<<endl;
	cout<<" 6. Opcion 6              "<<endl;
	cout<<" 7. Salir                 "<<endl;


    cout<<"\n Ingrese opcion : ";
}

/*                      funcion principal
------------------------------------------------------------------------------*/

int main()
{
    int op;   // opcion del menu
    int *apuntador = &op;

    system("color 0b");

    do
    {
        menu1();
        cin>> *apuntador;

        switch(*apuntador)
        {
            case 1:
                cout<<"\n Selecciono primera opcion ";
				cout<<endl;
                break;

            case 2:
                cout<<"\n Selecciono segunda opcion ";
				cout<<endl;
                break;

            case 3:
                cout<<"\n Selecciono tercer opcion ";
				cout<<endl;
                break;

            case 4:
                cout<<"\n Selecciono cuarta opcion ";
				cout<<endl;
                break;

            case 5:
                cout<<"\n Selecciono quinta opcion ";
				cout<<endl;
                break;

            case 6:
                cout<<"\n Selecciono sexta opcion ";
				cout<<endl;
                break;
        }

        cout<<endl<<endl;
        system("pause");  system("cls");

    } while(op != 7);


    return 0;
}
