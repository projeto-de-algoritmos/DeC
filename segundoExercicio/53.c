#include <stdio.h>
#include <stdlib.h>

int contFuncaoEsq( int valores[], int inicio, int fim ){
    int contagem = 0;
    int maiorSub = 0;

    for(int i = fim; i>=inicio; i--){
        //printf("entrou, o número é: %d !\n", valores[i]);
        contagem = valores[i] + contagem;

        if(maiorSub > contagem){
            maiorSub = maiorSub;
        }else{
            maiorSub = contagem;
        }

    }

       

    return maiorSub;

}

int contFuncaoDir( int valores[], int inicio, int fim ){
    int contagem = 0;
    int maiorSub = 0;

    for(int i = inicio+1; i<=fim; i++){
        //printf("entrou, o número é: %d !\n", valores[i]);
        // if(valores[i] == alvo){
        //     contagem++; //somando as repetições
        // }  
        contagem = valores[i] + contagem;
    
        if(maiorSub > contagem){
            maiorSub = maiorSub;
        }else{
            maiorSub = contagem;
        }
    }

    return maiorSub;

}


int maiorSubArray(int valores[], int inicio, int fim){
    
    if(inicio == fim){
        return valores[inicio];
    }

    int medio = (inicio + fim)/2; 
    int maiorSubArrayEsq = 0;
    int maiorSubArrayDir = 0;
    int soma = 0;
    int auxResult = 0;

    maiorSubArrayEsq = contFuncaoEsq(valores, inicio, medio );
    maiorSubArrayDir = contFuncaoDir(valores, medio, fim);
    //printf("maior valor esquerda %d\n", maiorSubArrayEsq);
    //printf("maior valor direita %d\n", maiorSubArrayDir);

    int somaArrays = maiorSubArrayEsq + maiorSubArrayDir;
    //printf("%d\n", somaArrays);
    int fimArrayEsq = maiorSubArray(valores, inicio, medio);
    int fimArrayDir = maiorSubArray(valores, medio, fim-1);

    if(fimArrayDir > fimArrayEsq){
        auxResult = fimArrayDir;
    }else{
        auxResult = fimArrayEsq;
    }

    if(auxResult > somaArrays){
        return auxResult;
    }else{
        return somaArrays;
    }

}

 
int main(){
    int valores[] = {-2,1,-3,4,-1,2,1,-5,4};

    int arr_size = sizeof(valores)/sizeof(valores[0]);


    int saida1 = maiorSubArray(valores, 0, arr_size-1);
    printf("%d\n", saida1);
    return 0;
}
