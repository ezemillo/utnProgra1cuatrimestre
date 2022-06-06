#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void cargarMatriz (int filas, int columnas, int A[filas][columnas]);
void mostrarMatriz(int filas, int columnas, int A[filas][columnas]);
void cargarMatrizRandom(int filas, int columnas, int A[filas][columnas]);
int sumaElementosMatriz(int filas, int columnas, int A[filas][columnas]);
float promedioMatriz(int filas, int columnas, int A[filas][columnas]);
int buscarElemento(int filas, int columnas, int A[filas][columnas], int numero);
int cargarArregloStr(int filas, int columnas, char A[filas][columnas]);
void mostrarMatrizStr(int filas,int columnas,char A[filas][columnas]);
int estaString(int filas, char A[filas][30], char wrd[1]);
int estaStringPos(int filas, char A[filas][30], char wrd[30]);
int buscarPosMenorEnArregloChar(int validos, char A[][30], int pasada);
void ordenarArregloSeleccionChar(int validos, char A[][30]);






int main()
{
    srand(time(NULL));

    int controlSwitch;
    char salirSwitch;
    int unaMatriz [20][20];
    int fil=0, col=0,resultado=0, unNumero=0, estaElemento=0;
    float promedio=0;
    char UnArregloChar[20][30];
    char palabra[30];





    do
    {
        printf("que ejercicio quiere correr?\n");
        printf("1 y 2.	Hacer una función que reciba como parámetro una matriz de números enteros y permita que el usuario ingrese valores al mismo por teclado. La función debe cargar la matriz por completo.\n");
        printf("3.	Hacer una función que reciba como parámetro una matriz de números enteros y que cargue la misma con números aleatorios (sin intervención del usuario).\n");
        printf("4.	Hacer una función tipo int que sume el contenido total de una matriz de números enteros.\n");
        printf("5.	Hacer una función tipo float que calcule el promedio de una matriz de números enteros.\n");
        printf("6.	Hacer una función que determine si un elemento se encuentra dentro de una matriz de números enteros. La función recibe la matriz y el dato a buscar.\n");
        printf("7.	Hacer una función que cargue un arreglo de palabras (strings). La función debe retornar cuantas palabras se cargaron.  (puede ser a través del parámetro como puntero)\n");
        printf("9.	Hacer una función que determine si un string se encuentra dentro de un arreglo de strings.\n");
        printf("10.	Hacer una función que determine si un string se encuentra dentro de un arreglo de strings ordenado \n alfabéticamente. La función recibe el arreglo, la cantidad de palabras que contiene y el string a buscar.  ///devuelve el índice de la fila en que se encuentra, de lo contrario -1\n");
        printf("11.	Hacer una función (o varias) que ordene un arreglo de palabras por orden alfabético.\n");



        fflush(stdin);
        scanf("%d", &controlSwitch);

        switch(controlSwitch)
        {



        case 1:
            puts("cuantas filas tiene la matriz?\n");
            scanf("%d",&fil);

            puts("cuantas columnas tiene la matriz?\n");
            scanf("%d",&col);


            cargarMatriz(fil, col, unaMatriz);
            mostrarMatriz(fil, col, unaMatriz);


            break;
        case 3:
            puts("cuantas filas tiene la matriz?\n");
            scanf("%d",&fil);

            puts("cuantas columnas tiene la matriz?\n");
            scanf("%d",&col);


            cargarMatrizRandom(fil, col, unaMatriz);
            mostrarMatriz(fil, col, unaMatriz);


            break;


        case 4:
            puts("cuantas filas tiene la matriz?\n");
            scanf("%d",&fil);

            puts("cuantas columnas tiene la matriz?\n");
            scanf("%d",&col);


            cargarMatrizRandom(fil, col, unaMatriz);
            mostrarMatriz(fil, col, unaMatriz);
            resultado = sumaElementosMatriz(fil, col,unaMatriz);
            printf("la suma de los elementos de la matriz es: %d", resultado);

            break;

        case 5:
            puts("cuantas filas tiene la matriz?\n");
            scanf("%d",&fil);

            puts("cuantas columnas tiene la matriz?\n");
            scanf("%d",&col);


            cargarMatrizRandom(fil, col, unaMatriz);
            mostrarMatriz(fil, col, unaMatriz);
            promedio = promedioMatriz(fil, col,unaMatriz);
            printf("el promedio de los elementos de la matriz es: %f", promedio);

            break;
        case 6:
            puts("cuantas filas tiene la matriz?\n");
            scanf("%d",&fil);

            puts("cuantas columnas tiene la matriz?\n");
            scanf("%d",&col);
            puts("ingrese el numero a buscar\n");
            scanf("%d",&unNumero);


            cargarMatrizRandom(fil, col, unaMatriz);
            mostrarMatriz(fil, col, unaMatriz);

            estaElemento = buscarElemento(fil, col, unaMatriz, unNumero);
            printf("esta elemento = %d \n", estaElemento);

            if(estaElemento != 1)
            {
                puts("el elemento no esta en la matriz\n");
            }
            if(estaElemento == 1 )
            {
                puts("el numero esta dentro de la matriz\n");
            }



            break;

        case 7:


            fil= cargarArregloStr(5,30, UnArregloChar);
            printf("palabras cargadas: %d\n", fil);
            mostrarMatrizStr(fil,30, UnArregloChar);




            break;

        case 9:
            fil= cargarArregloStr(5,30, UnArregloChar);

            mostrarMatrizStr(fil,30, UnArregloChar);
            puts("ingrese la palabra a buscar:\n");
            fflush(stdin);

            scanf("%s",palabra);
            unNumero= estaString(fil, UnArregloChar, palabra);
            if(unNumero==0)
            {
                puts("la palabra esta dentro del arreglo\n");
            }
            else
            {
                puts("la palabra no esta dentro del arreglo\n");
            }




            break;



        case 10:

            fil= cargarArregloStr(5,30, UnArregloChar);

            mostrarMatrizStr(fil,30, UnArregloChar);
            puts("ingrese la palabra a buscar:\n");
            fflush(stdin);
            scanf("%s",palabra);
            unNumero= estaStringPos(fil, UnArregloChar, palabra);
            printf("unnumero es igual a %d\n", unNumero);

            if(unNumero>-1)
            {
                printf("la palabra encontrada esta en la posicion: %d \n", unNumero);
            }
            else
                puts("la palabra no se encuentra en el arreglo \n");

            break;

        case 11:

            fil= cargarArregloStr(5,30, UnArregloChar);

            mostrarMatrizStr(fil,30, UnArregloChar);
            ordenarArregloSeleccionChar(fil, UnArregloChar);
            puts("\n");
            mostrarMatrizStr(fil,30, UnArregloChar);


            break;

        }
        puts("\nDesea continuar con otro ejercicio? s/n\n");
        fflush(stdin);
        scanf("%c", &salirSwitch);

    }
    while(salirSwitch != 'n');

    return 0;
}

