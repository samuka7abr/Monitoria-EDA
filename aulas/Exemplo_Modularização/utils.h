//prototipação

typedef struct cliente{
    int id;
    char[50] nome;
    float saldo;
    Emprestimo* historico;
} Cliente;

void imprimir_cliente(Cliente* cliente, Emprestimo* emprestimo);