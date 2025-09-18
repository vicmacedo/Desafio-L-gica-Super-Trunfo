#include <stdio.h>
#include <string.h> // usado para remover o '\n' quando usamos fgets

// Desafio Super Trunfo - Países
// Tema 2 - Desenvolvimento da Lógica do Jogo

// Definição das variáveis usadas para guardar informação
struct Carta {
    char estado;
    char codigo[4];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float superPoder; // variável extra para o super poder da carta
    double densidade;     // população / área
    double pibPerCapita;  // pib / população
};

int main() {
    struct Carta carta1, carta2; //organiza as cartas para receber apenas o cadastro de duas cartas
    int numero, comparacao;  // variáveis para armazenar o número da carta e as escolhas de comparação
    int atributos = 1; // variáveis para verificar se os atributos escolhidos são válidos

    printf("JOGO SUPER TRUNFO\n");

    // Cadastro das Cartas:    
    printf("CADASTRO DE CARTAS ===============================================\n");
    printf("Insira os seguintes dados das cartas:\n");

    // Cadastro da Carta 1
    printf("=========== Carta 1\n");
    printf("Estado (A-H): ");
    scanf(" %c", &carta1.estado);

    printf("Código da Carta (01 à 04): ");
    scanf(" %d", &numero);
    sprintf(carta1.codigo, "%c%02d", carta1.estado, numero);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta1.cidade);

    printf("População da Cidade: ");
    scanf(" %d", &carta1.populacao);

    printf("Área da Cidade (km2): ");
    scanf(" %f", &carta1.area);

    printf("PIB da cidade (em bilhões): ");
    scanf(" %f", &carta1.pib);

    printf("Pontos Turísticos: ");
    scanf(" %d", &carta1.pontosTuristicos);

    // calculo da densidade populacional e do PIB per capita, evitando divisão por zero
    if (carta1.area > 0.0) carta1.densidade = (double)carta1.populacao / carta1.area;
    else carta1.densidade = 0.0;

    // calculo do PIB per capita, evitando divisão por zero
    if (carta1.populacao > 0) carta1.pibPerCapita = (carta1.pib * 1000000000.0) / carta1.populacao;
    else carta1.pibPerCapita = 0.0;

    printf("\n");
    // Cadastro da Carta 2
    printf("=========== Carta 2\n");

    printf("Estado (A-H): ");
    scanf(" %c", &carta2.estado);

    printf("Código da Carta (01 à 04): ");
    scanf(" %d", &numero);
    sprintf(carta2.codigo, "%c%02d", carta2.estado, numero);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta2.cidade); // lê até o '\n', aceitando espaços

    printf("População da Cidade: ");
    scanf(" %d", &carta2.populacao);

    printf("Área da Cidade (km2): ");
    scanf(" %f", &carta2.area);

    printf("PIB da cidade (em bilhões): ");
    scanf(" %f", &carta2.pib);

    printf("Pontos Turísticos: ");
    scanf(" %d", &carta2.pontosTuristicos);


    if (carta2.area > 0.0) carta2.densidade = (double)carta2.populacao / carta2.area;
    else carta2.densidade = 0.0;

    if (carta2.populacao > 0) carta2.pibPerCapita = (carta2.pib * 1000000000.0) / carta2.populacao;
    else carta2.pibPerCapita = 0.0;

    printf("\n");
    // Exibição dos Dados das Cartas, um por linha:
    printf("CARTAS CADASTRADAS ===============================================\n");

    // Exibição da Carta 1
    printf("=========== Carta 1\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Código da Carta: %s\n", carta1.codigo);
    printf("Nome da Cidade: %s\n", carta1.cidade);
    printf("População: %d\n", carta1.populacao);
    printf("Área: %.2f km2\n", carta1.area);
    printf("PIB: %.2f bilhões de reais\n", carta1.pib);
    printf("Pontos Turísticos: %d\n", carta1.pontosTuristicos);
    printf("Densidade Populacional: %.2f habitantes/km2\n", carta1.densidade);
    printf("PIB per capita: %.2f reais\n", carta1.pibPerCapita);

    printf("\n");
    // Exibição da Carta 2
    printf("=========== Carta 2\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Código da Carta: %s\n", carta2.codigo);
    printf("Cidade: %s\n", carta2.cidade);
    printf("População: %d\n", carta2.populacao);
    printf("Área: %.2f km2\n", carta2.area);
    printf("PIB: %.2f bilhões de reais\n", carta2.pib);
    printf("Pontos Turísticos: %d\n", carta2.pontosTuristicos);
    printf("Densidade Populacional: %.2f habitantes/km2\n", carta2.densidade);
    printf("PIB per capita: %.2f reais\n\n", carta2.pibPerCapita);


    printf("\nCOMPARAÇÃO DE ATRIBUTOS ===============================================\n");

            // Comparação de População
            printf("Atributo: População\n");
            printf("Carta 1 - %s: %d habitantes\n", carta1.cidade, carta1.populacao);
            printf("Carta 2 - %s: %d habitantes\n", carta2.cidade, carta2.populacao);
            printf("=========== Resultado\n");

            if (carta1.populacao > carta2.populacao) printf("Carta 1 venceu!\n"); 
    
            else if (carta2.populacao > carta1.populacao) printf("Carta 2 venceu!\n");

            else printf("Empate!\n");
    
    return 0;
}
