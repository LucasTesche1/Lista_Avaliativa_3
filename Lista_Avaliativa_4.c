#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TAM_FABRICANTES 5 // min 2 max 5
#define TAM_PRODUTOS 50 // min 5 max 50
#define TAM_UF 27

	typedef struct{
		char nome[20];
		char abreviacao[2];
		int codigo;
	}Uf;

	typedef struct {
		char marca[30];
		char site[50];
		int telefone;
		int codigo;
		Uf uf;
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

// procedimentos do menu
void lista_todas_marcas(Fabricantes fabricante[], int qtd_fabricante);
void lista_todos_produtos(Produtos produto[], int qtd_produtos);
void lista_produtos_estado(Produtos produto[], Uf uf[], int qtd_produtos);
void lista_produtos_marcas(Produtos produto[], int qtd_produtos, Fabricantes fabricante[], int qtd_fabricantes);
void estado_produto_caro(Produtos produto[], int qtd_produtos, float *produto_caro);
void fabricante_produto_barato(Produtos produto[], int qtd_produtos, float *produto_barato);
void lista_produtos_crescente(Produtos produto[], int qtd_produtos);
void lista_produtos_valor_lucro(Produtos produto[], int qtd_produtos);
void lista_produtos_percentual_lucro(Produtos produto[], int qtd_produtos);
void lista_produtos_az(Produtos produto[], int qtd_produtos);
void lista_produtos_za(Produtos produto[], int qtd_produtos);
void retorno_saida();

// procedimentos de variaveis/cadastro
void imprimir_produtos(Produtos produto[],int i);
void listar_uf(Uf uf[]);
void variaveis_uf(Uf uf[]);
char cadastro_fabricante(Fabricantes fabricante[],int *qtd_fabricante, Uf uf[]);
char cadastro_produto(Produtos produto[], int *pt_qtd_produtos, Fabricantes fabricante[], int qtd_fabricantes);

// procedimentos bubble sort
void bubble_crescente_venda(Produtos produto[], int qtd_produtos);
void bubble_crescete_lucro(Produtos produto[], int qtd_produtos);
void bubble_crescente_porcentagem(Produtos produto[], int qtd_produtos);
void bubble_az(Produtos produto[], int qtd_produtos);
void bubble_za(Produtos produto[], int qtd_produtos);
void bubble_az_produto_estado(Produtos produto[], int qtd_produtos);
void bubble_az_produto_fabricante(Produtos produto[], int qtd_produtos);

// funcoes le_valida
int le_valida_opcao_menu();
int le_valida_opcao_retorno();
int le_valida_opcao_uf();
int le_valida_escolha_marca(int *qtd_fabricantes, Fabricantes fabricante[]);
float le_valida_peso();
float le_valida_compra();
float le_valida_venda();

int main(){

	Uf uf[TAM_UF];
	variaveis_uf(uf); // inicializacao da struct Uf

	float produto_caro=0, produto_barato=0;
	int qtd_produtos=0, qtd_fabricantes=0, i=0;
	char opcao,escolha;
    
    Fabricantes* fabricante;
    fabricante = (Fabricantes*)malloc(0 * sizeof(Fabricantes));
    if (fabricante == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }

    Produtos* produto;
    produto = (Produtos*)malloc(0 * sizeof(Produtos));
    if (produto == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }

	

	do{
		
		fabricante = realloc(fabricante, (qtd_fabricantes + 1) * sizeof(Fabricantes));    
		if (fabricante == NULL) {
    		printf("Memory not allocated.\n");
    		exit(0);
    	}			
		escolha = cadastro_fabricante(fabricante, &qtd_fabricantes, uf);	
			
	}while(escolha == '9' && qtd_fabricantes < TAM_FABRICANTES);

	do{

		produto = realloc(produto, (qtd_produtos + 1) * sizeof(Produtos));    
		if (fabricante == NULL) {
    		printf("Memory not allocated.\n");
    		exit(0);
    	}			
		escolha = cadastro_produto(produto, &qtd_produtos, fabricante, qtd_fabricantes);
		
	}while(escolha == '9' && qtd_produtos < TAM_PRODUTOS);

	do{
		system("cls");
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
		printf("- [A] Listar todos os produtos em ordem alfabetica crescente A-Z\n");
		printf("- [Z] Listar todas as marcas em ordem alfabetica decrescente Z-A\n");
		if(qtd_fabricantes < TAM_FABRICANTES){
			printf("- [B] Cadastro Fabricante\n");
		}
		if(qtd_produtos < TAM_PRODUTOS){
			printf("- [C] Cadastro Produto\n");
		}
		printf("- [0] Sair do programa\n");
			
		opcao = le_valida_opcao_menu();
		switch (opcao){
		
		case '1':
			lista_todas_marcas(fabricante, qtd_fabricantes);
			break;
		
		case '2': 
			lista_todos_produtos(produto, qtd_produtos);
			break;
			
		case '3':
			lista_produtos_estado(produto, uf, qtd_produtos);
			break;
			
		case '4':
			lista_produtos_marcas(produto, qtd_produtos, fabricante, qtd_fabricantes);
			break;
			
		case '5':
			estado_produto_caro(produto, qtd_produtos, &produto_caro);
			break;
			
		case '6':
			fabricante_produto_barato(produto, qtd_produtos, &produto_barato);
			break;
		
		case '7':
			lista_produtos_crescente(produto, qtd_produtos);
			break;	
		
		case '8':
			lista_produtos_valor_lucro(produto, qtd_produtos);
			break;
			
		case '9':
			lista_produtos_percentual_lucro(produto, qtd_produtos);
			break;
			
		case 'A':
			lista_produtos_az(produto,qtd_produtos);
			break;
			
		case 'Z':
			lista_produtos_za(produto,qtd_produtos);
			break;	

		case 'B':
			do{
				if(qtd_fabricantes == TAM_FABRICANTES){				
					printf("Limite de Fabricantes atingido\n");
					system("PAUSE");
				}else{
					fabricante = realloc(fabricante, (qtd_fabricantes + 1) * sizeof(Fabricantes));    
					if (fabricante == NULL) {
        				printf("Memory not allocated.\n");
        				exit(0);
    				}			
					escolha = cadastro_fabricante(fabricante, &qtd_fabricantes, uf);	
				}
			}while(escolha == '9' && qtd_fabricantes < TAM_FABRICANTES);
			break;
						
		case 'C':
			do{
				if(qtd_produtos == TAM_PRODUTOS){
					printf("Limite de Produtos atingido\n");
					system("PAUSE");
				}else{
					produto = realloc(produto, (qtd_produtos + 1) * sizeof(Produtos));    
					if (fabricante == NULL) {
        				printf("Memory not allocated.\n");
        				exit(0);
    				}			
					escolha = cadastro_produto(produto, &qtd_produtos, fabricante, qtd_fabricantes);
				}
			}while(escolha == '9' && qtd_produtos < TAM_PRODUTOS);
			break;
			
			
		case '0':
			printf("Encerrando o programa...\n");
			exit(0);
		}

		}while(opcao != 0);
        
    free(fabricante);
	free(produto);
	return 0;
}

// procedimentos do menu

void lista_todas_marcas(Fabricantes fabricante[], int qtd_fabricantes){
    int i=0;

    printf("\n\n===================================================================================\n");
	printf("\t\t\tRELATORIO 1 - LISTA DE TODAS AS MARCAS\n");
	printf("===================================================================================\n");
		
	printf("Marca\t\t|\tSite\t\t|\tTelefone\t|\tUF\t\t\n");
	printf("----------------+-----------------------+-----------------------+------------------\n");
    for(i=0; i<qtd_fabricantes; i++){
        printf("%s\t\t| %s\t| %d\t\t| %s\n",fabricante[i].marca, fabricante[i].site, fabricante[i].telefone, fabricante[i].uf.abreviacao);
		printf("----------------+-----------------------+-----------------------+------------------\n");
    }

    retorno_saida();
}

void lista_todos_produtos(Produtos produto[], int qtd_produtos){
	int i=0;
    printf("\n\n=================================================================================================================================================================\n");
	printf("\t\t\tRELATORIO 2 - LISTA DE TODAS OS PRODUTOS\n");
	printf("=================================================================================================================================================================\n");
	printf("\tDescricao\t\t|\tPeso\t| Valor Compra\t\t| Valor Venda\t\t| Valor Lucro\t\t| %%Lucro\t| Fabricante\t\t|\n");
	printf("--------------------------------+---------------+-----------------------+-----------------------+-----------------------+---------------+-----------------------+\n");
	for(i=0;i<qtd_produtos;i++){
		imprimir_produtos(produto,i);
	}
    retorno_saida();
}

void lista_produtos_estado(Produtos produto[], Uf uf[], int qtd_produtos){

	int i=0, opcao=0;

    printf("\n\n=======================================================================================================================================\n");
	printf("\t\t\tRELATORIO 3 - Escolha um estado\n");
	printf("=======================================================================================================================================\n");
	
	listar_uf(uf);
	opcao = le_valida_opcao_uf();

	printf("=================================================================================================================================================================\n");
	printf("\tDescricao\t\t|\tPeso\t| Valor Compra\t\t| Valor Venda\t\t| Valor Lucro\t\t| %%Lucro\t| Fabricante\t\t|\n");
	printf("--------------------------------+---------------+-----------------------+-----------------------+-----------------------+---------------+-----------------------+\n");
	for(i=0; i<qtd_produtos; i++){
		if(strcmp(uf[opcao-1].abreviacao, produto[i].fabricante.uf.abreviacao) == 0){
			imprimir_produtos(produto,i);
		}
 	}
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
			imprimir_produtos(produto,i);
		}
 	}
	retorno_saida();
}

