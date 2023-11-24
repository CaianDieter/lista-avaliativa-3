#include<stdio.h>
#include<math.h>

int main(){
    double aportemensal, taxaderetorno,V;
    int meses = 0;

    scanf("%d %lf %lf",&meses,&aportemensal,&taxaderetorno);
    

    for(int i = 0;i < meses;i++){
    V = 0;  
    V += aportemensal * (1 + taxaderetorno)
     * ((pow((1 + taxaderetorno),i + 1) - 1 )/ taxaderetorno);

    printf("Montante ao fim do mes %d: R$ %.2lf\n",i + 1,V);
    }

    return 0;
}