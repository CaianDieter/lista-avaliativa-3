#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int validaplaca(char *placa);

int validadiasemana(char *dia);

int ultimodiaplacacomdiasemana(char *dia, char *placa);

int main()
{
    char placa[9];
    char dia[15];

    scanf("%s", placa);
    scanf("%s", dia);
    if(!validaplaca(placa) && !validadiasemana(dia)){
        printf("Placa invalida\nDia da semana invalido");
    }
    else if (!validaplaca(placa)){
         printf("Placa invalida");

    }
    else if (!validadiasemana(dia)){
          printf("Dia da semana invalido");

    }
    else if(ultimodiaplacacomdiasemana(dia,placa)){

        printf("%s nao pode circular %s",placa,strlwr(dia));

    }else if(strcmp(dia,"SABADO") == 0 || strcmp(dia,"DOMINGO") == 0){
        printf("Nao ha proibicao no fim de semana");
        
    }
    else if(!ultimodiaplacacomdiasemana(dia,placa)){
        printf("%s pode circular %s",placa,strlwr(dia));

    }
        
    
   

    return 0;
}

int validaplaca(char *placa)
{

    if (strlen(placa) == 8 && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) &&
        placa[3] == '-' && isdigit(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]) && isdigit(placa[7]))
    {
        return 1;
    }
    else if (strlen(placa) == 7 && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) &&
             isdigit(placa[3]) && isalpha(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]))
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