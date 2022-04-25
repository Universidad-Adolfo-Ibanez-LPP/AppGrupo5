#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libro.h"

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

void buscar_libro(){
    char titulo_buscar[50];
    char temp;
    printf("Ingresa el titulo del libro a buscar: ");
    scanf("%c",&temp);
    scanf("%[^\n]", titulo_buscar);
    k = 0;
    for (int n = 0; n < (row_count-1); n++){
        if (strcmp(titulo_buscar, parametros[n].titulo) == 0){
            printf("Se encontro el siguiente libro:\nTitulo: %s\nAutor: %s\nAño: %d\nEstante: %d\nSeccion: %s\nPiso: %d\nEdificio: %s\nSede: %s",
                   parametros[n].titulo, parametros[n].autor, parametros[n].anio, parametros[n].estante_numero, parametros[n].estante_seccion,
                   parametros[n].piso, parametros[n].edificio, parametros[n].sede);
            *f = 1;
        }
        else {
            if (n == row_count - 2 && k == 0){
                printf("No se encontro el libro.\n");
            }
        }
    }
}

void agregar_sede(char *argv[]){
    char sede_agregar[50];
    char temp;
    printf("Ingresa la sede que desea agregar: ");
    scanf("%c",&temp);
    scanf("%[^\n]", sede_agregar);
    for (int n = 0 ; n < (row_count-1); n++){
        if (strcmp(sede_agregar, strtok(parametros[n].sede, "\n")) == 0){
            printf("Se encontro el siguiente libro:\nTitulo: %s\nAutor: %s\nAño: %d\nEstante: %d\nSeccion: %s\nPiso: %d\nEdificio: %s\nSede: %s",
                   parametros[n].titulo, parametros[n].autor, parametros[n].anio, parametros[n].estante_numero, parametros[n].estante_seccion,
                   parametros[n].piso, parametros[n].edificio, parametros[n].sede);
            *f = 1;
        }

        if(strcmp(sede_agregar, strtok(parametros[n].sede, "\n")) != 0 && n == row_count-2 && k == 0){
            int no_add_sede;
            printf("No se ha escontrado la sede. Desea agregar un libro? ");
            printf("Ingrese 1 para confirmar o 0 para salir del programa: ");
            scanf("%d", &no_add_sede);
            if (no_add_sede == 0) {
                exit(0);
            }
            if (no_add_sede == 1) {
                agregar_libro(argv);
            }
        }
    }
}

void quitar_sede(char *argv[]) {
    char sede_eliminar[50];
    char temp;
    printf("Ingresa la sede a eliminar: ");
    scanf("%c", &temp);
    scanf("%[^\n]", sede_eliminar);
    for (int n = 0; n < (row_count - 1); n++) {
        if (strcmp(sede_eliminar, strtok(parametros[n].sede, "\n")) == 0) {
            printf("Se encontro el siguiente libro con esa sede:\nTitulo: %s\nAutor: %s\nAño: %d\nEstante: %d\nSeccion: %s\nPiso: %d\nEdificio: %s\nSede: %s",
                   parametros[n].titulo, parametros[n].autor, parametros[n].anio, parametros[n].estante_numero,
                   parametros[n].estante_seccion,
                   parametros[n].piso, parametros[n].edificio, parametros[n].sede);
            printf("\n\nSolo se puede eliminar una sede si no hay libros asociados a esa sede\n");

            int borrar;
            printf("Se encontro un libro asociado a la sede ingresada, si desea eliminarlo elija 1, para salir elija 0: ");
            scanf("%d", &borrar);
            if (borrar == 0){
                exit(0);
            }
            if (borrar == 1){
                FILE *fp_eliminar = fopen(argv[1], "w");
                fprintf(fp_eliminar, "titulo,autor,anio,estante_numero,estante_seccion,piso,edificio,sede\n");
                for (int n = 0; n < row_count-1; n++){
                    if (strcmp(sede_eliminar, strtok(parametros[n].sede, "\n")) == 0){
                        parametros[n].borrar_libro = 1;
                    }
                    if(parametros[n].borrar_libro != 1){
                        fprintf(fp_eliminar, "%s,%s,%d,%d,%s,%d,%s,%s\n", parametros[n].titulo, parametros[n].autor, parametros[n].anio, parametros[n].estante_numero,
                                parametros[n].estante_seccion, parametros[n].piso, parametros[n].edificio, parametros[n].sede);
                    }
                }
                fclose(fp_eliminar);
            }
        }

    }

}

