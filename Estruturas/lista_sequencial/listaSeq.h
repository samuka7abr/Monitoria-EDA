#define MAX 10

typedef struct aluno{
	int RA;
	char nome[50];
	float n1, n2, n3, n4;
	float np;
} Aluno;
typedef struct lista Lista;

Lista* criaLista();

void liberaLista(Lista *li);
int tamanhoLista(Lista *li);
int listaCheia(Lista *li);
int listaVazia(Lista *li);
void imprimeLista(Lista *li);
void imprimeElemento(Aluno a);
int insereListaVazia(Lista *li, Aluno a);
int insereListaFinal(Lista *li, Aluno a);
int insereListaInicio(Lista *li, Aluno a);

float calcularNota(float n1, float n2, float n3, float n4, float np);
