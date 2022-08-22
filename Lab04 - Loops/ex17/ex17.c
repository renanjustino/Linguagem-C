#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  char letra;
  printf("<<Forca de uma letra só>>\n");
  for(short i = 0; i < 5; i++){
    if(i == 4){
      printf("\nÚltima chance!!!");
    }
    printf("\nQual a letra? ");
    scanf("%c", &letra);
    getchar();
    if(letra == 'w' || letra == 'W'){
      printf("ACERTOU!");
      return 0;
    }else if(letra != 'w' || letra != 'W'){
      if( i < 3 ){
        printf("\nErrado! Você tem mais %d chances", 4 - i);
      }
    }
  }
  printf("\nAcabaram suas chances. A letra correta é 'w'");
  return 0;
}