void editar_libro(char* argv[]){
    char libro_editar[50];
    char temp;
    printf("Ingresa el titulo del libro a editar: ");
    scanf("%c",&temp);
    scanf("%[^\n]", libro_editar);
    for (int n = 0; n < (row_count-1); n++){
        if (strcmp(libro_editar, parametros[n].titulo) == 0){
            printf("Se encontro el siguiente libro:\nTitulo: %s\nAutor: %s\nAño: %d\nEstante: %d\nSeccion: %s\nPiso: %d\nEdificio: %s\nSede: %s",
                   parametros[n].titulo, parametros[n].autor, parametros[n].anio, parametros[n].estante_numero, parametros[n].estante_seccion,
                   parametros[n].piso, parametros[n].edificio, parametros[n].sede);
            int confirm;
            printf ("\nEs este el libro que desea editar?\nIngresa 0 para salir o 1 para confirmar: ");
            scanf("%d", &confirm);
            if (confirm == 0){
                exit(0);
            }
            if (confirm == 1) {
                int cambiar;
                printf("\nQue desea editar del libro:\nPulsar 1 para cambiar el titulo\nPulsar 2 para cambiar el autor\nPulsar 3 para cambiar el año"
                       "\nPulsar 4 para cambiar el numero estante\nPulsar 5 para cambiar la seccion\nPulsar 6 para cambiar el piso"
                       "\nPulsar 7 para cambiar el edificio\nPulsar 8 para cambiar el sede\n");
                printf("Ingrese opcion: ");
                scanf("%d", &cambiar);
                switch (cambiar) {
                    case 1: {
                        char titulo[50];
                        char temp;
                        printf("Ingresa el titulo nuevo: ");
                        scanf("%c", &temp);
                        scanf("%[^\n]", titulo);
                        FILE *fp_edicion = fopen(argv[1], "w");
                        fprintf(fp_edicion, "titulo,autor,anio,estante_numero,estante_seccion,piso,edificio,sede\n");
                        for (int i = 0; i < row_count - 1; i++) {
                            if (strcmp(libro_editar, parametros[i].titulo) == 0) {
                                strcpy(parametros[i].titulo, titulo);
                                for (int i = 0; i < row_count - 1; i++) {
                                    fprintf(fp_edicion, "%s,%s,%d,%d,%s,%d,%s,%s", parametros[i].titulo,
                                            parametros[i].autor, parametros[i].anio, parametros[i].estante_numero,
                                            parametros[i].estante_seccion, parametros[i].piso, parametros[i].edificio,
                                            parametros[i].sede);
                                }
                            }
                        }
                        fclose(fp_edicion);
                        break;
                    }
                    case 2: {
                        char autor[50];
                        char temp;
                        printf("Ingresa el autor nuevo: ");
                        scanf("%c", &temp);
                        scanf("%[^\n]", autor);
                        FILE *fp_edicion = fopen(argv[1], "w");
                        fprintf(fp_edicion, "titulo,autor,anio,estante_numero,estante_seccion,piso,edificio,sede\n");
                        for (int i = 0; i < row_count - 1; i++) {
                            if (strcmp(libro_editar, parametros[i].titulo) == 0) {
                                strcpy(parametros[i].autor, autor);
                                for (int i = 0; i < row_count - 1; i++) {
                                    fprintf(fp_edicion, "%s,%s,%d,%d,%s,%d,%s,%s", parametros[i].titulo, parametros[i].autor,
                                            parametros[i].anio, parametros[i].estante_numero,
                                            parametros[i].estante_seccion, parametros[i].piso, parametros[i].edificio,
                                            parametros[i].sede);
                                }
                            }
                        }
                        fclose(fp_edicion);
                        break;
                    }
                    case 3: {
                        int anio;
                        printf("Ingresa el año nuevo: ");
                        scanf("%d", &anio);
                        FILE *fp_edicion = fopen(argv[1], "w");
                        fprintf(fp_edicion, "titulo,autor,anio,estante_numero,estante_seccion,piso,edificio,sede\n");
                        for (int i = 0; i < row_count - 1; i++) {
                            if (strcmp(libro_editar, parametros[i].titulo) == 0) {
                                parametros[i].anio = anio;
                                for (int i = 0; i < row_count - 1; i++) {
                                    fprintf(fp_edicion, "%s,%s,%d,%d,%s,%d,%s,%s", parametros[i].titulo, parametros[i].autor,
                                            parametros[i].anio, parametros[i].estante_numero,
                                            parametros[i].estante_seccion, parametros[i].piso, parametros[i].edificio,
                                            parametros[i].sede);
                                }
                            }
                        }
                        fclose(fp_edicion);
                        break;
                    }
                    case 4: {
                        int num_estante;
                        printf("Ingresa el numero de estante nuevo: ");
                        scanf("%d", &num_estante);
                        FILE *fp_edicion = fopen(argv[1], "w");
                        fprintf(fp_edicion, "titulo,autor,anio,estante_numero,estante_seccion,piso,edificio,sede\n");
                        for (int i = 0; i < row_count - 1; i++) {
                            if (strcmp(libro_editar, parametros[i].titulo) == 0) {
                                parametros[i].estante_numero = num_estante;
                                for (int i = 0; i < row_count - 1; i++) {
                                    fprintf(fp_edicion, "%s,%s,%d,%d,%s,%d,%s,%s", parametros[i].titulo,
                                            parametros[i].autor,
                                            parametros[i].anio, parametros[i].estante_numero,
                                            parametros[i].estante_seccion, parametros[i].piso, parametros[i].edificio,
                                            parametros[i].sede);
                                }
                            }
                        }
                        fclose(fp_edicion);
                        break;
                    }
                    case 5: {
                        editar_seccion(argv);
                        break;
                    }
                    case 6: {
                        editar_piso(argv);
                        break;
                    }
                    case 7: {
                        char edificio[4];
                        char temp;
                        printf("Ingresa el edificio nuevo con sus iniciales, por ejemplo TH: ");
                        scanf("%c", &temp);
                        scanf("%s", edificio);
                        FILE *fp_edicion = fopen(argv[1], "w");
                        fprintf(fp_edicion, "titulo,autor,anio,estante_numero,estante_seccion,piso,edificio,sede\n");
                        for (int i = 0; i < row_count - 1; i++) {
                            if (strcmp(libro_editar, parametros[i].titulo) == 0) {
                                strcpy(parametros[i].edificio, edificio);
                                for (int i = 0; i < row_count - 1; i++) {
                                    fprintf(fp_edicion, "%s,%s,%d,%d,%s,%d,%s,%s", parametros[i].titulo, parametros[i].autor,
                                            parametros[i].anio, parametros[i].estante_numero,
                                            parametros[i].estante_seccion, parametros[i].piso, parametros[i].edificio,
                                            parametros[i].sede);
                                }
                            }
                        }
                        fclose(fp_edicion);
                        break;
                    }
                    case 8: {
                        editar_sede(argv);
                        break;
                    }
                }
            }
            break;
        }
        if ((strcmp(libro_editar, parametros[n].titulo) != 0) && (n == row_count-2)){
            printf("No se encontro el libro dentro del sistema");
        }
    }
}

