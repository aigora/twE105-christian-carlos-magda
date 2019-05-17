# include <stdio.h>
#include <time.h>//Hay que incluir esta libreria para poder utilizar el sincronizador
int main()
{
	FILE *pff;
	//Abrimos un fichero, en modo lectura en el que se almacenaran los datos de los usuarios
	pff=fopen("horitas.txt","a");
	//Sincronizador:
time_t t = time(NULL);
struct tm tm = *localtime(&t);

fprintf(pff,"%d/%d/%d;", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
//fprintf(pff,"%d/%d/%d \n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
//Fin del trozo del sincronizador

fclose(pff);
return 0;
}
/*#include <string.h>
#include <stdio.h>

int main () {
   char str[80] = "This is - www.tutorialspoint.com - website";
   const char s[2] = "-";
   char *token;
   
   /* get the first token */
   //token = strtok(str, s);
   
   /* walk through other tokens */
 /*  while( token != NULL ) {
      printf( " %s\n", token );
    
      token = strtok(NULL, s);
   }
   
   return(0);
}*/
