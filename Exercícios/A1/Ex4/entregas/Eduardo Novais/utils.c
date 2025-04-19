#include "utils.h"

void limpar_buffer(){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

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

int validarString(char *nome) { // Adicionei essa função para validar string, se o usuario digitar um numero no lugar do nome ele retornar um erro
    size_t len = strlen(nome);

    if (len > 0 && nome[len - 1] == '\n') {
        nome[len - 1] = '\0';
        len--;
    }

    if (len == 0) {
        printf("Nome invalido. O nome nao pode estar vazio.\n");

        return 0;
    }

    for (size_t i = 0; i < len; i++) {
        if (!isalpha(nome[i]) && nome[i] != ' ') {
            printf("Nome invalido. Utilize apenas letras e espacos.\n");

            return 0;
        }
    }

    return 1;
}

Usuario *realocar_memoria_usuario(Usuario *usuarios, int novo_tamanho) {
    if(usuarios != NULL) {
        Usuario *temp = (Usuario*) realloc(usuarios, novo_tamanho * sizeof(Usuario));

        if(temp == NULL) {
            perror("Erro ao realocar!");

            limpar_buffer();

            exit(1);
        }

        usuarios = temp;

        return usuarios;
    }

    usuarios = (Usuario*) malloc(novo_tamanho * sizeof(Usuario));

    return usuarios;
}

Carro *realocar_memoria_carro(Carro *carros, int novo_tamanho) {
    if(carros != NULL) {
        Carro *temp = (Carro*) realloc(carros, novo_tamanho * sizeof(Carro));

        if(temp == NULL) {
            perror("Erro ao realocar!");

            limpar_buffer();

            exit(1);
        }

        carros = temp;

        return carros;
    }

    carros = (Carro*) malloc(novo_tamanho * sizeof(Carro));

    return carros;
}

void calcular_valor_total(Carro *carro) {
    carro->valor_total = carro->horas * TAXA_POR_HORA;
}

void aprovar_reprovar_carro(Usuario *usuario, Carro *carro) {
    calcular_valor_total(carro);

    if(carro->valor_total < usuario->saldo) {
        printf("Saldo insuficiente para pagar o estacionamento! Reprovado!");

        carro->aprovado = 0;

        exit(1);
    }

    carro->aprovado = 1;
    carro->aprovado = 1;

    usuario->saldo -= carro->valor_total;

    printf("Aprovado!");
}

void solicitar_nova_entrada(Usuario *usuarios, int num_usuarios) {
    Carro novoCarro;
    int idUser;

    printf("Digite seu ID de usuario: ");
    if (scanf("%i", &idUser) != 1) {
        printf("Insira um ID valido!");

        limpar_buffer();

        exit(1);
    }

    Usuario *usuario = buscar_usuario_por_id(usuarios, num_usuarios, idUser);

    if(usuarios == NULL) {
        printf("Usuario nao encontrado!");

        limpar_buffer();

        exit(1);
    }

    limpar_buffer();

    do{
        printf("Digite a placa do carro: ");
        if (fgets(novoCarro.placa, sizeof(novoCarro.placa), stdin) == NULL) {
            printf("\nPlaca invalido!");

            limpar_buffer();

            continue;
        }

        novoCarro.placa[strcspn(novoCarro.placa, "\n")] = '\0';
    } while (!validarString(novoCarro.placa));


    printf("Digite o horario: ");
    if(scanf("%i", &novoCarro.horas) != 1) {
        printf("Insira um horario valido!");

        limpar_buffer();

        exit(1);
    }

    novoCarro.usuario_id = usuario->id;
    novoCarro.ativo = 1;

    aprovar_reprovar_carro(usuarios, &novoCarro);

    adicionar_carro_historico(usuario, novoCarro);
}
