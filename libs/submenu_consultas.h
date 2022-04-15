#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#define tamanho 5

//void listar_todos(struct consulta consultas[]){
//    system("cls");
//    // int i, tam_vet;
//
//    printf("CRM: %s\nCPF: %s\nData: %s\nHora: %s\nDiagnostico: %s\n", consultas[0].crm, consultas[0].cpf, consultas[0].data, consultas[0].hora, consultas[0].diagnostico);
//    //printf(consultas[0].crm);
//    // tam_vet = contador;
//
//    // for(i = 0; i < tam_vet; i++)
//    //     imprime_consulta(consultas, i);
//}

void listar_um(struct consulta consultas[]){
    char crm1[20], cpf1[18], data1[10], hora1[6];
    int i;

    printf("Informe o CRM: ");
    scanf("%s", &crm1);
    printf("Informe o CPF do paciente: ");
    scanf("%s", &cpf1);
    printf("Informe a data da consulta: ");
    scanf("%s", &data1);
    printf("Informe a hora da consulta: ");
    scanf("%s", &hora1);
    
    i = busca_consulta(consultas, crm1, cpf1, data1, hora1);
    if (i == -1)
        printf("consulta não encontrada!");
    else{
        printf("Consulta: \n");
        printf("CRM: %s\nCPF: %s\nData: %s\nHora: %s\nDiagnostico: %s\n", consultas[i].crm, consultas[i].cpf, consultas[i].data, consultas[i].hora, consultas[i].diagnostico);
    }
}

 void imprime_consulta(struct consulta consultas[], int i){
     int j, k;
     j = i;
     printf("CRM: %s\nCPF: %s\nData: %s\nHora: %s\nDiagnostico: %s\n", consultas[j].crm, consultas[j].cpf, consultas[j].data, consultas[j].hora, consultas[j].diagnostico);
     for (k = 0; k < 10; k++)
     printf("Medicamento %d: %s", k + 1, consultas[j].medicamentos[k]);
 }

void incluir(struct consulta consultas[], int *contador){
    char crm1[20], cpf1[18], data1[10], hora1[6], diagnostico1[100], medicamentos1[10][50];
    int i, num_medicamentos;

    system("cls");

    printf("Insira o CRM do médico: ");
    scanf("%s", &crm1);
    printf("Insira o CPF do paciente: ");
    scanf("%s", &cpf1);
    printf("Insira a data: ");
    scanf("%s", &data1);
    printf("Insira a hora: ");
    scanf("%s", &hora1);
    printf("Insira o diagnostico: ");
    scanf("%s", &diagnostico1);
    printf("Insira o número de medicamentos: ");
    scanf("%d", &num_medicamentos);
    for(i = 0; i < num_medicamentos; i++){
        printf("Insira o medicamento número %.0d: ", i + 1);
        scanf("%s", &medicamentos1[i]);
    }
    strcpy(consultas[0].crm, crm1);
    strcpy(consultas[0].cpf, cpf1);
    strcpy(consultas[0].data, data1);
    strcpy(consultas[0].hora, hora1);
    strcpy(consultas[0].diagnostico, diagnostico1);
    //strcpy(consultas[0].medicamentos, medicamentos1[0]);
    (*contador) ++;
    //printf("CRM: %s\nCPF: %s\nData: %s\nHora: %s\nDiagnostico: %s\n", consultas[0].crm, consultas[0].cpf, consultas[0].data, consultas[0].hora, consultas[0].diagnostico);
    //printf("%s", consultas[0].crm);
}

int busca_consulta(struct consulta consultas[], char crm1, char cpf1, char data1, char hora1){
    int i, posicao;
    posicao = -1;

    for (i = 0; i < tamanho; i++){
        if (*consultas[i].crm == crm1 && *consultas[i].cpf == cpf1 && *consultas[i].data == data1 && *consultas[i].hora == hora1){
            posicao = i;
            break;
        }
    }
    return posicao;
}

void submenu_consultas(){
    int contador = 0;
    int volta;
    struct consulta consultas[tamanho];

    system("cls");

    int res = 0;
    printf("SUBMENU CONSULTAS\n\n");
    printf("1. Listar Todos\n");
    printf("2. Listar Um Item\n");
    printf("3. Incluir Item\n");
    printf("4. Alterar Item\n");
    printf("5. Excluir Item\n");
    printf("6. Voltar ao Menu Principal\n");
    printf("Digite o recurso desejado: ");
    scanf("%d", &res);
    switch (res)
    {
    case 1:
        //listar_todos(consultas);
        
        break;
    case 2:
        listar_um(consultas);
        break;
    case 3:
        incluir(consultas, &contador);
        break;
    case 4:
        //Alterar();
        break;
    case 5:
        //Alterar();
        break;
    case 6:
        menu_principal();
        break;
    
    default:
        printf("\nvalor invalido\n");
        break;
    }
    
    volta = 0;
    printf("1 para voltar pro menu: ");
    scanf("%d", &volta);
    if (volta == 1)
        submenu_consultas();
}