#define ODS_H

#define MAX_ODS 17


typedef struct ods_status
{
    char *ods_nome; // nome ods
    int ods_numero; // numero da ods

    // metadados
    struct ods_status *esquerda;
    struct ods_status *direita;
} ods_status;

// assinaturas (estilo poo)
ods_status *criar_lista_ods(void);
void liberar_ods(ods_status *ods);

