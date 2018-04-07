#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>

struct tree {
	char info;
	struct tree *esq, *dir;
};

typedef struct tree *TREEPTR;

void tInsere(TREEPTR *plist, char x);
TREEPTR tPesq(TREEPTR *plist, char x);
TREEPTR tMaior(TREEPTR *plist);
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
			puts("Informe o valor a ser localizado na arvore: ");
			scanf("%d", &letra);
			if (tPesq(&raiz, letra) == NULL) {
				puts("\nElemento nao localizado");
			} else {
				puts("\nElemento localizado");
			}
			getch();
		}
	} // Fim do while.
}

void tInsere(TREEPTR *plist, char x) {
	if ((*plist) == NULL) {
		*plist=(TREEPTR) malloc (sizeof(struct tree));
		(*plist)->info=x;
		(*plist)->esq=NULL;
		(*plist)->dir=NULL;
	} else {
		if (x < (*plist)->info) {
			tInsere(&((*plist)->esq), x);
		} else {
			tInsere(&((*plist)->dir), x);
		}
	}
}

TREEPTR tPesq(TREEPTR *plist, char x) {
	if (*plist == NULL) {
		return (NULL);
	} else if (x == (*plist)->info) {
		return (*plist);
	} else if (x < (*plist)->info) {
		return (NULL);//*tPesq(&((*plist)->esq), x));
	} else {
		return (NULL);//*tPesq(&((*plist)->dir), x));
	}
}

TREEPTR tMaior(TREEPTR *plist) {
	TREEPTR t;
	t=*plist;
	if (t->dir == NULL) {
		*plist=(*plist)->esq;
		return (t);
	} else {
		return (tMaior(&((*plist)->dir)));
	}
}

int tRemove(TREEPTR *plist, char *x) {
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
		tRemove(&((*plist)->esq), x);
	} else {
		tRemove(&((*plist)->dir), x);
	}
}

void emOrdem(TREEPTR t) {
	if (t != NULL) {
		emOrdem(t->esq);
		printf(" %c,", t->info);
		emOrdem(t->dir);
	}
}

void preOrdem(TREEPTR t) {
	if (t != NULL) {
		printf(" %c, ", t->info);
		preOrdem(t->esq);
		preOrdem(t->dir);
	}
}

void posOrdem(TREEPTR t) {
	if (t!=NULL) {
		posOrdem(t->esq);
		posOrdem(t->dir);
		printf(" %c,", t->info);
	}
}

