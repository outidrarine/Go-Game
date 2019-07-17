#include "data.h"
#include <windows.h>
int data[81],lib[81],check[81],ami[81],check2[81],interdit[81],old[81],old2[81],old3[81],terr[81],terr2[81],terr3[81];
float player1_score=0,player2_score=6.5;
int player1_territory=0,player2_territory=0,black_stones=0,white_stones=0;
int in=0,player=0;
int territory_found=0;
  int hh=0,dd=0,gg=0,bb=0;//detelet it after tesing
int compt=0;
int choice=0,choice2=0;
int who_plays_first=0,machine_must_pass=0;




void color(int t,int f)
{
HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(H,f*16+t);
}

void drop(int p,int i,int player)
{

 if(p!=0)
 {
     if(p==1)
     {
        color(11,11);
        printf("aa");
        color(8,0);
        printf("");
     }
     if(p==2)
     {
        color(14,14);
        printf("aa");
        color(8,0);
        printf("");
     }
 }
 else{
        if(terr2[i]==1)
            color(11,0);
        if(terr3[i]==2)
            color(14,0);
        if(terr3[i]==0&&terr2[i]==0)
            color(7,0);

        if(i<=9){
           // color(11,0);
            printf(" %d",i);
            color(8,0);
            }
        else
        {
          //  color(11,0);
            printf("%d",i);
            color(8,0);
        }
 color(7,0);
 }
}

