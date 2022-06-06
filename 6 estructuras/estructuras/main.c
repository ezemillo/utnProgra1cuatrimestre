#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int matricula;
    char nombre[30];
    char genero; //m, f, o
} stAlumno;

int cargarArregloAlumno(stAlumno unArregloDeAlumnos[], int dim);
void mostrarArregloDeAlumnos(int validos, stAlumno unArreglodeAlumnos[]);
void mostrarUnAlumno(int posicion, stAlumno unArregloDeAlumnos[]);
int buscarPosMatricula(int validos,int matricula, stAlumno unArregloDeAlumnos[]);
void mostrarAlumnoPorMatricula(int validos, int matricula, stAlumno unArregloDeAlumnos[]);
int encontrarMenorMatricula(int validos,int pasada, stAlumno unArregloDeAlumos[]);
void ordenarAlumnoPorSeleccion(int validos, stAlumno unArregloDeAlumos[]);
int buscarPosDeGenero(char genero,int validos,int pasada,stAlumno unArregloDeAlumnos[]);
void mostrarAlumnoPorGenero(char genero, int validos, stAlumno unArregloDeAlumnos[]);
void cargarUnAlumno(stAlumno unAlumno[]);
int insertarAlumnoOrdenadoPorMatricula(int validos, stAlumno unArregloDeAlumnos[]);
void ordenarAlumnoPorInsercion(int validos, stAlumno unArregloDeAlumnos[]);
void reemplazarPorInsercion(int posicionAOrdenar, stAlumno unArregloDeAlumnos[]);
int contarAlumnosIgualGenero(int validos, stAlumno unArregloDeAlumnos[], char genero);









int main()
{
    int matricula=0;
    stAlumno alumnos[30];

    int validos = cargarArregloAlumno(alumnos,30);
    char gen;
    int cantAlumnos=0;

    mostrarArregloDeAlumnos(validos, alumnos);

    /*printf("que matricula quiere mostrar??");
    scanf("%d",&matricula);
    mostrarAlumnoPorMatricula(validos,matricula,alumnos);

    ordenarAlumnoPorSeleccion(validos, alumnos);
    puts("estos son los alumnos ordenados por matricula\n");
    mostrarArregloDeAlumnos(validos, alumnos);


    puts("que genero de alumnos queres mostrar?? ingrese m o f");
    fflush(stdin);
    scanf("%c",&gen);
    mostrarAlumnoPorGenero(gen,validos,alumnos);

    validos = insertarAlumnoOrdenadoPorMatricula(validos,alumnos);

    ordenarAlumnoPorInsercion(validos,alumnos);



    mostrarArregloDeAlumnos(validos, alumnos);
*/

    puts("que genero de alumnos queres contar?? ingrese m o f");
    fflush(stdin);
    scanf("%c",&gen);
    cantAlumnos = contarAlumnosIgualGenero(validos,alumnos,gen);

    printf("la cantidad de alumnos de genero %c son: %d",gen,cantAlumnos);

    return 0;
}


///1.	Hacer una función que cargue un arreglo de alumnos, hasta que el usuario lo decida.


int cargarArregloAlumno(stAlumno unArregloDeAlumnos[], int dim)
{
    int validos=0;
    char control='s';

    while(control=='s' && validos<dim)
    {
        puts("ingrese la matricula del alumno:\n");
        scanf("%d", &unArregloDeAlumnos[validos].matricula);
        puts("ingrese el nombre del alumno(29char max):\n");
        fflush(stdin);
        scanf("%s", unArregloDeAlumnos[validos].nombre);
        puts("ingrese el genero del alumno(m o f):\n");
        fflush(stdin);

        scanf("%c", &unArregloDeAlumnos[validos].genero);


        puts("desea cargar otro alumno? s para seguir");
        fflush(stdin);
        scanf("%c", &control);
        validos++;
    }


    return validos;
}




///2.	Hacer una función que muestre un arreglo de alumnos por pantalla. Modularizar.

void mostrarArregloDeAlumnos(int validos, stAlumno unArreglodeAlumnos[])
{
    int i=0;
    for(i=0; i<validos; i++)
    {
        mostrarUnAlumno(i,unArreglodeAlumnos);

    }
}

void mostrarUnAlumno(int posicion, stAlumno unArregloDeAlumnos[])
{
    printf("matricula:%d , nombre: %s , genero: %c.\n",unArregloDeAlumnos[posicion].matricula, unArregloDeAlumnos[posicion].nombre, unArregloDeAlumnos[posicion].genero);

}
///3.	Hacer una función que muestre por pantalla los datos de un alumno,
///conociendo su matrícula. Modularizar.

int buscarPosMatricula(int validos,int matricula, stAlumno unArregloDeAlumnos[])
{
    int pos=-1;
    int i=0;
    while(pos==-1 && i<validos)
    {
        if(matricula == unArregloDeAlumnos[i].matricula)
        {
            pos = i;
        }
        i++;
    }
    return pos;
}
void mostrarAlumnoPorMatricula(int validos, int matricula, stAlumno unArregloDeAlumnos[])
{

    int pos=buscarPosMatricula(validos,matricula, unArregloDeAlumnos);
    mostrarUnAlumno(pos,unArregloDeAlumnos);
}
///4.	Hacer una función que ordene el arreglo de alumnos por medio del método de selección.
/// El criterio de ordenación es el número de matrícula.

