#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TAM_FABRICANTES 2 // min 2 max 5
#define TAM_PRODUTOS 5 // min 5 max 50

	typedef struct {
		char marca[30];
		char site[50];
		int telefone;
		char uf[2];
	}Fabricantes;

	typedef struct {
		char descricao[50];
		float peso;
		float valor_compra;
		float valor_venda;
		float valor_lucro;
		float percentual_lucro;
		Fabricantes fabricante;
	}Produtos;

void lista_todas_marcas(Fabricantes fabricante[], int qtd_fabricante);
void lista_todos_produtos();
void lista_produtos_estado();
void lista_produtos_marcas(Produtos produto[], int qtd_produtos, Fabricantes fabricante[], int qtd_fabricantes);
void estado_produto_caro();
void fabricante_produto_barato();
void lista_produtos_crescente();
void lista_produtos_valor_lucro();
void lista_produtos_percentual_lucro(Produtos produto[], int qtd_produtos);
void retorno_saida();
int le_valida_opcao_menu();
// void cadastro(Produtos produto[], int *pt_qtd_produtos, Fabricantes fabricante[], int qtd_fabricantes);

int main(){

	Produtos produto[TAM_PRODUTOS];
	Fabricantes fabricante[TAM_FABRICANTES];
	
	int opcao, qtd_produtos=0, qtd_fabricantes=0;

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
		
    opcao = le_valida_opcao_menu();
	
	switch (opcao){
	
	case 1: 
		lista_todas_marcas(fabricante, qtd_fabricantes);
		break;
	
	case 2: 
		lista_todos_produtos();
		break;
		
	case 3:
		lista_produtos_estado();
		break;
		
	case 4:
		lista_produtos_marcas(produto, qtd_produtos, fabricante, qtd_fabricantes);
        break;
		
	case 5:
		estado_produto_caro();
        break;
		
	case 6:
		fabricante_produto_barato();
        break;
	
	case 7:
		lista_produtos_crescente();
		break;	
	
	case 8:
        lista_produtos_valor_lucro();
		break;
		
	case 9:
        lista_produtos_percentual_lucro(produto, qtd_produtos);
		break;
		
	case 0:
        printf("Encerrando o programa...\n");
        exit(0);
    }

	return 0;
}

void lista_todas_marcas(Fabricantes fabricante[], int qtd_fabricantes){
    int i=0;

    printf("\n\n===================================================================================\n");
	printf("\t\t\tRELATORIO 1 - LISTA DE TODAS AS MARCAS\n");
	printf("===================================================================================\n");
		
	printf("Marca\t\t|\tSite\t\t|\tTelefone\t|\tUF\t\t\n");
	printf("----------------+-----------------------+-----------------------+------------------\n");
    for(i=0; i<qtd_fabricantes; i++){
        printf("%s\t\t| %s\t| %d\t\t| %s\n",fabricante[i].marca, fabricante[i].site, fabricante[i].telefone, fabricante[i].uf);
		printf("----------------+-----------------------+-----------------------+------------------\n");
    }

    retorno_saida();
}

void lista_todos_produtos(){

    printf("\n\n===================================================================================\n");
	printf("\t\t\tRELATORIO 2 - LISTA DE TODAS OS PRODUTOS\n");
	printf("===================================================================================\n");
		
	printf("Marca\t\t|\tSite\t\t|\tTelefone\t|\tUF\t\t\n");
	printf("----------------+-----------------------+-----------------------+------------------\n");
    retorno_saida();
}

void lista_produtos_estado(){

    printf("\n\n===================================================================================\n");
	printf("\t\t\tRELATORIO 3 - Escolha um estado\n");
	printf("===================================================================================\n");
    retorno_saida();
}

void lista_produtos_marcas(Produtos produto[], int qtd_produtos, Fabricantes fabricante[], int qtd_fabricantes){
	char marca[50];
	int i = 0, escolha =0;

    printf("\n\n=================================================================================================================================================================\n");
	printf("\t\t\tRELATORIO 4 - Escolha uma marca\n");
	printf("=================================================================================================================================================================\n");
	for(i=0;i<qtd_fabricantes;i++){
		printf("- [%d] %s\n",i+1, fabricante[i].marca);
	}
	printf("Escolha: ");
	scanf("%d", &escolha);
	for(i=0;i<qtd_fabricantes;i++){
		if(escolha-1 == i){
			strcpy(marca, fabricante[i].marca);
		}
	}	
	printf("\tDescricao\t\t|\tPeso\t| Valor Compra\t\t| Valor Venda\t\t| Valor Lucro\t\t| %%Lucro\t| Fabricante\t\t|\n");
	printf("--------------------------------+---------------+-----------------------+-----------------------+-----------------------+---------------+-----------------------+\n");
	for(i=0; i<qtd_produtos; i++){
		if(strcmp(marca, produto[i].fabricante.marca) == 0){
			printf("%s\t\t|  %.1fkg\t| R$ %.2f\t\t| R$ %.2f\t\t| R$ %.2f\t\t| %.1f%%\t\t| %s\t\t|\n",produto[i].descricao, produto[i].peso, produto[i].valor_compra, produto[i].valor_venda, produto[i].valor_lucro, produto[i].percentual_lucro, produto[i].fabricante.marca);
    		printf("--------------------------------+---------------+-----------------------+-----------------------+-----------------------+---------------+-----------------------+\n");
	
		}
 	}
	retorno_saida();
}

