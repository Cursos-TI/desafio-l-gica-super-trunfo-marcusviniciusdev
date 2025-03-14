#include <stdio.h>
#include <string.h>

// Função para obter o valor de um atributo
float obterValor(int atributo, int carta, int populacao1, int populacao2, float area1, float area2, float pib1, float pib2, int pontosTuristicos1, int pontosTuristicos2, float densidade1, float densidade2) {
    if (carta == 1) {
        switch (atributo) {
            case 1: return (float)populacao1;
            case 2: return area1;
            case 3: return pib1;
            case 4: return (float)pontosTuristicos1;
            case 5: return densidade1;
            default: return 0;
        }
    } else {
        switch (atributo) {
            case 1: return (float)populacao2;
            case 2: return area2;
            case 3: return pib2;
            case 4: return (float)pontosTuristicos2;
            case 5: return densidade2;
            default: return 0;
        }
    }
}

int main() {
    // Dados das cartas
    char estado1[] = "SP";
    char codigo1[] = "A01";
    char nomeCidade1[] = "São Paulo";
    int populacao1 = 12300000;
    float area1 = 1521.11;
    float pib1 = 699.28;
    int pontosTuristicos1 = 50;

    char estado2[] = "RJ";
    char codigo2[] = "B02";
    char nomeCidade2[] = "Rio de Janeiro";
    int populacao2 = 6748000;
    float area2 = 1200.25;
    float pib2 = 300.50;
    int pontosTuristicos2 = 30;

    // Cálculos adicionais
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    // Menu para escolha dos atributos
    int opcao1, opcao2;
    printf("Escolha dois atributos para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");

    // Validação da primeira opção
    do {
        printf("Digite o número do primeiro atributo (1 a 5): ");
        scanf("%d", &opcao1);
        if (opcao1 < 1 || opcao1 > 5) {
            printf("Erro: Opção inválida! Escolha um número entre 1 e 5.\n");
        }
    } while (opcao1 < 1 || opcao1 > 5);

    // Validação da segunda opção
    do {
        printf("Digite o número do segundo atributo (1 a 5): ");
        scanf("%d", &opcao2);
        if (opcao2 < 1 || opcao2 > 5) {
            printf("Erro: Opção inválida! Escolha um número entre 1 e 5.\n");
        } else if (opcao2 == opcao1) {
            printf("Erro: Escolha atributos diferentes!\n");
        }
    } while (opcao2 < 1 || opcao2 > 5 || opcao2 == opcao1);

    // Comparação e soma dos atributos
    float soma1 = obterValor(opcao1, 1, populacao1, populacao2, area1, area2, pib1, pib2, pontosTuristicos1, pontosTuristicos2, densidade1, densidade2) +
                  obterValor(opcao2, 1, populacao1, populacao2, area1, area2, pib1, pib2, pontosTuristicos1, pontosTuristicos2, densidade1, densidade2);

    float soma2 = obterValor(opcao1, 2, populacao1, populacao2, area1, area2, pib1, pib2, pontosTuristicos1, pontosTuristicos2, densidade1, densidade2) +
                  obterValor(opcao2, 2, populacao1, populacao2, area1, area2, pib1, pib2, pontosTuristicos1, pontosTuristicos2, densidade1, densidade2);

    // Exibição dos resultados
    printf("\nComparação de cartas:\n");
    printf("Carta 1 - %s (%s):\n", nomeCidade1, estado1);
    printf("Atributo %d: %.2f\n", opcao1, obterValor(opcao1, 1, populacao1, populacao2, area1, area2, pib1, pib2, pontosTuristicos1, pontosTuristicos2, densidade1, densidade2));
    printf("Atributo %d: %.2f\n", opcao2, obterValor(opcao2, 1, populacao1, populacao2, area1, area2, pib1, pib2, pontosTuristicos1, pontosTuristicos2, densidade1, densidade2));
    printf("Soma: %.2f\n", soma1);

    printf("Carta 2 - %s (%s):\n", nomeCidade2, estado2);
    printf("Atributo %d: %.2f\n", opcao1, obterValor(opcao1, 2, populacao1, populacao2, area1, area2, pib1, pib2, pontosTuristicos1, pontosTuristicos2, densidade1, densidade2));
    printf("Atributo %d: %.2f\n", opcao2, obterValor(opcao2, 2, populacao1, populacao2, area1, area2, pib1, pib2, pontosTuristicos1, pontosTuristicos2, densidade1, densidade2));
    printf("Soma: %.2f\n", soma2);

    if (soma1 > soma2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
    } else if (soma2 > soma1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}