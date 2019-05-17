//MENÃš DE INICIO de e-shop
//ESTE ES EL PROGRAMA DEFINITIVO DE TU GRUPO, SIMPLEMENTE TIENES QUE AGREGARLE EL PROTOTIPO Y LA DEFINICIÓN DE LA FUNCIÓN REGISTRO Y YA


//
//
// ESCRIBIR LAS OFERTAS Y DECIDIR EN CUALES LAS PONEMOS
//
//

#include <stdio.h>
#include <stdlib.h> /* system */
#include <string.h> /*strcmp*/
#define N 4 //N número de productos en venta
#define M 2 //M número de tipo de productos

typedef struct
    {
	    char Descripcion[30];
    }descripcion;

	typedef struct
	{
		char tipo[20];//tipo de producto letra ejemplo C de Condensador
		char nombre[50];//nombre exacto del producto. el que se mostrará en el carrito.
		descripcion Especificaciones[4];//cadena de caracteres que guardara la descripcion de los productos
		float precio;//resuelve el problema de filtrar producto por precios
		int unidades;//unidades disponibles
		char estado[10];//si está en oferta (1) o no(0), es una bandera para saber si el producto esta en oferta o no. 
	    char codigo[10];//esta componente sirve para diferencia varios productos del mismo tipo y que de esta forma podamos acceder a sus nombres
	}producto;//estructura de toda la informacion que contiene cada producto. podemos poner como codigos numero letras, letras y números.
	
	typedef struct
    {
        char letra[5];
        char TIPO[20];
        int NTIPO;//número de productos del mismo tipo Ejemplo 5 tipo distintos de Condensador
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

void catalogo_completo(int flag);//prototipo de la función
void categorias(int flag);
void evalua(int flag,int j);//función que compara si la elección concide con el tipo y manda imprimir productos del mismo tipo
void ofertas(int flag);/*producto productos[],int dimension*/
void comprando();
void filtro_precio(int flag);//función que filtra en base a un intervalo de precio dado por el usuario
void leer_catalogo(producto productos[],int dimension);//funcion que lee los ficheros y guarda los datos en un vector de estructuras
void leer_clase(clasificacion clasificaciones[],int dimension1);//funcion que lee los ficheros y guarda los datos en un vector de estructuras
void mostrar_carrito(CODE CODIGOS[],int dimension1,int unidades[],int dimension2,int i);
void opciones_carrito(CODE CODIGOS[],int dimension1,int unidades[],int dimension2,int i);
void leer_historial(historial compras[],int d1,CODE CODIGO[],int d2,int unidades[],int d3,int *p);//Le paso el nickname desde login
void historial_completo(char nick_usuario[],int dim);
void historial_fechas(char nick_usuario[],int dim);
//Función de registro.
void registro();

//Función del login.
void login(char *p,int *q);

void main()
{
	char election;
	char nick_usuario[16];//Cadena que almacena el nombre del usuario con sesión iniciada //el nombre de la cadena de caracteres de por si ya es un puntero, entonces no tienes que definir otro puntero
	int flag=0;
	//Caracter de opciones del menÃº 
	char option_menu;
	//Caracter de opciones del catÃ¡logo
	char option_cat;
    int m0=0,m=0,m1=0,i;
    int n=0,j;//variables locales. n1 número de tipos
    
    producto productos[N];//vector de estructuras//Perpiñan:la dimension del vector tiene que coincidir con el número de productos en tu lista
    clasificacion clasificaciones[M];//vector de estructuras
    
    FILE *pf,*pf1,*pf2/*,*pf3*/;//puntero que señala a fichero 
    
    pf = fopen("lista_de_productos.txt", "r");//Abrimos el fichero
    pf1 =fopen("lista_de_productos_1.txt","r");
    pf2 = fopen("lista_de_tipos.txt", "r");//Abrimos el fichero que contiene letras que se corresponden al tipo de producto, los nombres de los tipos de producto 
//y elnúmero de productos del mismo tipo//ojo a-->r
    //pf3 = fopen("lista_de_tipos_1.txt", "r");

	leer_catalogo(productos,N);
	leer_clase(clasificaciones,M);
	
	//Pantalla de inicio
	system("color E0");//cambia el color del fondo(E) y del texto(0).
	//LOGO
	printf("\n\t         ______                 _______    __    __    _______    _____");
	printf("\n\t       (  __   )               (  _____)  (  )  (  )  (  ___  )  (  __ )");
	printf("\n\t      (  (__)   )    _____     (  )____   (  )__(  )  ( (   ) )  ( (__) )");
	printf("\n\t     (    _____)    (_____)    (_____  )  (   __   )  ( (   ) )  (  ___) ");
	printf("\n\t      (  (_____                 ____(  )  (  )  (  )  ( (___) )  ( )");
	printf("\n\t       (_______)               (_______)  (__)  (__)  (_______)  (_)");
	printf("\n\n\n\n\t\t");
	system ("pause");//El programa hace una pausa, espera a que el usuario pulse una tecla para continuar.
	system("cls");//Limpia la pantalla.
	
	//MenÃº principal
	system ("color F0");//cambia el color del fondo(F) y del texto(0).
	do
	{
		system("cls");//limpia la pantalla
		//Pantalla de inicio
		printf("\n\te-shop\n");
    		printf("----------------------------------------------------------\n");
    		printf("\n BIENVENIDO\n\n");
 		printf("Seleccione una opci%cn para comenzar: \n\n \tAcceder al cat%clogo de productos (c)\n \tHistorial (h)\n \tInicio de sesi%cn (i)\n \tRegistrarse (r)\n \tSalir (s)\n",162,160,162);
    
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
								//CATÃLOGO COMPLETO
								system("cls");
								catalogo_completo(flag);
								system("pause");
								//comprando();
								break;	
							}
							case 'p':
							{
								//FILTRADO DE PRODUCTOS POR PRECIO (MAYOR-MENOR/MENOR-MAYOR)
								system("cls");
								//printf("\n\tPRODUCTOS ORDENADOS POR PRECIO\n");
								//printf("\n%cDesea que los productos se ordenen de mayor a menor precio (M) o de menor a mayor precio (m)?\n",168);
								//Filtro por intervalo de precios
								filtro_precio(flag);
								system("pause");
								break;
							}
							case 'o':
							{
								//OFERTAS
								system("cls");
								printf("\n\tOFERTAS\n");
								ofertas(flag);
								system("pause");
								break;
							}
							case 'k':
							{
								//CATEGORÃAS
								system("cls");
								categorias(flag);//función que te muestra las categorías
								system("pause");
								break;
							}
							default:
							{
								//CARACTER NO VÃLIDO
								system("cls");
								printf("Caracter introducido no vÃ¡lido.");
								system("pause");
								break;
									
							} 	
						}
						 				
      					break;
				}
			//PROBLEMA 1:NO APARECE h	
			case 'h':
				{
					system("cls");
					//printf("HOLIIII\n");
					//system("pause");
					if(flag==1)
					{
					    printf("Opciones:\n \tVer historial completo (H)\n \tVer historial por fechas (F)\n");
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
						default://CARACTER NO VÃLIDO
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
				{
					//REGISTRO DE NUEVO USUARIO
					system("cls");
					printf("\n\tCREA UNA CUENTA\n");
					
					//Función para el registro de nuevos usuarios
					registro();
					printf("\n");
					system("pause");
					break;
				}	
    			case 'i':
    				{
    					//INICIO DE SESIÓN
    					system("cls");
    					printf("\n\tINICIO DE SESI%cN\n",224);
    					//Función para el inicio de sesión
    					//Devuelve el nick del usuario iniciado una vez la sesión se inicia correctamente
    					//login(p);
    					login(nick_usuario,&flag);
    					printf("%s\n",nick_usuario);//compruebo que la asignacion se ha hecho correctamente
    					printf("%i",flag);//compruebo que la asignacion se ha hecho correctamente
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
					//CARACTER NO VÃLIDO
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

void login (char *p,int *q)//CON PUNTEROS MODIFICAMOS EL CONTENIDO DE NICK_USUARIO Y FLAG
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
	
	FILE *pf,*pf4;
	//Abrimos un fichero, en modo lectura en el que se almacenaran los datos de los usuarios
	pf=fopen("registro_usuarios.txt","r");
	pf4 = fopen("lista_provisional.txt", "w");//en modo write para modificarlo tantas veces como el usuario lo desee
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
			*q=1;//la bandera que indica que el usuario a iniciado sesión se activa
			fprintf(pf4,"%s\n",*p);
		}
		else
		{
		  printf("\n\t Nickname o contrase%ca incorrectos.\n",164);
		  system("pause");
		  system("cls");
		}
    }while(flag==1);
    
    //Asignación de la cadena almacenada en nick a la que guarda el nombre del usuario cuya sesión está iniciada.
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
int p=0,i;//p es una bandera que nos sirve para saber si el usuario a introducido un caracter válido o no y de esta forma saber si se lo tenemos que volver a pedir 
char eleccion;//mejor sería cambiar eleccion una cadena de caracteres por si el usuario en vez introoducir una letra mal, introduce varias letra, numero y simbolo mal

system("cls");

printf("\n\tCATEGOR%cAS\n",214);
printf("\n Elige la categor%ca:\n",161);
printf("\tCondensadores(C)\n\tPilas(P)\n\tConmutadores(S)\n\tResistencia(R)\n\tSalir(S)\n ");
//Apartir de esta parte no se ve. entonces aqui esta el problema. No atras, solo mira a partir de aqui
do{
scanf("%c",&eleccion);
//system("pause");
switch (eleccion)
{
case 'C':
case'c':
	evalua(flag,0);
    break;
    
case 'P':
case 'p':
    evalua(flag,1);
    break;
    
/*case 'S':
case's':
	
	j=2;
	evalua(productos,N,clasificaciones,M,j);
    break;
    
case 'R':
case'r':
	
	j=3;
	evalua(productos,N,clasificaciones,M,j);
    break;
    
default:
	
	p=1;
	printf("Caracter no valido. Vuelva a intentarlo\n");
    break;*/
    
}
}while(p=1);
}
	
