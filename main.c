#include<stdio.h>
#include<stdlib.h>

int OP, total;
char comu[10];
float temp[10], bater[10]; 


void menu (){
    
    printf("======================================\n");
    printf("|           MISSAO ESPACIAL          |\n");
    printf("======================================\n");

    printf("Digite a opcao desejada:\n");
    printf("1 - Inserir informacoes\n");
    printf("2 - Visualizar status\n");
    printf("3 - Executar analise\n");
    printf("4 - Historico de dados\n");
    printf("5 - Encerrar sistema\n");
    scanf("%d", &OP);
}

void dados (){

    printf("--------------------------\n");
    printf("|      NOVOS DADOS       |\n");
    printf("--------------------------\n");

    printf("Qual a temperatura atual?\n");
    scanf("%f", &temp[total]);

    if(temp[total] > 80){
        printf("=========================\n");
        printf("ALERTA: SUPERAQUECIMENTO\n");
        printf("=========================\n");
        printf("Aguarde o resfriamento do sistema.\n");
    }else if (temp[total] <= 10){
        printf("=========================\n");
        printf("ALERTA: CONGELAMENTO\n");
        printf("=========================\n");
    }

    printf("Qual o nivel de bateria atual? \n");
    scanf("%f", &bater[total]);

    while (bater[total] <= 0 || bater[total]>100){
        printf("Valor de bateria invalido, por favor responda com seriedade\n");
        printf("Qual o nivel de bateria atual?\n ");
        scanf("%f", &bater[total]);
    }
    if(bater[total] < 20 && bater[total] > 0){
        printf("Entrando em modo de economia de energia\n");
    }

    printf("Sua comunicacao esta ativa?\n S - Sim\n N - Nao\n");
    scanf(" %c", &comu[total]);

    while(comu[total] != 'S' && comu[total] != 's' && comu[total] != 'n' && comu[total] != 'N' ){
        printf("Resposta invalida, por favor responda com seriedade\n");
        printf("Sua comunicacao esta ativa?\n S - Sim\n N - Nao\n");
        scanf(" %c", &comu[total]);
    }

    if(comu[total] == 'N' || comu[total] == 'n'){
        printf("Falha de comunicacao, reinicie o sistema.\n");
    } 
    total++;
}

void visu_dados () {

    printf("-------------------------------------\n");
    printf("|      VISUALIZACAO DOS DADOS       |\n");
    printf("-------------------------------------\n");

    if (total == 0) {
        printf("Nenhuma leitura registrada ainda.\n");
    }

    printf("Sua temperatura atual e: %.2f graus celsius\n", temp[total-1]);
    printf("Sua bateria atual e: %.2f %%\n", bater[total-1]);
    if(comu[total-1] == 's' || comu[total-1] == 'S'){
        printf("Ha comunicacao disponivel no momento atual: SIM\n");
    }else {
        printf("Ha comunicacao disponivel no momento atual: NAO\n");
    }
}

void analise (){

    printf("--------------------------\n");
    printf("|         ANALISE        |\n");
    printf("--------------------------\n");

    if (total == 0) {
        printf("Nenhuma leitura registrada ainda.\n");
    }

    if(temp[total-1] > 80){
        printf("A temperatura do sistema esta maior que o esperado\n");
        printf("Por favor, aguarde o resfriamento do sistema\n");
        printf("Temperatura: CRITICO\n");
    }else if(temp[total-1] <= 10){
        printf("A temperatura do sistema esta menor que o esperado\n");
        printf("Por favor, aguarde o aquecimento do sistema\n");
        printf("Temperatura: CRITICO\n");        
    }else{
        printf("Temperatura: OK\n");
    }

    if(bater[total-1]<20 && bater[total-1]>10){
        printf("Recomendamos que você continue no modo economia de energia\n");
        printf("Bateria: RUIM\n");
    }else if (bater[total-1]<=10){
        printf("Carregue o sistema IMEDIATAMENTE\n");
        printf("Bateria: CRITICO\n");
    }else{
        printf("Bateria: OK\n");
    }

    if(comu[total-1] == 'N' || comu[total-1] == 'n'){
        printf("Ha uma falha na comunicacao com a central de informacoes\n");
        printf("Por favor, reinicie o sistema manualmente para reestabeler a comunicacao com a central\n");
        printf("Comunicacao: CRITICO\n");
    }else{
        printf("Comunicacao: OK\n");
    }
}

void historico (){
    printf("---------------------------------------------\n");
    printf("|          HISTORICO DE LEITURAS            |\n");
    printf("---------------------------------------------\n");
 
    if (total == 0) {
        printf("Nenhuma leitura registrada ainda.\n");
    }
 
    printf("%-8s %-14s %-12s %-14s\n",
           "Leitura", "Temp (C)", "Bateria (%)", "Comunicacao");
    printf("---------------------------------------------\n");
 
    for (int i = 0; i < total; i++) {
        printf("  #%-6d %-14.2f %-12.2f %s\n",
               i + 1,
               temp[i],
               bater[i],
               (comu[i] == 'S' || comu[i] == 's') ? "ATIVA" : "FALHA");
    }
}

int main (){
    do{
        menu();

        switch(OP){
            case 1:
                dados ();
                system("pause");
                system("cls");
                break;

            case 2:
                visu_dados ();
                system("pause");
                system("cls");
                break;

            case 3:
                analise ();
                system("pause");
                system("cls");
                break;
            case 4:
                historico();
                system("pause");
                system("cls");
                break;
            case 5:
                break;
            default:
                printf("opcao indisponivel, tente novamente\n");
        }

    }while (OP != 5); 
    printf("Encerrando sistema!");
    printf("Tenha uma otima missao\n");
    system("pause");
    system("cls");

return 0;
}