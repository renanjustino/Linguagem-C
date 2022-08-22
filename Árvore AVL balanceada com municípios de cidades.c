/*Renan Justino Rezende Silva - 11921BSI223*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char nome[25];
    float area;
    int populacao;
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
        printf("Municipio: %s Area: %.2f Populacao: %d\n", (*root)->nome, (*root)->area, (*root)->populacao);
        printAVLInOrder(&((*root)->right));
    }
}

// Imprime a árvore em stdout
void printAVLInOrderAdress(AVL* root) {
    if (root == NULL)
        return;
    if (*root != NULL) {
        printAVLInOrderAdress(&((*root)->left));
        printf("Municipio: %s Area: %.2f Populacao: %d\n", (*root)->nome, (*root)->area, (*root)->populacao);
      printf("Esq:%p - End. No:%p - Dir:%p\n\n", (*root)->left,(*root),(*root)->right);
        printAVLInOrderAdress(&((*root)->right));
    }
}

void printAVLDensity(AVL* root) {
    if (root == NULL)
        return;
    if (*root != NULL) {
        printAVLDensity(&((*root)->left));
        printf("Municipio: %s Area: %.2f Populacao: %d Densidade: %.2f\n", (*root)->nome, (*root)->area, (*root)->populacao, (*root)->populacao/(*root)->area);
        printAVLDensity(&((*root)->right));
    }
}

void printAboveX(AVL* root, int X) {
    char str[30] = "Maior que o valor!\n";
    char str2[30] = "NAO eh maior que o valor!\n";
    if (root == NULL)
        return;
    if (*root != NULL) {
        printAboveX(&((*root)->left),X);
        printf("Municipio: %s Area: %.2f Pop: %d %s\n", (*root)->nome, (*root)->area, (*root)->populacao, (*root)->populacao  > X ? str : str2);
        printAboveX(&((*root)->right), X);
    }
}


// Verifica se um valor está presente na árvore.
// Caso positivo, retorna a informação no nó em que ele se encontra.
char** queryAVL(AVL* root, char* data) {
    if (root == NULL)
        return NULL;

    char** r = (char**)malloc(3 * sizeof(char*));
    for (size_t i = 0; i < 3; i++)
        r[i] = (char*)malloc(255 * sizeof(char));

    struct node* current = *root;
    while (current != NULL) {
        if (strcmp(data, current->nome) == 0) {
            for (size_t i = 0; i < 3; i++)
                strcpy(r[i], current->nome);
            printf("\nMunicipio %s encontrado! Area: %.2f Populacao: %d\n", *r, current->area, current->populacao);
            return r;
        }
        if (strcmp(data, current->nome) > 0)
            current = current->right;
        else
            current = current->left;
    }
    printf("\nNão encontrado, municipio nao existe no sistema!\n");
    return NULL;
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
    printf("\n Rotação Simples a Direita(LL).\n");
    
    struct node* B = (*A)->left;
    (*A)->left = B->right;
    B->right = (*A);

    (*A)->height = greater(nodeHeight((*A)->left), nodeHeight((*A)->right)) + 1;
    B->height = greater(nodeHeight(B->left), (*A)->height) + 1;

    *A = B;
}

// Realiza uma rotação a esquerda na árvore
void rotationLeft(AVL* A) {//RR
    printf("\n Rotação Simples a Esquerda(RR).\n");

    struct node* B = (*A)->right;
    (*A)->right = B->left;
    B->left = (*A);

    (*A)->height = greater(nodeHeight((*A)->left), nodeHeight((*A)->right)) + 1;
    B->height = greater(nodeHeight(B->right), (*A)->height) + 1;

    (*A) = B;
}

// Realiza uma rotação dupla a direita na árvore
void doubleRotationRight(AVL* A) {//LR
    printf("\n Rotação Dupla a Direita (LR).\n");
    rotationLeft(&(*A)->left);
    rotationRight(A);
}

// Realiza uma rotação dupla a esquerda na árvore
void doubleRotationLeft(AVL* A) {//RL
    printf("\n Rotação Dupla a Esquerda (RL).\n");
    rotationRight(&(*A)->right);
    rotationLeft(A);
}

// Insere um novo nó na árvore
// data é um vetor de strings
int insertNodeAVL(AVL* root, char nome[25], float area, int populacao) {
    int r;
    // Árvore vazia ou nó folha
    if (*root == NULL) {
        struct node* new;
        new = (struct node*)malloc(sizeof(struct node));
        if (new == NULL)
            return 0;

        strcpy(new->nome,nome);
        new->area = area;
        new->populacao = populacao;
        new->height = 0;
        new->left = NULL;
        new->right = NULL;
        *root = new;
        return 1;
    }

    struct node* current = *root;
    if (strcmp(nome, current->nome) < 0) {
        r = insertNodeAVL(&(current->left), nome,area,populacao);
        if (r == 1) {
            if (nodeBalanceFactor(current) >= 2) {
                if (strcmp(nome, (*root)->left->nome) < 0) {
                    rotationRight(root);
                } else {
                    doubleRotationRight(root);
                }
            }
        }
    } else {
        if (strcmp(nome, current->nome) > 0) {
            r = insertNodeAVL(&(current->right), nome,area,populacao);
            if (r == 1) {
                if (nodeBalanceFactor(current) >= 2) {
                    if (strcmp((*root)->right->nome, nome) < 0) {
                        rotationLeft(root);
                    } else {
                        doubleRotationLeft(root);
                    }
                }
            }
        } else {
            printf("Valor duplicado!!\n");
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

int main(){
AVL* avl = createAVL();
  int op, var;
  char nome[25];
  float area;
  float populacao;
  int exit = 0;
  int X;
  while (!exit) {
    printf("\n-- Menu Arvore AVL Municipios --\n"
         "1- Inserir municipio ordenado por nome.\n"
         "2- Buscar municipio.\n"
         "3- Listar municipios por ordem alfabetica.\n"
         "4- Contar total de municipios.\n"
         "5- Mostrar municipios com mais de X habitantes.\n"
         "6- Mostrar densidade de cada cidade.\n"
         "0- Sair do programa.\n");
      printf("\n\n OPCAO: ");
      scanf("%d", &op);

      switch (op) {
        case 1: 
         printf("\nNome Municipio: ");
         scanf(" %s[^\n]", nome);
         printf("Area: ");
         scanf(" %f", &area);
         printf("Populacao: ");
         scanf("%f", &populacao);
         insertNodeAVL(avl, nome,area,populacao);
         printf("Dados inseridos.\n\n");
         printAVLInOrder(avl);
        break;
        case 2:
         if (isEmptyAVL(avl)) {
            printf("Arvore vazia!");
            break;
         }
         printf("\nPalavra que deseja consultar: ");
         scanf(" %s[^\n]", nome);
         queryAVL(avl, nome);
         break;
        case 3:
         printAVLInOrderAdress(avl);
         break;
        case 4:
        printf("\nTotal de municipios = %d\n", totalNodesAVL(avl));
        break;
        case 5:
        printf("\nDigite um valor X para listar municipios com populacao acima: ");
       scanf("%d", &X);
       printf("\n");
       printAboveX(avl, X);
        break;
        case 6:
       printf("\n");
       printAVLDensity(avl);
        break;
        case 0: 
        freeAVL(avl);
        exit = 1;
        printf("\nFim do Programa!\n");
        break;
        default:
         printf("\nOpcao invalida.\n");
    }
}
  }