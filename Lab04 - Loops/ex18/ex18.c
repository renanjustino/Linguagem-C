#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  
  char opcao;
  float ms, km;
  
  do{
    printf("<< Conversor >> \n");
    printf(" Digite uma opção  \n");
    printf("   1 - para converter de km/h para m/s \n");
    printf("   2 - para converter de m/s para hm/h \n");
    printf("   q - para sair \n");
    scanf("%s", &opcao);
    
    switch(opcao){
      case '1':
        printf("\nDigite a velocidade (km/h):");
        scanf("%f", &km);
        km = km / 3.6;
        if(km / floor(km) == 1)
          printf("\nA velocidade em m/s é %.0f\n", km);
        else
          printf("\nA velocidade em m/s é %.2f\n", km);
      break;
      case '2':
        printf("Digite a velocidade (m/s):");
        scanf("%f", &ms);
        ms = ms * 3.6;
        if(ms / floor(ms) == 1)
          printf("\nA velocidade em km/h é %.0f\n", ms);
        else
          printf("\nA velocidade em km/h é %.2f\n", ms);
      break;
      case 'q':
        return 0;
      break;
      printf("\n");
    }
  }while(opcao != 'q');
 
  return 0;
}