void evalua(int flag,int j)//función que te muestra las categorías,int j);//función que compara si la "eleccion" concide con el tipo y manda imprimir productos del mismo tipo
{
	
  int m=0;
  int p=0;
  
  producto productos[N];
  clasificacion clasificaciones[M];
  
  leer_catalogo(productos,N);//Leemos los productos y guardamos los datos en un vectores de estructuras
  leer_clase(clasificaciones,M);//Leemos las clases de producto y guardamos los datos en un vectores de estructuras
  
  system("cls");
  
  printf("%s\n", clasificaciones[j].TIPO);//imprime el tipo de producto Ejemplo imprime la palabra Condensador almacenada en el vector de estructuras "clasificciones"
  for(p=0;p<N;p++)
  {
  m=strcmp(productos[p].tipo,clasificaciones[j].letra);//de la libreria string,compara. letra[j]=letra del producto//AquI debe de estar el error poeque antes el compilador me dijo que clasificaciones[j].NTIPO era un puntero
  //entonces lo que estarí haciendo aquíes comparar punteros
  printf("%i\n",m);//nunca me imprime ningun producto porque estoy comparando dos punteros que siempre son distindos
  //printf("%c %c",m1,m2);
  if (m==0)//si son iguales imprimo toda la información del producto//doble igual de pregunta, no de asignación
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

  //for(i=0;i<clasificaciones[j].NTIPO;i++)
  /*for(i=0;i<N;i++)
  {
  char m1=clasificaciones[j].letra[0];//Si utilizas esta linea de codigo te dará error porque dira que estay dando la direccion de memoria de un puntero a un caracter mm
  char m2=productos[i].tipo[0];
  m=strcmp(m1,m2);//de la libreria string,compara. letra[j]=letra del producto//AquI debe de estar el error poeque antes el compilador me dijo que clasificaciones[j].NTIPO era un puntero
  //entonces lo que estarí haciendo aquíes comparar punteros
  printf("%i\n",m);//nunca me imprime ningun producto porque estoy comparando dos punteros que siempre son distindos
  printf("%c %c",m1,m2);
  if (m==0)//si son iguales imprimo toda la información del producto//doble igual de pregunta, no de asignación
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
  }*/
}

//Filtro de ofertas
//PARTE 5
void ofertas(int flag)//(/*producto productos[],int dimension*/)//Las ofertas son fijas de cada objeto, no se actualizan cada vez que se abre el programa
{
	char letra1[10]="oferta";
	int p,m=0;//N sigue siendo el número de productos. i contador
	producto productos[N];

	leer_catalogo(productos,N);//Leemos los productos y guardamos los datos en un vectores de estructuras

	//system("cls");
	//printf("\n\tOFERTAS\n");

	for(p=0;p<N;p++)
	  {
	  	//printf("%s",productos[0].estado);
	  	m=strcmp(productos[p].estado,letra1);
	  	printf("%i\n",m);
	  if (m==0)//si son iguales imprimo toda la información del producto//doble igual de pregunta, no de asignación
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

//SOLO FALTA AGREGAR LA PARTE DE COMPRANDO. RECUERDA QUE ESA PARTE SE TIENE QUE MOSTRAR SOLO SI EL USUARIO A INICIADO SESIÓN
//FALTA AGREGAR LA PARTE DE CARRITO. TIENES QUE DESARROLLAR ESA PARTE POR SEPARADO Y LUEGO AGRAGARLA  A ESTE CÓDIGO FINAL
void comprando()
{
	char eleccion;
	char seguir;
	//cadena de caracteres que guarda la eleccion del usuario de añadiro productos a su carrito definimos una cadena de caracteres por 
	//si el usuario en vez introoducir una letra mal, introduce varias letras, numero y simbolo, y así evitamos que todo el programa deje de funcionar
	CODE CODIGOS[20];//vector de estructuras que guarda los códigos de los productos que el usuario desea añadir a su carrito
	producto productos[N];
	int unidades[20];//vector que guarda las de los productos que el usuario desea añadir a su carrito
	int i=0,b=0,g=0,t=0,j=0;//b=bandera para saber si segimos o no ejecutando el bucle do while
	int flag=0;
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
		    scanf("%s",CODIGOS[i].CODIGOCOMPRA);//no poner & porque es cadena de caracteres pg 54 teoría tema 4
			printf("\nUnidades:");
			scanf("%i",&unidades[i]);
			i++;
			do
			{
			printf("\nOpciones:\nSeguir Anadiendo productos(A)\nConfirmar su lista(C)\n");
			scanf(" %c",&seguir);//guardamos la elección en una cadena de caracteres por si el usuario introduce muchos dígitos erroneamernte
			//PONERLE UN ESPACIO A %c después de " SIEMPRE SOLO A %c no para los demás %i %f %s
		//}while(seguir==1)
		//el do while al comienzo del case A no es conveniente porque si el usuario introduce otro número a casualida. y quiere en realidad seguir añadiendo productos, no podría hacerlo
			switch (seguir)
			{
			case 'A':
			case 'a':
			{
				printf("\nCodigo:");                                                                        
		        scanf("%s",CODIGOS[i].CODIGOCOMPRA);
			    printf("\nUnidades:");
			    scanf("%i",&unidades[i]);
			    i++;
		        break;
		    }
		    case 'C':
			case 'c'://en esta opción damos la orden de pasar la información al carrito FALTA DESARROLLAR ESTA PARTE MAÑANA CONTINUO
			{
				b=1;//bandera cambia Y se deja de ejecutar el bucle
				mostrar_carrito(CODIGOS,20,unidades,20,i);//i es el número de productos que se añade a la lista
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
		    }while(b==0);//se jecuta mientra la bandera no cambia de valor. mientra la expresión es verdadera
		     g=1;//ya hemos ababado exitosamente la opreacion de añadir productos a carrito
		     break;
    }
    default:
    {
    	system("cls");
		printf("Caracter introducido no valido");
		g=0;
		break;
    }
}
	  }while(g==0);
}

void mostrar_carrito(CODE CODIGOS[],int dimension1,int unidades[],int dimension2,int i)//i te da el número de productos que ha comprado el usuario
{
	int m0,m1,g;
	int m,j=0,k=0;
	producto productos[N];
	FILE *pf4;//puntero que señala a fichero 
    pf4 = fopen("lista_provisional.txt", "w");//en modo write para modificarlo tantas veces como el usuario lo desee
	leer_catalogo(productos,N);
if (i!=0)
{
printf("\tProductos\t\t\t\t\tUnidades\t\t\t\t\tPrecio\n\n");//imprimimos los productos en pantalla según los códigos
do
{
    g=0;//volvemos a recorrer todos los productos para buscar el producto que tenga el código del producto que me falta imprimir
	do 
	{   /*if(strcmp(CODIGOS[j].CODIGOCOMPRA,"no")==0)
	    j++;//Pasamos al siguiente código Y ¿Que pasaría si el usuario introduce un código no válido, el bucle no terminaría? Resolver ese problema*/ //SI YA HE HECHO EL TRASLADE DE LOS PRODUCTOS, ENTONCES YA NO NECESITO ESTAS DOS LÍNEAS PORQUE TENGO QUE IMPRIMIR TODA LA LISTA
	    m=strcmp(productos[g].codigo,CODIGOS[j].CODIGOCOMPRA);
	    g++;
	}while(m!=0);
//for(k=0;k<i ;k++)
printf("%i.%s\t\t\t\t\t",k+1,productos[g].nombre); //como estoy imprimiendo cadenas de caracteres de distinto tamaño por eso no se imprime todo en una misma fila
printf("%i\t\t\t\t\t",unidades[j]);
printf("%f\n",productos[g].precio*unidades[j]);//solucion 1 de poner espacios no funciona. ahora probar solucion 2 de poner la infor en distintos printf este problema es solo porque en una linea pones distiontos tipos de caracterres que quieres imprimir
fprintf(pf4, "%s;", CODIGOS[j].CODIGOCOMPRA);
fprintf(pf4, "%i\n", unidades[j]);
j++;//Pasamos al siguiente codigo porque solo hay un codigo parar cada producto
k++;//k es el contador del número de productos que se ha impreso y el bucle acaba cuando ya hemos imprimido los i productos
}while(k!=i);//El bucle tiene que acabar cuando el vector de unidades se ha recorrido totalmente, porque eso significa que ya hemos impreso toda la lista 
}
opciones_carrito(CODIGOS,20,unidades,20,i);
}
    
void opciones_carrito(CODE CODIGOS[],int dimension1,int unidades[],int dimension2,int i)
{
FILE *pf5;
pf5 = fopen("numero_tarjeta.txt", "a");//Abrimos el fichero para poder escribir en él
char eleccion;
long long int tarjeta;
long int pin;
int numprod,j,h;
printf("\n\nIntroduce la letra correspondiente para\nModificar la compra\n\tCambiar unidades(C)\n\tQuitar productos(Q)\nAnular la compra(S)\nPagar(P)\nVolver a Menu Principal(M)\n");
scanf(" %c",&eleccion);
switch (eleccion)
{
case 'C':
case 'c':
	    printf("Seleccione el producto 1  2  3 ...\n");
	    scanf("%i",&numprod);//número de producto
	    printf("Introduzca las unidades que desee\n");
	    scanf("%i",&unidades[numprod-1]);//NO NECESITAS PONER &???????????????PARA LLENA UNA COMPONENTE DE UN VECTOR DE ESTRUCTURA NO, PERO PARA UN VECTOR COMUN Y CORRIENTE
	    system("cls");//limpia la pantalla
	    mostrar_carrito(CODIGOS,20,unidades,20,i);//Damos la orden para que se imrpima la lista
	    break;
case 'Q':
case 'q':
        printf("Seleccione el producto 1. 2. 3. ...\n");
	    scanf("%i",&numprod);//número de producto
	    for(h=0;h<i-numprod;h++)
	    {
	    strcpy(CODIGOS[numprod-1+h].CODIGOCOMPRA,CODIGOS[numprod+h].CODIGOCOMPRA);//traslado el contenido para que si el usuario quisiera quitar de nuevo un producto de la lista, lo pueda hacer
	    //Hago lo mismo para el vector de unidades
	    //strcpy(unidades[numprod-1+h],unidades[numprod+h]);//pero strcpy solo copia cadena de caracteres, así que para trasladar números tendrás que pensar en otra cosa, porque si o si los número 
		//y los código deben ser trasladados para que se correspondan
	    }
	    i--;//Ahora tengo un producto menos
	    //printf("%s",CODIGOS[numprod-1].CODIGOCOMPRA);//Si hace la asignación
	    //CODIGOS[numprod-1]=0;//Imagina que el usuario al hacer la compra introduce en una de las unidades de un producto un 0, eso significaría que no quiere ese producto, pero 
		//igual introdujo el código y unidades a propósito. entonces, al hacer esta línea de código también estamos cubriendo esa posibilidad
		//unidades[numprod-1]=0;//Esta línea es innecesaria
		system("cls");//limpia la pantalla
		//printf("Carrito vacio\n");
		mostrar_carrito(CODIGOS,20,unidades,20,i);//Damos la orden para que se imrpima la lista
		break;
case 'S':
case 's':
	    for(j=0;j<i;j++)
	    /*{
        strcpy(CODIGOS[j].CODIGOCOMPRA,"0");
		unidades[j]=0;
	    }*/ //En realidad aquí solo debo limpiar la ventana y ya
	    system("cls");//limpia la pantalla
		printf("Carrito vacio\n");
	    break;
	    //Doy la orden de que se limpie la venta para que no aparesca ningún producto
case 'P':
case 'p':	
        printf("Numero de tarjeta:");
        scanf("%lli",&tarjeta);
        fprintf(pf5, "%lli;", tarjeta);//Escribimos en el fichero
        printf("\nPIN:");
        scanf("%li",&pin);
        fprintf(pf5, "%li\n", pin);//Escribimos el pin en la misma línea separado por ;
        //Recién cuando se paga la compra, la información se imprime en el hisotrial
        //En el formato en el que he escrito el historial
        break;
/*case 'M':
case 'm':*/
default:
	    printf("Opcion no valida\n");
	    break;
}
fclose(pf5);//cerramos el fichero aquí porque que si el usuario no quisiese alterar su lista y no optará por seleccionar alguna opción y defrente cerrase el programa, el fichero no quedaría sin cerrar
}


    
void filtro_precio(int flag){//Función que filtra el catálogo de manera que solo muestre los objetos que pertenezcan a un intervalo de precios a elegir por el usuario.
	float a, b;//Límites de precios a filtrar
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
		
		if(productos[i].precio<=b && productos[i].precio>=a) //Comprueba si los precios de cada objeto está dentro del intervalo elegido
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
	
	if(flag1==0) printf("No hay ningún objeto en ese rango de precio, por favor intentelo de nuevo.\n\n");
	//en caso de que ningun objeto cumpla el intervalo de precio determinado, se solicita un nuevo intervalo
	
	}
	while(flag1==0);
if(flag==1)
   comprando();
else
   printf("Para realizar compras debe iniciar sesion\n");
}

void leer_catalogo(producto productos[],int dimension){
	
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
  			&productos[i].unidades);//leemos los precios, y el número de unidades
  				
  		}
  		
  		fclose(pf); // Cerramos fichero
		fclose(df); // Cerramos fichero
}
			


