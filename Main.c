#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int res = menu_principal();
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

    return 0;
}