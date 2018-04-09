#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <locale.h>
#include <conio.c>

typedef struct aluno {
	char nomeCompleto[50];
	float mediaFinal;
	int anoCursou;
	struct aluno *direita, *esquerda;
} *turma;

void inserir(turma *aluno, char nome[50], float media, int ano);
void listarEmOrdem(turma aluno);
int remover(turma *aluno, char nome[50]);
turma maior(turma *aluno);
void parentesesAninhados(turma aluno);

main() {
	setlocale(LC_ALL, "Portuguese");

	turma t = NULL;

	char nome[50];
	float media;
	int ano;
	
	int op = 0;

	while (op != 5) {
		system("cls");

		gotoxy(2,2); printf("===== Menu de Opções =====");
		gotoxy(2,4); printf("1 - Inserir Aluno.");
		gotoxy(2,6); printf("2 - Listar Em-ordem.");
		gotoxy(2,8); printf("3 - Remover Aluno.");
		gotoxy(2,10); printf("4 - Parênteses Aninhados.");
		gotoxy(2,12); printf("5 - Sair");
		
		gotoxy(2,16); printf("Escolha uma Opção: ");
		scanf("%d", &op);
		fflush(stdin);
		
		system("cls");
		
		if (op == 1) {
			gotoxy(2,2); printf("Nome......: ");
			fflush(stdin);
			fgets(nome,50,stdin);

			gotoxy(2,4); printf("Media.....: ");
			scanf("%f",&media);

			gotoxy(2,6); printf("Ano.......: ");
			scanf("%i",&ano);
			
			inserir(&t, nome, media, ano);
			
			getch();
		}
		
		if (op == 2) {
			if (t == NULL) {
				printf("Arvore Vazia!");
			} else {
				listarEmOrdem(t);
			}
			getch();
		}
		
		if (op == 3) {
			gotoxy(2,2); printf("Informe o Nome do Aluno: ");
			fflush(stdin);
			fgets(nome,50,stdin);
			
			remover(&t, nome);
			
			getch();
		}
		
		if (op == 4) {
			if (t == NULL) {
				printf("Arvore Vazia!");
			} else {
				parentesesAninhados(t);
			}
			getch();
		}
	} // Fim do while.
}

void inserir(turma *aluno, char nome[50], float media, int ano) {
	if ((*aluno) == NULL) {
		(*aluno) = (struct aluno *) malloc(sizeof(struct aluno));
		(*aluno)->direita = NULL;
		strcpy((*aluno)->nomeCompleto,nome);
		(*aluno)->mediaFinal = media;
		(*aluno)->anoCursou = ano;
		(*aluno)->esquerda = NULL;
		puts("Raiz");
	} else {
		if (stricmp(nome,(*aluno)->nomeCompleto) < 0) {
			inserir(&(*aluno)->esquerda, nome, media, ano);
			puts("Esquerda");
		} else {
			inserir(&(*aluno)->direita, nome, media, ano);
			puts("Direita");
		}
	}
}

void listarEmOrdem(turma aluno) {
	if (aluno != NULL) {
		listarEmOrdem(aluno->esquerda);
		
		printf("Nome....: %s \n", aluno->nomeCompleto);
		printf("Media...: %.1f \n", aluno->mediaFinal);
		printf("Ano.....: %i \n", aluno->anoCursou);
		
		listarEmOrdem(aluno->direita);
	}
}

int remover(turma *aluno, char nome[50]) {
	turma t;
	if (*aluno==NULL) {
		return (1);
	}
	if (stricmp((*aluno)->nomeCompleto,nome) == 0) {
		t=*aluno;
		if ((*aluno)->esquerda == NULL) {
			// A raiz nao tem filho esquerdo.
			*aluno=(*aluno)->direita;
		} else if ((*aluno)->direita == NULL) {
			// A raiz nao tem filho direito.
			*aluno=(*aluno)->esquerda;
		} else {
			// A raiz tem ambos os filhos.
			t = maior(&((*aluno)->esquerda));
			strcpy((*aluno)->nomeCompleto,t->nomeCompleto);
			(*aluno)->mediaFinal = t->mediaFinal;
			(*aluno)->anoCursou = t->anoCursou;
		}
		free(t);
		gotoxy(2,2); printf("\nAluno encontrado e removido");
	} else if (stricmp(nome,(*aluno)->nomeCompleto) < 0) {
		remover(&((*aluno)->esquerda), nome);
	} else {
		remover(&((*aluno)->direita), nome);
	}
}

turma maior(turma *aluno) {
	turma t;
	t=*aluno;
	if (t->direita == NULL) {
		*aluno=(*aluno)->esquerda;
		return(t);
	} else {
		return(maior(&((*aluno)->direita)));
	}
}

void parentesesAninhados(turma aluno) {
	if (aluno != NULL) {
		printf(" ( ");
		printf("%s", aluno->nomeCompleto);
		parentesesAninhados(aluno->esquerda);
		parentesesAninhados(aluno->direita);
		printf(" ) ");
	}
}

