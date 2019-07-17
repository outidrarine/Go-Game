#include "data.h"

void joueur_joueur()
{
    int pass=0;
    old2[0]=9;  //to prevent ko from first play we initialise old
    old3[0]=9;
    old[0]=9;
    player1_score=0,player2_score=6.5;
    player1_territory=0,player2_territory=0,black_stones=0,white_stones=0;
    in=0;
    int ko=1;
        while(1)
        {

            int test=1; //test est utilise pour ne pas declarer une intersection remplie des le premier coup

            //ici on va sortir du do lorsque la valeur saisie est conforme
            do{
            showme();
            if(in==99)
            {
                    system("@cls||clear");
                    showme();
                    color(4,0);
                    printf("\n\n\t\t\t\t  Are you sure you want to exit [ 99 = YES ]  [ anything else = NO ] >>>  ");
                    int ex=2; // local variable to confirm the exit demande
                    scanf("%d",&ex);
                    if(ex==99)
                    {
                    int i=0;
                    player=0;
                    for(i=0;i<81;i++)
                            {
                                    data[i]=0;
                                    lib[i]=0;
                                    interdit[i]=1;
                                    terr2[i]=0;
                                    terr3[i]=0;
                            }
                                in=0;
                                return 0;
                        }
                        else{
                            system("@cls||clear");
                            showme();
                            }
            }
            if((in<=80&&in>=0)&&(data[in]!=0)&&(test==0))
            {
                    system("@cls||clear");
                    showme();
                    color(4,0);
                    printf("\n\n\t\t\t\t\t\t  warning ! intersection already filled >>>  ");
            }
            else {
                    if((in!=88)&&(in<0||in>80)&&(in!=99))
                        {
                            system("@cls||clear");
                            showme();
                            color(4,0);
                            printf("\n\n\t\t\t\t\t\t  numbers must be between 0 and 80 please ! >>> ");
                        }else{
                                    if(player==0)
                                    color(11,0);
                                    if(player==1)
                                    color(14,0);
                                    printf("\n\n\t\t\t\t\t\t  give a number between 0 and 80  >>> ");
                                    if((in<=80&&in>=0)&&interdit[in]==0)
                                    {
                                        system("@cls||clear");
                                        showme();
                                        color(4,0);
                                        printf("\n\n\t\t\t\t\t\t  WARNING YOU CANT PUT A STONE HERE ! >>>  ");
                                    }
                                    if(ko==0)  // ko=0 means that we have ko situation
                                    {
                                        player++;        //in case of ko we'll need to switch player twice
                                        player=player%2;

                                        system("@cls||clear");
                                        showme();
                                        color(4,0);
                                        printf("\n\n\t\t\t\t\t\t\t\t  WARNING KO ! >>>  ");
                                    }
                                    if(pass==2)
                                    {
                                            int i=0;
                                            for(i=0;i<81;i++)
                                            {
                                                data[i]=0;
                                                lib[i]=0;
                                                interdit[i]=1;
                                                terr2[i]=0;
                                                terr3[i]=0;
                                            }
                                            in=0;
                                            player=0;
                                       if(player1_score+player1_territory+black_stones>player2_score+player2_territory+white_stones)
                                       {
                                           system("@cls||clear");
                                            winner2();
                                            getch();
                                            return 1;
                                       }
                                       else{
                                            system("@cls||clear");
                                            winner1();
                                            getch();
                                            return 1;

                                       }

                                    }
                        }
             }color(8,0);
                scanf("%d",&in);
                                if(in==88)
                                    pass++;
                test=0;
                system("@cls||clear");
        }while(in!=88&&((in<0||in>80)||(data[in]!=0)||(interdit[in]==0)));


        //si on est ici c'est a dire qu'on a une valeur conforme dans la variable in

        if(in!=88&&data[in]==0)
        {
            pass=0;
            if(player==0)
            {
                data[in]=1;
            }
            if(player==1)
            {
                data[in]=2;
            }
        }
            player++;
            player=player%2;


            calcul_liberte();
            capture();
            calcul_liberte();
            zone();
            territoire();


            //here i have the instructions to prevent the ko situation


                if(ko!=0&&in!=88)  //we only advance when we dont have ko
                {
                    for(int v=0;v<81;v++)
                    {
                        old3[v]=old2[v];
                        old2[v]=old[v];
                        old[v]=data[v];
                    }
                }

            ko=0;
            for(int v=0;v<81;v++)
            {
                if(old3[v]!=data[v])
                   {
                       ko=1;
                   }
            }
            if(ko==0)
            {
                if(player==1)
                    player1_score=player1_score-1;
                if(player==0)
                    player2_score=player2_score-1;
            for(int v=0;v<81;v++)
                {
                    data[v]=old2[v];
                    old[v]=old2[v];
                }
            }

            //after analyses of ko situation from here to next we have correct values in data

}
}
