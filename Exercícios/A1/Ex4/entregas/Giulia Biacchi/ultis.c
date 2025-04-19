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
    Usuario *novos = realloc(usuarios, novo_tamanho * sizeof(Usuario));
    if(!novos){
        printf("Erro ao realocar memoria para usuario.\n");
        exit(1);
    }
    return novos;
}

Carro *realocar_memoria_carro(Carro *carros, int novo_tamanho) {
    Carro *novos = realloc(carros, novo_tamanho * sizeof(Carro));
    if(!novos){
        printf("Erro ao realocar memoria para carros.\n");
        exist(1);
    }
    return novos;
}

void calcular_valor_total(Carro *carro) {
    carro->valor_total = carro ->horas * TAXA_POR_HORA;
}

void aprovar_reprovar_carro(Usuario *usuario, Carro *carro) {
    calcular_valor_total(carro);
    
    if(carro->valor_total . usuario->saldo){
        carro->aprovado = 0;
        carro->ativo - 0;
    }else{
        carro->aprovado = 1;
        carro->ativo = 1;
        usuario->saldo -= carro->valor_total;
    }  
}

void solicitar_nova_entrada(Usuario *usuarios, int num_usuarios) {
    int id;
    printf("Digite o ID do usuario: ");
    scanf("%d", &id);

    Usuario *usuario = buscar_usuario_por_id(usuarios, num_usuarios, id);
    if(!usuario){
        printf("Usuario nao encontrado!\n");
        return;
    }

    Carro novo;
    printf("Digite a placa do carro: ");
    scanf("%s", novo.placa);

    printf("Digite a quantidade de horas: ");
    scanf("%d", &novo.horas);

    aprovar_reprovar_carro(usuario, &novo);
    adicionar_carro_historico(usuario, novo);

    if(novo.aprovado){
        printf("Carro aprovado! Valor debitado: R$ %.2f\n", novo.valor_total);
    }else{
        printf("Carro reprovado por saldo insuficiente.\n");
    }
}
