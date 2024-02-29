#include <stdio.h>

#include "funcoes.h"

double VALORES[TAMANHO];
int VALORES_POS = 0;
char OPERADORES[TAMANHO];
int OPERADORES_POS = 0;

bool estaCheiaValor(){
    return VALORES_POS == TAMANHO;
}
bool estaVaziaValor(){
    return VALORES_POS == 0;
}

bool estaCheiaOperador(){
    return OPERADORES_POS == TAMANHO;
}

bool estaVaziaOperador(){
    return OPERADORES_POS == 0;
}

bool popValor(){
    if(estaVaziaValor()){
        return false;
    }
    VALORES_POS--;
    return true;
}
bool popOperador(){
    if(estaVaziaOperador()){
        return false;
    }
    OPERADORES_POS--;
    return true;
}

bool pushValor(double valor){
    if(estaCheiaValor()){
        return false;
    }
    VALORES[VALORES_POS] = valor;
    VALORES_POS++;

    return true;
}

bool pushOperador(char operador){
    if(estaCheiaOperador()){
        return false;
    }
    OPERADORES[OPERADORES_POS] = operador;
    OPERADORES_POS++;

    return true;
}

double readValor(){
    return VALORES[VALORES_POS-1];
}
char readOperador(){
    return OPERADORES[OPERADORES_POS-1];
}

double calcular(double valor1, double valor2, char operador){
    switch (operador) {
        case '+':
            return valor2 + valor1;
            break;
        case '-':
            return valor2 - valor1;
            break;
        case '*':
            return valor2 * valor1;
            break;
        case '/':
            return valor2 / valor1;
            break;
        default:
            return -1234567;
            break;
    }
}

bool findMeu(char letra, char *str)
{
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == letra)
        {
            return true;
        }
    }
    return false;
}

bool mesmaOuMaiorPrecedencia(char op1, char op2) {
    if(op2 == '(' || op2 == ')')
    {
        return false;
    }
    if((op1 == '*' || op1 == '/') &&
       (op2 == '+' || op2 == '-'))
    {
        return false;
    }
    else
    {
        return true;
    }
}



double calcularVetor(char tokens[][20], int tamanho){
    char operadores[] = "+-*/()";
    char *ptr;
    double valor1, valor2;


    for(int i = 0; i < 100 && (strcmp(tokens[i], "") !=  0); i++)
    {
        //caso o tamanh for mair que 1 será numero
        if(strlen(tokens[i]) > 1) {
            pushValor(strtod(tokens[i], &ptr));
            continue;

        //caso seja exatamente igual a 1 ainda pode ser numero
        }else if (!findMeu(tokens[i][0], operadores)){
            pushValor(strtod(tokens[i], &ptr));
            continue;
        }

        //caso seja abrir parenteses
        if(strcmp(tokens[i], "(") == 0){
            pushOperador(tokens[i][0]);
            continue;
        }

        //caso seja fechar parenteses
        if(strcmp(tokens[i], ")") == 0){
            while(readOperador() != '('){
                valor1 = readValor();
                popValor();
                valor2 = readValor();
                popValor();
                pushValor(calcular(valor1, valor2, readOperador()));
                popOperador();
            }
            popOperador();
            continue;
        }

        //Caso operadores esteja vazio
        if(estaVaziaOperador()){
            pushOperador(tokens[i][0]);
            continue;
        }

        //Caso tenha mesma ou maior precendencia
        if(mesmaOuMaiorPrecedencia(tokens[i][0], readOperador())){
            valor1 = readValor();
            popValor();
            valor2 = readValor();
            popValor();
            pushValor(calcular(valor1, valor2, readOperador()));
            popOperador();
            pushOperador(tokens[i][0]);
        }else{
            pushOperador(tokens[i][0]);
        }


    }

    while (!estaVaziaOperador()){
        valor1 = readValor();
        popValor();
        valor2 = readValor();
        popValor();
        pushValor(calcular(valor1, valor2, readOperador()));
        popOperador();
    }


    return readValor();
}