#include "data.h"
#include <time.h>
void my_delay(int i)    /*Pause l'application pour i seconds*/
{
    clock_t start,end;
    start=clock();
    while(((end=clock())-start)<=i*CLOCKS_PER_SEC);
}



void zone()
{
     for(int m=0;m<81;m++)
     {
         //interdit[m]=1;
     }
    for(int m=0;m<81;m++)
    {

        if(lib[m]!=0)
        {
            interdit[m]=2;
        }
        else{

            int h=0,d=0,g=0,b=0;
            b=bas(m);g=gauche(m);d=droit(m);h=haut(m);

            int who=player;
            if(player==0)
            {
                who=2;
            }else{
                who=1;
            }
            interdit[m]=0;

            if((h!=99&&data[h]==who&&lib[h]==1))
            {
                interdit[m]=1;
            }
            if((b!=99&&data[b]==who&&lib[b]==1))
            {
                interdit[m]=1;
            }
            if((g!=99&&data[g]==who&&lib[g]==1))
            {
                interdit[m]=1;
            }
            if((d!=99&&data[d]==who&&lib[d]==1))
            {
                interdit[m]=1;
            }

            //maintenant le traitement du cas ou le groupe ne doit pas etre apture


        }
        //interdit[m]=dont;
    }

}

int haut(int pos){
    if(pos>8)
    {
        return (pos-9);
    }
    return 99;
}
int bas(int pos)
{
    if(pos<72)
    {
        return (pos+9);
    }
    return 99;
}
int droit(int pos)
{
    if((pos%9)!=8)
    {
        return (pos+1);
    }
    return 99;
}
int gauche(int pos)
{
    if((pos%9)!=0)
    {
        return (pos-1);
    }
    return 99;
}
calcul(int i) // prend une intersection et retourne un tableau qui contient ses amis
{
    int h=0,d=0,g=0,b=0;
    b=bas(i);g=gauche(i);d=droit(i);h=haut(i);
    if(data[i]!=0) // reminder : I added the one here so that it gives the number for all the intersections even non filled
    {
        check[i]=1; //blackliste cant calculate twice for one intersection
        if(h!=99&&data[h]==0) // an intersection is filled with 99 if it is outside the goban
        {
            ami[h]=1;
        }
        else{
            if(h!=99&&data[h]==data[i]&&check[h]==0)
            {
                check[h]=1;
                calcul(h);
            }
        }

        if(b!=99&&data[b]==0)
        {
            ami[b]=1;
        }
        else{
            if(b!=99&&data[b]==data[i]&&check[b]==0)
            {
                check[b]=1;
                calcul(b);
            }
        }


        if(g!=99&&data[g]==0)
        {
            ami[g]=1;
        }
        else{
            if(g!=99&&data[g]==data[i]&&check[g]==0)
            {
                check[g]=1;
                calcul(g);
            }
        }
         if(d!=99&&data[d]==0)
        {
            ami[d]=1;
        }
        else{
            if(d!=99&&data[d]==data[i]&&check[d]==0)
            {
                check[d]=1;
                calcul(d);
            }
        }
    }
    else  //ici on traite le cat où on ne pose une piere que pour capturer, on poura poser une piere dans un intersection de deg=0 mais pour capturer
    {
        check[i]=1;
        if(player==0)
        {
            if((h!=99&&data[h]==0)||(data[h]==1)&&lib[h]>1)
            {
                ami[h]=1;
            }
            if((b!=99&&data[b]==0)||(data[b]==1)&&lib[b]>1)
            {
                ami[b]=1;
            }
            if((g!=99&&data[g]==0)||(data[g]==1)&&lib[g]>1)
            {
                ami[g]=1;
            }
            if((d!=99&&data[d]==0)||(data[d]==1)&&lib[d]>1)
            {
                ami[d]=1;
            }

        }
        if(player==1)
        {
            if((h!=99&&data[h]==0)||(data[h]==2)&&lib[h]>1)
            {
                ami[h]=1;
            }
            if((b!=99&&data[b]==0)||(data[b]==2)&&lib[b]>1)
            {
                ami[b]=1;
            }
            if((g!=99&&data[g]==0)||(data[g]==2)&&lib[g]>1)
            {
                ami[g]=1;
            }
            if((d!=99&&data[d]==0)||(data[d]==2)&&lib[d]>1)
            {
                ami[d]=1;
            }

        }
    }
}

