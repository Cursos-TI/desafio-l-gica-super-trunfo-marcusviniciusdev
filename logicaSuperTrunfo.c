#include <stdio.h>
#include <string.h>

int main() {
    // Dados da Carta 1
    char estado1[] = "SP";
    char codigo1[] = "A01";
    char nomeCidade1[] = "São Paulo";
    int populacao1 = 12300000;
    float area1 = 1521.11;
    float pib1 = 699.28;
    int pontosTuristicos1 = 50;

    // Dados da Carta 2
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
    float pibPerCapita1 = (pib1 * 1e9) / populacao1;
    float pibPerCapita2 = (pib2 * 1e9) / populacao2;

    // Escolha do atributo para comparação (definido no código)
    char atributoEscolhido[] = "População"; // Pode ser "Área", "PIB", "Densidade", etc.

    // Comparação com base no atributo escolhido
    if (strcmp(atributoEscolhido, "População") == 0) {
        printf("Comparação de cartas (Atributo: População):\n");
        printf("Carta 1 - %s (%s): %d\n", nomeCidade1, estado1, populacao1);
        printf("Carta 2 - %s (%s): %d\n", nomeCidade2, estado2, populacao2);
        if (populacao1 > populacao2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
        } else if (populacao2 > populacao1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else if (strcmp(atributoEscolhido, "Densidade") == 0) {
        printf("Comparação de cartas (Atributo: Densidade Populacional):\n");
        printf("Carta 1 - %s (%s): %.2f hab/km²\n", nomeCidade1, estado1, densidade1);
        printf("Carta 2 - %s (%s): %.2f hab/km²\n", nomeCidade2, estado2, densidade2);
        if (densidade1 < densidade2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
        } else if (densidade2 < densidade1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else {
        printf("Atributo inválido para comparação.\n");
    }

    return 0;
}