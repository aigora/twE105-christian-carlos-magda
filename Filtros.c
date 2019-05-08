#include<stdio.h>

void filtro_categoria();
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
		filtro_categoria();
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

void filtro_categoria(){
	char cat;
	int aux;
	printf("Para seleccionar la categoria, pulse:\n\n\tc:Condensadores\tb:Baterias\tt:Conmutadores\tr:Resistencias\n");
	do{
	scanf(" %c",&cat);
	switch(cat){
		case'r':
		
		aux=1;
		break;
		case'c':
		
		aux=1;
		break;
		case'b':
		
		aux=1;
		break;
		case't':
		
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

void filtro_precio(){
	int a, b;
	printf("Indique los dos extremos del intervalo de precio\n");
	scanf(" %i %i", &a, &b);
}
