#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

int cargarUnArreglo(int A[], int dimension);  /// int * A
void mostrarUnArreglo(int A[], int validos);
int sumaValidosArreglo(int A[], int validos);
void cargarPilaDesdeArreglo (int A[], int validos,Pila * unapila);
int cargarUnArregloFloat(float A[], int dimension);
void mostrarUnArregloFloat(float A[], int validos);
float sumaValidosArregloFloat(float A[], int validos);
int encontrarCharEnArreglo (char A[], int validos, char buscado);
int cargarUnArregloChar (char A[], int dimension);
void mostrarUnArregloChar(char A[], int validos);
int cargarUnArregloCharOrdenado (char A[], int dimension);
int insertarCharEnAOrdenado (char A[],int validos, char aInsertar);
int encontrarMaximoChar(char A[],int validos );
int arregloCapicua(char A[], int validos);
void invertirArreglo(char A[], int validos);
int buscarPosMenorEnArreglo(char A[], int validos);
void ordenarArregloSeleccion(char A[],int validos);
void buscarMenorEnArreglo(char A[], int validos);
void ordenarArregloSeleccion2(char A[],int validos);








int main()
{
    srand(time(NULL));
    int  validos=0, otroValidos=0, suma =0;
    float sumaFloat=0;
    int unArreglo[20];
    int otroArreglo[10];
    float unArregloFloat[100];
    char unArregloChar[20];
    int controlSwitch;
    char salirSwitch;
    char buscarChar;
    char elementoChar;
    int charMaximo;
    int banderaChar;
    int controlCapicua;
    Pila unaPila;
    inicpila(&unaPila);



    do
    {
        printf("que ejercicio quiere correr?\n");
        printf("1.	Cargar un arreglo int.\n");
        printf("2.	Mostrar por pantalla un arreglo int\n");
        printf("3.	Sumar los elementos del array int.\n");
        printf("4.  Cargar Pila Desde Arreglo\n");
        printf("5.  Sumar los elementos de un array float\n");
        printf("6.	Realizar una función que indique si un elemento dado se encuentra\n en un arreglo de caracteres.\n");
        printf("7.	Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente, conservando el orden.\n");
        printf("8.	Realizar una función que obtenga el máximo carácter de un arreglo dado.\n");
        printf("9.	Realizar una función que determine si un arreglo es capicúa.\n");
        printf("10.	Realizar una función que invierta los elementos de un arreglo.\n");
        printf("11.	Ordenar un arreglo según a.	Selección  \n");


        fflush(stdin);
        scanf("%d", &controlSwitch);

        switch(controlSwitch)
        {



        case 1:
            validos=cargarUnArreglo(unArreglo, 20);

            break;
        case 2:
            validos=cargarUnArreglo(unArreglo, 20);
            mostrarUnArreglo(unArreglo, validos);

            break;

        case 3:
            validos=cargarUnArreglo(unArreglo, 20);
            suma = sumaValidosArreglo(unArreglo, validos);
            printf("\nla suma de los elementos del array son: %d \n",suma);
            mostrarUnArreglo(unArreglo, validos);
            break;

        case 4:
            validos=cargarUnArreglo(unArreglo, 20);
            cargarPilaDesdeArreglo(unArreglo, validos, &unaPila);
            mostrar(&unaPila);
            mostrarUnArreglo(unArreglo, validos);
            break;

        case 5:
            validos=cargarUnArregloFloat(unArregloFloat, 100);
            sumaFloat = sumaValidosArregloFloat(unArregloFloat, validos);
            printf("\nla suma de los elementos validos del array float es: %f \n", sumaFloat);
            mostrarUnArregloFloat(unArregloFloat, validos);

            break;
        case 6:


            validos=cargarUnArregloChar(unArregloChar, 20);
            puts("Ingrese el valor char que desea buscar\n");
            fflush(stdin);

            scanf("%c", &buscarChar);
            banderaChar = encontrarCharEnArreglo(unArregloChar, validos, buscarChar);
            if(banderaChar == (-1))
            {
                printf("El char no esta en el arreglo");
            }
            else
            {
                printf("el char esta por ultima vez en la posicion: %d", banderaChar);
            }


            mostrarUnArregloChar(unArregloChar, validos);

            break;

        case 7:


            validos = cargarUnArregloCharOrdenado(unArregloChar, 20);
            mostrarUnArregloChar(unArregloChar, validos);

            puts("Ingrese el valor char que desea insertar\n");
            fflush(stdin);

            scanf("%c", &elementoChar);


            validos= insertarCharEnAOrdenado(unArregloChar, validos, elementoChar);
            mostrarUnArregloChar(unArregloChar, validos);


            break;

        case 8:
            validos=cargarUnArregloChar(unArregloChar, 20);
            charMaximo = encontrarMaximoChar(unArregloChar, validos );
            mostrarUnArregloChar(unArregloChar, validos);
            printf("\nel maximo char de este arreglo es: %c\n",charMaximo);


            break;

        case 9:
            validos=cargarUnArregloChar(unArregloChar, 20);
            mostrarUnArregloChar(unArregloChar, validos);
            controlCapicua = arregloCapicua(unArregloChar, validos);


            if(controlCapicua==0)
            {
                puts("\nel arreglo no es capicua\n");
            }
            else
            {
                puts("\nel arreglo es capicua\n");
            }

            break;

        case 10:
            validos=cargarUnArregloChar(unArregloChar, 20);
            puts("\narreglo original\n");
            mostrarUnArregloChar(unArregloChar, validos);
            invertirArreglo(unArregloChar, validos);

            puts("\n arreglo invertido\n");
            mostrarUnArregloChar(unArregloChar, validos);

            break;

        case 11:
            validos=cargarUnArregloChar(unArregloChar, 20);
            puts("\narreglo original\n");
            mostrarUnArregloChar(unArregloChar, validos);
            ordenarArregloSeleccion2(unArregloChar, validos);
            puts("\n arreglo ordenado\n");
            mostrarUnArregloChar(unArregloChar, validos);


        }
        puts("\nDesea continuar con otro ejercicio? s/n\n");
        fflush(stdin);
        scanf("%c", &salirSwitch);

    }
    while(salirSwitch != 'n');

    return 0;
}




