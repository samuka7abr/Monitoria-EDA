#include "utils.h"

void listar_usuarios(const Usuario *usuarios, int num_usuarios) {
    printf("=== Lista de Usuários ===\n");
    for (int i = 0; i < num_usuarios; i++) {
        printf("ID: %d | Nome: %s | Saldo: R$ %.2f | Carros: %d\n",
               usuarios[i].id, usuarios[i].nome,
               usuarios[i].saldo, usuarios[i].num_carros);
    }
    printf("=========================\n");
}

void listar_carros(const Usuario *usuarios, int num_usuarios) {
    printf("=== Histórico de Carros ===\n");
    for (int i = 0; i < num_usuarios; i++) {
        printf("Usuário %s (ID: %d)\n", usuarios[i].nome, usuarios[i].id);
        for (int j = 0; j < usuarios[i].num_carros; j++) {
            Carro c = usuarios[i].historico_carros[j];
            printf("  Placa: %s | Horas: %d | Valor: R$%.2f | Aprovado: %s | Ativo: %s\n",
                   c.placa, c.horas, c.valor_total,
                   c.aprovado ? "Sim" : "Não",
                   c.ativo ? "Sim" : "Não");
        }
    }
}

Usuario *buscar_usuario_por_id(Usuario *usuarios, int num_usuarios, int id) {
    for (int i = 0; i < num_usuarios; i++) {
        if (usuarios[i].id == id)
            return &usuarios[i];
    }
    return NULL;
}

void adicionar_carro_historico(Usuario *usuario, Carro novo) {
    usuario->historico_carros = realocar_memoria_carro(usuario->historico_carros, usuario->num_carros + 1);
    usuario->historico_carros[usuario->num_carros] = novo;
    usuario->num_carros++;
}

// ======= PARA O ALUNO IMPLEMENTAR =======

Usuario *realocar_memoria_usuario(Usuario *usuarios, int novo_tamanho) {
    // TODO: implementar com realloc
    return NULL;
}

Carro *realocar_memoria_carro(Carro *carros, int novo_tamanho) {
    return NULL;
}

void calcular_valor_total(Carro *carro) {
    // TODO: valor_total = horas * TAXA_POR_HORA
}

void aprovar_reprovar_carro(Usuario *usuario, Carro *carro) {
    // TODO:
    // - calcular valor
    // - reprovar se valor > saldo
    // - marcar aprovado e ativo
    // - debitar do saldo
}

void solicitar_nova_entrada(Usuario *usuarios, int num_usuarios) {
    // TODO:
    // - pedir ID do usuário
    // - ler placa e horas
    // - calcular e aprovar
    // - adicionar ao histórico
}
