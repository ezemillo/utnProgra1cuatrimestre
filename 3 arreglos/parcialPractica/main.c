#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>

void mostrarArreglo(int A[], int validos);
int cargarArreglo(int A[],int dimension);
void cargarPilaUsuario(Pila *p);
int cargarArregloHastaVeinte(int A[]);
int posicionEnArreglo(int A[],int validos);
int pasarParesDePilaAArray(Pila *p, int A[],int validos);
void quitarElementoDePila(Pila *p, int elemento);


int main()
{
    srand(time(NULL));
    int unArregloInt[50];
    int validos=0;
    int posicionDelMenor;
    int unInt;
    Pila unaPila;
    inicpila(&unaPila);

    ///1
//    validos = cargarArreglo(unArregloInt, 30);
//    puts("este es el arreglo unArreglo");
//    mostrarArreglo(unArregloInt, validos);
///2
//   cargarPilaUsuario(&unaPila);
//   mostrar(&unaPila);
    ///3

    // validos = cargarArregloHastaVeinte(unArregloInt);
    // puts("este es el arreglo unArreglo");
    // mostrarArreglo(unArregloInt, validos);

///4 buscar menor
//validos = cargarArreglo(unArregloInt, 30);
//posicionDelMenor = posicionEnArreglo(unArregloInt , validos);
//printf("la posicion del menor es: %d",posicionDelMenor);
//mostrarArreglo(unArregloInt, validos);

///pasar pares de pila a array

//    cargarPilaUsuario(&unaPila);
//    validos = pasarParesDePilaAArray(&unaPila, unArregloInt, validos);
//    printf(" los validos son:%d", validos);
//    mostrar(&unaPila);
//    mostrarArreglo(unArregloInt, validos);

///quitar elemento de pila
//cargarPilaUsuario(&unaPila);
//puts("que elemento int desea eliminar de la pila?");
//scanf("%d", &unInt);
//quitarElementoDePila(&unaPila, unInt);
//mostrar(&unaPila);




    return 0;
}



int cargarArreglo(int A[],int dimension)
{
    int i=0;
    for(i=0; i<dimension; i++)
    {
        A[i]= (rand()%100) -50;

    }
    return i;
}
///Hacer una función que recorra un arreglo y lo muestre por pantalla.

void mostrarArreglo(int A[], int validos)
{
    int i =0;
    for(i=0; i<validos; i++)
    {
        printf("{%d}", A[i]);
    }
}
///Hacer una función que cargue una pila con intervención del usuario, limitando la carga a 20 elementos como máximo. La función debe trabajar la pila como referencia.


void cargarPilaUsuario(Pila *p)
{
    int i =0;
    char control;

    do
    {
        puts("ingrese un valor para agregar a la pila");
        leer(p);
        i++;
        puts("desea cargar otro elemento? n para salir");
        fflush(stdin);
        scanf("%c", &control);

    }
    while(control != 'n' && i<20);

}


///Realizar una funcion que cargue un arreglo.El arreglo tiene 20
///elementos como maximo. La funcion debe retornar la cantidad de elementos cargados.
int cargarArregloHastaVeinte(int A[])
{
    int i=0;
    char control;

    do
    {
        puts("ingrese un valor para agregar al arreglo");
        scanf("%d", &A[i]);
        i++;
        puts("desea cargar otro elemento? n para salir");
        fflush(stdin);
        scanf("%c", &control);

    }
    while(i<20 && control != 'n');
    return i;
}

///Realizar una funcion que busque el menor elemento en un arreglo y
///devuelva su posicion en el arreglo.

int posicionEnArreglo(int A[],int validos)
{
    int menor= A[0];
    int posicionMenor=0;
    int i;
    for(i=1; i<validos; i++)
    {
        if(A[i]<menor)
        {
            posicionMenor = i;
        }
    }
    return posicionMenor;
}
///Realizar una funcion que pase todos los elementos pares de una pila a un arreglo. La funcion
///debe trabajar la pila como referencia. En la pila solo deben quedar los numeros impares.

int pasarParesDePilaAArray(Pila *p, int A[], int validos)
{
    Pila basura;
    inicpila(&basura);
    Pila aux;
    inicpila(&aux);
    int i=0;


    while(!pilavacia(p))
    {
        if(tope(p)%2 == 0)
        {
            A[i]= tope(p);
            i++;
            apilar(&basura, desapilar(p));
            validos++;
        }
        else
        {
            apilar(&aux, desapilar(p));
        }

    }

    while(!pilavacia(&aux))
    {
        apilar(p, desapilar(&aux));
    }
    return validos;
}
// Hacer una funcion que quite de una pila cargada de elementos, un valor ingresado por el
//usuario. La funcion debe trabajar la pila como referencia.

void quitarElementoDePila(Pila *p, int elemento)
{
    Pila aux;
    Pila basura;
    inicpila(&aux);
    inicpila(&basura);

    while(!pilavacia(p))
    {
        if(tope(p)!= elemento)
        {
            apilar(&aux, desapilar(p));
        }
        else
        {
            apilar(&basura, desapilar(p));
        }
    }
    while(!pilavacia(&aux))
    {
        apilar(p, desapilar(&aux));
    }

}






/*





15 Realizar una funcion que cargue una pila con numeros aleatorios. Para esto, crear una
funcion que devuelva un numero random de 0 a 10 y utilizarla dentro de la funcion anterior.
15 Realizar una funcion que cargue una matriz segun un numero ingresado por el usuario.
5 Realizar una funcion que reciba un nombre de usuario y devuelva 1 si el nombre es
utn@gmail , y 0 si el nombre es diferente. La funcion no debe distinguir entre mayusculas y
minusculas.
5 Realizar una funcion que saque de una pila todos los elementos que figuren en un arreglo.*/
