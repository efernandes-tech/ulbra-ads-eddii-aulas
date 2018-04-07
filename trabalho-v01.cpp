#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.c>

typedef struct arvore {
	int dado;
	struct arvore *direita, *esquerda;
} *tipo;

void inserir(tipo *nodo, int n);
void listarEmOrdem(tipo nodo);
int remover(tipo *plist, char *x);
tipo localizar(tipo *nodo, int n);

main() {
	tipo raiz = NULL;
	int op = 0, achou = 0, dadodigitado;
	
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
			puts("Informe o valor a ser inserido na arvore: ");
			scanf("%d", &dadodigitado);
			puts("Caminho da insercao: ");
			inserir(&raiz, dadodigitado);
			getch();
		}
		
		if (op == 2) {
			if (raiz == NULL) {
				puts("Arvore vazia");
			} else {
				listarEmOrdem(raiz);
			}
			getch();
		}
		
		if (op == 3) {
			puts("Informe o valor a ser localizado na arvore: ");
			scanf("%d", &dadodigitado);
			if (localizar(&raiz, dadodigitado) == NULL) {
				puts("\nElemento nao localizado");
			} else {
				puts("\nElemento localizado");
			}
			getch();
		}
	} // Fim do while.
}

void inserir(tipo *nodo, int n) {
	printf("inserir");
	/*
	if ((*nodo) == NULL) {
		(*nodo) = (struct arvore *) malloc(sizeof(struct arvore));
		(*nodo)->direita = NULL;
		(*nodo)->dado = n;
		(*nodo)->esquerda = NULL;
		puts("Raiz");
	} else {
		if (n < (*nodo)->dado) {
			inserir(&(*nodo)->esquerda, n);
			puts("Esquerda");
		} else {
			inserir(&(*nodo)->direita, n);
			puts("Direita");
		}
	}
	*/
}

void listarEmOrdem(tipo nodo) {
	printf("listarEmOrdem");
	/*
	if (nodo != NULL) {
		emordem(nodo->esquerda);
		printf("%d ", nodo->dado);
		emordem(nodo->direita);
	}
	*/
}

int remover(tipo *plist, char *x) {
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
	}*/
}

tipo localizar(tipo *nodo, int n) {
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
	*/
}

