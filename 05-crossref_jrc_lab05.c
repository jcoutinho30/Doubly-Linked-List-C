#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    struct no *proximo;
    struct no *anterior;
    struct no *ref;
    float chave;
    int tempo;
}No;

//adicionando elementos no meio da lista encadeada
void inserir_no_meio(No **lista, float x, int k, float y, int timing){
    No *aux, *aux_2, *novo = malloc(sizeof(No));
    int contador = 0;

    if(novo){
        novo->chave = x;
        novo->tempo = timing;
        novo->ref = NULL;
        
        //inserindo primeiro elemento na lista
        if(*lista == NULL){
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;
        }
        //trocando primeiro elemento da lista
        else{
            if(*lista != NULL && k == 0){
                aux_2 = *lista;
                novo->anterior = NULL;
                aux_2->anterior = novo;
                novo->proximo = aux_2;
                *lista = novo;
            }
            
            if(*lista != NULL && k != 0){
            
                aux = *lista;

                while((contador != (k-1)) && (aux->proximo != NULL)){
                    aux = aux->proximo;
                    contador++;
                }
                //trocando elementos no meio da lista
                if((contador == (k-1)) && (aux->proximo != NULL)){
                    novo->proximo = aux->proximo;
                    aux->proximo->anterior = novo;
                    novo->anterior = aux;
                    aux->proximo = novo;
                }
                else{
                    //trocando o ultimo elemento da lista
                    aux->proximo = novo;
                    novo->anterior = aux;
                    novo->proximo = NULL;
                }
            }
            }
        }
        else
            printf("deu merda");
        
        //ajustando o ponteiro ref
        No *aux_dir = NULL; //comeca
        No *aux_esq = NULL;
        int distancia_esq = 0;
        int distancia_dir = 0;
        int achei_dir = 0;
        int achei_esq = 0;

        //caso simples em que y=0
        if(y == 0)
            novo->ref = NULL;
        //analisando distancia direita
        if(y != 0){
            aux_dir = novo;
            while(aux_dir->proximo != NULL && aux_dir->chave != y){
                aux_dir = aux_dir->proximo;
                distancia_dir++;
            }
            if(aux_dir->chave != y){
                achei_dir = 1;
            }
            //analisando distancia esquerda
            aux_esq = novo;
            while(aux_esq->anterior != NULL && aux_esq->chave != y){
                aux_esq = aux_esq->anterior;
                distancia_esq++;
            }
            if(aux_esq->chave != y)
                achei_esq = 1;
            
            if(achei_dir == 1 && achei_esq == 0)
                novo->ref = aux_esq;
            if(achei_dir == 0 && achei_esq == 1)
                novo->ref = aux_dir;
            if(achei_dir == 0 && achei_esq == 0){
                if(distancia_dir > distancia_esq)
                    novo->ref = aux_esq;
                if(distancia_esq > distancia_dir)
                    novo->ref = aux_dir;
                if(distancia_esq == distancia_dir)
                    novo->ref = aux_esq;
            }
        }
        }

//removendo o elemento da lista
void remover_elemento(No **lista, float x){
    No *aux = NULL; 
    No *aux_1 = NULL; 
    No *aux_2 = NULL; 
    No *aux_3 = NULL;
    
    aux = *lista;
    if(aux->chave == x && aux->anterior == NULL && aux->proximo == NULL){
        *lista = NULL;
        free(aux);
    }

    else{
    while(aux->chave != x)
        aux = aux->proximo;

    if(aux->anterior == NULL || aux->proximo == NULL){

    if(aux->anterior == NULL && aux->proximo != NULL){

        aux_1 = *lista;

        while(aux_1 != NULL){
            if(aux_1->ref == aux){
                aux_1->ref = NULL;
                aux_1 = aux_1->proximo;
            }
            else
                aux_1 = aux_1->proximo;
        }

        *lista = aux->proximo;
        aux->proximo->anterior = NULL;
        free(aux);
    }
    if(aux->proximo == NULL && aux->anterior != NULL){
        aux_2 = *lista;
        
        
        while(aux_2){
            if(aux_2->ref == aux){
                aux_2->ref = NULL;
                aux_2 = aux_2->proximo;
            }
            else
                aux_2 = aux_2->proximo;
        }

        aux->anterior->proximo = NULL;
        free(aux);
    }
    }
    else{
        aux_3 = *lista;

        while(aux_3){
            if(aux_3->ref == aux){
                aux_3->ref = NULL;
                aux_3 = aux_3->proximo;
            }
            else
                aux_3 = aux_3->proximo;
        }
        aux->anterior->proximo = aux->proximo;
        aux->proximo->anterior = aux->anterior;
        free(aux);
    }
}
}

//realizando a impressão da nossa lista encadeada
void imprimindo_lista(No **lista){
    No *aux = NULL;
    aux = *lista;
    
    if(aux){
        if(aux->ref){
            printf("%.1f %d %.1f %d |", aux->chave, aux->tempo, aux->ref->chave, aux->ref->tempo);
        }
        else{
            printf("%.1f %d |", aux->chave, aux->tempo);
        }

        aux = aux->proximo;

        while(aux){
            if(aux->proximo == NULL){
                if(aux->ref){
                    printf(" %.1f %d %.1f %d\n", aux->chave, aux->tempo, aux->ref->chave, aux->ref->tempo);
                    break;
                }
                else{
                    printf(" %.1f %d\n", aux->chave, aux->tempo);
                    break;
                }
            }
            if(aux->ref){
                printf(" %.1f %d %.1f %d |", aux->chave, aux->tempo, aux->ref->chave, aux->ref->tempo);
                aux = aux->proximo;
        }
            else{
                printf(" %.1f %d |", aux->chave, aux->tempo);
                aux = aux->proximo;
            }
        }
    }
    else{
        printf("vazia\n");
    }
}

int main (void){
    No *lista = NULL;
    int timing = 0;
    char comando;

    while(scanf("%c", &comando) != 'f'){
        if(comando == 'i'){
            float key;
            int pos;
            float proc;
            scanf("%f %d %f", &key, &pos, &proc);
            timing++;
            inserir_no_meio(&lista, key, pos, proc, timing);
        }
        if(comando == 'r'){
            float chave_1;
            scanf("%f", &chave_1);
            timing++;
            remover_elemento(&lista, chave_1);
        }
        if(comando == 'p'){
            imprimindo_lista(&lista);
        }
        if(comando == 'f')
            break;
    }



}