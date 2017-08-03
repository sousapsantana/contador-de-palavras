/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */

#include <stdio.h>

int main() {

  char c;
  int plv=0;
  int flag=0;

  c = 1;
  while (c != '\n') {       
    scanf("%c", &c);
    if(flag==0 && ((c >= 65 && c <=90) || (c >= 97 && c <=122) || (c >= 48 && c <=57))){
	plv++;
	flag=1;		
    }
    if(flag==1 && (c < 48 || (c > 57 && c < 65) || (c > 90 && c < 97) || c > 122)){
	flag=0;		
    }
  }



  printf("%d\n", plv);
  return 0;
}

//quero fazer amor gostoso
