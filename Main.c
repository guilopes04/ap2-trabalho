#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
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
    int dia_nasc;
    int mes_nasc;
    int ano_nasc;
    char sexo;
    char plano[40];
    char email[2][50];
    char telefone[2][20];
};

struct consulta{
    char crm[20];
    char cpf[18];
    int dia;
    int mes;
    int ano;
    char hora[6];
    char diagnostico[100];
    char medicamentos[10][50];
    int num_medicamentos;
};

//-----------	FUNCOES MEDICOS	  ----------------------------------------------------------------------

void listar_todos_medicos(struct medico medicos[], int *contador_medicos){
	int voltar = 0;
	int contador = *contador_medicos;
	system("cls");
	for(int i = 0; i < contador; i++){
		//int num_emails = medicos[i].n_emails;
		//int num_telefones = medicos[i].n_telefones;
		int num_emails = 2;
		int num_telefones = 2;
		printf("\nMedico %d\n", i + 1);
		printf("CRM: %s\n", medicos[i].crm);
		printf("NOME: %s\n", medicos[i].nome);
		printf("NASCIMENTO: %d/%d/%d\n", medicos[i].dia_nasc, medicos[i].mes_nasc, medicos[i].ano_nasc);
		printf("SEXO: %c\n", medicos[i].sexo);
		printf("ESPECIALIDADE: %s\n", medicos[i].especialidade);
		printf("UNIVERSIDADE: %s\n", medicos[i].universidade);
		for(int j = 0; j < num_emails; j++){
			printf("EMAIL %d: %s\n", j + 1, medicos[i].email[j]);
		}
		for(int x = 0; x < num_telefones; x++){
			printf("TELEFONE %d: %s\n", x + 1, medicos[i].telefone[x]);
		}
	}
	printf("\ninsira qualquer valor para voltar ao menu de medicos:");
	scanf("%d", &voltar);

}

void listar_um_medico(struct medico medicos[], int *contador_medicos){
	int voltar = 0;
	char crm_desejado[10];
	int contador = *contador_medicos;
	system("cls");
	printf("Digite o crm do medico que deseja visualizar:");
	scanf("%s", &crm_desejado);
	int achou = 0;
	for(int i = 0; i < contador && achou == 0; i++){
		if(strcmp(crm_desejado, medicos[i].crm) == 0){
			//int num_emails = medicos[i].n_emails;
			//int num_telefones = medicos[i].n_telefones;
			int num_emails = 2;
			int num_telefones = 2;
			achou = 1;
			printf("CRM: %s\n", medicos[i].crm);
			printf("NOME: %s\n", medicos[i].nome);
			printf("NASCIMENTO: %d/%d/%d\n", medicos[i].dia_nasc, medicos[i].mes_nasc, medicos[i].ano_nasc);
			printf("SEXO: %c\n", medicos[i].sexo);
			printf("ESPECIALIDADE: %s\n", medicos[i].especialidade);
			printf("UNIVERSIDADE: %s\n", medicos[i].universidade);
			for(int j = 0; j < num_emails; j++){
				printf("EMAIL %d: %s\n", j + 1, medicos[i].email[j]);
			}
			for(int x = 0; x < num_telefones; x++){
				printf("TELEFONE %d: %s\n", x + 1, medicos[i].telefone[x]);
			}
		}
			
	}
	if(achou == 0){
		printf("crm não existe\n");
	}
	printf("\ninsira qualquer valor para voltar ao menu de medicos:");
	scanf("%d", &voltar);

}

void deleta_medico(struct medico medicos[], int *contador_medicos){
	system("cls");
	int contador = *contador_medicos;
	char crm_desejado[10];
	printf("Digite o crm do medico que deseja deletar:");
	scanf("%s", &crm_desejado);
	int achou = 0;
	for(int i = 0; i < contador && achou == 0; i++){
		if(strcmp(crm_desejado, medicos[i].crm) == 0){
			achou = 1;
			for(int x = i; x < contador; x++){
				medicos[x] = medicos[x + 1];
			}
		}	
	}
	if(achou == 0){
		printf("crm nao existente");
	}else{
		(*contador_medicos)--;
	}
}