void editar_sede(char* argv[]){
    char libro_editar[50];
    char temp;
    printf("Ingresa el titulo del libro de la sede a editar/cambiar: ");
    scanf("%c",&temp);
    scanf("%[^\n]", libro_editar);
    for (int n = 0; n < (row_count-1); n++) {
        if (strcmp(libro_editar, parametros[n].titulo) == 0) {
            int confirm;
            printf("\nEs este el libro que desea editar?\nIngresa 0 para salir o 1 para confirmar: ");
            scanf("%d", &confirm);
            if (confirm == 0) {
                exit(0);
            }
            if (confirm == 1) {
                char sede[50];
                char temp;
                printf("Ingresa la sede nueva: ");
                scanf("%c", &temp);
                scanf("%[^\n]", sede);
                FILE *fp_edicion = fopen(argv[1], "w");
                fprintf(fp_edicion, "titulo,autor,anio,estante_numero,estante_seccion,piso,edificio,sede\n");
                for (int i = 0; i < row_count - 1; i++) {
                    if (strcmp(libro_editar, parametros[i].titulo) == 0) {
                        strcat(sede, "\n");
                        strcpy(parametros[i].sede, sede);
                        for (int i = 0; i < row_count - 1; i++) {
                            fprintf(fp_edicion, "%s,%s,%d,%d,%s,%d,%s,%s", parametros[i].titulo, parametros[i].autor,
                                    parametros[i].anio, parametros[i].estante_numero,
                                    parametros[i].estante_seccion, parametros[i].piso, parametros[i].edificio,
                                    parametros[i].sede);
                        }
                    }

                }
                fclose(fp_edicion);
            }
            break;
        }
        if ((strcmp(libro_editar, parametros[n].titulo) != 0) && (n == row_count-2)) {
            printf("No se encontro el libro dentro del sistema");
        }
    }
}

