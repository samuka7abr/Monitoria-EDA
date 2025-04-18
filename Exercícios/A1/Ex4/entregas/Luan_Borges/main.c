#include "utils.h"

/*
Rodei o codigo com gcc -o main main.c utils.c (não sei o do pq, porém eu tenho de compilar o meu arquivo de funções para que ocorra tudo certo)
e ./main.exe
Eu não sabia se era pra trocar algumas coisas na main, como acentuação ou coisa parecida. Então mantive o mesmo.
*/

int main() {
    Usuario *usuarios = NULL;
    int num_usuarios = 0;
    int opcao;

    // simula cadastro inicial
    usuarios = realocar_memoria_usuario(usuarios, 2);
    usuarios[0] = (Usuario){1, "João", 50.0, NULL, 0};
    usuarios[1] = (Usuario){2, "Maria", 20.0, NULL, 0};
    num_usuarios = 2;

    do {
        printf("\n1 - Nova entrada de carro\n");
        printf("2 - Listar usuários\n");
        printf("3 - Listar histórico de carros\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                solicitar_nova_entrada(usuarios, num_usuarios);
                break;
            case 2:
                listar_usuarios(usuarios, num_usuarios);
                break;
            case 3:
                listar_carros(usuarios, num_usuarios);
                break;
        }
    } while (opcao != 0);

    for (int i = 0; i < num_usuarios; i++) {
        free(usuarios[i].historico_carros);
    }
    free(usuarios);
    return 0;
}
