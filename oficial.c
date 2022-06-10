#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define tamanho 5

//-----------	STRUCTS	  ----------------------------------------------------------------------

struct medico
{
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

struct paciente
{
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

struct consulta
{
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

void listar_todos_medicos()
{
  int voltar = 0, i, j, x;
  FILE *fp_medicos;
  int quantidade_medicos;
  struct medico *lista_medicos;
  if ((fp_medicos = fopen("medicos.dat", "rb+")) == NULL)
  {
    printf("Nao foi possivel ler o arquivo");
    exit(0);
  }
  else
  {
    fseek(fp_medicos, 0, SEEK_END);
    quantidade_medicos = ftell(fp_medicos) / sizeof(struct medico);
    if (quantidade_medicos != 0)
    {
      rewind(fp_medicos);
      lista_medicos = (struct medico *)malloc(quantidade_medicos * sizeof(struct medico));
      if (!lista_medicos)
      {
        printf("\n[ERROR]: NÃƒÂ£o foi possÃƒÂ­vel alocar a memoria");
        exit(0);
      }
      if (fread(lista_medicos, sizeof(struct medico), quantidade_medicos, fp_medicos) != quantidade_medicos)
        printf("Nao foi possivel ler todos os elementos do arquivo");

      system("cls");
      for (i = 0; i < quantidade_medicos; i++)
      {
        int num_emails = lista_medicos[i].n_emails;
        int num_telefones = lista_medicos[i].n_telefones;
        printf("\nMedico %d\n", i + 1);
        printf("CRM: %s\n", lista_medicos[i].crm);
        printf("NOME: %s\n", lista_medicos[i].nome);
        printf("NASCIMENTO: %d/%d/%d\n", lista_medicos[i].dia_nasc, lista_medicos[i].mes_nasc, lista_medicos[i].ano_nasc);
        printf("SEXO: %c\n", lista_medicos[i].sexo);
        printf("ESPECIALIDADE: %s\n", lista_medicos[i].especialidade);
        printf("UNIVERSIDADE: %s\n", lista_medicos[i].universidade);
        for (j = 0; j < num_emails; j++)
        {
          printf("EMAIL %d: %s\n", j + 1, lista_medicos[i].email[j]);
        }
        for (x = 0; x < num_telefones; x++)
        {
          printf("TELEFONE %d: %s\n", x + 1, lista_medicos[i].telefone[x]);
        }
      }
      fclose(fp_medicos);
      free(lista_medicos);
    }
    else
    {
      printf("\nNenhum item cadastrado");
    }
    printf("\ninsira qualquer valor para voltar ao menu de medicos:");
    scanf("%d", &voltar);
  }
}

void listar_um_medico()
{
  int voltar = 0, i, j, x;
  char crm_desejado[10];
  struct medico *medico_desejado;
  FILE *fp_medicos;
  int quantidade_medicos;
  struct medico *lista_medicos;
  medico_desejado = (struct medico *)malloc(sizeof(struct medico)); // aloca mais uma posiÃƒÂ§ÃƒÂ£o no vetor
  int num_emails = 0, num_telefones = 0;
  if ((fp_medicos = fopen("medicos.dat", "rb+")) == NULL)
  {
    printf("Nao foi possivel ler o arquivo");
    exit(0);
  }
  else
  {
    fseek(fp_medicos, 0, SEEK_END);
    quantidade_medicos = ftell(fp_medicos) / sizeof(struct medico);
    rewind(fp_medicos);
    lista_medicos = (struct medico *)malloc(quantidade_medicos * sizeof(struct medico));
    if (!lista_medicos)
    {
      printf("\n[ERROR]: NÃƒÂ£o foi possÃƒÂ­vel alocar a memoria");
      exit(0);
    }
    if (fread(lista_medicos, sizeof(struct medico), quantidade_medicos, fp_medicos) != quantidade_medicos)
      printf("Nao foi possivel ler todos os elementos do arquivo");
    system("cls");
    fflush(stdin);
    printf("Digite o crm do medico que deseja visualizar:");
    scanf("%s", &crm_desejado);
    int achou = 0;
    for (i = 0; i < quantidade_medicos && achou == 0; i++)
    {
      if (strcmp(crm_desejado, lista_medicos[i].crm) == 0)
      {
        int num_emails = lista_medicos[i].n_emails;
        int num_telefones = lista_medicos[i].n_telefones;
        achou = 1;
        printf("CRM: %s\n", lista_medicos[i].crm);
        printf("NOME: %s\n", lista_medicos[i].nome);
        printf("NASCIMENTO: %d/%d/%d\n", lista_medicos[i].dia_nasc, lista_medicos[i].mes_nasc, lista_medicos[i].ano_nasc);
        printf("SEXO: %c\n", lista_medicos[i].sexo);
        printf("ESPECIALIDADE: %s\n", lista_medicos[i].especialidade);
        printf("UNIVERSIDADE: %s\n", lista_medicos[i].universidade);
        for (j = 0; j < num_emails; j++)
        {
          printf("EMAIL %d: %s\n", j + 1, lista_medicos[i].email[j]);
        }
        for (x = 0; x < num_telefones; x++)
        {
          printf("TELEFONE %d: %s\n", x + 1, lista_medicos[i].telefone[x]);
        }
      }
    }
    if (achou == 0)
    {
      printf("crm nÃƒÂ£o existe\n");
    }
    printf("\ninsira qualquer valor para voltar ao menu de medicos:");
    scanf("%d", &voltar);
  }
  fclose(fp_medicos);
  free(lista_medicos);
}

void deleta_medico()
{
  system("cls");
  struct medico *medico_desejado;
  FILE *fp_medicos;
  int quantidade_medicos;
  struct medico *lista_medicos;
  if ((fp_medicos = fopen("medicos.dat", "rb+")) == NULL)
  {
    printf("Nao foi possivel ler o arquivo");
    exit(0);
  }
  fseek(fp_medicos, 0, SEEK_END);
  quantidade_medicos = ftell(fp_medicos) / sizeof(struct medico);
  rewind(fp_medicos);
  lista_medicos = (struct medico *)malloc(quantidade_medicos * sizeof(struct medico));
  if (!lista_medicos)
  {
    printf("\n[ERROR]: NÃƒÂ£o foi possÃƒÂ­vel alocar a memoria");
  }
  if (fread(lista_medicos, sizeof(struct medico), quantidade_medicos, fp_medicos) != quantidade_medicos)
    printf("Nao foi possivel ler todos os elementos do arquivo");
  int i, x;
  char crm_desejado[10];
  printf("Digite o crm do medico que deseja deletar:");
  scanf("%s", &crm_desejado);
  int achou = 0;
  for (i = 0; i < quantidade_medicos && achou == 0; i++)
  {
    if (strcmp(crm_desejado, lista_medicos[i].crm) == 0)
    {
      achou = 1;
      if (quantidade_medicos > 1)
      {
        for (x = i; x < quantidade_medicos; x++)
        {
          printf("x: %d | x + 1: %d\n", lista_medicos[x].crm, lista_medicos[x + 1].crm);
          lista_medicos[x] = lista_medicos[x + 1];
        }
      }
    }
  }
  if (achou == 0)
  {
    printf("crm nao existente");
  }
  else
  {
    if (fwrite(lista_medicos, sizeof(struct medico), quantidade_medicos, fp_medicos) != quantidade_medicos)
    {
      printf("Nao foi possivel escrever todos os elementos do arquivo");
      // sleep(2);
    }
    printf("mÃƒÂ©dico deletado!");
  }
  fclose(fp_medicos);
  free(lista_medicos);
}

void alterar_um_medico()
{
  int voltar = 0;
  char crm_desejado[10];
  char crm1[20], nome1[18], sexo1, especialidade1[100], universidade1[50], emails1[2][50], telefones1[2][20];
  int i = 0, x, num_emails = 0, num_telefones = 0, dia_nasc1 = 0, mes_nasc1 = 0, ano_nasc1 = 0;
  struct medico *medico_desejado;
  FILE *fp_medicos;
  int quantidade_medicos;
  struct medico *lista_medicos;
  if ((fp_medicos = fopen("medicos.dat", "wb+")) == NULL)
  {
    printf("Nao foi possivel ler o arquivo");
    exit(0);
  }
  else
  {
    fseek(fp_medicos, 0, SEEK_END);
    quantidade_medicos = ftell(fp_medicos) / sizeof(struct medico);
    rewind(fp_medicos);
    lista_medicos = (struct medico *)malloc(quantidade_medicos * sizeof(struct medico));
    if (!lista_medicos)
    {
      printf("\n[ERROR]: NÃƒÂ£o foi possÃƒÂ­vel alocar a memoria");
      exit(0);
    }
    if (fread(lista_medicos, sizeof(struct medico), quantidade_medicos, fp_medicos) != quantidade_medicos)
      printf("Nao foi possivel ler todos os elementos do arquivo");
    system("cls");
    printf("Digite o crm do medico que deseja alterar:");
    scanf("%s", &crm_desejado);
    for (i = 0; i < quantidade_medicos; i++)
    {
      int num_emails = lista_medicos[i].n_emails;
      int num_telefones = lista_medicos[i].n_telefones;
      int res = 0;
      if (strcmp(crm_desejado, lista_medicos[i].crm) == 0)
      {
        printf("Deseja alterar o nome(1 = sim/0 = nao)?");
        scanf("%d", &res);
        if (res == 1)
        {
          printf("Insira o nome do medico:");
          scanf("%s", &nome1);
		  strcpy(lista_medicos[i].nome, nome1);
        }
        printf("Deseja alterar a data de nascimento(1 = sim/0 = nao)?");
        scanf("%d", &res);
        if (res == 1)
        {
          printf("Insira a data de nascimento (xx xx xxxx):");
          scanf("%d %d %d", &dia_nasc1, &mes_nasc1, &ano_nasc1);
          lista_medicos[i].dia_nasc = dia_nasc1;
          lista_medicos[i].mes_nasc = mes_nasc1;
          lista_medicos[i].ano_nasc = ano_nasc1;
        }
        printf("Deseja alterar o sexo(1 = sim/0 = nao)?");
        scanf("%d", &res);
        if (res == 1)
        {
          printf("Insira o sexo: ");
          scanf("%s", &sexo1);
          lista_medicos[i].sexo = sexo1;
        }
        printf("Deseja alterar a especialidade(1 = sim/0 = nao)?");
        scanf("%d", &res);
        if (res == 1)
        {
          printf("Insira a especialidade:");
          scanf("%s", &especialidade1);
          strcpy(lista_medicos[i].especialidade, especialidade1);
        }
        printf("Deseja alterar a universidade(1 = sim/0 = nao)?");
        scanf("%d", &res);
        if (res == 1)
        {
          printf("Insira a universidade que se formou:");
          scanf("%s", &universidade1);
          strcpy(lista_medicos[i].universidade, universidade1);
        }
        printf("Deseja alterar os emails(1 = sim/0 = nao)?");
        scanf("%d", &res);
        if (res == 1)
        {
          printf("Insira a quantidade de emails que o medico possui:");
          scanf("%d", &num_emails);
          lista_medicos[i].n_emails = num_emails;
          for (i = 0; i < num_emails; i++)
          {
            printf("Insira o email numero %d:", i + 1);
            scanf("%s", &emails1[i]);
          }
          for (x = 0; x < num_emails; x++)
          {
            strcpy(lista_medicos[i].email[x], emails1[x]);
          }
        }
        printf("Deseja alterar os telefones(1 = sim/0 = nao)?");
        scanf("%d", &res);
        if (res == 1)
        {
          printf("Insira a quantidade de telefones que o medico possui:");
          scanf("%d", &num_telefones);
          lista_medicos[i].n_telefones = num_telefones;
          for (i = 0; i < num_emails; i++)
          {
            printf("Insira o telefone numero %d:", i + 1);
            scanf("%s", &telefones1[i]);
          }
          for (x = 0; x < num_telefones; x++)
          {
            strcpy(lista_medicos[i].telefone[x], telefones1[x]);
          }
        }
      }
      else
      {
        printf("\no crm digitado nÃƒÂ£o existe");
      }
    }
	if (fwrite(lista_medicos, sizeof(struct medico), quantidade_medicos, fp_medicos) != quantidade_medicos)
        printf("Nao foi possivel escrever todos os elementos do arquivo");
    printf("\ninsira qualquer valor para voltar ao menu de medicos:");
    scanf("%d", &voltar);
  }
}

void Incluir_medico()
{
  struct medico *medico_inserir;
  FILE *fp_medicos;
  int quantidade_medicos;
  struct medico *lista_medicos;
  medico_inserir = (struct medico *)malloc(sizeof(struct medico)); // aloca mais uma posiÃƒÂ§ÃƒÂ£o no vetor
  int i = 0, num_emails = 0, num_telefones = 0;
  int achou = 0;
  if ((fp_medicos = fopen("medicos.dat", "ab+")) == NULL)
  {
    printf("Nao foi possivel ler o arquivo");
    exit(0);
  }
  else
  {
    fseek(fp_medicos, 0, SEEK_END);
    quantidade_medicos = ftell(fp_medicos) / sizeof(struct medico);
    rewind(fp_medicos);
    lista_medicos = (struct medico *)malloc(quantidade_medicos * sizeof(struct medico));
    if (!lista_medicos)
    {
      printf("\n[ERROR]: NÃƒÂ£o foi possÃƒÂ­vel alocar a memoria");
      exit(0);
    }
    if (fread(lista_medicos, sizeof(struct medico), quantidade_medicos, fp_medicos) != quantidade_medicos)
      printf("Nao foi possivel ler todos os elementos do arquivo");
    system("cls");
    fflush(stdin);
    printf("Insira o CRM do medico: ");
    scanf("%s", &(*medico_inserir).crm);
    for (i = 0; i < quantidade_medicos && achou != 1; i++)
    {
      if (strcmp((*medico_inserir).crm, lista_medicos[i].crm) == 0)
      {
        printf("Este crm jÃƒÂ¡ existe\n");
        achou = 1;
      }
    }
    if (achou == 0)
    {
      fflush(stdin);
      printf("Insira o nome do medico:");
      gets((*medico_inserir).nome);
      printf("Insira a data de nascimento (xx xx xxxx):");
      scanf("%d %d %d", &(*medico_inserir).dia_nasc, &(*medico_inserir).mes_nasc, &(*medico_inserir).ano_nasc);
      printf("Insira o sexo: ");
      scanf("%s", &(*medico_inserir).sexo);
      printf("Insira a especialidade:");
      scanf("%s", &(*medico_inserir).especialidade);
      printf("Insira a universidade que se formou:");
      scanf("%s", &(*medico_inserir).universidade);
      printf("Insira a quantidade de emails que o medico possui:");
      scanf("%d", &num_emails);
      (*medico_inserir).n_emails = num_emails;
      for (i = 0; i < num_emails; i++)
      {
        printf("Insira o email numero %d:", i + 1);
        scanf("%s", &(*medico_inserir).email[i]);
      }
      printf("Insira a quantidade de telefones que o medico possui:");
      scanf("%d", &num_telefones);
      (*medico_inserir).n_telefones = num_telefones;
      for (i = 0; i < num_emails; i++)
      {
        printf("Insira o telefone numero %d:", i + 1);
        scanf("%s", &(*medico_inserir).telefone[i]);
      }
      if (fwrite(medico_inserir, sizeof(struct medico), 1, fp_medicos) != 1)
        printf("Nao foi possivel escrever todos os elementos do arquivo");
    }
  }
  fclose(fp_medicos);
  free(medico_inserir);
  free(lista_medicos);
  // sleep(2);
}
//-----------	FUNCOES PACIENTES	  ----------------------------------------------------------------------

void listar_todos_pacientes()
{
  int voltar = 0, i, j, x;
  system("cls");
  FILE *fp_pacientes;
  int quantidade_pacientes;
  struct paciente *lista_pacientes;
  int num_emails = 0, num_telefones = 0;
  int achou = 0;
  if ((fp_pacientes = fopen("pacientes.dat", "rb+")) == NULL)
  {
    printf("Nao foi possivel ler o arquivo");
    exit(0);
  }
  else
  {
    fseek(fp_pacientes, 0, SEEK_END);
    quantidade_pacientes = ftell(fp_pacientes) / sizeof(struct paciente);
    rewind(fp_pacientes);
    lista_pacientes = (struct paciente *)malloc(quantidade_pacientes * sizeof(struct paciente));
    if (!lista_pacientes)
    {
      printf("\n[ERROR]: NÃƒÂ£o foi possÃƒÂ­vel alocar a memoria");
      exit(0);
    }
    if (fread(lista_pacientes, sizeof(struct paciente), quantidade_pacientes, fp_pacientes) != quantidade_pacientes)
      printf("Nao foi possivel ler todos os elementos do arquivo");
  for (i = 0; i < quantidade_pacientes; i++)
  {
    int num_emails = lista_pacientes[i].n_emails;
    int num_telefones = lista_pacientes[i].n_telefones;
    printf("\nPaciente %d\n", i + 1);
    printf("CPF: %s\n", lista_pacientes[i].cpf);
    printf("NOME: %s\n", lista_pacientes[i].nome);
    printf("NASCIMENTO: %d/%d/%d\n", lista_pacientes[i].dia_nasc, lista_pacientes[i].mes_nasc, lista_pacientes[i].ano_nasc);
    printf("SEXO: %c\n", lista_pacientes[i].sexo);
    printf("PLANO: %s\n", lista_pacientes[i].plano);
    for (j = 0; j < num_emails; j++)
    {
      printf("EMAIL %d: %s\n", j + 1, lista_pacientes[i].email[j]);
    }
    for (x = 0; x < num_telefones; x++)
    {
      printf("TELEFONE %d: %s\n", x + 1, lista_pacientes[i].telefone[x]);
    }
  }
  printf("\ninsira qualquer valor para voltar ao menu de medicos:");
  scanf("%d", &voltar);
}
free(lista_pacientes);
fclose(fp_pacientes);
}

void listar_um_paciente()
{
  int voltar = 0, i, j, x;
  char cpf_desejado[10];
  system("cls");
  FILE *fp_pacientes;
  int quantidade_pacientes;
  struct paciente *lista_pacientes;
  int num_emails = 0, num_telefones = 0;
  int achou = 0;
  if ((fp_pacientes = fopen("pacientes.dat", "rb+")) == NULL)
  {
    printf("Nao foi possivel ler o arquivo");
    exit(0);
  }
  else
  {
    fseek(fp_pacientes, 0, SEEK_END);
    quantidade_pacientes = ftell(fp_pacientes) / sizeof(struct paciente);
    rewind(fp_pacientes);
    lista_pacientes = (struct paciente *)malloc(quantidade_pacientes * sizeof(struct paciente));
    if (!lista_pacientes)
    {
      printf("\n[ERROR]: NÃƒÂ£o foi possÃƒÂ­vel alocar a memoria");
      exit(0);
    }
    if (fread(lista_pacientes, sizeof(struct paciente), quantidade_pacientes, fp_pacientes) != quantidade_pacientes)
      printf("Nao foi possivel ler todos os elementos do arquivo");
  printf("Digite o cpf do paciente que deseja visualizar:");
  scanf("%s", &cpf_desejado);
  int achou = 0;
  for (i = 0; i < quantidade_pacientes && achou == 0; i++)
  {
    if (strcmp(cpf_desejado, lista_pacientes[i].cpf) == 0)
    {
      int num_emails = lista_pacientes[i].n_emails;
      int num_telefones = lista_pacientes[i].n_telefones;
      achou = 1;
      printf("CPF: %s\n", lista_pacientes[i].cpf);
      printf("NOME: %s\n", lista_pacientes[i].nome);
      printf("NASCIMENTO: %d/%d/%d\n", lista_pacientes[i].dia_nasc, lista_pacientes[i].mes_nasc, lista_pacientes[i].ano_nasc);
      printf("SEXO: %c\n", lista_pacientes[i].sexo);
      printf("PLANO: %s\n", lista_pacientes[i].plano);
      for (j = 0; j < num_emails; j++)
      {
        printf("EMAIL %d: %s\n", j + 1, lista_pacientes[i].email[j]);
      }
      for (x = 0; x < num_telefones; x++)
      {
        printf("TELEFONE %d: %s\n", x + 1, lista_pacientes[i].telefone[x]);
      }
    }
  }
  if (achou == 0)
  {
    printf("cpf nao existe\n");
  }
  printf("\ninsira qualquer valor para voltar ao menu de medicos:");
  scanf("%d", &voltar);
}
	free(lista_pacientes);
	fclose(fp_pacientes);
}

void deleta_paciente()
{
  system("cls");
  char cpf_desejado[10];
  int i, x;
  FILE *fp_pacientes;
  int quantidade_pacientes;
  struct paciente *lista_pacientes;
  int num_emails = 0, num_telefones = 0;
  int achou = 0;
  if ((fp_pacientes = fopen("pacientes.dat", "wb+")) == NULL)
  {
    printf("Nao foi possivel ler o arquivo");
    exit(0);
  }
  else
  {
    fseek(fp_pacientes, 0, SEEK_END);
    quantidade_pacientes = ftell(fp_pacientes) / sizeof(struct paciente);
    rewind(fp_pacientes);
    lista_pacientes = (struct paciente *)malloc(quantidade_pacientes * sizeof(struct paciente));
    if (!lista_pacientes)
    {
      printf("\n[ERROR]: NÃƒÂ£o foi possÃƒÂ­vel alocar a memoria");
      exit(0);
    }
    if (fread(lista_pacientes, sizeof(struct paciente), quantidade_pacientes, fp_pacientes) != quantidade_pacientes)
      printf("Nao foi possivel ler todos os elementos do arquivo");
  printf("Digite o cpf do medico que deseja deletar:");
  scanf("%s", &cpf_desejado);
  int achou = 0;
  for (i = 0; i < quantidade_pacientes && achou == 0; i++)
  {
    if (strcmp(cpf_desejado, lista_pacientes[i].cpf) == 0)
    {
      achou = 1;
      for (x = i; x < quantidade_pacientes; x++)
      {
        lista_pacientes[x] = lista_pacientes[x + 1];
      }
    }
  }
  if (achou == 0)
  {
    printf("crm nao existente");
  }
  else
  {
    if (fwrite(lista_pacientes, sizeof(struct medico), quantidade_pacientes, fp_pacientes) != quantidade_pacientes)
    {
      printf("Nao foi possivel escrever todos os elementos do arquivo");
      // sleep(2);
    }
    printf("mÃƒÂ©dico deletado!");
  }
  fclose(fp_pacientes);
  free(lista_pacientes);
}
}

void alterar_um_paciente()
{
  int voltar = 0;
  char cpf_desejado[10];
  char cpf1[18], nome1[40], sexo1, plano1[20], emails1[2][25], telefones1[2][20];
  int i = 0, x, num_emails = 0, num_telefones = 0, dia_nasc1 = 0, mes_nasc1 = 0, ano_nasc1 = 0;
  system("cls");
  FILE *fp_pacientes;
  int quantidade_pacientes;
  struct paciente *lista_pacientes;
  int achou = 0;
  if ((fp_pacientes = fopen("pacientes.dat", "wb+")) == NULL)
  {
    printf("Nao foi possivel ler o arquivo");
    exit(0);
  }
  else
  {
    fseek(fp_pacientes, 0, SEEK_END);
    quantidade_pacientes = ftell(fp_pacientes) / sizeof(struct paciente);
    rewind(fp_pacientes);
    lista_pacientes = (struct paciente *)malloc(quantidade_pacientes * sizeof(struct paciente));
    if (!lista_pacientes)
    {
      printf("\n[ERROR]: NÃƒÂ£o foi possÃƒÂ­vel alocar a memoria");
      exit(0);
    }
    if (fread(lista_pacientes, sizeof(struct paciente), quantidade_pacientes, fp_pacientes) != quantidade_pacientes)
      printf("Nao foi possivel ler todos os elementos do arquivo");
  printf("Digite o cpf do paciente que deseja alterar:");
  scanf("%s", &cpf_desejado);
  for (i = 0; i < quantidade_pacientes; i++)
  {
    int num_emails = lista_pacientes[i].n_emails;
    int num_telefones = lista_pacientes[i].n_telefones;
    int res = 0;
    if (strcmp(cpf_desejado, lista_pacientes[i].cpf) == 0)
    {
      printf("Deseja alterar o nome(1 = sim/0 = nao)?");
      scanf("%d", &res);
      if (res == 1)
      {
        printf("Insira o nome do medico:");
        scanf("%s", &nome1);
        strcpy(lista_pacientes[i].nome, nome1);
      }
      printf("Deseja alterar a data de nascimento(1 = sim/0 = nao)?");
      scanf("%d", &res);
      if (res == 1)
      {
        printf("Insira a data de nascimento (xx xx xxxx):");
        scanf("%d %d %d", &dia_nasc1, &mes_nasc1, &ano_nasc1);
        lista_pacientes[i].dia_nasc = dia_nasc1;
        lista_pacientes[i].mes_nasc = mes_nasc1;
        lista_pacientes[i].ano_nasc = ano_nasc1;
      }
      printf("Deseja alterar o sexo(1 = sim/0 = nao)?");
      scanf("%d", &res);
      if (res == 1)
      {
        printf("Insira o sexo: ");
        scanf("%s", &sexo1);
        lista_pacientes[i].sexo = sexo1;
      }
      printf("Deseja alterar o plano(1 = sim/0 = nao)?");
      scanf("%d", &res);
      if (res == 1)
      {
        printf("Insira o plano:");
        scanf("%s", &plano1);
        strcpy(lista_pacientes[i].plano, plano1);
      }
      printf("Deseja alterar os emails(1 = sim/0 = nao)?");
      scanf("%d", &res);
      if (res == 1)
      {
        printf("Insira a quantidade de emails que o paciente possui:");
        scanf("%d", &num_emails);
        lista_pacientes[i].n_emails = num_emails;
        for (i = 0; i < num_emails; i++)
        {
          printf("Insira o email numero %d:", i + 1);
          scanf("%s", &emails1[i]);
        }
        for (x = 0; x < num_emails; x++)
        {
          strcpy(lista_pacientes[i].email[x], emails1[x]);
        }
      }
      printf("Deseja alterar os telefones(1 = sim/0 = nao)?");
      scanf("%d", &res);
      if (res == 1)
      {
        printf("Insira a quantidade de telefones que o paciente possui:");
        scanf("%d", &num_telefones);
        lista_pacientes[i].n_telefones = num_telefones;
        for (i = 0; i < num_emails; i++)
        {
          printf("Insira o telefone numero %d:", i + 1);
          scanf("%s", &telefones1[i]);
        }
        for (x = 0; x < num_telefones; x++)
        {
          strcpy(lista_pacientes[i].telefone[x], telefones1[x]);
        }
      }
    }
  }
  if (fwrite(lista_pacientes, sizeof(struct medico), quantidade_pacientes, fp_pacientes) != quantidade_pacientes)
        printf("Nao foi possivel escrever todos os elementos do arquivo");
  free(lista_pacientes);
  fclose(fp_pacientes);
  printf("\ninsira qualquer valor para voltar ao menu de pacientes:");
  scanf("%d", &voltar);
}
}

void Incluir_paciente()
{
  char cpf1[18];
  int i = 0, num_emails = 0, num_telefones = 0;
  system("cls");
  struct paciente *paciente_inserir;
  FILE *fp_pacientes;
  int quantidade_pacientes;
  struct paciente *lista_pacientes;
  paciente_inserir = (struct paciente *)malloc(sizeof(struct paciente)); // aloca mais uma posiÃƒÂ§ÃƒÂ£o no vetor
  int achou = 0;
  if ((fp_pacientes = fopen("pacientes.dat", "ab+")) == NULL)
  {
    printf("Nao foi possivel ler o arquivo");
  }
  else
  {
    fseek(fp_pacientes, 0, SEEK_END);
    quantidade_pacientes = ftell(fp_pacientes) / sizeof(struct paciente);
    rewind(fp_pacientes);
    lista_pacientes = (struct paciente *)malloc(quantidade_pacientes * sizeof(struct paciente));
    if (!lista_pacientes)
    {
      printf("\n[ERROR]: NÃƒÂ£o foi possÃƒÂ­vel alocar a memoria");
      exit(0);
    }
    if (fread(lista_pacientes, sizeof(struct paciente), quantidade_pacientes, fp_pacientes) != quantidade_pacientes)
      printf("Nao foi possivel ler todos os elementos do arquivo");
    
  printf("Insira o CPF do paciente: ");
  scanf("%s", &(*paciente_inserir).cpf);
  for (i = 0; i < quantidade_pacientes && achou != 1; i++)
  {
    if (strcmp((*paciente_inserir).cpf, lista_pacientes[i].cpf) == 0)
    {
      printf("Este cpf ja existe\n");
    }
    else
    {
      printf("Insira o nome do paciente:");
      gets(paciente_inserir->nome);
      printf("Insira a data de nascimento (xx xx xxxx):");
      scanf("%d %d %d", &(*paciente_inserir).dia_nasc, &(*paciente_inserir).mes_nasc, &(*paciente_inserir).ano_nasc);
      printf("Insira o sexo: ");
      scanf("%s", &(*paciente_inserir).sexo);
      printf("Insira o plano:");
      scanf("%s", &(*paciente_inserir).plano);
      printf("Insira a quantidade de emails que o paciente possui:");
      scanf("%d", &(*paciente_inserir).n_emails);
	  for (i = 0; i < num_emails; i++)
      {
        printf("Insira o email numero %d:", i + 1);
        scanf("%s", &(*paciente_inserir).telefone[i]);
      }
      printf("Insira a quantidade de telefones que o paciente possui:");
      scanf("%d", &(*paciente_inserir).n_telefones);
      
      for (i = 0; i < num_emails; i++)
      {
        printf("Insira o telefone numero %d:", i + 1);
        scanf("%s", &(*paciente_inserir).telefone[i]);
      }
    }
  }
  free(paciente_inserir);
  free(lista_pacientes);
  fclose(fp_pacientes);
}
}

//-----------	FUNCOES CONSULTAS	  ----------------------------------------------------------------------

void listar_todos(){
	int i, j;

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

void listar_um(){
    int i, achou = 0;

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

void incluir_consulta(){
    int i, j, num_medicamentos1;
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

void alterar_consulta(){
	int achou = 0, res = 0, i = 0, num_medicamentos1 = 0;
	char medicamentos1[10][50];

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

void exclui_consulta(){
	system("cls");
	int i = 0, achou = 0, x;

	struct consulta *consulta_excluir;
	FILE *fp_consultas;
	int quantidade_consultas;
	struct consulta *lista_consultas;
	consulta_excluir = (struct consulta *)malloc(sizeof(struct consulta));
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
				scanf("%s", &(*consulta_excluir).crm);
				printf("Insira o CPF do paciente: ");
				scanf("%s", &(*consulta_excluir).cpf);
				printf("Insira a data (xx xx xxxx): ");
				scanf("%d %d %d", &(*consulta_excluir).dia, &(*consulta_excluir).mes, &(*consulta_excluir).ano);
				printf("Insira a hora: ");
				scanf("%s", &(*consulta_excluir).hora);

				for(i = 0; i < quantidade_consultas; i++){
					if (strcmp((*consulta_excluir).crm, lista_consultas[i].crm) == 0 && strcmp((*consulta_excluir).cpf, lista_consultas[i].cpf) == 0 && (*consulta_excluir).dia == lista_consultas[i].dia && (*consulta_excluir).mes == lista_consultas[i].mes && (*consulta_excluir).ano == lista_consultas[i].ano && strcmp((*consulta_excluir).hora, lista_consultas[i].hora) == 0){
						for(x = i; x < quantidade_consultas; x++){
							lista_consultas[x] = lista_consultas[x + 1];
						}
						achou = 1;
					}
				}
				if (achou == 0)
					printf("Não foi possível alterar a consulta!\n");

				fclose(fp_consultas);
				free(consulta_excluir);
				free(lista_consultas);
				sleep(2);
			}
		}
	}
}

//-----------	FUNCOES RELATORIOS	  ----------------------------------------------------------------------

void filtra_especialidade(){

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

void menor_idade(){
	int i, j, idade, encontrou = 0, dia_atual = 9, mes_atual = 6, ano_atual = 2022;

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
						fprintf(arqRelatorio, "%d", idade);
						//fputs(idade, arqRelatorio);
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

void filtra_consultas_dias(){
	int achou = 0, dias_filtro, dias_consulta, i, j;
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
											
											for(j = 0; j < quantidade_pacientes; j++){
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

									fclose(fp_medicos);
									free(lista_medicos);
								}
							}
						}
						fclose(fp_pacientes);
						free(lista_pacientes);
					}
				}
			}
			fclose(fp_consultas);
			free(lista_consultas);
			sleep(2);
		}
	}
}

