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
    int dia_nasc;
    int mes_nasc;
    int ano_nasc;
    char sexo;
    char especialidade[100];
    char universidade[50];
    char email[2][50];
    int n_emails;
    char telefone[2][20];
    int n_telefones;
};

struct paciente{
    char cpf[18];
    char nome[40];
    int dia_nasc;
    int mes_nasc;
    int ano_nasc;
    char sexo;
    char plano[40];
    int n_emails;
   	char email[2][50];
    char telefone[2][20];
    int n_telefones;
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
	int voltar = 0, i, j, x;
	int contador = *contador_medicos;
	system("cls");
	for(i = 0; i < contador; i++){
		int num_emails = medicos[i].n_emails;
		int num_telefones = medicos[i].n_telefones;
		printf("\nMedico %d\n", i + 1);
		printf("CRM: %s\n", medicos[i].crm);
		printf("NOME: %s\n", medicos[i].nome);
		printf("NASCIMENTO: %d/%d/%d\n", medicos[i].dia_nasc, medicos[i].mes_nasc, medicos[i].ano_nasc);
		printf("SEXO: %c\n", medicos[i].sexo);
		printf("ESPECIALIDADE: %s\n", medicos[i].especialidade);
		printf("UNIVERSIDADE: %s\n", medicos[i].universidade);
		for(j = 0; j < num_emails; j++){
			printf("EMAIL %d: %s\n", j + 1, medicos[i].email[j]);
		}
		for(x = 0; x < num_telefones; x++){
			printf("TELEFONE %d: %s\n", x + 1, medicos[i].telefone[x]);
		}
	}
	printf("\ninsira qualquer valor para voltar ao menu de medicos:");
	scanf("%d", &voltar);

}