int encontrarMenorMatricula(int validos,int pasada, stAlumno unArregloDeAlumos[])
{
    int cont = 0+pasada;
    int matMenor =unArregloDeAlumos[cont].matricula;
    int posMenor=cont;

    for(int i=cont+1; i<validos; i++)
    {
        if(matMenor>unArregloDeAlumos[i].matricula)
        {
            posMenor = i;
        }
    }
    return posMenor;
}

void ordenarAlumnoPorSeleccion(int validos, stAlumno unArregloDeAlumos[])
{
    int posMenor=0;
    int i=0;
    stAlumno aux;
    for(i=0; i<validos-1; i++)
    {
        posMenor = encontrarMenorMatricula(validos,i,unArregloDeAlumos);
        aux=unArregloDeAlumos[i];
        unArregloDeAlumos[i]=unArregloDeAlumos[posMenor];
        unArregloDeAlumos[posMenor]=aux;

    }

}
///5.	Hacer una función que muestre por pantalla los datos de los estudiantes de un género
/// determinado (se envía por parámetro). Modularizar.

int buscarPosDeGenero(char genero,int validos,int pasada,stAlumno unArregloDeAlumnos[])
{
    int cont = 0+pasada;
    int posGeneroo=-1;


    while(cont<validos && posGeneroo==-1)
    {
        if(genero==unArregloDeAlumnos[cont].genero)
        {
            posGeneroo = cont;
        }
        cont++;
    }
    return posGeneroo;
}
void mostrarAlumnoPorGenero(char genero, int validos, stAlumno unArregloDeAlumnos[])
{
    int posGenero = 0;
    int i=0;
    while(posGenero!=-1)
    {
        posGenero = buscarPosDeGenero(genero,validos,i,unArregloDeAlumnos);
        if(posGenero !=-1)
            mostrarUnAlumno(posGenero,unArregloDeAlumnos);
        i=posGenero+1;
    }

}
///6.	Hacer una función que inserte en un arreglo ordenado por matrícula un nuevo dato,
/// conservando el orden.

void cargarUnAlumno(stAlumno unAlumno[])
{

    puts("ingrese la matricula del alumno:\n");
    scanf("%d", &unAlumno[0].matricula);
    puts("ingrese el nombre del alumno(29char max):\n");
    fflush(stdin);
    scanf("%s", unAlumno[0].nombre);
    puts("ingrese el genero del alumno(m o f):\n");
    fflush(stdin);
    scanf("%c", &unAlumno[0].genero);


}

int insertarAlumnoOrdenadoPorMatricula(int validos, stAlumno unArregloDeAlumnos[])
{
    int i = validos;
    stAlumno unAlumno[1];///preguntar porque no anda con un stalumno y si o si tiene que ser un array
    cargarUnAlumno(unAlumno);
    printf("alumno a insertar: matricula%d, genero%c, nombre%s\n",unAlumno[0].matricula,unAlumno[0].genero,unAlumno[0].nombre);

    while(i>0 && unArregloDeAlumnos[i-1].matricula>unAlumno[0].matricula)
    {
        unArregloDeAlumnos[i]=unArregloDeAlumnos[i-1];
        i--;
    }
    unArregloDeAlumnos[i]=unAlumno[0];
    return validos+1;
}

///7.	Hacer una función que ordene el arreglo de alumnos por medio del método de inserción.
/// El criterio de ordenación es el nombre.

void ordenarAlumnoPorInsercion(int validos, stAlumno unArregloDeAlumnos[])
{
    int j=0;

    for(j=0; j<validos-1; j++)
    {
        reemplazarPorInsercion(j,unArregloDeAlumnos);
    }
}

void reemplazarPorInsercion(int posOrdenada, stAlumno unArregloDeAlumnos[])
{
    stAlumno aux[1];
    aux[0]=unArregloDeAlumnos[posOrdenada+1];

    while(posOrdenada>=0 && strcmpi(unArregloDeAlumnos[posOrdenada].nombre, aux[0].nombre )>0 )
    {
        unArregloDeAlumnos[posOrdenada+1]=unArregloDeAlumnos[posOrdenada];
        posOrdenada--;
    }
    unArregloDeAlumnos[posOrdenada+1]=aux[0];

}
///8.	Hacer una función que cuente y retorne la cantidad de estudiantes de un género determinado (se envía por parámetro) que tiene un arreglo de alumnos.

int contarAlumnosIgualGenero(int validos,stAlumno unArregloDeAlumnos[], char genero){

    int posGenero = 0;
    int i=0;
    int cantAlumnos=0;
    while(posGenero!=-1)
    {
        posGenero = buscarPosDeGenero(genero,validos,i,unArregloDeAlumnos);
        if(posGenero !=-1)
            cantAlumnos++;
        i=posGenero+1;
    }
return cantAlumnos;
}






/*





9.	Hacer una función principal que pruebe el funcionamiento de todos los incisos anteriores, con un menú de opciones para poder ejecutar todas las funciones requeridas. Tengan presente la correcta declaración y el ámbito de variables.
*/