void leer_clase(clasificacion clasificaciones[],int dimension1){
	int i=0;
	int n;//auxiliar para lectura de ficheros
	
	FILE *tf;
	//Abrimos un fichero, en modo lectura en el que se almacenaran los datos de los usuarios
	tf=fopen("lista_de_tipos.txt","r");
	//Comprobamos si hay error al abrir el fichero
	if(tf==NULL) printf("Error al abrir el fichero lista_de_productos.");
	
	
	for(i=0;i<M;i++)
		{//Leemos la información y la guardamos en un vector de estructuras
		
		n=fscanf(tf,"%[^;];%[^;];%i\n",
			clasificaciones[i].letra,
			clasificaciones[i].TIPO,
			&clasificaciones[i].NTIPO);
		
  		}
  		
		fclose(tf); // Cerramos fichero	
}

//lee historial
void leer_historial(historial compras[],int d1,CODE CODIGO[],int d2,int unidades[],int d3,int *p)//Le paso el nickname desde login 
{
int i,m,J=0;

FILE *pf9;//puntero que señala a fichero 
pf9 = fopen("historial_compras.txt", "r");//Abrimos el fichero

for(i=0;i<2;i++)
{
m=fscanf(pf9,"%[^;];%[^;];%[^;];%[^;];%[^;];%i\n",compras[i].usuario,compras[i].n_compra,compras[i].n_prod,compras[i].fecha,CODIGO[i].CODIGOCOMPRA,&unidades[i]);//Leemos y guardamos la información
J++;//contador de líneas
}
*p=J;
//printf("%i",unidades[1]);//compruebo que la lectura se ha hecho bien
fclose(pf9); // Cerramos fichero
}

