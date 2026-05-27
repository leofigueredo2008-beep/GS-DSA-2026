#include<stdio.h>
#include<stdlib.h>

int OP;
char comu;
float temp, bater; 


void menu (){
    
    printf("======================================\n");
    printf("|           MISSAO ESPACIAL          |\n");
    printf("======================================\n");

    printf("Digite a opcao desejada:\n");
    printf("1 - Inserir informacoes\n");
    printf("2 - Visualizar status\n");
    printf("3 - Executar analise\n");
    printf("4 - Encerrar sistema\n");
    scanf("%d", &OP);
}

void dados (){

    printf("--------------------------\n");
    printf("|      NOVOS DADOS       |\n");
    printf("--------------------------\n");

    printf("Qual a temperatura atual?\n");
    scanf("%f", &temp);

    if(temp > 80){
        printf("=========================\n");
        printf("ALERTA: SUPERAQUECIMENTO\n");
        printf("=========================\n");
        printf("Aguarde o resfriamento do sistema.\n");
    }else if (temp <= 10){
        printf("=========================\n");
        printf("ALERTA: CONGELAMENTO\n");
        printf("=========================\n");
    }

    printf("Qual o nivel de bateria atual? \n");
    scanf("%f", &bater);

    while (bater <= 0){
        printf("Valor de bateria invalido, por favor responda com seriedade");
        printf("Qual o nivel de bateria atual? ");
        scanf("%f", &bater);
    }
    if(bater < 20 && bater > 0){
        printf("Entrando em modo de economia de energia\n");
    }

    printf("Sua comunicacao esta ativa?\n S - Sim\n N - Nao\n");
    scanf(" %c", &comu);

    while(comu != 'S' && comu != 's' && comu != 'n' && comu != 'N' ){
        printf("Resposta invalida, por favor responda com seriedade\n");
        printf("Sua comunicacao esta ativa?\n S - Sim\n N - Nao\n");
        scanf(" %c", &comu);
    }

    if(comu == 'N' || comu == 'n'){
        printf("Falha de comunicacao, reinicie o sistema.\n");
    } 
}

void visu_dados () {

    printf("-------------------------------------\n");
    printf("|      VISUALIZACAO DOS DADOS       |\n");
    printf("-------------------------------------\n");


    printf("Sua temperatura atual e: %.2f graus celsius\n", temp);
    printf("Sua bateria atual e: %.2f %%\n", bater);
    if(comu == 's' || comu == 'S'){
        printf("Ha comunicacao disponivel no momento atual: SIM\n");
    }else {
        printf("Ha comunicacao disponivel no momento atual: NAO\n");
    }
}

void analise (){

    printf("--------------------------\n");
    printf("|         ANALISE        |\n");
    printf("--------------------------\n");

    if(temp > 80){
        printf("A temperatura do sistema esta maior que o esperado\n");
        printf("Por favor, aguarde o resfriamento do sistema\n");
        printf("Temperatura: CRITICO\n");
    }else if(temp <= 10){
        printf("A temperatura do sistema esta menor que o esperado\n");
        printf("Por favor, aguarde o aquecimento do sistema\n");
        printf("Temperatura: CRITICO\n");        
    }else{
        printf("Temperatura: OK\n");
    }

    printf("");

    if(bater<20 && bater>10){
        printf("Recomendamos que você continue no modo economia de energia\n");
        printf("Bateria: RUIM\n");
    }else if (bater<10){
        printf("Carregue o sistema IMEDIATAMENTE\n");
        printf("Bateria: CRITICO\n");
    }else{
        printf("Bateria: OK\n");
    }

    printf("");

    if(comu == 'N' || comu == 'n'){
        printf("Ha uma falha na comunicacao com a central de informacoes\n");
        printf("Por favor, reinicie o sistema manualmente para reestabeler a comunicacao com a central\n");
        printf("Comunicacao: CRITICO\n");
    }else{
        printf("Cominicacao: OK\n");
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
                break;
            default:
                printf("opcao indisponivel, tente novamente\n");
        }

    }while (OP != 4); 
    printf("Encerrando sistema!");
    printf("Tenha uma otima missao\n");
    system("pause");
    system("cls");

return 0;
}