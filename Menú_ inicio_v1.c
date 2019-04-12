//MENÚ DE INICIO de e-shop

#include <stdio.h>
#include <stdlib.h> /* system */

void main()
{
	system ("color F0");//cambia el color del fondo(F) y del texto(0).
	//option1 es el caracter para seleccionar las opciones del menú de inicio y option2 es el caracter para seleccionar las opciones del catálogo
	char option1, option2;
	do
	{
		system("cls");//limpia la pantalla
		//Pantalla de inicio
		printf("\n\te-shop\n");
    		printf("----------------------------------------------------------\n");
    		printf("\n BIENVENIDO\n\n");
 		printf("Seleccione una opci%cn para comenzar: \n\n \tAcceder al cat%clogo de productos (c)\n \tInicio de sesi%cn (i)\n \tRegistrarse (r)\n \tSalir (s)\n",162,160,162);
    
		//Recoge la opción del usuario introducida por teclado
    		scanf("%c",&option1);
    
    		//Opciones elegibles por el usuario
    		switch(option1)
    		{
    			case 'c':
    				{
    					system("cls");
    					printf("\n\tCAT%cLOGO\n",181);
    					printf("Opciones del cat%clogo:\n -Mostrar cat%clogo completo(c)\n -Filtrar por precio(p)\n -Solo ofertas(o)\n -Mostrar categor%cas(k)\n", 160,160,161);
    			       
						scanf(" %c",&option2);
						switch(option2)
						{
							case 'c':
							{
								system("cls");
								printf("\n\tCAT%cLOGO\n",181);
								system("pause");
								break;	
							}	
						}
						 				
      					break;
				}
    			case 'i':
    				{
    					system("cls");
    					printf("\n\tINICIO DE SESI%cN\n",224);
    					system("pause");//El programa hace una pausa, espera a que el usuario pulse una tecla para continuar.
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
	while(option1!='s');
}