void estado_produto_caro(Produtos produto[], int qtd_produtos, float *produto_caro){

	int i=0;
	int aux;
	for(i=0;i<qtd_produtos;i++){
		if(produto[i].valor_venda > *produto_caro){
			*produto_caro = produto[i].valor_venda;
		}
	}
	bubble_az_produto_estado(produto,qtd_produtos);

    printf("\n\n===================================================================================\n");
	printf("\t\t\tRELATORIO 5 - ESTADO DO PRODUTO MAIS CARO\n");
	printf("===================================================================================\n");
	printf("Codigo\t|\tNome\t\t| Abreviacao\t|\n");
	printf("--------+-----------------------+---------------+\n");
    for(i=0; i<qtd_produtos; i++){
		if(*produto_caro == produto[i].valor_venda){
			if(produto[i].fabricante.uf.codigo  != aux){	
				printf("%d\t| %s\t\t\t|\t%s\t|\n",produto[i].fabricante.uf.codigo, produto[i].fabricante.uf.nome, produto[i].fabricante.uf.abreviacao);
				printf("--------+-----------------------+---------------+\n");
				aux = produto[i].fabricante.uf.codigo;
			}
		}
    }
	retorno_saida();
}

void fabricante_produto_barato(Produtos produto[], int qtd_produtos, float *produto_barato){

	int i=0, aux;
	for(i=0;i<qtd_produtos;i++){
		if(i==0 || produto[i].valor_venda < *produto_barato ){
			*produto_barato = produto[i].valor_venda;
		}
	}
	bubble_az_produto_fabricante(produto,qtd_produtos);
    printf("\n\n===================================================================================\n");
	printf("\t\t\tRELATORIO 6 - FABRICANTE COM PRODUTO MAIS BARATO\n");
	printf("===================================================================================\n");
	printf("Marca\t\t|\tSite\t\t|\tTelefone\t|\tUF\t\t\n");
	printf("----------------+-----------------------+-----------------------+------------------\n");
    for(i=0; i<qtd_produtos; i++){
		if(*produto_barato == produto[i].valor_venda){
			if(produto[i].fabricante.codigo  != aux){	
				printf("%s\t\t| %s\t| %d\t\t| %s\n",produto[i].fabricante.marca, produto[i].fabricante.site, produto[i].fabricante.telefone, produto[i].fabricante.uf.abreviacao);
				printf("----------------+-----------------------+-----------------------+------------------\n");
				aux = produto[i].fabricante.codigo;
			}
		}
    }
    retorno_saida();
}

