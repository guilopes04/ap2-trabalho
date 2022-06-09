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
	FILE *fp_medicos;
	int quantidade_medicos;
	struct medico *lista_medicos;
	if ((fp_medicos = fopen("medicos.dat", "rb+")) == NULL){
			printf("Nao foi possivel ler o arquivo");
			exit(0);
		}else{
			fseek(fp_medicos, 0, SEEK_END);
			quantidade_medicos = ftell(fp_medicos) / sizeof(struct medico);
			rewind(fp_medicos);
			lista_medicos = (struct medico *)malloc(quantidade_medicos * sizeof(struct medico));
			if(!lista_medicos){
				printf("\n[ERROR]: Não foi possível alocar a memoria");
				exit(0);
			}
			if (fread(lista_medicos, sizeof(struct medico), quantidade_medicos, fp_medicos) != quantidade_medicos)
			 	printf("Nao foi possivel ler todos os elementos do arquivo");

	system("cls");
	for(i = 0; i < quantidade_medicos; i++){
		int num_emails = lista_medicos[i].n_emails;
		int num_telefones = lista_medicos[i].n_telefones;
		printf("\nMedico %d\n", i + 1);
		printf("CRM: %s\n", lista_medicos[i].crm);
		printf("NOME: %s\n", lista_medicos[i].nome);
		printf("NASCIMENTO: %d/%d/%d\n", lista_medicos[i].dia_nasc, medicos[i].mes_nasc, medicos[i].ano_nasc);
		printf("SEXO: %c\n", lista_medicos[i].sexo);
		printf("ESPECIALIDADE: %s\n", lista_medicos[i].especialidade);
		printf("UNIVERSIDADE: %s\n", lista_medicos[i].universidade);
		for(j = 0; j < num_emails; j++){
			printf("EMAIL %d: %s\n", j + 1, lista_medicos[i].email[j]);
		}
		for(x = 0; x < num_telefones; x++){
			printf("TELEFONE %d: %s\n", x + 1, lista_medicos[i].telefone[x]);
		}
	}
	printf("\ninsira qualquer valor para voltar ao menu de medicos:");
	scanf("%d", &voltar);

	}
}


