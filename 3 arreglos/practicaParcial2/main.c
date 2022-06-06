#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>

void cargarPilaManual (Pila *p, int cantidadDatos);
void cargarPilaRandom (Pila *p, int cantidadDatos);
int filtrarLuvias (Pila p, Pila * lluviaHasta60, int A[]);
void mostrarArregloInt(int A[], int validos);


int main()
{
    Pila lluvias;
    inicpila(&lluvias);
    Pila lluviaH60;
    inicpila(&lluviaH60);
    int lluviaMas60[40];
    srand(time(NULL));
    int cantDatos;
    int validos;

    ///cargar pila radom preguntanto cant de datos
    puts("cuantos datos desea cargar?");
    scanf("%d", &cantDatos);
    //cargarPilaManual(&lluvias, cantDatos);
    cargarPilaRandom (&lluvias, cantDatos);

    mostrar(&lluvias);

    validos = filtrarLuvias(lluvias, &lluviaH60, lluviaMas60);

    puts("lluvias \n");
        mostrar(&lluvias);

            puts("lluvias hasta 60 \n");
            mostrar(&lluviaH60);
            puts("arreglo mas de 60\n");
            mostrarArregloInt(lluviaMas60, validos);





    return 0;
}

///cargar pila lluvias



//1. Efectuar la carga de los valores correspondientes a un mes de precipitaciones en
//una pila de datos enteros. La cantidad de días del mes se recibirá por parámetro.

void cargarPilaManual (Pila *p, int cantidadDatos)
{
    char control;
    int dato;
    int cant=0;


    do
    {
        puts("ingrese el valor a cargar");
        scanf("%d", &dato);
        if(dato>0 && dato <180)
        {
            apilar(p, dato);
            cant++;
        }
        else
        {
            puts("dato fuera de rango, intente nuevamente con otro dato");
        }

        puts("desea cargar otro valor? n para salir");
        fflush(stdin);
        scanf("%c", &control);

    }
    while(control != 'n' && cant<cantidadDatos);

}

void cargarPilaRandom (Pila *p, int cantidadDatos)
{
    int i=0;
    for(i=0; i<cantidadDatos; i++)
    {
        apilar(p, rand()%181-1);
    }


}

//A partir de la pila cargada con el inciso anterior, analizar la información y separar en
//un arreglo y otra pila, las precipitaciones según el siguiente criterio:
//i. En la pila A, se pasarán las precipitaciones entre 0 y 60 mm.
//ii. En el arreglo B, se pasarán las precipitaciones entre 61 y 180 mm.
int filtrarLuvias(Pila p, Pila * lluviaHasta60, int A[])
{
    int i=0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&p))
    {
        if(tope(&p)>60 && tope(&p)<181)
        {
            A[i]=tope(&p);
            apilar(&aux, desapilar(&p));
            i++;
        }
        else
        {
            if(tope(&p)>-1 && tope(&p)<61)
            {
                apilar(lluviaHasta60, desapilar(&p));
            }
        }

    }
    return i;
}

void mostrarArregloInt(int A[], int validos){
    int i =0;
for(i=0; i<validos; i++){
    printf("{%d}", A[i]);
    }
}