void lista_produtos_crescente(Produtos produto[], int qtd_produtos){
	
	int i=0;
	bubble_crescente_venda(produto,qtd_produtos);
    
	printf("\n\n=================================================================================================================================================================\n");
	printf("\t\t\tRELATORIO 7 - LISTA DE TODAS OS PRODUTOS EM ORDEM CRESCENTE (VALOR)\n");
	printf("=================================================================================================================================================================\n");
	printf("\tDescricao\t\t|\tPeso\t| Valor Compra\t\t| Valor Venda\t\t| Valor Lucro\t\t| %%Lucro\t| Fabricante\t\t|\n");
	printf("--------------------------------+---------------+-----------------------+-----------------------+-----------------------+---------------+-----------------------+\n");
	
	for(i=0;i<qtd_produtos;i++){
		imprimir_produtos(produto,i);
	}
    
	retorno_saida();
}

void lista_produtos_valor_lucro(Produtos produto[], int qtd_produtos){
	int i=0;

	bubble_crescete_lucro(produto,qtd_produtos);

    printf("\n\n=================================================================================================================================================================\n");
	printf("\t\t\tRELATORIO 8 - LISTA DE TODAS OS PRODUTOS EM ORDEM CRESCENTE (LUCRO)\n");
	printf("=================================================================================================================================================================\n");
	printf("\tDescricao\t\t|\tPeso\t| Valor Compra\t\t| Valor Venda\t\t| Valor Lucro\t\t| %%Lucro\t| Fabricante\t\t|\n");
	printf("--------------------------------+---------------+-----------------------+-----------------------+-----------------------+---------------+-----------------------+\n");
	
	for(i=0;i<qtd_produtos;i++){
		imprimir_produtos(produto,i);
	}
    
    retorno_saida();
}

