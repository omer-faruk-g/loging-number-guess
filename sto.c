#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct{
    char name[30];
    int score;
}playerdata;
enum Level{
    LOW=1,
    MEDIUM,
    HIGH
};
void menu(){
    printf("-----------------------------\n");
    printf("------Sayi Tahmin Oyunu------\n");
    printf("1)1-100\n2)1-1000\n3)1-100000\n4)Cikis\n\n");
}
int levels(int ptr){

    if(ptr == LOW){
      return (rand()%100)+1;
    }else if(ptr == MEDIUM){
      return (rand()%1000)+1;
    }else if(ptr == HIGH){
      return (rand()%100000)+1;
    }else{
        printf("Wrong enter!\n");
        return 0;
    }
}
int file(playerdata p[], int count, int highscore){
    FILE* fptr;
    fptr = fopen("C:\\Users\\HP\\Desktop\\database\\stolog.txt", "a");
    if(fptr == NULL){
        printf("WRONG\n");
        return -1;
    }
    for(int i=1; i<=count;i++){
        fprintf(fptr,"Player name:%s\t Score:%d\n",p[i].name, p[i].score);
    }
    fprintf(fptr,"------------------------\n");
    fprintf(fptr,"High Score:%d\n\n", highscore);
    fclose(fptr);
    return 0;
}
int main(){
    srand(time(NULL));
    int answer,playernumber,highscore=0;
    menu();
    printf("Seciminiz: ");
    scanf("%d",&answer);
    if(answer ==4){

        return 0;
    }
    printf("Kac kisi?\n");
    scanf("%d",&playernumber);
    playerdata player[playernumber+2];
    int trys[playernumber+2];
    for(int i=1;i<=playernumber;i++){
        printf("%d. kisinin adi: \n",i);
        scanf("%s", player[i].name);
        player[i].score = 0;
    }
    int found = 0;
    while(1){
        int x= levels(answer);
        while(!found){
            for(int i=1;i<=playernumber;i++){
                printf("%s'in tahmini: \n",player[i].name);
                scanf("%d",&trys[i]);
                if(trys[i] > x){
                    printf("Cok buyuk!\n");
                }else if(trys[i] < x){
                    printf("Cok gucuk!\n");
                }else{
                    printf("Dogru\n");
                    player[i].score+=10;
                    found = 1;
                    break;
                }
            }
        }
            found = 0;
            menu();
            printf("Seciminiz: ");
            scanf("%d",&answer);
            if(answer ==4){
                for(int i=1;i<=playernumber;i++){
                    if(player[i].score > highscore){
                        highscore = player[i].score;
                    }
                }
                file(player,playernumber,highscore);
                return 0;
            }
    }
    return 0;
}
