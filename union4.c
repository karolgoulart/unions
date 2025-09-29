#include <stdio.h>

typedef union {
    float real;
    float dolar;
    float euro;
} valor;

typedef struct {
    valor val;
    int tipo; 
} preco;

void exibe(preco p) {
    if (p.tipo == 1){ 
    printf("Preço: R$ %.2f\n", p.val.real);
    }
    else if (p.tipo == 2) 
    printf("Preço: $ %.2f\n", p.val.dolar);
    else if (p.tipo == 3){
    printf("Preço: € %.2f\n", p.val.euro);
    }
    else{ 
    printf("Inválido!\n");
    }
}

preco altera(preco p, int novo_tipo) {
    preco novo;
    if (p.tipo == 1) { 
        if (novo_tipo == 2){
            novo.val.dolar = p.val.real / 5.3;
        }
        else if (novo_tipo == 3){
            novo.val.euro = p.val.real / 6.2;
        }
        else{
            novo.val.real = p.val.real;
        }
    } 
    else if (p.tipo == 2) { 
        if (novo_tipo == 1){
            novo.val.real = p.val.dolar * 5.3;
        }
        else if (novo_tipo == 3){
            novo.val.euro = (p.val.dolar * 5.3) / 6.2;
        }
        else{
            novo.val.dolar = p.val.dolar;
        }    
    } 
    else if (p.tipo == 3) { 
        if (novo_tipo == 1){
            novo.val.real = p.val.euro * 6.2;
        }
        else if (novo_tipo == 2){
            novo.val.dolar = (p.val.euro * 6.2) / 5.3;
        }
        else{
            novo.val.euro = p.val.euro;
        }
    }
    novo.tipo = novo_tipo;
    return novo;
}

int main() {
    preco p;
    int origem, destino;

    printf("Escolha a moeda:\n1 - Reais\n2 - Dolares\n3 - Euros\nOpção: ");
    scanf("%d", &origem);

    p.tipo = origem;
    printf("Digite o valor: ");
    if (origem == 1) scanf("%f", &p.val.real);
    else if (origem == 2) scanf("%f", &p.val.dolar);
    else if (origem == 3) scanf("%f", &p.val.euro);

    exibe(p);

    printf("\nEscolha a moeda para conversão:\n1 - Reais\n2 - Dolares\n3 - Euros\nOpção: ");
    scanf("%d", &destino);

    preco p2 = altera(p, destino);
    
    exibe(p2);

    return 0;
}