void lista_produtos_percentual_lucro(Produtos produto[], int qtd_produtos){
	
	int i=0;

	bubble_crescente_porcentagem(produto,qtd_produtos);

    printf("\n\n=================================================================================================================================================================\n");
	printf("\t\t\t\tRELATORIO 9 - LISTA DE TODAS OS PRODUTOS EM ORDEM CRESCENTE (PERCENTUAL LUCRO)\n");
	printf("=================================================================================================================================================================\n");
	printf("\tDescricao\t\t|\tPeso\t| Valor Compra\t\t| Valor Venda\t\t| Valor Lucro\t\t| %%Lucro\t| Fabricante\t\t|\n");
	printf("--------------------------------+---------------+-----------------------+-----------------------+-----------------------+---------------+-----------------------+\n");
	
	for(i=0;i<qtd_produtos;i++){
		imprimir_produtos(produto,i);
	}
    
	retorno_saida();
}

void lista_produtos_az(Produtos produto[], int qtd_produtos){
	int i=0;

	bubble_az(produto,qtd_produtos);

	printf("\n\n=================================================================================================================================================================\n");
	printf("\t\t\t\tRELATORIO 9 - LISTA DE TODAS OS PRODUTOS EM ORDEM ALFABETICA A-Z\n");
	printf("=================================================================================================================================================================\n");
	printf("\tDescricao\t\t|\tPeso\t| Valor Compra\t\t| Valor Venda\t\t| Valor Lucro\t\t| %%Lucro\t| Fabricante\t\t|\n");
	printf("--------------------------------+---------------+-----------------------+-----------------------+-----------------------+---------------+-----------------------+\n");
	

	for(i=0;i<qtd_produtos;i++){
		imprimir_produtos(produto,i);
	}
    
	retorno_saida();
}