void alterar_um_medico(struct medico medicos[], int *contador_medicos){
	int voltar = 0;
	char crm_desejado[10];
	int contador = *contador_medicos;
	char crm1[20], nome1[18], sexo1, especialidade1[100], universidade1[50], emails1[2][50], telefones1[2][20];
   	int i = 0, num_emails = 0, num_telefones = 0, dia_nasc1 = 0, mes_nasc1 = 0, ano_nasc1 = 0;
	system("cls");
	printf("Digite o crm do medico que deseja alterar:");
	scanf("%s", &crm_desejado);
	for(int i = 0; i < contador; i++){
		//int num_emails = medicos[i].n_emails;
		//int num_telefones = medicos[i].n_telefones;
		int num_emails = 2;
		int num_telefones = 2;
		int res = 0;
		if(strcmp(crm_desejado, medicos[i].crm) == 0){
			printf("Deseja alterar o nome(1 = sim/0 = nao)?");
			scanf("%d", &res);
			if(res == 1){
				printf("Insira o nome do medico:");
				scanf("%s", &nome1);
				strcpy(medicos[i].nome, nome1);
			}
			printf("Deseja alterar a data de nascimento(1 = sim/0 = nao)?");
			scanf("%d", &res);
			if(res == 1){
				printf("Insira a data de nascimento (xx xx xxxx):");
				scanf("%d %d %d", &dia_nasc1, &mes_nasc1, &ano_nasc1);
				medicos[i].dia_nasc = dia_nasc1;
		   		medicos[i].mes_nasc = mes_nasc1;
		   		medicos[i].ano_nasc = ano_nasc1;
			}
			printf("Deseja alterar o sexo(1 = sim/0 = nao)?");
			scanf("%d", &res);
			if(res == 1){
				printf("Insira o sexo: ");
		    	scanf("%s", &sexo1);
		    	medicos[i].sexo = sexo1;
			}
		    printf("Deseja alterar a especialidade(1 = sim/0 = nao)?");
			scanf("%d", &res);
			if(res == 1){
				printf("Insira a especialidade:");
		    	scanf("%s", &especialidade1);
		    	strcpy(medicos[i].especialidade, especialidade1);
			}
		    printf("Deseja alterar a universidade(1 = sim/0 = nao)?");
			scanf("%d", &res);
			if(res == 1){
				printf("Insira a universidade que se formou:");
			    scanf("%s", &universidade1);
				strcpy(medicos[i].universidade, universidade1);	
			}
		    printf("Deseja alterar os emails(1 = sim/0 = nao)?");
			scanf("%d", &res);
			if(res == 1){
				printf("Insira a quantidade de emails que o medico possui:");
		    	scanf("%d", &num_emails);
		    	medicos[i].n_emails = num_emails;
		    	for(i = 0; i < num_emails; i++){
		       		printf("Insira o email numero %d:", i + 1);
		       		scanf("%s", &emails1[i]);
		   		}
		   		for(int x = 0; x < num_emails; x++){
					strcpy(medicos[i].email[x], emails1[x]);
		   		}
			}
		    printf("Deseja alterar os telefones(1 = sim/0 = nao)?");
			scanf("%d", &res);
			if(res == 1){
				printf("Insira a quantidade de telefones que o medico possui:");
		    	scanf("%d", &num_telefones);
		    	medicos[i].n_telefones = num_telefones;
		   		for(i = 0; i < num_emails; i++){
		       		printf("Insira o telefone numero %d:", i + 1);
		       		scanf("%s", &telefones1[i]);
		   		}
		   		for(int x = 0; x < num_telefones; x++){
					strcpy(medicos[i].telefone[x], telefones1[x]);
		   		}
			}
		}	
	}
	printf("\ninsira qualquer valor para voltar ao menu de medicos:");
	scanf("%d", &voltar);

}

