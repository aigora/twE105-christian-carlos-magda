//MENÚ DE INICIO de e-shop

#include <stdio.h>
#include <stdlib.h> /* system */

void main()
{
	//Pantalla de inicio
	system("color E0");//cambia el color del fondo(E) y del texto(0).
	//LOGO
	printf("\n\t         ______                 _______    __    __    _______    _____");
	printf("\n\t       (  __   )               (  _____)  (  )  (  )  (  ___  )  (  __ )");
	printf("\n\t      (  (__)   )    _____     (  )____   (  )__(  )  ( (   ) )  ( (__) )");
	printf("\n\t     (   ______)    (_____)    (_____  )  (   __   )  ( (   ) )  (  ___) ");
	printf("\n\t      ( (______                 ____(  )  (  )  (  )  ( (___) )  ( )");
	printf("\n\t       (_______)               (_______)  (__)  (__)  (_______)  (_)");
	printf("\n\n\n\n\t\t");
	system ("pause");//El programa hace una pausa, espera a que el usuario pulse una tecla para continuar.
	system("cls");//Limpia la pantalla.
	
	//Menú principal
	system ("color F0");//cambia el color del fondo(F) y del texto(0).
	//Caracter de opciones del menú 
	char option_menu;
	//Caracter de opciones del catálogo
	char option_cat;
	do
	{
		system("cls");//limpia la pantalla
		//Pantalla de inicio
		printf("\n\te-shop\n");
    		printf("----------------------------------------------------------\n");
    		printf("\n BIENVENIDO\n\n");
 		printf("Seleccione una opci%cn para comenzar: \n\n \tAcceder al cat%clogo de productos (c)\n \tInicio de sesi%cn (i)\n \tRegistrarse (r)\n \tSalir (s)\n",162,160,162);
    
		//Recoge la opción del usuario introducida por teclado
    		scanf("%c",&option_menu);
    
    		//Opciones elegibles por el usuario
    		switch(option_menu)
    		{
    			case 'c':
    				{
    					system("cls");
    					printf("\n\tCAT%cLOGO\n\n",181);
    					
    					//OPCIONES DEL CATÁLOGO
    					
    					printf("Opciones del cat%clogo:\n -Mostrar cat%clogo completo(c)\n -Filtrar por precio(p)\n -Solo ofertas(o)\n -Mostrar categor%cas(k)\n", 160,160,161);
    			       
						scanf(" %c",&option_cat);
						switch(option_cat)
						{
							case 'c':
							{
								//CATÁLOGO COMPLETO
								system("cls");
								printf("\n\tCAT%cLOGO\n",181);
								system("pause");
								break;	
							}
							case 'p':
							{
								//FILTRADO DE PRODUCTOS POR PRECIO (MAYOR-MENOR/MENOR-MAYOR)
								system("cls");
								printf("\n\tPRODUCTOS ORDENADOS POR PRECIO\n");
								printf("\n%cDesea que los productos se ordenen de mayor a menor precio (M) o de menor a mayor precio (m)?\n",168);
								
								system("pause");
								break;
							}
							case 'o':
							{
								//OFERTAS
								system("cls");
								printf("\n\tOFERTAS\n");
								system("pause");
								break;
							}
							case 'k':
							{
								//CATEGORÍAS
								system("cls");
								printf("\n\tCATEGOR%cAS\n",214);
								printf("\n Elige la categor%ca\n: ",161);
								system("pause");
								break;
							}
							default:
							{
								//CARACTER NO VÁLIDO
								system("cls");
								printf("Caracter introducido no válido.");
								system("pause");
								break;
									
							} 	
						}
						 				
      					break;
				}
    			case 'i':
    				{
    					//INICIO DE SESIÓN
    					system("cls");
    					printf("\n\tINICIO DE SESI%cN\n",224);
    					system("pause");//El programa hace una pausa, espera a que el usuario pulse una tecla para continuar.
    					break;
	        		}
			case 'r':
				{
					//REGISTRO DE NUEVO USUARIO
					system("cls");
					printf("\n\tCREA UNA CUENTA\n");
					system("pause");
					break;
				}
			case 's':
				{
					//SALIR
					system("cls");
					break;
				}
			default:
				{
					//CARACTER NO VÁLIDO
					printf("\n\tEl caracter introducido no es v%clido\n",160);
					system("pause");
					break;
				} 	
    		}
	}	
	while(option_menu!='s');
	system ("color E0");//cambia el color del fondo(F) y del texto(0).
	printf("\n\t%cHASTA LA PR%cXIMA!",173,224);
}
