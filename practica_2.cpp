#include <stdio.h>

int main(){

int lado=0; /* longitud del lado mas externo del rombo */

/*===================================================================================
                                INPUT DEL LADO DEL ROMBO
====================================================================================*/
printf("Lado del rombo?\n");
scanf("%d", &lado);
printf("\n");

/*===================================================================================
                                IMPRESION DEL ROMBO EN PANTALLA
====================================================================================*/

/* Si el lado = 1 solo se imprime @ */
if(lado==1){
  printf("@\n");
}

/* Si el lado > 1 se imprime el resto de caracteres */
if(lado>1){


/* imprime parte superior del triangulo*/
for(int i=1; i<=lado; i++){ /* inicia el bucle que contiene el triangulo superior del rombo */

  for(int j=1; j<=(lado-i); j++){ /* Imprime los espacios de la mitad superior izquierda del rombo*/
    printf(" ");
    }

  for(int k=1; k<=i; k++){ /* imprime los caracteres de la mitad superior izquierda del rombo */

    if((k%4)==1){          /* Si el modulo de 4 es 1 imprime '@' */
      printf("@");
    }else if((k%4)==2){    /* Si el modulo de 4 es 2 imprime '.' */
      printf(".");
    }else if((k%4)==3){    /* Si el modulo de 4 es 3 imprime 'o' */
      printf("o");
    }else if((k%4)==0){    /* Si el modulo de 4 es 0 imprime '.' */
      printf(".");
    }
  }

  for(int w=i-1; w>=1; w--){ /* Imprime los caracteres de la mitad superior derecha del rombo */

    if((w%4)==2){            /* Si el modulo de 4 es 2 imprime '.' */
      printf(".");
    }else if((w%4)==3){      /* Si el modulo de 4 es 3 imprime 'o' */
      printf("o");
    }else if((w%4)==0){      /* Si el modulo de 4 es 0 imprime '.' */
      printf(".");
    }else if((w%4)==1){      /* Si el modulo de 4 es 1 imprime '@' */
      printf("@");
    }
  }
  printf("\n");              /* Introduce un salto de linea cada vez que se completa una ciclo de 'i' */
  }

/* Imprime el triangulo inferior del rombo */
for(int i=1; i<=lado-1; i++){ /* Inicia el bucle que contiene la mitad inferior del rombo */

    for(int j=1; j<=i; j++){  /* Imprime los espacios de la mitad inferior izquierda del rombo */
        printf(" ");
      }

    for(int k=1; k<=lado-i; k++){ /* Imprime los caracteres de la mitad iferior izquierda del rombo */

      if((k%4)==1){               /* Si el modulo de 4 es 1 imprime '@' */
        printf("@");
      }else if((k%4)==2){           /* Si el modulo de 4 es 2 imprime '.' */
        printf(".");
      }else if((k%4)==3){           /* Si el modulo de 4 es 3 imprime 'o' */
        printf("o");
      }else if((k%4)==0){           /* Si el modulo de 4 es 0 imprime '.' */
        printf(".");
      }
    }

    for(int w=lado-i-1; w>=1; w--){ /* Imprime los caracteres de la mitad inferior derecha */

      if((w%4)==2){                 /* Si el modulo de 4 es 2 imprime '.' */
        printf(".");
      }else if((w%4)==3){           /* Si el modulo de 4 es 3 imprime 'o' */
        printf("o");
      }else if((w%4)==0){           /* Si el modulo de 4 es 0 imprime '.' */
        printf(".");
      }else if((w%4)==1){           /* Si el modulo de 4 es 1 imprime '@' */
        printf("@");
      }
    }
  printf("\n");                     /* Introduce un salto de linea cada vez que se completa una ciclo de 'i' */
  }                                 /* Aqui acaba el ciclo del triangulo inferior del rombo */
}                                   /* Y aqui se cierra la llave del condicional if(lado>1) de la linea 32 */

}
