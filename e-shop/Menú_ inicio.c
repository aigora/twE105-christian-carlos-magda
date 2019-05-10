//MENÃš DE INICIO de e-shop

#include <stdio.h>
#include <stdlib.h> /* system */
#include <string.h> /*strcmp*/

//Estructura de fechas (para fechas de nacimiento de los usuarios).
typedef struct{
	int day,month,year;
}fecha;

//Estructura de usuario.
typedef struct{
	char nombre[60];
	char apellidos[60];
    char nickname[16];
    char password[16];
}usuario; 

//Función de registro.
void registro();

//Función del login.
void login(char *p);

void main()
{
	char nick_usuario[16];//Cadena que almacena el nombre del usuario con sesión iniciada
	//Definimos un puntero que apunta a nick_usuario, lo usaremos para almacenar en este la cadena nick de la función login
	char *p;
	p=nick_usuario;
	
	
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
	
	//MenÃº principal
	system ("color F0");//cambia el color del fondo(F) y del texto(0).
	//Caracter de opciones del menÃº 
	char option_menu;
	//Caracter de opciones del catÃ¡logo
	char option_cat;
	do
	{
		system("cls");//limpia la pantalla
		//Pantalla de inicio
		printf("\n\te-shop\n");
    		printf("----------------------------------------------------------\n");
    		printf("\n BIENVENIDO\n\n");
 		printf("Seleccione una opci%cn para comenzar: \n\n \tAcceder al cat%clogo de productos (c)\n \tInicio de sesi%cn (i)\n \tRegistrarse (r)\n \tSalir (s)\n",162,160,162);
    
		//Recoge la opciÃ³n del usuario introducida por teclado
    		scanf(" %c",&option_menu);
    
    		//Opciones elegibles por el usuario
    		switch(option_menu)
    		{
    			case 'c':
    				{
    					system("cls");
    					printf("\n\tCAT%cLOGO\n\n",181);
    					
    					//OPCIONES DEL CATÃLOGO
    					
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
								printf("Caracter introducido no v%clido.",160);
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
					
					//Función para el registro de nuevos usuarios
					registro();
					printf("\n");
					system("pause");
				}	
    			case 'i':
    				{
    					//INICIO DE SESIÓN
    					system("cls");
    					printf("\n\tINICIO DE SESI%cN\n",224);
    					//Función para el inicio de sesión
    					//Devuelve el nick del usuario iniciado una vez la sesión se inicia correctamente
    					login(p);
    					printf("\n");
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

//Función de registro
 
void registro(){
	//indice de iteración.
	int i;
	
	//Auxiliar para comprobar si los datos son correctos.
	int flag;
	//Iteracion 
	int n;
	//Vector que almacena las estructuras de los usuarios registrados
	usuario registrados[100];
	
	//variable persona(estructura usuario) que se registra
	usuario persona1;
	//fecha de nacimiento del usuario.
	fecha nacimiento;	
	
	FILE *pf;
	//Abrimos un fichero, en modo lectura en el que se almacenaran los datos de los usuarios
	pf=fopen("registro_usuarios.txt","r");
	//Comprobamos si hay error al abrir el fichero
	if(pf==NULL) printf("Error al abrir el fichero.");

	//Usuario introduce sus datos
	//Bucle que se repite hasta que el usuario introduzca datos válidos.
	do
	{
	//Inicializamos n en 0 y flag en 1	
	n=0;
	flag=1;
	//Nombre
	printf("\n\tNombre: ");
	scanf(" %[^\n][60]",persona1.nombre);
	
	//Apellidos
	printf("\n\tApellidos: ");
	scanf(" %[^\n][60]",persona1.apellidos);
	
	//Nickname
	printf("\n\tNickname: ");
	scanf(" %s[16]",persona1.nickname);
	
	//comprueba si hay coincidencias en el nickname.
	
	while(fscanf(pf,"%[^;];%[^;];%[^;];%[^\n]\n",registrados[n].nombre,registrados[n].apellidos,registrados[n].nickname,registrados[n].password)!=EOF&&flag!=0)
	{
		//printf("%s\n", registrados[n].nickname);
		flag=strcmp(registrados[n].nickname,persona1.nickname);
		n++;
	}
	if (flag==0) 
	{
		printf("\n\tUsuario ya registrado\n");
		system ("pause");
		system ("cls");
	}
	else
	{
	//Password
	printf("\n\tPassword: ");
	scanf(" %s[16]",persona1.password);
//ERROR, LA CONTRASEÑA NO PUEDE ESCRIBIRSE, NO SALTA DE LÍNEA AL PULSAR ENTER.
/* while(persona1.password[i]!=16){
        //Capturamos carácter 
        persona1.password[i]=getch();   
        //Si es un carácter válido y no se ha sobrepasado el límite de 20 caracteres se imprime un asterisco 
        if(persona1.password[i]>32 && i<20) { 
             putchar('*'); 
             i++; 
        } 
        //Si se pulsa la tecla RETROCESO, se retrocede un carácter, se imprime un espacio para eliminar el asterisco y se vuelve a retroceder para que el siguiente asterisco se coloque a continuación del anterior. 
        else
      if(persona1.password[i]==8 && i>0){ 
               putchar(8); 
               putchar(' '); 
               putchar(8); 
               i--;  
            }
		}*/
		
	//Fecha de cumpleaños
	printf("\n\tEscriba la fecha con el formato: (2/3/1987) separando los n%cmeros con espacios\n",163);
	printf("\n\tFecha de nacimiento : ");
	scanf(" %i %i %i",
			&nacimiento.day,&nacimiento.month,&nacimiento.year);
	
	//Comprobación de mayoría de edad
	if (nacimiento.year>2000) {	
	printf("\n\nLo sentimos, los menores de 18 a%cos no pueden poseer una cuenta.\n",164);
	
	fclose (pf);
	}
    }
    }while(flag==0);
    
	if(flag !=0)
	{
	//Abrimos un fichero en modo escritura en el que se almacenaran los datos de los usuarios
	pf=fopen("registro_usuarios.txt","a");
	//Comprobamos si hay error al abrir el fichero
	if(pf==NULL) printf("Error al abrir el fichero.");
    
	fprintf(pf,"%s;%s;%s;%s\n"
			,persona1.nombre,persona1.apellidos,persona1.nickname,persona1.password);
			
	printf("\n\nRegistro completado satisfactoriamente!\n");
	
	fclose (pf);
	}
}

//función login

void login (char *p)
{
	//Indice de iteración
	int i;
	//auxiliar para comprobar si los datos son correctos.
	int flag;
	//iteracion 
	int n;
	//Vector que almacena las estructuras de los usuarios registrados
	usuario registrados[100];
	
	//Cadenas de caracteres para el nick y la contraseña del usuario logueandose
	char nick[16];
	char pass[16];
	
	
	FILE *pf;
	//Abrimos un fichero, en modo lectura en el que se almacenaran los datos de los usuarios
	pf=fopen("registro_usuarios.txt","r");
	//Comprobamos si hay error al abrir el fichero
	if(pf==NULL) printf("Error al abrir el fichero.");

	//Usuario introduce sus datos
	//Bucle que se repite hasta que el usuario introduzca datos válidos.
	do
	{
		//Inicializamos n en 0 y flag en 1	
		n=0;
		flag=1;
	
	
		//Nickname
		printf("\n\tNickname: ");
		scanf(" %s[16]",nick);
	
		//Password
		printf("\n\tPassword: ");
		scanf(" %s[16]",pass);
	
		//comprueba si el inicio de sesión es correcto.
	
		while(fscanf(pf,"%[^;];%[^;];%[^;];%[^\n]\n",registrados[n].nombre,registrados[n].apellidos,registrados[n].nickname,registrados[n].password)!=EOF&&flag!=0)
		{
			//Comprobamos usuario y contraseña
			if(strcmp(registrados[n].nickname,nick)==0&&strcmp(registrados[n].password,pass)==0)
			{
				flag=0;
			}
			n++;
		}
		if (flag==0){
			fclose (pf);
			printf("\n\tLa sesi%cn ha sido iniciada satisfactoriamente.\n",162);
			system("pause");
			system("cls");
			printf("\n\tBienvenido de nuevo, %s.\n",nick);
		}
		else
		{
		  printf("\n\t Nickname o contrase%ca incorrectos.\n",164);
		  system("pause");
		  system("cls");
		}
    }while(flag==1);
    
    
    //Asignación de la cadena almacenada en nick a la que guarda el nombre del usuario cuya sesión está iniciada.
    
  	for (i=0;i<16;i++)
  	{
  		*(p+i)=nick[i];
	}
} 