void lista_produtos_za(Produtos produto[], int qtd_produtos){
	int i=0;

	bubble_za(produto,qtd_produtos);

	printf("\n\n=================================================================================================================================================================\n");
	printf("\t\t\t\tRELATORIO 9 - LISTA DE TODAS OS PRODUTOS EM ORDEM ALFABETICA Z-A\n");
	printf("=================================================================================================================================================================\n");
	printf("\tDescricao\t\t|\tPeso\t| Valor Compra\t\t| Valor Venda\t\t| Valor Lucro\t\t| %%Lucro\t| Fabricante\t\t|\n");
	printf("--------------------------------+---------------+-----------------------+-----------------------+-----------------------+---------------+-----------------------+\n");
	
	for(i=0;i<qtd_produtos;i++){
		imprimir_produtos(produto,i);
	}
    
	retorno_saida();
}

void retorno_saida() {
    char opcao;

    printf("\n\n- [0] voltar para a tela principal\n");
    printf("- [9] sair do programa\n");
    opcao = le_valida_opcao_retorno();
   
    switch (opcao)
    {
    case '0':
        break;

    case '9':
        printf("Encerrando o programa...\n");
        exit(0);
        break;
    
    default:
        break;
    }
}

// procedimentos de variaveis/cadastro

void imprimir_produtos(Produtos produto[],int i){

    printf("%s\t\t|  %.1fkg\t| R$ %.2f\t\t| R$ %.2f\t\t| R$ %.2f\t\t| %.1f%%\t\t| %s\t\t|\n",produto[i].descricao, produto[i].peso, produto[i].valor_compra, produto[i].valor_venda, produto[i].valor_lucro, produto[i].percentual_lucro, produto[i].fabricante.marca);
    printf("--------------------------------+---------------+-----------------------+-----------------------+-----------------------+---------------+-----------------------+\n");

}

void listar_uf(Uf uf[]){
	int i=0, j=0, k=0;
	for(i=0;i<3;i++){
		for(j=0;j<9;j++){
			printf("[%d] %s\t\t", k+1, uf[k].abreviacao);
			k++;
		}
		printf("\n");
	}
}

