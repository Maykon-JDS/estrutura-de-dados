#include <stdio.h>

int main(){
    int valores[] = {10,20,30,40,50};

    int tamanhoArray = sizeof(valores)/sizeof(int);

    for (int i = 0; i < tamanhoArray; i++)
    {
        printf("%d\n", valores[i]);
    }
    
    return 0;
}