#include <stdio.h>
#include <string.h> // usado para remover o '\n' quando usamos fgets

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

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
    double pibPerCapita;  // pib  / população
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
    printf("CARTAS CADASTRADAS ===============================================\n\n");

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
    printf("PIB per capita: %.2f reais\n", carta2.pibPerCapita);

    // Escolha de dois atributos para comparação
    printf("ESCOLHA DOIS ATRIBUTOS PARA COMPARAÇÃO ===============================================\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB per capita\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Populacional\n");

    printf("Insira um atributo para comparação: ");
    scanf(" %d", &comparacao); // lê a escolha do primeiro atributo

    if (comparacao < 1 || comparacao > 5) { // validação se o número inserio é válido
        printf("Número inválido! Digite um valor entre 1 e 5: ");
        scanf("%d", &comparacao);
    }
     if (comparacao < 1 || comparacao > 5) {
            atributos = 0; // se o usuário errou duas vezes, atributo é dado como inválido
        }

    printf("COMPARAÇÃO DE ATRIBUTOS ===============================================\n");

    if (atributos) {

        // se os atributos forem válidos
        if (comparacao == 1) { // População
            printf("Atributo: População\n");
            printf("Carta 1 - %s: %d\n", carta1.cidade, carta1.populacao);
            printf("Carta 2 - %s: %d\n", carta2.cidade, carta2.populacao);
            printf("=========== Resultado\n");
                //  laço de comparação
                if (carta1.populacao > carta2.populacao) printf("Carta 1 venceu!\n"); 
                else if (carta2.populacao > carta1.populacao) printf("Carta 2 venceu!\n");
                else printf("Empate!\n");
        }

        else if (comparacao == 2) { // Área
            printf("Atributo: Área\n");
            printf("Carta 1 - %s: %.2f km²\n", carta1.cidade, carta1.area);
            printf("Carta 2 - %s: %.2f km²\n", carta2.cidade, carta2.area);
            printf("=========== Resultado\n");
                if (carta1.area > carta2.area) printf("Carta 1 venceu!\n");
                else if (carta2.area > carta1.area) printf("Carta 2 venceu!\n");
                else printf("Empate!\n");
        }
        
        else if (comparacao == 3) { // PIB per capita
            printf("Atributo: PIB per capita\n");
            printf("Carta 1 - %s: %.2f\n", carta1.cidade, carta1.pibPerCapita);
            printf("Carta 2 - %s: %.2f\n", carta2.cidade, carta2.pibPerCapita);
            printf("=========== Resultado\n");
                if (carta1.pibPerCapita > carta2.pibPerCapita) printf("Carta 1 venceu!\n");
                else if (carta2.pibPerCapita > carta1.pibPerCapita) printf("Carta 2 venceu!\n");
                else printf("Empate!\n");
        }

        else if (comparacao == 4) { // Pontos Turísticos
            printf("Atributo: Pontos Turísticos\n");
            printf("Carta 1 - %s: %d pontos\n", carta1.cidade, carta1.pontosTuristicos);
            printf("Carta 2 - %s: %d pontos\n", carta2.cidade, carta2.pontosTuristicos);
            printf("=========== Resultado\n");
                if (carta1.pontosTuristicos > carta2.pontosTuristicos) printf("Carta 1 venceu!\n");
                else if (carta2.pontosTuristicos > carta1.pontosTuristicos) printf("Carta 2 venceu!\n");
                else printf("Empate!\n");
        }

        else if (comparacao == 5) { // Densidade Populacional
            printf("Atributo: Densidade Populacional\n");
            printf("Carta 1 - %s: %.2f hab/km²\n", carta1.cidade, carta1.densidade);
            printf("Carta 2 - %s: %.2f hab/km²\n", carta2.cidade, carta2.densidade);
            printf("=========== Resultado\n");
                if (carta1.densidade < carta2.densidade) printf("Carta 1 venceu!\n"); // menor vence
                else if (carta2.densidade < carta1.densidade) printf("Carta 2 venceu!\n");
                else printf("Empate!\n");
        }

    } else { // se o atributo for inválido
        printf("Atributo: Inválido\n");
        printf("=========== Resultado\n");
        printf("Foi escolhida uma opção Inválida. É impossível realizar a comparação.\n");
    }

    return 0;
}