void Incluir_medico(struct medico medicos[], int *contador_medicos){
   int contador = *contador_medicos;
   char crm1[20], nome1[18], sexo1, especialidade1[100], universidade1[50], emails1[2][50], telefones1[2][20];
   int i = 0, num_emails = 0, num_telefones = 0, dia_nasc1 = 0, mes_nasc1 = 0, ano_nasc1 = 0;

   system("cls");

   printf("Insira o CRM do medico: ");
   scanf("%s", &crm1);
   for(int i = 0; i < contador; i++){
	   if(strcmp(crm1,medicos[i].crm) == 0){
		   printf("Este crm já existe\n");
	   }
   }
   printf("Insira o nome do medico:");
   scanf("%s", &nome1);
   printf("Insira a data de nascimento (xx xx xxxx):");
   scanf("%d %d %d", &dia_nasc1, &mes_nasc1, &ano_nasc1);
   printf("Insira o sexo: ");
   scanf("%s", &sexo1);
   printf("Insira a especialidade:");
   scanf("%s", &especialidade1);
   printf("Insira a universidade que se formou:");
   scanf("%s", &universidade1);
   printf("Insira a quantidade de emails que o medico possui:");
   scanf("%d", &num_emails);
   medicos[contador].n_emails = num_emails;
   printf("Insira a quantidade de telefones que o medico possui:");
   scanf("%d", &num_telefones);
   medicos[contador].n_telefones = num_telefones;
   for(i = 0; i < num_emails; i++){
       printf("Insira o email numero %d:", i + 1);
       scanf("%s", &emails1[i]);
   }
   for(i = 0; i < num_emails; i++){
       printf("Insira o telefone numero %d:", i + 1);
       scanf("%s", &telefones1[i]);
   }
   strcpy(medicos[contador].crm, crm1);
   strcpy(medicos[contador].nome, nome1);
   medicos[contador].dia_nasc = dia_nasc1;
   medicos[contador].mes_nasc = mes_nasc1;
   medicos[contador].ano_nasc = ano_nasc1;
   medicos[contador].sexo = sexo1;
   strcpy(medicos[contador].especialidade, especialidade1);
   strcpy(medicos[contador].universidade, universidade1);
   for(int i = 0; i < num_emails; i++){
		strcpy(medicos[contador].email[i], emails1[i]);
   }
   for(int i = 0; i < num_telefones; i++){
		strcpy(medicos[contador].telefone[i], telefones1[i]);
   }
   (*contador_medicos)++;
}
//-----------	FUNCOES PACIENTES	  ----------------------------------------------------------------------




//-----------	FUNCOES CONSULTAS	  ----------------------------------------------------------------------

void listar_todos(struct consulta consultas[], int *contador_consultas){
	int i, j, contador = *contador_consultas;
	
	for (i = 0; i < contador; i++){
		printf("Consulta %d:", i + 1);
		printf("\n\tCRM: %s\n\tCPF: %s\n\tData: %d/%d/%d\n\tHora: %s\n\tDiagnóstico: %s\n", consultas[i].crm, consultas[i].cpf, consultas[i].dia, consultas[i].mes, consultas[i].ano, consultas[i].hora, consultas[i].diagnostico);
		for(j = 0; j < consultas[i].num_medicamentos; j++){
			printf("\tMedicamento %d: %s\n", i + 1, consultas[i].medicamentos[j]);
		}
	}
}

void listar_um(struct consulta consultas[], int *contador_consultas)
{
    char crm1[20], cpf1[18], hora1[6];
    int i, posicao, contador = *contador_consultas, dia1, mes1, ano1;

    //printf("CRM: %s\nCPF: %s\nData: %s\nHora: %s\nDiagnostico: %s\n", consultas[0].crm, consultas[0].cpf, consultas[0].data, consultas[0].hora, consultas[0].diagnostico);

    printf("Informe o CRM (sem pontos ou traços): ");
    scanf("%s", &crm1);
    printf("Informe o CPF do paciente (sem pontos ou traços): ");
    scanf("%s", &cpf1);
    printf("Data:\n");
    printf("Informe o dia: ");
    scanf("%d", &dia1);
    printf("Informe o mês: ");
    scanf("%d", &mes1);
    printf("Informe o ano: ");
    scanf("%d", &ano1);
    printf("Informe a hora da consulta (sem pontos ou traços): ");
    scanf("%s", &hora1);
    
    //printf("%s, %s, %s, %s", consultas[0].crm, consultas[0].cpf, consultas[0].data, consultas[0].hora);
    
    posicao = -1;
    for (i = 0; i < contador; i++){
    	//printf("%s, %s, %s, %s\n", consultas[i].crm, consultas[i].cpf, consultas[i].data, consultas[i].hora);
    	if (strcmp(consultas[i].crm, crm1) == 0 && strcmp(consultas[i].cpf, cpf1) == 0 && consultas[i].dia == dia1 && consultas[i].mes == mes1 && consultas[i].ano == ano1 && strcmp(consultas[i].hora, hora1) == 0){
            posicao = i;
        }
	}
    
    if (posicao == -1)
        printf("Consulta não encontrada!");
    else{
        printf("Consulta: \n");
        printf("\tCRM: %s\n\tCPF: %s\n\tData: %d/%d/%d\n\tHora: %s\n\tDiagnostico: %s\n", consultas[posicao].crm, consultas[posicao].cpf, consultas[posicao].dia, consultas[posicao].mes, consultas[posicao].ano, consultas[posicao].hora, consultas[posicao].diagnostico);
    	for(i = 0; i < consultas[posicao].num_medicamentos; i++){
			printf("\tMedicamento %d: %s\n", posicao + 1, consultas[posicao].medicamentos[i]);
		}
	}
}