///1.	Hacer una función que reciba como parámetro un arreglo de números enteros y permita que el usuario ingrese valores al mismo por teclado. La función debe retornar la cantidad de elementos cargados en el arreglo (o pueden utilizar como puntero válidos).

int cargarUnArreglo(int A[], int dimension)
{
    char control='s';
    int validos=0;

    while(control=='s'&& validos<dimension)
    {
        printf("Ingrese un elemento entero al arreglo: ");
        scanf("%d", &A[validos]);

        printf("\nDesea continuar? s/n");
        fflush(stdin);
        scanf("%c", &control);

        validos++;
    }

    return validos;
}
///2.	Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y los muestre por pantalla.

void mostrarUnArreglo(int A[], int validos)
{
    int i;

    puts("Contenido del arreglo");

    for(i=0; i<validos; i++)
    {
        printf("%d ", A[i]);
    }
}
///3.	Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos)
///cargados en él y calcule la suma de sus elementos.

int sumaValidosArreglo(int A[], int validos)
{
    int i=0;
    int suma =0;

    for(i=0; i<validos; i++)
    {
        suma = suma + A[i];
    }


    return suma;
}

///4.	Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos)
///cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila.

void cargarPilaDesdeArreglo (int A[], int validos,Pila * unapila)
{
    int i=0;
    for(i=0; i< validos; i++)
    {

        apilar(unapila, A[i]);
    }
}




///5.	Realizar una función que sume los elementos de un arreglo de números reales (float) de dimensión
///100. (se recomienda hacer una función para cargar y otra para mostrar para este
///      tipo de dato asociado al arreglo)

int cargarUnArregloFloat(float A[], int dimension)
{
    char control='s';
    int i=0;

    while(control=='s'&&i<dimension)
    {
        printf("Ingrese un elemento entero al arreglo: ");
        scanf("%f", &A[i]);

        printf("\nDesea continuar? s/n");
        fflush(stdin);
        scanf("%c", &control);

        i++;
    }

    return i;
}

void mostrarUnArregloFloat(float A[], int validos)
{
    int i;

    puts("Contenido del arreglo float\n");

    for(i=0; i<validos; i++)
    {
        printf("%f ", A[i]);
    }
}

float sumaValidosArregloFloat(float A[], int validos)
{
    int i=0;
    float suma =0;

    for(i=0; i<validos; i++)
    {
        suma = suma + A[i];
    }

    return suma;
}






///6.	Realizar una función que indique si un elemento dado se encuentra en un arreglo de caracteres.
int cargarUnArregloChar (char A[], int dimension)
{
    char control='s';
    int i=0;

    while(control=='s'&&i<dimension)
    {
        printf("Ingrese un elemento char al arreglo: ");
        fflush(stdin);
        scanf("%c", &A[i]);

        printf("\nDesea continuar? s/n");
        fflush(stdin);
        scanf("%c", &control);

        i++;
    }
    return i;
}

int encontrarCharEnArreglo (char A[], int validos, char buscado)
{
    int bandera =-1;
    int i=0;

    for(i=0; i<validos; i++)
    {

        if (A[i]== buscado)
        {
            bandera = i;
        }


    }
    return bandera;


}