void listar_um_medico(struct medico medicos[], int *contador_medicos){
	int voltar = 0, i, j, x;
	char crm_desejado[10];
	int contador = *contador_medicos;
	system("cls");
	printf("Digite o crm do medico que deseja visualizar:");
	scanf("%s", &crm_desejado);
	int achou = 0;
	for(i = 0; i < contador && achou == 0; i++){
		if(strcmp(crm_desejado, medicos[i].crm) == 0){
			int num_emails = medicos[i].n_emails;
			int num_telefones = medicos[i].n_telefones;
			achou = 1;
			printf("CRM: %s\n", medicos[i].crm);
			printf("NOME: %s\n", medicos[i].nome);
			printf("NASCIMENTO: %d/%d/%d\n", medicos[i].dia_nasc, medicos[i].mes_nasc, medicos[i].ano_nasc);
			printf("SEXO: %c\n", medicos[i].sexo);
			printf("ESPECIALIDADE: %s\n", medicos[i].especialidade);
			printf("UNIVERSIDADE: %s\n", medicos[i].universidade);
			for(j = 0; j < num_emails; j++){
				printf("EMAIL %d: %s\n", j + 1, medicos[i].email[j]);
			}
			for(x = 0; x < num_telefones; x++){
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
	int i, x;
	char crm_desejado[10];
	printf("Digite o crm do medico que deseja deletar:");
	scanf("%s", &crm_desejado);
	int achou = 0;
	for(i = 0; i < contador && achou == 0; i++){
		if(strcmp(crm_desejado, medicos[i].crm) == 0){
			achou = 1;
			for(x = i; x < contador; x++){
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
   	int i = 0, x, num_emails = 0, num_telefones = 0, dia_nasc1 = 0, mes_nasc1 = 0, ano_nasc1 = 0;
	system("cls");
	printf("Digite o crm do medico que deseja alterar:");
	scanf("%s", &crm_desejado);
	for(i = 0; i < contador; i++){
		int num_emails = medicos[i].n_emails;
		int num_telefones = medicos[i].n_telefones;
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
		   		for(x = 0; x < num_emails; x++){
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
		   		for(x = 0; x < num_telefones; x++){
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
	medicos = (struct medico *)realloc(medicos, (contador + 1)*sizeof(struct medico)); // aloca mais uma posição no vetor
	char crm1[20], nome1[18], sexo1, especialidade1[100], universidade1[50], emails1[2][50], telefones1[2][20];
	int i = 0, num_emails = 0, num_telefones = 0, dia_nasc1 = 0, mes_nasc1 = 0, ano_nasc1 = 0;
	int achou = 0;

	system("cls");
	fflush(stdin);
	printf("Insira o CRM do medico: ");
	scanf("%s", &crm1);
	for(i = 0; i < contador; i++){
		if(strcmp(crm1,medicos[i].crm) == 0){
			printf("Este crm já existe\n");
			achou = 1;
		}
	}
	if(achou == 0){
		fflush(stdin);
		printf("Insira o nome do medico:");
		gets(&nome1);
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
		for(i = 0; i < num_emails; i++){
			strcpy(medicos[contador].email[i], emails1[i]);
		}
		for(i = 0; i < num_telefones; i++){
			strcpy(medicos[contador].telefone[i], telefones1[i]);
		}
		(*contador_medicos)++;
	}
   
}
//-----------	FUNCOES PACIENTES	  ----------------------------------------------------------------------

void listar_todos_pacientes(struct paciente pacientes[], int *contador_pacientes){
	int voltar = 0, i, j, x;
	int contador = *contador_pacientes;
	system("cls");
	for(i = 0; i < contador; i++){
		int num_emails = pacientes[i].n_emails;
		int num_telefones = pacientes[i].n_telefones;
		printf("\nPaciente %d\n", i + 1);
		printf("CPF: %s\n", pacientes[i].cpf);
		printf("NOME: %s\n", pacientes[i].nome);
		printf("NASCIMENTO: %d/%d/%d\n", pacientes[i].dia_nasc, pacientes[i].mes_nasc, pacientes[i].ano_nasc);
		printf("SEXO: %c\n", pacientes[i].sexo);
		printf("PLANO: %s\n", pacientes[i].plano);
		for(j = 0; j < num_emails; j++){
			printf("EMAIL %d: %s\n", j + 1, pacientes[i].email[j]);
		}
		for(x = 0; x < num_telefones; x++){
			printf("TELEFONE %d: %s\n", x + 1, pacientes[i].telefone[x]);
		}
	}
	printf("\ninsira qualquer valor para voltar ao menu de medicos:");
	scanf("%d", &voltar);

}

void listar_um_paciente(struct paciente pacientes[], int *contador_pacientes){
	int voltar = 0, i, j, x;
	char cpf_desejado[10];
	int contador = *contador_pacientes;
	system("cls");
	printf("Digite o cpf do paciente que deseja visualizar:");
	scanf("%s", &cpf_desejado);
	int achou = 0;
	for(i = 0; i < contador && achou == 0; i++){
		if(strcmp(cpf_desejado, pacientes[i].cpf) == 0){
			int num_emails = pacientes[i].n_emails;
		    int num_telefones = pacientes[i].n_telefones;
			achou = 1;
			printf("CPF: %s\n", pacientes[i].cpf);
			printf("NOME: %s\n", pacientes[i].nome);
			printf("NASCIMENTO: %d/%d/%d\n", pacientes[i].dia_nasc, pacientes[i].mes_nasc, pacientes[i].ano_nasc);
			printf("SEXO: %c\n", pacientes[i].sexo);
			printf("PLANO: %s\n", pacientes[i].plano);
			for(j = 0; j < num_emails; j++){
				printf("EMAIL %d: %s\n", j + 1, pacientes[i].email[j]);
			}
			for(x = 0; x < num_telefones; x++){
				printf("TELEFONE %d: %s\n", x + 1, pacientes[i].telefone[x]);
			}
		}
			
	}
	if(achou == 0){
		printf("cpf nao existe\n");
	}
	printf("\ninsira qualquer valor para voltar ao menu de medicos:");
	scanf("%d", &voltar);

}

void deleta_paciente(struct paciente pacientes[], int *contador_pacientes){
	system("cls");
	int contador = *contador_pacientes;
	char cpf_desejado[10];
	int i, x;
	printf("Digite o cpf do medico que deseja deletar:");
	scanf("%s", &cpf_desejado);
	int achou = 0;
	for(i = 0; i < contador && achou == 0; i++){
		if(strcmp(cpf_desejado, pacientes[i].cpf) == 0){
			achou = 1;
			for(x = i; x < contador; x++){
				pacientes[x] = pacientes[x + 1];
			}
		}	
	}
	if(achou == 0){
		printf("cpf nao existente");
	}else{
		(*contador_pacientes)--;
	}
}

void alterar_um_paciente(struct paciente pacientes[], int *contador_pacientes){
	int voltar = 0;
	char cpf_desejado[10];
	int contador = *contador_pacientes;
   	char cpf1[18], nome1[40], sexo1, plano1[20], emails1[2][25], telefones1[2][20];
   	int i = 0, x, num_emails = 0, num_telefones = 0, dia_nasc1 = 0, mes_nasc1 = 0, ano_nasc1 = 0;
   	system("cls");
	printf("Digite o cpf do paciente que deseja alterar:");
	scanf("%s", &cpf_desejado);
	for(i = 0; i < contador; i++){
		int num_emails = pacientes[i].n_emails;
		int num_telefones = pacientes[i].n_telefones;
		int res = 0;
		if(strcmp(cpf_desejado, pacientes[i].cpf) == 0){
			printf("Deseja alterar o nome(1 = sim/0 = nao)?");
			scanf("%d", &res);
			if(res == 1){
				printf("Insira o nome do medico:");
				scanf("%s", &nome1);
				strcpy(pacientes[i].nome, nome1);
			}
			printf("Deseja alterar a data de nascimento(1 = sim/0 = nao)?");
			scanf("%d", &res);
			if(res == 1){
				printf("Insira a data de nascimento (xx xx xxxx):");
				scanf("%d %d %d", &dia_nasc1, &mes_nasc1, &ano_nasc1);
				pacientes[i].dia_nasc = dia_nasc1;
		   		pacientes[i].mes_nasc = mes_nasc1;
		   		pacientes[i].ano_nasc = ano_nasc1;
			}
			printf("Deseja alterar o sexo(1 = sim/0 = nao)?");
			scanf("%d", &res);
			if(res == 1){
				printf("Insira o sexo: ");
		    	scanf("%s", &sexo1);
		    	pacientes[i].sexo = sexo1;
			}
		    printf("Deseja alterar o plano(1 = sim/0 = nao)?");
			scanf("%d", &res);
			if(res == 1){
				printf("Insira o plano:");
		    	scanf("%s", &plano1);
		    	strcpy(pacientes[i].plano, plano1);
			}
		    printf("Deseja alterar os emails(1 = sim/0 = nao)?");
			scanf("%d", &res);
			if(res == 1){
				printf("Insira a quantidade de emails que o paciente possui:");
		    	scanf("%d", &num_emails);
		    	pacientes[i].n_emails = num_emails;
		    	for(i = 0; i < num_emails; i++){
		       		printf("Insira o email numero %d:", i + 1);
		       		scanf("%s", &emails1[i]);
		   		}
		   		for(x = 0; x < num_emails; x++){
					strcpy(pacientes[i].email[x], emails1[x]);
		   		}
			}
		    printf("Deseja alterar os telefones(1 = sim/0 = nao)?");
			scanf("%d", &res);
			if(res == 1){
				printf("Insira a quantidade de telefones que o medico possui:");
		    	scanf("%d", &num_telefones);
		    	pacientes[i].n_telefones = num_telefones;
		   		for(i = 0; i < num_emails; i++){
		       		printf("Insira o telefone numero %d:", i + 1);
		       		scanf("%s", &telefones1[i]);
		   		}
		   		for(x = 0; x < num_telefones; x++){
					strcpy(pacientes[i].telefone[x], telefones1[x]);
		   		}
			}
		}	
	}
	printf("\ninsira qualquer valor para voltar ao menu de medicos:");
	scanf("%d", &voltar);

}

void Incluir_paciente(struct paciente pacientes[], int *contador_pacientes){
   int contador = *contador_pacientes;
   pacientes = (struct paciente *)realloc(pacientes, (contador + 1)*sizeof(struct paciente)); // aloca mais uma posição no vetor
   char cpf1[18], nome1[40], sexo1, plano1[20], emails1[2][25], telefones1[2][20];
   int i = 0, num_emails = 0, num_telefones = 0, dia_nasc1 = 0, mes_nasc1 = 0, ano_nasc1 = 0;
   system("cls");

   printf("Insira o CPF do paciente: ");
   scanf("%s", &cpf1);
   for(int i = 0; i < contador; i++){
	   if(strcmp(cpf1,pacientes[i].cpf) == 0){
		   printf("Este cpf ja existe\n");
	   }else{
		   	printf("Insira o nome do paciente:");
   			gets(nome1);
   			printf("Insira a data de nascimento (xx xx xxxx):");
			scanf("%d %d %d", &dia_nasc1, &mes_nasc1, &ano_nasc1);
			printf("Insira o sexo: ");
			scanf("%s", &sexo1);
			printf("Insira o plano:");
			scanf("%s", &plano1);
			printf("Insira a quantidade de emails que o paciente possui:");
			scanf("%d", &num_emails);
			pacientes[contador].n_emails = num_emails;
			printf("Insira a quantidade de telefones que o paciente possui:");
			scanf("%d", &num_telefones);
			pacientes[contador].n_telefones = num_telefones;
			for(i = 0; i < num_emails; i++){
				printf("Insira o email numero %d:", i + 1);
				scanf("%s", &emails1[i]);
			}
			for(i = 0; i < num_emails; i++){
				printf("Insira o telefone numero %d:", i + 1);
				scanf("%s", &telefones1[i]);
			}
			strcpy(pacientes[contador].cpf, cpf1);
			strcpy(pacientes[contador].nome, nome1);
			pacientes[contador].dia_nasc = dia_nasc1;
			pacientes[contador].mes_nasc = mes_nasc1;
			pacientes[contador].ano_nasc = ano_nasc1;
			pacientes[contador].sexo = sexo1;
			strcpy(pacientes[contador].plano, plano1);
			for(i = 0; i < num_emails; i++){
					strcpy(pacientes[contador].email[i], emails1[i]);
			}
			for(i = 0; i < num_telefones; i++){
					strcpy(pacientes[contador].telefone[i], telefones1[i]);
			}
			(*contador_pacientes)++;
	   }
   }
   
}



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
    
    
    posicao = -1;
    for (i = 0; i < contador; i++){
    	if (strcmp(consultas[i].crm, crm1) == 0 && strcmp(consultas[i].cpf, cpf1) == 0 && consultas[i].dia == dia1 && consultas[i].mes == mes1 && consultas[i].ano == ano1 && strcmp(consultas[i].hora, hora1) == 0){
            posicao = i;
        }
	}
    
    if (posicao == -1)
        printf("Consulta não encontrada!");
    else{
        printf("Consulta: \n");
        printf("\tCRM: %s\n\tCPF: %s\n\tData: %d/%d/%d\n\tHora: %s\n\tDiagnóstico: %s\n", consultas[posicao].crm, consultas[posicao].cpf, consultas[posicao].dia, consultas[posicao].mes, consultas[posicao].ano, consultas[posicao].hora, consultas[posicao].diagnostico);
    	for(i = 0; i < consultas[posicao].num_medicamentos; i++){
			printf("\tMedicamento %d: %s\n", posicao + 1, consultas[posicao].medicamentos[i]);
		}
	}
}

void incluir_consulta(struct consulta consultas[], int *contador_consultas, struct medico medicos[], int contador_medicos, struct paciente pacientes[], int contador_pacientes){
    char crm1[20], cpf1[18], hora1[6], diagnostico1[100];
    int i, j, num_medicamentos1, dia1, mes1, ano1, busca_consulta = 1, contador = *contador_consultas;
    int achouMedico = 0, achouPaciente = 0;
	consultas = (struct consulta *)realloc(consultas, (contador + 1)*sizeof(struct consulta)); // aloca mais uma posição no vetor

    system("cls");
	
    printf("Insira o CRM do médico (sem pontos ou tracos): ");
    scanf("%s", &crm1);

	//verificando se o medico ja foi cadastrado
	for(i = 0; i < contador_medicos; i++){
	   if(strcmp(crm1,medicos[i].crm) == 0){
		   achouMedico = 1;
	   }
	}
	if (achouMedico == 1){
		printf("Insira o CPF do paciente (sem pontos ou tracos): ");
		scanf("%s", &cpf1);

		//verificando se o paciente ja foi cadastrado
		for(i = 0; i < contador_pacientes; i++){
			if(strcmp(crm1,pacientes[i].cpf) == 0){
				achouPaciente = 1;
			}
		}

		if (achouPaciente == 1){
			printf("Data:\n");
			printf("\tInsira o dia: ");
			scanf("%d", &dia1);
			printf("\tInsira o mês: ");
			scanf("%d", &mes1);
			printf("\tInsira o ano: ");
			scanf("%d", &ano1);
			printf("Insira a hora (sem pontos ou traços): ");
			scanf("%s", &hora1);

			//verificando se possui repeticoes
			i = 0;
			while (i < contador){
				if (strcmp(crm1, consultas[i].crm) == 0 && strcmp(cpf1, consultas[i].cpf) == 0 && dia1 == consultas[i].dia && mes1 == consultas[i].mes && ano1 == consultas[i].ano && strcmp(hora1, consultas[i].hora) == 0){
					printf("Consulta já cadastrada!\n");
					busca_consulta = 0;
				}
				i++;
			}

			if (busca_consulta == 1){

				printf("Insira o diagnostico: ");
				scanf("%s", &diagnostico1);
				printf("Insira o numero de medicamentos: ");
				scanf("%d", &num_medicamentos1);
				
				char medicamentos1[num_medicamentos1][50];
				for(i = 0; i < num_medicamentos1; i++){
					printf("Insira o medicamento numero %.0d: ", i + 1);
					scanf("%s", &medicamentos1[i]);
				}
				
				i = contador;

				strcpy(consultas[i].crm, crm1);
				strcpy(consultas[i].cpf, cpf1);
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
		}
		else
			printf("Paciente não cadastrado!");
	}
	else
		printf("Médico não cadastrado!");
		sleep(10);
}

void alterar_consulta(struct consulta consultas[], int *contador_consultas){
	int voltar = 0, dia_desejado = 0, mes_desejado = 0, ano_desejado = 0;
	int contador = *contador_consultas;
	int i = 0, x, num_medicamentos1 = 0, dia1 = 0, mes1 = 0, ano1 = 0;
	char crm_desejado[20], cpf_desejado[18], hora_desejado[6];
	char crm1[20], cpf1[18], hora1[6], diagnostico1[100], medicamentos1[10][50];
   	
	system("cls");
	printf("Insira o CRM do médico (sem pontos ou tracos) da consulta a alterar: ");
    scanf("%s", &crm_desejado);
    printf("Insira o CPF do paciente (sem pontos ou tracos) da consulta a alterar: ");
    scanf("%s", &cpf_desejado);
    printf("Data da consulta a alterar:\n");
    printf("\tInsira o dia: ");
    scanf("%d", &dia_desejado);
    printf("\tInsira o mês: ");
    scanf("%d", &mes_desejado);
    printf("\tInsira o ano: ");
    scanf("%d", &ano_desejado);
    printf("Insira a hora (sem pontos ou traços) da consulta a alterar: ");
    scanf("%s", &hora_desejado);
    
	for(i = 0; i < contador; i++){
		int res = 0;
		if(strcmp(consultas[i].crm, crm_desejado) == 0 && strcmp(consultas[i].cpf, cpf_desejado) == 0 && consultas[i].dia == dia_desejado && consultas[i].mes == mes_desejado && consultas[i].ano == ano_desejado && strcmp(consultas[i].hora, hora_desejado) == 0){
			printf("Deseja alterar o CRM(1 = sim/0 = nao)?");
			scanf("%d", &res);
			if(res == 1){
				printf("Insira o CRM do medico (sem pontos ou tracos):");
				scanf("%s", &crm1);
				strcpy(consultas[i].crm, crm1);
			}
			printf("Deseja alterar o CPF do paciente(1 = sim/0 = nao)?");
			scanf("%d", &res);
			if(res == 1){
				printf("Insira o CPF (sem pontos ou tracos):");
		    	scanf("%s", &cpf1);
		    	strcpy(consultas[i].cpf, cpf1);
			}
			printf("Deseja alterar a data(1 = sim/0 = nao)?");
			scanf("%d", &res);
			if(res == 1){
				printf("Insira a data (xx xx xxxx):");
				scanf("%d %d %d", &dia1, &mes1, &ano1);
				consultas[i].dia = dia1;
		   		consultas[i].mes = mes1;
		   		consultas[i].ano = ano1;
			}
		    printf("Deseja alterar a hora(1 = sim/0 = nao)?");
			scanf("%d", &res);
			if(res == 1){
				printf("Insira a hora (sem pontos ou tracos):");
			    scanf("%s", &hora1);
				strcpy(consultas[i].hora, hora1);	
			}
			printf("Deseja alterar o diagnóstico(1 = sim/0 = nao)?");
			scanf("%d", &res);
			if(res == 1){
				printf("Insira o diagnóstico:");
			    scanf("%s", &diagnostico1);
				strcpy(consultas[i].diagnostico, diagnostico1);	
			}
		    printf("Deseja alterar os medicamentos(1 = sim/0 = nao)?");
			scanf("%d", &res);
			if(res == 1){
				printf("Insira a quantidade de medicamentos:");
		    	scanf("%d", &num_medicamentos1);
		    	consultas[i].num_medicamentos = num_medicamentos1;
		    	for(x = 0; x < num_medicamentos1; x++){
		       		printf("Insira o medicamneto %d:", x + 1);
		       		scanf("%s", &medicamentos1[x]);
		   		}
		   		for(x = 0; x < num_medicamentos1; x++){
					strcpy(consultas[i].medicamentos[x], medicamentos1[x]);
		   		}
			}
		}	
	}
	printf("\ninsira qualquer valor para voltar ao menu de consultas:");
	scanf("%d", &voltar);

}

void exclui_consulta(struct consulta consultas[], int *contador_consultas){
	system("cls");
	int contador = *contador_consultas;
	char crm_desejado[20], cpf_desejado[18], hora_desejado[6];
	int dia_desejado = 0, mes_desejado = 0, ano_desejado = 0;
	
	printf("Insira o CRM (sem pontos ou tracos) da consulta a excluir: ");
    scanf("%s", &crm_desejado);
    printf("Insira o CPF do paciente (sem pontos ou tracos) da consulta a excluir: ");
    scanf("%s", &cpf_desejado);
    printf("Data da consulta a excluir:\n");
    printf("\tInsira o dia: ");
    scanf("%d", &dia_desejado);
    printf("\tInsira o mês: ");
    scanf("%d", &mes_desejado);
    printf("\tInsira o ano: ");
    scanf("%d", &ano_desejado);
    printf("Insira a hora (sem pontos ou traços) da consulta a excluir: ");
    scanf("%s", &hora_desejado);
    
	int achou = 0, x, i;
	for(i = 0; i < contador && achou == 0; i++){
		if(strcmp(consultas[i].crm, crm_desejado) == 0 && strcmp(consultas[i].cpf, cpf_desejado) == 0 && consultas[i].dia == dia_desejado && consultas[i].mes == mes_desejado && consultas[i].ano == ano_desejado && strcmp(consultas[i].hora, hora_desejado) == 0){
			achou = 1;
			for(x = i; x < contador; x++){
				consultas[x] = consultas[x + 1];
			}
		}	
	}
	if(achou == 0){
		printf("Consulta nao encontrada!");
	}else{
		(*contador_consultas)--;
	}
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
	setlocale(LC_ALL, "Portuguese");
	
	
	
	
	int sair = 0, contador_consultas = 0; 
	int contador_medicos = 0;
	int contador_pacientes = 0;
	
	struct consulta *consultas;
	struct medico *medicos;
	struct paciente *pacientes;
	medicos = (struct medico *)malloc(contador_medicos * sizeof(struct medico));
	if(!medicos){
		printf("\n[ERROR]: Não foi possível alocar a memoria");
		exit;
	}
	pacientes = (struct paciente *)malloc(contador_pacientes * sizeof(struct paciente));
	if(!pacientes){
		printf("\n[ERROR]:Não foi possível alocar a memoria");
		exit;
	}
	consultas = (struct consulta *)malloc(contador_consultas * sizeof(struct consulta));
	if(!consultas){
		printf("\n[ERROR]:Não foi possível alocar a memoria");
		exit;
	}

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
			        listar_todos_pacientes(pacientes, &contador_pacientes);
			        break;
			    case 2:
			        listar_um_paciente(pacientes, &contador_pacientes);
			        break;
			    case 3:
			        Incluir_paciente(pacientes, &contador_pacientes);
			        break;
			    case 4:
			        alterar_um_paciente(pacientes, &contador_pacientes);
			        break;
			    case 5:
			        deleta_paciente(pacientes, &contador_pacientes);
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
					incluir_consulta(consultas, &contador_consultas, medicos, contador_medicos, pacientes, contador_pacientes);
			        break;
			    case 4:
			        alterar_consulta(consultas, &contador_consultas);
			        break;
			    case 5:
			        exclui_consulta(consultas, &contador_consultas);
			        break;
			    case 6:
			        sair_consulta = 1;
			        break;
			    
			    default: printf("\nvalor inválido\n");
			        break;
			    }
			}
	        break;
	        
	    case 4:
	        while (sair_relatorio == 0){
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