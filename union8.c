#include <stdio.h>
#include <stdbool.h>

typedef enum {
    anfibio,
    ave,
    mamifero,
    reptil
} Classe;

typedef union {
    struct {
        int patas;
        float espessuraPele;
        bool possuiCauda;
    } anfibio;

    struct {
        float comprimentoBico;
        float autonomiaVoo;
        float faixaFrequenciaCanto;
    } ave;

    struct {
        int dentes;
        float volumeCerebro;
        float velocidadeTerrestre;
    } mamifero;

    struct {
        bool venenoso;
        float autonomiaAgua;
        float espessuraOvos;
    } reptil;
} DadosAnimal;

typedef struct {
    char nomeEspecie[50]; 
    char corPredominante[30]; 
    Classe classe;
    DadosAnimal dados;
} Animal;

void exibirAnfibio(Animal a) {
    printf("%s (Anfíbio), Cor: %s, Patas = %d, Espessura Pele = %.2f, Possui Cauda = %s\n",
           a.nomeEspecie, a.corPredominante, a.dados.anfibio.patas,
           a.dados.anfibio.espessuraPele, a.dados.anfibio.possuiCauda ? "Sim" : "Não");
}

void exibirAve(Animal a) {
    printf("%s (Ave), Cor: %s, Comprimento Bico = %.2f, Autonomia Voo = %.2f, Faixa Frequência Canto = %.2f\n",
           a.nomeEspecie, a.corPredominante, a.dados.ave.comprimentoBico,
           a.dados.ave.autonomiaVoo, a.dados.ave.faixaFrequenciaCanto);
}

void exibirMamifero(Animal a) {
    printf("%s (Mamífero), Cor: %s, Dentes = %d, Volume Cérebro = %.2f, Velocidade Terrestre = %.2f\n",
           a.nomeEspecie, a.corPredominante, a.dados.mamifero.dentes,
           a.dados.mamifero.volumeCerebro, a.dados.mamifero.velocidadeTerrestre);
}

void exibirReptil(Animal a) {
    printf("%s (Réptil), Cor: %s, Venenoso = %s, Autonomia Debaixo d'água = %.2f, Espessura Ovos = %.2f\n",
           a.nomeEspecie, a.corPredominante, a.dados.reptil.venenoso ? "Sim" : "Não",
           a.dados.reptil.autonomiaAgua, a.dados.reptil.espessuraOvos);
}

int main() {
    Animal animais[6] = {
        {"Sapo Comum", "Verde", anfibio, {.anfibio = {4, 0.5, true}}},
        {"Papagaio", "Verde e Amarelo", ave, {.ave = {10.5, 5.0, 2000.0}}},
        {"Cachorro", "Marrom", mamifero, {.mamifero = {32, 1.2, 25.0}}},
        {"Cobra", "Preta", reptil, {.reptil = {true, 0.0, 0.3}}},
        {"Salamandra", "Laranja", anfibio, {.anfibio = {2, 0.3, false}}},
        {"Canário", "Amarelo", ave, {.ave = {5.2, 1.0, 1500.0}}}
    };

    
    exibirAnfibio(animais[0]);
    exibirAve(animais[1]);
    exibirMamifero(animais[2]);
    exibirReptil(animais[3]);
    exibirAnfibio(animais[4]);
    exibirAve(animais[5]);

    return 0;
}
