//MENÚ DE INICIO de e-shop

#include <stdio.h>
#include <stdlib.h> /* system */

void main()
{
	system ("color F0");//cambia el color del fondo(F) y del texto(0).
	char option;
	do
	{
	system("cls");//limpia la pantalla
	//Pantalla de inicio
    printf("\n\te-shop\n");
    printf("----------------------------------------------------------\n");
    printf("\n BIENVENIDO\n\n");
    printf("Seleccione una opci%cn para comenzar: \n\n \tAcceder al cat%clogo de productos (c)\n \tInicio de sesi%cn (i)\n \tRegistrarse (r)\n \tSalir (s)\n",162,160,162);
    
	//Recoge la opción del usuario introducida por teclado
    scanf("%c",&option);
    
    //Opciones elegibles por el usuario
    switch(option)
    {
    	case 'c':
    		{
    			system("cls");
    			printf("\n\tCAT%cLOGO\n",181);
    			system("pause");
    			break;
			}
    	case 'i':
    		{
    			system("cls");
    			printf("\n\tINICIO DE SESI%cN\n",224);
    			system("pause");
    			break;
			}
		case 'r':
			{
				system("cls");
				printf("\n\tCREA UNA CUENTA\n");
				system("pause");
				break;
			}
		case 's':
			{
				system("cls");
				break;
			}
		default:
			{
				printf("\n\tEl caracter introducido no es v%clido\n",160);
				system("pause");
				break;
			} 	
    }
	}
	while(option!='s');
}
