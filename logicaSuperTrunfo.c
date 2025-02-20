#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta de cidade
typedef struct {
    char estado[50];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} CartaCidade;

// Função para cadastrar uma cidade e preencher seus atributos
CartaCidade cadastrar_carta() {
    CartaCidade cidade;
    printf("Digite o estado da cidade: ");
    scanf(" %49s", cidade.estado);
    printf("Digite o nome da cidade: ");
    scanf(" %49s", cidade.nome);
    printf("Digite a população da cidade: ");
    scanf("%d", &cidade.populacao);
    printf("Digite a área da cidade (km²): ");
    scanf("%f", &cidade.area);
    printf("Digite o PIB da cidade: ");
    scanf("%f", &cidade.pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &cidade.pontos_turisticos);
    return cidade;
}

// Função que compara duas cartas de cidade com base em dois atributos
CartaCidade comparar_cartas(CartaCidade c1, CartaCidade c2, int atributo1, int atributo2) {
    CartaCidade vencedor;
    int empate = 0;
    
    float valor1, valor2;
    switch (atributo1) {
        case 1: valor1 = c1.populacao; valor2 = c2.populacao; break;
        case 2: valor1 = c1.area; valor2 = c2.area; break;
        case 3: valor1 = c1.pib; valor2 = c2.pib; break;
        case 4: valor1 = c1.pontos_turisticos; valor2 = c2.pontos_turisticos; break;
        default: printf("Atributo inválido!\n"); return c1;
    }
    
    if (valor1 > valor2) {
        return c1;
    } else if (valor2 > valor1) {
        return c2;
    } else {
        empate = 1;
    }
    
    if (empate) {
        switch (atributo2) {
            case 1: valor1 = c1.populacao; valor2 = c2.populacao; break;
            case 2: valor1 = c1.area; valor2 = c2.area; break;
            case 3: valor1 = c1.pib; valor2 = c2.pib; break;
            case 4: valor1 = c1.pontos_turisticos; valor2 = c2.pontos_turisticos; break;
            default: printf("Segundo atributo inválido!\n"); return c1;
        }
        return (valor1 > valor2) ? c1 : c2;
    }
    
    return c1;
}

// Função principal que executa o fluxo do programa
int main() {
    printf("Cadastro da primeira cidade:\n");
    CartaCidade carta1 = cadastrar_carta();
    printf("Cadastro da segunda cidade:\n");
    CartaCidade carta2 = cadastrar_carta();
    
    int opcao1, opcao2;
    printf("Escolha o primeiro atributo para comparação:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos turísticos\n");
    printf("Digite sua escolha: ");
    scanf("%d", &opcao1);
    
    printf("Escolha o segundo atributo para desempate:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos turísticos\n");
    printf("Digite sua escolha: ");
    scanf("%d", &opcao2);
    
    CartaCidade vencedor = comparar_cartas(carta1, carta2, opcao1, opcao2);
    
    printf("A cidade vencedora na categoria escolhida é: %s (%s)\n", vencedor.nome, vencedor.estado);
    
    return 0;
}
