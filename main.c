#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct libros{
    char titulo[50];
    char autor[50];
    int anio;
    int estante_numero;
    char estante_seccion[50];
    int piso;
    char edificio[4];
    char sede[50];
    int borrar_libro;
}biblioteca;


int opcion;
biblioteca parametros[999];
int row_count = 0;
int k = 0;
int *f = &k;

void menu();
int leer_archivo(char *argv[]);
void agregar_libro(char *argv[]);
void eliminar_libro(char *argv[]);
void agregar_sede(char *argv[]);
void quitar_sede(char *argv[]);
void editar_libro(char* argv[]);
void editar_sede(char* argv[]);
void editar_seccion(char* argv[]);
void editar_piso(char* argv[]);
void agregar_seccion(char *argv[]);
void quitar_seccion(char *argv[]);
void agregar_piso(char *argv[]);
void quitar_piso(char *argv[]);
void buscar_libro();

int main(int argc, char *argv[]){
    menu();
    leer_archivo(argv);
    if (opcion == 1){
        agregar_libro(argv);
    }
    if (opcion == 2){
        eliminar_libro(argv);
    }
    if (opcion == 3){
        agregar_sede(argv);
    }
    if (opcion == 4){
        quitar_sede(argv);
    }
    if(opcion == 5){
        editar_libro(argv);
    }
    if(opcion == 6){
        editar_sede(argv);
    }
    if(opcion == 7){
        editar_seccion(argv);
    }
    if(opcion == 8){
        editar_piso(argv);
    }
    if (opcion == 9){
        agregar_seccion(argv);
    }
    if (opcion == 10){
        quitar_seccion(argv);
    }
    if (opcion == 11){
        agregar_piso(argv);
    }
    if (opcion == 12){
        quitar_piso(argv);
    }
    if(opcion == 13){
        buscar_libro();
    }
    return 0;
}

void menu() {
    printf("\t\tMENU\n");
    printf("-------------------------------------\n");
    printf("Pulsar 1 para agregar un libro nuevo\n");
    printf("Pulsar 2 para quitar un libro\n");
    printf("Pulsar 3 para agregar una sede\n");
    printf("Pulsar 4 para quitar una sede (sólo si no tiene libros asociados)\n");
    printf("Pulsar 5 para editar un libro\n");
    printf("Pulsar 6 para cambiar un libro de sede\n");
    printf("Pulsar 7 para cambiar un libro de sección\n");
    printf("Pulsar 8 para cambiar un libro de piso\n");
    printf("Pulsar 9 para agregar secciones\n");
    printf("Pulsar 10 para eliminar una sección (sólo si no tiene libros asociados)\n");
    printf("Pulsar 11 para agregar pisos\n");
    printf("Pulsar 12 para quitar pisos (sólo si no tiene libros asociados)\n");
    printf("Pulsar 13 para buscar un libro\n");
    printf("Pulsar 0 para salir del programa\n");
    printf("-------------------------------------\n");
    printf("Ingrese su opción: ");
    scanf("%d", &opcion);
    if (opcion == 0){
        printf("Has seleccionado salir del programa");
        exit(0);
    }
}

int leer_archivo(char *argv[]){

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL){
        printf("No se pudo abrir el archivo: \n%s", argv[1]);
        exit(1);
    }
    char buff[1024];
    int field_count = 0;
    int i = 0;
    while(fgets(buff, 1024, fp)){
        field_count = 0;
        row_count++;
        if (row_count == 1)
            continue;
        char *field = strtok(buff, ",");
        while (field){
            if (field_count == 0)
                strcpy(parametros[i].titulo, field);
            if (field_count == 1)
                strcpy(parametros[i].autor, field);
            if (field_count == 2)
                parametros[i].anio = atoi(field);
            if (field_count == 3)
                parametros[i].estante_numero = atoi(field);
            if (field_count == 4)
                strcpy(parametros[i].estante_seccion, field);
            if (field_count == 5)
                parametros[i].piso = atoi(field);
            if (field_count == 6)
                strcpy(parametros[i].edificio, field);
            if (field_count == 7)
                strcpy(parametros[i].sede, field);
            if (field_count == 8)
                parametros[i].borrar_libro = 0;

            field = strtok(NULL, ",");
            field_count++;
        }
        i++;
    }
    fclose(fp);
    return row_count;
}



void agregar_libro(char *argv[]){
    FILE *fp = fopen(argv[1], "a");
    char titulo_add[50], autor_add[50], estante_seccion_add[20], edificio_add[4], sede_add[50];
    int anio_add, estante_numero_add, piso_add;

    printf("Por favor ingrese todos los campos requeridos.\nTitulo: ");
    scanf("%s", titulo_add);

    printf("Autor: ");
    scanf("%s", autor_add);

    printf("Año: ");
    scanf("%d", &anio_add);

    printf("Numero de estante: ");
    scanf("%d", &estante_numero_add);

    printf("Seccion de estante: ");
    scanf("%s", estante_seccion_add);

    printf("Piso: ");
    scanf("%d", &piso_add);

    printf("Edificio: ");
    scanf("%s", edificio_add);

    printf("Sede: ");
    scanf("%s", sede_add);

    fprintf(fp,"%s,%s,%d,%d,%s,%d,%s,%s\n", titulo_add, autor_add, anio_add, estante_numero_add,
            estante_seccion_add, piso_add, edificio_add, sede_add);
    fclose(fp);

}

void eliminar_libro(char *argv[]){

    char titulo_eliminar[50];
    char temp;
    printf("Ingresa el titulo del libro a eliminar: ");
    scanf("%c",&temp);
    scanf("%[^\n]", titulo_eliminar);
    f = 0;
    for (int n = 0; n < (row_count-1); n++){
        if (strcmp(titulo_eliminar, parametros[n].titulo) == 0){
            printf("Se encontro el siguiente libro:\nTitulo: %s\nAutor: %s\nAño: %d\nEstante: %d\nSeccion: %s\nPiso: %d\nEdificio: %s\nSede: %s",
                   parametros[n].titulo, parametros[n].autor, parametros[n].anio, parametros[n].estante_numero, parametros[n].estante_seccion,
                   parametros[n].piso, parametros[n].edificio, parametros[n].sede);;
        }
    }
    int borrar;
    printf ("\nEs este el libro que desea eliminar?\nIngresa 0 para salir o 1 para confirmar: ");
    scanf("%d", &borrar);
    if (borrar == 0){
        exit(0);
    }
    if (borrar == 1){
        FILE *fp_eliminar = fopen(argv[1], "w");
        fprintf(fp_eliminar, "titulo,autor,anio,estante_numero,estante_seccion,piso,edificio,sede\n");
        for (int n = 0; n < row_count-1; n++){
            printf("%d", parametros[n].titulo);
            if (strcmp(titulo_eliminar, parametros[n].titulo) == 0){
                parametros[n].borrar_libro = 1;
            }
            if(parametros[n].borrar_libro != 1){
                fprintf(fp_eliminar, "%s,%s,%d,%d,%s,%d,%s,%s", parametros[n].titulo, parametros[n].autor, parametros[n].anio, parametros[n].estante_numero,
                        parametros[n].estante_seccion, parametros[n].piso, parametros[n].edificio, parametros[n].sede);
            }
        }
        fclose(fp_eliminar);
    }

}
