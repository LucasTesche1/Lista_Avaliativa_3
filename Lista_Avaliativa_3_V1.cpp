#include <stdlib.h>
#include <stdio.h>

int main(){
	
	int opcao;
	char s,n;
	
	printf("===================================================================================\n");
	printf("\t\t\t\t\tMENU\n");
	printf("===================================================================================\n");
	
	printf("- [1] Listar todas as marcas\n");
	printf("- [2] Listar todos os produtos\n");
	printf("- [3] Listar os produtos de um determinado estado\n");
	printf("- [4] Listar os produtos de uma determinada marca\n");
	printf("- [5] Apresentar o(s) estado(s) onde esta registrado o produto mais caro\n");
	printf("- [6] Apresentar o(s) fabricante(s) onde esta registrado o produto mais barato\n");
	printf("- [7] Listar todos os produtos em ordem crescente de valor\n");
	printf("- [8] Listar todos os produtos em ordem crescente de maior 'valor de lucro'\n");
	printf("- [9] Listar todos os produtos em ordem crescente de maior 'percentual de lucro'\n");
	printf("- [0] Sair do programa\n");
		
		
	printf("\nEscolha uma das opcoes acima: ");	
	scanf("%d",&opcao);
	
	switch (opcao){
	
	case 1: 
		printf("===================================================================================\n");
		printf("\t\t\tRELATORIO 1- LISTA DE TODAS AS MARCAS\n");
		printf("===================================================================================\n");
		
		printf("Marca\t\t|\tSite\t\t|\tTelefone\t|\tUF\t\t\n");
		printf("----------------+-----------------------+-----------------------+------------------\n");
		
		break;
	
	
	case 2: 
		printf("===================================================================================\n");
		printf("\t\t\tRELATORIO 2- LISTA DE TODAS OS PRODUTOS\n");
		printf("===================================================================================\n");
		
		printf("Marca\t\t|\tSite\t\t|\tTelefone\t|\tUF\t\t\n");
		printf("----------------+-----------------------+-----------------------+------------------\n");
		
		break;
		
	case 3:
		printf("===================================================================================\n");
		printf("\t\t\tRELATORIO 3- Escolha um estado\n");
		printf("===================================================================================\n");
		
		
		
		break;
		
	case 4:
		printf("===================================================================================\n");
		printf("\t\t\tRELATORIO 4- Escolha uma marca\n");
		printf("===================================================================================\n");
		
	case 5:
		printf("===================================================================================\n");
		printf("\t\t\tRELATORIO 5- ESTADO DO PRODUTO MAIS CARO\n");
		printf("===================================================================================\n");
		
	case 6:
		printf("===================================================================================\n");
		printf("\t\t\tRELATORIO 6- FABRICANTE COM PRODUTO MAIS BARATO\n");
		printf("===================================================================================\n");
		
		
		
		break;
	
	case 7:
		printf("===================================================================================\n");
		printf("\t\t\tRELATORIO 7- LISTA DE TODAS OS PRODUTOS EM ORDEM CRESCENTE (VALOR)\n");
		printf("===================================================================================\n");
		
	
		break;	
	
	case 8:
		printf("===================================================================================\n");
		printf("\t\t\tRELATORIO 2- LISTA DE TODAS OS PRODUTOS EM ORDEM CRESCENTE (LUCRO)\n");
		printf("===================================================================================\n");



		break;
		
	case 9:
		printf("===================================================================================\n");
		printf("\t\t\tRELATORIO 2- LISTA DE TODAS OS PRODUTOS EM ORDEM CRESCENTE (PERCENTUAL LUCRO)\n");
		printf("===================================================================================\n");
		

		
		break;
		
	case 0:
		
		printf("===================================================================================\n");
		printf("\t\t\tDeseja Sair?\n");
		printf("===================================================================================\n");
		
		printf("Se sim, digite: 'S'\n");
		printf("Se nao, digite: 'N'\n");
		
		if(s){
			exit;	
		}
		
}
	
	
	
	return 0;
}


