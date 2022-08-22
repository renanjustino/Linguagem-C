#include <stdio.h>
#include <stdlib.h>
#include "TDLinkedList.h"

typedef struct dlnode DLNode;

struct DlinkedList {
    DLNode *begin;
    DLNode *end;
    int size;
};

struct dlnode {
    struct aluno data;
    DLNode *next;
    DLNode *prev;
};

List* list_create(){
    List *li;

    li = (List *)malloc(sizeof(List));

    if(li != NULL){
        li->begin = NULL;
        li->end = NULL;
        li->size = 0;
    }

    return li;
}

int list_free(List *li){
    DLNode *aux, *aux2;
    if(li == NULL){
        return OUT_OF_MEMORY;
    }
    aux = li->begin;
    while(aux != NULL){
        aux2 = aux->next;
        free(aux);
        aux = aux2;
    }
    free(li);
    return SUCCESS;
}

int list_push_front(List *li, struct aluno al){
    DLNode *aux;
    if(li == NULL){
        return OUT_OF_MEMORY;
    }
    aux = (DLNode *)malloc(sizeof(DLNode));
    if(aux == NULL){
        return OUT_OF_MEMORY;
    }
    aux->data = al;
    aux->prev = NULL;
    aux->next = li->begin;
    li->begin = aux;
    if(li->size > 0){
        aux->next->prev = aux;
    }else{
        li->end = aux;
    }
    li->size++;
    return SUCCESS;
}

int list_push_back(List *li, struct aluno al){
    DLNode *aux;
    if(li == NULL){
        return OUT_OF_MEMORY;
    }
    aux = (DLNode *)malloc(sizeof(DLNode));
    if(aux == NULL){
        return OUT_OF_MEMORY;
    }
    aux->data = al;
    aux->next = NULL;
    aux->prev = li->end;
    li->end = aux;
    if(li->size > 0){
        aux->prev->next = aux;
    }
    else{
       li->begin = aux;
    }
    li->size++;
    return SUCCESS;
}

int list_insert(List *li, int pos, struct aluno al){
    DLNode *aux, *aux2;
    int i;
    if(li == NULL){
        return OUT_OF_MEMORY;
    }
    aux = (DLNode *)malloc(sizeof(DLNode));
    if(aux == NULL){
        return OUT_OF_MEMORY;
    }
    if(pos > li->size + 1){
        return OUT_OF_RANGE;
    }
    //teste se a inserçao se dara pelo inicio ou pelo fim
    if(pos <= (li->size / 2)){
        aux2 = li->begin;
        if(pos == 1){
            aux->data = al;
            aux->prev = NULL;
            aux->next = li->begin;
            li->begin = aux;
            if(li->size > 0){
                aux->next->prev = aux;
            }else{
                li->end = aux;
            }
            li->size++;
            return SUCCESS;
        }else{
            for(i = 1; i < pos - 1; i++){
                aux2 = aux2->next;
            }
            aux->data = al;
            aux->next = aux2->next;
            aux->prev = aux2;
            aux->next->prev = aux;
            aux->prev->next = aux;
            li->size++;
            return SUCCESS;
        }
    }else{
        aux2 = li->end;
        if(pos == li->size + 1){
            aux->data = al;
            aux->next = NULL;
            aux->prev = li->end;
            li->end = aux;
            if(li->size > 0){
                aux->prev->next = aux;
            }
            else{
               li->begin = aux;
            }
            li->size++;
            return SUCCESS;
        }else{
            for(i = li->size; i > pos + 1; i--){
                aux2 = aux2->prev;
            }
            aux->data = al;
            aux->prev = aux2->prev;
            aux->next = aux2;
            aux->next->prev = aux;
            aux->prev->next = aux;
            li->size++;
            return SUCCESS;
        }
    }
}

int list_size(List *li){
    if(li == NULL){
        return OUT_OF_MEMORY;
    }
    return li->size;
}