void estado_produto_caro(){

    printf("\n\n===================================================================================\n");
	printf("\t\t\tRELATORIO 5 - ESTADO DO PRODUTO MAIS CARO\n");
	printf("===================================================================================\n");
    retorno_saida();
}

void fabricante_produto_barato(){

    printf("\n\n===================================================================================\n");
	printf("\t\t\tRELATORIO 6 - FABRICANTE COM PRODUTO MAIS BARATO\n");
	printf("===================================================================================\n");
    retorno_saida();
}
void lista_produtos_crescente(){

    printf("\n\n===================================================================================\n");
	printf("\t\t\tRELATORIO 7 - LISTA DE TODAS OS PRODUTOS EM ORDEM CRESCENTE (VALOR)\n");
	printf("===================================================================================\n");
	//implementar bubblesort do valor
    retorno_saida();
}
void lista_produtos_valor_lucro(){

    printf("\n\n===================================================================================\n");
	printf("\t\t\tRELATORIO 2 - LISTA DE TODAS OS PRODUTOS EM ORDEM CRESCENTE (LUCRO)\n");
	printf("===================================================================================\n");
	//implementar bubblesort do lucro
    retorno_saida();
}
void lista_produtos_percentual_lucro(Produtos produto[], int qtd_produtos){
	
	int i=0,j=0;
	Produtos aux;

    for(i=0;i<qtd_produtos;i++){
        for(j=0;j<qtd_produtos-i-1;j++){
            if(produto[j].percentual_lucro>produto[j+1].percentual_lucro){
                aux = produto[j];
                produto[j] = produto[j+1];
                produto[j+1] = aux;
            }
        }
    }

    printf("\n\n=================================================================================================================================================================\n");
	printf("\t\t\t\tRELATORIO 9 - LISTA DE TODAS OS PRODUTOS EM ORDEM CRESCENTE (PERCENTUAL LUCRO)\n");
	printf("=================================================================================================================================================================\n");
    printf("\tDescricao\t\t|\tPeso\t| Valor Compra\t\t| Valor Venda\t\t| Valor Lucro\t\t| %%Lucro\t| Fabricante\t\t|\n");
	printf("--------------------------------+---------------+-----------------------+-----------------------+-----------------------+---------------+-----------------------+\n");
	for(i=0;i<qtd_produtos;i++){
    	printf("%s\t\t|  %.1fkg\t| R$ %.2f\t\t| R$ %.2f\t\t| R$ %.2f\t\t| %.1f%%\t\t| %s\t\t|\n",produto[i].descricao, produto[i].peso, produto[i].valor_compra, produto[i].valor_venda, produto[i].valor_lucro, produto[i].percentual_lucro, produto[i].fabricante.marca);
    	printf("--------------------------------+---------------+-----------------------+-----------------------+-----------------------+---------------+-----------------------+\n");
	}
    retorno_saida();
}

void retorno_saida() {
    int opcao;

    printf("\n\n- [0] voltar para a tela principal\n");
    printf("- [9] sair do programa\n");
    printf("\nEscolha: ");
    scanf("%d", &opcao);
   
    switch (opcao)
    {
    case 0:
        main();
        break;

    case 9:
        printf("Encerrando o programa...\n");
        exit(0);
        break;
    
    default:
        break;
    }
}

int le_valida_opcao_menu(){
    int opcao=0, count=0;

    do{
        if(count>0){
            printf("Escolha uma opcao entre 0 e 9!\n");
        }
        printf("\nEscolha uma das opcoes acima: ");	
        scanf("%d",&opcao);
        count++;
    }while(opcao <0 || opcao >9);
}

/* 
void cadastro(Produtos produto[], int *pt_qtd_produtos, Fabricantes fabricante[], int qtd_fabricantes){
	
	int escolha=0, i=0, opcao=0;
	
	do{
		printf("Descricao: ");
		scanf(" %[^\n]s", &produto[*pt_qtd_produtos].descricao);
		printf("Peso: ");
		scanf("%f", &produto[*pt_qtd_produtos].peso);
		printf("Compra: ");
		scanf("%f", &produto[*pt_qtd_produtos].valor_compra);
		printf("Venda: ");
		scanf("%f", &produto[*pt_qtd_produtos].valor_venda);
		produto[*pt_qtd_produtos].valor_lucro = produto[*pt_qtd_produtos].valor_venda - produto[*pt_qtd_produtos].valor_compra;
		produto[*pt_qtd_produtos].percentual_lucro = (produto[*pt_qtd_produtos].valor_lucro / produto[*pt_qtd_produtos].valor_compra) * 100;
		printf("Marca\n");
		for(i=0;i<qtd_fabricantes;i++){
			printf("- [%d] %s\n",i+1, fabricante[i].marca);
		}
		printf("Escolha: ");
		scanf("%d", &escolha);
		produto[*pt_qtd_produtos].fabricante = fabricante[escolha-1];
		printf("\n\n- [0] Voltar para a tela inicial\n");
		printf("- [9] Continuar cadastrando\n");    
		printf("\nEscolha: ");
    	scanf("%d", &opcao);
		*pt_qtd_produtos = *pt_qtd_produtos + 1;
	}while(opcao==9);

}

 */