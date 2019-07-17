#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include <conio.h>
#include <windows.h>



int main()
{
    int i=0;
    for(i=0;i<81;i++)
    {
        data[i]=0;
        lib[i]=0;
        check[i]=0;
        interdit[i]=1;
        old3[0]=1;
        old[0]=1; //pour ne pas avoir Ko dees le premier coup
    }
    while(choice!=3)
    {
            system("@cls||clear");
            start();
            color(11,0);
            printf("\n\n\t\t\t\t\t\t\t\t     Enter your choice here please ! >>>  ");
            color(8,0);
            scanf("%d",&choice);
            switch(choice)
            {
                case 1 :
                    {
                                system("@cls||clear");
                                plays();
                                color(11,0);
                                printf("\n\n\t\t\t\t\t\t\t\t     Enter your choice here please ! >>>  ");
                                color(8,0);
                                scanf("%d",&choice2);
                                switch(choice2)
                                {
                                    case 1: {
                                            system("@cls||clear");
                                            joueur_joueur();
                                            break;
                                    }
                                    case 2: {
                                            system("@cls||clear");

                                            srand(time(NULL));
                                            who_plays_first=rand()%2;
                                            for(int u=0;u<15;u++)
                                            {
                                                Sleep(200);
                                                system("@cls||clear");
                                                if(u%2==0)
                                                {
                                                    randome_player_first();
                                                    printf("\n\n\n");
                                                }

                                                if(u%2==1)
                                                {
                                                    randome_player_first2();
                                                    printf("\n\n\n");
                                                }
                                            }
                                            if(who_plays_first==0)
                                            {
                                                system("@cls||clear");
                                                randome_player_first2();
                                                printf("\n\n\n\t\t\t\t\t\t\t\t          YOU GOT WHITE, YOU'LL PLAY SECOND  \n");
                                                printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t               PRESS ENTER TO CONTINUE  \n");
                                                getch();
                                                system("@cls||clear");
                                            }
                                            if(who_plays_first==1)
                                            {
                                                system("@cls||clear");
                                                randome_player_first();
                                                printf("\n\n\n\t\t\t\t\t\t\t\t          YOU GOT BLACK, YOU'LL PLAY FIRST  \n");
                                                printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t               PRESS ENTER TO CONTINUE  \n");
                                                getch();
                                                system("@cls||clear");
                                            }
                                            srand(time(NULL));
                                            joueur_vs_machine();
                                            break;
                                    }

                                }

                            break;
                    }
            }
    }
}

