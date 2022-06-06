#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

typedef struct
{
    int legajo;
    char nombreYapellido [30];
    int edad;
    int anio;
//año que cursa, recordar que no podemos utilizar la ñ para definir variables
} stAlumno;




void cargarIntaArchivo(char archivo[]);
void mostrarArchivo(char archivo[]);
int contarRegistrosInt(char archivo[]);
void cargarCincoAlumnos(char archivo[]);
void cargarUnAlumnoRandom(FILE *puntArchivo);
void mostrarArchivoDeAlumnos(char archivo[]);
void mostrarUnAlumno(stAlumno unAlumno);
void agregarUnAlumno(char archivo[]);
void crearUnAlumno(stAlumno * unAlumno);
void pasarMayoresaPila(char archivo[], Pila *pilita);
void mostrarPila(Pila pilita);
int contarAlumnosPorEdad(char archivo[], int edad);
void mostrarAlumnosEntreEdades(int edadUno, int edadDos, char archivo[]);
void consultarDosEdades(int * edadMenor, int * edadMayor);
int buscarPosMasViejo(char archivo[]);
void mostrarAlumnoMasViejo(char archivo[]);
void mostrarAlumnoEnPos(char archivo[],int pos);
int buscarPorAnioDesdePos(char archivo[], int anio);
void pasarAlumnosaArchivo(int validos,stAlumno unArreglodeAlumnos[], char archivo[]);
int cargarArregloDeAlumnos(stAlumno unArreglodeAlumnos[], int dim);
int pasarAlumnosPorAniodeArchivoaArray(char archivo[],stAlumno unArregloAlumnos[],int anios);
void mostrarArregloAlumnos(stAlumno arregloAl[], int validos);
int contarRegistrosArchivo(char archivo[],int pesoDelRegistro);
void mostrarPosicionEnArchivo(char archivo[], int posicion);



int main()
{
    char archiv[]="archivos.bin";
    char archiv2[]="file2.bin";
    int cantRegistros=0,edadMen,edadMay,unAnio;
    int contAlumnosMayores=0;
    Pila unaPila;
    inicpila(&unaPila);
    stAlumno unArregloDeAlumnos[20];
    int validos=0;

    /*
    cargarIntaArchivo(archiv);
    mostrarArchivo(archiv);
    cantRegistros =contarRegistrosInt(archiv);
    printf("la cantidad de registros son: %d",cantRegistros);
    */
    //cargarCincoAlumnos(archiv2);
    // agregarUnAlumno(archiv2);

    mostrarArchivoDeAlumnos(archiv2);


    // pasarMayoresaPila(archiv2,&unaPila);
    // mostrarPila(unaPila);
    //contAlumnosMayores=contarAlumnosPorEdad(archiv2,30);
    //printf("\nla cantidad de alumnos mayores a 30 son:%d\n",contAlumnosMayores);

    //consultarDosEdades(&edadMen,&edadMay);
    //mostrarAlumnosEntreEdades(edadMen,edadMay,archiv2);
    //puts("el alumno mas viejo es:\n");
    //mostrarAlumnoMasViejo(archiv2);

    // puts("ingrese el año que quiere buscar:\n");
    //scanf("%d",&unAnio);
    //cantRegistros= buscarPorAnioDesdePos(archiv2, unAnio);
    //printf("la cantidad de registros del %d anio son:%d\n",unAnio,cantRegistros);

    //validos=cargarArregloDeAlumnos(unArregloDeAlumnos,20);
    //pasarAlumnosaArchivo(validos,unArregloDeAlumnos, archiv2);
    //mostrarArchivoDeAlumnos(archiv2);


   // puts("ingrese el año que quiere pasar del archivo al arreglo:\n");
    //scanf("%d",&unAnio);
    //validos=pasarAlumnosPorAniodeArchivoaArray(archiv2,unArregloDeAlumnos,unAnio);
    //mostrarArregloAlumnos(unArregloDeAlumnos,validos);

    //cantRegistros=contarRegistrosArchivo(archiv2,sizeof(stAlumno));
    //printf("\n la cantidad de registros es:%d",cantRegistros);

    puts("ingrese la posicion del registro que quiere mostroar? de 0 a 9:\n");
    scanf("%d",&unAnio);
    mostrarPosicionEnArchivo(archiv2,unAnio);



    return 0;
}
///1.	Hacer una función que agregue un elemento al final de un archivo.

