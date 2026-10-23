#include <stdio.h>
#include <string.h>
#define M 12
#define MAX 100

//*Registro del jugador
typedef struct
{
    int puntuacion, deporte, promedio;
    char actividad[20];
} Actividad;
typedef struct
{
    int min;
    int prom;
    int suma;
    int max_puntos;
    int mes, mes_min;
    char name[20];
} ScoresFinals;

//*Funciones necesarias
void inicializarActividad(ScoresFinals *salidas)
{
    salidas->min = 9999999;
    salidas->max_puntos = 0;
    salidas->suma = 0;
    salidas->mes_min = 999999;
}
void loadSports(Actividad mat[][MAX], int n)
{
    //*leer cada unos de los datos

    for (int i = 0; i < M; i++)
    {
        printf("---Mes %d---\n", i + 1);
        for (int j = 0; j < n; j++)
        {
            //*Ingresar el nombre de la actividad y el puntaje
            printf("Ingrese el nombre del deporte %d: ", j + 1);
            scanf("%s", mat[i][j].actividad);
            printf("Ingrese el puntaje del %d: ", j + 1);
            scanf("%d", &mat[i][j].puntuacion);
        }
    }
}
void showSports(Actividad mat[][MAX], int n)
{
    //*leer cada unos de los datos
    printf("TABLA DEPORTIVA :\n");
    for (int i = 0; i < M; i++)
    {
        printf("Mes %2d: ", i + 1);
        for (int j = 0; j < n; j++)
        {
            //*Ingresar el nombre de la actividad y el puntaje
            printf("%s: %d PTS", mat[i][j].actividad, mat[i][j].puntuacion);
        }
        printf("\n");
    }
}
void sumaPromMeses(Actividad mat[][MAX], ScoresFinals *score, int n)
{
    Actividad prom[M][MAX];
    //*Imprimir y guardar el promedio de cada mes

    printf("--PROMEDIO DE ACTIVIDADES DURANTE LOS 12 MESES--\n");
    for (int j = 0; j < n; j++)
    {
        strcpy(score->name, mat[0][j].actividad);
        score->suma = 0;
        for (int i = 0; i < M; i++)
        {
            for (int k = 0; k < n; k++)
            {
                if (strcmp(mat[i][k].actividad, score->name) == 0)
                {
                    score->suma += mat[i][k].puntuacion;
                }
            }
        }
        //*calculamos el promedio durante los 12 meses
        float prom = (float)score->suma / 12;
        printf("PROMEDIO %s Actividad %d: %.2f\n", score->name, j + 1, prom);
    }
}

int main()
{
    //*Variables

    int cant;

    Actividad Dep[M][MAX];
    ScoresFinals scores;
    inicializarActividad(&scores);
    printf("Ingrese la cantidad de Actividades del mes: ");
    scanf("%d", &cant);
    loadSports(Dep, cant);
    showSports(Dep, cant);
    sumaPromMeses(Dep, &scores, cant);
}