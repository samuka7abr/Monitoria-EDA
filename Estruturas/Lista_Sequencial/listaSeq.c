#include <stdio.h>
#include <stdlib.h>
#include "listaSeq.h"

struct lista{
	int qtd;
	Aluno dados[MAX];
};
float calcularNota(float n1, float n2, float n3, float n4, float np) {
    float media_ap = (n1 + n2 + n3 + n4) / 4.0;
    float nota_final = (media_ap * 0.4) + (np * 0.6);
    return nota_final;
}

Lista* criaLista(){

	Lista *li;
	li = (Lista*) malloc(sizeof(struct lista));
	if(li != NULL){
		li->qtd = 0;
	}
	return li;
}

void liberaLista(Lista *li){
	free(li);
}

int tamanhoLista(Lista *li){
	if(li == NULL){
		return -1;
	}else{
		return li->qtd;
	}
}

int listaCheia(Lista *li){
	if(li == NULL){
		return -1;
	}
	
	return (li->qtd == MAX);
}

int listaVazia(Lista *li){
	if(li == NULL) return -1;

	return (li->qtd == 0);
}

void imprimeLista(Lista *li){
	if(li == NULL || listaVazia(li)) return;

	int i;
	for(i = 0; i < li->qtd; i++){
		float mF = calcularNota(li->dados[i].n1, li->dados[i].n2, li->dados[i].n3, li->dados[i].n4, li->dados[i].np);

		printf("RA: %d \n", li->dados[i].RA);
		printf("Nome: %s\n", li->dados[i].nome);
		printf("Notas AP: %.2f - %.2f - %.2f - %.2f \n", li->dados[i].n1, li->dados[i].n2, li->dados[i].n3, li->dados[i].n4);
		printf("Nota da Prova: %.2f\n", li->dados[i].np);
		printf("Média final: %.2f\n", mF);

		for(int i = 0; i < 30 ; i++){
			printf("-");
		}
		printf("\n");
};
}
int insereListaVazia(Lista *li, Aluno al){
	if(li == NULL) return 0;

	li->dados[0] = al;
	li->qtd++;
	
	return 1;
}

int insereListaFinal(Lista *li, Aluno al){
	if(li == NULL) return 0;
	li->dados[li->qtd] = al;
	li->qtd++;

	return 1;
}

int insereListaInicio(Lista *li, Aluno al){
	if(li == NULL || listaVazia(li)) return 0;
	
	for(int i = li->qtd - 1; i >= 0; i--){
		li->dados[i + 1] = li->dados[i];
	}
	li->dados[0] = al;
	li->qtd++;

	return 1;
}