//-----------	MAIN	  ----------------------------------------------------------------------

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int sair = 0;
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
			        listar_todos_medicos();
			        break;
			    case 2:
			        listar_um_medico();
			        break;
			    case 3:
			        Incluir_medico();
			        break;
			    case 4:
			        alterar_um_medico();
			        break;
			    case 5:
			        deleta_medico();
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
			        listar_todos_pacientes();
			        break;
			    case 2:
			        listar_um_paciente();
			        break;
			    case 3:
			        Incluir_paciente();
			        break;
			    case 4:
			        alterar_um_paciente();
			        break;
			    case 5:
			        deleta_paciente();
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
			        listar_todos();
			        break;
			    case 2: 
					listar_um();
			        break;
			    case 3: 
					incluir_consulta();
			        break;
			    case 4:
			        alterar_consulta();
			        break;
			    case 5:
			        //exclui_consulta();
			        break;
			    case 6:
			        sair_consulta = 1;
			        break;
			    
			    default: printf("\nvalor invÃƒÂ¡lido\n");
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
			    printf("3. Mostrar o CRM, o nome do medico, o CPF do paciente, o nome do paciente, data, hora, diagnÃƒÂ³stico e medicamentos para todas as consultas realizadas nos ÃƒÂºltimos X dias\n");
			    printf("4. Voltar ao Menu Principal\n");
			    printf("Digite o recurso desejado: ");
			    scanf("%d", &res);
			    switch (res)
			    {
			    case 1:
			        filtra_especialidade();
			        break;
			    case 2:
			        menor_idade();
			        break;
			    case 3:
			        filtra_consultas_dias();
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