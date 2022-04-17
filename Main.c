#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define tamanho 5

//-----------	STRUCTS	  ----------------------------------------------------------------------

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

//-----------	FUNCOES MEDICOS	  ----------------------------------------------------------------------

void listar_todos_medicos(struct medico medicos[]){
	int voltar = 0;
	system("cls");
	printf("CRM, Nome, Data de Nascimento, Sexo, Especialidade, Universidade em que se formou, E-mails, Telefones\n");
	for(int i = 0; i < strlen(medicos); i++){
		printf("%s, %s, %s, %s, %s, %s", medicos[i].crm, medicos[i].nome, medicos[i].nascimento, medicos[i].sexo, medicos[i].especialidade, medicos[i].universidade);
	}
	printf("insira qualquer valor para voltar ao menu de medicos:");
	scanf("%d", &voltar);
}

void Incluir_medico(struct medico medicos[], int *contador_medicos){
   int contador = *contador_medicos;
   char crm1[20], nome1[18], data_nascimento1[10], sexo1[6], especialidade1[100], universidade1[50], emails1[1][20], telefones1[1][10];
   int i, num_emails, num_telefones;

   system("cls");

   printf("Insira o CRM do medico: ");
   scanf("%s", &crm1);
   for(int i = 0; i < strlen(medicos); i++){
	   if(crm1 == medicos[i].crm){
		   printf("Este crm já existe\n");
	   }
   }
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
   scanf("%d", &num_emails);
   printf("Insira a quantidade de telefones que o medico possui: ");
   scanf("%d", &num_telefones);
   for(i = 0; i < num_emails; i++){
       printf("Insira o email numero %d: ", i + 1);
       scanf("%s", &emails1[i]);
   }
   for(i = 0; i < num_emails; i++){
       printf("Insira o tefone numero %d: ", i + 1);
       scanf("%s", &telefones1[i]);
   }
   strcpy(medicos[contador].crm, crm1);
   strcpy(medicos[contador].nome, nome1);
   strcpy(medicos[contador].nascimento, data_nascimento1);
   strcpy(medicos[contador].sexo, sexo1);
   strcpy(medicos[contador].especialidade, especialidade1);
   strcpy(medicos[contador].universidade, universidade1);
   strcpy(medicos[contador].email, emails1);
   strcpy(medicos[contador].telefone, telefones1);
   (*contador_medicos)++;
}

//-----------	FUNCOES PACIENTES	  ----------------------------------------------------------------------




//-----------	FUNCOES CONSULTAS	  ----------------------------------------------------------------------

void listar_todos(struct consulta consultas[], int *contador_consultas){
	int i, j, contador = *contador_consultas;
	
	for (i = 0; i < contador; i++){
		printf("Consulta %d:", i + 1);
		printf("\n\tCRM: %s\n\tCPF: %s\n\tData: %s\n\tHora: %s\n\tDiagnóstico: %s", consultas[i].crm, consultas[i].cpf, consultas[i].data, consultas[i].hora, consultas[i].diagnostico);
		for(j = 0; j < consultas[i].num_medicamentos; j++){
			printf("\n\tMedicamento %d: %s", i + 1, consultas[i].medicamentos[j]);
		}
	}
}

void listar_um(struct consulta consultas[], int *contador_consultas)
{
    char crm1[20], cpf1[18], data1[10], hora1[6];
    int i, posicao, contador = *contador_consultas;

    printf("CRM: %s\nCPF: %s\nData: %s\nHora: %s\nDiagnostico: %s\n", consultas[0].crm, consultas[0].cpf, consultas[0].data, consultas[0].hora, consultas[0].diagnostico);

    printf("Informe o CRM: ");
    scanf("%s", &crm1);
    printf("Informe o CPF do paciente: ");
    scanf("%s", &cpf1);
    printf("Informe a data da consulta: ");
    scanf("%s", &data1);
    printf("Informe a hora da consulta: ");
    scanf("%s", &hora1);
    
    //printf("%s, %s, %s, %s", consultas[0].crm, consultas[0].cpf, consultas[0].data, consultas[0].hora);
    
    posicao = -1;
    for (i = 0; i < contador; i++){
    	printf("%s, %s, %s, %s\n", consultas[i].crm, consultas[i].cpf, consultas[i].data, consultas[i].hora);
    	if (consultas[i].crm == crm1 && consultas[i].cpf == cpf1 && consultas[i].data == data1 && consultas[i].hora == hora1){
            posicao = i;
            //break;
        }
	}
    
    if (posicao == -1)
        printf("Consulta não encontrada!");
    else{
        printf("Consulta: \n");
        printf("CRM: %s\nCPF: %s\nData: %s\nHora: %s\nDiagnostico: %s\n", consultas[posicao].crm, consultas[posicao].cpf, consultas[posicao].data, consultas[posicao].hora, consultas[posicao].diagnostico);
    }
}