void listar_um_medico(struct medico medicos[], int *contador_medicos){
	int voltar = 0, i, j, x;
	char crm_desejado[10];
	struct medico *medico_desejado;
	FILE *fp_medicos;
	int quantidade_medicos;
	struct medico *lista_medicos;
	medico_desejado = (struct medico *)malloc(sizeof(struct medico)); // aloca mais uma posição no vetor
	int num_emails = 0, num_telefones = 0;
	if ((fp_medicos = fopen("medicos.dat", "ab+")) == NULL){
			printf("Nao foi possivel ler o arquivo");
			exit(0);
		}else{
			fseek(fp_medicos, 0, SEEK_END);
			quantidade_medicos = ftell(fp_medicos) / sizeof(struct medico);
			rewind(fp_medicos);
			lista_medicos = (struct medico *)malloc(quantidade_medicos * sizeof(struct medico));
			if(!lista_medicos){
				printf("\n[ERROR]: Não foi possível alocar a memoria");
				exit(0);
			}
			if (fread(lista_medicos, sizeof(struct medico), quantidade_medicos, fp_medicos) != quantidade_medicos)
			 	printf("Nao foi possivel ler todos os elementos do arquivo");
			system("cls");
			fflush(stdin);
	printf("Digite o crm do medico que deseja visualizar:");
	scanf("%s", &crm_desejado);
	int achou = 0;
	for(i = 0; i < quantidade_medicos && achou == 0; i++){
		if(strcmp(crm_desejado, lista_medicos[i].crm) == 0){
			int num_emails = lista_medicos[i].n_emails;
			int num_telefones = lista_medicos[i].n_telefones;
			achou = 1;
			printf("CRM: %s\n", lista_medicos[i].crm);
			printf("NOME: %s\n", lista_medicos[i].nome);
			printf("NASCIMENTO: %d/%d/%d\n", lista_medicos[i].dia_nasc, lista_medicos[i].mes_nasc, lista_medicos[i].ano_nasc);
			printf("SEXO: %c\n", lista_medicos[i].sexo);
			printf("ESPECIALIDADE: %s\n", lista_medicos[i].especialidade);
			printf("UNIVERSIDADE: %s\n", lista_medicos[i].universidade);
			for(j = 0; j < num_emails; j++){
				printf("EMAIL %d: %s\n", j + 1, lista_medicos[i].email[j]);
			}
			for(x = 0; x < num_telefones; x++){
				printf("TELEFONE %d: %s\n", x + 1, lista_medicos[i].telefone[x]);
			}
		}
			
	}
	if(achou == 0){
		printf("crm não existe\n");
	}
	printf("\ninsira qualquer valor para voltar ao menu de medicos:");
	scanf("%d", &voltar);

	}
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

void Incluir_medico(struct medico *medicos, int *contador_medicos){
	struct medico *medico_inserir;
	FILE *fp_medicos;
	int quantidade_medicos;
	struct medico *lista_medicos;
	medico_inserir = (struct medico *)malloc(sizeof(struct medico)); // aloca mais uma posição no vetor
	int i = 0, num_emails = 0, num_telefones = 0;
	int achou = 0;
	if ((fp_medicos = fopen("medicos.dat", "ab+")) == NULL){
			printf("Nao foi possivel ler o arquivo");
			exit(0);
		}else{
			fseek(fp_medicos, 0, SEEK_END);
			quantidade_medicos = ftell(fp_medicos) / sizeof(struct medico);
			printf("%d", quantidade_medicos);
			rewind(fp_medicos);
			lista_medicos = (struct medico *)malloc(quantidade_medicos * sizeof(struct medico));
			if(!lista_medicos){
				printf("\n[ERROR]: Não foi possível alocar a memoria");
				exit(0);
			}
			if (fread(lista_medicos, sizeof(struct medico), quantidade_medicos, fp_medicos) != quantidade_medicos)
			 	printf("Nao foi possivel ler todos os elementos do arquivo");
			system("cls");
			fflush(stdin);
			printf("Insira o CRM do medico: ");
			scanf("%s", &(*medico_inserir).crm);
			for(i = 0; i < quantidade_medicos && achou != 1; i++){
				if(strcmp((*medico_inserir).crm, lista_medicos[i].crm) == 0){
					printf("Este crm já existe\n");
					achou = 1;
				}
			}
			if(achou == 0){
				fflush(stdin);
				printf("Insira o nome do medico:");
				gets(&(*medico_inserir).nome);
				printf("Insira a data de nascimento (xx xx xxxx):");
				scanf("%d %d %d", &(*medico_inserir).dia_nasc,  &(*medico_inserir).mes_nasc,  &(*medico_inserir).ano_nasc);
				printf("Insira o sexo: ");
				scanf("%s", &(*medico_inserir).sexo);
				printf("Insira a especialidade:");
				scanf("%s", &(*medico_inserir).especialidade);
				printf("Insira a universidade que se formou:");
				scanf("%s", &(*medico_inserir).universidade);
				printf("Insira a quantidade de emails que o medico possui:");
				scanf("%d", &num_emails);
				(*medico_inserir).n_emails = num_emails;
				for(i = 0; i < num_emails; i++){
					printf("Insira o email numero %d:", i + 1);
					scanf("%s", &(*medico_inserir).email[i]);
				}
				printf("Insira a quantidade de telefones que o medico possui:");
				scanf("%d", &num_telefones);
				(*medico_inserir).n_telefones = num_telefones;
				for(i = 0; i < num_emails; i++){
					printf("Insira o telefone numero %d:", i + 1);
					scanf("%s", &(*medico_inserir).telefone[i]);
				}
				(*contador_medicos)++;
				if (fwrite(medico_inserir, sizeof(struct medico), 1, fp_medicos) != 1)
					printf("Nao foi possivel escrever todos os elementos do arquivo");
				}
			}
			fclose(fp_medicos);
			free(medico_inserir);
			free(lista_medicos);
			sleep(2);
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

void listar_todos(struct consulta *consultas, int *contador_consultas){
	int i, j, contador = *contador_consultas;

	FILE *fp_consultas;
	int quantidade_consultas;
	struct consulta *lista_consultas;
	if ((fp_consultas = fopen("consultas.dat", "rb")) == NULL){
			printf("Nao foi possivel ler o arquivo");
			exit(0);
		}
	else{
		fseek(fp_consultas, 0, SEEK_END);
		quantidade_consultas = ftell(fp_consultas) / sizeof(struct consulta);
		rewind(fp_consultas);
		lista_consultas = (struct consulta *)malloc(quantidade_consultas * sizeof(struct consulta));
		if(!lista_consultas){
			printf("\n[ERROR]: Não foi possível alocar a memoria");
			exit(0);
		}
		else{
			if (fread(lista_consultas, sizeof(struct consulta), quantidade_consultas, fp_consultas) != quantidade_consultas)
				printf("Nao foi possivel ler todos os elementos do arquivo");
			else{
				system("cls");
				fflush(stdin);
				for (i = 0; i < quantidade_consultas; i++){
					printf("\n\tCRM: %s\n\tCPF: %s\n\tData: %d/%d/%d\n\tHora: %s\n\tDiagnóstico: %s\n", lista_consultas[i].crm, lista_consultas[i].cpf, lista_consultas[i].dia, lista_consultas[i].mes, lista_consultas[i].ano, lista_consultas[i].hora, lista_consultas[i].diagnostico);
					for(j = 0; j < lista_consultas[i].num_medicamentos; j++){
						printf("\tMedicamento %d: %s\n", i + 1, lista_consultas[i].medicamentos[j]);
					}
				}
			}
		}
		free(lista_consultas);
	}
	fclose(fp_consultas);
}

void listar_um(struct consulta *consultas, int *contador_consultas)
{
    char crm1[20], cpf1[18], hora1[6];
    int i, posicao, contador = *contador_consultas, dia1, mes1, ano1, achou = 0;

	struct consulta *consulta_imprimir;
	FILE *fp_consultas;
	int quantidade_consultas;
	struct consulta *lista_consultas;
	consulta_imprimir = (struct consulta *)malloc(sizeof(struct consulta));
	if ((fp_consultas = fopen("consultas.dat", "rb")) == NULL){
			printf("Nao foi possivel ler o arquivo");
			exit(0);
		}
	else{
		fseek(fp_consultas, 0, SEEK_END);
		quantidade_consultas = ftell(fp_consultas) / sizeof(struct consulta);
		//printf("%d", quantidade_consultas);
		rewind(fp_consultas);
		lista_consultas = (struct consulta *)malloc(quantidade_consultas * sizeof(struct consulta));
		if(!lista_consultas){
			printf("\n[ERROR]: Não foi possível alocar a memoria");
			exit(0);
		}
		else{
			if (fread(lista_consultas, sizeof(struct consulta), quantidade_consultas, fp_consultas) != quantidade_consultas)
				printf("Nao foi possivel ler todos os elementos do arquivo");
			else{
				system("cls");
				fflush(stdin);

				//ACESSANDO CONSULTA
				printf("Insira o CRM do medico: ");
				scanf("%s", &(*consulta_imprimir).crm);
				printf("Insira o CPF do paciente: ");
				scanf("%s", &(*consulta_imprimir).cpf);
				printf("Insira a data (xx xx xxxx): ");
				scanf("%d %d %d", &(*consulta_imprimir).dia, &(*consulta_imprimir).mes, &(*consulta_imprimir).ano);
				printf("Insira a hora: ");
				scanf("%s", &(*consulta_imprimir).hora);

				for(i = 0; i < quantidade_consultas; i++){
					if (strcmp((*consulta_imprimir).crm, lista_consultas[i].crm) == 0 && strcmp((*consulta_imprimir).cpf, lista_consultas[i].cpf) == 0 && (*consulta_imprimir).dia == lista_consultas[i].dia && (*consulta_imprimir).mes == lista_consultas[i].mes && (*consulta_imprimir).ano == lista_consultas[i].ano && strcmp((*consulta_imprimir).hora, lista_consultas[i].hora) == 0){
						printf("\tCRM: %s\n\tCPF: %s\n\tData: %d/%d/%d\n\tHora: %s\n\tDiagnóstico: %s\n", lista_consultas[i].crm, lista_consultas[i].cpf, lista_consultas[i].dia, lista_consultas[i].mes, lista_consultas[i].ano, lista_consultas[i].hora, lista_consultas[i].diagnostico);
						for(i = 0; i < lista_consultas[i].num_medicamentos; i++){
						printf("\tMedicamento %d: %s\n", i + 1, lista_consultas[i].medicamentos[i]);
					}
						achou = 1;
					}
				}
				if (achou == 0)
					printf("Esta consulta não foi cadatrada\n");

				fclose(fp_consultas);
				free(consulta_imprimir);
				free(lista_consultas);
			}
		}
	}
}

void incluir_consulta(struct consulta *consultas, int *contador_consultas, struct medico *medicos, int *contador_medicos, struct paciente *pacientes, int *contador_pacientes){
    char crm1[20], cpf1[18], hora1[6], diagnostico1[100];
    int i, j, num_medicamentos1, dia1, mes1, ano1, busca_consulta = 1, contador = *contador_consultas;
    int achouMedico = 0, achouPaciente = 0, achouConsulta = 0;
	
	//ABRINDO ARQUIVO DE MEDICOS E ALOCANDO MEMORIA

	struct medico *medico_buscar;
	FILE *fp_medicos;
	int quantidade_medicos;
	struct medico *lista_medicos;
	medico_buscar = (struct medico *)malloc(sizeof(struct medico));

	if ((fp_medicos = fopen("medicos.dat", "rb")) == NULL){
		printf("Nao foi possivel ler o arquivo");
		exit(0);
	}
	else{

		//INDENTIFICANDO O NUMERO DE MEDICOS
		fseek(fp_medicos, 0, SEEK_END);
		quantidade_medicos = ftell(fp_medicos) / sizeof(struct medico);
		rewind(fp_medicos);
		lista_medicos = (struct medico *)malloc(quantidade_medicos * sizeof(struct medico));
		if(!lista_medicos){
			printf("\n[ERROR]: Não foi possível alocar a memoria");
			exit(0);
		}
		if (fread(lista_medicos, sizeof(struct medico), quantidade_medicos, fp_medicos) != quantidade_medicos)
			printf("Nao foi possivel ler todos os elementos do arquivo");
		system("cls");
		fflush(stdin);

		printf("Insira o CRM do medico: ");
		scanf("%s", &(*medico_buscar).crm);

		//VERIFICANDO SE O MEDICO JA FOI CADASTRADO
		for(i = 0; i < quantidade_medicos && achouMedico != 1; i++){
			if(strcmp((*medico_buscar).crm, lista_medicos[i].crm) == 0)
				achouMedico = 1;
		}
		if (achouMedico == 0)
			printf("Médico não cadastrado!");

		else{

			//ABRINDO ARQUIVO DE PACIENTES E ALOCANDO MEMORIA

			struct paciente *paciente_buscar;
			FILE *fp_pacientes;
			int quantidade_pacientes;
			struct paciente *lista_pacientes;
			paciente_buscar = (struct paciente *)malloc(sizeof(struct paciente));

			if ((fp_pacientes = fopen("pacientes.dat", "rb")) == NULL){
				printf("Nao foi possivel ler o arquivo");
				exit(0);
			}
			else{
				fseek(fp_pacientes, 0, SEEK_END);
				quantidade_pacientes = ftell(fp_pacientes) / sizeof(struct paciente);
				//printf("%d", quantidade_medicos);
				rewind(fp_pacientes);
				lista_pacientes = (struct paciente *)malloc(quantidade_pacientes * sizeof(struct paciente));
				if(!lista_pacientes){
					printf("\n[ERROR]: Não foi possível alocar a memoria");
					exit(0);
				}
				if (fread(lista_pacientes, sizeof(struct paciente), quantidade_pacientes, fp_pacientes) != quantidade_pacientes)
					printf("Nao foi possivel ler todos os elementos do arquivo");
				system("cls");
				fflush(stdin);

				printf("Insira o CPF do paciente: ");
				scanf("%s", &(*paciente_buscar).cpf);

				//VERIFICANDO SE O PACIENTE JA FOI CADASTRADO
				for(i = 0; i < quantidade_pacientes && achouPaciente != 1; i++){
					if(strcmp((*paciente_buscar).cpf, lista_pacientes[i].cpf) == 0)
						achouPaciente = 1;
				}
				if (achouPaciente == 0)
					printf("Paciente não cadastrado!");
				else{
					
					//ABRINDO ARQUIVO DE CONSULTAS E ALOCANDO MEMORIA
					struct consulta *consulta_inserir;
					FILE *fp_consultas;
					int quantidade_consultas;
					struct consulta *lista_consultas;
					consulta_inserir = (struct consulta *)malloc(sizeof(struct consulta)); // aloca mais uma posição no vetor

					if ((fp_consultas = fopen("consultas.dat", "ab+")) == NULL){
							printf("Nao foi possivel ler o arquivo");
							exit(0);
						}
					else{
						fseek(fp_consultas, 0, SEEK_END);
						quantidade_consultas = ftell(fp_consultas) / sizeof(struct consulta);
						//printf("%d", quantidade_consultas);
						rewind(fp_consultas);
						lista_consultas = (struct consulta *)malloc(quantidade_consultas * sizeof(struct consulta));
						if(!lista_consultas){
							printf("\n[ERROR]: Não foi possível alocar a memoria");
							exit(0);
						}
						else{
							if (fread(lista_consultas, sizeof(struct consulta), quantidade_consultas, fp_consultas) != quantidade_consultas)
								printf("Nao foi possivel ler todos os elementos do arquivo");
							else{
								system("cls");
								fflush(stdin);

								//VERIFICANDO REPETICOES
								printf("Insira o CRM do medico: ");
								scanf("%s", &(*consulta_inserir).crm);
								printf("Insira o CPF do paciente: ");
								scanf("%s", &(*consulta_inserir).cpf);
								printf("Insira a data (xx xx xxxx): ");
								scanf("%d %d %d", &(*consulta_inserir).dia, &(*consulta_inserir).mes, &(*consulta_inserir).ano);
								printf("Insira a hora: ");
								scanf("%s", &(*consulta_inserir).hora);

								for(i = 0; i < quantidade_consultas && achouConsulta != 1; i++){
									if (strcmp((*consulta_inserir).crm, lista_consultas[i].crm) == 0 && strcmp((*consulta_inserir).cpf, lista_consultas[i].cpf) == 0 && (*consulta_inserir).dia == lista_consultas[i].dia && (*consulta_inserir).mes == lista_consultas[i].mes && (*consulta_inserir).ano == lista_consultas[i].ano && strcmp((*consulta_inserir).hora, lista_consultas[i].hora) == 0){
										printf("Esta consulta já existe\n");
										achouConsulta = 1;
									}
								}
								if(achouConsulta == 0){
									printf("Insira o diagnostico: ");
									scanf("%s", &(*consulta_inserir).diagnostico);
									printf("Insira o numero de medicamentos: ");
									scanf("%d", &num_medicamentos1);

									(*consulta_inserir).num_medicamentos = num_medicamentos1;
									for(i = 0; i < num_medicamentos1; i++){
										printf("Insira o medicamento numero %.0d:", i + 1);
										scanf("%s", &(*consulta_inserir).medicamentos[i]);
									}
									
									if (fwrite(consulta_inserir, sizeof(struct consulta), 1, fp_consultas) != 1)
										printf("Nao foi possivel escrever todos os elementos do arquivo");
								}
							}
						}
					}
					fclose(fp_consultas);
					free(consulta_inserir);
					free(lista_consultas);
				}			
			}
			fclose(fp_pacientes);
			free(lista_pacientes);
		}
	}
	fclose(fp_medicos);
	free(lista_medicos);
	sleep(2);
}

void alterar_consulta(struct consulta consultas[], int *contador_consultas){
	int voltar = 0, dia_desejado = 0, mes_desejado = 0, ano_desejado = 0, achou = 0, res = 0;;
	int contador = *contador_consultas;
	int i = 0, x, num_medicamentos1 = 0, dia1 = 0, mes1 = 0, ano1 = 0;
	char crm_desejado[20], cpf_desejado[18], hora_desejado[6];
	char crm1[20], cpf1[18], hora1[6], diagnostico1[100], medicamentos1[10][50];

	struct consulta *consulta_alterar;
	FILE *fp_consultas;
	int quantidade_consultas;
	struct consulta *lista_consultas;
	consulta_alterar = (struct consulta *)malloc(sizeof(struct consulta));
	if ((fp_consultas = fopen("consultas.dat", "ab+")) == NULL){
			printf("Nao foi possivel ler o arquivo");
			exit(0);
		}
	else{
		fseek(fp_consultas, 0, SEEK_END);
		quantidade_consultas = ftell(fp_consultas) / sizeof(struct consulta);
		rewind(fp_consultas);
		lista_consultas = (struct consulta *)malloc(quantidade_consultas * sizeof(struct consulta));
		if(!lista_consultas){
			printf("\n[ERROR]: Não foi possível alocar a memoria");
			exit(0);
		}
		else{
			if (fread(lista_consultas, sizeof(struct consulta), quantidade_consultas, fp_consultas) != quantidade_consultas)
				printf("Nao foi possivel ler todos os elementos do arquivo");
			else{
				system("cls");
				fflush(stdin);

				//ACESSANDO CONSULTA
				printf("Insira o CRM do medico: ");
				scanf("%s", &(*consulta_alterar).crm);
				printf("Insira o CPF do paciente: ");
				scanf("%s", &(*consulta_alterar).cpf);
				printf("Insira a data (xx xx xxxx): ");
				scanf("%d %d %d", &(*consulta_alterar).dia, &(*consulta_alterar).mes, &(*consulta_alterar).ano);
				printf("Insira a hora: ");
				scanf("%s", &(*consulta_alterar).hora);

				for(i = 0; i < quantidade_consultas; i++){
					if (strcmp((*consulta_alterar).crm, lista_consultas[i].crm) == 0 && strcmp((*consulta_alterar).cpf, lista_consultas[i].cpf) == 0 && (*consulta_alterar).dia == lista_consultas[i].dia && (*consulta_alterar).mes == lista_consultas[i].mes && (*consulta_alterar).ano == lista_consultas[i].ano && strcmp((*consulta_alterar).hora, lista_consultas[i].hora) == 0){
						
						printf("Deseja alterar o CRM(1 = sim/0 = nao)?");
						scanf("%d", &res);
						if(res == 1){
							printf("Insira o CRM do medico (sem pontos ou tracos):");
							scanf("%s", &(*consulta_alterar).crm);
						}
						printf("Deseja alterar o CPF do paciente(1 = sim/0 = nao)?");
						scanf("%d", &res);
						if(res == 1){
							printf("Insira o CPF (sem pontos ou tracos):");
							scanf("%s",&(*consulta_alterar).cpf);
						}
						printf("Deseja alterar a data(1 = sim/0 = nao)?");
						scanf("%d", &res);
						if(res == 1){
							printf("Insira a data (xx xx xxxx):");
							scanf("%d %d %d", &(*consulta_alterar).dia, &(*consulta_alterar).mes, &(*consulta_alterar).ano);
						}
						printf("Deseja alterar a hora(1 = sim/0 = nao)?");
						scanf("%d", &res);
						if(res == 1){
							printf("Insira a hora (sem pontos ou tracos):");
							scanf("%s", &(*consulta_alterar).hora);
						}
						printf("Deseja alterar o diagnóstico(1 = sim/0 = nao)?");
						scanf("%d", &res);
						if(res == 1){
							printf("Insira o diagnóstico:");
							scanf("%s", &(*consulta_alterar).diagnostico);
						}
						printf("Deseja alterar os medicamentos(1 = sim/0 = nao)?");
						scanf("%d", &res);
						if(res == 1){
							printf("Insira a quantidade de medicamentos:");
							scanf("%d", &num_medicamentos1);
							(*consulta_alterar).num_medicamentos = num_medicamentos1;
							for(i = 0; i < num_medicamentos1; i++){
								printf("Insira o medicamento numero %.0d:", i + 1);
								scanf("%s", &(*consulta_alterar).medicamentos[i]);
							}
						}
						achou = 1;
					}
				}
				if (achou == 0)
					printf("Não foi possível alterar a consulta!\n");

				fclose(fp_consultas);
				free(consulta_alterar);
				free(lista_consultas);
				sleep(2);
			}
		}
	}
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

void filtra_especialidade(struct medico *medicos){

	int i, j, encontrou = 0;
	char especialidade1[100];

	FILE *fp_medicos;
	int quantidade_medicos;
	struct medico *lista_medicos;

	if ((fp_medicos = fopen("medicos.dat", "rb")) == NULL){
		printf("Nao foi possivel ler o arquivo");
		exit(0);
	}
	else{
		fseek(fp_medicos, 0, SEEK_END);
		quantidade_medicos = ftell(fp_medicos) / sizeof(struct medico);
		printf("quantidade medicos: %d\n", quantidade_medicos);
		rewind(fp_medicos);
		lista_medicos = (struct medico *)malloc(quantidade_medicos * sizeof(struct medico));
		if(!lista_medicos){
			printf("\n[ERROR]: Não foi possível alocar a memoria");
			exit(0);
		}
		if (fread(lista_medicos, sizeof(struct medico), quantidade_medicos, fp_medicos) != quantidade_medicos)
			printf("Nao foi possivel ler todos os elementos do arquivo");
		//system("cls");
		fflush(stdin);

		printf("Insira a especialidade: ");
		scanf("%s", &especialidade1);

		FILE *arqRelatorio;
		arqRelatorio = fopen("relatorios.txt", "a");
		if (arqRelatorio == NULL){
			printf("Não foi possivel abrir o arquivo");
			exit(0);
		}
		else{
			for(i = 0; i < quantidade_medicos; i++){
				if(strcmp(lista_medicos[i].especialidade, especialidade1) == 0){
					if (encontrou == 0){
						fputs("Todos os médicos com a especialidade: ", arqRelatorio);
						fputs(especialidade1, arqRelatorio);
					}
					fputs("\nMédico:", arqRelatorio);
					fputs("\n\tCRM:", arqRelatorio);
					fputs(lista_medicos[i].crm, arqRelatorio);
					fputs("\n\tNome:", arqRelatorio);
					fputs(lista_medicos[i].nome, arqRelatorio);
					fputs("\n\tData de nascimento:", arqRelatorio);
					fprintf (arqRelatorio, "%d/%d/%d", lista_medicos[i].dia_nasc, lista_medicos[i].mes_nasc, lista_medicos[i].ano_nasc);
					fputs("\n\tSexo:", arqRelatorio);
					fputc(lista_medicos[i].sexo, arqRelatorio);
					fputs("\n\tEspecialidade:", arqRelatorio);
					fputs(lista_medicos[i].especialidade, arqRelatorio);
					fputs("\n\tUniversidade:", arqRelatorio);
					fputs(lista_medicos[i].universidade, arqRelatorio);
					fputs("\n\te-mail:", arqRelatorio);
					for(j = 0; j < lista_medicos[i].n_emails; j++){
						fputs("\n\t\t", arqRelatorio);
						fputs(lista_medicos[i].email[j], arqRelatorio);
					}
					fputs("\n\ttelefones:", arqRelatorio);
					for(j = 0; j < lista_medicos[i].n_telefones; j++){
						fputs("\n\t\t", arqRelatorio);
						fputs(lista_medicos[i].telefone[j], arqRelatorio);
					}
					encontrou++;
				}
			}
			fputs("\n\n", arqRelatorio);
			if (encontrou == 0){
				printf("Nenhum médico com essa especialidade foi encontrado!");
				fclose(arqRelatorio) == 0;
			}
			else{
				if (fclose(arqRelatorio) == 0)
					printf("Relatório gravado com sucesso!");
				else
					printf("Não foi possível gravar o relatório!");
			}
		}
	}
	fclose(fp_medicos);
	free(lista_medicos);
	sleep(2);
}

void menor_idade(struct paciente *pacientes){
	int i, j, idade, encontrou = 0, dia_atual = 17, mes_atual = 4, ano_atual = 2022;

	FILE *fp_pacientes;
	int quantidade_pacientes;
	struct paciente *lista_pacientes;

	if ((fp_pacientes = fopen("pacientes.dat", "rb")) == NULL){
		printf("Nao foi possivel ler o arquivo");
		exit(0);
	}
	else{
		fseek(fp_pacientes, 0, SEEK_END);
		quantidade_pacientes = ftell(fp_pacientes) / sizeof(struct paciente);
		printf("quantidade pacientes: %d\n", quantidade_pacientes);
		rewind(fp_pacientes);
		lista_pacientes = (struct paciente *)malloc(quantidade_pacientes * sizeof(struct paciente));
		if(!lista_pacientes){
			printf("\n[ERROR]: Não foi possível alocar a memoria");
			exit(0);
		}
		if (fread(lista_pacientes, sizeof(struct paciente), quantidade_pacientes, fp_pacientes) != quantidade_pacientes)
			printf("Nao foi possivel ler todos os elementos do arquivo");
		//system("cls");
		fflush(stdin);

		printf("Insira a idade: ");
		scanf("%d", &idade);

		FILE *arqRelatorio;
		arqRelatorio = fopen("relatorios.txt", "a");
		if (arqRelatorio == NULL){
			printf("Não foi possivel abrir o arquivo");
			exit(0);
		}
		else{
			for (i = 0; i < quantidade_pacientes; i++){
				if (lista_pacientes[i].ano_nasc >= ano_atual - idade){
					if (encontrou == 0){
						fputs("Todos os pacientes mais novos que: ", arqRelatorio);
						fputs(idade, arqRelatorio);
					}
					fputs("\nPaciente:", arqRelatorio);
					fputs("\n\tCPF:", arqRelatorio);
					fputs(lista_pacientes[i].cpf, arqRelatorio);
					fputs("\n\tNome:", arqRelatorio);
					fputs(lista_pacientes[i].nome, arqRelatorio);
					fprintf (arqRelatorio, "%d/%d/%d", lista_pacientes[i].dia_nasc, lista_pacientes[i].mes_nasc, lista_pacientes[i].ano_nasc);
					fputs("\n\tSexo:", arqRelatorio);
					fputc(lista_pacientes[i].sexo, arqRelatorio);
					fputs("\n\tPlano:", arqRelatorio);
					fputs(lista_pacientes[i].plano, arqRelatorio);
					fputs("\n\te-mail:", arqRelatorio);
					for(j = 0; j < lista_pacientes[i].n_emails; j++){
						fputs("\n\t\t", arqRelatorio);
						fputs(lista_pacientes[i].email[j], arqRelatorio);
					}
					fputs("\n\ttelefones:", arqRelatorio);
					for(j = 0; j < lista_pacientes[i].n_telefones; j++){
						fputs("\n\t\t", arqRelatorio);
						fputs(lista_pacientes[i].telefone[j], arqRelatorio);
					}
					encontrou++;
				}
			}
			if (encontrou == 0){
				printf("Nenhum médico com essa especialidade foi encontrado!");
				fclose(arqRelatorio) == 0;
			}
			else{
				if (fclose(arqRelatorio) == 0)
					printf("Relatório gravado com sucesso!");
				else
					printf("Não foi possível gravar o relatório!");
			}
		}
	}
	fclose(fp_pacientes);
	free(lista_pacientes);
	sleep(2);
}

void filtra_consultas_dias(struct medico *medicos, struct paciente *pacientes, struct consulta *consultas, int contador_consultas, int contador_medicos, int contador_pacientes){
	int achou = 0, dias_filtro, dias_consulta, i, j, cont_consultas = contador_consultas, cont_medicos = contador_medicos, cont_pacientes = contador_pacientes;
	char crm1[20];
	
	FILE *fp_consultas;
	int quantidade_consultas;
	struct consulta *lista_consultas;
	if ((fp_consultas = fopen("consultas.dat", "rb")) == NULL){
		printf("Nao foi possivel ler o arquivo");
		exit(0);
	}
	else{
		fseek(fp_consultas, 0, SEEK_END);
		quantidade_consultas = ftell(fp_consultas) / sizeof(struct consulta);
		rewind(fp_consultas);
		lista_consultas = (struct consulta *)malloc(quantidade_consultas * sizeof(struct consulta));
	}
	if(!lista_consultas){
		printf("\n[ERROR]: Não foi possível alocar a memoria");
		exit(0);
	}
	else{
		if (fread(lista_consultas, sizeof(struct consulta), quantidade_consultas, fp_consultas) != quantidade_consultas)
			printf("Nao foi possivel ler todos os elementos do arquivo");
		else{
			FILE *fp_pacientes;
			int quantidade_pacientes;
			struct paciente *lista_pacientes;

			if ((fp_pacientes = fopen("pacientes.dat", "rb")) == NULL){
				printf("Nao foi possivel ler o arquivo");
				exit(0);
			}
			else{
				fseek(fp_pacientes, 0, SEEK_END);
				quantidade_pacientes = ftell(fp_pacientes) / sizeof(struct paciente);
				printf("quantidade pacientes: %d\n", quantidade_pacientes);
				rewind(fp_pacientes);
				lista_pacientes = (struct paciente *)malloc(quantidade_pacientes * sizeof(struct paciente));
				if(!lista_pacientes){
					printf("\n[ERROR]: Não foi possível alocar a memoria");
					exit(0);
				}
				else{
					if (fread(lista_pacientes, sizeof(struct paciente), quantidade_pacientes, fp_pacientes) != quantidade_pacientes)
						printf("Nao foi possivel ler todos os elementos do arquivo");
					else{
						system("cls");
						fflush(stdin);

						FILE *fp_medicos;
						int quantidade_medicos;
						struct medico *lista_medicos;

						if ((fp_medicos = fopen("medicos.dat", "rb")) == NULL){
							printf("Nao foi possivel ler o arquivo");
							exit(0);
						}
						else{
							fseek(fp_medicos, 0, SEEK_END);
							quantidade_medicos = ftell(fp_medicos) / sizeof(struct medico);
							printf("quantidade medicos: %d\n", quantidade_medicos);
							rewind(fp_medicos);
							lista_medicos = (struct medico *)malloc(quantidade_medicos * sizeof(struct medico));
							if(!lista_medicos){
								printf("\n[ERROR]: Não foi possível alocar a memoria");
								exit(0);
							}
							else{
								if (fread(lista_medicos, sizeof(struct medico), quantidade_medicos, fp_medicos) != quantidade_medicos)
									printf("Nao foi possivel ler todos os elementos do arquivo");
								else{
									printf("Insira o número de dias: ");
									scanf("%d", &dias_filtro);

									for (i = 0; i < quantidade_consultas; i++){
										dias_consulta = 0;
										if (lista_consultas[i].ano == 2022){
											if(lista_consultas[i].mes == 6)
												dias_consulta = lista_consultas[i].dia;	
											else{
												dias_consulta = lista_consultas[i].dia;
												for (j = lista_consultas[i].mes; j > 0; j--)
													dias_consulta += 31;
											}
										}
										else{
											dias_consulta = lista_consultas[i].dia;
											for (j = lista_consultas[i].mes; j > 0; j--)
												dias_consulta += 31;
											for (j = lista_consultas[i].ano; j < 2022; j++)
												dias_consulta += 365;
										}
										if (dias_consulta <= dias_filtro){
											printf("Consulta:\n");
											achou++;
											
											for(j = 0; j < quantidade_medicos; j++){
												if(strcmp(lista_consultas[i].crm, lista_medicos[j].crm) == 0)
													printf("\tCRM: %s\n\tNome do medico: %s", lista_medicos[j].crm, lista_medicos[j].nome);
											}
											
											for(j = 0; j < cont_pacientes; j++){
												if(strcmp(lista_consultas[i].cpf, lista_pacientes[j].cpf) == 0)
													printf("\n\tCPF: %s\n\tNome do paciente: %s", lista_pacientes[j].cpf, lista_pacientes[j].nome);
											}
											
											printf("\n\tData: %d/%d/%d\n\tHora: %s\n\tDiagnóstico: %s\n", lista_consultas[i].dia, lista_consultas[i].mes, lista_consultas[i].ano, lista_consultas[i].hora, lista_consultas[i].diagnostico);
											for(j = 0; j < lista_consultas[i].num_medicamentos; j++)
												printf("\tMedicamento %d: %s\n", j + 1, lista_consultas[i].medicamentos[j]);
										}

									}
									if(achou == 0)
										printf("Nenhuma consulta encontrada!");
								}
							}
							fclose(fp_medicos);
							free(lista_medicos);
						}
					}
					fclose(fp_pacientes);
					free(lista_pacientes);
				}
			}
			fclose(fp_consultas);
			free(lista_consultas);
		}
	}
	sleep(2);
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
	// FILE *fp_medicos;
	// int quantidade_medicos;
	// if ((fp_medicos = fopen("medicos.dat", "rb+")) == NULL){
	// 		printf("Nao foi possivel ler o arquivo");
	// 		exit(0);
	// 	}else{
	// 		fseek(fp_medicos, 0, SEEK_END);
	// 		quantidade_medicos = ftell(fp_medicos) / sizeof(struct medico);
	// 		printf("%d", quantidade_medicos);
	// 		medicos = (struct medico *)malloc(quantidade_medicos * sizeof(struct medico));
	// 		if(!medicos){
	// 			printf("\n[ERROR]: Não foi possível alocar a memoria");
	// 			exit(0);
	// 		}
	// 		if (fread(medicos, sizeof(struct medico), quantidade_medicos, fp_medicos) != quantidade_medicos)
	// 		printf("Nao foi possivel escrever todos os elementos do arquivo");
	// 	}
	// pacientes = (struct paciente *)malloc(contador_pacientes * sizeof(struct paciente));
	// if(!pacientes){
	// 	printf("\n[ERROR]:Não foi possível alocar a memoria");
	// 	exit;
	// }
	// consultas = (struct consulta *)malloc(contador_consultas * sizeof(struct consulta));
	// if(!consultas){
	// 	printf("\n[ERROR]:Não foi possível alocar a memoria");
	// 	exit;
	// }

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
			        listar_todos_medicos(&medicos, &contador_medicos);
			        break;
			    case 2:
			        listar_um_medico(&medicos, &contador_medicos);
			        break;
			    case 3:
			        Incluir_medico(&medicos, &contador_medicos);
			        break;
			    case 4:
			        alterar_um_medico(&medicos, &contador_medicos);
			        break;
			    case 5:
			        deleta_medico(&medicos, &contador_medicos);
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
			        listar_todos(&consultas, &contador_consultas);
			        break;
			    case 2: 
					listar_um(&consultas, &contador_consultas);
			        break;
			    case 3: 
					incluir_consulta(&consultas, &contador_consultas, &medicos, &contador_medicos, &pacientes, &contador_pacientes);
			        break;
			    case 4:
			        alterar_consulta(&consultas, &contador_consultas);
			        break;
			    case 5:
			        exclui_consulta(&consultas, &contador_consultas);
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
			        filtra_especialidade(&medicos);
			        break;
			    case 2:
			        menor_idade(&pacientes);
			        break;
			    case 3:
			        filtra_consultas_dias(&medicos, &pacientes, &consultas, contador_consultas, contador_medicos, contador_pacientes);
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