void cargarIntaArchivo(char archivo[])
{
    int a=0;
    FILE *puntArchivo;
    char letra='s';

    puntArchivo = fopen(archivo, "ab");

    if(puntArchivo != NULL)
    {
        while(letra=='s')
        {

            puts("ingrese el int a cargar en el archivo:\n");
            scanf("%d", &a);

            fwrite(&a, sizeof(int),1, puntArchivo);
            puts("desea cargar otro int en el archivo?\n");
            fflush(stdin);
            scanf("%c", &letra);
        }
        fclose(puntArchivo);
    }
}
///2.	Hacer una función que muestre por pantalla el contenido de un archivo.
void mostrarArchivo(char archivo[])
{
    int a =0;
    FILE *puntArchivo;

    puntArchivo = fopen(archivo, "rb");
    if(puntArchivo !=NULL)
    {
        while(fread(&a,sizeof(int),1,puntArchivo)>0)
        {

            printf("el int cargado es:%d\n",a);
        }
        fclose(puntArchivo);
    }
}
///3.	Hacer una función que retorne la cantidad de registros que contiene un archivo.
int contarRegistrosInt(char archivo[])
{
    FILE *puntArchivo;
    puntArchivo = fopen(archivo, "rb");
    int cont=0;
    int a;
    if(puntArchivo != NULL)
    {
        while(!feof(puntArchivo))
        {
            fread(&a, sizeof(int),1, puntArchivo);
            cont++;
        }
        fclose(puntArchivo);
    }
    return cont-1;

}
///4.	Crear una función que cargue un archivo de alumnos.
///Abrirlo de manera tal de verificar si el archivo ya está creado previamente.
///Cargar el archivo con 5 datos. Cerrarlo dentro de la función.

void cargarCincoAlumnos(char archivo[])
{
    FILE *puntArchivo ;
    char opcion;
    puntArchivo = fopen(archivo, "rb");
    if(puntArchivo == NULL)
    {
        printf("el archivo no existe, desea crearlo? s o n\n");
        fflush(stdin);
        scanf("%c",&opcion);
        if(opcion !='s')
        {
            exit(0);
        }
        else
        {
            puntArchivo=fopen(archivo,"wb");
        }
    }
    else
    {
        printf("el archivo ya existe,se seguira escribiendo en el mismo archivo");
        system("pause");
        fclose(puntArchivo);
        puntArchivo=fopen(archivo,"ab");
    }

    if(puntArchivo!=NULL)
    {

        for(int i=0; i<5; i++)
        {
            cargarUnAlumnoRandom(puntArchivo);
        }

        fclose(puntArchivo);
    }

}

void cargarUnAlumnoRandom(FILE *puntArchivo)
{
    stAlumno unAlumnoRandom;

    if(puntArchivo != NULL)
    {
        unAlumnoRandom.legajo= 11;
        unAlumnoRandom.anio=2022;
        unAlumnoRandom.edad=25;
        strcpy(unAlumnoRandom.nombreYapellido, "NombreyApellido" );

        fwrite(&unAlumnoRandom, sizeof(stAlumno),1, puntArchivo);

    }
}
///5.	Crear una función que muestre por pantalla los registros de un archivo de alumnos. Modularizar.

