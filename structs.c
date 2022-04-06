#include <stdio.h>

struct medico{
    char crm[20];
    char nome[40];
    char nascimento[15];
    char sexo[10];
    char especialidade[100];
    char universidade[50];
    char email[2][50];
    char telefone[2][20];
};

struct paciente{
    char cpf[18];
    char nome[40];
    char nascimento[15];
    char sexo[10];
    char plano[40];
    char email[2][50];
    char telefone[2][20];
};

struct consulta{
    char crm[20];
    char cpf[18];
    char data[15];
    char hora[6];
    char diagnostico[100];
    char medicamentos[5][50];
};
