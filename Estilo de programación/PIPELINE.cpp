#include <stdio.h>
#include <conio.h>
 
char auxa(int posicion);       
void escribe (int posicion, char (* ptr)(int) ); 
 
int main() {                      
  char (* fptr) (int);            
  fptr = auxa;                     
  printf("La letra%2d es una: %c\n", 5, auxa(5));
  escribe (5, fptr);           
  return (0);
}
 
char auxa (int num) {              
  char * str = "Hola mundo";
  return str[num];                 
}
 
void escribe (int pos, char (* fpointer)(int) ) { // Función utiliza mas funciones 
  char ch ;
  printf ("Estoy recibiendo la letra: %c\n", auxa(pos));
  ch = (* fpointer)(6);
  printf ("Estoy inventando la letra: %c\n", ch); 
}