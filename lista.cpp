#include<stdio.h>

struct No {
    int valor;
    No* prox;

    No() {
        prox = NULL;
    }

    No(int _valor) {
        valor = _valor;
        prox = NULL;
    }
};

struct Lista {
    No* inicio;
    No* fim;
    int n;

    Lista() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    void inserirInicio(int valor) {
        No* novo = new No(valor);
        
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            novo->prox = inicio;
            inicio = novo;
        }
        
        n++;
    }

    void inserirFinal(int valor) {
        No* novo = new No(valor);
        
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
        
        n++;
    }

    void removerInicio() {
        if (n == 0) return;
        
        if (n == 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n--;
            return;
        }
        
        No* aux = inicio;
        inicio = inicio->prox;
        delete(aux);
        n--;
    }

    void removerFinal() {
        if (n == 0) return;
        
        if (n == 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n--;
            return;
        }
        
        No* aux = inicio;
        
        while (aux->prox != fim) {
            aux = aux->prox;
        }
        
        delete(fim);
        fim = aux;
        aux->prox = NULL;
        n--;
    }

    void imprimir() {
        No* aux = inicio;
        //printf("%d %d\n", aux, aux->valor);
        
        while (aux != NULL) {
            printf("%d\n", aux->valor);
            //printf("%d %d\n", aux->prox, aux->valor);
            aux = aux->prox;
        }
        printf("\n");
    }

    // Criar um método que recebe um número N e remove os N últimos elementos da lista. Caso o tamanho da lista seja menor que N, esvaziar a lista.
    void removerElementos(int valor) {
        if (n < valor) {
            while (n > 0) removerFinal();
            return;
        }

        for (int i = 0; i < valor; i++) removerFinal();
    }
    
    // Crie um método que remove o segundo elemento da lista. Se a lista tiver tamanho <= 1, seu método não deve fazer nada.
    void removerSegundoElemento() {
        if (n <= 1) return;
        
        No* aux = inicio->prox;
        inicio->prox = aux->prox;
        delete(aux);
        n--;
    }
    
    // Crie um método que seja capaz de inserir no final da lista o tamanho atual da lista.
    void inserirTamanhoAtual() {
        inserirFinal(n);
    }
    
    // Crie um método que receba um número N e insira na lista todos os números de 1 até N.
    void inserirDeUmAteN(int valor) {
        for (int i = 1; i <= valor; i++) {
            inserirFinal(i);
        }
    }
    
    // Crie um método que insere um elemento sempre na penúltima posição da lista. Se a lista tiver tamanho <= 1, seu método não deve fazer nada.
    void inserirPenultimaPosicao(int valor) {
        if (n <= 1) return;
        
        No* novo = new No(valor);
        novo->prox = fim;
        
        No* aux = inicio;
        
        while (aux->prox != fim) {
            aux = aux->prox;
        }
        
        aux->prox = novo;
        n++;
    }
};

int main() {
    Lista l;

    l.inserirInicio(10);
    l.inserirInicio(5);
    l.inserirInicio(1);
    l.inserirInicio(8);
    l.inserirFinal(7);
    l.inserirFinal(3);
    l.imprimir();
    
    // remove os 2 últimos elementos
    l.removerElementos(2);
    l.imprimir();
    
    // remove todos os elementos
    l.inserirFinal(7);
    l.inserirFinal(3);
    l.removerElementos(6);
    l.imprimir();
    
    // reinsere todos os elementos na lista e depois remove o segundo elemento
    l.inserirInicio(10);
    l.inserirInicio(5);
    l.inserirInicio(1);
    l.inserirInicio(8);
    l.inserirFinal(7);
    l.inserirFinal(3);
    l.removerSegundoElemento();
    l.imprimir();
    
    // insere o tamanho atual da lista ao seu final
    l.inserirTamanhoAtual();
    l.imprimir();
    
    // esvazia a lista e depois adiciona números de 1 a 5
    l.removerElementos(l.n);
    l.inserirDeUmAteN(5);
    l.imprimir();
    
    // insere um elemento na penúltima posição
    l.inserirPenultimaPosicao(10);
    l.imprimir();

    return 0;
}