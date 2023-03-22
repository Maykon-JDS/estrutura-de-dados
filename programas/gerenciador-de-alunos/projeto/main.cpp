#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct no //ok
{
	struct no* proximo{NULL};
	struct no* anterior{NULL};
	char nome[50]{ NULL };
	float nota{ NULL };
}Aluno;


//ler produto
Aluno criar_aluno();

//imprimir
void imprimir_aluno(Aluno aluno); 
void imprimir_lista(Aluno* end_inicio); 
void alunos_aprovados(Aluno* end_inicio);

//push
void push_inicio(Aluno** end_inicio, Aluno** end_fim); 
void push_fim(Aluno** end_inicio, Aluno** end_fim); 



int main() {
	int qtd{ 0 };
	int opcao;
	Aluno* inicio = NULL;
	Aluno* fim = NULL;
	int loop_while{ 0 };


	do {

		printf("\n0 - Sair \
				\n1 - Listar no Inicio \
				\n2 - Listar no Final \
				\n3 - Lista de Alunos Aprovados \
				\n4 - Imprimir Lista\n");
		scanf("%d", &opcao);
		getchar();

		switch (opcao) {
		case 1:
				push_inicio(&inicio, &fim);
				qtd++;
			break;
		case 2:
				push_fim(&inicio, &fim);
				qtd++;
			break;
		case 3:
			if (qtd >= 5) {
				alunos_aprovados(inicio);
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

	system("PAUSE >nul");
	return 0;
}

Aluno criar_aluno()
{
	Aluno aluno;
	printf("\nDigite o nome do aluno: ");
	gets(aluno.nome);
	printf("Digite o nota do aluno: ");
	cin >> aluno.nota;
	return aluno;
}

void imprimir_aluno(Aluno aluno) 
{
	cout << "Nome:" << aluno.nome << "\n" \
		<< "Nota:" << aluno.nota  << "\n";
}

void imprimir_lista(Aluno* end_inicio) 
{
	printf("\n----------------- LISTA -----------------\n");
	while (end_inicio) {
		imprimir_aluno(*end_inicio);
		cout << "\n";
		end_inicio = end_inicio->proximo;
	}
	printf("\n--------------- FIM LISTA ---------------\n");
}

void alunos_aprovados(Aluno* end_inicio)
{
	printf("\n----------------- LISTA DE ALUNOS APROVADOS -----------------\n");
	int qtd_ap{ 0 };
	while (end_inicio) {
		if (end_inicio->nota >= 7) {
			cout << "\nNome:" << end_inicio->nome << "\n";
			qtd_ap++;
		}
		end_inicio = end_inicio->proximo;
	}
	if (qtd_ap == 0) {
		cout << "\nNenhum aluno aprovado!!!\n";
	}
	printf("\n------------- FIM DA LISTA DE ALUNOS APROVADOS --------------\n");
}


void push_inicio(Aluno** end_inicio, Aluno** end_fim) //ok
{
	Aluno* novo = (Aluno*)malloc(sizeof(Aluno));

	if (novo) {
		*novo = criar_aluno();
		if (*end_inicio == NULL) {
			*end_inicio = novo;
			*end_fim = *end_inicio;
		}
		else {
			Aluno * atual; 
			atual = *end_inicio;
			novo->proximo = atual;
			atual->anterior = novo;
			*end_inicio = novo;
		}
	}
	else {
		printf("\nErro ao alocar memoria...\n");
	}
}

void push_fim(Aluno** end_inicio, Aluno** end_fim) //ok
{
	Aluno* novo = (Aluno*)malloc(sizeof(Aluno));

	if (novo) {
		*novo = criar_aluno();
		if (*end_inicio == NULL) {
			*end_inicio = novo;
			*end_fim = *end_inicio;
		}
		else {
			Aluno* atual; 
			atual = *end_fim;
			novo->anterior = atual;
			atual->proximo = novo;
			*end_fim = novo;
		}
	}
	else {
		printf("\nErro ao alocar memoria...\n");
	}
}







