#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int validaplaca(char *placa);

int validadiasemana(char *dia);

int ultimodiaplacacomdiasemana(char *dia, char *placa);

int main()
{
    char placa[9];
    char dia[15];

    scanf("%s", placa);
    scanf("%s", dia);
    if (validaplaca(placa) && validadiasemana(dia) && ultimodiaplacacomdiasemana(dia, placa))
    {
        printf("%s pode circular %s", placa, dia);
    }
    else
    {
        printf("nao deu nao ");
    }

    return 0;
}

int validaplaca(char *placa)
{

    if (strlen(placa) == 9 && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) &&
        placa[3] == '-' && isdigit(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]) && isdigit(placa[7]))
    {
        return 1;
    }
    else if (strlen(placa) == 7 && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) &&
             isalpha(placa[3]) && isdigit(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]))
    {
        return 1;
    }

    return 0;
}

int validadiasemana(char *dia)
{

    if (strcmp(dia, "SEGUNDA-FEIRA") == 0 || strcmp(dia, "TERCA-FEIRA") == 0 || strcmp(dia, "QUARTA-FEIRA") == 0 ||
        strcmp(dia, "QUINTA-FEIRA") == 0 || strcmp(dia, "SEXTA-FEIRA") == 0 || strcmp(dia, "SABADO") == 0 || strcmp(dia, "DOMINGO") == 0)
    {
        return 1;
    }

    return 0;
}

int ultimodiaplacacomdiasemana(char dia[], char placa[])
{
    int x = strlen(placa);
    int ultimoDigito = placa[x - 1] - '0'; 

    if ((ultimoDigito == 0 || ultimoDigito == 1) && strcmp(dia, "SEGUNDA-FEIRA") == 0)
    {
        return 1;
    }
    else if ((ultimoDigito == 2 || ultimoDigito == 3) && strcmp(dia, "TERCA-FEIRA") == 0)
    {
        return 1;
    }
    else if ((ultimoDigito == 4 || ultimoDigito == 5) && strcmp(dia, "QUARTA-FEIRA") == 0)
    {
        return 1;
    }
    else if ((ultimoDigito == 6 || ultimoDigito == 7) && strcmp(dia, "QUINTA-FEIRA") == 0)
    {
        return 1;
    }
    else if ((ultimoDigito == 8 || ultimoDigito == 9) && strcmp(dia, "SEXTA-FEIRA") == 0)
    {
        return 1;
    }

    return 0;
}