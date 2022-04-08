#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int menu_principal()
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