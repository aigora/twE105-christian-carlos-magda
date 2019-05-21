//MENÚ DE INICIO de e-shop

#include <stdio.h>
#include <stdlib.h> /* system */
#include <string.h> /*strcmp*/
#include <time.h>
#define N 4 //N n�mero de productos en venta
#define M 2 //M n�mero de tipo de productos

//Estructura de fechas (para fechas de nacimiento de los usuarios).
typedef struct
    {
	    char Descripcion[30];
    }descripcion;

	typedef struct
	{
		char tipo[20];//tipo de producto letra ejemplo C de Condensador
		char nombre[50];//nombre exacto del producto. el que se mostrar� en el carrito.
		descripcion Especificaciones[4];//cadena de caracteres que guardara la descripcion de los productos
		float precio;//resuelve el problema de filtrar producto por precios
		int unidades;//unidades disponibles
		char estado[10];//si est� en oferta (1) o no(0), es una bandera para saber si el producto esta en oferta o no. 
	    char codigo[10];//esta componente sirve para diferencia varios productos del mismo tipo y que de esta forma podamos acceder a sus nombres
	}producto;//estructura de toda la informacion que contiene cada producto. podemos poner como codigos numero letras, letras y n�meros.
	
	typedef struct
    {
        char letra[5];
        char TIPO[20];
        int NTIPO;//n�mero de productos del mismo tipo Ejemplo 5 tipo distintos de Condensador
    }clasificacion;

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

typedef struct
{
	char CODIGOCOMPRA[5];
}CODE;

typedef struct 
{
	char usuario[16];
    char n_compra[4];
    char n_prod[4];
    char fecha[15];
}historial;

typedef struct 
{
	char usuario[16];
    char n_prod[4];
    char fecha[15];
}lista_prov;

//Funci�n de registro.
void registro();

//Funci�n del login.
void login(char *p, int *q);

void catalogo_completo(int flag);//prototipo de la funci�n
void categorias(int flag);
void evalua(int flag,int j);//funci�n que compara si la elecci�n concide con el tipo y manda imprimir productos del mismo tipo
void ofertas(int flag);/*producto productos[],int dimension*/
void comprando();
void filtro_precio(int flag);//funci�n que filtra en base a un intervalo de precio dado por el usuario
void leer_catalogo(producto productos[],int dimension);//funcion que lee los ficheros y guarda los datos en un vector de estructuras
void leer_clase(clasificacion clasificaciones[],int dimension1);//funcion que lee los ficheros y guarda los datos en un vector de estructuras
void mostrar_carrito(CODE CODIGOS[],int dimension1,int unidades[],int dimension2,int i);
void opciones_carrito(CODE CODIGOS[],int dimension1,int unidades[],int dimension2,int i,char nick_usuario[],int dimension3);
void leer_historial(historial compras[],int d1,CODE CODIGOS[],int d2,int unidades[],int d3,int *p);
void historial_completo(char nick_usuario[],int dim);
void historial_fechas(char nick_usuario[],int dim);
void ver_lista_provisional(char nick_usuario[],int dim);

