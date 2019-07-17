#ifndef function_H_INCLUDED
#define function_H_INCLUDED
/* ^^ these are the include guards */

/* Prototypes for the functions */
/* Sums two ints*/
extern int data[81],lib[81],check[81],ami[81],check2[81],player,interdit[81],old[81],old2[81],old3[81],terr[81],terr2[81],terr3[81];
extern float player1_score,player2_score;
extern int player1_territory,player2_territory,black_stones,white_stones;
extern int in;
extern int territory_found;
 extern  int hh,dd,gg,bb;//detelet it after tesing
extern int compt;
extern int choice,choice2;
extern int who_plays_first,machine_must_pass;

void showme();
void start();
void plays();
void winner1();
void winner2();
void randome_player_first();
void randome_player_first2();



#endif

