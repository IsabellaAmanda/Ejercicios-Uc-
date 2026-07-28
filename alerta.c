#include <stdio.h>

//Cuerpo principal
int main(){
    //Files
    FILE *num, *salida;

    //Apertura de archivos
    num = fopen("num.txt", "r");
    salida = fopen("alerta.txt", "w");

    //Entradas
    int numero;

    //Variables de control
    int cont, limite, max;

    //Validacion
    if (num == NULL){
        printf("Error\n");
    }else{

        cont = 0;
        max = 0;

        //Lectura
        
        while (fscanf(num, "%d", &numero) == 1){

            cont++;
            
        
        }
        fclose(num);
        num = fopen("num.txt", "r");

        limite = 0;
        while (fscanf(num, "%d", &numero) == 1){

            limite++;
            if (numero > cont){
                
                break;
            }
            
        }
        fprintf(salida, "%d línea %d\n",numero, limite);
        printf("%d línea %d\n", numero, limite);

        //Cerrar archivo
        fclose(num);
        fclose(salida);
    }


}