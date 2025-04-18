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

// ======= IMPLEMENTAÇÕES DAS FUNÇÕES DO ALUNO =======

Usuario *realocar_memoria_usuario(Usuario *usuarios, int novo_tamanho) {

    // Usa realloc para redimensionar o array de usuarios
    Usuario *novo = realloc(usuarios, novo_tamanho * sizeof(Usuario));
    
    // Uma boa pratica, verificar se o realloc funcionou, caso não, o programa irá fechar
    if (novo == NULL) {
        printf("Erro ao realocar memória para usuários!\n");
        exit(1); // Encerra o programa em caso de erro
    }
    
    return novo;
}

Carro *realocar_memoria_carro(Carro *carros, int novo_tamanho) {
    // Usa realloc para redimensionar o array de carros
    Carro *novo = realloc(carros, novo_tamanho * sizeof(Carro));
    
    
    if (novo == NULL) {
        printf("Erro ao realocar memória para carros!\n");
        exit(1); // Encerra o programa em caso de erro
    }
    
    return novo;
}

void calcular_valor_total(Carro *carro) {
    // Calcula o valor total: horas * taxa por hora
    carro->valor_total = carro->horas * TAXA_POR_HORA;
}

void aprovar_reprovar_carro(Usuario *usuario, Carro *carro) {
    // Calcula o valor total do carro
    calcular_valor_total(carro);
    
    // Verifica se o saldo do usuário é suficiente
    if (carro->valor_total <= usuario->saldo) {
        // Aprova o carro
        carro->aprovado = 1;
        carro->ativo = 1;
        // Debita o valor do saldo
        usuario->saldo -= carro->valor_total;
    } else {
        // Reprova o carro
        carro->aprovado = 0;
        carro->ativo = 0;
    }
}

void solicitar_nova_entrada(Usuario *usuarios, int num_usuarios) {
    int id;
    char placa[MAX_PLACA];
    int horas;
    
    // Pede o ID do usuário
    printf("Digite o ID do usuário: ");
    scanf("%d", &id);
    
    // Busca o usuário pelo ID
    Usuario *usuario = buscar_usuario_por_id(usuarios, num_usuarios, id);
    if (usuario == NULL) {
        printf("Usuário não encontrado!\n");
        return;
    }
    
    // Pede a placa do carro
    printf("Digite a placa do carro: ");
    scanf("%s", placa);
    
    // Pede a quantidade de horas
    printf("Digite a quantidade de horas: ");
    scanf("%d", &horas);
    
    // Valida as horas
    if (horas <= 0 || horas > LIMITE_HORAS_ATIVAS) {
        printf("Horas inválidas! Deve ser entre 1 e %d.\n", LIMITE_HORAS_ATIVAS);
        return;
    }
    
    // Cria um novo carro
    Carro novo_carro = {0}; // Inicializa todos os campos com 0
    novo_carro.usuario_id = id;
    strncpy(novo_carro.placa, placa, MAX_PLACA - 1);
    novo_carro.placa[MAX_PLACA - 1] = '\0'; // Garante terminação da string
    novo_carro.horas = horas;
    
    // Aprova ou reprova o carro
    aprovar_reprovar_carro(usuario, &novo_carro);
    
    // Adiciona o carro ao histórico
    adicionar_carro_historico(usuario, novo_carro);
    
    // Informa o resultado
    if (novo_carro.aprovado) {
        printf("Carro aprovado! Valor: R$%.2f | Novo saldo: R$%.2f\n",
               novo_carro.valor_total, usuario->saldo);
    } else {
        printf("Carro reprovado! Saldo insuficiente.\n");
    }
}