void mostrarArchivoDeAlumnos(char archivo[])
{
    stAlumno unAlumno;
    FILE *puntArchivo;
    puntArchivo = fopen(archivo, "rb");
    if(puntArchivo !=NULL)
    {
        while(fread(&unAlumno,sizeof(stAlumno),1,puntArchivo)>0)
        {

            mostrarUnAlumno(unAlumno);
        }
        fclose(puntArchivo);
    }
}


void mostrarUnAlumno(stAlumno unAlumno)
{

    puts("------------------\n");
    printf("legajo:%d\n",unAlumno.legajo);
    printf("nombre:%s\n",unAlumno.nombreYapellido);
    printf("edad:%d\n",unAlumno.edad);
    printf("anio:%d\n",unAlumno.anio);

}
///6.	Crear una función que permita agregar de a un elemento al final del archivo.
///O sea, se debe abrir el archivo, se piden los datos (se llena una variable de tipo struct alumno),
/// se escribe en el archivo y se cierra.

void agregarUnAlumno(char archivo[])
{
    stAlumno unAlumno2;
    FILE *puntArchivo;
    puntArchivo=fopen(archivo, "ab");
    if(puntArchivo!=NULL)
    {
        crearUnAlumno(&unAlumno2);
        fwrite(&unAlumno2,sizeof(stAlumno),1,puntArchivo);
        fclose(puntArchivo);

    }
}

///preguntar al profesor por las flechitas

void crearUnAlumno(stAlumno * unAlumno)
{

    puts("ingrese el legajo del alumno\n");
    scanf("%d", &unAlumno->legajo);
    puts("ingrese el anio \n");
    scanf("%d", &unAlumno->anio);
    puts("ingrese el nombre del alumno\n");
    fflush(stdin);
    gets(unAlumno->nombreYapellido);
    ///scanf("%s", &unAlumno->nombreYapellido);  porque no anda con scanf???
    puts("ingrese la edad del alumno\n");
    scanf("%d", &unAlumno->edad);

}
///7.	Crear una función que pase a una pila los números de legajo de los alumnos mayores de edad.

void pasarMayoresaPila(char archivo[], Pila *pilita)
{
    FILE * puntArchivo;
    puntArchivo = fopen(archivo,"rb");

    stAlumno unAlumno;
    if(puntArchivo!=NULL)
    {
        while(fread(&unAlumno,sizeof(stAlumno),1, puntArchivo)>0)
        {
            if(unAlumno.edad>18)
            {
                apilar(pilita, unAlumno.legajo);
            }

        }
        fclose(puntArchivo);

    }

}
void mostrarPila(Pila unaPila)
{
    Pila otraPila;
    inicpila(&otraPila);
    while(!pilavacia(&unaPila))
    {
        printf("legajo de mayor:%d\n",tope(&unaPila));
        apilar(&otraPila,desapilar(&unaPila));
    }

}
///8.	Dado un archivo de alumnos, hacer una función que cuente la cantidad de alumnos
///mayores a edad específica que se envía por parámetro.
int contarAlumnosPorEdad(char archivo[], int edad)
{
    stAlumno unAlumno;
    FILE * puntFile;
    puntFile = fopen(archivo, "rb");
    int cont=0;
    if(puntFile!=NULL)
    {
        while(fread(&unAlumno, sizeof(stAlumno),1,puntFile)>0)
        {
            if(unAlumno.edad>edad)
            {
                cont++;

            }
        }
        fclose(puntFile);
    }
    return cont;
}

