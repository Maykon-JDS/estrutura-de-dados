#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AC_BLACK "\x1b[30m"
#define AC_RED "\x1b[31m"
#define AC_GREEN "\x1b[32m"
#define AC_YELLOW "\x1b[33m"
#define AC_BLUE "\x1b[34m"
#define AC_MAGENTA "\x1b[35m"
#define AC_CYAN "\x1b[36m"
#define AC_WHITE "\x1b[37m"
#define AC_NORMAL "\x1b[m"

typedef struct knot 
{
    char name[100];      
    int price;

    struct knot * next;
    struct knot * previous;
} Car; 


void pushFirst(Car **inicio); 

// TODO: Criar a função para adicionar no final da lista
// TODO: Criar a função para adicionar no meio da lista

// TODO: Criar a função para remover do inicio da lista
// TODO: Criar a função para remover do final da lista
// TODO: Criar a função para remover do meio da lista

Car setCar(); 

void showCarList(Car ** lista);

void showLoopedOptionsPanel(Car ** first);

int setOption(Car ** first);

int main()
{
    Car *first = NULL;

    showLoopedOptionsPanel(&first);
}

Car setCar()
{
    int price;
    Car novo_no;

    printf("Digite o price do no\n");
    scanf("%d", &price);

    novo_no.price = price;
    return novo_no;
}

void pushFirst(Car **first) 
{
    const int KNOT_SIZE  = sizeof(Car);
    Car *newCar = (Car *)calloc(1, KNOT_SIZE);

    printf("\nEndereco do novo no: %p\n", newCar);

    *newCar = setCar();

    newCar->previous = *first;
    *first = newCar;
}

void showCarList(Car ** first)
{
    while (*first != NULL)
    {
        printf("\nValor:%d\n", (*first)->price); 

        first = &((*first)->previous);
    }
}

void showLoopedOptionsPanel(Car ** first)
{
    int loop;

    do {
        loop = setOption(first);
    }
    while (loop == 0);
}

int setOption(Car ** first)
{
    int option;
    
    const int LOOP_ON = 0;
    const int LOOP_OFF = 1;

    printf("Escolha o numero da opcao:\n");
    printf("1 - Adicionar ao inicio da lista\n");
    printf("2 - Mostrar lista\n");
    printf("3 - Sair\n");
    
    scanf("%d", &option);

    switch (option)
    {
    case 1:
            pushFirst(first);
            return LOOP_ON;
        break;
    case 2:
            showCarList(first);
            return LOOP_ON;
        break;
    case 3:
            printf("Saindo...");
            return LOOP_OFF;
        break;
    default:
            printf("\n%sEscolha uma Opcao valida!%s\n", AC_RED, AC_WHITE);
            return LOOP_ON;
        break;
    }
}

