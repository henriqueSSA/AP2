#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include<string.h>
#include<ctype.h>



int main(){
	setlocale(LC_ALL, "");
	char *fita, ch, buffer[15], operators[14] = { '(', ')', '{', '}', '=', '>', '<', '+', '-', '*', '/', '%',':'};
	
	FILE *arquivo;
	int i, j=0, k=0, cl=0, linha=1, tamanho=0;            //cl= cabeça de leitura
	
	arquivo = fopen("ArquivoFonte1.mln","r");              //abertura de arquivo.
	
	if(arquivo == NULL){
		printf("Problemas na abertura do arquivo\n");
		exit(0);
	}
	
	while(fgetc(arquivo) != EOF){
		tamanho++;                            //verifica quantidade de caracter no arquivo.
	}
	
	fita = (char *)malloc((tamanho+1) * sizeof(char));      //aloca dinâmicamente um vetor de char com tamanho do arquivo;
	
	fseek(arquivo, 0, SEEK_SET);             //retorna para o começo do arquivo.
	
	
    // Preenchendo fita com caracteres do arquivo.
	while((ch = fgetc(arquivo)) != EOF){      //variável "ch", que vai receber caractere por caractere do arquivo com o uso da funcao fgetc().
   		fita[k] = ch;
		fita[++k] = '\0'; 
		if(ch == '\n'){
			linha++;
		}  
	}
	
	
	while((ch = fita[cl]) != '\0'){
		for(i = 0; i < 12; ++i){
	   		if(ch == operators[i]){
	   			printf("%c é operador\n", ch);
	   			}
			}	
		if(isalnum(ch)){
	   		buffer[j++] = ch;
			}else if((ch == ' ' || ch == '\n' || '"' ) && (j != 0)){
	   			buffer[j] = '\0';
	   			j = 0;
	   			
	   			if(isKeyword(buffer) == 1){
		   			printf("%s é palavra chave\n", buffer);
					}else if(teste(buffer) == 1){
		   			printf("%s é identificador\n", buffer);
		   			}else if(isnum(buffer) == 1){
		   				printf("%s numero valido\n", buffer);
					   }	 				
		   	}
				
	cl++;	   		
	}
	

	
	//printf("%s\n", fita);
		
	printf("\nTamanho: %d caracteres  Linhas: %d\n", tamanho, linha);
	
	
	free(fita);
	fclose(arquivo);
	
	return 0;
}

char alfabeto[] = {'a', 'b', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k','l', 'm',
		'n', 'o', 'p', 'q','r', 's', 't', 'u','v', 'w', 'y','x', 'z', '0',
		'1', '2', '3', '4','5', '6', '7', '8', '9', '=','<', '>', '(', ')',
		'{', '}','+', '-', '%', ',', ';', '"', ';', '[', ']', '/', ':'};

int isKeyword(char buffer[]){
	char isKeyword[12][10] = {"for","step","step","sqrt","if","else","return",
							"print","read","to","num","string"};
	int i, flag = 0;
	
	for(i = 0; i < 12; ++i){
		if(strcmp(isKeyword[i], buffer) == 0){
			flag = 1;
			break;
		}
	}
	
	return flag;
}


int teste(char buffer[]) {
 	
 	int i=0, j=0, k=0;
    
    if (isdigit(buffer[0]) && isalpha(buffer[1])){
    	printf("%s palavra invalida\n", buffer);			
	}else if(isalpha(buffer[0]) && isalpha(buffer[1])){
		return 1;	
	}
}
 
 
 int isnum(char buffer[]) { 
	int i, len = strlen(buffer); 

	if (len == 0) 
		return 0; 
	for (i = 0; i < len; i++) { 
		if (buffer[i] != '0' && buffer[i] != '1' && buffer[i] != '2'
			&& buffer[i] != '3' && buffer[i] != '4' && buffer[i] != '5'
			&& buffer[i] != '6' && buffer[i] != '7' && buffer[i] != '8'
			&& buffer[i] != '9' || (buffer[i] == '-' && i > 0)) 
			return 0; 
	} 
	return 1; 
} 


