// Éderson e Vander.

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
int remover(turma *aluno, char nome[50], int *acho);
turma maior(turma *aluno);
void parentesesAninhados(turma aluno);
void removerQuebraLinha(char *nome);

main() {
	setlocale(LC_ALL, "Portuguese");

	turma t = NULL;

	char nome[50];
	float media;
	int ano;
	
	int op = 0, len = 0, achou = 0;
	
	/*inserir(&t, "maria", 	5, 2010);
	inserir(&t, "jose", 	6, 2010);
	inserir(&t, "marcelo",	7, 2010);
	inserir(&t, "artur" ,	8, 2010);
	inserir(&t, "ana", 		9, 2010);
	inserir(&t, "cezar", 	10, 2010);
	inserir(&t, "claudio", 	11, 2010);
	inserir(&t, "raul", 	12, 2010);
	inserir(&t, "zulmira", 	13, 2010);
	inserir(&t, "vander", 	14, 2010);*/

	while (op != 5) {
		system("cls");

		gotoxy(2,2); printf("===== Menu de Opções =====");
		gotoxy(2,4); printf("1 - Inserir Aluno.");
		gotoxy(2,6); printf("2 - Listar Em-ordem.");
		gotoxy(2,8); printf("3 - Remover Aluno.");
		gotoxy(2,10); printf("4 - Parênteses Aninhados.");
		gotoxy(2,12); printf("5 - Sair.");
		
		gotoxy(2,16); printf("Escolha uma Opção: ");
		scanf("%d", &op);
		fflush(stdin);
		
		system("cls");
		
		if (op == 1) {
			gotoxy(2,2); printf("Cadastro de Aluno: ");
			
			gotoxy(2,4); printf("Nome Completo.........: ");
			fflush(stdin);
			fgets(nome,50,stdin);
			removerQuebraLinha(nome);

			gotoxy(2,6); printf("Media Final (10,0)....: ");
			scanf("%f",&media);

			gotoxy(2,8); printf("Ano Que Cursou........: ");
			scanf("%i",&ano);
			
			gotoxy(2,10); printf("Caminho da inserção: \n\n");

			inserir(&t, nome, media, ano);
			
			printf("\n\nPressione algo para continuar....");
			
			getch();
		}
		
		if (op == 2) {
			if (t == NULL) {
				printf("\n\n\n\n\t\tNenhum aluno cadastrado!\n\n\n\n\n\t Pressione uma tecla para continuar...");
			} else {
				printf("Lista de Alunos:\n\n");
				listarEmOrdem(t);
				printf("\n\nPressione algo para continuar....");
			}
			getch();
		}
		
		if (op == 3) {
			if (t == NULL) {
				printf("\n\n\n\n\t\tNenhum aluno cadastrado!\n\n\n\n\n\t Pressione uma tecla para continuar...");
			} else {
				gotoxy(2,2); printf("Informe o Nome do Aluno: ");
				fflush(stdin);
				fgets(nome,50,stdin);
				removerQuebraLinha(nome);
			
				remover(&t, nome, &achou);
				
				if (achou == 1) {
					gotoxy(2,2); printf("\n\n Aluno encontrado e removido!\n\n Digite algo para continuar....");
					achou = 0;
				} else {
					gotoxy(2,2); printf("\n\n Aluno não encontrado!\n\n Digite algo para continuar....");
				}
			}
			getch();
		}

		if (op == 4) {
			if (t == NULL) {
				printf("\n\n\n\n\t\tNenhum aluno cadastrado!\n\n\n\n\n\t Pressione uma tecla para continuar...");
			} else {
				printf("\n\tRepresentação por Parênteses Aninhados:\n\n\n");
				parentesesAninhados(t);
				printf("\n\n\n\n\n Pressione algo para continuar....");
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
			puts("Esquerda");
			inserir(&(*aluno)->esquerda, nome, media, ano);
		} else {
			puts("Direita");
			inserir(&(*aluno)->direita, nome, media, ano);
		}
	}
}

void listarEmOrdem(turma aluno) {
	if (aluno != NULL) {
		listarEmOrdem(aluno->esquerda);
		
		printf("Nome : %s ", aluno->nomeCompleto);
		printf("\tMedia :%4.1f ", aluno->mediaFinal);
		printf("\tAno : %i \n", aluno->anoCursou);
		
		listarEmOrdem(aluno->direita);
	}
}

int remover(turma *aluno, char nome[50], int *achou) {
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
			t = maior(&((*aluno)->esquerda),(*aluno));
			strcpy((*aluno)->nomeCompleto,t->nomeCompleto);
			(*aluno)->mediaFinal = t->mediaFinal;
			(*aluno)->anoCursou = t->anoCursou;
		}
		free(t);
		*achou = 1;
	} else if (stricmp(nome,(*aluno)->nomeCompleto) < 0) {
		remover(&((*aluno)->esquerda), nome, achou);
	} else {
		remover(&((*aluno)->direita), nome, achou);
	}
}

turma maior(turma *aluno, turma *alunoAnterior) {
	turma t;
	t=*aluno;
	if (t->direita == NULL) {
		if(t->esquerda == NULL)
			*alunoAnterior->
		*aluno=(*aluno)->esquerda;
		return(t);
	} else {
		return(maior(&((*aluno)->direita),&(*aluno));
	}
}

void parentesesAninhados(turma aluno) {
	if (aluno != NULL) {
		printf(" (");
		printf("%s", aluno->nomeCompleto);
		parentesesAninhados(aluno->esquerda);
		parentesesAninhados(aluno->direita);
		printf(") ");
	}
}

void removerQuebraLinha(char *nome) {
	int len = strlen(nome);
	if ((len > 0) && (nome[len - 1] == '\n')) {
		// Remove quebra de linha.
    	nome[--len] = 0;
	}
}

