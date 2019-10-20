#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bal = 100;
int main(void){
    int profit = bal;
    printf("Welcome to pick the correct hand game\n");
    char arr[3]={'l','r','n'};
            char input;
        while(1)
        {
            srand(time(0));
            int check_index=rand()%3;
            printf("Input l for left hand and r for right hand\n");
            scanf("%c",&input);
            int count=0;
            if(arr[check_index]==input)
            {
                printf("YOU WON!!\n");
                bal = bal + 20;
                printf("Current balance: %d \n",bal);
            }
            else
            {
                printf("You lost\n");
                bal = bal - 20;
                printf("answer was: %c\n",arr[check_index]);
                printf("Current balance: %d \n",bal);
            }
            count++;
            profit = bal - 100;
            if(bal<=0)
            {
                printf("Loss was:%d\n thank you for coming",profit);
                        break;
            }
            if(count==1)
            {
                printf("\ndo you want to continue playing? press 1 to continue and 0 to exit\n");
                int play;
                scanf("%d",&play);
                if(play==1)
                {
                    printf("I see you want to play again\n");
                    count=0;
                    scanf("%c",&input);
                    continue;
                }
                else
                    {
                        printf("Thank you for playing\n");
                        printf("You won %d\n",bal);
                        if(profit>=0)
                        printf("Profit was:%d\n",profit);
                        else
                        printf("Loss was:%d\n",abs(profit));
                        break;
                    }
            }
        }
 return 0;
}