///9.	Dado un archivo de alumnos, mostrar por pantalla el nombre de todos los alumnos entre
/// un rango de edades específico (por ejemplo, entre 17 y 25 años).
/// Dicho rango debe recibirse por parámetro. Modularizar.
void mostrarAlumnosEntreEdades(int edadUno, int edadDos, char archivo[])
{
    stAlumno unAlumno;
    FILE * puntFile;
    puntFile = fopen(archivo, "rb");

    if(puntFile!=NULL)
    {
        while(fread(&unAlumno, sizeof(stAlumno),1,puntFile)>0)
        {
            if(unAlumno.edad>=edadUno && unAlumno.edad<=edadDos)
            {
                printf("los alumnos mayores que %d y menores que %d son:\n",edadUno,edadDos);
                mostrarUnAlumno(unAlumno);
            }

        }
    }
}
void consultarDosEdades(int * edadMenor, int * edadMayor)
{
    do
    {
        puts("mostrar alumnos mayores que:\n");
        scanf("%d", edadMenor);
        puts("mostrar alumnos menores que:\n");
        scanf("%d", edadMayor);
        if(*edadMayor<*edadMenor)
        {
            printf("valores incorrectos, %d es menor que %d ingrese nuevamente\n",*edadMayor,*edadMenor);

        }
    }
    while(*edadMayor<*edadMenor);
}
///10.	Dado un archivo de alumnos, mostrar los datos del alumno de mayor edad. Modularizar.

int buscarPosMasViejo(char archivo[])
{
    FILE * puntFile;
    puntFile = fopen(archivo, "rb");
    stAlumno unAlumno;
    int edadMay=0;
    int posMay=0;
    int i=0;

    if(puntFile!=NULL && fread(&unAlumno,sizeof(stAlumno),1,puntFile)>0)
    {
        edadMay=unAlumno.edad;
        i++;
        while(fread(&unAlumno,sizeof(stAlumno),1,puntFile)>0)
        {
            if(edadMay<unAlumno.edad)
            {
                edadMay=unAlumno.edad;
                posMay=i;

            }
            i++;
        }
        fclose(puntFile);
    }
    else
    {
        printf("error al leer el archivo");
        posMay=-1;
    }
    return posMay;
}

void mostrarAlumnoMasViejo(char archivo[])
{
    int mayor=0;
    FILE * puntFile2;
    puntFile2 = fopen(archivo, "rb");
    stAlumno unAlumno;

    if(puntFile2!=NULL)
    {

        mayor=buscarPosMasViejo(archivo);
        if(mayor>=0)
        {

            fseek(puntFile2,mayor*sizeof(stAlumno),SEEK_SET);
            if(fread(&unAlumno,sizeof(stAlumno),1,puntFile2)>0)
            {
                mostrarUnAlumno(unAlumno);
            }
            else
            {
                puts("error, no se puedo leer el alumno");
            }
        }
        fclose(puntFile2);
    }

}
///11.	Crear una función que retorne la cantidad de alumnos que cursan un determinado año.
///El año buscado se pasa por parámetro.
void mostrarAlumnoEnPos(char archivo[],int pos)
{

    FILE * puntFile2;
    puntFile2 = fopen(archivo, "rb");
    stAlumno unAlumno;

    if(puntFile2!=NULL)
    {

        if(fseek(puntFile2,pos*sizeof(stAlumno),SEEK_SET)== (pos*sizeof(stAlumno)))
        {

            fseek(puntFile2,pos*sizeof(stAlumno),SEEK_SET);
            if(fread(&unAlumno,sizeof(stAlumno),1,puntFile2)>0)
            {
                mostrarUnAlumno(unAlumno);
            }
            else
            {
                puts("error, no se puedo leer el alumno");
            }
        }
        else
        {
            puts("error en el parametro pos");
        }
        fclose(puntFile2);
    }

}

int buscarPorAnioDesdePos(char archivo[], int anio)
{
    FILE * puntFile;
    puntFile = fopen(archivo, "rb");
    stAlumno unAlumno;
    int cont=0;

    if(puntFile!=NULL)
    {
        while(fread(&unAlumno,sizeof(stAlumno),1,puntFile)>0)
        {
            if(anio==unAlumno.anio)
            {
                cont++;
            }
        }

        fclose(puntFile);
    }
    else
    {
        printf("error al leer el archivo");
    }

    return cont;
}
///12.	Crear una función que reciba como parámetro un arreglo de tipo alumno y lo copie en el archivo.
///Asimismo, realice otra función que pase los elementos del archivo a un arreglo de alumnos,
/// filtrando los estudiantes de un año en particular.