void showme()
{
color(11,0);
printf("\n\n");
printf("                                              _/_/_/    _/_/         _/_/_/    _/_/    _/      _/  _/_/_/_/   \n");
printf("                                           _/        _/    _/     _/        _/    _/  _/_/  _/_/  _/          \n");
printf("                                          _/  _/_/  _/    _/     _/  _/_/  _/_/_/_/  _/  _/  _/  _/_/_/       \n");
printf("                                         _/    _/  _/    _/     _/    _/  _/    _/  _/      _/  _/            \n");
printf("                                          _/_/_/    _/_/         _/_/_/  _/    _/  _/      _/  _/_/_/_/       \n");
color(8,0);


   printf("\n\n\n");
    printf("\t\t\t\t  "); drop(data[0],0,player); printf("----- "); drop(data[1],1,player); printf(" ----- "); drop(data[2],2,player); printf(" ----- "); drop(data[3],3,player); printf(" ----- "); drop(data[4],4,player); printf(" ----- "); drop(data[5],5,player); printf(" ----- "); drop(data[6],6,player); printf(" ----- "); drop(data[7],7,player); printf(" ----- "); drop(data[8],8,player);printf("\t\t----------------------------------------");printf("\n");
    printf("\t\t\t\t  |        |        |        |        |        |        |        |        |");printf("\t\t|       Enter 99 to exit please !      |");printf("\n");
    printf("\t\t\t\t  |        |        |        |        |        |        |        |        |");printf("\t\t----------------------------------------");printf("\n");
    printf("\t\t\t\t  "); drop(data[9],9,player); printf("----- "); drop(data[10],10,player); printf(" ----- "); drop(data[11],11,player); printf(" ----- "); drop(data[12],12,player); printf(" ----- "); drop(data[13],13,player); printf(" ----- "); drop(data[14],14,player); printf(" ----- "); drop(data[15],15,player); printf(" ----- "); drop(data[16],16,player); printf(" ----- "); drop(data[17],17,player);printf("\t\t|       Enter 88 to pass please !      |");printf("\n");
    printf("\t\t\t\t  |        |        |        |        |        |        |        |        |");printf("\t\t----------------------------------------");printf("\n");
    printf("\t\t\t\t  |        |        |        |        |        |        |        |        |");printf("\n");
    printf("\t\t\t\t  "); drop(data[18],18,player); printf("----- "); drop(data[19],19,player); printf(" ----- "); drop(data[20],20,player); printf(" ----- "); drop(data[21],21,player); printf(" ----- "); drop(data[22],22,player); printf(" ----- "); drop(data[23],23,player); printf(" ----- "); drop(data[24],24,player); printf(" ----- "); drop(data[25],25,player); printf(" ----- "); drop(data[26],26,player); printf("\t\t----------------------------------------");printf("\n");
    printf("\t\t\t\t  |        |        |        |        |        |        |        |        |");printf("\t\t|      ");color(11,11);printf("aa");color(8,0);printf("");printf("       B L A C K   %.1f      |",player1_score+player1_territory+black_stones);printf("\n");
    printf("\t\t\t\t  |        |        |        |        |        |        |        |        |");printf("\t\t----------------------------------------");printf("\n");
    printf("\t\t\t\t  "); drop(data[27],27,player); printf("----- "); drop(data[28],28,player); printf(" ----- "); drop(data[29],29,player); printf(" ----- "); drop(data[30],30,player); printf(" ----- "); drop(data[31],31,player); printf(" ----- "); drop(data[32],32,player); printf(" ----- "); drop(data[33],33,player); printf(" ----- "); drop(data[34],34,player); printf(" ----- "); drop(data[35],35,player);  if (player ==0){printf("\t\t|               ");printf("your turn");printf("              |");}else{printf("\t\t|                                      |");};printf("\n");
    printf("\t\t\t\t  |        |        |        |        |        |        |        |        |");printf("\t\t|                                      |");printf("\n");
    printf("\t\t\t\t  |        |        |        |        |        |        |        |        |");printf("\t\t|         capture : %.1f                |",player1_score);printf("\n");
    printf("\t\t\t\t  "); drop(data[36],36,player); printf("----- "); drop(data[37],37,player); printf(" ----- "); drop(data[38],38,player); printf(" ----- "); drop(data[39],39,player); printf(" ----- "); drop(data[40],40,player); printf(" ----- "); drop(data[41],41,player); printf(" ----- "); drop(data[42],42,player); printf(" ----- "); drop(data[43],43,player); printf(" ----- "); drop(data[44],44,player); printf("\t\t|         territory : %d                |",player1_territory);printf("\n");
    printf("\t\t\t\t  |        |        |        |        |        |        |        |        |");printf("\t\t|         stones :   %d                 |",black_stones);printf("\n");
    printf("\t\t\t\t  |        |        |        |        |        |        |        |        |");printf("\t\t|                                      |");printf("\n");
    printf("\t\t\t\t  "); drop(data[45],45,player); printf("----- "); drop(data[46],46,player); printf(" ----- "); drop(data[47],47,player); printf(" ----- "); drop(data[48],48,player); printf(" ----- "); drop(data[49],49,player); printf(" ----- "); drop(data[50],50,player); printf(" ----- "); drop(data[51],51,player); printf(" ----- "); drop(data[52],52,player); printf(" ----- "); drop(data[53],53,player); printf("\t\t----------------------------------------");printf("\n");
    printf("\t\t\t\t  |        |        |        |        |        |        |        |        |");printf("\t\t|      ");color(14,14);printf("aa");color(8,0);printf("");printf("       W H I T E   %.1f       |",player2_score+player2_territory+white_stones);printf("\n");
    printf("\t\t\t\t  |        |        |        |        |        |        |        |        |");printf("\t\t----------------------------------------");printf("\n");
    printf("\t\t\t\t  "); drop(data[54],54,player); printf("----- "); drop(data[55],55,player); printf(" ----- "); drop(data[56],56,player); printf(" ----- "); drop(data[57],57,player); printf(" ----- "); drop(data[58],58,player); printf(" ----- "); drop(data[59],59,player); printf(" ----- "); drop(data[60],60,player); printf(" ----- "); drop(data[61],61,player); printf(" ----- "); drop(data[62],62,player);  if (player ==1){printf("\t\t|               ");printf("your turn");printf("              |");}else{printf("\t\t|                                      |");};printf("\n");
    printf("\t\t\t\t  |        |        |        |        |        |        |        |        |");printf("\t\t|                                      |");printf("\n");
    printf("\t\t\t\t  |        |        |        |        |        |        |        |        |");printf("\t\t|         capture : %.1f                |",player2_score);printf("\n");
    printf("\t\t\t\t  "); drop(data[63],63,player); printf("----- "); drop(data[64],64,player); printf(" ----- "); drop(data[65],65,player); printf(" ----- "); drop(data[66],66,player); printf(" ----- "); drop(data[67],67,player); printf(" ----- "); drop(data[68],68,player); printf(" ----- "); drop(data[69],69,player); printf(" ----- "); drop(data[70],70,player); printf(" ----- "); drop(data[71],71,player); printf("\t\t|         territory : %d                |",player2_territory);printf("\n");
    printf("\t\t\t\t  |        |        |        |        |        |        |        |        |");printf("\t\t|         stones :  %d                  |",white_stones);printf("\n");
    printf("\t\t\t\t  |        |        |        |        |        |        |        |        |");printf("\t\t|                                      |");printf("\n");
    printf("\t\t\t\t  "); drop(data[72],72,player); printf("----- "); drop(data[73],73,player); printf(" ----- "); drop(data[74],74,player); printf(" ----- "); drop(data[75],75,player); printf(" ----- "); drop(data[76],76,player); printf(" ----- "); drop(data[77],77,player); printf(" ----- "); drop(data[78],78,player); printf(" ----- "); drop(data[79],79,player); printf(" ----- "); drop(data[80],80,player); printf("\t\t----------------------------------------");printf("\n");

/*
    printf("\n ");
        for(int i=0;i<81;i++)
        {if(i%9==0)
                printf("\n");
            printf("%d",terr2[i]);

        }
       printf("\n ");

        for(int i=0;i<81;i++)
        {if(i%9==0)
                printf("\n");
            printf("%d",terr3[i]);

        }

        for(int i=0;i<81;i++)
        {if(i%9==0)
                printf("\n");
            printf("%d",old[i]);

        }*/



}


