#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_PLACA 10
#define TAXA_POR_HORA 5.0
#define LIMITE_HORAS_ATIVAS 24

typedef struct Carro {
    int usuario_id;
    char placa[MAX_PLACA];
    int horas;
    float valor_total;
    int aprovado;  // 1 = sim, 0 = não
    int ativo;     // 1 = está no estacionamento
} Carro;

typedef struct Usuario {
    int id;
    char nome[MAX_NOME];
    float saldo;
    Carro *historico_carros;
    int num_carros;
} Usuario;

// já implementadas
void listar_usuarios(const Usuario *usuarios, int num_usuarios);
void listar_carros(const Usuario *usuarios, int num_usuarios);
Usuario *buscar_usuario_por_id(Usuario *usuarios, int num_usuarios, int id);
void adicionar_carro_historico(Usuario *usuario, Carro novo);

// para implementar
Usuario *realocar_memoria_usuario(Usuario *usuarios, int novo_tamanho);
Carro *realocar_memoria_carro(Carro *carros, int novo_tamanho);
void solicitar_nova_entrada(Usuario *usuarios, int num_usuarios);
void calcular_valor_total(Carro *carro);
void aprovar_reprovar_carro(Usuario *usuario, Carro *carro);

#endif
