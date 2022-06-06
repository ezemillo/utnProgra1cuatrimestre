#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cargarArreglosParalelos(int dim, int legajos[dim], char nombres[dim][30],int anios[dim]);
void mostrarArregloParalelos(int validos,int legajos[validos], char nombres[validos][30],int anios[validos]);
int posicionEnLegajos(int valor, int validos, int legajos[]);
void mostrarNombreDesdeLegajo(int legajo,int validos,int legajos[validos], char nombres[validos][30],int anios[validos]);
void ordenarArregloSeleccionChar(int validos,char A[][30]);
int buscarPosMenorEnArregloChar(int validos, char A[][30], int pasada);
void ordenarArreglosPorNombre(int validos,int legajos[validos], char nombres[validos][30],int anios[validos]);



int main()
{
    int posicion;
    int legajos[20];

    int anios[20];
    int validos, legajo;
    char nombres[20][30];

    ///cargar arreglos
    /*
        validos = cargarArreglosParalelos(10, legajos, nombres,anios);
        mostrarArregloParalelos(validos,legajos, nombres,anios);
        */
    /// buscar legajo
    /*  validos = cargarArreglosParalelos(10, legajos, nombres,anios);
      mostrarArregloParalelos(validos,legajos, nombres,anios);

      puts("de que legajo quiere saber la posicion?");
      scanf("%d",&legajo);

      posicion=posicionEnLegajos(legajo, validos, legajos);
      printf("\nla posicion del legajo %d, es: %d",legajo,posicion);

    ///imprimir nombre de un legajo
    validos = cargarArreglosParalelos(10, legajos, nombres,anios);
    mostrarArregloParalelos(validos,legajos, nombres,anios);

    puts("de que legajo quiere saber el nombre?");
    scanf("%d",&legajo);

    mostrarNombreDesdeLegajo(legajo,validos, legajos,nombres,anios);

/// ordenar arreglos por nombre
    validos = cargarArreglosParalelos(10, legajos, nombres,anios);
    mostrarArregloParalelos(validos,legajos, nombres,anios);
    ordenarArreglosPorNombre(validos,legajos,nombres,anios);
    mostrarArregloParalelos(validos,legajos, nombres,anios);
*/
/// mostrar alumnos en una linea
    validos = cargarArreglosParalelos(10, legajos, nombres,anios);
    mostrarArreglosEnUnaLinea(validos,legajos,nombres,anios);

    return 0;
}

///1.	Crear una función que los cargue, hasta que el usuario lo decida.

int cargarArreglosParalelos(int dim, int legajos[dim], char nombres[dim][30],int anios[dim])
{
    char control='s';
    int i=0;

    while(i<dim && control=='s')
    {
        printf("\ningrese el numero de legajo:\n");
        scanf("%d", &legajos[i]);
        printf("\ningrese el nombre:\n");
        fflush(stdin);
        scanf("%s", &nombres[i]);
        printf("\ningrese los años:\n");
        scanf("%d", &anios[i]);
        printf("\ndesea cargar otro alumno? s para seguir:\n");
        fflush(stdin);
        scanf("%c", &control);
        i++;


    }
    return i;
}

void mostrarArregloParalelos(int validos,int legajos[validos], char nombres[validos][30],int anios[validos])
{
    for(int i=0; i<validos; i++)
    {

        printf("\nlegajo:%d\n", legajos[i]);
        printf("nombre:%s\n", nombres[i]);
        printf("edad:%d\n", anios[i]);

    }



}
///2.	Crear una función que busque dentro del arreglo de legajos y retorne la posición de un determinado valor.

int posicionEnLegajos(int valor, int validos, int legajos[])
{
    int posLeg=-1;
    int i=0;
    while(i<validos && posLeg<0)
    {
        if(valor==legajos[i])
        {
            posLeg=i;
        }
        i++;
    }
    return posLeg;
}

void mostrarNombreDesdeLegajo(int legajo,int validos,int legajos[validos], char nombres[validos][30],int anios[validos])
{
    int posicion;
    posicion=posicionEnLegajos(legajo, validos, legajos);
    printf("\nel nombre del legajo %d, es: %s",legajo,nombres[posicion]);

}
///4.	Hacer una función que reciba como parámetro todos los arreglos y los ordene por nombre. (por el método de selección o inserción).

void ordenarArreglosPorNombre(int validos,int legajos[validos], char nombres[validos][30],int anios[validos])
{
    char aux[30];
    int i =0;
    int posMin=0;
    int legaAux=0;
    int aniosAux=0;

    for(i=0; i<validos-1; i++)
    {
        strcpy(aux, nombres[i]);
        legaAux=legajos[i];
        aniosAux=anios[i];
        posMin = buscarPosMenorEnArregloChar(validos, nombres, i);
        strcpy(nombres[i], nombres[posMin]);
        legajos[i]=legajos[posMin];
        anios[i]=anios[posMin];

        strcpy(nombres[posMin], aux);
        legajos[posMin]=legaAux;
        anios[posMin]=aniosAux;
    }
}

int buscarPosMenorEnArregloChar(int validos, char A[][30], int pasada)
{
    int posCharMin=pasada;
    int j=0;
    for (j=pasada+1 ; j<validos; j++)
    {

        if(strcmpi(A[j], A[posCharMin])<0)
        {
            posCharMin=j;

        }
    }

    return posCharMin;
}

///5.	Mostrar por pantalla los 3 arreglos pero de a un “registro” o alumno por vez (es decir: muestra el legajo, nombre y años del 1er alumno, luego el legajo, nombre y años del 2do alumno, y así sucesivamente)..

void mostrarArreglosEnUnaLinea(int validos,int legajos[validos], char nombres[validos][30],int anios[validos])
{
    int i=0;
    for(i=0; i<validos; i++)
    {
        printf("el alumbro con nombre: %s, tiene el legajo: %d, y tiene %d años\n", nombres[i],legajos[i], anios[i]);

    }

}


