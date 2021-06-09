#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"
int CLIENTE_MAX=0;
#define TEXT_MAX 15
int LIVRO_MAX=0;

int qtdClientes=0, qtdLivros=0;

int CM()
{
	return CLIENTE_MAX;
}
int LM()
{
	return LIVRO_MAX;
}
int QC()
{
	return qtdClientes;
}
int QL()
{
	return qtdLivros;
}

char* ObterNomeCliente(int i)
{
	return cadastros[i].nome;
}
char* ObterTelefoneCliente(int i)
{
	return cadastros[i].telefone;
}
char* ObterCpfCliente(int i)
{
	return cadastros[i].cpf;
}

int NovosClientes(int i, char nome[], char cpf[], char telefone[])
{
	if (qtdClientes == CLIENTE_MAX)
	{
		CLIENTE_MAX++;
		
		tpCliente* verificaCliente  = (tpCliente*) realloc (cadastros, CLIENTE_MAX * sizeof(tpCliente));
		
		if (verificaCliente==NULL)
		{
			CLIENTE_MAX--;
			return 0;
		}
		else 
		{
			cadastros=verificaCliente;
		}
	}

	cadastros[qtdClientes].locado=-1;
	
	strcpy(cadastros[qtdClientes].nome, nome);
	strcpy(cadastros[qtdClientes].cpf, cpf);
	strcpy(cadastros[qtdClientes].telefone, telefone);
	
	qtdClientes++;
	return 1;
}// FINALIZADA ADI플O DE CLIENTES
int funcaoPesquisar(char nome[], int n)
{
	if (n<0)
	{
		return -1;
	}
	if (strcmp (ObterNomeCliente(n), nome)==0)
	{
		return n;
	}
	else
	{
		funcaoPesquisar(nome, n-1);
	}
}
int RemoverCadastro(int remover)
{
	if (qtdClientes < CLIENTE_MAX*0.4)
	{
		CLIENTE_MAX--;
		
		tpCliente* verificaCliente  = (tpCliente*) realloc (cadastros, CLIENTE_MAX * sizeof(tpCliente));
		
		if (verificaCliente==NULL)
		{
			CLIENTE_MAX++;
			return 0;
		}
		else 
		{
			cadastros=verificaCliente;
		}
	}
	int i;
	for (i=remover; i<CLIENTE_MAX-1; i++)
	{
		strcpy (cadastros[i].nome,cadastros[i+1].nome);	
		strcpy (cadastros[i].cpf, cadastros[i+1].cpf);
		strcpy (cadastros[i].telefone, cadastros[i+1].telefone);
		cadastros[i].locado = cadastros[i+1].locado;
	}
	strcpy (cadastros[qtdClientes-1].nome, "\0");
	strcpy (cadastros[qtdClientes-1].cpf, "\0");
	strcpy (cadastros[qtdClientes-1].telefone, "\0");
	cadastros[qtdClientes-1].locado = -1;
	qtdClientes--;
	return 1;
}// FINALIZADA REMO플O DE CLIENTES
char* ObterNomeLivro(int i)
{
	return livros[i].livro;
}

char* ObterAutorLivro(int i)
{
	return livros[i].autor;
}

char* ObterAnoLivro(int i)
{
	return livros[i].ano;
}

int NovosLivros(int i, char nomeLivro[], char autor[], char ano[])
{
	if (qtdLivros == LIVRO_MAX)
	{
		LIVRO_MAX++;
		bibliotecaLivro* verificaLivro = (bibliotecaLivro*) realloc (livros, LIVRO_MAX * sizeof(bibliotecaLivro));
		if (verificaLivro==NULL)
		{
			LIVRO_MAX--;
			return 0;
		}
		else
		{
			livros=verificaLivro;
		}
	}

	strcpy(livros[qtdLivros].livro, nomeLivro);
	strcpy(livros[qtdLivros].autor, autor);
	strcpy(livros[qtdLivros].ano, ano);
	qtdLivros++;
	return 1;
}// FINALIZADA ADI플O DE LIVROS

int RemoverLivro(int remover)
{
	if (qtdLivros < LIVRO_MAX*0.4)
	{
		LIVRO_MAX--;
		bibliotecaLivro* verificaLivro = (bibliotecaLivro*) realloc (livros, LIVRO_MAX * sizeof(bibliotecaLivro));
		if (verificaLivro==NULL)
		{
			return 0;
		}
		else
		{
			livros=verificaLivro;
		}
	}
	int i;
	for (i=remover; i<LIVRO_MAX; i++)
	{
		strcpy (livros[i].livro, livros[i+1].livro);
		strcpy (livros[i].autor, livros[i+1].autor);	
		strcpy (livros[i].ano, livros[i+1].ano);	
	}
	strcpy (livros[qtdLivros-1].livro, "\0");
	strcpy (livros[qtdLivros-1].autor, "\0");
	strcpy (livros[qtdLivros-1].ano, "\0");
	qtdLivros--;
	return 1;
}// FINALIZADA REMO플O DE LIVROS

int ObterCodigoLivro(int i)
{
	return cadastros[i].locado;
}

void DefinirCodigoLivro(int codigoCliente, int codigoLivro)
{
	cadastros[codigoCliente].locado=codigoLivro;
}

char* EntregaLivro(int i)
{
	return cadastros[i].dataEntrega;
}
void DevoucaoLivro(int i)
{
	cadastros[i].locado=-1;
	strcpy(cadastros[i].dataEntrega,"\0");
}
void salvarArquivo ()
{
	FILE* ptCliente = fopen ("registrosClientes.txt", "wb");
	FILE* ptLivro = fopen("registrosLivros.txt","wb");
	if (ptCliente == NULL || ptLivro == NULL)
	{
		exit(1);
	}
	
	int r = fwrite(cadastros, sizeof(tpCliente), qtdClientes, ptCliente);
	int v = fwrite(livros, sizeof(bibliotecaLivro), qtdLivros, ptLivro);
	
	fclose(ptCliente);
	fclose(ptLivro);

	free(cadastros);
	free(livros);
	
}

void abrirArquivo()
{
	FILE* ptCliente = fopen ("registrosClientes.txt", "rb");
	FILE* ptLivro = fopen("registrosLivros.txt","rb");
	if (ptCliente == NULL || ptLivro == NULL)
	{
		exit(1);
	}
	
	fseek(ptCliente, 0, SEEK_END);
	long int tamanhoBcliente = ftell(ptCliente);
	CLIENTE_MAX = tamanhoBcliente / sizeof(tpCliente);
	rewind(ptCliente);
	
	fseek(ptLivro, 0, SEEK_END);
	long int tamanhoBlivro = ftell(ptLivro);
	LIVRO_MAX = tamanhoBlivro / sizeof(bibliotecaLivro);
	rewind(ptLivro);
	
	cadastros = (tpCliente*) malloc (CLIENTE_MAX * sizeof(tpCliente));
	livros = (bibliotecaLivro*) malloc (LIVRO_MAX * sizeof(bibliotecaLivro));
	
	int r = fread(cadastros, sizeof(tpCliente), CLIENTE_MAX, ptCliente);
	int v = fread(livros, sizeof(bibliotecaLivro), LIVRO_MAX, ptLivro);
	
	qtdClientes=CLIENTE_MAX;
	qtdLivros=LIVRO_MAX;
	
	fclose(ptCliente);
	fclose(ptLivro);
	
}

