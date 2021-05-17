
#include<conio.h>
#include<stdio.h>
#include"arvore.h"
#include<string.h>
#include<ctype.h>
int main(){
     FILE *arq = fopen("palavras.txt","r");
     //char palavra[30000];
     char b[50],resp='S';
     int i=1;
	 int y;

     Arvore *a = novaArvore(NULL);



    while(fscanf(arq,"%s",b) != EOF){
      	if(a->raiz==NULL){
            insercaoRaiz(a,b,i);
            printf("%s\n",b);
      	}else{
      	    insercaoTxt(a->raiz,b,i);
      	    //printf("%s\n",palavra);
      	    printf("%s\n",b);
      	}
        i++;
    }
    fclose(arq);




 while(resp=='S'){
    printf("\n\ninforme uma palavra: ");
    scanf("%s",b);


    y = busca(a->raiz,b);
    if(y==-1){
    	printf("\n\nNao Achou!\n");
	}else{
		printf("Palavra: %s    na posicao: %d\n",b,y);
	}
   printf("\n\nContinuar(S/N): ");
   resp=toupper(getch());
   if(resp=='S'){
     //system("cls");
     preorder(a->raiz);
   }

 }



getch();
return 0;
}




