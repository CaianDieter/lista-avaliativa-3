#include <stdio.h>
#include <math.h>

int main() {
    double aportemensal, taxaderetorno, V;
    int meses = 0;

    scanf("%d %lf %lf", &meses, &aportemensal, &taxaderetorno);

    for (int i = 0; i < meses; i++) {
        V = 0; // Resetar V para zero a cada iteração
        /*na funcao pow se eleva a i pois caso se elevasse a 
        meses o resultado seria constante(meses = 12) e queremos 
        que o resultado esquale junto com a funcao . Adicionamos 
        +1 na funcao pois i começa de zero .*/
        V += aportemensal * (1 + taxaderetorno) * ((pow((1 + taxaderetorno), i + 1) - 1) / taxaderetorno);
        printf("%.2lf\n", V);
    }

    return 0;
}