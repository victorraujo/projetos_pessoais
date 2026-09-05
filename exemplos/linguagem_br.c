

#include <stdio.h>
#include <stdbool.h>

// COMANDOS PRINCIPAIS
#define inicio main
#define vazio void
//___PRINCIPAIS DO C___
#define print printf // vem do printf
//--------scanf----------------------
#define pedir scanf // vem do scanf

//_____________________

//-------LOOPS--------
#define enquanto while
#define para for

// CONDICOES
#define se if
#define senao_se else if
#define senao else

//chaves
#define abre {
#define fecha }

typedef int inteiro;
typedef int inteiro_64;
typedef float decimal;
typedef bool sim_nao;
typedef char string;

inteiro inicio(vazio)
abre
    string nome[50]; 
    inteiro idade;
    inteiro peso;
    
    print("ficha pessoal. diga algumas coisas sobre voce\n");
    print("qual seu nome:\n ");
    pedir("%s", nome);

    print("idade: ");
    pedir("%i", &idade);
    
    print("peso: ");
    pedir("%i", &peso);

    print("ok sua ficha pessoal e: \n\n");
    print("nome = %s\n"
          "idade = %i\n"
          "peso = %i\n", nome, idade, peso);
fecha