void start()
{
color(11,0);
printf("\n\n");
printf("  \t                                                  _/_/_/    _/_/         _/_/_/    _/_/    _/      _/  _/_/_/_/   \n");
printf("  \t                                               _/        _/    _/     _/        _/    _/  _/_/  _/_/  _/          \n");
printf(" \t                                               _/  _/_/  _/    _/     _/  _/_/  _/_/_/_/  _/  _/  _/  _/_/_/       \n");
printf(" \t                                              _/    _/  _/    _/     _/    _/  _/    _/  _/      _/  _/            \n");
printf(" \t                                               _/_/_/    _/_/         _/_/_/  _/    _/  _/      _/  _/_/_/_/       \n");
color(8,0);
printf("\n \n \n");
printf("\t\t\t\t\t\t                            _______________________\n");
printf("\t\t\t\t\t\t                           |                       | \n");
printf("\t\t\t\t\t\t                           |    1 >   P L A Y      |\n");
printf("\t\t\t\t\t\t                           \\_______________________/\n");
printf("\t\t\t\t\t\t                            _______________________\n");
printf("\t\t\t\t\t\t                           |                       | \n");
printf("\t\t\t\t\t\t                           |    2 >  R U L E S     |\n");
printf("\t\t\t\t\t\t                           \\_______________________/\n");
printf("\t\t\t\t\t\t                            _______________________\n");
printf("\t\t\t\t\t\t                           |                       | \n");
printf("\t\t\t\t\t\t                           |    3 >   E X I T      |\n");
printf("\t\t\t\t\t\t                           \\_______________________/\n");
}
void plays()
{
color(11,0);
printf("\n\n");
printf("  \t                                                  _/_/_/    _/_/         _/_/_/    _/_/    _/      _/  _/_/_/_/   \n");
printf("  \t                                               _/        _/    _/     _/        _/    _/  _/_/  _/_/  _/          \n");
printf(" \t                                               _/  _/_/  _/    _/     _/  _/_/  _/_/_/_/  _/  _/  _/  _/_/_/       \n");
printf(" \t                                              _/    _/  _/    _/     _/    _/  _/    _/  _/      _/  _/            \n");
printf(" \t                                               _/_/_/    _/_/         _/_/_/  _/    _/  _/      _/  _/_/_/_/       \n");
color(8,0);
printf("\n \n \n");
printf("\t\t\t\t\t\t                            _______________________\n");
printf("\t\t\t\t\t\t                           |                       | \n");
printf("\t\t\t\t\t\t                           |    1 >    1 vs 1      |\n");
printf("\t\t\t\t\t\t                           \\_______________________/\n");
printf("\t\t\t\t\t\t                            _______________________\n");
printf("\t\t\t\t\t\t                           |                       | \n");
printf("\t\t\t\t\t\t                           |    2 >  1 VS MACHINE  |\n");
printf("\t\t\t\t\t\t                           \\_______________________/\n");
printf("\t\t\t\t\t\t                            _______________________\n");
printf("\t\t\t\t\t\t                           |                       | \n");
printf("\t\t\t\t\t\t                           |    3 >   B A C K      |\n");
printf("\t\t\t\t\t\t                           \\_______________________/\n");
}

