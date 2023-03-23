#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <cctype>

using namespace std;

typedef struct no
{
	struct no* anterior{ NULL };
	struct no* proximo{ NULL };
	char nome[50]{ "\0" };
	float salario{ NULL };
}Funcionario;


//ler funcionario
Funcionario criar_funcionario();

//imprimir
void imprimir_funcionario(Funcionario funcionario);
void imprimir_lista(Funcionario* end_inicio);
void imprimir_lista_com_imposto(Funcionario* end_inicio, float imposto);
void imprimir_funcionario_com_imposto(Funcionario funcionario, float imposto);
void pesquisa_por_letra(Funcionario* end_inicio);


//push
void inserir_ordenado_crescente(Funcionario** end_inicio, Funcionario** end_fim);




int main() {
	Funcionario* inicio{ NULL };
	Funcionario* fim{ NULL };

	int qtd{ 0 };

	int loop_while{ 0 };


	do {
		int opcao{ 0 };
		printf("\n0 - Sair \
				\n1 - Listar \
				\n2 - Imprimir Lista com Imposto \
				\n3 - Pesquisa por Letra do Nome \
				\n4 - Imprimir Lista Completa\n");
		scanf("%d", &opcao);
		getchar();

		switch (opcao) {
		case 1:
			inserir_ordenado_crescente(&inicio, &fim);
			qtd++;
			break;
		case 2:
			if (qtd >= 6) {
				float imposto;
				cout << "\nDigite o valor do imposto (ex: 10 = 10%)\nImposto:";
				cin >> imposto;
				imprimir_lista_com_imposto(inicio, imposto);
			}
			else
			{
				cout << "\nPara mostrar a lista com o imposto aplicado \nprecisa ter no minimo 6 Funcionarios!!!\n";
				cout << "\nQuantidade de Funcionarios Atualmente:" << qtd << "\n";
			}
		
			break;
		case 3:
			if (qtd >= 6) {
				pesquisa_por_letra(inicio);
			}
			else
			{
				cout << "\nPara pesquisar registros \nprecisa ter no minimo 6 Funcionarios!!!\n";
				cout << "\nQuantidade de Funcionarios Atualmente:" << qtd << "\n";
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

	system("PAUSE >nul");
	return 0;
}

void imprimir_funcionario(Funcionario funcionario)
{
	cout << "\nNome: " << funcionario.nome << "\n" \
		<< "Salario: R$" << funcionario.salario << "\n";
}

void imprimir_funcionario_com_imposto(Funcionario funcionario, float imposto)
{
	cout << "\nNome: " << funcionario.nome << "\n" \
		<< "Salario com imposto: R$" << funcionario.salario * ((100 - imposto) / 100) << "";
}

void imprimir_lista_com_imposto(Funcionario* end_inicio, float imposto)
{
	cout << "\n----------------- LISTA COM IMPOSTO DE " << imposto <<"% -------------------\n";
	while (end_inicio) {
		imprimir_funcionario_com_imposto(*end_inicio, imposto);
		cout << "\n";
		end_inicio = end_inicio->proximo;
	}
	printf("\n----------------- FIM LISTA COM IMPOSTO ----------------------------------\n");
}

void imprimir_lista(Funcionario* end_inicio)
{
	printf("\n----------------- LISTA -----------------\n\n");
	while (end_inicio) {
		imprimir_funcionario(*end_inicio);
		cout << "\n";
		end_inicio = end_inicio->proximo;
	}
	printf("\n--------------- FIM LISTA ---------------\n");
}

void imprimir_maior_salario(Funcionario* end_inicio)
{
	Funcionario* aux = end_inicio;
	printf("\n----------------- LISTA -----------------\n\n");
	while (aux) {
		if (end_inicio->salario == aux->salario) {
			imprimir_funcionario(*aux);
			cout << "\n";
		}
		aux = aux->proximo;
	}
	printf("\n--------------- FIM LISTA ---------------\n");
}

void media_salarial(Funcionario* end_inicio)
{
	float total{ 0 };
	int qtd{ 0 };
	while (end_inicio) {
		total += end_inicio->salario;
		qtd++;
		end_inicio = end_inicio->proximo;
	}
	cout << "\nMedia Salarial = R$" << total / qtd << "\n";
}

void pesquisa_por_letra(Funcionario* end_inicio)
{
	int qtd{0};
	char letra;
	cout << "\nDigite a primeira letra do nome: ";
	cin >> letra;

	cout << "\n----------------- LISTA DE NOME QUE COMECA COM " << (char)toupper(letra) << " ------------------\n";
	while (end_inicio) {
		if (tolower(end_inicio->nome[0]) == tolower(letra)) {
			imprimir_funcionario(*end_inicio);
			qtd++;
		}
		end_inicio = end_inicio->proximo;
	}
	if (qtd == 0) {
		cout << "\nNao existe nenhum nome que comece com a letra " << (char)toupper(letra) << "!!!\n";
	}
	printf("\n------------------------- FIM LISTA DE NOME ----------------------------\n");
}

Funcionario* listar_funcionario()
{
	Funcionario* novo = (Funcionario*)malloc(sizeof(Funcionario));

	if (novo) {
		*novo = criar_funcionario();
		return novo;
	}
	else {
		printf("\nErro ao alocar memoria...\n");
	}
	return NULL;
}

Funcionario criar_funcionario()
{
	Funcionario funcionario;
	printf("\nDigite o nome do funcionario: ");
	gets(funcionario.nome);
	printf("\nDigite o salario do funcionario: R$");
	cin >> funcionario.salario;

	return funcionario;
}

void inserir_ordenado_crescente(Funcionario** end_inicio, Funcionario** end_fim)
{
	Funcionario* aux = NULL;
	Funcionario* novo = (Funcionario*)malloc(sizeof(Funcionario));

	if (novo) {

		*novo = criar_funcionario();

		if (*end_inicio == NULL) {
			novo->proximo = NULL;
			novo->anterior = NULL;
			*end_inicio = novo;
			*end_fim = *end_inicio;
		}
		else if (novo->salario < (*end_inicio)->salario) {
			*end_fim = *end_inicio;
			novo->proximo = *end_inicio;
			(*end_inicio)->anterior = novo;
			*end_inicio = novo;
		}
		else if (novo->salario > (*end_inicio)->salario) {
			aux = *end_inicio;
			int loop_inserir{ 0 };

			if (aux->proximo) {
				while (loop_inserir == 0) {
					if (aux->proximo && novo->salario > aux->proximo->salario) {
						aux = aux->proximo;
					}
					else if (aux->proximo && novo->salario < aux->proximo->salario) {
						aux->proximo->anterior = novo;
						novo->proximo = aux->proximo;
						aux->proximo = novo;
						novo->anterior = aux;
						loop_inserir = 1;
					}
					else if (aux->proximo && novo->salario == aux->proximo->salario) {
						aux = aux->proximo;
					}
					else if (aux->proximo == NULL) {
						aux->proximo = novo;
						novo->anterior = aux;
						novo->proximo = NULL;
						loop_inserir = 1;
					}
				}
			}
			else
			{
				(*end_inicio)->proximo = novo;
			}

		}
		else {
			int loop_inserir{ 0 };
			aux = *end_inicio;
			while (loop_inserir == 0) {
				if (aux->proximo && novo->salario == aux->salario && novo->salario == aux->proximo->salario) {
					aux = aux->proximo;
				}
				else if (aux->proximo == NULL) {
					aux->proximo = novo;
					novo->anterior = aux;
					*end_fim = novo;
					loop_inserir = 1;
				}
				else if(aux->proximo) {
					aux->proximo->anterior = novo;
					novo->proximo = aux->proximo;
					aux->proximo = novo;
					novo->anterior = aux;
					loop_inserir = 1;
				}
				else
				{
					printf("\nError ao alocar memoria!\n");
					loop_inserir = 1;

				}
			}

		}
	}
	else{
		printf("\nError ao alocar memoria!\n");
	}
}
