#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define t 50    // quantidade maxima de funcionarios possiveis no programa

int i=0;     // variavel de controle do numero de funcionarios registrados no sistema

typedef struct   // conjunto de variaveis de um funcionario
{
	int cpf,idade;
    float ht,vht,sl;
    char sexo[10],nome[30];
} Pessoa;

Pessoa funcionario[t];

void Adicionar(){
	int verificar=0;    // variavel para verificar se o funcionario já está registrado no sistema	
	system("cls");
	if(t<=i){// se o numero de funcionarios registrados for maior ou igual que o maximo permitido, volta para o menu inicial
		printf("Sistema Lotado\n");
		system("pause");
		return;
	}
		else{
		printf("*** Adicionar Funcionario ***\n");
		printf("\nNome do funcionario: ");
        scanf("%s",&funcionario[i].nome);
		printf("\nCPF do funcionario: ");
		scanf("%d",&verificar);
		for(int j=0;j<i;j++){                // verificação se o funcionario ja esta registrado
		if(verificar==funcionario[j].cpf){
		    printf("\nFuncionario ja registrado\n");
		    system("pause");
		    return;
	    }
    }
    funcionario[i].cpf=verificar;     // funcionario sendo adicionado ao sistema
    printf("\nSexo do funcionario: ");
    scanf("%s",&funcionario[i].sexo);
    printf("\nIdade do funcionario: ");
    scanf("%d",&funcionario[i].idade);
    printf("\nHoras Trabalhadas do Funcionario: ");
    scanf("%f",&funcionario[i].ht);
    printf("\nValor das Horas Trabalhadas do Funcionario: ");
    scanf("%f",&funcionario[i].vht);
    funcionario[i].sl=funcionario[i].ht*funcionario[i].vht;       // calculo do salario liquido
    if(funcionario[i].sl<=1751.81)   
    funcionario[i].sl=funcionario[i].sl*0.92;
    else if(funcionario[i].sl>=1751.82 && funcionario[i].sl<=2919.72)
    funcionario[i].sl=funcionario[i].sl*0.91;
    else if(funcionario[i].sl>=2919.73 && funcionario[i].sl<=5839.45)
    funcionario[i].sl=funcionario[i].sl*0.89;
}
	i++;               // variavel de controle de funcionarios incrementa 1 após o adicionamento do funcionario
	system("pause");
}

void Buscar(){
	int c,q=0,op;
	system("cls");
	printf("*** Pesquisar Funcionario ***\n");
	printf("\nInforme o CPF do funcionario desejado: ");
	scanf("%d",&c);
	for(int j=0;j<i;j++){
		if(c==funcionario[j].cpf){                      // busca do cpf desejado dentro do sistema 
			printf("\nNome: %s\n",funcionario[j].nome);
			printf("Sexo: %s\n",funcionario[j].sexo);
			printf("Idade: %d\n",funcionario[j].idade);
			printf("Horas Trabalhadas: %.2f\n",funcionario[j].ht);
			printf("Valor Horas Trabalhadas: %.2f\n",funcionario[j].vht);
			printf("Salario Liquido: %.2f\n\n",funcionario[j].sl);
			q++;                // variavel de controle para verificação se o cpf está registrado no sistema
		}
	}
	if(q==0){                 // se não tiver incremento na variavel, o cpf não está registrado 
		printf("\nFuncionario nao matriculado, deseja adicionar ao sistema ?\n");
		printf("\n[1] - Sim\n\n[2] - Nao\n\n-> ");
		scanf("%d",&op);
		if(op==1)
		Adicionar();
		else
		return;
	}
	system("pause");
}

