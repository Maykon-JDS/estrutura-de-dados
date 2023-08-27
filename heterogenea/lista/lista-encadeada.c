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


void pushFirst(Car **first, Car ** last);

void pushLast(Car **first, Car ** last); 

// TODO: Criar a fun��o para adicionar no final da lista
// TODO: Criar a fun��o para adicionar no meio da lista

// TODO: Criar a fun��o para remover do inicio da lista
// TODO: Criar a fun��o para remover do final da lista
// TODO: Criar a fun��o para remover do meio da lista

Car setCar(); 

void showCarList(Car ** lista);

void showLoopedOptionsPanel(Car ** first, Car ** last);

int setOption(Car ** first, Car ** last);

int main()
{
    
    Car *first = NULL;
    Car *last = NULL;

    showLoopedOptionsPanel(&first, &last);

}

Car setCar()
{
    int price;
    Car novo_no;

    printf("Digite o preco do carro:\n");
    scanf("%d", &price);

    novo_no.price = price;
    return novo_no;
}

void pushFirst(Car **first, Car ** last)  // Continuar
{
    const int KNOT_SIZE  = sizeof(Car);
    Car *newCar = (Car *)calloc(1, KNOT_SIZE);

    printf("\nEndereco do novo no: %p\n", newCar);

    *newCar = setCar();

    if(**first == NULL && **last == NULL)
    {
        newCar->previous = NULL;
        newCar->next = NULL;

        *first = newCar
        *last = newCar
    }
    else
    {
        
        newCar->previous = NULL;
        newCar->next = *first

        *first->previous = newCar;

    }

    *first = newCar;
}

void pushLast(Car **first, Car ** last)  // Continuar
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

void showLoopedOptionsPanel(Car ** first, Car ** last)
{
    int loop;

    do {
        loop = setOption(first, last);
    }
    while (loop == 0);
}

int setOption(Car ** first, Car ** last)
{
    int option;
    
    const int LOOP_ON = 0;
    const int LOOP_OFF = 1;

    printf("Escolha o numero da opcao:\n");
    printf("1 - Adicionar ao inicio da lista\n");
    printf("2 - Adicionar ao inicio da lista\n");
    printf("3 - Mostrar lista\n");
    printf("4 - Sair\n");
    
    scanf("%d", &option);

    switch (option)
    {
    case 1:
            pushFirst(first, last);
            return LOOP_ON;
        break;
    case 2:
            pushLast(first, last);
            return LOOP_ON;
        break;
    case 3:
            showCarList(first);
            return LOOP_ON;
        break;
    case 4:
            printf("Saindo...");
            return LOOP_OFF;
        break;
    default:
            printf("\n%sEscolha uma Opcao valida!%s\n", AC_RED, AC_WHITE);
            return LOOP_ON;
        break;
    }
}

