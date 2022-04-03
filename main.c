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
