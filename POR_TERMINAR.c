//MEN√ö DE INICIO de e-shop
//ESTE ES EL PROGRAMA DEFINITIVO DE TU GRUPO, SIMPLEMENTE TIENES QUE AGREGARLE EL PROTOTIPO Y LA DEFINICI”N DE LA FUNCI”N REGISTRO Y YA


//
//
// ESCRIBIR LAS OFERTAS Y DECIDIR EN CUALES LAS PONEMOS
//
//

#include <stdio.h>
#include <stdlib.h> /* system */
#include <string.h> /*strcmp*/
#define N 4 //N n˙mero de productos en venta
#define M 2 //M n˙mero de tipo de productos

typedef struct
    {
	    char Descripcion[30];
    }descripcion;

	typedef struct
	{
		char tipo[20];//tipo de producto letra ejemplo C de Condensador
		char nombre[50];//nombre exacto del producto. el que se mostrar· en el carrito.
		descripcion Especificaciones[4];//cadena de caracteres que guardara la descripcion de los productos
		float precio;//resuelve el problema de filtrar producto por precios
		int unidades;//unidades disponibles
		char estado[10];//si est· en oferta (1) o no(0), es una bandera para saber si el producto esta en oferta o no. 
	    char codigo[10];//esta componente sirve para diferencia varios productos del mismo tipo y que de esta forma podamos acceder a sus nombres
	}producto;//estructura de toda la informacion que contiene cada producto. podemos poner como codigos numero letras, letras y n˙meros.
	
	typedef struct
    {
        char letra[5];
        char TIPO[20];
        int NTIPO;//n˙mero de productos del mismo tipo Ejemplo 5 tipo distintos de Condensador
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

void catalogo_completo();//prototipo de la funciÛn
void categorias();
void evalua(int j);//funciÛn que compara si la elecciÛn concide con el tipo y manda imprimir productos del mismo tipo
void ofertas(/*producto productos[],int dimension*/);
void comprando();
void filtro_precio();//funciÛn que filtra en base a un intervalo de precio dado por el usuario
void leer_catalogo(producto productos[],int dimension);//funcion que lee los ficheros y guarda los datos en un vector de estructuras
void leer_clase(clasificacion clasificaciones[],int dimension1);//funcion que lee los ficheros y guarda los datos en un vector de estructuras
void mostrar_carrito(CODE CODIGOS[],int dimension1,int unidades[],int dimension2,int i);
void opciones_carrito(CODE CODIGOS[],int dimension1,int unidades[],int dimension2,int i);
//funciÛn de registro.
//void registro();

void main()
{
	//Caracter de opciones del men√∫ 
	char option_menu;
	//Caracter de opciones del cat√°logo
	char option_cat;
    int m0=0,m=0,m1=0,i;
    int n=0,j;//variables locales. n1 n˙mero de tipos
    
    producto productos[N];//vector de estructuras//PerpiÒan:la dimension del vector tiene que coincidir con el n˙mero de productos en tu lista
    clasificacion clasificaciones[M];//vector de estructuras
    
    FILE *pf,*pf1,*pf2/*,*pf3*/;//puntero que seÒala a fichero 
    
    pf = fopen("lista_de_productos.txt", "r");//Abrimos el fichero
    pf1 =fopen("lista_de_productos_1.txt","r");
    pf2 = fopen("lista_de_tipos.txt", "r");//Abrimos el fichero que contiene letras que se corresponden al tipo de producto, los nombres de los tipos de producto 
//y eln˙mero de productos del mismo tipo//ojo a-->r
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
	
	//Men√∫ principal
	system ("color F0");//cambia el color del fondo(F) y del texto(0).
	do
	{
		system("cls");//limpia la pantalla
		//Pantalla de inicio
		printf("\n\te-shop\n");
    		printf("----------------------------------------------------------\n");
    		printf("\n BIENVENIDO\n\n");
 		printf("Seleccione una opci%cn para comenzar: \n\n \tAcceder al cat%clogo de productos (c)\n \tInicio de sesi%cn (i)\n \tRegistrarse (r)\n \tSalir (s)\n",162,160,162);
    
		//Recoge la opci√≥n del usuario introducida por teclado
    		scanf(" %c",&option_menu);
    
    		//Opciones elegibles por el usuario
    		switch(option_menu)
    		{
    			case 'c':
    				{
    					system("cls");
    					printf("\n\tCAT%cLOGO\n\n",181);
    					
    					//OPCIONES DEL CAT√ÅLOGO
    					
    					printf("Opciones del cat%clogo:\n -Mostrar cat%clogo completo(c)\n -Filtrar por precio(p)\n -Solo ofertas(o)\n -Mostrar categor%cas(k)\n", 160,160,161);
    			       
						scanf(" %c",&option_cat);
						switch(option_cat)
						{
							case 'c':
							{
								//CAT√ÅLOGO COMPLETO
								system("cls");
								catalogo_completo();
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
								ofertas();
								printf("\n\tOFERTAS\n");
								system("pause");
								break;
							}
							case 'k':
							{
								//CATEGOR√çAS
								system("cls");
								categorias();//funciÛn que te muestra las categorÌas
								system("pause");
								break;
							}
							default:
							{
								//CARACTER NO V√ÅLIDO
								system("cls");
								printf("Caracter introducido no v√°lido.");
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
					
					//FunciÛn para el registro de nuevos usuarios
					//registro();
					printf("\n");
					system("pause");
				}	
    			case 'i':
    				{
    					//INICIO DE SESI√ìN
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
					//CARACTER NO V√ÅLIDO
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



void catalogo_completo()
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
   comprando();
}

void categorias()
{	
int p=0,i;//p es una bandera que nos sirve para saber si el usuario a introducido un caracter v·lido o no y de esta forma saber si se lo tenemos que volver a pedir 
char eleccion;//mejor serÌa cambiar eleccion una cadena de caracteres por si el usuario en vez introoducir una letra mal, introduce varias letra, numero y simbolo mal

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
	evalua(0);
    break;
    
case 'P':
case 'p':
    evalua(1);
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
	
void evalua(int j)//funciÛn que te muestra las categorÌas,int j);//funciÛn que compara si la "eleccion" concide con el tipo y manda imprimir productos del mismo tipo
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
  //entonces lo que estarÌ haciendo aquÌes comparar punteros
  printf("%i\n",m);//nunca me imprime ningun producto porque estoy comparando dos punteros que siempre son distindos
  //printf("%c %c",m1,m2);
  if (m==0)//si son iguales imprimo toda la informaciÛn del producto//doble igual de pregunta, no de asignaciÛn
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
  char m1=clasificaciones[j].letra[0];//Si utilizas esta linea de codigo te dar· error porque dira que estay dando la direccion de memoria de un puntero a un caracter mm
  char m2=productos[i].tipo[0];
  m=strcmp(m1,m2);//de la libreria string,compara. letra[j]=letra del producto//AquI debe de estar el error poeque antes el compilador me dijo que clasificaciones[j].NTIPO era un puntero
  //entonces lo que estarÌ haciendo aquÌes comparar punteros
  printf("%i\n",m);//nunca me imprime ningun producto porque estoy comparando dos punteros que siempre son distindos
  printf("%c %c",m1,m2);
  if (m==0)//si son iguales imprimo toda la informaciÛn del producto//doble igual de pregunta, no de asignaciÛn
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
void ofertas(/*producto productos[],int dimension*/)//Las ofertas son fijas de cada objeto, no se actualizan cada vez que se abre el programa
{
	char letra1[10]="oferta";
	int p,m=0;//N sigue siendo el n˙mero de productos. i contador
	producto productos[N];

	leer_catalogo(productos,N);//Leemos los productos y guardamos los datos en un vectores de estructuras

	system("cls");

	for(p=0;p<N;p++)
	  {
	  	//printf("%s",productos[0].estado);
	  	m=strcmp(productos[p].estado,letra1);
	  	printf("%i\n",m);
	  if (m==0)//si son iguales imprimo toda la informaciÛn del producto//doble igual de pregunta, no de asignaciÛn
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

//SOLO FALTA AGREGAR LA PARTE DE COMPRANDO. RECUERDA QUE ESA PARTE SE TIENE QUE MOSTRAR SOLO SI EL USUARIO A INICIADO SESI”N
//FALTA AGREGAR LA PARTE DE CARRITO. TIENES QUE DESARROLLAR ESA PARTE POR SEPARADO Y LUEGO AGRAGARLA  A ESTE C”DIGO FINAL
void comprando()
{
	char eleccion;
	char seguir;
	//cadena de caracteres que guarda la eleccion del usuario de aÒadiro productos a su carrito definimos una cadena de caracteres por 
	//si el usuario en vez introoducir una letra mal, introduce varias letras, numero y simbolo, y asÌ evitamos que todo el programa deje de funcionar
	CODE CODIGOS[20];//vector de estructuras que guarda los cÛdigos de los productos que el usuario desea aÒadir a su carrito
	producto productos[N];
	int unidades[20];//vector que guarda las de los productos que el usuario desea aÒadir a su carrito
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
		    scanf("%s",CODIGOS[i].CODIGOCOMPRA);//no poner & porque es cadena de caracteres pg 54 teorÌa tema 4
			printf("\nUnidades:");
			scanf("%i",&unidades[i]);
			i++;
			do
			{
			printf("\nOpciones:\nSeguir Anadiendo productos(A)\nConfirmar su lista(C)\n");
			scanf(" %c",&seguir);//guardamos la elecciÛn en una cadena de caracteres por si el usuario introduce muchos dÌgitos erroneamernte
			//PONERLE UN ESPACIO A %c despuÈs de " SIEMPRE SOLO A %c no para los dem·s %i %f %s
		//}while(seguir==1)
		//el do while al comienzo del case A no es conveniente porque si el usuario introduce otro n˙mero a casualida. y quiere en realidad seguir aÒadiendo productos, no podrÌa hacerlo
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
			case 'c'://en esta opciÛn damos la orden de pasar la informaciÛn al carrito FALTA DESARROLLAR ESTA PARTE MA—ANA CONTINUO
			{
				b=1;//bandera cambia Y se deja de ejecutar el bucle
				mostrar_carrito(CODIGOS,20,unidades,20,i);//i es el n˙mero de productos que se aÒade a la lista
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
		    }while(b==0);//se jecuta mientra la bandera no cambia de valor. mientra la expresiÛn es verdadera
		     g=1;//ya hemos ababado exitosamente la opreacion de aÒadir productos a carrito
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

void mostrar_carrito(CODE CODIGOS[],int dimension1,int unidades[],int dimension2,int i)//i te da el n˙mero de productos que ha comprado el usuario
{
	int m0,m1,g;
	int m,j=0,k=0;
	producto productos[N];
	FILE *pf4;//puntero que seÒala a fichero 
    pf4 = fopen("lista_provisional.txt", "w");//en modo write para modificarlo tantas veces como el usuario lo desee
	leer_catalogo(productos,N);
if (i!=0)
{
printf("\tProductos\t\t\t\t\tUnidades\t\t\t\t\tPrecio\n\n");//imprimimos los productos en pantalla seg˙n los cÛdigos
do
{
    g=0;//volvemos a recorrer todos los productos para buscar el producto que tenga el cÛdigo del producto que me falta imprimir
	do 
	{   /*if(strcmp(CODIGOS[j].CODIGOCOMPRA,"no")==0)
	    j++;//Pasamos al siguiente cÛdigo Y øQue pasarÌa si el usuario introduce un cÛdigo no v·lido, el bucle no terminarÌa? Resolver ese problema*/ //SI YA HE HECHO EL TRASLADE DE LOS PRODUCTOS, ENTONCES YA NO NECESITO ESTAS DOS LÕNEAS PORQUE TENGO QUE IMPRIMIR TODA LA LISTA
	    m=strcmp(productos[g].codigo,CODIGOS[j].CODIGOCOMPRA);
	    g++;
	}while(m!=0);
//for(k=0;k<i ;k++)
printf("%i.%s\t\t\t\t\t",k+1,productos[g].nombre); //como estoy imprimiendo cadenas de caracteres de distinto tamaÒo por eso no se imprime todo en una misma fila
printf("%i\t\t\t\t\t",unidades[j]);
printf("%f\n",productos[g].precio*unidades[j]);//solucion 1 de poner espacios no funciona. ahora probar solucion 2 de poner la infor en distintos printf este problema es solo porque en una linea pones distiontos tipos de caracterres que quieres imprimir
fprintf(pf4, "%s;", CODIGOS[j].CODIGOCOMPRA);
fprintf(pf4, "%i\n", unidades[j]);
j++;//Pasamos al siguiente codigo porque solo hay un codigo parar cada producto
k++;//k es el contador del n˙mero de productos que se ha impreso y el bucle acaba cuando ya hemos imprimido los i productos
}while(k!=i);//El bucle tiene que acabar cuando el vector de unidades se ha recorrido totalmente, porque eso significa que ya hemos impreso toda la lista 
}
opciones_carrito(CODIGOS,20,unidades,20,i);
}
    
void opciones_carrito(CODE CODIGOS[],int dimension1,int unidades[],int dimension2,int i)
{
FILE *pf5;
pf5 = fopen("numero_tarjeta.txt", "a");//Abrimos el fichero para poder escribir en Èl
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
	    scanf("%i",&numprod);//n˙mero de producto
	    printf("Introduzca las unidades que desee\n");
	    scanf("%i",&unidades[numprod-1]);//NO NECESITAS PONER &???????????????PARA LLENA UNA COMPONENTE DE UN VECTOR DE ESTRUCTURA NO, PERO PARA UN VECTOR COMUN Y CORRIENTE
	    system("cls");//limpia la pantalla
	    mostrar_carrito(CODIGOS,20,unidades,20,i);//Damos la orden para que se imrpima la lista
	    break;
case 'Q':
case 'q':
        printf("Seleccione el producto 1. 2. 3. ...\n");
	    scanf("%i",&numprod);//n˙mero de producto
	    for(h=0;h<i-numprod;h++)
	    {
	    strcpy(CODIGOS[numprod-1+h].CODIGOCOMPRA,CODIGOS[numprod+h].CODIGOCOMPRA);//traslado el contenido para que si el usuario quisiera quitar de nuevo un producto de la lista, lo pueda hacer
	    //Hago lo mismo para el vector de unidades
	    //strcpy(unidades[numprod-1+h],unidades[numprod+h]);//pero strcpy solo copia cadena de caracteres, asÌ que para trasladar n˙meros tendr·s que pensar en otra cosa, porque si o si los n˙mero 
		//y los cÛdigo deben ser trasladados para que se correspondan
	    }
	    i--;//Ahora tengo un producto menos
	    //printf("%s",CODIGOS[numprod-1].CODIGOCOMPRA);//Si hace la asignaciÛn
	    //CODIGOS[numprod-1]=0;//Imagina que el usuario al hacer la compra introduce en una de las unidades de un producto un 0, eso significarÌa que no quiere ese producto, pero 
		//igual introdujo el cÛdigo y unidades a propÛsito. entonces, al hacer esta lÌnea de cÛdigo tambiÈn estamos cubriendo esa posibilidad
		//unidades[numprod-1]=0;//Esta lÌnea es innecesaria
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
	    }*/ //En realidad aquÌ solo debo limpiar la ventana y ya
	    system("cls");//limpia la pantalla
		printf("Carrito vacio\n");
	    break;
	    //Doy la orden de que se limpie la venta para que no aparesca ning˙n producto
case 'P':
case 'p':	
        printf("Numero de tarjeta:");
        scanf("%lli",&tarjeta);
        fprintf(pf5, "%lli;", tarjeta);//Escribimos en el fichero
        printf("\nPIN:");
        scanf("%li",&pin);
        fprintf(pf5, "%li\n", pin);//Escribimos el pin en la misma lÌnea separado por ;
        break;
/*case 'M':
case 'm':*/
default:
	    printf("Opcion no valida\n");
	    break;
}
fclose(pf5);//cerramos el fichero aquÌ porque que si el usuario no quisiese alterar su lista y no optar· por seleccionar alguna opciÛn y defrente cerrase el programa, el fichero no quedarÌa sin cerrar
}


    
void filtro_precio(){//FunciÛn que filtra el cat·logo de manera que solo muestre los objetos que pertenezcan a un intervalo de precios a elegir por el usuario.
	float a, b;//LÌmites de precios a filtrar
	int i, flag=0;//auxiliares
	producto productos[N];

	leer_catalogo(productos,N);//Leemos el catalogo y guardamos los datos en un vectores de estructuras

	printf("Precios\n");
	
	do
	{
		
		printf("Indique los dos extremos del intervalo de precio\n\n");
		scanf(" %f %f", &a, &b);
		
		
		
		for(i=0;i<N;i++)
		{
		
		if(productos[i].precio<=b && productos[i].precio>=a) //Comprueba si los precios de cada objeto est· dentro del intervalo elegido
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
	
	if(flag==0) printf("No hay ning˙n objeto en ese rango de precio, por favor intentelo de nuevo.\n\n");
	//en caso de que ningun objeto cumpla el intervalo de precio determinado, se solicita un nuevo intervalo
	
	}
	while(flag==0);
	
	comprando();//funciÛn compra
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
  			&productos[i].unidades);//leemos los precios, y el n˙mero de unidades
  				
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
		{//Leemos la informaciÛn y la guardamos en un vector de estructuras
		
		n=fscanf(tf,"%[^;];%[^;];%i\n",
			clasificaciones[i].letra,
			clasificaciones[i].TIPO,
			&clasificaciones[i].NTIPO);
		
  		}
  		
		fclose(tf); // Cerramos fichero	
}
