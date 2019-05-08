//MENÚ DE INICIO de e-shop
//ESTE ES EL PROGRAMA DEFINITIVO DE TU GRUPO, SIMPLEMENTE TIENES QUE AGREGARLE EL PROTOTIPO Y LA DEFINICI�N DE LA FUNCI�N REGISTRO Y YA

#include <stdio.h>
#include <stdlib.h> /* system */
#include <string.h> /*strcmp*/
#define N 4 //N n�mero de productos en venta
#define M 2 //M n�mero de tipo de productos

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

void catalogo_completo(producto productos[],int dimension,clasificacion clasificaciones[],int dimension1);//prototipo de la funci�n
void categorias(producto productos[], int dimension,clasificacion clasificaciones[],int dimension1);
void evalua(producto productos[],int dimension,clasificacion clasificaciones[],int dimension1,int j);//funci�n que compara si la elecci�n concide con el tipo y manda imprimir productos del mismo tipo
void ofertas(producto productos[],int dimension);
void comprando(void);
void filtro_precio();//funci�n qeu filtra en base a un intervalo de precio dado por el usuario
//funci�n de registro.
//void registro();

void main()
{
	//Caracter de opciones del menú 
	char option_menu;
	//Caracter de opciones del catálogo
	char option_cat;
    int m0=0,m=0,m1=0,i;
    int n=0,j;//variables locales. n1 n�mero de tipos
    producto productos[N];//vector de estructuras//Perpi�an:la dimension del vector tiene que coincidir con el n�mero de productos en tu lista
    clasificacion clasificaciones[M];//vector de estructuras
    FILE *pf,*pf1,*pf2,*pf3;//puntero que se�ala a fichero 
    pf = fopen("lista_de_productos.txt", "r");//Abrimos el fichero
    pf1 =fopen("lista_de_productos_1.txt","r");
    pf2 = fopen("lista_de_tipos.txt", "r");//Abrimos el fichero que contiene letras que se corresponden al tipo de producto, los nombres de los tipos de producto 
//y eln�mero de productos del mismo tipo//ojo a-->r
    //pf3 = fopen("lista_de_tipos_1.txt", "r");
for(i=0;i<N;i++)
{
m0=fscanf(pf,"%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n",
  productos[i].tipo,
  productos[i].nombre,
  productos[i].Especificaciones[0].Descripcion,
  productos[i].Especificaciones[1].Descripcion,
  productos[i].Especificaciones[2].Descripcion,
  productos[i].Especificaciones[3].Descripcion,
  productos[i].estado,
  productos[i].codigo);//Leemos todos los productos
m1=fscanf(pf1,"%f;%i\n",
  &productos[i].precio,
  &productos[i].unidades);
}//y los guardamos la informaci�n en un vector de estructuras
for(j=0;j<M;j++)
{//Leemos la informaci�n y la guardamos en un vector de estructuras
n=fscanf(pf2,"%[^;];%[^;];%i\n",clasificaciones[j].letra,clasificaciones[j].TIPO,&clasificaciones[j].NTIPO);
}
fclose(pf); // Cerramos fichero
fclose(pf2); // Cerramos fichero
	
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
								catalogo_completo(productos,N,clasificaciones,M);
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
								filtro_precio();
								system("pause");
								break;
							}
							case 'o':
							{
								//OFERTAS
								system("cls");
								ofertas(productos,N);
								printf("\n\tOFERTAS\n");
								system("pause");
								break;
							}
							case 'k':
							{
								//CATEGORÍAS
								system("cls");
								categorias(productos,N,clasificaciones,M);//funci�n que te muestra las categor�as
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
					//registro();
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



void catalogo_completo(producto productos[], int dimension,clasificacion clasificaciones[],int dimension1)
{
	int i,m,k,a,j;
	printf("\n\tCAT%cLOGO\n",181);
	//for (j=0;j<M;j++)
    //{
	//printf("%s", clasificaciones[j].TIPO);
	//for(i=0;i<clasificaciones[j].NTIPO;i++)
	for(i=0;i<N;i++)
	{
	/*m=0;
	for(k=0;k<4;k++)
        {
           if(*productos[i].Especificaciones[k].Descripcion==0)//Doble igual de pregunta, no de asignaci�n//productos[0].Especificaciones[3].todo esto es Descripcion es un pruntero y aunque ponga *()no me da el valor
           m++;
        }
    //Doble igual de pregunta, no de asignaci�n//printf("%s\n\tEspecificaciones:%s\n\tCodigo:%s\n"    
    if(m==0)*/
	printf("%s\n\tEspecificaciones:\n\t\t%s\n\t\t%s\n\t\t%s\n\tCodigo: %s\n",
	       productos[i].nombre,
	       productos[i].Especificaciones[0].Descripcion,
	       productos[i].Especificaciones[1].Descripcion,
	       productos[i].Especificaciones[2].Descripcion,
	       productos[i].codigo);
	printf("\tPrecio: %f\n\tUnidades: %i\n\n",
           productos[i].precio,
           productos[i].unidades);
	 /*else
   {
   printf("%s %s %s %s\n",
	       productos[i].nombre,
	       productos[i].Especificaciones[0].Descripcion,
	       productos[i].Especificaciones[1].Descripcion,
	       productos[i].codigo);
   }
   }*/  
   }   
   comprando();
}

void categorias(producto productos[], int dimension,clasificacion clasificaciones[],int dimension1)
{	
int p=0,i;//p es una bandera que nos sirve para saber si el usuario a introducido un caracter v�lido o no y de esta forma saber si se lo tenemos que volver a pedir 
char eleccion;//mejor ser�a cambiar eleccion una cadena de caracteres por si el usuario en vez introoducir una letra mal, introduce varias letra, numero y simbolo mal
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
	evalua(productos,N,clasificaciones,M,0);
    break;
    
case 'P':
case 'p':
    evalua(productos,N,clasificaciones,M,1);
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
	
void evalua(producto productos[], int dimension,clasificacion clasificaciones[],int dimension1,int j)//funci�n que te muestra las categor�as,int j);//funci�n que compara si la "eleccion" concide con el tipo y manda imprimir productos del mismo tipo
{
	
  int m=0;
  int p=0;
  printf("%s\n", clasificaciones[j].TIPO);//imprime el tipo de producto Ejemplo imprime la palabra Condensador almacenada en el vector de estructuras "clasificciones"
  for(p=0;p<N;p++)
  {
  m=strcmp(productos[p].tipo,clasificaciones[j].letra);//de la libreria string,compara. letra[j]=letra del producto//AquI debe de estar el error poeque antes el compilador me dijo que clasificaciones[j].NTIPO era un puntero
  //entonces lo que estar� haciendo aqu�es comparar punteros
  printf("%i\n",m);//nunca me imprime ningun producto porque estoy comparando dos punteros que siempre son distindos
  //printf("%c %c",m1,m2);
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
    comprando();

  //for(i=0;i<clasificaciones[j].NTIPO;i++)
  /*for(i=0;i<N;i++)
  {
  char m1=clasificaciones[j].letra[0];//Si utilizas esta linea de codigo te dar� error porque dira que estay dando la direccion de memoria de un puntero a un caracter mm
  char m2=productos[i].tipo[0];
  m=strcmp(m1,m2);//de la libreria string,compara. letra[j]=letra del producto//AquI debe de estar el error poeque antes el compilador me dijo que clasificaciones[j].NTIPO era un puntero
  //entonces lo que estar� haciendo aqu�es comparar punteros
  printf("%i\n",m);//nunca me imprime ningun producto porque estoy comparando dos punteros que siempre son distindos
  printf("%c %c",m1,m2);
  if (m==0)//si son iguales imprimo toda la informaci�n del producto//doble igual de pregunta, no de asignaci�n
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
void ofertas(producto productos[],int dimension)
{
char letra1[10]="oferta";
int p,m=0;//N sigue siendo el n�mero de productos. i contador
for(p=0;p<N;p++)
  {
  	//printf("%s",productos[0].estado);
  	m=strcmp(productos[p].estado,letra1);
  	printf("%i\n",m);
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
  comprando();
}

//SOLO FALTA AGREGAR LA PARTE DE COMPRANDO. RECUERDA QUE ESA PARTE SE TIENE QUE MOSTRAR SOLO SI EL USUARIO A INICIADO SESI�N
//FALTA AGREGAR LA PARTE DE CARRITO. TIENES QUE DESARROLLAR ESA PARTE POR SEPARADO Y LUEGO AGRAGARLA  A ESTE C�DIGO FINAL
void comprando(void)
{
char eleccion;
char seguir;
//cadena de caracteres que guarda la eleccion del usuario de a�adiro productos a su carrito definimos una cadena de caracteres por 
//si el usuario en vez introoducir una letra mal, introduce varias letras, numero y simbolo, y as� evitamos que todo el programa deje de funcionar
CODE CODIGOS[20];//vector de estructuras que guarda los c�digos de los productos que el usuario desea a�adir a su carrito
int unidades[20];//vector que guarda las de los productos que el usuario desea a�adir a su carrito
int i=0,b=0,g=0;//b=bandera para saber si segimos o no ejecutando el bucle do while
 do{
printf("Indroduzca la letra (A) si desea anadir algo a su carrito\n");
scanf(" %c",&eleccion);
switch (eleccion)
   {
	case 'A':
	case 'a':
	{	//do{
			printf("Codigo:");                                                                        
		    scanf("%s",CODIGOS[i].CODIGOCOMPRA);//no poner & porque es cadena de caracteres pg 54 teor�a tema 4
			printf("\nUnidades:");
			scanf("%i",&unidades[i]);
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
				printf("Codigo:\n");                                                                        
		        scanf("%s",CODIGOS[i].CODIGOCOMPRA);
			    printf("Unidades:");
			    scanf("%i",&unidades[i]);
			    i++;
		        break;
		    }
		    case 'C':
			case 'c'://en esta opci�n damos la orden de pasar la informaci�n al carrito FALTA DESARROLLAR ESTA PARTE MA�ANA CONTINUO
			{
				b=1;//bandera cambia Y se deja de ejecutar el bucle
				//mostrarcarrito(CODIGOS,20,unidades,20,i);//i es el n�mero de productos que se a�ade a la lista
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
    
void filtro_precio(){//Funci�n que filtra el cat�logo de manera que solo muestre los objetos que pertenezcan a un intervalo de precios a elegir por el usuario.
	float a, b;//L�mites de precios a filtrar
	int n, h;//auxiliar para lectura de ficheros
	int i, flag=0;//auxiliares
	producto productos[N];
	
	printf("Precios\n");
	
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
	
	do
	{
		
		printf("Indique los dos extremos del intervalo de precio\n\n");
		scanf(" %f %f", &a, &b);
		
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
           		
       		 	flag=1;
       		 	
			}	
			
		}
	
	if(flag==0) printf("No hay ning�n objeto en ese rango de precio, por favor intentelo de nuevo.\n\n");
	//en caso de que ningun objeto cumpla el intervalo de precio determinado, se solicita un nuevo intervalo
	
	}
	while(flag==0);
	
	comprando();//funci�n compra
}
			

