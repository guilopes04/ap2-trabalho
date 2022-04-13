#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

int submenu_consultas()
{
    system("cls");

    struct consulta teste[5];
    strcpy(teste[0].crm, "123");

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
        //listar_todos();
        printf("%s", teste[0].crm);
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
        menu_principal();
        break;
    
    default:
        printf("\nvalor invalido\n");
        break;
    }
}