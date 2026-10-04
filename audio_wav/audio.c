#include <stdio.h>
#include <stdint.h> // save 1 byte
#include <stdbool.h>


#define DATA 0x61746164
typedef struct 
{
    int16_t canal_esquerdo;
    int16_t canal_direito;
} Estereo;
int main(void)
{
    uint32_t chunk_id = 0;
    uint32_t size_data = 0;

    FILE* input  = fopen("O Pintinho Piu - Amigovos - Amigovos (audio-extractor.net).wav", "rb");
    FILE* output = fopen("music_modificada.wav", "wb");

    if (input == NULL || output == NULL)
    {
        printf("algo deu errado\n");
        return 1;
    }

    bool no_ponteiro_input_NULL = (input != NULL);
    //bool leitura_wav = (fread(header,sizeof(header), 1, input) == 1);   

    while(fread(&chunk_id,sizeof(size_data), 1, input) == 1)
    {
        if (chunk_id == DATA)
        {
            //// 2. Leu "data"! Os próximos 4 bytes são o tamanho do áudio
            fread(&size_data, sizeof(size_data), 1, input);
            break; // Sai do loop pois já chegou ao áudio!
        }
        fseek(input, -3, SEEK_CUR); // sensor volta 3 se nao encontrar
    }
    long pos_atual = ftell(input); // Ex: 78
    long inicio = 0;
    long header_size = pos_atual - inicio; // 78 - 0 = 78 bytes!

    uint8_t header[header_size];
    fseek(input, 0, SEEK_SET);
    fread(header, sizeof(uint8_t), header_size, input);
    fwrite(header, sizeof(header), 1, output);
    //LEITURA OU MEXIDA NO AUDIO
    
    // amostras por segundos sao 16 bits ou seja 2 bytes

    Estereo buffer;
    buffer.canal_esquerdo = 0;
    buffer.canal_direito  = 0;

    while(fread(&buffer,sizeof(Estereo), 1,input) == 1)
    {
        int32_t res_esq = buffer.canal_esquerdo * 2;
        // Trava o áudio nos limites máximos do formato de 16 bits
        if (res_esq > 32767)  res_esq = 32767;
        if (res_esq < -32768) res_esq = -32768;
        buffer.canal_esquerdo = (int16_t)res_esq;


        int32_t res_dir = buffer.canal_direito * 2;
        // Trava o áudio nos limites máximos do formato de 16 bits
        if (res_dir > 32767)  res_dir = 32767;
        if (res_dir < -32768) res_dir = -32768;
        buffer.canal_direito = (int16_t)res_dir;

        fwrite(&buffer, sizeof(Estereo), 1, output);
    }

    fclose(input);  // Fecha o arquivo original
    fclose(output); // Libera o arquivo modificado para o sistema
}