void variaveis_uf(Uf uf[]){
	strcpy(uf[0].nome, "Acre");
	strcpy(uf[0].abreviacao, "AC");
	uf[0].codigo = 12;
	strcpy(uf[1].nome, "Alagoas");
	strcpy(uf[1].abreviacao, "AL");
	uf[1].codigo = 27;
	strcpy(uf[2].nome, "Amapa");
	strcpy(uf[2].abreviacao, "AP");
	uf[2].codigo = 16;
	strcpy(uf[3].nome, "Amazonas");
	strcpy(uf[3].abreviacao, "AM");
	uf[3].codigo = 13;
	strcpy(uf[4].nome, "Bahia");
	strcpy(uf[4].abreviacao, "BA");
	uf[4].codigo = 29;
	strcpy(uf[5].nome, "Ceara");
	strcpy(uf[5].abreviacao, "CE");
	uf[5].codigo = 23;
	strcpy(uf[6].nome, "Distrito Federal");
	strcpy(uf[6].abreviacao, "DF");
	uf[6].codigo = 53;
	strcpy(uf[7].nome, "Espirito Santo");
	strcpy(uf[7].abreviacao, "ES");
	uf[7].codigo = 32;
	strcpy(uf[8].nome, "Goias");
	strcpy(uf[8].abreviacao, "GO");
	uf[8].codigo = 52;
	strcpy(uf[9].nome, "Maranhao");
	strcpy(uf[9].abreviacao, "MA");
	uf[9].codigo = 21;
	strcpy(uf[10].nome, "Mato Grosso");
	strcpy(uf[10].abreviacao, "MT");
	uf[10].codigo = 51;
	strcpy(uf[11].nome, "Mato Grosso do Sul");
	strcpy(uf[11].abreviacao, "MS");
	uf[11].codigo = 50;
	strcpy(uf[12].nome, "Minas Gerais");
	strcpy(uf[12].abreviacao, "MG");
	uf[12].codigo = 31;
	strcpy(uf[13].nome, "Para");
	strcpy(uf[13].abreviacao, "PA");
	uf[13].codigo = 15;
	strcpy(uf[14].nome, "Paraiba");
	strcpy(uf[14].abreviacao, "PB");
	uf[14].codigo = 25;
	strcpy(uf[15].nome, "Parana");
	strcpy(uf[15].abreviacao, "PR");
	uf[15].codigo = 41;
	strcpy(uf[16].nome, "Pernambuco");
	strcpy(uf[16].abreviacao, "PE");
	uf[16].codigo = 26;
	strcpy(uf[17].nome, "Piaui");
	strcpy(uf[17].abreviacao, "PI");
	uf[17].codigo = 22;
	strcpy(uf[18].nome, "Rio de Janeiro");
	strcpy(uf[18].abreviacao, "RJ");
	uf[18].codigo = 33;
	strcpy(uf[19].nome, "Rio Grande do Norte");
	strcpy(uf[19].abreviacao, "RN");
	uf[19].codigo = 24;
	strcpy(uf[20].nome, "Rio Grande do Sul");
	strcpy(uf[20].abreviacao, "RS");
	uf[20].codigo = 43;
	strcpy(uf[21].nome, "Rondonia");
	strcpy(uf[21].abreviacao, "RO");
	uf[21].codigo = 11;
	strcpy(uf[22].nome, "Roraima");
	strcpy(uf[22].abreviacao, "RR");
	uf[22].codigo = 14;
	strcpy(uf[23].nome, "Santa Catarina");
	strcpy(uf[23].abreviacao, "SC");
	uf[23].codigo = 42;
	strcpy(uf[24].nome, "Sao Paulo");
	strcpy(uf[24].abreviacao, "SP");
	uf[24].codigo = 35;
	strcpy(uf[25].nome, "Segipe");
	strcpy(uf[25].abreviacao, "SE");
	uf[25].codigo = 26;
	strcpy(uf[26].nome, "Tocantins");
	strcpy(uf[26].abreviacao, "TO");
	uf[26].codigo = 17;
}

char cadastro_fabricante(Fabricantes fabricante[],int *qtd_fabricante, Uf uf[]){

	int escolha=0;
	char opcao;

	system("cls");
	printf("\tCadastro de fabricantes\n");
	printf("Marca: ");
	scanf(" %[^\n]", &fabricante[*qtd_fabricante].marca);
	printf("Site: ");
	scanf(" %[^\n]", &fabricante[*qtd_fabricante].site);
	printf("Telefone: ");
	scanf("%d", &fabricante[*qtd_fabricante].telefone);
	printf("Estados\n");
	listar_uf(uf);
	escolha = le_valida_opcao_uf();
	fabricante[*qtd_fabricante].uf = uf[escolha-1];		
	if (*qtd_fabricante < 1){
		opcao = '9';
	}else if(*qtd_fabricante == TAM_FABRICANTES-1){
		opcao = '0';
	}else{
		printf("\n\n- [0] Voltar para a tela inicial\n");
		printf("- [9] Continuar cadastrando\n"); 
		opcao=le_valida_opcao_retorno();
	}
	fabricante[*qtd_fabricante].codigo = *qtd_fabricante +1;
	*qtd_fabricante = *qtd_fabricante + 1;
	return opcao;
}

