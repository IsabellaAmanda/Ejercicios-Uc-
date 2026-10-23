#include <stdio.h>
#include <string.h>
#define P 8
#define MAX 50
// Registro planeta
typedef struct
{
    char name[MAX];
    char tiporot_unidad;
    int tiempo_rot;
    int numsalite;
    float translacion;
    float distancia_sol;

} Planet;

Planet ptns[P];

// void cargar datos
void loadVect()
{
    int i;
    // cargar dato de los planetas
    for (i = 0; i < P; i++)
    {

        printf("Ingrese el nombre del planeta %d: ", i + 1);
        fgets(ptns[i].name, sizeof(ptns[i].name), stdin);
        ptns[i].name[strcspn(ptns[i].name, "\n")] = '\0';
        printf("Ingrese la cantidad de salites del planeta %d: ", i + 1);
        scanf("%d", &ptns[i].numsalite);
        printf("Ingrese la distacia del sol del planeta %d: ", i + 1);
        scanf("%f", &ptns[i].distancia_sol);
        printf("Ingrese el tiempo de traslación del planeta %d: ", i + 1);
        scanf("%f", &ptns[i].translacion);
        printf("Ingrese el tiempo de rotación del planeta  %d (Unidad a ingresar si d = dias/ h = horas): ", i + 1);
        scanf(" %c", &ptns[i].tiporot_unidad);
        printf("Ingrese el tiempo de rotación del planeta %d, ya sabiendo si lo ingresa en días o en horas: ", i + 1);
        scanf("%d", &ptns[i].tiempo_rot);
    }
}
void transformarTiempo()
{
    int i;
    printf("Planetas de días a hora (Tiempo de rotación): ");
    for (i = 0; i < P; i++)
    {
        if (ptns[i].tiporot_unidad == 'd' || ptns[i].tiempo_rot == 'D')
        {
            ptns[i].tiempo_rot = ptns[i].tiempo_rot * 24;
            ptns[i].tiporot_unidad = 'h';
        }
    }
}

void numstelitesLimite(int *limite)
{
    int i;
    for (i = 0; i < P; i++)
    {
        (*limite) = ptns[i].numsalite;
        if (ptns[i].numsalite > (*limite))
        {
            printf("Planeta %s| Número de satélites: %d| Tiempo de rotación : %d| Transalación: %.2f| Distancia al sol: %.2f\n", ptns[i].name, ptns[i].numsalite, ptns[i].tiempo_rot, ptns[i].translacion, ptns[i].distancia_sol);
        }
    }
}

int main()
{
    int lim;
    loadVect();
    transformarTiempo();
    printf("Ingrese un número de satélites: ");
    scanf("%d", &lim);
    numstelitesLimite(&lim);
    return 0;
}