void editar_seccion(char* argv[]){
    char libro_editar[50];
    char temp;
    printf("Ingresa el titulo del libro de la seccion a editar/cambiar: ");
    scanf("%c",&temp);
    scanf("%[^\n]", libro_editar);
    for (int n = 0; n < (row_count-1); n++) {
        if (strcmp(libro_editar, parametros[n].titulo) == 0) {
            int confirm;
            printf("\nEs este el libro que desea editar?\nIngresa 0 para salir o 1 para confirmar: ");
            scanf("%d", &confirm);
            if (confirm == 0) {
                exit(0);
            }
            if (confirm == 1) {
                char seccion[50];
                char temp;
                printf("Ingresa la seccion nueva: ");
                scanf("%c", &temp);
                scanf("%[^\n]", seccion);
                FILE *fp_edicion = fopen(argv[1], "w");
                fprintf(fp_edicion, "titulo,autor,anio,estante_numero,estante_seccion,piso,edificio,sede\n");
                for (int i = 0; i < row_count - 1; i++) {
                    if (strcmp(libro_editar, parametros[i].titulo) == 0) {
                        strcpy(parametros[i].estante_seccion, seccion);
                        for (int i = 0; i < row_count - 1; i++) {
                            fprintf(fp_edicion, "%s,%s,%d,%d,%s,%d,%s,%s", parametros[i].titulo, parametros[i].autor,
                                    parametros[i].anio, parametros[i].estante_numero,
                                    parametros[i].estante_seccion, parametros[i].piso, parametros[i].edificio,
                                    parametros[i].sede);
                        }
                    }
                }
                fclose(fp_edicion);
            }
            break;
        }
        if ((strcmp(libro_editar, parametros[n].titulo) != 0) && (n == row_count-2)) {
            printf("No se encontro el libro dentro del sistema");
        }
    }
}