char cadastro_produto(Produtos produto[], int *pt_qtd_produtos, Fabricantes fabricante[], int qtd_fabricantes){
	
	int escolha=0;
	char opcao;
	

	system("cls");
	printf("\tCadastro de produtos\n");
	printf("Descricao: ");
	scanf(" %[^\n]s", &produto[*pt_qtd_produtos].descricao);
	produto[*pt_qtd_produtos].peso = le_valida_peso();
	produto[*pt_qtd_produtos].valor_compra = le_valida_compra();
	produto[*pt_qtd_produtos].valor_venda = le_valida_venda();
	produto[*pt_qtd_produtos].valor_lucro = produto[*pt_qtd_produtos].valor_venda - produto[*pt_qtd_produtos].valor_compra;
	produto[*pt_qtd_produtos].percentual_lucro = (produto[*pt_qtd_produtos].valor_lucro / produto[*pt_qtd_produtos].valor_compra) * 100;
	escolha= le_valida_escolha_marca(&qtd_fabricantes, fabricante);
	produto[*pt_qtd_produtos].fabricante = fabricante[escolha-1];
	if (*pt_qtd_produtos < 4){
		opcao = '9';
	}else if(*pt_qtd_produtos == TAM_PRODUTOS-1){
		opcao = '0';
	}else{
		printf("\n\n- [0] Voltar para a tela inicial\n");
		printf("- [9] Continuar cadastrando\n");
		opcao=le_valida_opcao_retorno();
	}

	*pt_qtd_produtos = *pt_qtd_produtos + 1;
	return opcao;
}

// procedimentos bubble sort

void bubble_crescente_venda(Produtos produto[], int qtd_produtos){
	int i=0,j=0;
	Produtos aux;

    for(i=0;i<qtd_produtos;i++){
        for(j=0;j<qtd_produtos-i-1;j++){
            if(produto[j].valor_venda>produto[j+1].valor_venda){
                aux = produto[j];
                produto[j] = produto[j+1];
                produto[j+1] = aux;
            }
        }
    }
}

void bubble_crescete_lucro(Produtos produto[], int qtd_produtos){
	int i=0,j=0;
	Produtos aux;

    for(i=0;i<qtd_produtos;i++){
        for(j=0;j<qtd_produtos-i-1;j++){
            if(produto[j].valor_lucro>produto[j+1].valor_lucro){
                aux = produto[j];
                produto[j] = produto[j+1];
                produto[j+1] = aux;
            }
        }
    }
}

void bubble_crescente_porcentagem(Produtos produto[], int qtd_produtos){
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
}

void bubble_az(Produtos produto[], int qtd_produtos){
	int i=0, j=0;
	Produtos aux;

	for(i=0;i<qtd_produtos;i++){
        for(j=0;j<qtd_produtos-i-1;j++){
            if(strcmp(produto[j].descricao, produto[j+1].descricao) > 0){
                aux = produto[j];
                produto[j] = produto[j+1];
                produto[j+1] = aux;
            }
        }
    }
}

void bubble_za(Produtos produto[], int qtd_produtos){
	int i=0, j=0;
	Produtos aux;

	for(i=0;i<qtd_produtos;i++){
        for(j=0;j<qtd_produtos-i-1;j++){
            if(strcmp(produto[j].descricao, produto[j+1].descricao) < 0){
                aux = produto[j];
                produto[j] = produto[j+1];
                produto[j+1] = aux;
            }
        }
    }
}

void bubble_az_produto_estado(Produtos produto[], int qtd_produtos){
	int i=0, j=0;
	Produtos aux;

	for(i=0;i<qtd_produtos;i++){
        for(j=0;j<qtd_produtos-i-1;j++){
            if(strcmp(produto[j].fabricante.uf.abreviacao, produto[j+1].fabricante.uf.abreviacao) > 0){
                aux = produto[j];
                produto[j] = produto[j+1];
                produto[j+1] = aux;
            }
        }
    }
}