int list_pop_front(List *li){
    DLNode *aux;
    if(li == NULL){
        return OUT_OF_MEMORY;
    }if(li->begin == NULL || li->size == 0){
        return INVALID_NULL_POINTER;
    }
    aux = li->begin;
    if(aux->next == NULL){
        free(aux);
        li->begin = NULL;
        li->end = NULL;
        li->size = 0;
        return SUCCESS;
    }
    aux = aux->next;
    aux->prev = NULL;
    free(li->begin);
    li->begin = aux;
    li->size--;
    return SUCCESS;
}

int list_pop_back(List *li){
    DLNode *aux;
    if(li == NULL){
        return OUT_OF_MEMORY;
    }
    if(li->end == NULL || li->size == 0){
        return INVALID_NULL_POINTER;
    }
    aux = li->end;
    if(aux->prev == NULL){
        free(aux);
        li->begin = NULL;
        li->end = NULL;
        li->size = 0;
        return SUCCESS;
    }
    aux = aux->prev;
    aux->next = NULL;
    free(li->end);
    li->end = aux;
    li->size--;
    return SUCCESS;
}

int list_erase(List *li, int pos){
    int i;
    DLNode *aux;
    if(li == NULL){
        return OUT_OF_MEMORY;
    }
    if(li->end == NULL || li->size == 0){
        return INVALID_NULL_POINTER;
    }
    if(pos > li->size){
        return OUT_OF_RANGE;
    }
    if(pos <= (li->size / 2)){
        aux = li->begin;
        if(pos == 1){
            return list_pop_front(li);
        }else{
            for(i = 1; i < pos; i++){
                aux = aux->next;
            }
            aux->next->prev = aux->prev;
            aux->prev->next = aux->next;
            free(aux);
            li->size--;
            return SUCCESS;
        }
    }else{
        aux = li->end;
        if(pos == li->size){
            return list_pop_back(li);
        }else{
            for(i = li->size; i > pos; i--){
                aux = aux->prev;
            }
            aux->next->prev = aux->prev;
            aux->prev->next = aux->next;
            free(aux);
            li->size--;
            return SUCCESS;
        }
    }
}

int list_find_pos(List *li, int pos, struct aluno *al){
    int i;
    DLNode *aux;
    if(li == NULL){
        return OUT_OF_MEMORY;
    }
    if(li->end == NULL || li->size == 0){
        return INVALID_NULL_POINTER;
    }
    if(pos > li->size){
        return OUT_OF_RANGE;
    }
    if(pos <= (li->size / 2)){
        aux = li->begin;
        if(pos == 1){
            *al = li->begin->data;
            return SUCCESS;
        }else{
            for(i = 1; i < pos; i++){
                aux = aux->next;
            }
            *al = aux->data;
            return SUCCESS;
        }
    }else{
        aux = li->end;
        if(pos == li->size){
            *al = li->end->data;
            return SUCCESS;
        }else{
            for(i = li->size; i > pos; i--){
                aux = aux->prev;
            }
            *al = aux->data;
            return SUCCESS;
        }
    }
}

int list_find_mat(List *li, int nmat, struct aluno *al){
    int i;
    DLNode *aux;
    if(li == NULL){
        return OUT_OF_MEMORY;
    }
    if(li->end == NULL || li->size == 0){
        return INVALID_NULL_POINTER;
    }
    aux = li->begin;
    while(aux->next != NULL){
        if(aux->data.matricula == nmat){
            *al = aux->data;
            return SUCCESS;
        }
        aux = aux->next;
    }
    if(aux->next == NULL && aux->data.matricula == nmat){
        *al = aux->data;
        return SUCCESS;
    }
    return ELEM_NOT_FOUND;
}

int list_front(List *li, struct aluno *al){
    if(li == NULL){
        return OUT_OF_MEMORY;
    }
    if(li->begin == NULL){
        return INVALID_NULL_POINTER;
    }
    if(li->size == 0){
        return ELEM_NOT_FOUND;
    }
    *al = li->begin->data;
    return SUCCESS;
}