void Salario(int n){     // Funcao para comparar salario dos funcionarios na funcao "Exibir"
	int v=0;
	for(int j=0;j<i;j++){
		if(n>4000){                              // Divisao das possibilidades de escolha do usuario
			if(funcionario[j].sl>=n){
			printf("\n*******************\n");
			printf("\nNome: %s\n",funcionario[j].nome);
			printf("CPF: %d\n",funcionario[j].cpf);
		    printf("Sexo: %s\n",funcionario[j].sexo);
            printf("Idade: %d\n",funcionario[j].idade);
		    printf("Horas Trabalhadas: %.2f\n",funcionario[j].ht);
		    printf("Valor Horas Trabalhadas: %.2f\n",funcionario[j].vht);
		    printf("Salario Liquido: %.2f\n",funcionario[j].sl);
		    v++;
		}
	}
	    else if(funcionario[j].sl<=n){
			printf("\n*******************\n");
			printf("\nNome: %s\n",funcionario[j].nome);
			printf("CPF: %d\n",funcionario[j].cpf);
		    printf("Sexo: %s\n",funcionario[j].sexo);
            printf("Idade: %d\n",funcionario[j].idade);
		    printf("Horas Trabalhadas: %.2f\n",funcionario[j].ht);
		    printf("Valor Horas Trabalhadas: %.2f\n",funcionario[j].vht);
		    printf("Salario Liquido: %.2f\n",funcionario[j].sl);
		    v++;
		}
	}
	if(v==0)
	printf("\nNenhum funcionario verificado\n\n");
	system("pause");
}

void Exibir(){
	int op,v;
	do{
	v=0;                     // variavel de verificação caso não tiver funcionarios na opção desejada
	system("cls");
	printf("*** Exibir Funcionarios ***\n");
	printf("\n[1] - Funcionarios com salario inferior a R$500\n");
	printf("\n[2] - Funcionarios com salario inferior a R$1000\n");
	printf("\n[3] - Funcionarios com salario superior a R$4000\n");
	printf("\n[4] - Funcionarios com salario superior ou igual a R$5000\n");
	printf("\n[5] - Funcionarios com salario superior ou igual a R$7000\n");
	printf("\n[6] - Funcionarios com salario superior ou igual a R$10000\n");
	printf("\n[7] - Todos os Funcionarios\n");
	printf("\n[0] - Sair\n\n-> ");
	scanf("%d",&op);
	switch(op){               // Enviando informação da opção desejada para funcao "Salario" comparar
		case 1: system("cls"); 
		        printf("*** Funcionarios com salario inferior a R$500 ***\n");
		        Salario(499);
				break;
	    case 2: system("cls");    
		        printf("*** Funcionarios com salario inferior a R$1000 ***\n");
		        Salario(999);
				break;
		case 3:	system("cls");	
				printf("*** Funcionarios com salario superior a R$4000 ***\n");	
				Salario(4001);
				break;
		case 4: system("cls");
		        printf("*** Funcionarios com salario superior ou igual a R$5000 ***\n");
				Salario(5000);			
				break;
		case 5: system("cls");
		        printf("*** Funcionarios com salario superior ou igual a R$7000 ***\n");  
		        Salario(7000);
				break;
		case 6: system("cls");
		        printf("*** Funcionarios com salario superior ou igual a R$10000 ***\n");
		        Salario(10000);
				break;
		case 7: system("cls");
		        printf("*** Todos os Funcionarios ***\n");
		        for(int j=0;j<i;j++){
		        	printf("\n*******************\n");
		        	printf("\nNome: %s\n",funcionario[j].nome);
					printf("CPF: %d\n",funcionario[j].cpf);
			        printf("Sexo: %s\n",funcionario[j].sexo);
			        printf("Idade: %d\n",funcionario[j].idade);
	                printf("Horas Trabalhadas: %.2f\n",funcionario[j].ht);
		            printf("Valor Horas Trabalhadas: %.2f\n",funcionario[j].vht);
		            printf("Salario Liquido: %.2f\n",funcionario[j].sl);
		            v++;
				}
				if(v==0)
				printf("\nNenhum funcionario verificado\n\n");
				system("pause");
				break;
		case 0: return;
		default: system("cls");
		         printf("\n*** Opcao invalida ***\n\n");
		         system("pause");
		         break;
	}
}while(op!=0);
}