void pasarAlumnosaArchivo(int validos,stAlumno unArreglodeAlumnos[], char archivo[])
{
    FILE * puntFile;
    puntFile = fopen(archivo, "ab");

    if(puntFile!=NULL)
    {
        fwrite(unArreglodeAlumnos,sizeof(stAlumno),validos,puntFile);

        fclose(puntFile);
    }

}

int cargarArregloDeAlumnos(stAlumno unArreglodeAlumnos[], int dim)
{
    int i =0;
    char control='s';
    stAlumno unAlumno;
    while(i<dim && control =='s')
    {
        crearUnAlumno(&unAlumno);
        unArreglodeAlumnos[i]=unAlumno;
        i++;
        puts("desea cargar otro alumno?? s para seguir");
        fflush(stdin);
        scanf("%c",&control);
    }
    return i;

}

int pasarAlumnosPorAniodeArchivoaArray(char archivo[],stAlumno unArregloAlumnos[],int anios)
{
    FILE * puntFile;
    puntFile = fopen(archivo,"rb");
    int validos=0;
    stAlumno unAlumno;

    if(puntFile!=NULL)
    {
        while(fread(&unAlumno,sizeof(stAlumno),1,puntFile)>0)
        {
            if(unAlumno.anio==anios)
            {
                if(!feof(puntFile))
                {
                    unArregloAlumnos[validos]=unAlumno;
                    validos++;
                }
            }
        }

        fclose(puntFile);
    }

    return validos;

}

void mostrarArregloAlumnos(stAlumno arregloAl[], int validos){
for(int i=0;i<validos;i++){
    mostrarUnAlumno(arregloAl[i]);

}
}
///13.	Crear una función que retorne la cantidad de registros que tiene el archivo.
///Usar fseek y ftell. Puede pensar la función para uso genérico, que sirva para averiguar la cantidad
///de registros de cualquier archivo.
int contarRegistrosArchivo(char archivo[],int pesoDelRegistro){
int pesoTotal;
FILE * puntFile;
puntFile =fopen(archivo,"rb");
if(puntFile!=NULL){
    fseek(puntFile,0,SEEK_END);
    pesoTotal=ftell(puntFile);
    fclose(puntFile);

}

return pesoTotal/pesoDelRegistro;

}
///14.	Dado un archivo de alumnos, que tenga al menos 10 registros, hacer una función que
/// muestre el contenido de un registro, cuyo número (entre 0 y 9) se pase por parámetro.
/// Controlar no sobrepasar los límites del archivo.

void mostrarPosicionEnArchivo(char archivo[], int posicion){
FILE * puntFile;
puntFile =fopen(archivo,"rb");
stAlumno unAlumno;

if(puntFile!=NULL){
   fseek(puntFile,posicion*(sizeof(stAlumno)), SEEK_SET);
    if(!feof(puntFile)&& fread(&unAlumno,sizeof(stAlumno),1,puntFile)>0){
    mostrarUnAlumno(unAlumno);
    }else{
    puts("valor incorrecto, intente nuevamente con un numero menor");
    }

   fclose(puntFile);
   }

}




/*


15.	Realice una (o varias) funciones que permitan modificar un registro existente en el archivo de alumnos.
La misma debe permitir modificar uno o todos los campos de la estructura y sobreescribir el
registro existente en el archivo.



16.	Dado un archivo de alumnos, hacer una función que invierta los elementos del mismo.
No se puede usar otro archivo auxiliar ni un arreglo auxiliar.
Debe trabajar sobre el archivo. Puede utilizar variables de tipo alumno auxiliares.
17.	Hacer una función principal que pruebe el funcionamiento de todos los incisos anteriores,
 con un menú de opciones para poder ejecutar todas las funciones requeridas.
 Tengan presente la correcta declaración y el ámbito de variables.


*/