void incluir_consulta(struct consulta consultas[], int *contador_consultas){
    char crm1[20], cpf1[18], data1[10], hora1[6], diagnostico1[100];
    int i, j, num_medicamentos1, busca_consulta = 1, contador = *contador_consultas;
    
    system("cls"); //limpando o terminal
	
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
    scanf("%d", &num_medicamentos1);
    
    char medicamentos1[num_medicamentos1][50];
    for(i = 0; i < num_medicamentos1; i++){
        printf("Insira o medicamento numero %.0d: ", i + 1);
        scanf("%s", &medicamentos1[i]);
    }
	
	//verificando se possui repeticoes
	i = 0;
	while (i < contador){
		if (crm1 == consultas[i].crm && cpf1 == consultas[i].cpf && data1 == consultas[i].data && hora1 == consultas[i].hora){
			printf("Consulta já cadastrada!");
			busca_consulta = 0;
		}
		i++;
	}
	
	i = contador;
	
	//adicionando no vetor
	if (busca_consulta == 1){
		strcpy(consultas[i].crm, crm1);
	    strcpy(consultas[i].cpf, cpf1);
	    strcpy(consultas[i].data, data1);
	    strcpy(consultas[i].hora, hora1);
	    strcpy(consultas[i].diagnostico, diagnostico1);
	    consultas[i].num_medicamentos = num_medicamentos1;
	    for (j = 0; j < num_medicamentos1; j++){
	    	strcpy(consultas[i].medicamentos[j], medicamentos1[j]);
		}
		(*contador_consultas)++; //incrementando o contador de consultas
	}
	//printf("CRM: %s\nCPF: %s\nData: %s\nHora: %s\nDiagnostico: %s\n", consultas[0].crm, consultas[0].cpf, consultas[0].data, consultas[0].hora, consultas[0].diagnostico);
}


//-----------	FUNCOES RELATORIOS	  ----------------------------------------------------------------------

//void especialidade(struct medico medicos[]){
//	int i, encontrou = 0;
//	char especialidade1[100];
//	printf("Insira a especialidade: ");
//	scanf("%s", &especialidade1);
//	
//	for (i = 0; i < tamanho; i++){
//		//printf("Especialidade %d: %s", i, medicos[i].especialidade);
//		if (medicos[i].especialidade == especialidade1){
//			printf("Aquiiiiiii");
//			printf("Médico %d: ", i + 1);
//			printf("\n\tCRM: ", medicos[i].crm);
//		    printf("\n\tNome: ", medicos[i].nome);
//		    printf("\n\tData de nascimento: ", medicos[i].nascimento);
//		    printf("\n\tSexo: ", medicos[i].sexo);
//		    printf("\n\tEspecialidade: ", medicos[i].especialidade);
//		    printf("\n\tUniversidade: ", medicos[i].universidade);
//		    printf("\n\tE-mail: ", medicos[i].email[0]);
//		    printf("\n\tTelefone: ", medicos[i].telefone[0]);
//		    
//		    if (encontrou == 0)
//		    	encontrou++;
//		}
//	}
//	
//	if (encontrou == 0)
//		printf("Nenhum médico com a especialidade %s foi encontrado!", especialidade1);
//}
//
//void menor_idade(struct medico medicos[]){
//	char idade[5], ano[10], ano2[10];
//	int i, a;
//	
//	printf("Insira a idade: ");
//	scanf("%s", idade);
//	
//	for (i = 0; i < tamanho; i++){
//		strcpy(ano, medicos[i].nascimento);
//		strrev(ano);
//		strncpy(ano2, ano, 4);
//		strrev(ano2);
//	}
//}


//-----------	MAIN	  ----------------------------------------------------------------------

int main()
{
	struct consulta consultas[tamanho];
	struct medico medicos[tamanho];
	int sair = 0, contador_consultas = 0, contador_medicos = 0;
	
	while (sair == 0){
		int sair_medico = 0, sair_paciente = 0, sair_consulta = 0, sair_relatorio = 0;
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
	        while(sair_medico == 0){
	        	
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
			        listar_todos_medicos(medicos);
			        break;
			    case 2:
			        //listar_um();
			        break;
			    case 3:
			        Incluir_medico(medicos, &contador_medicos);
			        break;
			    case 4:
			        //Alterar();
			        break;
			    case 5:
			        //Alterar();
			        break;
			    case 6:
			        sair_medico = 1;
			        break;
			    
			    default:
			        printf("\nvalor invalido\n");
			        break;
			    }
			}
	        break;
	        
	    case 2:
	        while(sair_paciente == 0){
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
			        sair_paciente = 1;
			        break;
			    
			    default:
			        printf("\nvalor invalido\n");
			        break;
			    }
			}
	        break;
	        
	    case 3:
	        while(sair_consulta == 0){
		    	//system("cls");
		
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
			        listar_todos(consultas, &contador_consultas);
			        break;
			    case 2: 
					listar_um(consultas, &contador_consultas);
			        break;
			    case 3: 
					incluir_consulta(consultas, &contador_consultas);
			        break;
			    case 4:
			        //Alterar();
			        break;
			    case 5:
			        //Alterar();
			        break;
			    case 6:
			        sair_consulta = 1;
			        break;
			    
			    default: printf("\nvalor invalido\n");
			        break;
			    }
			}
	        break;
	        
	    case 4:
	        while (sair_relatorio == 0){
	        	//system("cls");
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
			        //especialidade(medicos);
			        break;
			    case 2:
			        //menor_idade(medicos);
			        break;
			    case 3:
			        //funcao();
			        break;
			    case 4:
			        sair_relatorio = 1;
			        break;
			    
			    default:
			        printf("\nvalor invalido\n");
			        break;
			    }
			}
	        break;
	        
	    case 5:
	        printf("\nsaindo...\n");
	        sair = 1;
	        break;
	    
	    default:
	        printf("\nvalor invalido\n");
	        break;
	    }
	}
}
