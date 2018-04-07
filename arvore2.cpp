#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct arvore {
	int dado;
	struct arvore *direita, *esquerda;
} *tipo;

void inserir(tipo *nodo, int n);
void emordem(tipo nodo);
void preordem(tipo nodo);
void posordem(tipo nodo);
tipo localizar(tipo *nodo, int n);

main() {
	tipo raiz = NULL;
	int op = 0, achou = 0, dadodigitado;
	
	while (op != 6) {
		system("cls");
		printf("Menu de op%c%ces\n", 135, 228);
		puts("1 - Inserir elemento");
		puts("2 - Listar Em-ordem");
		puts("3 - Pre-ordem");
		puts("4 - Pos-ordem");
		puts("5 - Localizar");
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
				emordem(raiz);
			}
			getch();
		}
		
		if (op == 3) {
			if (raiz == NULL) {
				puts("Arvore vazia");
			} else {
				preordem(raiz);
			}
			getch();
		}
		
		if (op == 4) {
			if (raiz == NULL) {
				puts("Arvore vazia");
			} else {
				posordem(raiz);
			}
			getch();
		}
		
		
		if (op == 5) {
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
}

void emordem(tipo nodo) {
	if (nodo != NULL) {
		emordem(nodo->esquerda);
		printf("%d ", nodo->dado);
		emordem(nodo->direita);
	}
}

void preordem(tipo nodo) {
	if (nodo != NULL) {
		printf("%d ", nodo->dado);
		preordem(nodo->esquerda);
		preordem(nodo->direita);
	}
}

void posordem(tipo nodo) {
	if (nodo != NULL) {
		posordem(nodo->esquerda);
		posordem(nodo->direita);
		printf("%d ", nodo->dado);
	}
}

tipo localizar(tipo *nodo, int n) {
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
}

