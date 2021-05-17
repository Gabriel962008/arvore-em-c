#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
typedef struct Nodo{//criação da estrutura de um nodo
    char item[50];
    int pos;
    struct Nodo *esq,*dir;
}Nodo;

typedef struct Arvore{
     Nodo *raiz; //indicação de um nodo que indoca a raaiz
}Arvore;


Nodo * novoNodo(char i[],int v,Nodo *e,Nodo *d){
     Nodo *novo=(Nodo *)malloc(sizeof(Nodo));//criação do novo nodo
     strcpy(novo->item,i);
     novo->pos  = v;
     novo->esq  = e;
     novo->dir  = d;
     return novo;
}

Arvore * novaArvore(Nodo *raiz){//cração da nova arvore com o parametro indicando a raiz na chamada
  Arvore *nova = (Arvore *)malloc(sizeof(Arvore));
     nova->raiz = raiz;
  return nova;
}

int ehFolha(Nodo *n){//metodo que analisa se o nodo eh uma folha ou não
    int result;
    if(n->dir==NULL && n->esq==NULL){
        result = 1;
    }
    else{
        result = 0;
    }
    //return (n->esq ==NULL && n->dir ==NULL)? 1 : 0;//if else de uma linha
    return result;
}


void preorder(Nodo *n){//algoritimo de percurso
    if(n != NULL){
        //printf("%d - %s \n",n->pos,n->item);
        preorder(n->esq);
        preorder(n->dir);
    }
}

void inorder(Nodo *n){//algoritimo de percurso
     if(n!= NULL){//condição para execução
        inorder(n->esq);//vai para todo o lado esquerdo
           //printf(" %s \n",n->item);//e imprime na volta
           inorder(n->dir);//e na volta chama para o lado direitor
     }
}

void posorder(Nodo *n){//algoritimo de percurso
    if(n!= NULL){
        posorder(n->esq);
        posorder(n->dir);
        //printf(" %s \n",n->item);
    }
}

void insercaoRaiz(Arvore *a ,char i[],int val){//criação do nodo raiz
  Nodo *novo = novoNodo(i,val,NULL,NULL);//criação do nodo
  a->raiz = novo; //inserção do nodo como raiz
}



void insercaoTxt (Nodo *n,char i[],int val){
    if(strcmp(i,n->item)<0 && n->esq == NULL){//se o valor fos maior que n->valor existente e diferente de null
        Nodo *novo = novoNodo(i,val,NULL,NULL);//crai o novo nodo com o valor passado no parametro
        n->esq = novo;//coloca o novo nodo no local certo
    }else if(strcmp(i,n->item)<0 && n->esq != NULL){
        insercaoTxt(n->esq,i,val);//chama o proximo da esquerda para verificar caso ñ se ja null
    }else if(strcmp(i,n->item)>0 && n->dir == NULL){//caso para inserção no lado direito
       Nodo *novo = novoNodo(i,val,NULL,NULL);
       n->dir = novo;
    }else if(strcmp(i,n->item)>0 && n->dir !=NULL){
      insercaoTxt(n->dir,i,val);
    }
}


int busca(Nodo *n,char i[]){
     int achei = -1;

     while(n != NULL && achei==-1){//condições para a repetição da busca
        if(strcmp(n->item,i)==0){//strings iguais
           achei = n->pos;//retorna a posição
        }else if(strcmp(i,n->item)<0){//conferir esta condição
          n = n->esq;//senão percorrer a esquerda
        }else {//ou
          n = n->dir;//a direita
        }
     }
     return achei;
}


