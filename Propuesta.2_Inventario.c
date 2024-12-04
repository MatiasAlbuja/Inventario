#include<stdio.h>
#include<string.h>

int main(){

    int N;
    int Opc;
    int Opc1;
    int Opc2;
    int NF;

    printf("\nIngrese la cantidad de productos: "); //Ingreso de cantidad de producto 
    scanf("%d",&N); //Define la cantidad de filas
    getchar();

    float Inv[N][3]; //Matriz del inventario
    char Nombre[N][100]; //Matriz para ingreso de nombres

    NF=N; // EL numero de filas igual a N

    printf("\nTabla del inventario");

    for (int i = 0; i < N; i++) 
    {
        printf("\nIntroduce el nombre del producto: "); // Se introduce el nombre de los productos
        fgets(Nombre[i], sizeof(Nombre[i]), stdin);
        Nombre[i][strcspn(Nombre[i], "\n")] = '\0';

        for (int j = 1; j < 3; j++)
        {
            if (j==1)
            {
                printf("\nIngrese la Cantidad: "); // Ingreso de los valores
                scanf("%f",&Inv[i][j]); 
                getchar(); // Limpiar el buffer
            } else if (j==2) {
                printf("\nIngrese el Precio: ");
                scanf("%f",&Inv[i][j]); 
                getchar();
            }
            
        }

    }
    //Impresion de la matriz 

    for (int i = 0; i < N; i++) {
        printf("\n%d) Nombre: %s",i, Nombre[i]);
        for (int j = 1; j < 3; j++)
        {
            if (j==1)
            {
                printf("- Cantidad: %.2f", Inv[i][j]);
            }
            if (j==2)
            {
                printf("- Precio: %.2f", Inv[i][j]);
            }
        }
        
    }   

    printf("\nSeleccione que es lo que desea hacer: 1)Edicion / 2)Eliminacion / 3)Nada: "); // Menu de opciones
    scanf("%d",&Opc);
    switch (Opc)
    {
    case 1:
        printf("\nSeleccione la fila que desea editar: "); //El usuario sellecion la fila que desea modificar
        scanf("%d",&Opc1);
        getchar();

        for (int i = Opc1; i < Opc1+1; i++) // Se ingresa a esa fila para editar
        {
            // Se piden nuevamente los datos 
            printf("\nIntroduce el nuevo producto: "); 
            fgets(Nombre[Opc1], sizeof(Nombre[i]), stdin);
            Nombre[Opc1][strcspn(Nombre[Opc1], "\n")] = '\0';

            for (int j = 1; j < 3; j++)
            {
                if (j==1)
                {
                    printf("\nIngrese la Cantidad: "); 
                    scanf("%f",&Inv [i][j]); 
                    getchar();
                } else if (j==2) {
                    printf("\nIngrese el Precio: ");
                    scanf("%f",&Inv [i][j]); 
                    getchar();
                }
            
            }

        }  
        //Se imprime la nueva matriz con los cambios
        printf("\nLa nueva tabla con la edicion realizada");
            for (int i = 0; i < N; i++) {
                printf("\n%d Nombre: %s",i, Nombre[i]);
            
                for (int j = 1; j < 3; j++)
                {
                if (j==1)
                {
                    printf("- Cantidad: %.2f", Inv[i][j]);
                }
                if (j==2)
                {
                    printf("- Precio: %.2f", Inv[i][j]);
                }
            }
        
        }  
        break;
    case 2:

        printf("\nSeleccione la fila que desea eliminar: "); // El usuario selecciona la fila a eliminar
        scanf("%d",&Opc2);
        
        
        for (int i = Opc2; i < NF - 1; i++) { // Reccore la fila hacia la derecha 
            strcpy(Nombre[i], Nombre[i + 1]); 
            for (int j = 1; j < 3; j++) {
                Inv[i][j] = Inv[i + 1][j];
            }
        }

        NF--; // Reduce el numero de filas

        //Se imprime la nueva matriz con la eliminacion 

        printf("\nLa nueva tabla con la edicion realizada");

            for (int i = 0; i < NF; i++) {
                printf("\n%d Nombre: %s",i, Nombre[i]);
                for (int j = 1; j < 3; j++)
                {
                    if (j==1)
                    {
                        printf("- Cantidad: %.2f", Inv[i][j]);
                    }
                    if (j==2)
                    {
                        printf("- Precio: %.2f", Inv[i][j]);
                    }
                }
            } 
        break;

    case 3:
        //No realiza ningun proceso 
        return 0;

        break;
    default: 
        // Si el numero ingresado no es ninguno de los anteriores 
        
        printf("\nEl numero seleccionado no esta registrado");
        break;
    } 

}

