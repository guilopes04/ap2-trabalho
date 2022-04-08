#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int submenu_relatorios()
{
    system("cls");
    int res = 0;
    printf("SUBMENU RELATORIOS\n\n");
    printf("1. Mostrar todos os dados de todos os medicos a partir de uma especialidade\n");
    printf("2. Mostrar todos os dados de todos os pacientes menores de X anos de idade\n");
    printf("3. Mostrar o CRM, o nome do medico, o CPF do paciente, o nome do paciente, data, hora, diagnostico e medicamentos para todas as consultas realizadas nos últimos X dias\n");
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
    
    default:
        printf("\nvalor invalido\n");
        break;
    }
}