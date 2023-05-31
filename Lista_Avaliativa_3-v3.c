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
void lista_produtos_marcas();
void estado_produto_caro();
void fabricante_produto_barato();
void lista_produtos_crescente();
void lista_produtos_valor_lucro();
void lista_produtos_percentual_lucro();
void retorno_saida();
int le_valida_opcao_menu();

int main(void){

	Produtos produto[TAM_PRODUTOS]; //declarar como vetor
	Fabricantes fabricante[TAM_FABRICANTES]; // declarar como vetor
	
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
		lista_todas_marcas(fabricante, qtd_fabricantes); // depois alterar qtd
		break;
	
	case 2: 
		lista_todos_produtos();
		break;
		
	case 3:
		lista_produtos_estado();
		break;
		
	case 4:
		lista_produtos_marcas();
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
        lista_produtos_percentual_lucro();
		break;
		
	case 0:
        printf("Encerrando o programa...\n");
        exit(0);
    }

	return 0;
}

void lista_todas_marcas(Fabricantes fabricante[], int qtd_fabricante){
    int i=0;

    printf("\n\n===================================================================================\n");
	printf("\t\t\tRELATORIO 1- LISTA DE TODAS AS MARCAS\n");
	printf("===================================================================================\n");
		
	printf("Marca\t\t|\tSite\t\t|\tTelefone\t|\tUF\t\t\n");
	printf("----------------+-----------------------+-----------------------+------------------\n");
    for(i=0; i<qtd_fabricante; i++){
        printf("%s\t\t| %s\t| %d\t\t| %s\n",fabricante[i].marca, fabricante[i].site, fabricante[i].telefone, fabricante[i].uf);
    }
	printf("----------------+-----------------------+-----------------------+------------------\n");
    retorno_saida();
}

void lista_todos_produtos(){

    printf("\n\n===================================================================================\n");
	printf("\t\t\tRELATORIO 2- LISTA DE TODAS OS PRODUTOS\n");
	printf("===================================================================================\n");
		
	printf("Marca\t\t|\tSite\t\t|\tTelefone\t|\tUF\t\t\n");
	printf("----------------+-----------------------+-----------------------+------------------\n");
    retorno_saida();
}

void lista_produtos_estado(){

    printf("\n\n===================================================================================\n");
	printf("\t\t\tRELATORIO 3- Escolha um estado\n");
	printf("===================================================================================\n");
    retorno_saida();
}

void lista_produtos_marcas(){

    printf("\n\n===================================================================================\n");
	printf("\t\t\tRELATORIO 4- Escolha uma marca\n");
	printf("===================================================================================\n");
    retorno_saida();
}

void estado_produto_caro(){

    printf("\n\n===================================================================================\n");
	printf("\t\t\tRELATORIO 5- ESTADO DO PRODUTO MAIS CARO\n");
	printf("===================================================================================\n");
    retorno_saida();
}

void fabricante_produto_barato(){

    printf("\n\n===================================================================================\n");
	printf("\t\t\tRELATORIO 6- FABRICANTE COM PRODUTO MAIS BARATO\n");
	printf("===================================================================================\n");
    retorno_saida();
}
void lista_produtos_crescente(){

    printf("\n\n===================================================================================\n");
	printf("\t\t\tRELATORIO 7- LISTA DE TODAS OS PRODUTOS EM ORDEM CRESCENTE (VALOR)\n");
	printf("===================================================================================\n");
	//implementar bubblesort do valor
    retorno_saida();
}
void lista_produtos_valor_lucro(){

    printf("\n\n===================================================================================\n");
	printf("\t\t\tRELATORIO 2- LISTA DE TODAS OS PRODUTOS EM ORDEM CRESCENTE (LUCRO)\n");
	printf("===================================================================================\n");
	//implementar bubblesort do lucro
    retorno_saida();
}
void lista_produtos_percentual_lucro(){

    printf("\n\n===================================================================================\n");
	printf("\t\t\tRELATORIO 2- LISTA DE TODAS OS PRODUTOS EM ORDEM CRESCENTE (PERCENTUAL LUCRO)\n");
	printf("===================================================================================\n");
	//implementar bubblesort do percentual de lucro
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
    }while(opcao != 0 && opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5 && opcao != 6 && opcao != 7 && opcao != 8 && opcao != 9);
}
