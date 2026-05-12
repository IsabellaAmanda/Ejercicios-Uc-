#include <stdio.h>

/*
Funcion del programa:
Generar estadisticas de conductores que han participado en accidente
de transito durante 1 year
*/
// Cuerpo principal
int main()
{
    // entradas
    int band = 1, provincia, edad;
    char sexo;
    // varibles de control, contadores y acumuladores
    int cont30 = 0, cont18 = 0, femenino = 0, masculino = 0, total = 0, edad_capt = 0, cont_fem = 0, cont_mas = 0;

    // salidas
    float porcent_30, porcent_fem, porcent_m18, porcent_capt, prom_fem, prom_mas;

    // activar bandera
    printf("Han ocurrido accidentes automovilisticos (si = 1 / no = 0) ?\n");
    scanf("%d", &band);

    while (band)
    {
        total++;

        printf("\nIngrese los datos del conductor:\n");
        printf("Edad: ");
        scanf("%d", &edad);
        printf("\nSexo (F o M): ");
        scanf(" %c", &sexo);
        printf("\nDe donde priviene? (1.-Capital, 2.-Otro): ");
        scanf("%d", &provincia);

        // contar, acumular, evaluar condiciones
        if (edad < 30)
            cont30++;

        if (sexo == 'M' && edad >= 18 && edad <= 30)
            cont18++;

        if (sexo == 'F')
        {
            femenino += edad;
            cont_fem++;
        }
        else
        {
            masculino += edad;
            cont_mas++;
        }

        if (provincia == 1)
            edad_capt++;

        // preguntemos de nuevo si hay accidentes
        printf("Han ocurrido accidentes automovilisticos (si = 1 / no = 0) ?\n");
        scanf("%d", &band);
    }

    // condiciones de salida

    // porcentajes
    if (total > 0)
    {
        porcent_30 = ((float)cont30 / total) * 100;
        porcent_m18 = ((float)cont18 / total) * 100;
        porcent_fem = ((float)cont_fem / total) * 100;
        porcent_capt = ((float)edad_capt / total) * 100;

        if (cont_fem > 0)
            // promedios
            prom_fem = femenino / cont_fem;

        if (cont_mas > 0)
            prom_mas = masculino / cont_mas;

        // salidas
        printf("\n---Estadisticas---\n");
        printf("Porcentaje de conductores menores de 30 anios: %.2f\n", porcent_30);
        printf("Porcentaje de conductores sexo femenino: %.2f\n", porcent_fem);
        printf("Porcentaje de conductores masculinos de entre 18 y 30 anios: %.2f\n", porcent_m18);
        printf("Porcentaje de conductores de la capital: %.2f\n", porcent_capt);
        printf("Promedio de edades femeninos: %.2f\n", prom_fem);
        printf("Promedio de edades masculino: %.2f\n", prom_mas);
    }
    else
    {

        printf("Error: La division por cero no existe\n");
    }
    return 0;
}