void winner1(){

color(15,0);
printf("\n\n\t\t\t\t\t\t\t\t            ___________    ____ \n");
printf("\t\t\t\t\t\t\t\t     ______/   \\__//   \\__/____\\ \n");
printf("\t\t\t\t\t\t\t\t   _/   \\_/  :           //____\\\\  \n");
printf("\t\t\t\t\t\t\t\t  /|      :  :  ..      /        \\ \n");
printf("\t\t\t\t\t\t\t\t | |     ::     ::      \\        / \n");
printf("\t\t\t\t\t\t\t\t | |     :|     ||     \\ \\______/ \n");
printf("\t\t\t\t\t\t\t\t | |     ||     ||      |\\  /  |  \n");
printf("\t\t\t\t\t\t\t\t  \\|     ||     ||      |   / | \\ \n");
printf("\t\t\t\t\t\t\t\t   |     ||     ||      |  / /_\\ \\ \n");
printf("\t\t\t\t\t\t\t\t   | ___ || ___ ||      | /  /    \\ \n");
printf("\t\t\t\t\t\t\t\t    \\_-_/  \\_-_/ | ____ |/__/      \\ \n");
printf("\t\t\t\t\t\t\t\t                 _\\_--_/    \\      /  \n");
printf("\t\t\t\t\t\t\t\t                /____             /  \n");
printf("\t\t\t\t\t\t\t\t               /     \\           /  \n");
printf("\t\t\t\t\t\t\t\t               \\______\\_________/ \n");
color(11,0);



printf("\n\n\t\t\t\t\t\t\t _|          _|  _|    _|  _|_|_|  _|_|_|_|_|  _|_|_|_|  \n");
printf("\t\t\t\t\t\t\t _|          _|  _|    _|    _|        _|      _|        \n");
printf("\t\t\t\t\t\t\t _|    _|    _|  _|_|_|_|    _|        _|      _|_|_|    \n");
printf("\t\t\t\t\t\t\t   _|  _|  _|    _|    _|    _|        _|      _|        \n");
printf("\t\t\t\t\t\t\t     _|  _|      _|    _|  _|_|_|      _|      _|_|_|_|  \n");

printf("\n\n\n\t\t\t\t\t\t\t\t   YOU ARE THE WINNER WITH %.1f  POINTS \n",-(player1_score+player1_territory+black_stones-player2_score-player2_territory-white_stones));
color(8,0);
printf("\n\n\n\t\t\t\t\t\t\t\t          PRESS ENTER TO CONTINUE  \n");

}

void winner2()
{

color(15,0);
printf("\n\n\t\t\t\t\t\t\t\t            ___________    ____ \n");
printf("\t\t\t\t\t\t\t\t     ______/   \\__//   \\__/____\\ \n");
printf("\t\t\t\t\t\t\t\t   _/   \\_/  :           //____\\\\  \n");
printf("\t\t\t\t\t\t\t\t  /|      :  :  ..      /        \\ \n");
printf("\t\t\t\t\t\t\t\t | |     ::     ::      \\        / \n");
printf("\t\t\t\t\t\t\t\t | |     :|     ||     \\ \\______/ \n");
printf("\t\t\t\t\t\t\t\t | |     ||     ||      |\\  /  |  \n");
printf("\t\t\t\t\t\t\t\t  \\|     ||     ||      |   / | \\ \n");
printf("\t\t\t\t\t\t\t\t   |     ||     ||      |  / /_\\ \\ \n");
printf("\t\t\t\t\t\t\t\t   | ___ || ___ ||      | /  /    \\ \n");
printf("\t\t\t\t\t\t\t\t    \\_-_/  \\_-_/ | ____ |/__/      \\ \n");
printf("\t\t\t\t\t\t\t\t                 _\\_--_/    \\      /  \n");
printf("\t\t\t\t\t\t\t\t                /____             /  \n");
printf("\t\t\t\t\t\t\t\t               /     \\           /  \n");
printf("\t\t\t\t\t\t\t\t               \\______\\_________/ \n");
color(11,0);



printf("\n\n\t\t\t\t\t\t\t     _|_|_|    _|          _|_|      _|_|_|  _|    _|   \n");
printf("\t\t\t\t\t\t\t     _|    _|  _|        _|    _|  _|        _|  _|     \n");
printf("\t\t\t\t\t\t\t     _|_|_|    _|        _|_|_|_|  _|        _|_|       \n");
printf("\t\t\t\t\t\t\t     _|    _|  _|        _|    _|  _|        _|  _|      \n");
printf("\t\t\t\t\t\t\t     _|_|_|    _|_|_|_|  _|    _|    _|_|_|  _|    _|   \n");

printf("\n\n\n\t\t\t\t\t\t\t\t   YOU ARE THE WINNER WITH %.1f  POINTS \n",(player1_score+player1_territory+black_stones-player2_score-player2_territory-white_stones));
color(8,0);
printf("\n\n\n\t\t\t\t\t\t\t\t          PRESS ENTER TO CONTINUE  \n");

}


