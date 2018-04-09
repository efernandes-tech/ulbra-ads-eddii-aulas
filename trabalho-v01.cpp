#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <conio.c>

typedef struct aluno {
	char nomeCompleto[50];
	float mediaFinal;
	int anoCursou;
	struct aluno *direita, *esquerda;
} *turma;

void inserir(turma *aluno, char nome[50], float media, int ano);
void listarEmOrdem(turma aluno);
// int remover(tipo *plist, char *x);
// tipo localizar(tipo *nodo, int n);

main() {
	turma t = NULL;
	int op = 0, achou = 0;
	char nome[50];
	float media;
	int ano;

	while (op != 6) {
		system("cls");
		printf("Menu de op%c%ces\n", 135, 228);
		puts("1 - Inserir");
		puts("2 - Listar Em-ordem");
		puts("3 - Remover");
		puts("6 - Sair");
		
		printf("Escolha uma op%c%co: ", 135, 198);
		scanf("%d", &op);
		fflush(stdin);
		system("cls");
		
		if (op == 1) {
			printf("Nome.........................: ");
			fflush(stdin);
			fgets(nome,50,stdin);
			printf("Media........................: ");
			scanf("%f",&media);
			printf("Ano..........................: ");
			scanf("%i",&ano);
			inserir(&t, nome, media, ano);
			getch();
		}
		
		if (op == 2) {
			if (t == NULL) {
				puts("Arvore vazia");
			} else {
				listarEmOrdem(t);
			}
			getch();
		}
		
		/*if (op == 3) {
			puts("Informe o valor a ser localizado na arvore: ");
			scanf("%d", &dadodigitado);
			if (localizar(&raiz, dadodigitado) == NULL) {
				puts("\nElemento nao localizado");
			} else {
				puts("\nElemento localizado");
			}
			getch();
		}*/
	} // Fim do while.
}

void inserir(turma *aluno, char nome[50], float media, int ano) {
	//printf("inserir");
	if ((*aluno) == NULL) {
		(*aluno) = (struct aluno *) malloc(sizeof(struct aluno));
		(*aluno)->direita = NULL;
		strcpy((*aluno)->nomeCompleto,nome);
		(*aluno)->mediaFinal = media;
		(*aluno)->anoCursou = ano;
		(*aluno)->esquerda = NULL;
		puts("Raiz");
	} else {
		// if (n < (*nodo)->dado) {
		if (true) {
			inserir(&(*aluno)->esquerda, nome, media, ano);
			puts("Esquerda");
		} else {
			inserir(&(*aluno)->direita, nome, media, ano);
			puts("Direita");
		}
	}
}

void listarEmOrdem(turma aluno) {
	//printf("listarEmOrdem");
	if (aluno != NULL) {
		listarEmOrdem(aluno->esquerda);
		
		printf("Nome....: %s \n",aluno->nomeCompleto);
		printf("Media...: %.1f \n",aluno->mediaFinal);
		printf("Ano.....: %i \n",aluno->anoCursou);
		
		listarEmOrdem(aluno->direita);
	}
}

/*int remover(tipo *plist, char *x) {
	printf("remover");
	/*
	TREEPTR p;
	if (*plist==NULL) {
		return (1);
	}
	if ((*x == (*plist)->info) == 1) {
		p=*plist;
		if ((*plist)->esq == NULL) {
			// A raiz nao tem filho esquerdo.
			*plist=(*plist)->dir;
		} else if ((*plist)->dir == NULL) {
			// A raiz nao tem filho direito.
			*plist=(*plist)->esq;
		} else {
			// A raiz tem ambos os filhos.
			p=tMaior(&((*plist)->esq));
			(*plist)->info = p->info;
		}
		free(p);
		printf("\nElemento achado e removido");
	} else if ((*x < (*plist)->info) == 1) {
		remover(&((*plist)->esq), x);
	} else {
		remover(&((*plist)->dir), x);
	}* /
}*/

/*tipo localizar(tipo *nodo, int n) {
	printf("localizar");
	/*
	if ((*nodo) == NULL) {
		return(NULL);
	} else {
		if ((*nodo)->dado == n) {
			return(*nodo);
		} else {
			if (n < (*nodo)->dado) {
				return(localizar(&(*nodo)->esquerda, n));
			} else {
				return(localizar(&(*nodo)->direita, n));
			}
		}
	}
	* /
}*/

