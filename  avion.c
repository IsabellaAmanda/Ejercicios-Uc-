#include <stdio.h>

// Cuerpo principal

int main()
{

    // Entradas
    int gasoline, height, speed;

    // salidas
    int normal = 0, emergency = 0, urgency = 0, total = 0, min = 9999999;

    // Ciclo principal
    do
    {
        // ingresar datos del avion
        printf("========Condiciones del Avión========\n");
        printf("Ingrese la cantidad de combustible: ");
        scanf("%d", &gasoline);

        if (gasoline != 0)
        {
            printf("Ingrese la altitud en que viaja el avión: ");
            scanf("%d", &height);
            printf("Ingrese la velocidad que viaja el avión: ");
            scanf("%d", &speed);

            total++;

            // Restricciones (Condiciones)
            if (gasoline < 500 || (height < 2000 && (speed > 250)))
            {
                emergency++;
                if (emergency == 2)
                {
                    break;
                }
            }
            else if (gasoline <= 1200 || (speed > 300))
            {
                urgency++;
                printf("Riesgo de rebosar en la pista\n");
            }
            else
            {
                normal++;
            }

            if (gasoline < min)
                min = gasoline;

            // Riesgo
        }
        else
        {
            break;
        }

    } while (gasoline != 0);

    // mostrar salida
    printf("Cantidad de aviones de emergencia: %d\n", emergency);
    printf("Cantidad de aviones de urgencia: %d\n", urgency);
    printf("Cantidad de aviones sin problemas: %d\n", normal);
    printf("Total de Aviones : %d\n", total);

    if (total > 0)
    {
        printf("El avión con menor nivel de combistible total de %d\n", min);
    }

    return 0;
}