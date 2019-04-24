//MENÚ DE INICIO de e-shop

#include <stdio.h>
#include <stdlib.h> /* system */

//Estructura de fechas (para fechas de nacimiento de los usuarios).
typedef struct{
	int day,month,year;
}fecha;

//Estructura de usuario.
typedef struct{
	char nombre[60];
	char apellidos[60];
    fecha nacimiento;
    char nickname[16];
    char password[16];
}usuario; 

//funci�n de registro.
void registro();

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
    		scanf(" %c",&option_menu);
    
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
			case 'r':
				{
					//REGISTRO DE NUEVO USUARIO
					system("cls");
					printf("\n\tCREA UNA CUENTA\n");
					
					//Funci�n para el registro de nuevos usuarios
					registro();
					printf("\n");
					system("pause");
				}	
    			case 'i':
    				{
    					//INICIO DE SESIÓN
    					system("cls");
    					printf("\n\tINICIO DE SESI%cN\n",224);
    					system("pause");//El programa hace una pausa, espera a que el usuario pulse una tecla para continuar.
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

//funci�n de registro (PRUEBA)
void registro(){
	
	//Ejemplo de variable persona(estructura usuario) que se registra
	usuario persona1;	
	
	FILE *pf;
	//Abrimos un fichero en el que se almacenaran los datos de los usuarios
	pf=fopen("registro_usuarios.txt","a");
	//Comprobamos si hay error al abrir el fichero
	if(pf==NULL) printf("Error al abrir el fichero.");

	//Usuario introduce sus datos
	
	//Nombre
	printf("\n\tNombre: ");
	scanf(" %[^\n][60]",persona1.nombre);
	
	//Apellidos
	printf("\n\tApellidos: ");
	scanf(" %[^\n][60]",persona1.apellidos);
	
	//Nickname
	printf("\n\tNickname: ");
	scanf(" %[^\n][16]",persona1.nickname);
	
	//Password
	printf("\n\tPassword: ");
	scanf(" %[^\n][16]",persona1.password);
	
	//Fecha de cumplea�os
	printf("\n\tEscriba la su fecha con el formato: (2/3/1987) separando los n%cmeros con espacios\n",163);
	printf("\n\tFecha de nacimiento : ");
	scanf(" %i %i %i",
			&persona1.nacimiento.day,&persona1.nacimiento.month,&persona1.nacimiento.year);
	
	//Comprobaci�n de mayor�a de edad
	if (persona1.nacimiento.year>2000) {	
	printf("\n\nLo sentimos, los menores de 18 a%cos no pueden poseer una cuenta.\n",164);
	}
	
	fprintf(pf,"USER:%s %s\t NICK:%s\t PASSWORD:%s\n"
			,persona1.nombre,persona1.apellidos,persona1.nickname,persona1.password);
			
	printf("\n\nRegistro completado satisfactoriamente!\n");		
}















