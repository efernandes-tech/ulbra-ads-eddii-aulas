#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct tree{
	int info;
	struct tree *esq, *dir;
} *raiz, *novo, *plist;

unsigned insere(struct tree *plist1, int inf) {
	struct tree *raiz1;
	if (plist1 == NULL) {
		novo = (struct tree *) malloc(sizeof(struct tree));
		novo->info = inf;
		novo->esq = NULL;
		novo->dir = NULL;
		plist1 = novo;
		printf("\nElemento inserido na RAIZ!");
	} else {
		if (inf < plist1->info) {
			printf("\nPara a ESQUERDA!");
			if (plist1->esq == NULL) {
				raiz1 = plist1;
			}
			plist1 = insere(plist1->esq, inf);
			if (plist1->esq == NULL) {
				raiz1->esq = plist1;
			}
		} else {
			if (inf > plist1->info) {
				printf("\nPara a DIREITA!");
				if (plist1->dir == NULL) {
					raiz1 = plist1;
				}
				plist1 = insere(plist1->dir, inf);
				if (plist1->dir == NULL) {
					raiz1->dir = plist1;
				}
			}
		}
	}
	return(plist1);
}

void emordem(struct tree *raiz1) {
	if (raiz1 != NULL) {
		emordem(raiz1->esq);
		printf("\n\nEndereco ... esquerda: %u", raiz1->esq);
		printf("\nEndereco %u ---> Elemento: %d", raiz1, raiz1->info);
		printf("\nEndereco --- Direita: %u", raiz1->dir);
		emordem(raiz1->dir);
	}
}

void destruir(struct tree *raiz1) {
	if (raiz1 != NULL) {
		destruir(raiz1->esq);
		destruir(raiz1->dir);
		free(raiz1);
		printf("\nLiberado elemento:%d, do endereco : %u!", raiz1->info, raiz1);
	}
}

int inf=0;
char resp = 's';

void main(void) {
	clsscr();
	raiz = NULL;
	
	printf("Digite um valor:");
	scanf("%d", &inf);
	
	raiz = insere(raiz, inf);
	
	printf("Conteudo de raiz: %u", raiz);
	
	while(resp == 's'){
		printf("\nDeseja continuar ( s/n )?");
		getchar();
		if (getchar() == 's') {
			printf("Digite outro valor: ");
			scanf("%d",&inf);
			plist = insere(raiz, inf);
			printf("Conteudo de PLIST %u", plist):
		} else {
			break;
		}
	}
	printf("\n\n ...ELEMENTOS(emordem)---");
	emordem(raiz);
	getch();
	printf("\n\n...DESTRUINDO(posordem)...");
	destruir(raiz);
	getch();
}

