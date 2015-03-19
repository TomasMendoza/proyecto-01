/* Incluyo la librería standard input output, 
Tiene la función [printf] entre otras */
#include <stdio.h>

/* Incluyo la librería [array_helpers] */
/* Va con comillas dobles porque el archivo [.h] 
   se encuentra en la misma carpeta que este archivo */
#include "array_helpers.h"


/* La función [sumatoria].
   El primer argumento es un arreglo de enteros, y el segundo su longitud. 
   El tipo [unsigned int] representa los números enteros no negativos.
*/
int sumatoria(int *a, unsigned int length) {
    int s = 0;
    unsigned int i = 0;
    while (i < length) {
        s = s + a[i];
        i++;
    }
    return (s);
}

/* La función [productoria] */
int productoria(int *a, unsigned int length) {
    int p = 1;
    for (unsigned int i = 0; i < length; i++) {
        p = p * a[i];
    }
    return (p);
}

/* El tipo estructura suma_producto, con dos campos de tipo entero */
struct suma_producto {
    int suma;
    int producto;
};

/* Devuelve una estructura con la sumatoria y la productoria */
struct suma_producto sumatoria_productoria(int *a, unsigned int length) {
    int s = 0;
    int p = 1;
    unsigned int i = 0;
    while (i < length) {
        s = s + a[i];
        p = p * a[i];
        i++;
    }
    /* Declaro una variable de tipo struct suma_producto */
    struct suma_producto res;
    /* Con el operador punto [.] accedo a los campos de la estructura 
       En el campo [suma] guardo el valor de la sumatoria */
    res.suma = s;
    /* En el campo [producto] guardo el valor de la productoria */
    res.producto = p;
    return (res);
}

/* Función principal */
int main(void) {
    /* Declaro una variable que se usará para guardar el tamaño del arreglo */
    unsigned int tam = 0;
    /* Leer el arreglo ejemplo.in que está en la misma carpeta que este archivo*/
    int *a = array_from_file("ejemplo.in", &tam);
    /* Imprimo el arreglo en pantalla */
    array_dump(a, tam);
    /* Imprimo sólo la sumatoria */
    printf("La sumatoria es %d\n", sumatoria(a, tam));
    /* Imprimo sólo la productoria */
    printf("La productoria es %d\n", productoria(a, tam));
    /* Guardo en una variable la estructura devuelta
       por la función sumatoria_productoria */
    struct suma_producto resultado = sumatoria_productoria(a, tam);
    /* Imprimo los campos de la estructura */
    printf("La sumatoria es %d y la productoria es %d\n", resultado.suma,
           resultado.producto);
    /* Me despido */
    printf("Chau, gracias.\n");
    return 0;
}
