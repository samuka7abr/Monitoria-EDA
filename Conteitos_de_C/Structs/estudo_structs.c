
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////////////////////////////////////
// estudo completo sobre structs em linguagem C
// autor: monitoria de estrutura de dados (IDP)
// este arquivo cobre: declaração de structs, typedef,
// inicialização, acesso a membros, ponteiros para structs,
// arrays de structs, passagem para funções e boas práticas
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// declaração de struct tradicional
////////////////////////////////////////////////////////////
struct aluno {
    int RA;
    char nome[50];
    float nota;
};

////////////////////////////////////////////////////////////
// declaração com typedef (evita uso de 'struct' ao declarar)
////////////////////////////////////////////////////////////
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

////////////////////////////////////////////////////////////
// função que recebe struct por valor
////////////////////////////////////////////////////////////
void imprimeAluno(struct aluno a) {
    //imprime os dados de um aluno passado por valor
    printf("RA: %d\n", a.RA);
    printf("Nome: %s\n", a.nome);
    printf("Nota: %.2f\n", a.nota);
}

////////////////////////////////////////////////////////////
// função que recebe ponteiro para struct
////////////////////////////////////////////////////////////
void alteraNota(struct aluno *a, float novaNota) {
    //altera a nota do aluno diretamente
    a->nota = novaNota;
}

////////////////////////////////////////////////////////////
// função que recebe array de structs
////////////////////////////////////////////////////////////
void imprimeTurma(struct aluno turma[], int tamanho) {
    //imprime todos os alunos de uma turma
    for (int i = 0; i < tamanho; i++) {
        imprimeAluno(turma[i]);
        printf("------------------------------\n");
    }
}

////////////////////////////////////////////////////////////
// função que retorna uma struct
////////////////////////////////////////////////////////////
Data criaData(int d, int m, int a) {
    //retorna uma struct Data com os valores preenchidos
    Data data;
    data.dia = d;
    data.mes = m;
    data.ano = a;
    return data;
}

////////////////////////////////////////////////////////////
// função principal
////////////////////////////////////////////////////////////
int main() {
    //inicialização de struct tradicional
    struct aluno aluno1;
    aluno1.RA = 123;
    strcpy(aluno1.nome, "Samuel");
    aluno1.nota = 8.5;

    //uso de typedef: sem escrever 'struct'
    Data hoje = criaData(25, 3, 2025);

    //impressão de dados
    imprimeAluno(aluno1);
    printf("Data: %02d/%02d/%d\n", hoje.dia, hoje.mes, hoje.ano);

    //uso de ponteiro para struct
    alteraNota(&aluno1, 9.3);
    printf("Nota atualizada: %.2f\n", aluno1.nota);

    //array de structs
    struct aluno turma[2] = {
        {456, "Maria", 7.8},
        {789, "João", 6.4}
    };

    //impressão da turma
    imprimeTurma(turma, 2);

    return 0;
}