int list_back(List *li, struct aluno *al){
    if(li == NULL){
        return OUT_OF_MEMORY;
    }
    if(li->end == NULL){
        return INVALID_NULL_POINTER;
    }
    if(li->size == 0){
        return ELEM_NOT_FOUND;
    }
    *al = li->end->data;
    return SUCCESS;
}

int list_get_pos(List *li, int nmat, int *pos){
    int i, count;
    DLNode *aux;
    if(li == NULL){
        return OUT_OF_MEMORY;
    }
    if(li->end == NULL || li->size == 0){
        return INVALID_NULL_POINTER;
    }
    aux = li->begin;
    count = 1;
    while(aux->next != NULL){
        if(aux->data.matricula == nmat){
            *pos = count;
            return SUCCESS;
        }
        aux = aux->next;
        count++;
    }
    if(aux->next == NULL && aux->data.matricula == nmat){
        *pos = count;
        return SUCCESS;
    }
    return ELEM_NOT_FOUND;
}

int list_print_forward(List *li){
    DLNode *aux;
    int i;
    if(li == NULL){
        return OUT_OF_MEMORY;
    }
    if(li->begin == NULL || li->size == 0){
        return ELEM_NOT_FOUND;
    }
    aux = li->begin;
    while(aux != NULL){
        printf("\nMatricula aluno: %d\nNome aluno: %s\nNotas aluno:\n", aux->data.matricula, aux->data.nome);
        for(i = 0; i < 3; i++){
            printf("- Nota %d: %.2lf\n", i + 1, aux->data.n[i]);
        }
        aux = aux->next;
    }
    return SUCCESS;
}

int list_print_reverse(List *li){
    DLNode *aux;
    int i;
    if(li == NULL){
        return OUT_OF_MEMORY;
    }
    if(li->end == NULL || li->size == 0){
        return ELEM_NOT_FOUND;
    }
    aux = li->end;
    while(aux != NULL){
        printf("\nMatricula aluno: %d\nNome aluno: %s\nNotas aluno:\n", aux->data.matricula, aux->data.nome);
        for(i = 0; i < 3; i++){
            printf("- Nota %d: %.2lf\n", i + 1, aux->data.n[i]);
        }
        aux = aux->prev;
    }
    return SUCCESS;
}

int list_splice(List *dest, List *source, int pos){
    int i;
    DLNode *aux;
    if(dest == NULL){
        return -1;
    }
    if(source == NULL){
        return -1;
    }
    if(pos > dest->size + 1){
        return -1;
    }
    if(dest->size == 0){
        dest->begin = source->begin;
        dest->end = source->end;
        dest->size = source->size;
        source->begin = NULL;
        source->end = NULL;
        source->size = 0;
        return 0;
    }
    else if(source->size == 0){
        return 0;
    }
        aux = dest->begin;
        if(pos == 1){
            source->end = dest->begin;
            aux->prev = source->end;
            dest->begin = source->begin;
            dest->size = dest->size + source->size;
            source->size = 0;
            source->begin = NULL;
            source->end = NULL;
            return SUCCESS;
        }else{
            for(i = 1; i < pos-1; i++){
                aux = aux->next;
            }
            aux->next->prev = source->end;
            source->end->next = aux->next;
            aux->next = source->begin;
            source->begin->prev = aux;
            dest->size = dest->size + source->size;
            source->size = 0;
            source->begin = NULL;
            source->end = NULL;

            return SUCCESS;
        }
}

int list_erase_even(List *li){
    DLNode *aux, *aux2;
    if(li == NULL){
        return -1;
    }
    if(li->size == 0){
        return 0; //por nao ter o que apagar e nao influenciar negativamente na lista, coloco com um acerto
    }
    aux = li->begin;
    while(aux->next != NULL){
        if(aux->data.matricula % 2 == 0){
            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;
            li->size--;
            aux2 = aux;
            aux = aux->next;
            free(aux2);
        }else{
            aux = aux->next;
        }
    }
    if(aux->next == NULL){
        if(aux->data.matricula % 2 == 0){
            aux->prev->next = NULL;
            li->end = aux->prev;
            li->size--;
            free(aux);
        }
    }

    return 0;
}
