#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//constantes
enum {
    TAMANHO = 100,
};

//Variaveis
extern double VALORES[TAMANHO];
extern int VALORES_POS;
extern char OPERADORES[TAMANHO];
extern int OPERADORES_POS;

bool popValor();
bool popOperador();

bool pushValor(double valor);
bool pushOperador(char operador);

double readValor();
char readOperador();

bool estaCheiaValor();
bool estaVaziaValor();

bool estaCheiaOperador();
bool estaVaziaOperador();

bool mesmaOuMaiorPrecedencia(char op1, char op2);

double calcular(double valor1, double valor2, char operador);

double calcularVetor(char tokens[][20], int tamanho);