void bubble_az_produto_fabricante(Produtos produto[], int qtd_produtos){
	int i=0, j=0;
	Produtos aux;

	for(i=0;i<qtd_produtos;i++){
        for(j=0;j<qtd_produtos-i-1;j++){
            if(strcmp(produto[j].fabricante.marca, produto[j+1].fabricante.marca) > 0){
                aux = produto[j];
                produto[j] = produto[j+1];
                produto[j+1] = aux;
            }
        }
    }
}
// funcoes le_valida

int le_valida_opcao_menu(){
    int  count=0;
	char opcao;
    do{
        if(count>0){
            printf("\nEscolha uma opcao entre 0 e 9 ou A e Z!\n");
        }
        printf("\nEscolha uma das opcoes acima: ");	
        scanf(" %c",&opcao);
		opcao = toupper(opcao);
        count++;
    }while(opcao != '0' && opcao != '1' && opcao != '2' && opcao != '3' && opcao != '4' && opcao != '5' && opcao != '6' && opcao != '7' && opcao != '8' && opcao != '9' && opcao != 'A' && opcao != 'Z' && opcao != 'B' && opcao != 'C');
	return opcao;
}

int le_valida_opcao_retorno(){
	int count=0;
	char opcao;
    do{
        if(count>0){
            printf("\nEscolha 0 ou 9!\n");
        }
        printf("\nEscolha: ");
        scanf(" %c",&opcao);
        count++;
    }while(opcao !='0' && opcao != '9');
	return opcao;
}

int le_valida_opcao_uf(){
	int opcao=0, count=0;

    do{
        if(count>0){
            printf("\nEscolha entre 1 e 27!\n");
        }
        printf("\nEscolha: ");
        scanf("%d",&opcao);
        count++;
    }while(opcao < 1 || opcao > 27);
	return opcao;	
}

int le_valida_escolha_marca(int *qtd_fabricantes, Fabricantes fabricante[]){
	int escolha=0, i=0, count=0;
	
	printf("Marca\n");
	for(i=0;i<*qtd_fabricantes;i++){
		printf("- [%d] %s\n",i+1, fabricante[i].marca);
	}
	do{
		if(count >0){
			printf("\t--Erro--\n");
			printf("Escolha entre 1 e %d\n", *qtd_fabricantes);
		}
		printf("Escolha: ");
		scanf("%d", &escolha);
		count++;
	}while(escolha <1 || escolha > *qtd_fabricantes);
	
	return escolha;
}

float le_valida_peso(){
	float peso=0;
	int count=0;
	do{
		if(count > 0){
			printf("\t--Erro--\n");
			printf("Peso permitido entre 0.05kg e 50kg\n");
		}	
		printf("Peso(kg): ");
		scanf("%f", &peso);
		count++;
	}while(peso < 0.05 || peso > 50);
	return peso;
}

float le_valida_compra(){

	int count=0;
	float valor_compra=0;
	
	do{
		if(count > 0){
			printf("\t--Erro--\n");
			printf("Valor permitido entre R$ 0.50 e R$ 8000\n");
		}	
		printf("Valor Compra: ");
		scanf("%f", &valor_compra);
		count++;
	}while(valor_compra <0.5 || valor_compra > 8000);

	return valor_compra;
}

float le_valida_venda(){

	int count=0;
	float valor_venda=0;
	
	do{
		if(count > 0){
			printf("\t--Erro--\n");
			printf("Valor permitido entre R$ 1 e R$ 10000\n");
		}	
		printf("Valor Venda: ");
		scanf("%f", &valor_venda);
		count++;
	}while(valor_venda < 1 || valor_venda > 10000);

	return valor_venda;
}