void historial_completo(char nick_usuario[],int dim)
{
	int g=-1,m,n,i=0,k=1,j;
	float val;
	historial compras[100];
	CODE CODIGOS[100];
	int unidades[100];
	leer_historial(compras,100,CODIGOS,100,unidades,100,&j);//modifico el contenido de j a traves de un puntero
	producto productos[N];
    leer_catalogo(productos,N);//Leemos el catalogo y guardamos los datos en un vectores de estructuras //DOy la direccion de memoria y me llena los vectores
 //Necesito algo que me indique cuantas compras se han hecho para saber cuantas veces tiene que aumentar t
 do
 {
 m=strcmp(nick_usuario,compras[i].usuario);//bucamos los productos del usuario
 if(m==0)//si coinciden imprimimos los productos
 {
 printf("COMPRA %s",compras[i].n_compra);
 printf("\t\t\t\t\tFECHA: %s\n",compras[i].fecha);
 printf("\tProductos\t\t\t\t\tUnidades\t\t\t\t\tPrecio\n\n");//imprimimos los productos en pantalla según los códigos
 val=atof(compras[i].n_prod);//atof es una función que transforma una cadena de caracteres en un float
 //printf("%f\n",val);//esta línea solo me sirve para comprobar que se ha hecho la asignación
 for(n=0;n<val;n++)//imprimo todos los productos de la misma compra ya que tengo la informacion de cuantos productos tiene cada compra. n_prod es una cadena de caracteres
 {  
	do 
	{   
	    g++;//avanzamos al siguiente producto y lo imprimimos
	    m=strcmp(productos[g].codigo,CODIGOS[i].CODIGOCOMPRA);
	
	}while(m!=0);

printf("%i.%s\t\t\t\t\t",k,productos[g].nombre); //como estoy imprimiendo cadenas de caracteres de distinto tamaño por eso no se imprime todo en una misma fila
printf("%i\t\t\t\t\t",unidades[i]);
printf("%f\n",productos[g].precio*unidades[i]);//solucion 1 de poner espacios no funciona. ahora probar solucion 2 de poner la infor en distintos printf este problema es solo porque en una linea
i++;//paso a la siguiente línea del fichero
k++;//te imprime el número del producto 1. 2. 3. 4.
}
}
else
i++;//si está línea no es la del usuario entonces paso a la siguiente
}while(i!=j);//imagina que tienes j=5 líneas entonces i recorrería las posiciones 0 1 2 3 4 (5 posiciones del vector, que se corresponden con 5 líneas), y cuando i=5 la expresión es falsa y 
//el bucle ya no se ejecuta, con lo cual, he conseguido recorrer las 5 líneas
}

