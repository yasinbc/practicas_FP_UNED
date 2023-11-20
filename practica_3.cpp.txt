#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//Tipo enumerado de los meses del año
typedef enum TipoMeses{
    Enero, Febrero, Marzo, Abril,
    Mayo, Junio, Julio, Agosto,
    Septiembre, Octubre, Noviembre, Diciembre
};

//Tipo enumerado de los dias de la semana
typedef enum TipoDiasSemana{
    Lunes, Martes, Miercoles,
    Jueves, Viernes,
    Sabado, Domingo
};

//Tipo estructurado que forma el registro de los componentes de un año
typedef struct Anno{
    TipoMeses mes;
    TipoDiasSemana semana;
    int anno;
};

//Tipo cadena para escribir los meses de un año
typedef char TipoNombreMeses[15];
//Tipo vector de cadena con espacio para los 12 meses del año
typedef TipoNombreMeses TipoMatrizMeses[12];
//Constante que contiene el nombre de los meses del año
const TipoMatrizMeses cabecerasCalendario = {
    "ENERO     ", "FEBRERO   ", "MARZO     ", "ABRIL     ", "MAYO      ", "JUNIO     ",
    "JULIO     ", "AGOSTO    ", "SEPTIEMBRE", "OCTUBRE   ", "NOVIEMBRE ", "DICIEMBRE "
};


/*===================================================================================
                  FUNCION QUE DETERMINA SI UN AÑO ES BISIESTO
====================================================================================*/
int esBisiesto(int anno) {
    return (anno % 4 == 0 && anno % 100 != 0) || (anno % 400 == 0);
}

// Función para determinar el día de la semana
/*===================================================================================
                  FUNCION PARA DETERMINAR EL DIA DE LA SEMANA
====================================================================================*/
int obtenerDiaSemana(int anno, int mes, int dia) {
    int h;

    if (mes < 3) {
        mes = mes + 12;
        anno = anno -1;
    }
    // Ajuste para que el 1 de enero de 1601 sea Lunes
    h = (dia + 2 * mes + 3 * (mes + 1) / 5 + anno + anno / 4 - anno / 100 + anno / 400 + 1) % 7;
    return h;
}

// Función para obtener la cantidad de días en un mes
/*===================================================================================
              FUNCION PARA DETERMINAR LA CANTIDAD DE DIAS EN UN MES
====================================================================================*/
int obtenerDiasEnMes(int anno, int mes) {
    if (mes == 2) {
        // Verificar si el año es bisiesto
        if ((anno % 4 == 0 && anno % 100 != 0) || (anno % 400 == 0)) {
            return 29; // Año bisiesto, febrero tiene 29 días
        } else {
            return 28; // Año no bisiesto, febrero tiene 28 días
        }
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return 30; // Abril, junio, septiembre, noviembre tienen 30 días
    } else {
        return 31; // Enero, marzo, mayo, julio, agosto, octubre, diciembre tienen 31 días
    }
}

int main() {
  int  diasDeLaSemana,
  diasDelMes, diasDelMesAnterior,
  diaActual, diasDelSiguienteMes, contador, indiceDiaSemana;
  Anno registroAnno;
  bool imprimirUltimaLinea;

  // Variable para controlar si se imprimirá la última línea de puntos
  imprimirUltimaLinea = false;

  contador = 0 ;
  indiceDiaSemana=0;

  printf("¿Mes (1..12)? ");
  scanf("%d", &registroAnno.mes);

  printf("\n¿Anno (1601..3000)? ");
  scanf("%d", &registroAnno.anno);

  if( (registroAnno.anno >= 1601 && registroAnno.anno <= 3000)
      &&
      (registroAnno.mes >= 1 && registroAnno.mes <= 12) ) {
  printf("\n%s             %2d\n", cabecerasCalendario[registroAnno.mes-1] , registroAnno.anno);
  printf("===========================\n");
  printf("LU  MA  MI  JU  VI | SA  DO\n");
  printf("===========================\n");

  // Obtener el día de la semana en el que comienza el mes
  diasDeLaSemana = obtenerDiaSemana(registroAnno.anno, registroAnno.mes, 1);

  // Obtener la cantidad de días en el mes
  diasDelMes = obtenerDiasEnMes(registroAnno.anno, registroAnno.mes);

  // Calcular la cantidad de días del mes anterior que se solapan
  if (diasDeLaSemana == 0) {
    diasDelMesAnterior = 6;
  } else {
    diasDelMesAnterior = diasDeLaSemana - 1;
  }

  // Variable para rastrear el día actual
  diaActual = 1;


  // Imprimir los días del mes
  for (int i = 0; i < 6 && !imprimirUltimaLinea; i++) { // incluye el numero de lineas
    for (int j = 0; j < 7; j++) {
      // Calcular la cantidad de días del siguiente mes que se solapan
          diasDelSiguienteMes = 7 - j;
          indiceDiaSemana = 7 - j;
      // Imprimir "|" entre VI y SA
      if (j == 5) {
        printf("| ");
      }

      // Imprimir los números del día o un punto si está fuera del rango del mes
      if ((i == 0 && j < diasDelMesAnterior) || diaActual > diasDelMes) {
        if( indiceDiaSemana == 3/*j==4*/){
          printf(" . ");
        }else if(diasDelSiguienteMes ){
          printf(" .  ");
          contador = contador + 1;
        }
      } else {
        if (diaActual <= diasDelMes) {
          // Marcar que se imprimirá la última línea si estamos en el último día del mes
          imprimirUltimaLinea = (diaActual == diasDelMes);
          if (j == 4) {
            printf("%2d ", diaActual);
          }else{
            printf("%2d  ", diaActual);
          }
          diaActual = diaActual+1;
        } else {


          // Calcular la cantidad de días del siguiente mes que se solapan
          diasDelSiguienteMes = 7 - j;
          printf(" . ");
        }
      }
    }//fin for j12

    // Saltar a la siguiente línea después de cada sábado
    printf("\n");

  }//fin for i
    printf("\n");
  } else {
    //Si no se introduce mes y año bien, salta este mensaje
    printf("\nIntroduzca meses comprendidos del 1 al 12 y anno comprendido del 1601 al 3000.\n");
  }//fin condicion 1601 <= anno <= 3000
    return 0;
}
