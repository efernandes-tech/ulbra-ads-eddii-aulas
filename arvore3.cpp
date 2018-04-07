#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>

struct tree {
	char info;
	struct tree *esq, *dir;
};

typedef struct tree *TREEPTR;
typedef struct tree *AVRPTR;

void tInsere(TREEPTR *plist, char x);
AVRPTR tPesq(TREEPTR *plist, char x);
AVRPTR tMaior(TREEPTR *plist);
int tRemove(TREEPTR *plist, char *x);
void emOrdem(TREEPTR t);
void preOrdem(TREEPTR t);
void posOrdem(TREEPTR t);

main() {
	TREEPTR raiz = NULL;
	int op = 0, achou = 0;
	char letra;
	
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
			puts("Informe uma letra a ser inserida na arvore: ");
			scanf("%c", &letra);
			puts("Caminho da insercao: ");
			tInsere(&raiz, letra);
			getch();
		}
		
		if (op == 2) {
			if (raiz == NULL) {
				puts("Arvore vazia");
			} else {
				emOrdem(raiz);
			}
			getch();
		}
		
		if (op == 3) {
			if (raiz == NULL) {
				puts("Arvore vazia");
			} else {
				preOrdem(raiz);
			}
			getch();
		}
		
		if (op == 4) {
			if (raiz == NULL) {
				puts("Arvore vazia");
			} else {
				posOrdem(raiz);
			}
			getch();
		}
		
		
		if (op == 5) {
			/*puts("Informe o valor a ser localizado na arvore: ");
			scanf("%d", &dadodigitado);
			if (localizar(&raiz, dadodigitado) == NULL) {
				puts("\nElemento nao localizado");
			} else {
				puts("\nElemento localizado");
			}
			getch();*/
		}
	} // Fim do while.
}

void tInsere(TREEPTR *plist, char x) {
	printf("tInsere");
}

AVRPTR tPesq(TREEPTR *plist, char x) {
	printf("tPesq");
}

AVRPTR tMaior(TREEPTR *plist) {
	printf("tMaior");
}

int tRemove(TREEPTR *plist, char *x) {
	printf("tRemove");
}

void emOrdem(TREEPTR t) {
	printf("emOrdem");
}

void preOrdem(TREEPTR t) {
	printf("preOrdem");
}

void posOrdem(TREEPTR t) {
	printf("posOrdem");
}

