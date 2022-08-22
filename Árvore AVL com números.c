/*Renan Justino Rezende Silva - 11921BSI223*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    int dado;
    // Altura do nó
    int height;
    // Ponteiro para subárvore a esquerda
    struct node* left;
    // Ponteiro para subárvore a direita
    struct node* right;
};

typedef struct node* AVL;
// Cria uma árvore
AVL* createAVL() {
    AVL* root = (AVL*)malloc(sizeof(AVL));
    if (root != NULL)
        *root = NULL;
    return root;
}

// Libera um nó da memória
void freeNode(struct node* node) {
    if (node == NULL)
        return;
    freeNode(node->left);
    freeNode(node->right);
    free(node);
    node = NULL;
}

// Libera uma árvore da memória
void freeAVL(AVL* root) {
    if (root == NULL)
        return;
    // Libera cada nó
    freeNode(*root);
    // Libera a raiz
    free(root);
}

// Retorna a altura no nó
int nodeHeight(struct node* node) {
    if (node == NULL)
        return -1;
    else
        return node->height;
}

// Retorna fator de balanceamento do nó
int nodeBalanceFactor(struct node* node) {
    return labs(nodeHeight(node->left) - nodeHeight(node->right));
}

// Verifica se a árvore está vazia
int isEmptyAVL(AVL* root) {
    if (root == NULL)
        return 1;
    if (*root == NULL)
        return 1;
    return 0;
}

// Retorna o total de nós da árvore
int totalNodesAVL(AVL* root) {
    if (root == NULL)
        return 0;
    if (*root == NULL)
        return 0;
    int h_left = totalNodesAVL(&((*root)->left));
    int h_right = totalNodesAVL(&((*root)->right));
    return(h_left + h_right + 1);
}

// Retorna a altura da árvore
int AVLHeight(struct node* node) {
    if (node == NULL)
        return 0;
    int h_left = AVLHeight(node->left);
    int h_right = AVLHeight(node->right);
    if (h_left > h_right)
        return (h_left + 1);
    else
        return(h_right + 1);
}

// Imprime a árvore em stdout
void printAVLInOrder(AVL* root) {
    if (root == NULL)
        return;
    if (*root != NULL) {
        printAVLInOrder(&((*root)->left));
        printf("Registro: %d Data: %d\n", (*root)->dado, (*root)->data);
        printf("End Esq:%p - End. no:%p - End dir:%p\n\n", (*root)->left,(*root),(*root)->right);
        printAVLInOrder(&((*root)->right));
    }
}


// Retorna o maior valor entre x e y
int greater(int x, int y) {
    if (x > y)
        return x;
    else
        return y;
}

// Realiza uma rotação a direita na árvore
void rotationRight(AVL* A) {//LL

   
    struct node* B = (*A)->left;
    (*A)->left = B->right;
    B->right = (*A);

    (*A)->height = greater(nodeHeight((*A)->left), nodeHeight((*A)->right)) + 1;
    B->height = greater(nodeHeight(B->left), (*A)->height) + 1;

    *A = B;
}

// Realiza uma rotação a esquerda na árvore
void rotationLeft(AVL* A) {//RR
   

    struct node* B = (*A)->right;
    (*A)->right = B->left;
    B->left = (*A);

    (*A)->height = greater(nodeHeight((*A)->left), nodeHeight((*A)->right)) + 1;
    B->height = greater(nodeHeight(B->right), (*A)->height) + 1;

    (*A) = B;
}

// Realiza uma rotação dupla a direita na árvore
void doubleRotationRight(AVL* A) {//LR
   
    rotationLeft(&(*A)->left);
    rotationRight(A);
}

// Realiza uma rotação dupla a esquerda na árvore
void doubleRotationLeft(AVL* A) {//RL
   
    rotationRight(&(*A)->right);
    rotationLeft(A);
}

// Insere um novo nó na árvore
// data é um vetor de strings
int insertNodeAVL(AVL* root, int dado, int data) {
    int r;
    // Árvore vazia ou nó folha
    if (*root == NULL) {
        struct node* new;
        new = (struct node*)malloc(sizeof(struct node));
        if (new == NULL)
            return 0;
        new->dado = dado;
        new->data = data;
        new->height = 0;
        new->left = NULL;
        new->right = NULL;
        *root = new;
        return 1;
    }

    struct node* current = *root;
    if (data<current->data) {
        r = insertNodeAVL(&(current->left), dado, data);
        if (r == 1) {
            if (nodeBalanceFactor(current) >= 2) {
                if (data<(*root)->left->data) {
                    rotationRight(root);
                } else {
                    doubleRotationRight(root);
                }
            }
        }
    } else {
        if (data>current->data) {
            r = insertNodeAVL(&(current->right),dado, data);
            if (r == 1) {
                if (nodeBalanceFactor(current) >= 2) {
                    if ((*root)->right->data<data)  {
                        rotationLeft(root);
                    } else {
                        doubleRotationLeft(root);
                    }
                }
            }
        } else {
          printf("\nValor duplicado!\n");
          return 0;
        }
    }

    current->height = greater(nodeHeight(current->left), nodeHeight(current->right)) + 1;

    return r;
}

// Retorna o nó com o menor valor na ávore
struct node* searchMinor(struct node* root) {
    struct node* current, * next;
    if (isEmptyAVL(&root)) return NULL;
    current = root;
    next = root->left;
    while (next != NULL) {
        current = next;
        next = next->left;
    }
    return current;
}

int removeNodeAVL(AVL* root, int data) {
    int r;

    // Valor não existe
    if (*root == NULL) {
        return 0;
    }

    if (data< (*root)->data) {
        r = removeNodeAVL(&(*root)->left, data);
        if (r == 1) {
            if (nodeBalanceFactor(*root) >= 2) {
                if (nodeHeight((*root)->right->left) <= nodeHeight((*root)->right->right))
                    rotationLeft(root);
                else
                    doubleRotationLeft(root);
            }
        }
    }

    if ((*root)->data<data) {
        r = removeNodeAVL(&(*root)->right, data);
        if (r == 1) {
            if (nodeBalanceFactor(*root) >= 2) {
                if (nodeHeight((*root)->left->right) <= nodeHeight((*root)->left->left))
                    rotationRight(root);
                else
                    doubleRotationRight(root);
            }
        }
    }

    if ((*root)->data==data) {
        if (((*root)->left == NULL || (*root)->right == NULL)) {// nó tem 1 filho ou nenhum
            struct node* older = (*root);
            if ((*root)->left != NULL)
                *root = (*root)->left;
            else
                *root = (*root)->right;
            free(older);
        } else {
            // Nó tem 2 filhos
            struct node* temp = searchMinor((*root)->right);
            removeNodeAVL(&(*root)->right, (*root)->data);
            if (nodeBalanceFactor(*root) >= 2) {
                if (nodeHeight((*root)->left->right) <= nodeHeight((*root)->left->left))
                    rotationRight(root);
                else
                    doubleRotationRight(root);
            }
        }
        if (*root != NULL)
            (*root)->height = greater(nodeHeight((*root)->left), nodeHeight((*root)->right)) + 1;
        return 1;
    }

    (*root)->height = greater(nodeHeight((*root)->left), nodeHeight((*root)->right)) + 1;
    return r;
}

int main()
{
  AVL* avl = createAVL();
int valor=0;
  int data;
  int dataExclusao;
  int i=1;
  int j;
  do{
  printf("\nDigite uma data para o registro %d: " , i);
  scanf("%d",&data);
    while(data<0 || data>31){
     printf("\nData inválida! Tem que ser entre 1 e 31.\n");
  printf("\nDigite uma data para o registro %d: " , i);
  scanf("%d",&data);
;}
      if(data>0 && data<=31){
      insertNodeAVL(avl,i,data);
      i++;
        }
       }while(data != 0);
  printf("\nDigite a data para deletar registros anteriores: ");
       scanf("%d", &dataExclusao);
       printf("\nListagem antes de excluir arquivos\n");
       printAVLInOrder(avl);
       for(j=0;j<dataExclusao;j++)
       removeNodeAVL(avl,j);
       printf("\nListagem apos exclusao de arquivos anteriores!\n");
       printAVLInOrder(avl);
return 0;
}