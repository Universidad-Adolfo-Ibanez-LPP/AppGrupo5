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