void editar_piso(char* argv[]){
    char libro_editar[50];
    char temp;
    printf("Ingresa el titulo del libro del piso a editar/cambiar: ");
    scanf("%c",&temp);
    scanf("%[^\n]", libro_editar);
    for (int n = 0; n < (row_count-1); n++) {
        if (strcmp(libro_editar, parametros[n].titulo) == 0) {
            int confirm;
            printf("\nEs este el libro que desea editar?\nIngresa 0 para salir o 1 para confirmar: ");
            scanf("%d", &confirm);
            if (confirm == 0) {
                exit(0);
            }
            if (confirm == 1) {
                int piso;
                printf("Ingresa el piso nuevo: ");
                scanf("%d", &piso);
                FILE *fp_edicion = fopen(argv[1], "w");
                fprintf(fp_edicion, "titulo,autor,anio,estante_numero,estante_seccion,piso,edificio,sede\n");
                for (int i = 0; i < row_count - 1; i++) {
                    if (strcmp(libro_editar, parametros[i].titulo) == 0) {
                        parametros[i].piso = piso;
                        for (int i = 0; i < row_count - 1; i++) {
                            fprintf(fp_edicion, "%s,%s,%d,%d,%s,%d,%s,%s", parametros[i].titulo, parametros[i].autor,
                                    parametros[i].anio, parametros[i].estante_numero,
                                    parametros[i].estante_seccion, parametros[i].piso, parametros[i].edificio,
                                    parametros[i].sede);
                        }
                    }
                }
                fclose(fp_edicion);
            }
            break;
        }
        if ((strcmp(libro_editar, parametros[n].titulo) != 0) && (n == row_count-2)) {
            printf("No se encontro el libro dentro del sistema");
        }
    }
}

void agregar_seccion(char *argv[]){
    char seccion_agregar[50];
    char temp;
    printf("Ingresa la seccion de estante que desea agregar: ");
    scanf("%c",&temp);
    scanf("%[^\n]", seccion_agregar);
    for (int n = 0; n < (row_count-1); n++){
        if (strcmp(seccion_agregar, parametros[n].estante_seccion) == 0){
            printf("Se encontro el siguiente libro con la seccion ingresada\nTitulo: %s\nAutor: %s\nAño: %d\nEstante: %d\nSeccion: %s\nPiso: %d\nEdificio: %s\nSede: %s\n",
                   parametros[n].titulo, parametros[n].autor, parametros[n].anio, parametros[n].estante_numero, parametros[n].estante_seccion,
                   parametros[n].piso, parametros[n].edificio, parametros[n].sede);
            *f = 1;
        }
        if (strcmp(seccion_agregar, strtok(parametros[n].estante_seccion, "\n")) != 0 && (n == row_count-2) && (k == 0)){
            int no_add_seccion;
            printf("No se ha escontrado la seccion. Desea agregar un libro? ");
            printf("Ingrese 1 para confirmar o 0 para salir del programa: ");
            scanf("%d", &no_add_seccion);
            if (no_add_seccion == 0) {
                exit(0);
            }
            if (no_add_seccion == 1) {
                agregar_libro(argv);
            }
        }
    }
}

