/*
SistemaInventarios_ProyectoI.c
04/12/2024
Matias Albuja
Isaac Cordero
Daniela Muñoz

Descripción: 
Se desea desarrollar un sistema de inventarios, el cual implemente las siguientes funcionalidades:
-Ingresar, editar y eliminar productos.
-Listar productos ingresados.
*/

#include <stdio.h>
#include <string.h>

#define NumMaxProductos 50 //definir un valor para el numero maximo de productos.
#define IVA 0.15

//Funcion para calcular el valor total del producto
float ValorTotalProducto(float Cantidad, float PrecioUnidad){
    return Cantidad * ((PrecioUnidad*IVA)+PrecioUnidad); 
}

//Funcion para agregar nuevo producto
int NuevoProducto(char(*productos)[20], float *cantidades, float *valores, int *TotalProductos) {

    printf("Ingrese el nombre del producto: \n"); //ingresamos el nombre, cantidades y valores 
    fgets(productos[*TotalProductos], 20, stdin);
    productos[*TotalProductos][strcspn(productos[*TotalProductos], "\n")] = '\0';

    printf("Ingrese la cantidad de unidades: \n");
    scanf("%f", &cantidades[*TotalProductos]);

    printf("Ingrese el valor por unidad: \n");
    scanf("%f", &valores[*TotalProductos]);
    
    (*TotalProductos)++;//aumenta el numero de productos
    return *TotalProductos;
}

void ListaProductos(char (*productos)[20], float *cantidades, float *valores, int TotalProductos) {
    if(TotalProductos==0){
        printf("Primero ingrese productos para poder listarlos.\n");
        return;
    }

    printf("\nListado de productos:\n");
    printf("\t");
    for(int i=1; i<=50; i++){
        printf("-");
    }
    printf("\n");
    for(int i=0; i<TotalProductos; i++) {
        float ValorTotal=ValorTotalProducto(cantidades[i], valores[i]);
        printf("%s\tCantidad: %.2f\t Precio unitario: %.2f\t Valor con IVA: %.2f\n", productos[i], cantidades[i], valores[i], ValorTotal);
    }
    printf("\t");
    for(int i=1; i<=50; i++){
        printf("-");
    }
}

void EditarProducto(char (*productos)[20], float *cantidades, float *valores, int TotalProductos){
    int Editar;
    printf("Ingrese el número del producto a cambiar:\n");
    scanf("%d", &Editar); // Leer el número del producto
    getchar(); // Limpiar el buffer

    if (Editar<1 || Editar>TotalProductos) { // Verificar si el indice Editar es válido
        printf("Ese valor no existe.\n");
        return;
    }
    Editar--;//Resta el indice para que se reestablesca

    printf("Ingrese el nuevo nombre del producto o deje en blanco si no va a cambiar: \n");
    char nuevoNombre[20]; //declarar nuevo arreglo para el cambio de nombre
    fgets(nuevoNombre, 20, stdin);
    if(strlen(nuevoNombre)>1){ //si la longitud es mayor a 1, se registra un nuevo nombre.
        nuevoNombre[strcspn(nuevoNombre, "\n")] = '\0';
        strcpy(productos[Editar], nuevoNombre); //Funcion para copiar el nuevo nombre en el arreglo producto con el indice q se quiere editar.
    }

    printf("Ingrese la nueva cantidad o 0 para mantener: \n");
    float nuevaCantidad;
    scanf("%f", &nuevaCantidad);
    if(nuevaCantidad!=0){
        cantidades[Editar]=nuevaCantidad;
    }

    printf("Ingrese el nuevo valor unitario o 0 para mantener: \n");
    float nuevoValor;
    scanf("%f", &nuevoValor);
    if(nuevoValor!=0){
        valores[Editar]=nuevoValor;
    }
}

void EliminarProductos(char (*productos)[20], float *cantidades, float *valores, int *TotalProductos){
    int Eliminar;
    printf("Ingrese el numero del producto a eliminar:\n");
    scanf("%d",&Eliminar); //variable Eliminar sirve como cambio en los indices del arreglo.
    getchar();

    if(Eliminar<1 || Eliminar>*TotalProductos){//controlar valores negativos y excedentes
        printf("El valor a eliminar no se encuentra.\n");
    }
    Eliminar--; //restamos 1 para utilizar el valor correcto del indice.

    for(int i=Eliminar; i<*TotalProductos-1; i++){//Lazo for para realizar la oeracion de eliminar el producto
        strcpy(productos[i], productos[i+1]); //Funcion para copiar el contenido de la siguiente fila en la fila donde se quiere eliminar.
        cantidades[i]=cantidades[i+1]; 
        valores[i]=valores[i+1];
    }
    (*TotalProductos)--;//Resta la cantidad de productos
}
    

int main() {
    //Ingreso de variables
    char Productos[NumMaxProductos][20]; //Matriz para el nombre de los productos, con el maximo de lo que se defina en NumMaxProductos.
    float Cantidades[NumMaxProductos]; //Cantidades con el maximo de lo que se defina en NumMaxProductos.
    float Valores[NumMaxProductos];
    int TotalProductos;
    int Opcion;

    printf("\t Sistema de inventario para tienda minorista de viveres.\n");
    printf("\t\t");
    for(int i=1; i<=35; i++){
        printf("-");
    }

    do{
        //Menu de opciones
        printf("\nSeleccione la opción que desea realizar:\n1.Agregar producto\n2.Listar productos\n3.Editar producto\n4.Eliminar producto\n5.Finalizar\n");
        scanf("%d", &Opcion);
        getchar();//limpiar el buffer

        switch(Opcion){
            case 1:
                NuevoProducto(Productos, Cantidades, Valores, &TotalProductos);
                break;
            case 2:
                ListaProductos(Productos, Cantidades, Valores, TotalProductos);
                break;
            case 3:
                EditarProducto(Productos, Cantidades, Valores, TotalProductos);
                break;
            case 4:
                EliminarProductos(Productos, Cantidades, Valores, &TotalProductos);
                break;
            case 5:
                printf("Adiós!\n");
                break;
            default:
                printf("No existe esta opción, intente otra vez.\n");
        }
    }while(Opcion!=5);
    return 0;
}