void randome_player_first(){

printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t   .");
color(14,14);
printf("    ");
color(8,0);
printf(" ");
color(11,11);
printf("aaaa");
color(8,0);
printf(". ");

printf("\n\t\t\t\t\t\t\t\t\t\t   .");
color(14,14);
printf("    ");
color(8,0);
printf(" ");
color(11,11);
printf("aaaa");
color(8,0);
printf(". ");
/*
color(8,0);
printf("\n\t\t\t\t\t\t\t\t\t\t");
color(11,11);
printf("    aaaa            ");
color(11,11);
printf("aaaa");
color(8,0);
printf(". ");
*/

printf("\n\n        \t\t\t\t\t\t\t\t      .");
color(14,14);
printf("aaaa");

color(8,0);
printf(" ");

color(11,11);
printf("    ");

color(8,0);
printf("      ");
color(11,11);
printf("aaaa");
color(8,0);
printf(". ");

printf("\n\t\t\t\t\t\t\t\t\t      .");
color(14,14);
printf("aaaa");

color(8,0);
printf(" ");

color(11,11);
printf("    ");

color(8,0);
printf("      ");
color(11,11);
printf("aaaa");
color(8,0);
printf(". ");

//////////////////

printf("\n\n\t\t\t\t\t\t\t\t\t\t   .");
color(14,14);
printf("    ");
color(8,0);
printf(" ");
color(11,11);
printf("aaaa");
color(8,0);
printf(". ");

printf("\n\t\t\t\t\t\t\t\t\t\t   .");
color(14,14);
printf("    ");
color(8,0);
printf(" ");
color(11,11);
printf("aaaa");
color(8,0);
printf(". ");

}






void randome_player_first2(){

printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t   .");
color(14,14);
printf("    ");
color(8,0);
printf(" ");
color(11,11);
printf("aaaa");
color(8,0);
printf(". ");

printf("\n\t\t\t\t\t\t\t\t\t\t   .");
color(14,14);
printf("    ");
color(8,0);
printf(" ");
color(11,11);
printf("aaaa");
color(8,0);
printf(". ");
/*
color(8,0);
printf("\n\t\t\t\t\t\t\t\t\t\t");
color(11,11);
printf("    aaaa            ");
color(11,11);
printf("aaaa");
color(8,0);
printf(". ");
*/

printf("\n\n        \t\t\t\t\t\t\t\t      .");
color(14,14);
printf("aaaa");

color(8,0);
printf(" ");

color(8,0);
printf("     ");

color(14,14);
printf("    ");

color(8,0);
printf(" ");

color(11,11);
printf("aaaa");
color(8,0);
printf(". ");

printf("\n\t\t\t\t\t\t\t\t\t      .");
color(14,14);
printf("aaaa");

color(8,0);
printf(" ");

color(8,0);
printf("     ");

color(14,14);
printf("    ");

color(8,0);
printf(" ");

color(11,11);
printf("aaaa");
color(8,0);
printf(". ");

//////////////////

printf("\n\n\t\t\t\t\t\t\t\t\t\t   .");
color(14,14);
printf("    ");
color(8,0);
printf(" ");
color(11,11);
printf("aaaa");
color(8,0);
printf(". ");

printf("\n\t\t\t\t\t\t\t\t\t\t   .");
color(14,14);
printf("    ");
color(8,0);
printf(" ");
color(11,11);
printf("aaaa");
color(8,0);
printf(". ");

}
