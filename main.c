#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "funcoes.h"

/*
 * Feito por Mariane Oliveira dos Santos e Pedro Silva Ribeiro
 */



bool find(char letra, char *str)
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

void stringParaVetor(char *line, char vec[][20], int tamanho)
{
    char trab[tamanho];
    char operacoes[] = "+-*/()";
    char letra;
    bool numero = false;
    bool str = false;
    int vecI = 0;
    int aux = 0;
    strcpy(trab, "");

    for(int i = 0; i < tamanho; i++)
    {
        letra = line[i];
        if((isdigit(letra) || letra=='.')  && !str)
        {
            if(!numero)
            {
                if(strlen(trab)!=0)
                {
                    strcpy(vec[vecI++],trab);
                    strcpy(trab, "");
                }
                numero = true;
                str = false;
            }
            aux = strlen(trab);
            trab[aux] = letra;
            trab[aux+1] = '\0';
        }
        else if(letra == ' ')
        {
            if(!str)
            {
                if(strlen(trab)!=0)
                {
                    strcpy(vec[vecI++],trab);
                    strcpy(trab, "");
                    numero = false;
                    str = false;
                }
            }
        }
        else if(find(letra, operacoes) != 0)
        {
            if(strlen(trab)!=0)
            {
                strcpy(vec[vecI++],trab);
                strcpy(trab, "");
            }
            aux = strlen(trab);
            trab[aux] = letra;
            trab[aux+1] = '\0';
            strcpy(vec[vecI++],trab);
            strcpy(trab, "");
            numero = false;
            str = false;
        }
    }
    if(strlen(trab)!=0)
    {
        strcpy(vec[vecI++],trab);
    }
}

void limpaVetor(char v[][20], int tamanho)
{
    for(int i = 0; i < tamanho; i++)
    {
        strcpy(v[i], "");
    }
}

int main() {

    printf("strl len de 'a' : %d\n", strlen("a"));
    char exp[100] = "";
    char vec[100][20] = {'\0'};

    limpaVetor(vec, 100);

    strcpy(exp,"( 2 + 2 ) / 5 * 3");

    stringParaVetor(exp, vec, 100);


    printf("\n resultado eh %lf\n", calcularVetor(vec, 100));


    return 0;
}
