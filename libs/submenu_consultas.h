#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#define tamanho 5

void listar_todos(struct consulta consultas[], int contador){
    system("cls");
    int i, tam_vet;

    printf("CRM: %s\nCPF: %s\nData: %s\nHora: %s\nDiagnostico: %s\n", consultas[0].crm, consultas[0].cpf, consultas[0].data, consultas[0].hora, consultas[0].diagnostico);

    // tam_vet = contador;

    // for(i = 0; i < tam_vet; i++)
    //     imprime_consulta(consultas, i);
}

// void imprime_consulta(struct consulta consultas[], int i){
//     int j, k;
//     j = i;
//     printf("CRM: %s\nCPF: %s\nData: %s\nHora: %s\nDiagnostico: %s\n", consultas[j].crm, consultas[j].cpf, consultas[j].data, consultas[j].hora, consultas[j].diagnostico);
//     for (k = 0; k < 10; k++)
//     printf("Medicamento %d: %s", k + 1, consultas[j].medicamentos[k]);
// }

char incluir(struct consulta consultas[], int *contador){
    char crm1[20], cpf1[18], data1[10], hora1[5], diagnostico1[100], medicamentos1[10][50];
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
        scanf("%s", medicamentos1[i]);
    }
    *strcpy(consultas[0].crm, crm1);
    *strcpy(consultas[0].cpf, cpf1);
    *strcpy(consultas[0].data, data1);
    *strcpy(consultas[0].hora, hora1);
    *strcpy(consultas[0].diagnostico, diagnostico1);
    *strcpy(consultas[0].medicamentos, medicamentos1);
    (*contador) ++;
    //printf("%s", consultas[0].crm);
    //menu_principal();
    return consultas;
}

void submenu_consultas(){
    int contador = 0;
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
        listar_todos(consultas, contador);
        break;
    case 2:
        //listar_um();
        break;
    case 3:
        consultas[0] = incluir(consultas, &contador); //passar cada posição do vetor como referencia
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
    
    // printf("Consulta cadastrada!");
    //menu_principal();
    // printf("%s", crm1);
    //printf("%s", consultas[0].crm);
}