#include <stdio.h>
<<<<<<< HEAD
=======
#include "TLinkedList.h"
>>>>>>> 1c960833a81e88484467e040c2dee1794073dfa3
#include <stdlib.h>
#include "TLinkedList.h"


typedef struct list_node List_node;
typedef struct list List;

struct list{
    List_node *head;
};

struct list_node{
    struct aluno data;
    List_node *next;
};

List* list_create(){
    List *li;

    li = (List *)malloc(sizeof(List));

    if(li != NULL){
        li->head = NULL;
    }

    return li;
}

int list_print(List *li){
    List_node *a = li->head;
    int i;
    if(li == NULL){
        return OUT_OF_MEMORY;
    }
    if(li->head == NULL){
        return ELEM_NOT_FOUND;
    }
    while(a != NULL){
        printf("\nMatricula aluno: %d\nNome aluno: %s\nNotas aluno:\n", a->data.matricula, a->data.nome);
        for(i = 0; i < 3; i++){
            printf("- Nota %d: %.2lf\n", i + 1, a->data.n[i]);
        }
        a = a->next;
    }
    return SUCCESS;
}

int list_free(List *li){
    List_node *aux, *aux2;
    if(li == NULL){
        return OUT_OF_MEMORY;
    }
    aux = li->head;
    while(aux != NULL){
        aux2 = aux->next;
        free(aux);
        aux = aux2;
    }
    free(li);
    return SUCCESS;
}

int list_push_front(List *li, struct aluno al){
    List_node *a;
    if(li == NULL){
        return OUT_OF_MEMORY;
    }
    a = (List_node *)malloc(sizeof(List_node));
    if(a == NULL){
        return OUT_OF_MEMORY;
    }
    a->data = al;
    a->next = li->head;
    li->head = a;

    return SUCCESS;
}

int list_push_back(List *li, struct aluno al){
    List_node *a, *prev;
    if(li == NULL){
        return OUT_OF_MEMORY;
    }
    prev = li->head;

    a = (List_node *)malloc(sizeof(List_node));
    if(a == NULL){
        return OUT_OF_MEMORY;
    }

    a->data = al;
    a->next = NULL;

    if(li->head == NULL){
        li->head = a;
        return SUCCESS;
    }

    while(prev->next != NULL){
        prev = prev->next;
    }

    prev->next = a;

    return SUCCESS;
}

int list_size(List *li){
    int aux;
    List_node *a;
    if(li == NULL){
        return OUT_OF_MEMORY;
    }

    a = li->head;
    aux = 0;

    while(a != NULL){
        a = a->next;
        aux++;
    }

    return aux;
}

int list_insert(List *li, int pos, struct aluno al){
    List_node *a, *aux;
    int back, i;
    if(li == NULL){
        return OUT_OF_MEMORY;
    }

    back = list_size(li);

    if(pos > back + 1){
        return OUT_OF_RANGE;
    }

    aux = li->head;
    if(pos == 1){
        back = list_push_front(li, al);
        return back;
    }
    a = (List_node *)malloc(sizeof(List_node));
    if(a == NULL){
        return OUT_OF_MEMORY;
    }
    a->data = al;


    for(i = 1; i < pos - 1; i++){
        aux = aux->next;
    }
    a->next = aux->next;
    aux->next = a;
    return SUCCESS;
}

int list_pop_front(List *li){
    List_node *aux;
    if(li == NULL){
        return OUT_OF_MEMORY;
    }
    if(li->head == NULL){
        return INVALID_NULL_POINTER;
    }
    aux = li->head->next;
    free(li->head);
    li->head = aux;
    return SUCCESS;
}

int list_pop_back(List *li){
    List_node *aux, *aux2;
    if(li == NULL){
        return OUT_OF_MEMORY;
    }
    if(li->head == NULL){
        return INVALID_NULL_POINTER;
    }
    aux = li->head;
    if(aux->next == NULL){
        free(aux);
        li->head = NULL;
        return SUCCESS;
    }
    while(aux->next != NULL){
        aux2 = aux;
        aux = aux->next;
    }

    free(aux);
    aux2->next = NULL;
    return SUCCESS;
}

int list_erase(List *li, int pos){
    List_node *aux, *aux2;
    int back, i;
    if(li == NULL){
        return OUT_OF_MEMORY;
    }
    if(li->head == NULL){
        return INVALID_NULL_POINTER;
    }

    aux = li->head;
    back = list_size(li);

    if(pos > back){
        return OUT_OF_RANGE;
    }
    if(pos == 1){
        back = list_pop_front(li);
        return back;
    }else{
        for(i = 1; i < pos; i++){
            aux2 = aux;
            aux = aux->next;
       }
       aux2->next = aux->next;
       free(aux);
    }
    return SUCCESS;
}

int list_find_pos(List *li, int pos, struct aluno *al){
    List_node *aux;
    int back, i;
    if(li == NULL){
        return OUT_OF_MEMORY;
    }
    if(li->head == NULL){
        return INVALID_NULL_POINTER;
    }

    aux = li->head;
    back = list_size(li);

    if(pos > back){
        return OUT_OF_RANGE;
    }

    for(i = 1; i < pos; i++){
        aux = aux->next;
    }
    *al = aux->data;
    return SUCCESS;
}

