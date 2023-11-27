#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca de  controle das strings


int registro() // fun��o respons�vel por cadastrar os dados

{
	// defini��o das vari�veis e strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	// fim das vari�veis e strings
	
	printf("CPF: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);
	
	FILE *file; // cria��o do arquivo
	file = fopen(arquivo, "w"); // criar o arquivo
	fprintf(file,cpf); // salvar o valor da variavel
	fclose(file); // fechar o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",\t");
	fclose(file);
	
	printf("NOME: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",\t");
	fclose(file);
	
	printf("SOBRENOME: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",\t");
	fclose(file);
	
	printf("CARGO: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta() // fun��o respons�vel por consultar os dados
{
	setlocale(LC_ALL,"Portuguese"); // identificar localiza��o
	
	char cpf[40];
	char cadastro[200];
	
	printf("CPF CADASTRADO: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\nCPF N�O ENCONTRADO\n\n");
	}
	
	while(fgets(cadastro, 200, file) != NULL)
	{
		printf("\n");
		printf("%s", cadastro);
		printf("\n\n");
	}
	system("pause");
}

int apagar() // fun��o repsons�vel por apagar os dados
{
	char cpf[40];
	
	printf("CPF a ser apagado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("\nCPF N�O CADASTRADO\n\n");
		system("pause");
	}
}


int main() // fun��o principal do sistema

{	
	int opcao=0;
	int circle=1;
	
	for (circle=1;circle=1;)
	{
		system("cls"); // limpar a tela

		setlocale(LC_ALL,"Portuguese"); // identificar localiza��o
	
// �nicio do menu
		printf("###CART�RIO DA EBAC###\n\n");
		printf("Escolha a op��o desejada:\n\n");
		printf("\t1 Novo cadastro\n");
		printf("\t2 Consultar cadastro\n");
		printf("\t3 Apagar cadastro\n");
		printf("\t4 Sair do sistema\n\n");
		printf("Op��o desejada: ");
// fim do menu	
	
		scanf("%d", &opcao); // armazenamento da op��o escolhida
	
		system("cls"); // limpar a tela
	
// �nicio da sele��o	
		switch (opcao)
		{
			// chamada das fun��es de registro, cosnulta e apagar dados
			case 1: 
				registro();
				break;
			
			case 2:
				consulta();
				break;
			
			case 3:
				apagar();
				break;
				
			case 4:
				printf("Obrigado por utilizar o sistema.\n\n");
				return 0;
				break;
				
			default:
				printf("OP��O INV�LIDA\n");
				system("pause");
				break;
		}
// fim da sele��o
}
}
