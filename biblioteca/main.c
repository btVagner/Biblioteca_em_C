#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/biblioteca.h"

int i=0, opcao=0, excluido;
char nomePesquisado[10];

void MostrarMenu()
{
	printf (" ~~~~~~~~~~~~~~Biblioteca Patoleca~~~~~~~~~~~~~~\n\n\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf ("|         Qual funcao deseja executar?          |\n");
	printf ("|                                               |\n");
	printf ("|Opcao 0: Sair                                  |\n");
	printf ("|Opcao 1: Listar clientes                       |\n");
	printf ("|Opcao 2: Cadastrar cliente pelo nome           |\n");
	printf ("|Opcao 3: Pesquisar cliente pelo nome           |\n");
	printf ("|Opcao 4: Excluir cliente pelo codigo           |\n");
	printf ("|Opcao 5: Listar livros                         |\n");
	printf ("|Opcao 6: Cadastrar livro                       |\n");
	printf ("|Opcao 7: Pesquisar livro pelo nome             |\n");
	printf ("|Opcao 8: Excluir livro pelo codigo             |\n");
	printf ("|Opcao 9: listar livros locados                 |\n");
	printf ("|Opcao 10: Locar livro                          |\n");
	printf ("|Opcao 11: Devolver livro pelo codigo do cliente|\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

}

void ListarCliente()
{
	system("cls");
	if (QC()==0)
	{
		printf ("\n\nNao ha clientes cadastrados, recomece a operacao.\n\n");
		return;
	}
	printf ("\n------Os clientes cadastrados sao:------\n");
	
	for (i=0; i < QC(); i++)
		{			
			printf ("\n\nCodigo: %d\nNome: %s\nCPF: %s\nTelefone: %s\n", i, ObterNomeCliente(i), ObterCpfCliente(i), ObterTelefoneCliente(i));
		}
	system("pause");
	system("cls");
}
void CadastrarCliente()
{
	system("cls");
	printf ("Informe o nome a cadastrar:\n");

		char nome[TEXT_MAX];
		char cpf[TEXT_MAX];
		char telefone[TEXT_MAX];
		scanf("%s", nome);
		printf ("Informe o seu CPF (SOMENTE NUMEROS):\n");
		scanf ("%s" ,cpf);
		printf ("Informe seu telefone:\n");
		scanf ("%s", telefone);
		if (NovosClientes(QC(), nome, cpf, telefone)== 1)
		{
			system("cls");
			printf ("Cliente cadastrado com sucesso !\n");	
		}
		else
		{
			printf ("Falha ao cadastrar o novo cliente.");
		}
}
void PesquisarPorNome ()
{
	system("cls");
	if (QC()==0)
	{
		printf ("\n\nNao ha clientes cadastrados, recomece a operacao.\n\n");
		return;
	}
	printf ("Pesquisar cliente pelo nome \n");
	scanf ("%s", nomePesquisado);
	for (i=0; i<QC(); i++)
	{
		if (strcmp (ObterNomeCliente(i), nomePesquisado)==0)
		{
			printf ("Cadastro: %s\n",ObterNomeCliente(funcaoPesquisar(nomePesquisado,CM())));
			printf ("CPF: %s\n", ObterCpfCliente(funcaoPesquisar(nomePesquisado,CM())));
			printf ("Telefone: %s\n", ObterTelefoneCliente(funcaoPesquisar(nomePesquisado,CM())));
			return;
		}
	}
	printf ("Cliente nao cadastrado, reinicie a operacao.\n");
}
void ExcluirCliente()
{
	system("cls");
	if (QC()>0)
	{
		ListarCliente();
		
		
		printf ("\n\nInforme o codigo do cliente que deseja excluir: \n");			
		scanf ("%d", &excluido);
		if (excluido == ObterCodigoLivro(excluido))
		{
			printf ("\nO cliente possui um livro locado, eh necessario realizar a devolucao antes de excluir o cadastro.\n");
			return;
		}
		if(excluido>=0 && excluido<CM())
		{	
			RemoverCadastro(excluido);
		
			system("cls");
			printf ("\nCliente excluido com sucesso.\n");
		}
		else
		{
			printf ("\nCodigo de cadastro invalido, recomece a operacao.\n");
		}
	}
	else
	{
		printf ("Nao ha clientes cadastrados.\n");
		system("pause");
		return;
	}
	
}
void ListarLivros()
{
	system("cls");
	if (QL()==0)
	{
		printf ("\n\nNao ha livros cadastrados, recomece a operacao.\n\n");
		return;
	}
	printf ("--------------- Os Livros sao ---------------\n");
	if (QL()>0)
	{
		for (i=0; i < QL(); i++)
		{
			printf ("\n\nCodigo: %d\nLivro: %s\nAutor: %s\nAno: %s\n", i, ObterNomeLivro(i), ObterAutorLivro(i), ObterAnoLivro(i));
		}	
	}
	else
	{
		printf ("\nNao ha livros cadastrados.\n");
	}
	system("pause");
	system("cls");
}
void CadastrarLivro()
{
		system("cls");
	
		printf("\n\nInforme o nome do livro a cadastrar:\n");
				
		char nomeLivro[TEXT_MAX];			
		char autor[TEXT_MAX];			
		char ano[TEXT_MAX];
		scanf ("%s", nomeLivro);
		printf ("Qual o autor do livro?\n");
		scanf ("%s", autor);
		printf ("Qual o ano do livro?\n");
		scanf ("%s", ano);
		if (NovosLivros(QL(), nomeLivro,  autor, ano)==1)
		{
			system ("cls");
			printf ("Livro cadastrado com sucesso!\n");
		}
		else
		{
			printf ("Falha ao cadastrar o novo livro.");
		}
				
}
void PesquisarLivro()
{
	system("cls");
	if (QL()==0)
	{
		printf ("\n\nNao ha livros cadastrados, recomece a operacao.\n\n");
		return;
	}
	printf ("\nPesquisar livro pelo nome \n");
	scanf ("%s", nomePesquisado);
	
	bibliotecaLivro* array;
		
	for (array = livros; array != livros+QL(); array++)
	{

		if (strcmp (array->livro, nomePesquisado)==0)
		{
			printf ("Livro: %s\nAno: %s\nAutor: %s\n", array->livro, array->ano, array->autor);
			return;
		}
	}

	printf ("Livro nao cadastrado, reinicie a operacao.\n");
	return;
}

void ExcluirLivro()
{
	system("cls");
	if (QL()>0)
	{
		ListarLivros();
		printf ("\nInforme o codigo do livro que deseja excluir: ");			
		scanf ("%d", &excluido);
		if (ObterCodigoLivro(excluido)==-1)
		{
			RemoverLivro(excluido);
		}
		else 
		{
			printf ("O livro esta alugado, deve ser entregue antes de excluir.\n");
			return;
		}
	
		printf ("\nLivro excluido com sucesso.\n");	
	}
	else
	{
		printf ("Nao ha livros cadastrados.\n");
		system("pause");
		return;
	}
	
}

void LivrosLocados ()
{	
	int encontrado=0;
	system("cls");
	for(i=0; i<CM(); i++)
	{
		if(ObterCodigoLivro(i)!=-1)
		{
			encontrado=1;
		}
	}
	if (encontrado==0){
		printf ("\nNao ha livro locado!\n\n");
		system("pause");
		return;
		
	}
	else
	{
		for (i=0; i<CM(); i++)
		{
			if (ObterCodigoLivro(i)!=-1)
			{
				printf ("\nO cliente %s (indice %d), tem o livro %s alugado e sua data de entrega eh %s.\n", ObterNomeCliente(i), i, ObterNomeLivro(i), EntregaLivro(i));
				return;
			}
		}	
	}
	system("CLS");
}

void LocarLivro()
{
	if (QC()==0)
	{
		printf ("\n\nNao ha clientes cadastrados, recomece a operacao.\n\n");
		return;
	}
	else if (QL()==0)
	{
		printf ("\n\nNao ha livros cadastrados, recomece a operacao.\n\n");
		return;
	}
	ListarCliente();
	printf ("\nInforme o indice de quem ira alugar o livro:\n");
	int j=0;
	scanf ("%d", &j);
		
	if (ObterCodigoLivro(j)!=-1)
	{
		system("cls");
		printf ("\n\nEste cliente possui um livro locado, eh necessario entregar antes de locar outro.\n\n");
		return;
	}
	if (QL()==0)
	{
		return;
	}
	if (j<0 || j>QC()-1)
	{
		printf ("\nIndice do cliente invalido, recomece a operacao!\n");
		return;
	}
	ListarLivros();
	printf ("\nInforme o indice do livro que deseja locar:\n");
	scanf ("%d", &i);
	
	system("cls");
	if (i<0 || i>QL()-1)
	{
		printf ("\nIndice do livro invalido, recomece a operacao!\n");
		return;
	}
	else
	{
		printf ("\nInforme a data de entrega para o livro:\n");
		scanf ("%s", EntregaLivro(j));
		
		if (ObterCodigoLivro(j)==-1)
		{
			system ("cls");
			printf ("\n\nLivro locado com sucesso.\n\n");
			DefinirCodigoLivro(j, i);
	
		}		
	}
}
void DevolverLivro()
{
	int encontrado=0;
	system("cls");
	for(i=0; i<CM(); i++)
	{
		if(ObterCodigoLivro(i)!=-1)
		{
			encontrado=1;
		}
	}
	if (encontrado==0){
		printf ("\nNao ha livro locado!\n\n");
		system("pause");
		return;
		
	}
	LivrosLocados();
	printf ("\nInforme o codigo do cliente que ira devolver o livro:\n");
	scanf("%d", &i);
	if (i>=0 && i<QL())
	{
		if (ObterCodigoLivro(i)!=-1)
		{
			DevoucaoLivro(i);
		}
		system("cls");
		printf ("\nLivro devolvido com sucesso.\n\n");	
	}
	else
	{
		system ("cls");
		printf ("\nCodigo do cliente invalido, recomece a operacao!\n");
	}
	
}


int main(int argc, char *argv[]) {

	abrirArquivo();

	do
	{
		
		MostrarMenu();	
		
		scanf("%d", &opcao);
		
		switch (opcao)
		{
			case 0:
				printf ("Obrigado e volte sempre!\n");
				salvarArquivo();
				break;
			case 1:
				printf ("A lista de clientes eh:\n");
				ListarCliente();
				break;
			case 2:
				CadastrarCliente();
				break;
			case 3:
				PesquisarPorNome ();		
				break;
			case 4:		
				ExcluirCliente();			
				break;
			case 5:
				ListarLivros();
				break;
			case 6:
				CadastrarLivro();
				break;
			case 7:
				PesquisarLivro();
				break;
			case 8:
				ExcluirLivro();
				break;
			case 9:
				LivrosLocados();
				break;
			case 10:
				LocarLivro();
				break;
			case 11:
				DevolverLivro();
				break;
			default:
				printf("\nNumero invalido, escolha novamente.\n");
				break;
		}	
	}
	while (opcao!=0);

	return 0;
}