void main()
{
	char election;
	char nick_usuario[16];//Cadena que almacena el nombre del usuario con sesi�n iniciada
	//Definimos un puntero que apunta a nick_usuario, lo usaremos para almacenar en este la cadena nick de la funci�n login
	char *p;
	p=nick_usuario;
	int flag=0;
	//Caracter de opciones del menú 
	char option_menu;
	//Caracter de opciones del catálogo
	char option_cat;
    int m0=0,m=0,m1=0,i;
    int n=0,j;//variables locales. n1 n�mero de tipos
    
    producto productos[N];//vector de estructuras//Perpi�an:la dimension del vector tiene que coincidir con el n�mero de productos en tu lista
    clasificacion clasificaciones[M];//vector de estructuras
    
    FILE *pf,*pf1,*pf2/*,*pf3*/;//puntero que se�ala a fichero 
    
    pf = fopen("lista_de_productos.txt", "r");//Abrimos el fichero
    pf1 =fopen("lista_de_productos_1.txt","r");
    pf2 = fopen("lista_de_tipos.txt", "r");//Abrimos el fichero que contiene letras que se corresponden al tipo de producto, los nombres de los tipos de producto 
	//y eln�mero de productos del mismo tipo//ojo a-->r
    //pf3 = fopen("lista_de_tipos_1.txt", "r");

	leer_catalogo(productos,N);
	leer_clase(clasificaciones,M);
	
	
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

	do
	{
		system("cls");//limpia la pantalla
		//Pantalla de inicio
		printf("\n\te-shop\n");
    		printf("----------------------------------------------------------\n");
    		printf("\n BIENVENIDO\n\n");
 		printf("Seleccione una opci%cn para comenzar: \n\n \tAcceder al cat%clogo de productos (c)\n \tInicio de sesi%cn (i)\n \tRegistrarse (r)\n \tHistorial (h)\n \tSalir (s)\n",162,160,162);
    
		//Recoge la opción del usuario introducida por teclado
    		scanf(" %c",&option_menu);
    
    		//Opciones elegibles por el usuario
    		switch(option_menu)
    		{
    			case 'c':
    			case 'C':
    				{
    					system("cls");
    					printf("\n\tCAT%cLOGO\n\n",181);
    					
    					//OPCIONES DEL CATÁLOGO
    					
    					printf("Opciones del cat%clogo:\n -Mostrar cat%clogo completo(c)\n -Filtrar por precio(p)\n -Solo ofertas(o)\n -Mostrar categor%cas(k)\n", 160,160,161);
    			       
						scanf(" %c",&option_cat);
						switch(option_cat)
						{
							case 'c':
							case 'C':
							{
								//CAT�LOGO COMPLETO
								system("cls");
								catalogo_completo(flag);
								system("pause");
								break;	
							}
							case 'p':
							case 'P':
							{
								//FILTRADO POR PRECIOS A ELEGIR
								system("cls");
								filtro_precio(flag);
								system("pause");
								break;
							}
							case 'o':
							case 'O':
							{
								//OFERTAS
								system("cls");
								printf("\n\tOFERTAS\n");
								ofertas(flag);
								system("pause");
								break;
							}
							case 'k':
							case 'K':
							{
								//CATEGOR�AS
								system("cls");
								categorias(flag);//funci�n que te muestra las categor�as
								system("pause");
								break;
							}
							default:
							{
								//CARACTER NO V�LIDO
								system("cls");
								printf("Caracter introducido no v%clido.",160);
								system("pause");
								break;
									
							} 	
						}
						 				
      					break;
					}
				case 'h':
				case 'H':
					{
						system("cls");
						//printf("HOLIIII\n");
						//system("pause");
						if(flag==1)
						{
						    printf("Opciones:\n \tVer historial completo (H)\n \tVer historial por fechas (F)\n \tVer lista porvisional de compras (P) Solo elegir esta opcion si ya habeis guardado anteriormente una lista\n");
						    scanf(" %c",&election);
						    switch (election)
					     	{
							case 'H':
							case 'h':
								system("cls");
								printf("HISTORIAL COMPLETO\n");
								historial_completo(nick_usuario,16);
								system("pause");
								break;
							case 'F':
							case 'f':
								system("cls");
								printf("Historial de compras\n");
								historial_fechas(nick_usuario,16);
								system("pause");
								break;
							case 'P':
							case 'p':
								system("cls");
								ver_lista_provisional(nick_usuario,16);
								system("pause");
								break;
							default://CARACTER NO VÁLIDO
							system("cls");
						    printf("\n\tEl caracter introducido no es v%clido\n",160);
					     	system("pause");
					     	break;
				            }
				        }
	                    else
						printf("Lo sentimos, para poder ver su historial tiene que iniciar sesion\n");
						system("pause");
						break;
	                }
				case 'r':
				case 'R':
					{
						//REGISTRO DE NUEVO USUARIO
						system("cls");
						printf("\n\tCREA UNA CUENTA\n");
						
						//Funci�n para el registro de nuevos usuarios
						registro();
						printf("\n");
						system("pause");
						break;
					}	
	    		case 'i':
	    		case 'I':
	    			{
	    				//INICIO DE SESI�N
	    				system("cls");
	    				printf("\n\tINICIO DE SESI%cN\n",224);
	    				//Funci�n para el inicio de sesi�n
	    				//Devuelve el nick del usuario iniciado una vez la sesi�n se inicia correctamente
	    				login(p,&flag);
	    				printf("\n");
	    				system("pause");
	    				break;
		        	}
				case 's':
				case 'S':
					{
						//SALIR
						system("cls");
						break;
					}
				default:
					{
						//CARACTER NO V�LIDO
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
//Funci�n de registro
void registro(){
	//Necesario para tomar la fecha actual (librer�a time.h).
	time_t t = time(NULL);
	//Estructura fecha/ hora actual.
	struct tm tm = *localtime(&t);
	
	//Variables que almacena el dia de hoy.
	int day=tm.tm_mday;
	int month=tm.tm_mon+1; //Enero es el mes 0, por lo que sumamos 1.
	int year=tm.tm_year+1900; //Hemos de sumar 1900 porque los a�os se cuentan desde 1900.
	
	//Variable que almacena la diferencia entre los datos de la fecha actual y la del nacimiento del usuario.
	int diff_year;
	int diff_month;
	int diff_day;
	
	//indice de iteraci�n.
	int i=0;
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
	//Bucle que se repite hasta que el usuario introduzca datos v�lidos.
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
		
	//Fecha de cumplea�os
	printf("\n\tEscriba la fecha con el formato: (dd/mm/yyyy).\n",163);
	printf("\n\tFecha de nacimiento : ");
	scanf(" %i/%i/%i",
			&nacimiento.day,&nacimiento.month,&nacimiento.year);
	
	//Utilizaremos i como flag para comprobar si el usuario es mayor de edad.
	i=0;
	
	diff_year = year - nacimiento.year;
	diff_month = month - nacimiento.month;
	diff_day = day - nacimiento.day;
	
	//Calcula si el usuario es mayor de edad.
	if(diff_year>=19) i=1;
	else if(diff_year==18){
		
			if (diff_month>0) i=1;
			else if(diff_month==0){
					
					if (diff_day>0) i=1;
					else if(diff_day==0) {
						i=1;
						printf("\n \t Oh, hoy es tu cumplea%cos. Felicidades!!",164);
					}
				}
		
		}
				
	//Comprobaci�n de mayor�a de edad
	if (i==0) {	
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
//funci�n login
void login (char *p,int *q)//CON PUNTEROS MODIFICAMOS EL CONTENIDO DE NICK_USUARIO Y FLAG
{
	//Indice de iteraci�n
	int i;
	//auxiliar para comprobar si los datos son correctos.
	int flag;
	//iteracion 
	int n;
	//Vector que almacena las estructuras de los usuarios registrados
	usuario registrados[100];
	
	//Cadenas de caracteres para el nick y la contrase�a del usuario logueandose
	char nick[16];
	char pass[16];
	
	FILE *pf,*pf4;
	//Abrimos un fichero, en modo lectura en el que se almacenaran los datos de los usuarios
	pf=fopen("registro_usuarios.txt","r");
	pf4 = fopen("lista_provisional.txt", "w");//en modo write para modificarlo tantas veces como el usuario lo desee
	//Comprobamos si hay error al abrir el fichero
	if(pf==NULL) printf("Error al abrir el fichero.");

	//Usuario introduce sus datos
	//Bucle que se repite hasta que el usuario introduzca datos v�lidos.
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
	
		//comprueba si el inicio de sesi�n es correcto.
	
		while(fscanf(pf,"%[^;];%[^;];%[^;];%[^\n]\n",registrados[n].nombre,registrados[n].apellidos,registrados[n].nickname,registrados[n].password)!=EOF&&flag!=0)
		{
			//Comprobamos usuario y contrase�a
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
			*q=1;//la bandera que indica que el usuario a iniciado sesi�n se activa
			fprintf(pf4,"%s\n",nick);
		}
		else
		{
		  printf("\n\t Nickname o contrase%ca incorrectos.\n",164);
		  system("pause");
		  system("cls");
		}
    }while(flag==1);
    
    //Asignaci�n de la cadena almacenada en nick a la que guarda el nombre del usuario cuya sesi�n est� iniciada.
    //Quitar este for y el nick de la declaracion porque son innecesarios
  	for (i=0;i<16;i++)
  	{
  		*(p+i)=nick[i];
	}
	fclose(pf4);//cerramos la lista provisional
	
} 
void catalogo_completo(int flag)
{
	int i,m,k,a,j;
	producto productos[N];
	
	system("cls");
	
	printf("\n\tCAT%cLOGO\n",181);
		
	leer_catalogo(productos,N);
	
	for(i=0;i<N;i++)
	{

	printf("%s\n\tEspecificaciones:\n\t\t%s\n\t\t%s\n\t\t%s\n\tCodigo: %s\n",
	       productos[i].nombre,
	       productos[i].Especificaciones[0].Descripcion,
	       productos[i].Especificaciones[1].Descripcion,
	       productos[i].Especificaciones[2].Descripcion,
	       productos[i].codigo);
	printf("\tPrecio: %f\n\tUnidades: %i\n\n",
           productos[i].precio,
           productos[i].unidades);

   }   
if(flag==1)
   comprando();
else
   printf("Para realizar compras debe iniciar sesion\n");
}
void categorias(int flag)
{	
int p=0,i;//p es una bandera que nos sirve para saber si el usuario a introducido un caracter v�lido o no y de esta forma saber si se lo tenemos que volver a pedir 
char eleccion;//mejor ser�a cambiar eleccion una cadena de caracteres por si el usuario en vez introoducir una letra mal, introduce varias letra, numero y simbolo mal

system("cls");

printf("\n\tCATEGOR%cAS\n",214);
printf("\n Elige la categor%ca:\n",161);
printf("\tAmperimetros(A)\n \tBobinas(B)\n \tCondensadores(C)\n \tPilas(P)\n \tResistencias(R)\n \tConmutadores(S)\n \tTransitores(T)\n ");
//Apartir de esta parte no se ve. entonces aqui esta el problema. No atras, solo mira a partir de aqui
do{
scanf("%c",&eleccion);
//system("pause");
switch (eleccion)
{
case 'A':
case'a':
	p=1;//bandera cambia
	evalua(flag,0);
    break;
    
case 'B':
case 'b':
	p=1;
    evalua(flag,1);
    break;

case 'C':
case'c':
	p=1;//bandera cambia
	evalua(flag,2);
    break;
    
case 'P':
case 'p':
	p=1;
    evalua(flag,3);
    break;

case 'R':
case 'r':
	p=1;
    evalua(flag,4);
    break;

case 'S':
case's':
	p=1;//bandera cambia
	evalua(flag,5);
    break;
    
case 'T':
case 't':
	p=1;
    evalua(flag,6);
    break; 
     
}
}while(p!=1);
}	
void evalua(int flag,int j)//funci�n que te muestra las categor�as,int j);//funci�n que compara si la "eleccion" concide con el tipo y manda imprimir productos del mismo tipo
{
	
  int m=0,p=0;
  
  producto productos[N];
  clasificacion clasificaciones[M];
  
  leer_catalogo(productos,N);//Leemos los productos y guardamos los datos en un vectores de estructuras
  leer_clase(clasificaciones,M);//Leemos las clases de producto y guardamos los datos en un vectores de estructuras
  
  system("cls");
  
  printf("%s\n", clasificaciones[j].TIPO);//imprime el tipo de producto Ejemplo imprime la palabra Condensador almacenada en el vector de estructuras "clasificciones"
  for(p=0;p<N;p++)
  {
  m=strcmp(productos[p].tipo,clasificaciones[j].letra);//de la libreria string,compara. letra[j]=letra del producto
 
  if (m==0)//si son iguales imprimo toda la informaci�n del producto//doble igual de pregunta, no de asignaci�n
  {
    printf("%s\n\tEspecificaciones:\n\t\t%s\n\t\t%s\n\t\t%s\n\tCodigo: %s\n",
	       productos[p].nombre,
	       productos[p].Especificaciones[0].Descripcion,
	       productos[p].Especificaciones[1].Descripcion,
	       productos[p].Especificaciones[2].Descripcion,
	       productos[p].codigo);
	printf("\tPrecio: %f\n\tUnidades: %i\n\n",
           productos[p].precio,
           productos[p].unidades);
  }
  }
  if(flag==1)
   comprando();
  else
   printf("Para realizar compras debe iniciar sesion\n");

}
void ofertas(int flag)//(/*producto productos[],int dimension*/)//Las ofertas son fijas de cada objeto, no se actualizan cada vez que se abre el programa
{
	char letra1[10]="oferta";
	int p,m=0;//N sigue siendo el n�mero de productos. i contador
	producto productos[N];

	leer_catalogo(productos,N);//Leemos los productos y guardamos los datos en un vectores de estructuras

	for(p=0;p<N;p++)
	  {
	  
	  	m=strcmp(productos[p].estado,letra1);
	
	  if (m==0)//si son iguales imprimo toda la informaci�n del producto//doble igual de pregunta, no de asignaci�n
	  {
	    printf("%s\n\tEspecificaciones:\n\t\t%s\n\t\t%s\n\t\t%s\n\tCodigo: %s\n",
		       productos[p].nombre,
		       productos[p].Especificaciones[0].Descripcion,
		       productos[p].Especificaciones[1].Descripcion,
		       productos[p].Especificaciones[2].Descripcion,
		       productos[p].codigo);
		printf("\tPrecio: %f\n\tUnidades: %i\n\n",
	           productos[p].precio,
	           productos[p].unidades);
	  }
	  }
  if(flag==1)
   comprando();
  else
   printf("Para realizar compras debe iniciar sesion\n");

}
void comprando()
{
	char eleccion;
	char seguir;
	//cadena de caracteres que guarda la eleccion del usuario de a�adiro productos a su carrito definimos una cadena de caracteres por 
	//si el usuario en vez introoducir una letra mal, introduce varias letras, numero y simbolo, y as� evitamos que todo el programa deje de funcionar
	CODE CODIGOS[20];//vector de estructuras que guarda los c�digos de los productos que el usuario desea a�adir a su carrito
	producto productos[N];
	int unidades[20];//vector que guarda las de los productos que el usuario desea a�adir a su carrito
	int i=0,b=0,g=0,t=0,j=0,h=0,w=0;//b=bandera para saber si segimos o no ejecutando el bucle do while
	int flag=1000;//AUXIALIAR PARA COMPROBAR EL C�DIGO ELEGIDO PARA LA COMPRA
	char fallo;//auxiliar para cuando no hay suficientes items en stock
	
	leer_catalogo(productos,N);

	 do{
	printf("Indroduzca la letra (A) si desea anadir algo a su carrito\n");
	scanf(" %c",&eleccion);
	switch (eleccion)
	   {
		case 'A':
		case 'a':
		{	//do{
				printf("Codigo:");                                                                        
			    scanf(" %s",CODIGOS[i].CODIGOCOMPRA);//no poner & porque es cadena de caracteres pg 54 teor�a tema 4
			    
			    for(j=0;j<N;j++){//COMPROBAMOS SI EL CODIGO INTRODUCIDO COINCIDE CON ALGUNO DE LSO CODIGOS DE LOS ITEMS
			    	if(strcmp(CODIGOS[i].CODIGOCOMPRA,productos[j].codigo)==0) {
			    		flag=1;
			    		h=j;//FLAG PARA INDICAR LUEGO EL NUMERO Y PRECIO
					}	
				}
				
				if(flag==1){
					
					printf("\nUnidades:");
					scanf("%i",&unidades[i]);
					
					if(unidades[i]>productos[h].unidades){
						
						printf("Lo sentimos, pero no tenemos suficientes unidades en stock.\n");
						
						do{
							printf("Para realizar la compra de %i unidades pulse 'c', y para cancelar la compra pulse 'h'.\n",productos[h].unidades);
							scanf(" %c",&fallo);
							switch(fallo){
								case'c':
								{
					
									//compra el numero indicado
									
									FILE *pf;
									//Abrimos un fichero, en el qeu sobreescribimos los datos almacenados en el vector de estructuras, de manera que se altere el numero de unidades
									pf=fopen("lista_de_productos_1.txt","w");
									//Comprobamos si hay error al abrir el fichero
									if(pf==NULL) printf("Error al abrir el fichero lista_de_productos_1.");
									
									
									for(j=0;j<N;j++){//COMPROBAMOS SI EL CODIGO INTRODUCIDO COINCIDE CON ALGUNO DE LSO CODIGOS DE LOS ITEMS
								    	if(j==h){
											fprintf(pf,"%f;%i\n",productos[j].precio,0);//0 porque ha accedido a comprar todas las unidades posibles
										}
									
										else{
											fprintf(pf,"%f;%i\n",productos[j].precio,productos[j].unidades);
										}
									}	

								
									fclose(pf);
									
									t=1;
									break;
									}
								case'h':{
									b=1;
									t=1;
									break;
								}
									
								default:{
									printf("Opcion no valida, intentelo de nuevo.\n");
									t=0;
									break;
								}
									
							}	
						} while(t==0);
					}   
					
					else{
						//compra el numero indicado
									FILE *pf;
									//Abrimos un fichero, en el qeu sobreescribimos los datos almacenados en el vector de estructuras, de manera que se altere el numero de unidades
									pf=fopen("lista_de_productos_1.txt","w");
									//Comprobamos si hay error al abrir el fichero
									if(pf==NULL) printf("Error al abrir el fichero lista_de_productos_1.");
									
									
									for(j=0;j<N;j++){//COMPROBAMOS SI EL CODIGO INTRODUCIDO COINCIDE CON ALGUNO DE LSO CODIGOS DE LOS ITEMS
								    	if(j==h){
											fprintf(pf,"%f;%i\n",productos[j].precio,productos[j].unidades-unidades[i]);
										}
									
										else{
											fprintf(pf,"%f;%i\n",productos[j].precio,productos[j].unidades);
										}
									}	

									
									
									fclose(pf);
					}
				}
				
				else{
					printf("\tCodigo no valido\n\n");
				}
				
				i++;
				
				do
				{
				printf("Opciones:\nSeguir Anadiendo productos(A)\nConfirmar su lista(C)\n");
				scanf(" %c",&seguir);//guardamos la elecci�n en una cadena de caracteres por si el usuario introduce muchos d�gitos erroneamernte
				//PONERLE UN ESPACIO A %c despu�s de " SIEMPRE SOLO A %c no para los dem�s %i %f %s
			//}while(seguir==1)
			//el do while al comienzo del case A no es conveniente porque si el usuario introduce otro n�mero a casualida. y quiere en realidad seguir a�adiendo productos, no podr�a hacerlo
				switch (seguir)
				{
				case 'A':
				case 'a':
				{
					printf("Codigo:");                                                                        
				    scanf(" %s",CODIGOS[i].CODIGOCOMPRA);//no poner & porque es cadena de caracteres pg 54 teor�a tema 4
				    
				    for(j=0;j<N;j++){//COMPROBAMOS SI EL CODIGO INTRODUCIDO COINCIDE CON ALGUNO DE LSO CODIGOS DE LOS ITEMS
				    	if(strcmp(CODIGOS[i].CODIGOCOMPRA,productos[j].codigo)==0) {
				    		flag=1;
				    		h=j;//FLAG PARA INDICAR LUEGO EL NUMERO Y PRECIO
						}	
					}
					
					if(flag==1){
						
						printf("\nUnidades:");
						scanf("%i",&unidades[i]);
						
						if(unidades[i]>productos[h].unidades){
							
							printf("Lo sentimos, pero no tenemos suficientes unidades en stock.\n");
							
							do{
								printf("Para realizar la compra de %i unidades pulse 'c', y para cancelar la compra pulse 'h'.\n",productos[h].unidades);
								scanf(" %c",&fallo);
								switch(fallo){
									case'c':
									{
							
										//compra el numero indicado
										
										FILE *pf;
										//Abrimos un fichero, en el qeu sobreescribimos los datos almacenados en el vector de estructuras, de manera que se altere el numero de unidades
										pf=fopen("lista_de_productos_1.txt","w");
										//Comprobamos si hay error al abrir el fichero
										if(pf==NULL) printf("Error al abrir el fichero lista_de_productos_1.");
										
										
										for(j=0;j<N;j++){//COMPROBAMOS SI EL CODIGO INTRODUCIDO COINCIDE CON ALGUNO DE LSO CODIGOS DE LOS ITEMS
									    	if(j==h){
												fprintf(pf,"%f;%i\n",productos[j].precio,0);//0 porque accepta comprar todo el stock
											}
										
											else{
												fprintf(pf,"%f;%i\n",productos[j].precio,productos[j].unidades);
											}
										}	
	
										fclose(pf);
										
										t=1;
										break;
										}
									case'h':{
										b=1;
										t=1;
										break;
									}
										
									default:{
										printf("Opcion no valida, intentelo de nuevo.\n");
										t=0;
										break;
									}
										
								}	
							} while(t==0);
						}
						
						else{
							//compra el numero indicado
							
									FILE *pf;
									//Abrimos un fichero, en el qeu sobreescribimos los datos almacenados en el vector de estructuras, de manera que se altere el numero de unidades
									pf=fopen("lista_de_productos_1.txt","w");
									//Comprobamos si hay error al abrir el fichero
									if(pf==NULL) printf("Error al abrir el fichero lista_de_productos_1.");
									
									
									for(j=0;j<N;j++){//COMPROBAMOS SI EL CODIGO INTRODUCIDO COINCIDE CON ALGUNO DE LSO CODIGOS DE LOS ITEMS
								    	if(j==h){
											fprintf(pf,"%f;%i\n",productos[j].precio,productos[j].unidades-unidades[i]);
										}
									
										else{
											fprintf(pf,"%f;%i\n",productos[j].precio,productos[j].unidades);
										}
									}	

									
									
									fclose(pf);
							
						}  
					}
					
					else{
						printf("\tCodigo no valido\n\n");
					}
					
					i++;
				
			        break;
			    }
			    case 'C':
				case 'c'://en esta opci�n damos la orden de pasar la informaci�n al carrito FALTA DESARROLLAR ESTA PARTE MA�ANA CONTINUO
				{
					b=1;//bandera cambia Y se deja de ejecutar el bucle
					//mostrarcarrito(CODIGOS,20,unidades,20,i);//i es el n�mero de productos que se a�ade a la lista
					mostrar_carrito(CODIGOS,20,unidades,20,i);//i es el n�mero de productos que se a�ade a la lista
				    break;	
			    }
				default:
				{	
					//system("cls");
			    	printf("Caracter introducido no valido");
					b=0;
					break;
			    }
			    }//llave del switch  
			    }while(b==0);//se jecuta mientra la bandera no cambia de valor. mientra la expresi�n es verdadera
			     g=1;//ya hemos ababado exitosamente la opreacion de a�adir productos a carrito
			     break;
	    }
	    default:
	    {
	    	system("cls");
			printf("Caracter introducido no valido");
			g=0;
			break;
	    }
	  }//Llave del switch
	  }while(g==0);
}
void mostrar_carrito(CODE CODIGOS[],int dimension1,int unidades[],int dimension2,int i)//i te da el n�mero de productos que ha comprado el usuario
{
	//Estas dos l�neas de c�digo son necesaria para poder imprimir la fecha
	time_t t = time(NULL);
    struct tm tm = *localtime(&t);
	int m0,m1,g;
	int m,j=0,k=0,n;
	float s=0;
	char nick_usuario[16];
	producto productos[N];
	FILE *pf4;//puntero que se�ala a fichero 
	pf4 = fopen("lista_provisional.txt", "r");
	//Leo el nick_usario del fichero
	n = fscanf(pf4,"%s",nick_usuario);
	//cierro el fichero
	fclose(pf4);
	leer_catalogo(productos,N);
	
if (i!=0)
{
printf("\tProductos\t\t\t\t\tUnidades\t\t\t\t\tPrecio\n\n");//imprimimos los productos en pantalla seg�n los c�digos
do
{
    g=0;//volvemos a recorrer todos los productos para buscar el producto que tenga el c�digo del producto que me falta imprimir
	do 
	{   /*if(strcmp(CODIGOS[j].CODIGOCOMPRA,"no")==0)
	    j++;//Pasamos al siguiente c�digo Y �Que pasar�a si el usuario introduce un c�digo no v�lido, el bucle no terminar�a? Resolver ese problema*/ //SI YA HE HECHO EL TRASLADE DE LOS PRODUCTOS, ENTONCES YA NO NECESITO ESTAS DOS L�NEAS PORQUE TENGO QUE IMPRIMIR TODA LA LISTA
	    m=strcmp(productos[g].codigo,CODIGOS[j].CODIGOCOMPRA);
	    g++;
	}while(m!=0);
//for(k=0;k<i ;k++)
printf("%i.%s\t\t\t\t\t",k+1,productos[g].nombre); //como estoy imprimiendo cadenas de caracteres de distinto tama�o por eso no se imprime todo en una misma fila
printf("%i\t\t\t\t\t",unidades[j]);
printf("%f\n",productos[g].precio*unidades[j]);//solucion 1 de poner espacios no funciona. ahora probar solucion 2 de poner la infor en distintos printf este problema es solo porque en una linea pones distiontos tipos de caracterres que quieres imprimir
s+=productos[g].precio*unidades[j];
j++;//Pasamos al siguiente codigo porque solo hay un codigo parar cada producto
k++;//k es el contador del n�mero de productos que se ha impreso y el bucle acaba cuando ya hemos imprimido los i productos
}while(k!=i);//El bucle tiene que acabar cuando el vector de unidades se ha recorrido totalmente, porque eso significa que ya hemos impreso toda la lista 
printf("\n\t\t\t\t\t\t\t\t\t\t\tPrecio total %f\n",s);
}

opciones_carrito(CODIGOS,20,unidades,20,i,nick_usuario,16);
}   
void opciones_carrito(CODE CODIGOS[],int dimension1,int unidades[],int dimension2,int i,char nick_usuario[],int dimension3)
{
	//Estas dos l�neas de c�digo son necesaria para poder imprimir la fecha
	time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int g=0,m,n,T=0,j,flag1=0;
	char val[4];
	float val1;
	historial compras[100];
	CODE CODIGOS1[100];
	int unidades1[100];
	leer_historial(compras,100,CODIGOS1,100,unidades1,100,&j);//modifico el contenido de j a traves de un puntero
FILE *pf5;
pf5 = fopen("numero_tarjeta.txt", "a");//Abrimos el fichero para poder escribir en �l
FILE *pf9;//puntero que se�ala a fichero 
pf9 = fopen("historial_compras.txt", "a");//Abrimos el fichero para escribir sobre �l
FILE *pf10;//puntero que se�ala a fichero 
pf10 = fopen("lista_provisional1.txt", "a");
char eleccion;
long int tarjeta;
long int pin;
int numprod,p,h;

printf("\n\nIntroduce la letra correspondiente para\n \tModificar la compra\n \tCambiar unidades(C)\n \tQuitar productos(Q)\n \tAnular la compra(S)\n \tPagar(P)\n \tGuardar Lista provisional (G)\n \tPara volver al Menu Principal debe Guardar o Anular la lista\n");
do
{
scanf(" %c",&eleccion);
switch (eleccion)
{
case 'C':
case 'c':
	{
		flag1=1;
	    printf("Seleccione el producto 1  2  3 ...\n");
	    scanf("%i",&numprod);//n�mero de producto
	    printf("Introduzca las unidades que desee\n");
	    scanf("%i",&unidades[numprod-1]);//NO NECESITAS PONER &???????????????PARA LLENA UNA COMPONENTE DE UN VECTOR DE ESTRUCTURA NO, PERO PARA UN VECTOR COMUN Y CORRIENTE
	    system("cls");//limpia la pantalla
	    mostrar_carrito(CODIGOS,20,unidades,20,i);//Damos la orden para que se imrpima la lista
	    break;
    }
case 'Q':
case 'q':
	{
		flag1=1;
        printf("Seleccione el producto 1. 2. 3. ...\n");
	    scanf("%i",&numprod);//n�mero de producto
	    for(h=0;h<i-numprod;h++)
	    {
	    strcpy(CODIGOS[numprod-1+h].CODIGOCOMPRA,CODIGOS[numprod+h].CODIGOCOMPRA);//traslado el contenido para que si el usuario quisiera quitar de nuevo un producto de la lista, lo pueda hacer
	    //Hago lo mismo para el vector de unidades
	    //strcpy(unidades[numprod-1+h],unidades[numprod+h]);//pero strcpy solo copia cadena de caracteres, as� que para trasladar n�meros tendr�s que pensar en otra cosa, porque si o si los n�mero 
		//y los c�digo deben ser trasladados para que se correspondan
	    }
	    i--;//Ahora tengo un producto menos
	    //printf("%s",CODIGOS[numprod-1].CODIGOCOMPRA);//Si hace la asignaci�n
	    //CODIGOS[numprod-1]=0;//Imagina que el usuario al hacer la compra introduce en una de las unidades de un producto un 0, eso significar�a que no quiere ese producto, pero 
		//igual introdujo el c�digo y unidades a prop�sito. entonces, al hacer esta l�nea de c�digo tambi�n estamos cubriendo esa posibilidad
		//unidades[numprod-1]=0;//Esta l�nea es innecesaria
		system("cls");//limpia la pantalla
		//printf("Carrito vacio\n");
		mostrar_carrito(CODIGOS,20,unidades,20,i);//Damos la orden para que se imrpima la lista
		break;
	}
case 'S':
case 's':
	{
		flag1=1;
	    system("cls");//limpia la pantalla
		printf("Carrito vacio\n");
	    break;
	    //Doy la orden de que se limpie la venta para que no aparesca ning�n producto
	}
case 'P':
case 'p':	
{
	    system("cls");//limpia la pantalla
	    flag1=1;
	    fprintf(pf5,"%s;",nick_usuario);//imprimo el nick del usuario
        printf("Numero de tarjeta:");
        scanf("%ld",&tarjeta);
        fprintf(pf5, "%ld;", tarjeta);//Escribimos en el fichero
        printf("\nPIN:");
        scanf("%ld",&pin);
        fprintf(pf5, "%ld\n", pin);//Escribimos el pin en la misma l�nea separado por ;*/
        //Reci�n cuando se paga la compra, la informaci�n se imprime en el hisotrial
        //En el formato en el que he escrito el historial

//PARA SABER QUE N�MERO DE COMPRA ES
do
 {
 m=strcmp(nick_usuario,compras[T].usuario);//bucamos los productos del usuario
 if(m==0)//si coinciden imprimimos los productos
 {
 strcpy(val,compras[T].n_compra);//si la compra es del usuario asigno el n�mero de compra a val
 T++;//pasamos a la l�nea siguiente
}
 else 
 T++;//si la l�nea no es del usuario, paso a la siguiente
}while(T!=j);//el bucle termina cuando hayamos recorrido todo el fichero

*val+=1;//este es el n�mero de compra que realizaremos ahora
//printf("%s\n",val);
//como el i me da el n�mero de productos que he comprado,recorro los vectores conla compra i veces
for(T=0;T<i;T++)
{
fprintf(pf9,"%s;",nick_usuario);//imprimo el nick del usuario
fprintf(pf9,"%s;",val);//Imprimo n�mero de compra es
fprintf(pf9,"%i;",i);//y te da el n�mero de productos de la compra
fprintf(pf9,"%d/%d/%d;", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);//imprimo la fecha
fprintf(pf9,"%s;",CODIGOS[T].CODIGOCOMPRA);//imprimo el c�digo del producto
fprintf(pf9,"%i\n",unidades[T]);//imprimo las unidades
}
printf("Compra realizada satisfactoriamente\n");
break;
}
case 'G':
case 'g'://imprimimos en el fichero lista_provisional la lista
	{
	flag1=1;
	 for(T=0;T<i;T++)//i es el n�mero de productos
	 {
	 fprintf(pf10,"%s;",nick_usuario);//imprimo el nick del usuario
     fprintf(pf10,"%i;",i);//y te da el n�mero de productos de la compra
     fprintf(pf10,"%d/%d/%d;", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);//imprimo la fecha
     fprintf(pf10, "%s;", CODIGOS[T].CODIGOCOMPRA);
     fprintf(pf10, "%i\n", unidades[T]);
     }
     printf("Recuerde que solo puede guardar una lista provisional\nSi desea guardar una nueva lista debera ir a su Historial y anular la lista provisional anterior\n");
     break;
    }
	
default:
	{
	    
	    printf("Opcion no valida. Vuelva a intentarlo\n");
	    break;
	}
}
}while(flag1!=1);//sirve para que si el usuario presiona un caracter no v�lido como opci�n, el programa todav�a continue
fclose(pf5);//cerramos el fichero aqu� porque que si el usuario no quisiese alterar su lista y no optar� por seleccionar alguna opci�n y defrente cerrase el programa, el fichero no quedar�a sin cerrar
fclose(pf9);//Cerramos el fichero historial
fclose(pf10);
}   
void filtro_precio(int flag)
{//Funci�n que filtra el cat�logo de manera que solo muestre los objetos que pertenezcan a un intervalo de precios a elegir por el usuario.
	float a, b;//L�mites de precios a filtrar
	int i, flag1=0;//auxiliares
	producto productos[N];

	leer_catalogo(productos,N);//Leemos el catalogo y guardamos los datos en un vectores de estructuras

	printf("Precios\n");
	
	do
	{
		
		printf("Indique los dos extremos del intervalo de precio\n\n");
		scanf(" %f %f", &a, &b);
		
		
		
		for(i=0;i<N;i++)
		{
		
		if(productos[i].precio<=b && productos[i].precio>=a) //Comprueba si los precios de cada objeto est� dentro del intervalo elegido
			{//si se cumple, se imprime el objeto, junto con todas sus especificaciones
				
			printf("%s\n\tEspecificaciones:\n\t\t%s\n\t\t%s\n\t\t%s\n\tCodigo: %s\n",
	    		productos[i].nombre,
	       		productos[i].Especificaciones[0].Descripcion,
	       		productos[i].Especificaciones[1].Descripcion,
	       		productos[i].Especificaciones[2].Descripcion,
	       		productos[i].codigo);
	       		
			printf("\tPrecio: %f\n\tUnidades: %i\n\n",
           		productos[i].precio,
           		productos[i].unidades);
           		
       		 	flag1=1;
       		 	
			}	
			
		}
	
	if(flag1==0) printf("No hay ning�n objeto en ese rango de precio, por favor intentelo de nuevo.\n\n");
	//en caso de que ningun objeto cumpla el intervalo de precio determinado, se solicita un nuevo intervalo
	
	}
	while(flag1==0);
if(flag==1)
   comprando();
else
   printf("Para realizar compras debe iniciar sesion\n");
}
void leer_catalogo(producto productos[],int dimension)
{
	
	int i=0;
	int n, h;//auxiliar para lectura de ficheros
	
	FILE *pf;
	//Abrimos un fichero, en modo lectura en el que se almacenaran los datos de los usuarios
	pf=fopen("lista_de_productos_1.txt","r");
	//Comprobamos si hay error al abrir el fichero
	if(pf==NULL) printf("Error al abrir el fichero lista_de_productos_1.");
	
	FILE *df;
	//Abrimos un fichero, en modo lectura en el que se almacenaran los datos de los usuarios
	df=fopen("lista_de_productos.txt","r");
	//Comprobamos si hay error al abrir el fichero
	if(df==NULL) printf("Error al abrir el fichero lista_de_productos.");
	
	
	for(i=0;i<N;i++)
		{
			
		n=fscanf(df,"%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n",
  			productos[i].tipo,
  			productos[i].nombre,
  			productos[i].Especificaciones[0].Descripcion,
  			productos[i].Especificaciones[1].Descripcion,
  			productos[i].Especificaciones[2].Descripcion,
  			productos[i].Especificaciones[3].Descripcion,
  			productos[i].estado,
  			productos[i].codigo);//Leemos todos los productos
  			
		h=fscanf(pf,"%f;%i\n",
  			&productos[i].precio,
  			&productos[i].unidades);//leemos los precios, y el n�mero de unidades
  				
  		}
  		
  		fclose(pf); // Cerramos fichero
		fclose(df); // Cerramos fichero
}			
void leer_clase(clasificacion clasificaciones[],int dimension1)
{
	int i=0;
	int n;//auxiliar para lectura de ficheros
	
	FILE *tf;
	//Abrimos un fichero, en modo lectura en el que se almacenaran los datos de los usuarios
	tf=fopen("lista_de_tipos.txt","r");
	//Comprobamos si hay error al abrir el fichero
	if(tf==NULL) printf("Error al abrir el fichero lista_de_productos.");
	
	
	for(i=0;i<M;i++)
		{//Leemos la informaci�n y la guardamos en un vector de estructuras
		
		n=fscanf(tf,"%[^;];%[^;];%i\n",
			clasificaciones[i].letra,
			clasificaciones[i].TIPO,
			&clasificaciones[i].NTIPO);
		
  		}
  		
		fclose(tf); // Cerramos fichero	
}
//lee historial
void leer_historial(historial compras[],int d1,CODE CODIGOS[],int d2,int unidades[],int d3,int *p)//Le paso el nickname desde login 
{
int i,m=10,J=0;//A m le damos cualquier valor distinto de cero para asegurarnos de entrar en el bucle

FILE *pf9;//puntero que se�ala a fichero 
pf9 = fopen("historial_compras.txt", "r");//Abrimos el fichero

//for(i=0;i<9;i++)
while(m!=EOF)//Recorremos todo el fichero
{
m=fscanf(pf9,"%[^;];%[^;];%[^;];%[^;];%[^;];%i\n",compras[i].usuario,compras[i].n_compra,compras[i].n_prod,compras[i].fecha,CODIGOS[i].CODIGOCOMPRA,&unidades[i]);//Leemos y guardamos la informaci�n
J++;//contador de l�neas del fichero
i++;
}
*p=J;
//printf("%i",unidades[1]);//compruebo que la lectura se ha hecho bien
fclose(pf9); // Cerramos fichero
}
void historial_completo(char nick_usuario[],int dim)
{
	//Declaraci�n de variables y tipos de variables a utilizar
	int g=-1,m,n,i=0,k=1,j;
	float val;
	historial compras[100];
	CODE CODIGOS[100];
	int unidades[100];
	leer_historial(compras,100,CODIGOS,100,unidades,100,&j);//modifico el contenido de j a traves de un puntero
	producto productos[N];
    leer_catalogo(productos,N);//Leemos el catalogo y guardamos los datos en un vectores de estructuras //DOy la direccion de memoria y me llena los vectores
 
 do
 {
 m=strcmp(nick_usuario,compras[i].usuario);//bucamos los productos del usuario
 if(m==0)//si coinciden imprimimos los productos
 {
 printf("COMPRA %s",compras[i].n_compra);
 printf("\t\t\t\t\tFECHA: %s\n",compras[i].fecha);
 printf("\tProductos\t\t\t\t\tUnidades\t\t\t\t\tPrecio\n\n");//imprimimos los productos en pantalla seg�n los c�digos
 val=atof(compras[i].n_prod);//atof es una funci�n que transforma una cadena de caracteres en un float. Transformo
 //el n�mero de productos de cada compra a realya que inicialmente lo guarde como cadena de caracteres. Lo guardamos como cadena de caracteres para podre almacenar
 // esta informaci�n en un vector de estructuras del tipo historial(Lo puede ver en el fichero que guarda las estructuras) directamente utilizando un solo
 // fscanf(al leer el fichero historial_compras), ya que scanf no nos permit�a leer cadenas de caracteres y n�meros mezclados para cada l�nea del fichero
 
 for(n=0;n<val;n++)//imprimo todos los productos de la misma compra ya que tengo la informacion de cuantos productos tiene cada compra. 
 {  
    g=-1; //volvemos a comparar todos los productos
	do 
	{   
	    g++;//avanzamos al siguiente producto y lo imprimimos
	    m=strcmp(productos[g].codigo,CODIGOS[i].CODIGOCOMPRA);
	
	}while(m!=0);

printf("%i.%s\t\t\t\t\t",k,productos[g].nombre); //como estoy imprimiendo cadenas de caracteres de distinto tama�o por eso no se imprime todo en una misma fila
printf("%i\t\t\t\t\t",unidades[i]);
printf("%f\n",productos[g].precio*unidades[i]);//solucion 1 de poner espacios no funciona. ahora probar solucion 2 de poner la infor en distintos printf este problema es solo porque en una linea
i++;//paso a la siguiente l�nea del fichero
k++;//te imprime el n�mero del producto 1. 2. 3. 4.
}
}
else
i++;//si est� l�nea no es la del usuario entonces paso a la siguiente
}while(i!=j);//imagina que tienes j=5 l�neas entonces i recorrer�a las posiciones 0 1 2 3 4 (5 posiciones del vector, que se corresponden con 5 l�neas), y cuando i=5 la expresi�n es falsa y 
//el bucle ya no se ejecuta, con lo cual, he conseguido recorrer las 5 l�neas
}
void historial_fechas(char nick_usuario[],int dim)
{
	//Declaraci�n de varianles y tipos de variables a utilizar
	int i=0,k=1,g=-1,n,m,t=0,j;
	float val;
	char FECHA[15];
	historial compras[100];
	CODE CODIGOS[100];
	int unidades[100];
	
	leer_historial(compras,100,CODIGOS,100,unidades,100,&j);//modifico el contenido de j a traves de un puntero
	producto productos[N];
    leer_catalogo(productos,N);//Leemos el catalogo y guardamos los datos en un vectores de estructuras //DOy la direccion de memoria y me llena los vectores
    
	printf("\n\tEscriba la fecha con el formato: 2/3/2019\n",163);
	scanf("%s",FECHA);
	
   do
   { 
       m=strcmp(nick_usuario,compras[i].usuario);//bucamos los productos del usuario
       if(m==0)//si coinciden
       {
 	        if(strcmp(FECHA,compras[i].fecha)==0)//comparamos la fecha con la fecha que quiero, si coincide, se imprimira toda la compra de esa fecha
          	{
                 printf("COMPRA %s",compras[i].n_compra);
                 printf("\t\t\t\t\tFECHA: %s\n",compras[i].fecha);
                 printf("\tProductos\t\t\t\t\tUnidades\t\t\t\t\tPrecio\n\n");
                 val=atof(compras[i].n_prod);//atof es una funci�n que transforma una cadena de caracteres en un float
  
                 for(n=0;n<val;n++)//imprimo todos los productos de la misma compra ya que tengo la informacion de cuantos productos tiene cada compra. n_prod es una cadena de caracteres
                 {  
                 g=-1;//Tenemos que volver a recorrer el vector de productos cada vez que el bucle for se ejecute
	             do 
	             {   
	             g++;//avanzamos al siguiente producto 
	             m=strcmp(productos[g].codigo,CODIGOS[i].CODIGOCOMPRA);//imprimimos los productos en pantalla comparando los c�digos del historial con los codigos de todo el cat�logo
	             }while(m!=0);

                 printf("%i.%s\t\t\t\t\t",k,productos[g].nombre);
                 printf("%i\t\t\t\t\t",unidades[i]);
                 printf("%f\n",productos[g].precio*unidades[i]);
                 i++;//paso a la siguiente l�nea del fichero
                 k++;//te imprime el n�mero del producto 1. 2. 3. 4.
                }
                 t++;//bandera que me indica si se realizaron o no compras en la fecha introducida
            }
            else
            i++;//si las fechas no coinciden paso a la l�nea siguiente del fichero
       }
   else
   i++;//si las fechas no coinciden entonces paso a la siguiente l�nea siguiente del fichero
}while(i!=j);//El bucle se ejecuta hasta leer todo el fichero

if(t==0)//Si despu�s de leer todo el fichero, no se encontro ninguna compra realizada en la fecha indicada, se imprime este mensaje
printf("No se realizaron compras el %s\n",FECHA);

}
void ver_lista_provisional(char nick_usuario[],int dim)
{
	//Declaraci�n de variables y tipos de variables a utilizar
	int i=0,j=0,m=10,p=0,n,t;//asigno a m cualquier valor para asegurame de entrar en el bucle
    lista_prov lista[100];
	CODE CODIGOS1[100];
	int unidades1[100];
	CODE CODIGOS[100];
	int unidades[100];
    FILE *pf10;//puntero que se�ala a fichero 
    pf10 = fopen("lista_provisional1.txt", "r");//Abrimos el fichero

   while(m!=EOF)//Recorremos todo el fichero hasta el final
   {
     m=fscanf(pf10,"%[^;];%[^;];%[^;];%[^;];%i\n",lista[j].usuario,lista[j].n_prod,lista[j].fecha,CODIGOS1[j].CODIGOCOMPRA,&unidades1[j]);//Leemos y guardamos la informaci�n
     j++;//avanzamos en el vector en donde guardamos la informaci�n de cada l�nea del fichero
     p++;//contador de l�neas
   }

   fclose(pf10); // Cerramos fichero

   for(n=0;n<p;n++)//recorremos todos los elementos de los vectores en donde guardamos la informaci�n del fichero
   {
    m=strcmp(nick_usuario,lista[n].usuario);//bucamos los productos del usuario
    if(m==0)//si coinciden 
    {
 	   //Asignamos lainformaci�n a  nuevos vectores que luego pasaremos como argumentos de entrada a la funci�n mostrar_carrrito
 	   t=n;
 	   strcpy(CODIGOS[i].CODIGOCOMPRA,CODIGOS1[n].CODIGOCOMPRA);//.La asignaci�n es de derecha a izquierda
 	   unidades[i]=unidades1[n];
       i++;//i tiene el n�mero de productos de la lista
    }
   }
   
   n=t-i+1;//Este es el elemento en el que comienza la lista provisional del usuario

   //una vez ya le�da, la lista deja de ser provisional y toda la informaci�n de la lista debe desaparecer del fichero, para dar espacio a otra futura lista provisional del usuario
   //desplazamos la informaci�n que iba despues de est� lista i l�neas m�s abajo
    for(j=0;j<=p-n+i;j++)
    {
    	strcpy(lista[n+j].usuario,lista[n+i+j].usuario);//A la posiciona n va el producto que estaba en la posici�n n+i
    	strcpy(lista[n+j].n_prod,lista[n+i+j].n_prod);
    	strcpy(lista[n+j].fecha,lista[n+i+j].fecha);
    	strcpy(CODIGOS1[n+j].CODIGOCOMPRA,CODIGOS1[n+i+j].CODIGOCOMPRA);
    	unidades1[n+j]=unidades1[n+i+j];
    }

    //Imprimo la informacion de las listas provisionales (de todos los usuarios)en el fichero. Ya habiendo quitado la informaci�n de la lista del usuario 
    for(j=0;j<i;j++)
    {
    fprintf(pf10,"%s;",nick_usuario);//imprimo el nick del usuario
    fprintf(pf10,"%s;",lista[j].n_prod);//Imprimo n�mero de compra es
    fprintf(pf10,"%i;",lista[j].fecha);//y te da el n�mero de productos de la compra
    fprintf(pf10,"%s;",CODIGOS1[j].CODIGOCOMPRA);//imprimo el c�digo del producto
    fprintf(pf10,"%i\n",unidades[j]);//imprimo las unidades
    }

  //LLamo a la funci�n
  mostrar_carrito(CODIGOS,100,unidades,100,i);//i es el n�mero de productos de la lista
}
