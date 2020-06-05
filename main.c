#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

int main(){
    srand(time(NULL));
    int pontos_qnt = 0, jogadores_qnt = 0, x=0  ,r=0, y=0, stop=0, nn=2;
    int pontos[20];
    char sim_ou_nao;
    char jogador[20][20];
    char temp[20];

    setlocale(LC_ALL, "Portuguese");// aceita acentos e caracteres especiais
    printf("\n   ======== CONTADOR DE PONTOS ========\n");
    printf("\n  Insira a pontuação final: ");
    scanf("%i", &pontos_qnt);// recebe a quantidade de pontos para ganhar o jogo
    printf("\n  Vencerá o jogo o primeiro a alcançar : %i pontos\n", pontos_qnt);
    //======= Recebe e armazena os jogadores ======
    while(1){
        printf("\n  Jogador %i: ", jogadores_qnt+1);
        scanf("%s", jogador[jogadores_qnt]);
        printf("  Adicionar outro jogador?(S/N): ");
        scanf("%s", &sim_ou_nao);
        jogadores_qnt  = jogadores_qnt+1;
        if(sim_ou_nao == 'n'){
            break;
        }
    //======= Mostra os jogadores =======
    }
    printf("\n  Jogadores:\n");
    for(x=0;x<jogadores_qnt;x++){
    printf("  %s\n",jogador[x]);
    }
    //======== Embaralha os jogadores =======
    for(x=0;x<jogadores_qnt;x++){
        r = rand()%jogadores_qnt;
        strcpy(temp, jogador[x]);
        strcpy(jogador[x],jogador[r]);
        strcpy(jogador[r],temp);
    }
    //======== Mostra a ordem de jogada =======
    printf("\n  Ordem de jogada:\n");
    for(x=0;x<jogadores_qnt;x++){
    printf("  %s\n",jogador[x]);
    }
    //======== recebe a pontuação da primeira rodada ======
    printf("\n\n  ***Rodada 1***"  );
    for(x=0;x<jogadores_qnt;x++){
        printf("\n ---- Vez de: %s ----", jogador[x]);
        printf("\n  Pontuação obtida: ");
        scanf("%i", &pontos[x]);
        printf("  Pontuação atual: %i\n", pontos[x]);
    }
    //======== soma novos pontos aos valores da primeira rodada =====
    while(stop == 0){
        printf("\n  ***Rodada %i***", nn);
        nn=nn+1;
        for(x=0;x<jogadores_qnt;x++){
            printf("\n ---- Vez de: %s ----", jogador[x]);
            printf("\n  Pontuação obtida: ");
            scanf("%i", &y);
            pontos[x]=pontos[x]+y;
            printf("  Pontuação atual: %i\n", pontos[x]);
            if(pontos[x]>=pontos_qnt){
                printf("\n  ********");
                printf("\n  ======== %s é o campeão ========", jogador[x]);
                stop = 1;
                break;
            }
        }
    }
    return 0;
}