void historial_fechas(char nick_usuario[],int dim)
{
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
    printf("\tProductos\t\t\t\t\tUnidades\t\t\t\t\tPrecio\n\n");//imprimimos los productos en pantalla según los códigos
    val=atof(compras[i].n_prod);//atof es una función que transforma una cadena de caracteres en un float
    //printf("%f\n",val);//esta línea solo me sirve para comprobar que se ha hecho la asignación
    for(n=0;n<val;n++)//imprimo todos los productos de la misma compra ya que tengo la informacion de cuantos productos tiene cada compra. n_prod es una cadena de caracteres
    {  
	  do 
	  {   
	    g++;//avanzamos al siguiente producto y lo imprimimos
	    m=strcmp(productos[g].codigo,CODIGOS[i].CODIGOCOMPRA);
	  }while(m!=0);

    printf("%i.%s\t\t\t\t\t",k,productos[g].nombre); //como estoy imprimiendo cadenas de caracteres de distinto tamaño por eso no se imprime todo en una misma fila
    printf("%i\t\t\t\t\t",unidades[i]);
    printf("%f\n",productos[g].precio*unidades[i]);//solucion 1 de poner espacios no funciona. ahora probar solucion 2 de poner la infor en distintos printf este problema es solo porque en una linea
    i++;//paso a la siguiente línea del fichero
    k++;//te imprime el número del producto 1. 2. 3. 4.
    }
    t++;//bandera que me indica si se realizaron o no compras en la fecha introducida
    }
    else
    i++;//si las fechas no coinciden paso a la línea siguiente del fichero
}
   else
   i++;//si las fechas no coinciden entonces paso a la siguiente línea siguiente del fichero
}while(i!=j);//El bucle se ejecuta hasta leer todo el fichero

if(t==0)//Si después de leer todo el fichero, no se encontro ninguna compra realizada en la fecha indicada, se imprime este mensaje
printf("No se realizaron compras el %s\n",FECHA);

}
