#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int submenu_medicos()
{
    system("cls");
    int res = 0;
    printf("SUBMENU MEDICOS\n\n");
    printf("1. Listar Todos\n");
    printf("2. Listar Um Item\n");
    printf("3. Incluir Item\n");
    printf("4. Alterar Item\n");
    printf("5. Excluir Item\n");
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