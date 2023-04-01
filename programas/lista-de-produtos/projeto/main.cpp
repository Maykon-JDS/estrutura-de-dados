#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct no //ok
{
	struct no* proximo;
	long long int codigo;
	float preco;
	int estoque;
}Produto;


//ler produto
Produto criar_produto();

//imprimir
void imprimir_produto(Produto produto); //ok
void mais_que_500(Produto * protudo); //ok
void imprimir_lista(Produto * end_inicio); //ok

//taxa de desconto
void taxa_desconto(Produto* end_inicio, float desconto); //ok


//push
Produto* push_inicio(Produto * end_inicio); //ok
Produto* push_fim(Produto * end_fim); //ok



int main() {
	int qtd{ 0 };
	int opcao;
	Produto* inicio = NULL;
	Produto* fim = NULL;
	int loop_while{ 0 };

	
		do {
			
			printf("\n0 - Sair \
				\n1 - Listar no Inicio \
				\n2 - Listar no Final \
				\n3 - Adicionar Desconto na Lista \
				\n4 - Imprimir\n");
			scanf_s("%d", &opcao);
			getchar();
			
			switch (opcao) {
			case 1:

				if (inicio == NULL) {
					inicio = push_inicio(inicio);
					fim = inicio;
					qtd++;
				}
				else {
					inicio = push_inicio(inicio);
					qtd++;
				}
				break;
			case 2:
				if (inicio == NULL) {
					inicio = push_inicio(inicio);
					fim = inicio;
					qtd++;
				}
				else if (inicio->proximo == NULL) {
					fim = push_fim(fim);
					qtd++;
				}
				else{
					fim = push_fim(fim);
					qtd++;
				}
				break;
			case 3:
				//Desconto
				if (qtd  >= 5) {
					float desconto;
					cout << "\nDigite a taxa de desconto de 0 a 100:\nEx: 10 = 10%\nDesconto de: ";
					cin >> desconto; cout << "%";
					taxa_desconto(inicio, desconto);
					loop_while = 1;
				}
				else
				{
					cout << "\nPara adicionar o desconto precisa incluir 5 produtos!!!\n";
				}
				
				break;
			case 4:
				imprimir_lista(inicio);
				break;
			default:
				if (opcao != 0) {
					printf("\nOpcao invalida!!!\n");
				}
				else
				{
					loop_while = 1;
				}
				
			}
		} while (loop_while == 0);
	
		mais_que_500(inicio);
		system("PAUSE >nul");
	return 0;
}

Produto criar_produto() //ok
{
	Produto produto;
	printf("\nDigite o codigo do produto: ");
	cin >> produto.codigo;
	printf("Digite o preco do produto: ");
	cin >> produto.preco;
	printf("Digite o estoque do produto: ");
	cin >> produto.estoque;
	return produto;
}

void imprimir_produto(Produto produto) //ok
{
	cout << "Codigo:" << produto.codigo << "\n" \
		<< "Preco:" << produto.preco << "\n" \
		<< "Estoque:" << produto.estoque << "\n";
}

void mais_que_500(Produto * produto) //ok
{
	
	int qtd_mais_500{0};
	while (produto)
	{
		
		if (produto->estoque > 500) {
			qtd_mais_500++;
		}
		produto = produto->proximo;
	}
	cout << "\nQuantidade de produtos com quantidade estocada superior a 500: " << qtd_mais_500;
}

void imprimir_lista(Produto* end_inicio) //ok
{
	printf("\n----------------- LISTA -----------------\n");
	while (end_inicio) {
		imprimir_produto(*end_inicio);
		cout << "\n";
		end_inicio = end_inicio->proximo;
	}
	printf("\n--------------- FIM LISTA ---------------\n");
}

void taxa_desconto(Produto* end_inicio, float desconto)
{
	printf("\n\n\n----------------- LISTA COM DESCONTO -----------------\n");
	while (end_inicio) {
		end_inicio->preco = end_inicio->preco * ((100 - desconto)/100);
		imprimir_produto(*end_inicio);
		cout << "\n";
		end_inicio = end_inicio->proximo;
	}
	printf("\n--------------- FIM LISTA COM DESCONTO ---------------\n");
}

Produto* push_inicio(Produto* end_inicio) //ok
{
	Produto* novo = (Produto*)malloc(sizeof(Produto));

	if (novo) {
		*novo = criar_produto();
		novo->proximo = end_inicio;
		return novo;
	}
	else {
		printf("\nErro ao alocar memoria...\n");
	}
	return NULL;
}

Produto* push_fim(Produto* end_fim) //ok
{
	Produto* novo = (Produto*)malloc(sizeof(Produto));

	if (novo) {
		*novo = criar_produto();
		novo->proximo = NULL;
		end_fim->proximo = novo;
		return novo;
	}
	else {
		printf("\nErro ao alocar memoria...\n");
	}
	return NULL;
}







