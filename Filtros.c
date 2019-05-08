#include<stdio.h>

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

void filtro_precio();

void main (){
	char filtro;
	int aux;
	printf("Para aplicar un filtro, pulse:\n\n\tn:Sin filtro\tc:Por categorias\tp:Por precio\to:Solo ofertas\n");
	do{
	scanf(" %c",&filtro);
	switch(filtro){
		case'n':
		//cat_comp() (Función mostrar catálogo completo)
		aux=1;
		break;
		case'c':
		aux=1;
		break;
		case'p':
		filtro_precio();
		aux=1;
		break;
		case'o':
		
		aux=1;
		break;
		default:
		printf("Esa no es una opción válida, por favor seleccione una de las opciones indicadas previamente\n");
		aux=0;
		break;
	}
	}
	while(aux==0);
}

void filtro_precio(){//Función que filtra el catálogo de manera que solo muestre los objetos que pertenezcan a un intervalo de precios a elegir por el usuario.
	float a, b;//Límites de precios a filtrar
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
  			&productos[i].unidades);//leemos los precios, y el número de unidades
  			
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
           		
       		 	flag=1;
       		 	
			}	
			
		}
	
	if(flag==0) printf("No hay ningún objeto en ese rango de precio, por favor intentelo de nuevo.\n\n");
	//en caso de que ningun objeto cumpla el intervalo de precio determinado, se solicita un nuevo intervalo
	
	}
	while(flag==0);
	
	comprando();//función compra
}
