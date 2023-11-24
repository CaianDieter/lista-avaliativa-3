#include <stdio.h>
#include <math.h>
#include <string.h>

int romanoparadecimal(char simbolos);

int main()
{
    char romano[14];
    int decimal = 0;

    scanf("%s", romano);
    
    int tamanhoromano = strlen(romano);

    for (int i = 0; i < tamanhoromano; i++)
    {
        int atual = romanoparadecimal(romano[i]);
        int proximo = (i + 1 < tamanhoromano) ? romanoparadecimal(romano[i + 1]) : 0;

        if (atual < proximo)
        {
            decimal += proximo - atual;
            i++;
        }
        else
        {
            decimal += atual;
        }
    }

    int binario[10];
    int contadorcasasbinarias = 0;
    int seguradecimal = decimal;

    while (decimal > 0)
    {
        binario[contadorcasasbinarias] = decimal % 2;
        decimal /= 2;

        contadorcasasbinarias++;
    }
    printf("%s na base 2: ", romano);

    for (int j = contadorcasasbinarias - 1; j >= 0; j--)
    {
        printf("%d", binario[j]);
    }
    printf("\n");

    printf("%s na base 10: %d\n", romano, seguradecimal);

    printf("%s na base 16: %x\n", romano, seguradecimal);

    return 0;
}

int romanoparadecimal(char simbolos)
{

    switch (simbolos)
    {

    case 'I':
        return 1;

    case 'V':
        return 5;

    case 'X':
        return 10;

    case 'L':
        return 50;

    case 'C':
        return 100;

    case 'D':
        return 500;

    case 'M':
        return 1000;

    default:
        return 0;
    }
}