void mostrarUnArregloChar(char A[], int validos)
{
    {
        int i;

        puts("Contenido del arreglo char\n");

        for(i=0; i<validos; i++)
        {
            printf("%c ", A[i]);
        }
    }

}

///7.	Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente, conservando el orden.

int cargarUnArregloCharOrdenado (char A[], int dimension)
{
    int i=0;
    for(i=0; i<dimension; i++ )
    {
        A[i]= i+97;
    }

    return i;
}

int insertarCharEnAOrdenado (char A[], int validos, char aInsertar)
{
    int posicion = validos-1;


    while( posicion > 0 && A[posicion] > aInsertar )
    {
        A[posicion+1]= A[posicion];
        posicion--;
    }
    A[posicion+1]= aInsertar;
    return validos+1;
}
///8.	Realizar una función que obtenga el máximo carácter de un arreglo dado.


int encontrarMaximoChar(char A[],int validos )
{
    int charMax2=A[0];
    int i=0;
    for (i=1; i<validos; i++)
    {
        if(A[i]>charMax2)
        {
            charMax2=A[i];
        }

    }

    return charMax2;
}
///9.	Realizar una función que determine si un arreglo es capicúa.

int arregloCapicua(char A[], int validos)
{
    int posIn=0;
    int posFin = validos-1;
    int capicua =1;
    int flag=1;

    while(posIn<posFin && flag==1)
    {
        if(A[posIn]==A[posFin])
        {
            posIn++;
            posFin--;
        }
        else
        {
            flag=0;
            capicua=0;
        }
    }
    return capicua;

}

///10.	Realizar una función que invierta los elementos de un arreglo.  (sin utilizar un arreglo auxiliar)
void invertirArreglo(char A[], int validos)
{
    char aux;
    int posIn=0;
    int posFin = validos-1;

    while(posIn<posFin)
    {
        aux = A[posFin];
        A[posFin]=A[posIn];
        A[posIn]=aux;
        posFin--;
        posIn++;
    }

}



///11.	Ordenar un arreglo según a.	Selección :

/*void ordenarArregloSeleccion(char A[],int validos)
{
    char aux;
    int i =0;
    int posCharMin=0;

    for(i=0; i<validos-1; i++)
    {
        aux = A[i];
        posCharMin = buscarPosMenorEnArreglo(A[], validos);
        A[i] = A[posCharMin];
        A[posCharMin]= aux;
    }
}

int buscarPosMenorEnArreglo(char A[], int validos)
{
    int posCharMin=0;
    int i=0;
    for (i=1; i<validos; i++)
    {
        if(A[i]<A[posCharMin])
        {
            posCharMin=i;
        }
    }
    return posCharMin;
}
*/
void ordenarArregloSeleccion2(char A[],int validos)
{
    char aux;
    int i =0;
    int posCharMin=0;
    int a =0;
    char charMin;

    for(i=0; i<validos-1; i++)
    {
        posCharMin=i;
        charMin =A[i];
        for (a=i+1; a<validos; a++)
        {
            if(A[a]<charMin)
            {
                posCharMin=a;
                charMin = A[a];
            }
        }
        aux = A[i];
        A[i] = A[posCharMin];
        A[posCharMin]= aux;
    }
}


///12.	Ordenar un arreglo según Inserción






///ejercicio que paso el profesor 5/5
///hacer una función que retorne la posición del carácter mas grande que se encuentra en el arreglo
/*
char buscaCharMaximo(char A[], int c) ///esta es la de ejemplo
{
    char max = A[0];
    int i = 1;
    while (i<c)
    {
        if (max<A[i])
        {
            max = A[i];
        }
        i++;
    }
    return max;
}

int buscaPosicionMaximo(char A[], int dimension) ///esta es la de ejemplo
{
    char max = A[0];
    int i = 1;
    while (i<c)
    {
        if (max<A[i])
        {
            max = A[i];
        }
        i++;
    }
    return max;
}

int buscaCharMaximo(char A[], int validos)
{
    char max = A[0];
    int i = 1, posmax=0;
    while (i<validos)
    {
        if (max<A[i])
        {
            max = A[i];
            posmax=i;
        }
        i++;
    }
    return posmax;
}

*/

/*






11.	Ordenar un arreglo según los siguientes métodos:
a.	Selección
void



b.	Inserción




12.	Dados dos arreglos ordenados alfabéticamente, crear un tercer arreglo con los elementos de los dos primeros intercalados, de manera que quede un arreglo también ordenado alfabéticamente.
13.	Dado un el vector {1,5,6,7,8} escribir un programa que genere otro vector con la suma del contenido de todo los elementos anteriores al índice actual: {1,6,12,19,27}.
*/