void calcul_liberte()
{

            for(int i=0;i<81;i++)
            {
            check[i]=0;
            check2[i]=0;
            ami[i]=0;
            }
            for(int i=0;i<81;i++)
            {
                if(check[i]==0)
                {

                    calcul(i);
                    for(int j=0;j<81;j++)
                    {
                        if(ami[j]==1)
                        {
                            compt++;
                            ami[j]=0;
                        }
                    }
                    for(int j=0;j<81;j++)
                    {
                        if(check[j]==1&&check2[j]==0) //check2 contient hadok li 3tinahom degre d liberte dyalhom
                        {
                            lib[j]=compt;
                            check2[j]=1;
                            if(compt==0&&j!=in&&data[j]!=data[in]) // bach radi itcaptura ila ghir li dayerin bih, howa o les amis dyalo non
                            {
                                check2[j]=2;
                            }

                        }
                    }
                    compt=0;
                }
            }
            capture();
}

void capture()
{
    for(int k=0;k<81;k++)
    {
        if(check2[k]==2)
        {
            if(data[k]==2)
            {
                player1_score=player1_score+1;
                data[k]=0;
                check2[k]=1;
            }
            if(data[k]==1)
            {
                player2_score=player2_score+1;
                data[k]=0;
                check2[k]=1;
            }
        }
    }
}

int calcul_territoire(int i,int player_territory) //prend une indice et retourne une tableau terr qui contient le territoir de l'indice donnée
{
    int h=0,d=0,g=0,b=0;
    int adverse=player_territory+1; //adverse to do
    if(player_territory==1)
        adverse=2;
    if(player_territory==2)
        adverse=1;
    b=bas(i);g=gauche(i);d=droit(i);h=haut(i);
    if(data[i]==0)
    {
        terr[i]=player_territory;
        check[i]=1; //blackliste cant calculate twice for one intersection
        if(h!=99&&data[h]==0&&check[h]==0) // an intersection is filled with 99 if it is outside the goban
        {
            terr[h]=player_territory;
            calcul_territoire(h,player_territory);
        }else{
            if(h==99)
                hh=1;
            }
        if(h!=99&&data[h]==adverse)
            {
                territory_found=0;
                check[h]=1;
            }
        if(b!=99&&data[b]==0&&check[b]==0)
        {
            terr[b]=player_territory;
            calcul_territoire(b,player_territory);
        }else{
            if(b==99)
                bb=1;
            }
        if(b!=99&&data[b]==adverse)
            {
                territory_found=0;
                check[b]=1;
            }
        if(g!=99&&data[g]==0&&check[g]==0)
        {
            terr[g]=player_territory;
            calcul_territoire(g,player_territory);
        }else{
            if(g==99)
                gg=1;
            }
        if(g!=99&&data[g]==adverse)
            {
                territory_found=0;
                check[g]=1;
            }
         if(d!=99&&data[d]==0&&check[d]==0)
        {
            terr[d]=player_territory;
            calcul_territoire(d,player_territory);
        }else{
            if(d==99)
                dd=1;
            }
            if(d!=99&&data[d]==adverse)
                {
                    territory_found=0;
                    check[d]=player_territory;
                }
        }

    if((bb+hh+gg+dd)==4)
    {
        territory_found=0;
    }
    return 0;

}
void territoire()
{
        hh=0,dd=0,gg=0,bb=0,territory_found=0;
    int test=1;
    for(int m=0;m<81;m++)
    {
        check[m]=0;
        terr2[m]=0;
        terr[m]=0;
        terr3[m]=0;
    }
    territory_found=1;
    for(int m=0;m<81;m++)
    {
            territory_found=1;
            hh=0,dd=0,gg=0,bb=0;
            if(terr2[m]==0&&data[m]==0)
            test=calcul_territoire(m,1);
            if(territory_found)
            {
                for(int n=0;n<81;n++)
                {
                      if(check[n]==1)
                    {
                        terr2[n]=terr[n];
                    }
                }
            }
                for(int n=0;n<81;n++)
                {
                    terr[n]=0;
                    check[n]=0;
                }
        }


            for(int m=0;m<81;m++)
    {
            territory_found=1;
            hh=0,dd=0,gg=0,bb=0;
            if(terr3[m]==0&&data[m]==0)
            test=calcul_territoire(m,2);
            if(territory_found)
            {
                for(int n=0;n<81;n++)
                {
                      if(check[n]==1)
                    {
                        terr3[n]=terr[n];
                    }
                }
            }
                for(int n=0;n<81;n++)
                {
                    terr[n]=0;
                    check[n]=0;
                }
        }
        player1_territory=0,player2_territory=0;
        black_stones=0,white_stones=0;
        for(int n=0;n<81;n++)
        {
            if(terr2[n]==1)
                player1_territory++;
            if(terr3[n]==2)
                player2_territory++;
            if(data[n]==1)
                black_stones++;
            if(data[n]==2)
                white_stones++;
        }

}
