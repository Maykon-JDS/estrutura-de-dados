#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

typedef struct no 
{
	struct no* proximo{NULL};
	char nome[50]{NULL};
	float salario{NULL};
}Funcionario;


//ler funcionario
Funcionario criar_funcionario();

//imprimir
void imprimir_funcionario(Funcionario funcionario);
void imprimir_lista(Funcionario* end_inicio); 
void imprimir_maior_salario(Funcionario* end_inicio);
void media_salarial(Funcionario* end_inicio);
void qtd_func_c_salario_superior_a_n(Funcionario* end_inicio);


//push
void inserir_ordenado_crescente(Funcionario** end_inicio);
void inserir_ordenado_decrescente(Funcionario** end_inicio);




int main() {
	Funcionario* inicio{NULL};
	int qtd{ 0 };
	
	int loop_while{ 0 };


	do {
		int opcao{ NULL };
		printf("\n0 - Sair \
				\n1 - Listar \
				\n2 - Funcionario com Maior Salario \
				\n3 - Media Salarial \
				\n4 - QTD. de Funcionarios com salario maior que N \
				\n5 - Imprimir Lista Completa\n");
		scanf_s("%d", &opcao);
		getchar();

		switch (opcao) {
		case 1:
				inserir_ordenado_decrescente(&inicio);
				qtd++;
		break;
		case 2:

			if (qtd >= 8) {
				imprimir_maior_salario(inicio);
			}
			else
			{
				cout << "\nPara mostrar o(s) funcionario(s) \ncom o(s) maior(es) salario(s) \nprecisa ter no minimo 8 Funcionarios!!!\n";
				cout << "\nQuantidade de Funcionarios Atualmente:" << qtd << "\n";
			}

			break;
		case 3:
			
			if (qtd >= 8) {
				media_salarial(inicio);
			}
			else
			{
				cout << "\nPara mostrar a media salarial precisa ter no minimo 8 Funcionarios!!!\n";
				cout << "\nQuantidade de Funcionarios Atualmente:" << qtd << "\n";
			}
			
			break;
		case 4:
			qtd_func_c_salario_superior_a_n(inicio);
			
			
			break;
		case 5:
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
	float total{0};
	int qtd{0};
	while (end_inicio) {
		total += end_inicio->salario;
		qtd++;
		end_inicio = end_inicio->proximo;
	}
	cout << "\nMedia Salarial = R$" << total / qtd  <<  "\n";
}

void qtd_func_c_salario_superior_a_n(Funcionario* end_inicio)
{
	float n_salario;
	cout << "\nDigite o salario usado pra a comparacao: R$";
	cin >> n_salario;
	int qtd{ 0 };
	
	while (end_inicio) {
		if (end_inicio->salario > n_salario) {
			qtd++;
		}
		end_inicio = end_inicio->proximo;
	}
	if (qtd == 1) {
		cout << "\nExiste um funcionario com o salario maior que R$" << n_salario << "\n";
	}
	else if (qtd > 1) {
		cout << "\nExistem "<< qtd <<" funcionarios com o salario maior que R$" << n_salario << "\n";
	}
	else {
		cout << "\nNao existem funcionarios com o salario maior que R$" << n_salario << "\n";
	}
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
	gets_s(funcionario.nome);
	printf("\nDigite o salario do funcionario: R$");
	cin >> funcionario.salario;

	return funcionario;
}

void inserir_ordenado_crescente(Funcionario** end_inicio)
{
	Funcionario* aux = NULL;
	Funcionario	* novo = (Funcionario*)malloc(sizeof(Funcionario));

	if (novo) {
		
		*novo = criar_funcionario();
		
		if (*end_inicio == NULL) {
			novo->proximo = NULL;
			*end_inicio = novo;
		}
		else if(novo->salario < (* end_inicio)->salario) {
			novo->proximo = *end_inicio;
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
						novo->proximo = aux->proximo;
						aux->proximo = novo;
						loop_inserir = 1;
					}
					else if (aux->proximo == NULL) {
						aux->proximo = novo;
						loop_inserir = 1;
					}
					else {
						printf("\nError!\n");
					}
				}
			}
			else
			{
				(* end_inicio)->proximo = novo;
			}
		}
		else{
			aux = *end_inicio;
			novo->proximo = aux->proximo;
			aux->proximo = novo;
		}
	}
	else {
		printf("\nError ao alocar memoria!\n");
	}
}

void inserir_ordenado_decrescente(Funcionario** end_inicio)
{
	Funcionario* aux = NULL;
	Funcionario* novo = (Funcionario*)malloc(sizeof(Funcionario));

	if (novo) {

		*novo = criar_funcionario();

		if (*end_inicio == NULL) {
			novo->proximo = NULL;
			*end_inicio = novo;
		}
		else if (novo->salario > (*end_inicio)->salario) {
			novo->proximo = *end_inicio;
			*end_inicio = novo;
		}
		else if (novo->salario < (*end_inicio)->salario) {
			aux = *end_inicio;
			int loop_inserir{ 0 };

			if (aux->proximo) {
				while (loop_inserir == 0) {
					if (aux->proximo && novo->salario < aux->proximo->salario) {
						aux = aux->proximo;
					}
					else if (aux->proximo && novo->salario > aux->proximo->salario) {
						novo->proximo = aux->proximo;
						aux->proximo = novo;
						loop_inserir = 1;
					}
					else if (aux->proximo && novo->salario == aux->proximo->salario) {
						aux = aux->proximo;
					}
					else if (aux->proximo == NULL) {
						aux->proximo = novo;
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
				else {
					novo->proximo = aux->proximo;
					aux->proximo = novo;
					loop_inserir = 1;
				}
			}
			
		}
	}
	else {
		printf("\nError ao alocar memoria!\n");
	}
}