#define TEXT_MAX 15
struct tipo_cliente
{
	char nome[TEXT_MAX];
	char cpf[TEXT_MAX];
	char telefone[TEXT_MAX];
	int locado;
	char dataEntrega[TEXT_MAX];
};
typedef struct tipo_cliente tpCliente;
tpCliente* cadastros;

struct biblioteca_livro
{
	char livro[TEXT_MAX];
	char ano[TEXT_MAX];
	char autor [TEXT_MAX];
};
typedef struct biblioteca_livro bibliotecaLivro;
bibliotecaLivro* livros;
int CM();
int LM();
int QC();
int QL();

char* ObterNomeCliente(int i);
char* ObterTelefoneCliente(int i);
char* ObterCpfCliente(int i);

int NovosClientes(int i, char nome[], char cpf[], char telefone[]);
int funcaoPesquisar(char nome[], int n);

int RemoverCadastro(int remover);

char* ObterNomeLivro(int i);
char* ObterAutorLivro(int i);
char* ObterAnoLivro(int i);

int NovosLivros(int i, char nomeLivro[], char autor[], char ano[]);

int RemoverLivro(int remover);

int ObterCodigoLivro(int i);

void DefinirCodigoLivro(int codigoCliente, int codigoLivro);

char* EntregaLivro(int i);
void DevoucaoLivro(int i);
void salvarArquivo ();
void abrirArquivo();
