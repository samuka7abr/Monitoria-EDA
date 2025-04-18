#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

#define TAXA_POR_HORA 5.0

// Struct do carro
typedef struct {
    char modelo[50];
    int horas;
    float valor_total;
    int status; // 1 = aprovado, 0 = reprovado
} Carro;

// Struct do usuário
typedef struct {
    char nome[100];
    float saldo;
    Carro *carros;
    int quantidade_carros;
} Usuario;

// Protótipos das funções
Usuario *realocar_memoria_usuario(Usuario *usuarios, int novo_tamanho);
Carro *realocar_memoria_carro(Carro *carros, int novo_tamanho);
void calcular_valor_total(Carro *carro);
void aprovar_reprovar_carro(Usuario *usuario, Carro *carro);
void solicitar_nova_entrada(Usuario *usuarios, int num_usuarios);

#endif