void Arquivo(){
	int op;
	char n[50];
	FILE *arquivo;
	system("cls");
	printf("*** Salvar / Carregar Dados ***\n");
	printf("\n[1] - Salvar\n");
	printf("\n[2] - Carregar\n");
	printf("\n[0] - Voltar\n\n-> ");
	scanf("%d",&op);
	switch(op){
		case 1: system("cls");
		        printf("*** Salvar Arquivo ***\n");            // Salvar os dados em um arquivo externo
		        printf("\nInforme o nome do arquivo: ");
		        scanf("%s",&n);
		        strcat(n,".txt");                 // juntar nome do arquivo do usuario com o ".txt"
		        arquivo = fopen(n,"w");
		        fprintf(arquivo,"Numero de Funcionarios: %d\n",i);    // registrando o total de funcionarios no sistema
		        for(int j=0;j<i;j++){
		        	fprintf(arquivo,"\nNome: %s\n",funcionario[j].nome);   // registrando informações dos funcionarios
					fprintf(arquivo,"CPF: %d\n",funcionario[j].cpf);
			        fprintf(arquivo,"Sexo: %s\n",funcionario[j].sexo);
			        fprintf(arquivo,"Idade: %d\n",funcionario[j].idade);
	                fprintf(arquivo,"Horas Trabalhadas: %.2f\n",funcionario[j].ht);
		            fprintf(arquivo,"Valor Horas Trabalhadas: %.2f\n",funcionario[j].vht);
		            fprintf(arquivo,"Salario Liquido: %.2f\n",funcionario[j].sl);
				}
				printf("\nArquivo salvo\n\n");
		        fclose(arquivo);
		        system("pause");
		        break;
		case 2: system("cls");                       // Carregar algum arquivo externo       
		        printf("*** Carregar Arquivo ***\n");
		        printf("\nInforme o nome do arquivo: ");
		        scanf("%s",&n);
		        strcat(n,".txt");
		        arquivo=fopen(n,"r");
		        if(arquivo==NULL){                       // Caso não existir nenhum arquivo com o nome desejado
		        printf("\nArquivo nao encontrado\n\n");
		        system("pause");
		        return Arquivo();
		    }
		        else
		        {
		        	fseek(arquivo,23,0); fscanf(arquivo,"%d",&i);   // Lendo a quantidade funcionarios, para usar no "for"
		        	for(int j=0;j<i;j++){
		        	fseek(arquivo,9,1); fscanf(arquivo,"%s",&funcionario[j].nome); // Lendo informações dos funcionarios
		        	fseek(arquivo,6,1); fscanf(arquivo,"%d",&funcionario[j].cpf);
		        	fseek(arquivo,7,1); fscanf(arquivo,"%s",&funcionario[j].sexo);
		        	fseek(arquivo,8,1); fscanf(arquivo,"%d",&funcionario[j].idade);
		        	fseek(arquivo,20,1); fscanf(arquivo,"%f",&funcionario[j].ht);
		        	fseek(arquivo,26,1); fscanf(arquivo,"%f",&funcionario[j].vht);
		        	fseek(arquivo,18,1); fscanf(arquivo,"%f",&funcionario[j].sl);
		        }
			}
			printf("\nArquivo carregado\n\n");
			system("pause");
			break;
	}
}

int main(){
	int op;
	do{
	system("cls");
	printf("Escolha uma opcao:\n");                   // Menu inicial 
	printf("\n[1] - Adicionar Funcionario\n");
	printf("\n[2] - Pesquisar Funcionario\n");
	printf("\n[3] - Exibir Funcionario\n");
	printf("\n[4] - Salvar Dados / Carregar Dados\n");
	printf("\n[0] - Sair\n\n-> ");
	scanf("%d",&op);
	switch(op){
		case 1: Adicionar(); 
		        break;
		case 2: Buscar(); 
		        break;
		case 3: Exibir(); 
		        break;
		case 4: Arquivo(); 
		        break;
		case 0: break;
		default: printf("\nOpcao invalida\n\n");
		         system("pause"); break;
	}
}while(op!=0); 
system("cls");
printf("Programa Finalizado...\n");
return 0;
}