void quitar_seccion(char *argv[]) {
    char seccion_eliminar[50];
    char temp;
    printf("Ingresa la seccion a eliminar: ");
    scanf("%c", &temp);
    scanf("%[^\n]", seccion_eliminar);
    for (int n = 0; n < (row_count - 1); n++) {
        if (strcmp(seccion_eliminar, parametros[n].estante_seccion) == 0) {
            printf("Se encontro el siguiente libro en esa seccion:\nTitulo: %s\nAutor: %s\nAño: %d\nEstante: %d\nSeccion: %s\nPiso: %d\nEdificio: %s\nSede: %s",
                   parametros[n].titulo, parametros[n].autor, parametros[n].anio, parametros[n].estante_numero,
                   parametros[n].estante_seccion,
                   parametros[n].piso, parametros[n].edificio, parametros[n].sede);
            printf("\n\nSolo se puede eliminar una seccion si no hay libros asociados a esa seccion\n");

            int borrar;
            printf("Se encontro un libro asociado a la seccion ingresada, si desea eliminarlo elija 1, para salir elija 0: ");
            scanf("%d", &borrar);
            if (borrar == 0){
                exit(0);
            }
            if (borrar == 1){
                FILE *fp_eliminar = fopen(argv[1], "w");
                fprintf(fp_eliminar, "titulo,autor,anio,estante_numero,estante_seccion,piso,edificio,sede");
                for (int n = 0; n < row_count-1; n++){

                    if (strcmp(seccion_eliminar, parametros[n].estante_seccion)  == 0){
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
    }


}

void agregar_piso(char *argv[]){
    int piso_agregar;
    printf("Ingresa el piso que desea agregar: ");
    scanf("%d", &piso_agregar);
    k = 0;
    for (int n = 0; n < (row_count-1); n++){
        if (piso_agregar == parametros[n].piso){
            printf("Se encontro el siguiente libro con el piso ingresado\nTitulo: %s\nAutor: %s\nAño: %d\nEstante: %d\nSeccion: %s\nPiso: %d\nEdificio: %s\nSede: %s\n",
                   parametros[n].titulo, parametros[n].autor, parametros[n].anio, parametros[n].estante_numero, parametros[n].estante_seccion,
                   parametros[n].piso, parametros[n].edificio, parametros[n].sede);
            *f = 1;
        }

        if (piso_agregar != parametros[n].piso && n == row_count-2 && k == 0){
            int no_add_piso;
            printf("No se ha escontrado el piso. Desea agregar un libro? ");
            printf("Ingrese 1 para confirmar o 0 para salir del programa: ");
            scanf("%d", &no_add_piso);
            if (no_add_piso == 0) {
                exit(0);
            }
            if (no_add_piso == 1) {
                agregar_libro(argv);
            }
        }

    }
}

void quitar_piso(char *argv[]) {
    int piso_eliminar;
    printf("Ingresa el piso a eliminar: ");
    scanf("%d", &piso_eliminar);
    for (int n = 0; n < (row_count - 1); n++) {
        if (piso_eliminar == parametros[n].piso) {
            printf("Se encontro el siguiente libro en el piso ingresado:\nTitulo: %s\nAutor: %s\nAño: %d\nEstante: %d\nSeccion: %s\nPiso: %d\nEdificio: %s\nSede: %s",
                   parametros[n].titulo, parametros[n].autor, parametros[n].anio, parametros[n].estante_numero,
                   parametros[n].estante_seccion,
                   parametros[n].piso, parametros[n].edificio, parametros[n].sede);
            printf("\nComo se encontro por lo menos un libro asociado al piso ingresado, no se puede eliminar el piso a menos que elimine esos libros");
        }


    }
    int borrar;
    printf("\nSi desea eliminar el/los libros para eliminar el piso ingresado elija 1, sino elija 0 para salir del programa: ");
    scanf("%d", &borrar);
    if (borrar == 0) {
        exit(0);
    }
    if (borrar == 1) {
        FILE *fp_eliminar = fopen(argv[1], "w");
        fprintf(fp_eliminar, "titulo,autor,anio,estante_numero,estante_seccion,piso,edificio,sede\n");
        for (int n = 0; n < row_count - 1; n++) {

            if (piso_eliminar == parametros[n].piso) {
                parametros[n].borrar_libro = 1;
            }
            if (piso_eliminar != parametros[n].piso) {
                fprintf(fp_eliminar, "%s,%s,%d,%d,%s,%d,%s,%s", parametros[n].titulo, parametros[n].autor,
                        parametros[n].anio, parametros[n].estante_numero,
                        parametros[n].estante_seccion, parametros[n].piso, parametros[n].edificio, parametros[n].sede);
            }
        }
        fclose(fp_eliminar);
    }
}