void incluir_consulta(struct consulta consultas[], int *contador_consultas){
    char crm1[20], cpf1[18], hora1[6], diagnostico1[100];
    int i, j, num_medicamentos1, dia1, mes1, ano1, busca_consulta = 1, contador = *contador_consultas;
    
    system("cls"); //limpando o terminal
	
    printf("Insira o CRM do médico (sem pontos ou traços): ");
    scanf("%s", &crm1);
    printf("Insira o CPF do paciente (sem pontos ou traços): ");
    scanf("%s", &cpf1);
    printf("Data:\n");
    printf("\tInsira o dia: ");
    scanf("%d", &dia1);
    printf("\tInsira o mês: ");
    scanf("%d", &mes1);
    printf("\tInsira o ano: ");
    scanf("%d", &ano1);
    printf("Insira a hora (sem pontos ou traços): ");
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
//	i = 0;
//	while (i < contador){
//		if (crm1 == consultas[i].crm && cpf1 == consultas[i].cpf && data1 == consultas[i].data && hora1 == consultas[i].hora){
//			printf("Consulta já cadastrada!");
//			busca_consulta = 0;
//		}
//		i++;
//	}
	
	i = contador;
	
	//adicionando no vetor
	if (busca_consulta == 1){
		strcpy(consultas[i].crm, crm1);
	    strcpy(consultas[i].cpf, cpf1);
//	    strcpy(consultas[i].data, data1);
		consultas[i].dia = dia1;
		consultas[i].mes = mes1;
		consultas[i].ano = ano1;
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

void filtra_especialidade(struct medico medicos[]){
	int i, j, encontrou = 0;
	char especialidade1[100];
	
	printf("Insira a especialidade: ");
	scanf("%s", &especialidade1);
	
	for (i = 0; i < tamanho; i++){
		if (strcmp(medicos[i].especialidade, especialidade1) == 0){		//busca no vetor medicos com a
			printf("\nMédico: ");										//especialidade e imprime
			printf("\n\tCRM: %s", medicos[i].crm);
		    printf("\n\tNome: %s", medicos[i].nome);
		    printf("\n\tData de nascimento: %d/%d/%d", medicos[i].dia_nasc, medicos[i].mes_nasc, medicos[i].ano_nasc);
		    printf("\n\tSexo: %c", medicos[i].sexo);
		    printf("\n\tEspecialidade: %s", medicos[i].especialidade);
		    printf("\n\tUniversidade: %s", medicos[i].universidade);
			for(j = 0; j < medicos[i].n_emails; j++){
				printf("\n\t%s", medicos[i].email[j]);
			}
			for(j = 0; j < medicos[i].n_telefones; j++){
				printf("\n\t%s", medicos[i].telefone[j]);
			}
		    encontrou++;
		}
	}
	if (encontrou == 0)
		printf("Nenhum médico com essa especialidade foi encontrado!");
}

void menor_idade(struct paciente pacientes[]){
	int i, j, idade, encontrou = 0, dia_atual = 17, mes_atual = 4, ano_atual = 2022;
	
	printf("Insira a idade: ");
	scanf("%d", &idade);
	
	for (i = 0; i < tamanho; i++){						//filtra a idade
		if (pacientes[i].ano_nasc >= ano_atual - idade){
			if (pacientes[i].mes_nasc <= mes_atual || pacientes[i].ano_nasc > ano_atual - idade){
				if (pacientes[i].mes_nasc == mes_atual && pacientes[i].dia_nasc <= dia_atual || pacientes[i].mes_nasc < mes_atual || pacientes[i].mes_nasc > mes_atual || pacientes[i].ano_nasc > ano_atual - idade){
					printf("\nPaciente:");
					printf("\n\tCPF: %s", pacientes[i].cpf);
					printf("\n\tNome: %s", pacientes[i].nome);
					printf("\n\tData de nascimento: %d/%d/%d", pacientes[i].dia_nasc, pacientes[i].mes_nasc, pacientes[i].ano_nasc);
					printf("\n\tSexo: %c", pacientes[i].sexo);
					printf("\n\tPlano: %s", pacientes[i].plano);
					for(j = 0; j < pacientes[i].n_emails; j++){
						printf("\n\t%s", pacientes[i].email[j]);
					}
					for(j = 0; j < pacientes[i].n_telefones; j++){
						printf("\n\t%s", pacientes[i].telefone[j]);
					}
					
					encontrou++;
				}
			}
		}
	}
	
	if (encontrou == 0)
		printf("Nenhum paciente encontrado!");
}

void filtra_consultas_dias(struct medico medicos[], struct paciente pacientes[], struct consulta consultas[], int contador_consultas, int contador_medicos, int contador_pacientes){
	int achou = 0, dias_filtro, dias_consulta, i, j, cont_consultas = contador_consultas, cont_medicos = contador_medicos, cont_pacientes = contador_pacientes;
	char crm1[20];
	
	printf("Insira o número de dias: ");
	scanf("%d", &dias_filtro);

	for (i = 0; i < cont_consultas; i++){
		dias_consulta = 0;
		
		if (consultas[i].ano == 2022){
			if(consultas[i].mes == 4)
				dias_consulta = consultas[i].dia;	
			else{
				dias_consulta = consultas[i].dia;
				for (j = consultas[i].mes; j > 0; j--)
					dias_consulta += 31;
			}
		}
		else{
			dias_consulta = consultas[i].dia;
			for (j = consultas[i].mes; j > 0; j--)
				dias_consulta += 31;
			for (j = consultas[i].ano; j < 2022; j++)
				dias_consulta += 365;
		}
		
		if (dias_consulta <= dias_filtro){
			printf("Consulta:\n");
			achou++;
			
			for(j = 0; j < cont_medicos; j++){
				if(strcmp(consultas[i].crm, medicos[j].crm) == 0)
					printf("\tCRM: %s\n\tNome do medico: %s", medicos[j].crm, medicos[j].nome);
			}
			
			for(j = 0; j < cont_pacientes; j++){
				if(strcmp(consultas[i].cpf, pacientes[j].cpf) == 0)
					printf("\n\tCPF: %s\n\tNome do paciente: %s", pacientes[j].cpf, pacientes[j].nome);
			}
			
			printf("\n\tData: %d/%d/%d\n\tHora: %s\n\tDiagnóstico: %s\n", consultas[i].dia, consultas[i].mes, consultas[i].ano, consultas[i].hora, consultas[i].diagnostico);
			for(j = 0; j < consultas[i].num_medicamentos; j++)
				printf("\tMedicamento %d: %s\n", j + 1, consultas[i].medicamentos[j]);
		}
	}
	if(achou == 0)
		printf("Nenhuma consulta encontrada!");
}


//-----------	MAIN	  ----------------------------------------------------------------------

int main()
{
	setlocale(LC_ALL,"portuguese");
	
	struct consulta consultas[tamanho];
	
	strcpy(consultas[0].crm, "31545455");
    strcpy(consultas[0].cpf, "786354");
    consultas[0].dia = 24;
    consultas[0].mes = 4;
    consultas[0].ano = 2022;
    strcpy(consultas[0].hora, "1050");
    strcpy(consultas[0].diagnostico, "dor de cabeça");
    strcpy(consultas[0].medicamentos[0], "advil");
    consultas[0].num_medicamentos = 1;
    
    strcpy(consultas[1].crm, "54648546");
    strcpy(consultas[1].cpf, "684664");
    consultas[1].dia = 17;
    consultas[1].mes = 5;
    consultas[1].ano = 2022;
    strcpy(consultas[1].hora, "0800");
    strcpy(consultas[1].diagnostico, "gripe");
    strcpy(consultas[1].medicamentos[0], "cimegripe");
    consultas[1].num_medicamentos = 1;
    
    strcpy(consultas[2].crm, "31545455");
    strcpy(consultas[2].cpf, "786354");
    consultas[2].dia = 30;
    consultas[2].mes = 8;
    consultas[2].ano = 2021;
    strcpy(consultas[2].hora, "1800");
    strcpy(consultas[2].diagnostico, "cefaleia");
    strcpy(consultas[2].medicamentos[0], "neusaldina");
    consultas[2].num_medicamentos = 1;
	
	struct medico medicos[tamanho];
	
	strcpy(medicos[0].crm, "31545455");
    strcpy(medicos[0].nome, "CArlos Alberto");
    strcpy(medicos[0].nascimento, "25/05/1990");
    medicos[0].sexo = 'M';
    strcpy(medicos[0].especialidade, "cardiologia");
    strcpy(medicos[0].universidade, "UFSCAR");
    strcpy(medicos[0].email[0], "medico1@gmail.com");
    strcpy(medicos[0].telefone[0], "3377-9988");
    
    strcpy(medicos[1].crm, "54648546");
    strcpy(medicos[1].nome, "Silvana Mendes");
    strcpy(medicos[1].nascimento, "15/11/1980");
    medicos[1].sexo = 'F';
    strcpy(medicos[1].especialidade, "oftalmologia");
    strcpy(medicos[1].universidade, "USP");
    strcpy(medicos[1].email[0], "medico2@gmail.com");
    strcpy(medicos[1].telefone[0], "99632-4587");
    
    strcpy(medicos[2].crm, "4548181");
    strcpy(medicos[2].nome, "Joao Silva");
    strcpy(medicos[2].nascimento, "05/07/1975");
    medicos[2].sexo = 'F';
    strcpy(medicos[2].especialidade, "oftalmologia");
    strcpy(medicos[2].universidade, "UNICAMP");
    strcpy(medicos[2].email[0], "medico3@gmail.com");
    strcpy(medicos[2].telefone[0], "98457-3241");
	
	
	struct paciente pacientes[tamanho];
	
	strcpy(pacientes[0].cpf, "684664");
    strcpy(pacientes[0].nome, "MArcos Aurelio");
    pacientes[0].dia_nasc = 25;
    pacientes[0].mes_nasc = 5;
    pacientes[0].ano_nasc = 1990;
    pacientes[0].sexo = 'M';
    strcpy(pacientes[0].plano, "unimed");
    strcpy(pacientes[0].email[0], "marcos1@gmail.com");
    strcpy(pacientes[0].telefone[0], "7887-1223");
	
	strcpy(pacientes[1].cpf, "786354");
    strcpy(pacientes[1].nome, "Rita Laura");
    //strcpy(pacientes[1].nascimento, "25/05/1990");
    pacientes[1].dia_nasc = 19;
    pacientes[1].mes_nasc = 4;
    pacientes[1].ano_nasc = 2003;
    pacientes[1].sexo = 'F';
    strcpy(pacientes[1].plano, "sao francisco");
    strcpy(pacientes[1].email[0], "rita@gmail.com");
    strcpy(pacientes[1].telefone[0], "4568-4864");
	
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
			    {
			    case 1:
			        listar_todos_medicos(medicos, &contador_medicos);
			        break;
			    case 2:
			        listar_um_medico(medicos, &contador_medicos);
			        break;
			    case 3:
			        Incluir_medico(medicos, &contador_medicos);
			        break;
			    case 4:
			        alterar_um_medico(medicos, &contador_medicos);
			        break;
			    case 5:
			        deleta_medico(medicos, &contador_medicos);
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
			    printf("\nSUBMENU RELATORIOS\n\n");
			    printf("1. Mostrar todos os dados de todos os medicos a partir de uma especialidade\n");
			    printf("2. Mostrar todos os dados de todos os pacientes menores de X anos de idade\n");
			    printf("3. Mostrar o CRM, o nome do medico, o CPF do paciente, o nome do paciente, data, hora, diagnóstico e medicamentos para todas as consultas realizadas nos últimos X dias\n");
			    printf("4. Voltar ao Menu Principal\n");
			    printf("Digite o recurso desejado: ");
			    scanf("%d", &res);
			    switch (res)
			    {
			    case 1:
			        filtra_especialidade(medicos);
			        break;
			    case 2:
			        menor_idade(pacientes);
			        break;
			    case 3:
			        filtra_consultas_dias(medicos, pacientes, consultas, contador_consultas, contador_medicos, contador_pacientes);
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
