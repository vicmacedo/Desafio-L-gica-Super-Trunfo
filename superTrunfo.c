#include <stdio.h>
#include <string.h> // usado para remover o '\n' quando usamos fgets

// Desafio Super Trunfo - Países
// Tema 2 - Desenvolvimento Lógica do Jogo

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
    int numero, comparacao1, comparacao2;  // variáveis para armazenar o número da carta e as escolhas de comparação
    double valorAttrCarta1_1 = 0.0, valorAttrCarta1_2 = 0.0; // variáveis que armazenam os atributos das cartas 1 e 2
    double valorAttrCarta2_1 = 0.0, valorAttrCarta2_2 = 0.0;
    double soma1 = 0.0, soma2 = 0.0; // variáveis para armazenar os valores dos atributos escolhidos para comparação e soma
    int atributo1_valido = 1, atributo2_valido = 1; // variáveis para verificar se os atributos escolhidos são válidos

    printf("JOGO SUPER TRUNFO\n\n");

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

    // Escolha de dois atributos para comparação
    printf("ESCOLHA DOIS ATRIBUTOS PARA COMPARAÇÃO ===============================================\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB per capita\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Populacional\n\n");

    printf("Primeiro atributo para comparação: ");
    scanf(" %d", &comparacao1); // lê a escolha do primeiro atributo
    if (comparacao1 < 1 || comparacao1 > 5) { // validação simples (uma chance)
        printf("Número inválido! Digite um valor entre 1 e 5: ");
        scanf("%d", &comparacao1);
        printf("\n");
    }

    printf("Segundo atributo para comparação: ");
    scanf(" %d", &comparacao2); // lê a escolha do segundo atributo
    if (comparacao2 < 1 || comparacao2 > 5) {
        printf("Número inválido! Digite um valor entre 1 e 5:");
        scanf("%d", &comparacao2);
        printf("\n");
    }

    // se o usuário escolheu o mesmo atributo duas vezes (e ambos válidos), considera o segundo inválido
    if (comparacao1 == comparacao2 && (comparacao1 >= 1 && comparacao1 <= 5)) {
        printf("Os atributos escolhidos são iguais! Atributo 2 será considerado inválido.\n");
        atributo2_valido = 0; // não é possível utilizar loop com if, então para melhor apresentação do resultado os atributos inválidos = 0
        printf("\n");
    }

    // atualiza flags de validade (caso o usuário tenha digitado errado duas vezes)
    if (comparacao1 < 1 || comparacao1 > 5) atributo1_valido = 0;
    if (comparacao2 < 1 || comparacao2 > 5) atributo2_valido = 0;

    printf("COMPARAÇÃO DE ATRIBUTOS ===============================================\n");

    // Comparação do primeiro atributo (atributo 1)
    if (atributo1_valido) {
        if (comparacao1 == 1) { // População
            valorAttrCarta1_1 = carta1.populacao;
            valorAttrCarta2_1 = carta2.populacao;
            printf("Atributo 1: População\n");
            printf("Carta 1 - %s: %d\n", carta1.cidade, carta1.populacao);
            printf("Carta 2 - %s: %d\n", carta2.cidade, carta2.populacao);
            printf("=========== Resultado\n");
            if (carta1.populacao > carta2.populacao) printf("Carta 1 venceu!\n");
            else if (carta2.populacao > carta1.populacao) printf("Carta 2 venceu!\n");
            else printf("Empate!\n");
        }
        else if (comparacao1 == 2) { // Área
            valorAttrCarta1_1 = carta1.area;
            valorAttrCarta2_1 = carta2.area;
            printf("Atributo 1: Área\n");
            printf("Carta 1 - %s: %.2f km²\n", carta1.cidade, carta1.area);
            printf("Carta 2 - %s: %.2f km²\n", carta2.cidade, carta2.area);
            printf("=========== Resultado\n");
            if (carta1.area > carta2.area) printf("Carta 1 venceu!\n");
            else if (carta2.area > carta1.area) printf("Carta 2 venceu!\n");
            else printf("Empate!\n");
        }
        else if (comparacao1 == 3) { // PIB per capita
            valorAttrCarta1_1 = carta1.pibPerCapita;
            valorAttrCarta2_1 = carta2.pibPerCapita;
            printf("Atributo 1: PIB per capita\n");
            printf("Carta 1 - %s: %.2f\n", carta1.cidade, carta1.pibPerCapita);
            printf("Carta 2 - %s: %.2f\n", carta2.cidade, carta2.pibPerCapita);
            printf("=========== Resultado\n");
            if (carta1.pibPerCapita > carta2.pibPerCapita) printf("Carta 1 venceu!\n");
            else if (carta2.pibPerCapita > carta1.pibPerCapita) printf("Carta 2 venceu!\n");
            else printf("Empate!\n");
        }
        else if (comparacao1 == 4) { // Pontos Turísticos
            valorAttrCarta1_1 = carta1.pontosTuristicos;
            valorAttrCarta2_1 = carta2.pontosTuristicos;
            printf("Atributo 1: Pontos Turísticos\n");
            printf("Carta 1 - %s: %d pontos\n", carta1.cidade, carta1.pontosTuristicos);
            printf("Carta 2 - %s: %d pontos\n", carta2.cidade, carta2.pontosTuristicos);
            printf("=========== Resultado\n");
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) printf("Carta 1 venceu!\n");
            else if (carta2.pontosTuristicos > carta1.pontosTuristicos) printf("Carta 2 venceu!\n");
            else printf("Empate!\n");
        }
        else if (comparacao1 == 5) { // Densidade Populacional
            valorAttrCarta1_1 = carta1.densidade;
            valorAttrCarta2_1 = carta2.densidade;
            printf("Atributo 1: Densidade Populacional\n");
            printf("Carta 1 - %s: %.2f hab/km²\n", carta1.cidade, carta1.densidade);
            printf("Carta 2 - %s: %.2f hab/km²\n", carta2.cidade, carta2.densidade);
            printf("=========== Resultado\n");
            if (carta1.densidade < carta2.densidade) printf("Carta 1 venceu!\n"); // menor vence
            else if (carta2.densidade < carta1.densidade) printf("Carta 2 venceu!\n");
            else printf("Empate!\n");
        }
    } else {
        printf("Atributo 1: Inválido\n");
        printf("=========== Resultado\n");
        printf("Foi escolhida uma opção Inválida. É impossível realizar a comparação.\n");
    }

    printf("\n");
    // Comparação do segundo atributo (atributo 2)
    if (atributo2_valido) { 
        if (comparacao2 == 1) { // População
            valorAttrCarta1_2 = carta1.populacao;
            valorAttrCarta2_2 = carta2.populacao;
            printf("Atributo 2: População\n");
            printf("Carta 1 - %s: %d\n", carta1.cidade, carta1.populacao);
            printf("Carta 2 - %s: %d\n", carta2.cidade, carta2.populacao);
            printf("=========== Resultado\n");
            if (carta1.populacao > carta2.populacao) printf("Carta 1 venceu!\n");
            else if (carta2.populacao > carta1.populacao) printf("Carta 2 venceu!\n");
            else printf("Empate!\n");
        }
        else if (comparacao2 == 2) { // Área
            valorAttrCarta1_2 = carta1.area;
            valorAttrCarta2_2 = carta2.area;
            printf("Atributo 2: Área\n");
            printf("Carta 1 - %s: %.2f km²\n", carta1.cidade, carta1.area);
            printf("Carta 2 - %s: %.2f km²\n", carta2.cidade, carta2.area);
            printf("=========== Resultado\n");
            if (carta1.area > carta2.area) printf("Carta 1 venceu!\n");
            else if (carta2.area > carta1.area) printf("Carta 2 venceu!\n");
            else printf("Empate!\n");
        }
        else if (comparacao2 == 3) { // PIB per capita
            valorAttrCarta1_2 = carta1.pibPerCapita;
            valorAttrCarta2_2 = carta2.pibPerCapita;
            printf("Atributo 2: PIB per capita\n");
            printf("Carta 1 - %s: %.2f\n", carta1.cidade, carta1.pibPerCapita);
            printf("Carta 2 - %s: %.2f\n", carta2.cidade, carta2.pibPerCapita);
            printf("=========== Resultado\n");
            if (carta1.pibPerCapita > carta2.pibPerCapita) printf("Carta 1 venceu!\n");
            else if (carta2.pibPerCapita > carta1.pibPerCapita) printf("Carta 2 venceu!\n");
            else printf("Empate!\n");
        }
        else if (comparacao2 == 4) { // Pontos Turísticos
            valorAttrCarta1_2 = carta1.pontosTuristicos;
            valorAttrCarta2_2 = carta2.pontosTuristicos;
            printf("Atributo 2: Pontos Turísticos\n");
            printf("Carta 1 - %s: %d pontos\n", carta1.cidade, carta1.pontosTuristicos);
            printf("Carta 2 - %s: %d pontos\n", carta2.cidade, carta2.pontosTuristicos);
            printf("=========== Resultado\n");
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) printf("Carta 1 venceu!\n");
            else if (carta2.pontosTuristicos > carta1.pontosTuristicos) printf("Carta 2 venceu!\n");
            else printf("Empate!\n");
        }
        else if (comparacao2 == 5) { // Densidade Populacional
            valorAttrCarta1_2 = carta1.densidade;
            valorAttrCarta2_2 = carta2.densidade;
            printf("Atributo 2: Densidade Populacional\n");
            printf("Carta 1 - %s: %.2f hab/km²\n", carta1.cidade, carta1.densidade);
            printf("Carta 2 - %s: %.2f hab/km²\n", carta2.cidade, carta2.densidade);
            printf("=========== Resultado\n");
            if (carta1.densidade < carta2.densidade) printf("Carta 1 venceu!\n"); // menor vence
            else if (carta2.densidade < carta1.densidade) printf("Carta 2 venceu!\n");
            else printf("Empate!\n");
        }
    } else {
        printf("Atributo 2: Inválido\n");
        printf("=========== Resultado\n");
        printf("Foi escolhida uma opção Inválida. É impossível realizar a comparação.\n");
    }

    printf("\n");
    // soma dos atributos de cada carta
    printf("SOMA DOS ATRIBUTOS ===============================================\n");

    if (atributo1_valido) { // se o atributo 1 é válido, soma seus valores
        soma1 += valorAttrCarta1_1;
        soma2 += valorAttrCarta2_1;
    }
    if (atributo2_valido) { // se o atributo 2 é válido, soma seus valores
        soma1 += valorAttrCarta1_2;
        soma2 += valorAttrCarta2_2;
    }

    // exibe as somas
    printf("Carta 1 - %s: %.2f\n", carta1.cidade, soma1);
    printf("Carta 2 - %s: %.2f\n", carta2.cidade, soma2);

    printf("=========== Resultado\n");
    // decide o vencedor
    if (soma1 == 0.0 && soma2 == 0.0) {
        printf("Empate! Ambos os atributos são inválidos.\n");
    } else if (soma1 > soma2) {
        printf("Carta 1 venceu!\n");
    } else if (soma2 > soma1) {
        printf("Carta 2 venceu!\n");
    } else {
        printf("Empate!\n");
    }

    return 0;
}
