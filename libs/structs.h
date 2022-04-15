#include <stdio.h>

struct medico{
    char crm[20];
    char nome[40];
    char nascimento[10];
    char sexo;
    char especialidade[100];
    char universidade[50];
    char email[2][50];
    char telefone[2][20];
};

struct paciente{
    char cpf[18];
    char nome[40];
    char nascimento[10];
    char sexo;
    char plano[40];
    char email[2][50];
    char telefone[2][20];
};

struct consulta{
    char crm[20];
    char cpf[18];
    char data[10];
    char hora[6];
    char diagnostico[100];
    char medicamentos[10][50];
};
