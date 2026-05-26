#include<stdio.h>

int OP, comu;
float temp, bater; 


int menu (){
    
    printf("======================================\n");
    printf("|           MISSAO ESPACIAL          |\n");
    printf("======================================\n");

    printf("Digite a opcao desejada:\n");
    printf("1 - inserir informacoes\n");
    printf("2 - visualizar status\n");
    printf("3 - executar analise\n");
    printf("4 - encerrar sistema\n");
    scanf("%d", &OP);
}

int dados (){
    printf("Qual a temperatura atual?\n");
    scanf("%f", &temp);

    if(temp > 80){
        printf("=========================\n");
        printf("ALERTA: SUPERAQUECIMENTO\n");
        printf("=========================\n");
        printf("Aguarde o resfriamento do sistema.\n");
    }

    printf("Qual o nivel de bateria atual? ");
    scanf("%f", &bater);

    if(bater < 20){
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


int main (){
    do{
        menu();

        switch(OP){
            case 1:
                dados ();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                printf("opcao indisponivel, tente novamente\n");
        }

    }while (OP != 4); 
    printf("Encerrando sistema!");
    printf("Tenha uma otima missao");

return 0;
}