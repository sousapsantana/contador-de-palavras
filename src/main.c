/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */

#include <stdio.h>

int palavra(char c );
  
int pontofinal=0;
int pontuacao=0;

int main() {

  char c;
  int plv=0;
  int flag=0;


  c = 1;
  while (c != '\n') {       
    scanf("%c", &c);
    
    if(pontofinal==1 && (c >= 48 && c <=57)){ //se teve um ponto final e agora eh um numero entao eh ponto flutuante
        plv++;
        pontofinal=0; //ja tratei o ponto final
    }
    else if((pontofinal==1 || pontuacao==1) && palavra(c)==1){ //se teve um ponto final ou outra pontuacao e agora eh uma letra entao a pessoa nao deu espaco e comecou uma nova palavra
        plv++;
        flag=1;
        pontofinal=0; //ja tratei o ponto final
        pontuacao=0; //ja tratei a pontuacao
    }
    else if(flag==0 && palavra(c)==1){
	plv++;
	flag=1;	//entrei em uma palavra	
    }
    else if(flag==1 && palavra(c)==0){
	flag=0;	//sai de uma palavra	
    }
  
      
}
  printf("%d\n", plv);
  return 0;
}

int palavra(char c ){ //Função que confere se um caracter pode ser parte de uma palavra (retorna 1) ou não (retorna 0)
    
    if(c == 46){ //se for um ponto final
        pontofinal=1; //apareceu um ponto final
        return 0;
    }
    else if((c >= 33 && c <=47) || (c >= 58 && c <=64)){ //se for uma virgula ou outra pontuacao
        pontuacao=1; //apareceu uma pontuacao
        return 0;
    }
    else if(c >= 48 && c <=57){ //se for um numero de 0 a 9 pode ser parte de uma palavra
        
        return 1; 
    }
    
    else if(c >= 65 && c <=90){ //se for uma letra maiuscula de A a Z pode ser parte de uma palavra
        return 1;    
    }
    else if(c >= 97 && c <=122){ //se for uma letra minuscula de A a Z pode ser parte de uma palavra
        return 1;
    }
    else if((c >= 128 && c <=167)||(c >= 181 && c <=183)||(c >= 198 && c <=199)||(c >= 181 && c <=183)){ //se for uma letra com acento ou uma letra de outro alfabeto pode ser parte de uma palavra
        return 1;
    }
    return 0;
}

