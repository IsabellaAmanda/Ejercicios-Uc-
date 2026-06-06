#include <stdio.h>
#include <string.h>

// cuerpo principal
int main()
{
    // entradas y banderas
    int K, Q, band = 1;

    // cuentas (corriente, ahorro y activos liquidos), trasaccion (deposito o retiro)
    int tipo_cuenta, tipo_transaccion, cont_depositos, cont_retiro, num_noretiros, encontrado;
    // nombre de agencia
    char agencia[50], agencia_max[50];

    // contadores y acumuladores
    float monto, max_deposito, total_depositos, total_retiros, min_RETIRO, cuenta_ahorros;

    // ciclo del programa
    printf("¨\nHay una sucursal del Banco Universal en el estado (1-si/0-no)?: ");
    scanf("%d", &band);

    // ciclo de estados
    while (band)
    {
        // inicializar y reseteo de var de control por estados
        min_RETIRO = 9999999999.9;
        total_retiros = 0.0;
        cont_retiro = 0;

        printf("\nIngrese la cantidad de municipios en el estado: ");
        scanf("%d", &K);
        // el ciclo de los municipios
        for (int i = 0; i < K; i++)
        {
            // Por municipio, por eso se resetean aqui adentro
            cont_depositos = 0;
            total_depositos = 0.0;
            num_noretiros = 0;
            cuenta_ahorros = 0.0;
            max_deposito = -1;

            // ciclo para verificar que haya Agencias en el Municipio

            printf("\nIngrese la cantidad de Agencias en el Municipio: ");
            scanf("%d", &Q);

            encontrado = 0;
            // ciclo de agencias
            for (int j = 0; j < Q; j++)
            {
                // actualizar aqui adentro

                printf("\nIngrese el nombre de la Agencia: ");
                scanf(" %[^\n]", agencia);

                // ingresar tipo de transaccion, cuenta y monto a disponer
                printf("\nIngrese el tipo de cuenta (1.Corriente, 2.Ahorro, 3.Activos liquidos): ");
                scanf("%d", &tipo_cuenta);

                printf("\nIngrese el tipo de transacción (1.Deposito, 2.Retiro): ");
                scanf("%d", &tipo_transaccion);

                printf("\nIngrese el monto que va a depositar o retirar: ");
                scanf("%f", &monto);

                // por cada municipio
                if (tipo_transaccion == 1)
                {
                    cont_depositos++;
                    total_depositos += monto;
                }
                else if (tipo_transaccion == 2)
                {
                    cont_retiro++;
                    total_retiros += monto;
                }

                if (tipo_transaccion == 1 && tipo_cuenta == 2)
                {

                    if (monto > max_deposito)
                    {

                        max_deposito = monto;
                        strcpy(agencia_max, agencia);
                    }
                }

                if (tipo_transaccion == 2 && tipo_cuenta == 1)
                {
                    if (monto < min_RETIRO)
                    {
                        min_RETIRO = monto;
                    }
                }

                if (tipo_transaccion == 2 && tipo_cuenta == 3)
                {
                    encontrado = 1;
                }
            }

            if (!(encontrado))
            {
                num_noretiros++;
            }

            // Estadisticas
            printf("\nAgencia con mayor cantidad de depositos en cuenta de ahorro es %s con un monto: %.2f Bs depositados\n", agencia_max, max_deposito);

            printf("El municipio nro %d tiene una cantidad de depositos total: %d y %.2f Bs\n", i, cont_depositos, total_depositos);

            printf("El municipio %d tiene una cantidad de no retiros en cuentas de activos liquido: %d", i, num_noretiros);
        }
        // Estadisticas por estado
        printf("El Estado tiene una cantidad de retiros total: %d y %.2f Bs\n", cont_retiro, total_retiros);

        printf("\nAgencia con el monto menor  de retiros en cuenta corriente: %.2f Bs retirados\n", min_RETIRO);

        printf("¨\nHay una sucursal del Banco Universal en el Estado (1-si/0-no)?: ");
        scanf("%d", &band);
    }

    return 0;
}

// especificaciones

/*
Funcion principal de programa:
*Calcular las edisticas del Banco Universal
*Datos
* tienen K (municipios)
* tienen Q (Agencias)
*tipos de transacciones (depositos y retiros)
*tipos de cuentas (corriente, ahorro, activos liquidos)
*Salidas:
    * K -> name_max = max {Angencia} = > monto_maximo, deposito en cuenta de ahorro
    * cont_depositos y acum depositos por K agencias
    *Por k dar cont_retiros y acum_total
    * Monto_min = > retiros en tipo_corriente por Estado
    * indicar por cada k, cont de agencias donde no se tipo_retiro
*/

// leer todo antes de un espacio  " %[^\n]" el espacio de antes es para evitar caracteres raros