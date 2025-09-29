#include <stdio.h>

typedef union {
    char cpf[15];        
    char rg[20];         
    char nome[100]; 
} id;

typedef struct {
    int tipo; 
    id dado;  
} pessoa;

int main() {
    pessoa pes;
    
    printf("Cadastro de Cidadão\n");
    printf("Escolha o tipo de identificação (1-CPF, 2-RG, 3-NOME): ");
    
    scanf("%d", &pes.tipo); 

   
    if (pes.tipo == 1) {
        printf("Digite o CPF: ");
        scanf("%s", pes.dado.cpf); 
    } 
    else if (pes.tipo == 2) {
        printf("Digite o RG: ");
        scanf("%s", pes.dado.rg);
    } 
    else if (pes.tipo == 3) {
        printf("Digite o NOME COMPLETO: ");
        scanf("%99[^\n]", pes.dado.nome);
    } 
    else {
        printf("Opção inválida.\n");
        return 1;
    }

    printf("\nDados Registrados\n");
    if (pes.tipo == 1) {
        printf("Tipo: CPF\n");
        printf("Valor: %s\n", pes.dado.cpf);
    } else if (pes.tipo == 2) {
        printf("Tipo: RG\n");
        printf("Valor: %s\n", pes.dado.rg);
    } else if (pes.tipo == 3) {
        printf("Tipo: Nome Completo\n");
        printf("Valor: %s\n", pes.dado.nome);
    }
   
    return 0;
}
