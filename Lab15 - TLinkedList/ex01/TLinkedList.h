#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4

struct aluno{
    int matricula;
    char nome[30];
    double n[3];
};

<<<<<<< HEAD
typedef struct list List;
=======
typedef struct TLinkedList TLinkedList;

TLinkedList *list_create();
int list_free(TLinkedList *list);
int list_push_front(TLinkedList *list, struct aluno al);
int list_push_back(TLinkedList *list, struct aluno al);
int list_insert_sorted(TLinkedList *list, struct aluno al);


int list_print(TLinkedList *list);
>>>>>>> 1c960833a81e88484467e040c2dee1794073dfa3

List* list_create();
int list_free(List *li);
int list_push_front(List *li, struct aluno al);
int list_push_back(List *li, struct aluno al);
int list_insert(List *li, int pos, struct aluno al);
int list_insert_sorted(List *li, struct aluno al);
int list_size(List *li);
int list_pop_front(List *li);
int list_pop_back(List *li);
int list_erase(List *li, int pos);
int list_find_pos(List *li, int pos, struct aluno *al);
int list_find_mat(List *li, int nmat, struct aluno *al);
int list_front(List *li, struct aluno *al);
int list_back(List *li, struct aluno *al);
int list_get_pos(List *li, int nmat, int *pos);
int list_print(List *li);
