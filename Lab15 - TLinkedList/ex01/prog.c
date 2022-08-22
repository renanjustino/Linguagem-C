#include <stdio.h>
#include <stdlib.h>
#include "TLinkedList.h"

void retira_enter(char *a, int tamanho);

int main()
{
    List *li;
    int back, opcao, opcao1, i, posicao, posicao_lista;
    struct aluno aluno, aluno2;
    printf("     LISTA ALUNOS ENCADEADA\n");
    li = list_create();
    do{
        printf("\n1 - Adicionar elemento.\n2 - Excluir elemento.\n3 - Consultar elementos.\n4 - Tamanho da lista.\n5 - Imprimir primeiro/ultimo item.\n6 - Imprimir lista.\n7 - Fim\n\nSelecione uma opcao: ");
        scanf("%d", &opcao);
        getchar();
        switch(opcao){
        case 1:
            printf("\nDigite a matricula do aluno: ");
            scanf("%d", &aluno.matricula);
            getchar();
            printf("Digite o nome do aluno: ");
            fgets(aluno.nome, 30, stdin);
            retira_enter(aluno.nome, 30);
            for(i = 0; i < 3; i++){
                printf("Digite a %dª nota do aluno: ", i + 1);
                scanf("%lf", &aluno.n[i]);
                getchar();
            }
            printf("\n1 - Adicionar no inicio.\n2 - Adicionar no fim.\n3 - Adicionar por posicao.\n4 - Adicionar ordenadamente.\n\nSelecione uma opcao: ");
            scanf("%d", &opcao1);
            getchar();
            switch(opcao1){
            case 1:
                back = list_push_front(li, aluno);
                if(back == OUT_OF_MEMORY){
                    printf("\nOUT_OF_MEMORY\n");
                }else if(back == SUCCESS){
                    printf("\nAdicionado com sucesso!!!\n");
                }
                break;
            case 2:
                back = list_push_back(li, aluno);
                if(back == OUT_OF_MEMORY){
                    printf("\nOUT_OF_MEMORY\n");
                }else if(back == SUCCESS){
                    printf("\nAdicionado com sucesso!!!\n");
                }
                break;
            case 3:
                printf("Informe a posicao para inserir: ");
                scanf("%d", &posicao);
                getchar();
                back = list_insert(li, posicao, aluno);
                if(back == OUT_OF_MEMORY){
                    printf("\nOUT_OF_MEMORY\n");
                }else if(back == SUCCESS){
                    printf("\nAdicionado com sucesso!!!\n");
                }else if(back == OUT_OF_RANGE){
                    printf("\nPosicao informada invalida!!\n");
                }
                break;
            case 4:
                back = list_insert_sorted(li, aluno);
                if(back == OUT_OF_MEMORY){
                    printf("\nOUT_OF_MEMORY\n");
                }else if(back == SUCCESS){
                    printf("\nAdicionado com sucesso!!!\n");
                }
                break;
                }
            break;
        case 2:
             printf("\n1 - Remover do inicio.\n2 - Remover do fim.\n3 - Remover por posicao.\n\nSelecione uma opcao: ");
             scanf("%d", &opcao1);
             getchar();
             switch(opcao1){
             case 1:
                back = list_pop_front(li);
                if(back == OUT_OF_MEMORY){
                    printf("\nOUT_OF_MEMORY\n");
                }else if(back == INVALID_NULL_POINTER){
                    printf("\nLista vazia!!!\n");
                }else if(back == SUCCESS){
                    printf("\nItem removido com sucesso!!!\n");
                }
                break;
             case 2:
                back = list_pop_back(li);
                if(back == OUT_OF_MEMORY){
                    printf("\nOUT_OF_MEMORY\n");
                }else if(back == INVALID_NULL_POINTER){
                    printf("\nLista vazia!!!\n");
                }else if(back == SUCCESS){
                    printf("\nItem removido com sucesso!!!\n");
                }
                break;
             case 3:
                printf("Informe a posicao para remover: ");
                scanf("%d", &posicao);
                getchar();
                back = list_erase(li, posicao);
                if(back == OUT_OF_MEMORY){
                    printf("\nOUT_OF_MEMORY\n");
                }else if(back == INVALID_NULL_POINTER){
                    printf("\nLista vazia!!!\n");
                }else if(back == SUCCESS){
                    printf("\nItem removido com sucesso!!!\n");
                }else if(back == OUT_OF_RANGE){
                    printf("\nPosicao informada invalida!!\n");
                }
                break;
             }
             break;
        case 3:
             printf("\n1 - Consultar posicao.\n2 - Consultar matricula.\n3 - Consultar posicao por matricula.\n\nSelecione uma opcao: ");
             scanf("%d", &opcao1);
             getchar();
             switch(opcao1){
             case 1:
                printf("Informe a posicao para consultar: ");
                scanf("%d", &posicao);
                getchar();
                 back = list_find_pos(li, posicao, &aluno2);
                 if(back == OUT_OF_MEMORY){
                    printf("\nOUT_OF_MEMORY\n");
                }else if(back == INVALID_NULL_POINTER){
                    printf("\nLista vazia!!!\n");
                }else if(back == SUCCESS){
                    printf("\nMatricula aluno: %d\nNome aluno: %s\nNotas aluno:\n", aluno2.matricula, aluno2.nome);
                    for(i = 0; i < 3; i++){
                        printf("- Nota %d: %.2lf\n", i + 1, aluno2.n[i]);
                    }
                }else if(back == OUT_OF_RANGE){
                    printf("\nPosicao informada invalida!!\n");
                }
                break;
             case 2:
                printf("Informe a matricula para consultar: ");
                scanf("%d", &posicao);
                getchar();
                 back = list_find_mat(li, posicao, &aluno2);
                 if(back == OUT_OF_MEMORY){
                    printf("\nOUT_OF_MEMORY\n");
                }else if(back == INVALID_NULL_POINTER){
                    printf("\nLista vazia!!!\n");
                }else if(back == SUCCESS){
                    printf("\nMatricula aluno: %d\nNome aluno: %s\nNotas aluno:\n", aluno2.matricula, aluno2.nome);
                    for(i = 0; i < 3; i++){
                        printf("- Nota %d: %.2lf\n", i + 1, aluno2.n[i]);
                    }
                }else if(back == ELEM_NOT_FOUND){
                    printf("\nElemento nao encontrado\n");
                }
                break;
             case 3:
                printf("Informe a matricula para consultar: ");
                scanf("%d", &posicao);
                getchar();
                 back = list_get_pos(li, posicao, &posicao_lista);
                 if(back == OUT_OF_MEMORY){
                    printf("\nOUT_OF_MEMORY\n");
                }else if(back == INVALID_NULL_POINTER){
                    printf("\nLista vazia!!!\n");
                }else if(back == SUCCESS){
                    printf("\nAluno na posicao %d!\n", posicao_lista);
                }else if(back == ELEM_NOT_FOUND){
                    printf("\nElemento nao encontrado\n");
                }
             break;
             }
            break;
        case 4:
            back = list_size(li);
            if(back == OUT_OF_MEMORY){
                printf("\nOUT_OF_MEMORY\n");
            }
            printf("\nTamanho da lista: %d\n\n", back);
            break;
        case 5:
            printf("\n1 - Consultar primeiro item.\n2 - Consultar ultimo item.\n\nSelecione uma opcao: ");
            scanf("%d", &opcao1);
            getchar();
            switch(opcao1){
            case 1:
                back = list_front(li, &aluno2);
                 if(back == OUT_OF_MEMORY){
                    printf("\nOUT_OF_MEMORY\n");
                }else if(back == INVALID_NULL_POINTER){
                    printf("\nLista vazia!!!\n");
                }else if(back == SUCCESS){
                    printf("\nMatricula aluno: %d\nNome aluno: %s\nNotas aluno:\n", aluno2.matricula, aluno2.nome);
                    for(i = 0; i < 3; i++){
                        printf("- Nota %d: %.2lf\n", i + 1, aluno2.n[i]);
                    }
                }
            break;
            case 2:
                back = list_back(li, &aluno2);
                 if(back == OUT_OF_MEMORY){
                    printf("\nOUT_OF_MEMORY\n");
                }else if(back == INVALID_NULL_POINTER){
                    printf("\nLista vazia!!!\n");
                }else if(back == SUCCESS){
                    printf("\nMatricula aluno: %d\nNome aluno: %s\nNotas aluno:\n", aluno2.matricula, aluno2.nome);
                    for(i = 0; i < 3; i++){
                        printf("- Nota %d: %.2lf\n", i + 1, aluno2.n[i]);
                    }
                }
            }
            break;
            break;
        case 6:
            back = list_print(li);
            if(back == OUT_OF_MEMORY){
                printf("\nOUT_OF_MEMORY\n");
            } else if(back == ELEM_NOT_FOUND){
                printf("\nLista vazia!!\n");
            }
            break;
        case 7:
            back = list_free(li);
            if(back == OUT_OF_MEMORY){
                printf("\nOUT_OF_MEMORY\n");
            }else if(back == SUCCESS){
                printf("\nVolte sempre!!!");
            }
            break;
        }
    }while(opcao != 7);
    return 0;
}

void retira_enter(char *a, int tamanho){
    int i;
    for(i = 0; i < (tamanho-1); i++){
        if(a[i] == '\n'){
            a[i] = '\0';
        }
    }
}