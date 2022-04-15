#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define tamanho 5
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

int main()
{
    system("cls");
    int res = 0;
    printf("MENU\n\n");
    printf("1. Submenu de Medicos\n");
    printf("2. Submenu de Pacientes\n");
    printf("3. Submenu de Consultas\n");
    printf("4. Submenu Relatorios\n");
    printf("5. Sair\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &res);
    switch (res)
    {
    case 1:
        submenu_medicos();
        break;
    case 2:
        submenu_pacientes();
        break;
    case 3:
        submenu_consultas();
        break;
    case 4:
        submenu_relatorios();
        break;
    case 5:
        printf("\nsaindo...\n");
        break;
    
    default:
        printf("\nvalor invalido\n");
        break;
    }
}

void listar_todos(struct consulta consultas[]){
   system("cls");
   // int i, tam_vet;

   printf("CRM: %s\nCPF: %s\nData: %s\nHora: %s\nDiagnostico: %s\n", consultas[0].crm, consultas[0].cpf, consultas[0].data, consultas[0].hora, consultas[0].diagnostico);
   //printf(consultas[0].crm);
   // tam_vet = contador;

   // for(i = 0; i < tam_vet; i++)
   //     imprime_consulta(consultas, i);
}

// void listar_um(struct consulta consultas[]){
//     char crm1[20], cpf1[18], data1[10], hora1[6];
//     int i;

//     printf("Informe o CRM: ");
//     scanf("%s", &crm1);
//     printf("Informe o CPF do paciente: ");
//     scanf("%s", &cpf1);
//     printf("Informe a data da consulta: ");
//     scanf("%s", &data1);
//     printf("Informe a hora da consulta: ");
//     scanf("%s", &hora1);
    
//     i = busca_consulta(consultas, *crm1, *cpf1, *data1, *hora1);
//     if (i == -1)
//         printf("consulta não encontrada!");
//     else{
//         printf("Consulta: \n");
//         printf("CRM: %s\nCPF: %s\nData: %s\nHora: %s\nDiagnostico: %s\n", consultas[i].crm, consultas[i].cpf, consultas[i].data, consultas[i].hora, consultas[i].diagnostico);
//     }
// }

 void imprime_consulta(struct consulta consultas[], int i){
     int j, k;
     j = i;
     printf("CRM: %s\nCPF: %s\nData: %s\nHora: %s\nDiagnostico: %s\n", consultas[j].crm, consultas[j].cpf, consultas[j].data, consultas[j].hora, consultas[j].diagnostico);
     for (k = 0; k < 10; k++)
     printf("Medicamento %d: %s", k + 1, consultas[j].medicamentos[k]);
 }

void incluir_consulta(struct consulta consultas[], int *contador){
    char crm1[20], cpf1[18], data1[10], hora1[6], diagnostico1[100], medicamentos1[10][50];
    int i, num_medicamentos;

    system("cls");

    printf("Insira o CRM do medico: ");
    scanf("%s", &crm1);
    printf("Insira o CPF do paciente: ");
    scanf("%s", &cpf1);
    printf("Insira a data: ");
    scanf("%s", &data1);
    printf("Insira a hora: ");
    scanf("%s", &hora1);
    printf("Insira o diagnostico: ");
    scanf("%s", &diagnostico1);
    printf("Insira o numero de medicamentos: ");
    scanf("%d", &num_medicamentos);
    for(i = 0; i < num_medicamentos; i++){
        printf("Insira o medicamento numero %.0d: ", i + 1);
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

// int busca_consulta(struct consulta consultas[], char crm1, char cpf1, char data1, char hora1){
//     int i, posicao;
//     posicao = -1;

//     for (i = 0; i < tamanho; i++){
//         if (*consultas[i].crm == crm1 && *consultas[i].cpf == cpf1 && *consultas[i].data == data1 && *consultas[i].hora == hora1){
//             posicao = i;
//             break;
//         }
//     }
//     return posicao;
// }

void submenu_consultas(){
    int contador;
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
        listar_todos(consultas);
        
        break;
    case 2:
        //listar_um(consultas);
        break;
    case 3:
        incluir_consulta(consultas, &contador);
        break;
    case 4:
        //Alterar();
        break;
    case 5:
        //Alterar();
        break;
    case 6:
        //menu_principal();
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

int submenu_pacientes()
{
    system("cls");
    int res = 0;
    printf("SUBMENU PACIENTES\n\n");
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
        //listar_todos();
        break;
    case 2:
        //listar_um();
        break;
    case 3:
        //Incluir();
        break;
    case 4:
        //Alterar();
        break;
    case 5:
        //Alterar();
        break;
    case 6:
        //menu_principal();
        break;
    
    default:
        printf("\nvalor invalido\n");
        break;
    }
}

int submenu_medicos()
{
    int contador_medicos;
    system("cls");
    int res = 0;
    printf("SUBMENU MEDICOS\n\n");
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
        //listar_todos();
        break;
    case 2:
        //listar_um();
        break;
    case 3:
        Incluir_medico(&contador_medicos);
        break;
    case 4:
        //Alterar();
        break;
    case 5:
        //Alterar();
        break;
    case 6:
        //menu_principal();
        break;
    
    default:
        printf("\nvalor invalido\n");
        break;
    }
}

int Incluir_medico(struct consulta consultas[], int *contador_medicos){
    int contador = *contador_medicos;
    struct medico medicos[tamanho];
    char crm1[20], nome1[18], data_nascimento1[10], sexo1[6], especialidade1[100], universidade1[50], emails1[1][20], telefones1[1][10];
    int i, num_emails, num_telefones;

    system("cls");

    printf("Insira o CRM do medico: ");
    scanf("%s", &crm1);
    printf("Insira o nome do medico: ");
    scanf("%s", &nome1);
    printf("Insira a data de nascimento: ");
    scanf("%s", &data_nascimento1);
    printf("Insira o sexo: ");
    scanf("%s", &sexo1);
    printf("Insira a especialidade: ");
    scanf("%s", &especialidade1);
    printf("Insira a universidade que se formou: ");
    scanf("%s", &universidade1);
    printf("Insira a quantidade de emails que o medico possui: ");
    scanf("%s", &num_emails);
    printf("Insira a quantidade de telefones que o medico possui: ");
    scanf("%s", &num_telefones);
    for(i = 0; i < num_emails; i++){
        printf("Insira o email numero %d: ", i + 1);
        scanf("%s", &emails1[i]);
    }
    for(i = 0; i < num_emails; i++){
        printf("Insira o tefone numero %d: ", i + 1);
        scanf("%s", &telefones1[i]);
    }
    strcpy(medicos[contador].crm, crm1);
    strcpy(medicos[contador_medico].nome, nome1);
    strcpy(medicos[contador_medico].nascimento, data_nascimento1);
    strcpy(medicos[contador_medico].sexo, sexo1);
    strcpy(medicos[contador_medico].especialidade, especialidade1);
    strcpy(medicos[contador_medico].universidade, universidade1);
    strcpy(medicos[contador_medico].email, emails1);
    strcpy(medicos[contador_medico].telefone, telefones1);
    *contador_medico++;
    //printf("CRM: %s\nCPF: %s\nData: %s\nHora: %s\nDiagnostico: %s\n", consultas[0].crm, consultas[0].cpf, consultas[0].data, consultas[0].hora, consultas[0].diagnostico);
    //printf("%s", consultas[0].crm);
}


int submenu_relatorios()
{
    system("cls");
    int res = 0;
    printf("SUBMENU RELATORIOS\n\n");
    printf("1. Mostrar todos os dados de todos os medicos a partir de uma especialidade\n");
    printf("2. Mostrar todos os dados de todos os pacientes menores de X anos de idade\n");
    printf("3. Mostrar o CRM, o nome do medico, o CPF do paciente, o nome do paciente, data, hora, diagnostico e medicamentos para todas as consultas realizadas nos últimos X dias\n");
    printf("4. Voltar ao Menu Principal\n");
    printf("Digite o recurso desejado: ");
    scanf("%d", &res);
    switch (res)
    {
    case 1:
        //funcao();
        break;
    case 2:
        //lfuncao();
        break;
    case 3:
        //funcao();
        break;
    case 4:
        //menu_principal();
        break;
        
    
    default:
        printf("\nvalor invalido\n");
        break;
    }
}