void cargarMatriz (int filas, int columnas, int A[filas][columnas])
{
///cargar matriz
    int f=0, c=0;
    for(f=0; f<filas; f++)
    {
        for(c=0; c<columnas; c++)
        {
            printf("ingrese el valor para la posicion %d%d \n",f, c );
            scanf("%d", &A[f][c]);

        }

    }
}
///mostrarMatriz
void mostrarMatriz(int filas, int columnas, int A[filas][columnas])
{
    int f=0, c=0;
    for(f=0; f<filas; f++)
    {
        for(c=0; c<columnas; c++)
        {
            printf(" -%d- ",A[f][c]);

        }
        printf("\n");

    }

}
void cargarMatrizRandom(int filas, int columnas, int A[filas][columnas])
{
    int f=0, c=0;
    for(f=0; f<filas; f++)
    {
        for(c=0; c<columnas; c++)
        {
            A[f][c]= rand()%50;
        }

    }
}
int sumaElementosMatriz(int filas, int columnas, int A[filas][columnas])
{
    int f=0, c=0, suma=0;
    for(f=0; f<filas; f++)
    {
        for(c=0; c<columnas; c++)
        {
            suma += A[f][c];

        }

    }

    return suma;
}

float promedioMatriz(int filas, int columnas, int A[filas][columnas])
{
    int f=0, c=0, suma=0,cont=0;
    for(f=0; f<filas; f++)
    {
        for(c=0; c<columnas; c++)
        {
            suma += A[f][c];
            cont++;

        }
    }
    return (float)suma/cont;


}

int buscarElemento(int filas, int columnas, int A[filas][columnas], int numero)
{

    int f=0, c=0, flag=0;
    for(f=0; f<filas && flag==0; f++)
    {
        for(c=0; c<columnas && flag==0; c++)
        {
            if(A[f][c]==numero)
            {
                flag = 1;
            }

        }

    }
    return flag;
}

int cargarArregloStr(int filas, int columnas,char A[filas][columnas])
{
    int cont=0;
    char control='s';

    while(cont<filas && control!='n')
    {
        puts("\ningrese una palabra\n");
        fflush(stdin);
        scanf("%s", &A[cont]);
        cont++;
        puts("\ndesea seguir cargando palabras? ingrese n para salir\n");
        fflush(stdin);
        scanf("%c", &control);
    }


    return cont;

}

///8.	Hacer una función que muestre un arreglo de palabras.


void mostrarMatrizStr(int filas,int columnas,char A[filas][columnas])
{
    int f=0;

    puts("matriz de strings:");
    for(f=0; f<filas; f++)
    {
        printf(" -%s- \n",A[f]);

    }
}

int estaString(int filas, char A[filas][30], char wrd[30])
{
    int i=0,estastr=1;

    while(i<filas && estastr !=0 )
    {
        estastr = strcmpi(A[i],wrd);
        i++;
    }
    return estastr;
}

int estaStringPos(int filas, char A[filas][30], char wrd[30])
{
    int i=0,estastr=1, pos=-1;

    while(i<filas && estastr !=0 )
    {
        estastr = strcmpi(A[i],wrd);

        i++;

    }
    if(estastr==0)
    {
        pos=i-1;
    }


    return pos;
}


///11.	Hacer una función (o varias) que ordene un arreglo de palabras por orden alfabético. (Por selección o inserción, el que más te guste).

void ordenarArregloSeleccionChar(int validos,char A[][30])
{
    char aux[30];
    int i =0;
    int posMin=0;

    for(i=0; i<validos-1; i++)
    {
        strcpy(aux, A[i]);
        posMin = buscarPosMenorEnArregloChar(validos, A , i);
        strcpy(A[i], A[posMin]);
        strcpy(A[posMin], aux);
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



/*

12.	Hacer una función que retorne el determinante de una matriz de 2x2.
13.	Función que verifique si una matriz de 2x2 tiene inversa.
14.	Hacer una función que multiplique una matriz de 2x2 por una matriz de 2x5.
15.	Hacer una función que calcule la matriz inversa de una matriz de 2x2.
*/