<<<<<<< HEAD
int list_find_mat(List *li, int nmat, struct aluno *al){
    List_node *aux;
    int back, i, mat;
    if(li == NULL){
        return OUT_OF_MEMORY;
    }
    if(li->head == NULL){
        return INVALID_NULL_POINTER;
    }

    aux = li->head;
    back = list_size(li);
    mat = aux->data.matricula;

    for(i = 0; i < back; i++){
        if(mat == nmat){
          *al = aux->data;
          return SUCCESS;
        }else
            aux = aux->next;
    }
    return ELEM_NOT_FOUND;
=======
int list_push_back(TLinkedList *list, struct aluno al)
{
    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        list_node *node;
        node = malloc(sizeof(list_node));
        if (node == NULL)
        {
            return OUT_OF_MEMORY;
        }
        node->data = al;
        node->next = NULL;

        if (list->head == NULL)
        {
            list->head = node;
        }
        else
        {
            list_node *aux;
            aux = list->head;
            while (aux->next != NULL)
            {
                aux = aux->next;
            }
            aux->next = node;
        }
        return SUCCESS;
    }
}

int list_print(TLinkedList *list)
{
    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        list_node *aux;
        aux = list->head;
        printf("\nImprimindo a lista\n");
        while (aux != NULL)
        {
            printf("\n------------------\n");
            printf("Matricula: %d\n", aux->data.matricula);
            printf("Nome: %s\n", aux->data.nome);
            printf("Notas: %f; %f; %f;\n", aux->data.n1, aux->data.n2, aux->data.n3);

            aux = aux->next;
        }
        printf("\nFim da lista \n");
        return SUCCESS;
    }
}

int list_free(TLinkedList *list)
{
    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        list_node *aux;
        aux = list->head;

        while (aux != NULL)
        {
            list->head = aux->next;
            // list->head = list->head->next;  (outra opção)
            free(aux);
            aux = list->head;
        }
        // segunda forma
        // while (list->head != NULL)
        // {
        //     aux = list->head;
        //     list->head = list->head->next;
        //     free(aux);
        // }

        free(list);
        return SUCCESS;
    }
}

int list_insert_sorted(TLinkedList *list, struct aluno al)
{
    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        list_node *node;
        node = malloc(sizeof(node));
        if (node == NULL)
        {
            return OUT_OF_MEMORY;
        }
        node->data = al;

        list_node *curr; // current - nó atual
        list_node *prev; // previous - nó anterior
        prev = NULL;
        curr = list->head;
        while ((curr != NULL) && curr->data.matricula < al.matricula)
        {
            prev = curr;
            curr = curr->next;
        }
        if (prev == NULL)  // insere na cabeça (lista vazia ou não)
        {
            node->next = list->head;
            list->head = node;
        }
        else
        {// insere a partir do segundo elemento (incluso)
            prev->next = node;
            node->next = curr;
        }
        return SUCCESS;
    }
>>>>>>> 1c960833a81e88484467e040c2dee1794073dfa3
}

int list_front(List *li, struct aluno *al){
    if(li == NULL){
        return OUT_OF_MEMORY;
    }
    if(li->head == NULL){
        return INVALID_NULL_POINTER;
    }
    *al = li->head->data;
    return SUCCESS;
}

int list_back(List *li, struct aluno *al){
   List_node *aux;
   if(li == NULL){
        return OUT_OF_MEMORY;
    }
    if(li->head == NULL){
        return INVALID_NULL_POINTER;
    }
    aux = li->head;
    while(aux->next != NULL){
        aux = aux->next;
    }
    *al = aux->data;
    return SUCCESS;
}

int list_get_pos(List *li, int nmat, int *pos){
   List_node *aux;
   int posicao;
   if(li == NULL){
        return OUT_OF_MEMORY;
    }
   if(li->head == NULL){
        return INVALID_NULL_POINTER;
    }
    posicao = 1;
   aux = li->head;
   while(aux->next != NULL){
        if(aux->data.matricula == nmat){
            *pos = posicao;
            return SUCCESS;
        }
        else{
            posicao++;
            aux = aux->next;
        }

   }
   if(aux->data.matricula == nmat){
            *pos = posicao;
            return SUCCESS;
    }
   return ELEM_NOT_FOUND;
}


int list_insert_sorted(List *li, struct aluno al){
    List_node *aux, *a;
    int back;
    if(li == NULL){
        return OUT_OF_MEMORY;
    }
    back = list_size(li);
    aux = li->head;
    if(back == 0 || al.matricula < aux->data.matricula){
        list_push_front(li, al);
        return SUCCESS;
    }

    a = (List_node *)malloc(sizeof(List_node));
    if(a == NULL){
        return OUT_OF_MEMORY;
    }
    a->data = al;

    while(aux != NULL){
        if(al.matricula > aux->data.matricula && aux->next == NULL){
            aux->next = a;
            a->next = NULL;
            return SUCCESS;
        }else if(al.matricula > aux->data.matricula && al.matricula < aux->next->data.matricula){
            a->next = aux->next;
            aux->next = a;
            return SUCCESS;
        }
        aux = aux->next;
    }
    return SUCCESS;
}