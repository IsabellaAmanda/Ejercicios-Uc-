#include <stdio.h>

// cuerpo principal

int main()
{
    int dia_semana, dia_mes, mes, year;

    // ingresar datos por el user de la fecha
    printf("Dia de semana:\n0-domingo,1-lunes,2-martes,3-miércoles,4-jueves,5-viernes,6-sábado\n");
    printf("\nDia del mes:\nValor 1-31\n");
    printf("\nMes:\n1-enero,2-febrero,3-marzo,4-abril,5-mayo,6-junio,7-julio,8-agosto,9-septiembre,10-octube,11-noviembre,12-diciembre\n\n");
    scanf("%d %d %d %d", &dia_semana, &dia_mes, &mes, &year);

    // evaluar y mostrar fecha correspondiente
    printf("\nLa secuencia %d %d %d %d corresponde a ", dia_semana, dia_mes, mes, year);

    if (dia_semana == 0)
    {
        printf("domingo, ");
    }
    else if (dia_semana == 1)
    {
        printf("lunes, ");
    }
    else if (dia_semana == 2)
    {
        printf("martes, ");
    }
    else if (dia_semana == 3)
    {
        printf("miércoles, ");
    }
    else if (dia_semana == 4)
    {
        printf("jueves, ");
    }
    else if (dia_semana == 5)
    {
        printf("viernes, ");
    }
    else if (dia_semana == 6)
    {
        printf("sábado, ");
    }

    // podria usar un switch para mejor legibilidad  y optimisacion. Además usar días max y después evaluaria desde el dia 1 al dia max, esa forma es más legible
    //  evaluar mes y dia del mes
    if (mes == 1 && (dia_mes >= 1 && dia_mes <= 31))
    {
        printf("%d de enero de ", dia_mes);
    }
    else if (mes == 2)
    {
        if (dia_mes >= 1 && dia_mes <= 28)
        {
            printf("%d de febrero de ", dia_mes);
        }
        else if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            if (dia_mes >= 1 && dia_mes <= 29)
            {
                printf("%d de febrero de ", dia_mes);
            }
        }
    }
    else if (mes == 3 && (dia_mes >= 1 && dia_mes <= 31))
    {
        printf("%d de marzo de ", dia_mes);
    }
    else if (mes == 4 && (dia_mes >= 1 && dia_mes <= 30))
    {
        printf("%d de abril de ", dia_mes);
    }
    else if (mes == 5 && (dia_mes >= 1 && dia_mes <= 31))
    {
        printf("%d de mayo de ", dia_mes);
    }
    else if (mes == 6 && (dia_mes >= 1 && dia_mes <= 30))
    {
        printf("%d de junio de ", dia_mes);
    }
    else if (mes == 7 && (dia_mes >= 1 && dia_mes <= 31))
    {
        printf("%d de julio de ", dia_mes);
    }
    else if (mes == 8 && (dia_mes >= 1 && dia_mes <= 31))
    {
        printf("%d de agosto de ", dia_mes);
    }
    else if (mes == 9 && (dia_mes >= 1 && dia_mes <= 30))
    {
        printf("%d de septiembre de ", dia_mes);
    }
    else if (mes == 10 && (dia_mes >= 1 && dia_mes <= 31))
    {
        printf("%d de octubre de ", dia_mes);
    }
    else if (mes == 11 && (dia_mes >= 1 && dia_mes <= 30))
    {
        printf("%d de noviembre de ", dia_mes);
    }
    else if (mes == 12 && (dia_mes >= 1 && dia_mes <= 31))
    {
        printf("%d de deciembre de ", dia_mes);
    }
    else
    {
        printf("Fecha no reconocida\n");
    }

    // evaluar  years
    if (year >= 1900)
    {
        printf("%d.\n", year);
    }
    else
    {
        printf("[Año invalido]\n");
    }
    return 0;
}