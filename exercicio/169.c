#include <stdio.h>
#include <stdlib.h>

int contFuncao( int valores[], int alvo, int inicio, int fim ){
    int contagem = 0;

    for(int i = inicio; i<=fim-1; i++){
        //printf("entrou, o número é: %d !\n", valores[i]);
        if(valores[i] == alvo){
            contagem++; //somando as repetições
        }  
    }

    return contagem;

}

int maiorElemento(int inicio, int fim, int valores[]){
    
    if(inicio == fim){
        return valores[inicio];
    }

    int medio = (inicio + fim)/2; //pegando o espaço médio do array de valores. Para dividir ao meio
    //printf("%d", &medio);
    int divisaoEsquerda = maiorElemento(inicio, medio, valores); //chamada recursiva dividindo o vetor ao meio, pegando a parte mais a esquerda.
    int divisaoDireita = maiorElemento(medio+1, fim, valores); //o mesmo acima mas pegando a direita. 

    int contagemMaiorEsquerda = contFuncao(valores, divisaoEsquerda, inicio, fim); //realizando a contagem
    int contagemMaiorDireita = contFuncao(valores, divisaoDireita, inicio, fim); //o mesmo

    if(contagemMaiorEsquerda > contagemMaiorDireita){
        return divisaoEsquerda;
    }else{
        return divisaoDireita;
    }

    
    //return medio;
}




int main(){

    int valores[] = {2,2,1,1,1,2,2,9,1,1,1,1,9,9,9,9};
    //int saida = contFuncao(valores, 2, 0, 4);
    //int saida2 = maiorElemento(0, 4, valores);
    //printf("%d\n", saida);
    //printf("%d\n", saida2);

    int arr_size = sizeof(valores)/sizeof(valores[0]);

//    int extensaoVetor = tamanhoVetor(valores);

    //printf("%d\n", arr_size);

    int saida = maiorElemento(0, arr_size-1, valores);
    printf("%d\n", saida);
    return 0;
}