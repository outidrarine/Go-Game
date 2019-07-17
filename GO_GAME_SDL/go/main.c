#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include"data.h"






////////////////////////////////////////// graphique


void board(int* data,SDL_Window* window,SDL_Surface* screenSurface,SDL_Surface *play)
{
    SDL_Rect position2;

    //play = IMG_Load("goban.png");
    //SDL_BlitSurface(play, NULL, screenSurface, &position2);

 int x=0,y=0;


    for(int i=0;i<81;i++)
    {
            x=i%9;
            y=(i/9)+1;
            position2.x = 365+67*x;
            position2.y = -35+70*y;
        if(data[i]==1)
        {
            play = IMG_Load("img/black.png");
            SDL_BlitSurface(play, NULL, screenSurface, &position2);
        }
        if(data[i]==2)
        {
            play = IMG_Load("img/white.png");
            SDL_BlitSurface(play, NULL, screenSurface, &position2);
        }
                x=i%9;
                y=(i/9)+1;
                position2.x = 390+67*x;
                position2.y = -15+70*y;
        if(terr2[i]==1)
        {
            play = IMG_Load("img/rec_black.png");
            SDL_BlitSurface(play, NULL, screenSurface, &position2);
        }
        if(terr3[i]==2)
        {
            play = IMG_Load("img/rec_white.png");
            SDL_BlitSurface(play, NULL, screenSurface, &position2);
        }




    }

   // SDL_UpdateWindowSurface( window );
}

void afficher(int x,int y, char* s,SDL_Window* window,SDL_Surface* screenSurface)
{
    SDL_Rect position2;

                            position2.x = x;
                            position2.y = y;

                        SDL_Surface *play = NULL;
                        play = IMG_Load(s);
                        SDL_BlitSurface(play, NULL, screenSurface, &position2);
                        SDL_UpdateWindowSurface( window );
                        free(play);
}





void afficher2(int x,int y, char* s,SDL_Window* window,SDL_Surface* screenSurface)
{
    int get_in=0;
    SDL_Rect position2;
    int c=67,l=70;

    for(int r=0;r<9;r++)
    {
        for(int u=0;u<9;u++)
        {
            if(x<420+c*u&&x>380+c*u&&y>50+l*r&&y<90+l*r)
            {
                position2.x = 400+c*u-35;
                position2.y = 70+l*r-35;
                get_in=1;
                in=u+r*9;
            }
        }

    }



    if(get_in)
    {
        SDL_Surface *play = NULL;
        play = IMG_Load(s);
        SDL_BlitSurface(play, NULL, screenSurface, &position2);
        SDL_UpdateWindowSurface( window );
        free(play);
    }

}
void afficher4(int x,int y, char* s,SDL_Window* window,SDL_Surface* screenSurface)
{
    int get_in=0;
    SDL_Rect position2;
    int c=67,l=70;

    for(int r=0;r<9;r++)
    {
        for(int u=0;u<9;u++)
        {
            if(x<420+c*u&&x>380+c*u&&y>50+l*r&&y<90+l*r)
            {
                position2.x = 400+c*u-35;
                position2.y = 70+l*r-35;
                get_in=1;
            }
        }

    }



    if(get_in)
    {
        SDL_Surface *play = NULL;
        play = IMG_Load(s);
        SDL_BlitSurface(play, NULL, screenSurface, &position2);
        free(play);
    }

}
void afficher3(int x,int y, char* s,SDL_Window* window,SDL_Surface* screenSurface)
{
    SDL_Rect position2;

                            position2.x = x;
                            position2.y = y;

                        SDL_Surface *play = NULL;
                        play = IMG_Load(s);
                        SDL_BlitSurface(play, NULL, screenSurface, &position2);
                        //SDL_UpdateWindowSurface( window );
                        free(play);
}

void afficher_score(SDL_Window* window,SDL_Surface* screenSurface,int a,int b, int is_float, float player1_score)
{

    int tmp=0;
    //virule
    tmp=(int)player1_score%10;
    if(is_float)
    afficher3(a+27,b+25,"img/num/p.png",window,screenSurface);

    //unité
    if(tmp==0)
        afficher3(a,b,"img/num/0.png",window,screenSurface);
    if(tmp==1)
        afficher3(a,b,"img/num/1.png",window,screenSurface);
    if(tmp==2)
        afficher3(a,b,"img/num/2.png",window,screenSurface);
    if(tmp==3)
        afficher3(a,b,"img/num/3.png",window,screenSurface);
    if(tmp==4)
        afficher3(a,b,"img/num/4.png",window,screenSurface);
    if(tmp==5)
        afficher3(a,b,"img/num/5.png",window,screenSurface);
    if(tmp==6)
        afficher3(a,b,"img/num/6.png",window,screenSurface);
    if(tmp==7)
        afficher3(a,b,"img/num/7.png",window,screenSurface);
    if(tmp==8)
        afficher3(a,b,"img/num/8.png",window,screenSurface);
    if(tmp==9)
        afficher3(a,b,"img/num/9.png",window,screenSurface);


    //le nombre *10
        tmp=(int)player1_score/10;
        tmp=tmp%10;

    if(tmp==1)
        afficher3(a-27,b,"img/num/1.png",window,screenSurface);
    if(tmp==2)
        afficher3(a-27,b,"img/num/2.png",window,screenSurface);
    if(tmp==3)
        afficher3(a-27,b,"img/num/3.png",window,screenSurface);
    if(tmp==4)
        afficher3(a-27,b,"img/num/4.png",window,screenSurface);
    if(tmp==5)
        afficher3(a-27,b,"img/num/5.png",window,screenSurface);
    if(tmp==6)
        afficher3(a-27,b,"img/num/6.png",window,screenSurface);
    if(tmp==7)
        afficher3(a-27,b,"img/num/7.png",window,screenSurface);
    if(tmp==8)
        afficher3(a-27,b,"img/num/8.png",window,screenSurface);
    if(tmp==9)
        afficher3(a-27,b,"img/num/9.png",window,screenSurface);

        //le nomre *100


        tmp=(int)player1_score/100;
        tmp=tmp%10;

    if(tmp==1)
        afficher3(a-54,b,"img/num/1.png",window,screenSurface);
    if(tmp==2)
        afficher3(a-54,b,"img/num/2.png",window,screenSurface);
    if(tmp==3)
        afficher3(a-54,b,"img/num/3.png",window,screenSurface);
    if(tmp==4)
        afficher3(a-54,b,"img/num/4.png",window,screenSurface);
    if(tmp==5)
        afficher3(a-54,b,"img/num/5.png",window,screenSurface);
    if(tmp==6)
        afficher3(a-54,b,"img/num/6.png",window,screenSurface);
    if(tmp==7)
        afficher3(a-54,b,"img/num/7.png",window,screenSurface);
    if(tmp==8)
        afficher3(a-54,b,"img/num/8.png",window,screenSurface);
    if(tmp==9)
        afficher3(a-54,b,"img/num/9.png",window,screenSurface);




        //apres la virgule
        if(is_float)
        {
            tmp=(int)(player1_score*10);
            tmp=tmp%10;

            if(tmp==5)
                afficher3(a+40,b,"img/num/5.png",window,screenSurface);
            if(tmp==0)
                afficher3(a+40,b,"img/num/0.png",window,screenSurface);
        }
    tmp=(int)(player1_score*10);
    tmp=tmp%10;



}

/////////////////////////////// joueur vs machine


int joueur_ordinateur_aleatoir(int generated,int* data,int* interdit)
{
    int in=0,get_in2=0,get_in=0;
    int c=67,l=70;

    in=generated;
      //a partir de ce niveau on a l'input dans une dimension
    if(data[in]==0&&interdit[in]!=0)
    {
        end_game=0;
        if(player==0)
            {
                data[in]=1;
            }
        if(player==1)
            {
                data[in]=2;
            }

            return 1;
    }
    if(in==80)
    {
        end_game++;
        player++;
        player%=2;
        return 11;
    }
    return 0;

}



void joueur_ordinateur(int generated,SDL_Window* window,SDL_Surface* screenSurface,SDL_Surface *play,SDL_Event event,int* one_player)
{


        int test=0; //la variable test nous permet de voir si la valeur entré et integre ou non
        test=joueur_ordinateur_aleatoir(generated,data,interdit); //test=1 si une piere est posé 11 si pass
        calcul_liberte();

        for(int i=0;i<81;i++)
        {
            if(lib[i]==0)
                data[i]=0;

        }
        capture();
        calcul_liberte();
        zone();
        if(test)
        {

                if(test!=11)
                {
                    calcul_liberte();
                    capture();
                    calcul_liberte();
                    zone();
                    ko_prevent();
                }
        }

                             territoire();

        if(1)
        {
                afficher3(0,0,"img/goban.png",window,screenSurface);

                afficher_score(window,screenSurface,1120,250,1,player2_score);
                afficher_score(window,screenSurface,1145,520,0,white_stones);
                afficher_score(window,screenSurface,1145,380,0,player2_territory);

                afficher_score(window,screenSurface,120,250,1,player1_score);
                afficher_score(window,screenSurface,140,520,0,black_stones);
                afficher_score(window,screenSurface,140,380,0,player1_territory);

                board(data,window,screenSurface,play);
                if(player==1)
                afficher3(1030,600,"img/pass.png",window,screenSurface);
                if(player==0)
                afficher3(40,600,"img/pass.png",window,screenSurface);
                SDL_UpdateWindowSurface( window );
        }

                        if(end_game==2)
                        {
                            if(player1_score+player1_territory+black_stones<player2_score+player2_territory+white_stones)
                            afficher3(0,0,"img/winner_w.png",window,screenSurface);
                            if(player1_score+player1_territory+black_stones>player2_score+player2_territory+white_stones)
                            afficher3(0,0,"img/winner_b.png",window,screenSurface);

                            afficher3(520,560,"img/menu.png",window,screenSurface);
                            SDL_UpdateWindowSurface( window );
                            int continuer3=1;
                            while(continuer3)
                            {
                                SDL_WaitEvent(&event);
                                switch(event.type)
                                {
                                    case SDL_QUIT:
                                        //Destroy window
                                        SDL_DestroyWindow( window );
                                        //Quit SDL subsystems
                                        SDL_Quit();
                                        break;
                                    case SDL_MOUSEMOTION:
                                        if((event.button.x>520&&event.button.x<810)&&(event.button.y>560&&event.button.y<645))
                                        {
                                            afficher(520,560,"img/menu_p.png",window,screenSurface);
                                        }else{
                                            afficher(520,560,"img/menu.png",window,screenSurface);
                                        }
                                        break;
                                    case SDL_MOUSEBUTTONUP:
                                        if((event.button.x>520&&event.button.x<810)&&(event.button.y>560&&event.button.y<645))
                                        {
                                            afficher(0,0,"img/bg.png",window,screenSurface);
                                            afficher(510,190,"img/1player.png",window,screenSurface);
                                            afficher(510,310,"img/2players.png",window,screenSurface);
                                            afficher(510,430,"img/return.png",window,screenSurface);
                                            player=0;
                                            player1_score=0;
                                            player2_score=6.5;
                                            for(int v=0;v<81;v++)
                                            {
                                                data[v]=0;
                                                lib[v]=0;
                                                interdit[v]=1;
                                            }
                                            end_game=0;
                                            (*one_player)=0;
                                            continuer3 = 0;

                                        }
                                        break;
                                }
                            }
                        }
        test=0;
}

//////////////////// joueur vs joueur
//#include"data.h"
//#include <SDL.h>


int saisie(int x, int y,int* data,int* interdit)
{
    int in=0,get_in2=0,get_in=0;
    int c=67,l=70;
    for(int r=0;r<9;r++)
    {
        for(int u=0;u<9;u++)
        {
            if(x<420+c*u&&x>380+c*u&&y>50+l*r&&y<90+l*r)
            {
                get_in2=1;
                in=u+r*9;
                get_in=1;
            }
        }
    }
        if(player==0)
        {
            if((x>40&&x<270)&&(y>600&&y<670))
            {
                end_game++;
                player++;
                player%=2;
                return 11;
            }
        }
        if(player==1)
        {
            if((x>1030&&x<1260)&&(y>600&&y<670))
            {
                end_game++;
                player++;
                player%=2;
                return 11;
            }
        }
      //a partir de ce niveau on a l'input dans une dimension

    if(get_in2&&data[in]==0&&interdit[in]!=0)
    {
        end_game=0;
        if(player==0)
            {
                data[in]=1;
            }
        if(player==1)
            {
                data[in]=2;
            }

            return 1;
    }
    return 0;

}



void joueur_joueur(int abscice,int ordonnee,SDL_Window* window,SDL_Surface* screenSurface,SDL_Surface *play,SDL_Event event,int* one_player)
{

        calcul_liberte();
        capture();
        calcul_liberte();
        zone();
        int test=0; //la variable test nous permet de voir si la valeur entré et integre ou non
        test=saisie(abscice,ordonnee,data,interdit); //test=1 si une piere est posé 11 si pass
        if(test)
        {
                if(player==0)
                   {
                       afficher2(abscice,ordonnee,"img/black.png",window,screenSurface);
                   }
               if(player==1)
                   {
                       afficher2(abscice,ordonnee,"img/white.png",window,screenSurface);
                   }

                if(test!=11)
                {
                    calcul_liberte();
                    capture();
                    calcul_liberte();
                    zone();
                    ko_prevent();
                }
        }

                             territoire();

        if(1)
        {
                afficher3(0,0,"img/goban.png",window,screenSurface);

                afficher_score(window,screenSurface,1120,250,1,player2_score);
                afficher_score(window,screenSurface,1145,520,0,white_stones);
                afficher_score(window,screenSurface,1145,380,0,player2_territory);

                afficher_score(window,screenSurface,120,250,1,player1_score);
                afficher_score(window,screenSurface,140,520,0,black_stones);
                afficher_score(window,screenSurface,140,380,0,player1_territory);

                board(data,window,screenSurface,play);
                if(player==1)
                afficher3(1030,600,"img/pass.png",window,screenSurface);
                if(player==0)
                afficher3(40,600,"img/pass.png",window,screenSurface);
                SDL_UpdateWindowSurface( window );
        }

                        if(end_game==2)
                        {
                            if(player1_score+player1_territory+black_stones<player2_score+player2_territory+white_stones)
                            afficher3(0,0,"img/winner_w.png",window,screenSurface);
                            if(player1_score+player1_territory+black_stones>player2_score+player2_territory+white_stones)
                            afficher3(0,0,"img/winner_b.png",window,screenSurface);

                            afficher3(520,560,"img/menu.png",window,screenSurface);
                            SDL_UpdateWindowSurface( window );
                            int continuer3=1;
                            while(continuer3)
                            {
                                SDL_WaitEvent(&event);
                                switch(event.type)
                                {
                                    case SDL_QUIT:
                                        //Destroy window
                                        SDL_DestroyWindow( window );
                                        //Quit SDL subsystems
                                        SDL_Quit();
                                        break;
                                    case SDL_MOUSEMOTION:
                                        if((event.button.x>520&&event.button.x<810)&&(event.button.y>560&&event.button.y<645))
                                        {
                                            afficher(520,560,"img/menu_p.png",window,screenSurface);
                                        }else{
                                            afficher(520,560,"img/menu.png",window,screenSurface);
                                        }
                                        break;
                                    case SDL_MOUSEBUTTONUP:
                                        if((event.button.x>520&&event.button.x<810)&&(event.button.y>560&&event.button.y<645))
                                        {
                                            afficher(0,0,"img/bg.png",window,screenSurface);
                                            afficher(510,190,"img/1player.png",window,screenSurface);
                                            afficher(510,310,"img/2players.png",window,screenSurface);
                                            afficher(510,430,"img/return.png",window,screenSurface);
                                            player=0;
                                            player1_score=0;
                                            player2_score=6.5;
                                            for(int v=0;v<81;v++)
                                            {
                                                data[v]=0;
                                                lib[v]=0;
                                                interdit[v]=1;
                                            }
                                            end_game=0;
                                            (*one_player)=0;
                                            continuer3 = 0;

                                        }
                                        break;
                                }
                            }
                        }
        test=0;
}







const int SCREEN_WIDTH = 1300;
const int SCREEN_HEIGHT = 700;

int main( int argc, char* args[] )
{
    srand(time(NULL));
    for(int m=0;m<81;m++)
     {
         interdit[m]=1;
     }
	//The window we'll be rendering to
	SDL_Window* window = NULL;
    SDL_Window* window2 = NULL;
	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;
    SDL_Surface* screenSurface2 = screenSurface;
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else
	{
		//Create window
		window = SDL_CreateWindow( "GO GAME", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN  );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface( window );
            screenSurface2 = SDL_GetWindowSurface( window );
			//Fill the surface white
			SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 15, 0xFF ) );

			//Update the surface

            afficher(0,0,"img/bg.png",window,screenSurface);
            afficher(510,190,"img/play.png",window,screenSurface);
            afficher(510,310,"img/rules.png",window,screenSurface);
            afficher(510,430,"img/options.png",window,screenSurface);
            afficher(510,550,"img/exit.png",window,screenSurface);
            SDL_UpdateWindowSurface( window );
			int continuer = 1;
            SDL_Event event;

            while (continuer)
            {

                SDL_WaitEvent(&event);
                switch(event.type)
                {
                    case SDL_QUIT:
                        {
                            //Destroy window
                            SDL_DestroyWindow( window );

                            //Quit SDL subsystems
                            SDL_Quit();
                        }
                    case SDL_MOUSEMOTION:
                        if((event.motion.x>510&&event.motion.x<800)&&(event.motion.y>190&&event.motion.y<280))
                        {
                            afficher(510,190,"img/play_p.png",window,screenSurface);
                        }else{
                            afficher(510,190,"img/play.png",window,screenSurface);
                        }
                        if((event.motion.x>510&&event.motion.x<800)&&(event.motion.y>310&&event.motion.y<400))
                        {
                            afficher(510,310,"img/rules_p.png",window,screenSurface);
                        }else{
                            afficher(510,310,"img/rules.png",window,screenSurface);
                        }
                        if((event.motion.x>510&&event.motion.x<800)&&(event.motion.y>430&&event.motion.y<510))
                        {
                            afficher(510,430,"img/options_p.png",window,screenSurface);
                        }else{
                            afficher(510,430,"img/options.png",window,screenSurface);
                        }
                        if((event.motion.x>510&&event.motion.x<800)&&(event.motion.y>550&&event.motion.y<640))
                        {
                            afficher(510,550,"img/exit_p.png",window,screenSurface);
                        }else{
                            afficher(510,550,"img/exit.png",window,screenSurface);
                        }
                        break;

                    case SDL_MOUSEBUTTONUP:
                        //play clicked
                         if((event.button.x>510&&event.button.x<800)&&(event.button.y>190&&event.button.y<280))
                         {
                            int continuer2=1,continuer3=1;
                            afficher(0,0,"img/bg.png",window,screenSurface);
                            afficher(510,190,"img/1player.png",window,screenSurface);
                            afficher(510,310,"img/2players.png",window,screenSurface);
                            afficher(510,430,"img/return.png",window,screenSurface);
                            SDL_UpdateWindowSurface( window );
                            continuer2=1;
                            while (continuer2)
                            {
                                SDL_WaitEvent(&event);
                                switch(event.type)
                                {
                                    case SDL_QUIT:
                                        //Destroy window
                                        SDL_DestroyWindow( window );
                                        //Quit SDL subsystems
                                        SDL_Quit();
                                        break;
                                    case SDL_MOUSEMOTION:
                                        if((event.button.x>510&&event.button.x<800)&&(event.button.y>190&&event.button.y<280))
                                            {
                                                afficher(510,190,"img/1player_p.png",window,screenSurface);
                                            }else{
                                                afficher(510,190,"img/1player.png",window,screenSurface);
                                            }
                                        if((event.button.x>510&&event.button.x<800)&&(event.button.y>310&&event.button.y<400))
                                            {
                                                afficher(510,310,"img/2players_p.png",window,screenSurface);
                                            }else{
                                                afficher(510,310,"img/2players.png",window,screenSurface);
                                            }
                                        if((event.button.x>510&&event.button.x<800)&&(event.button.y>430&&event.button.y<510))
                                            {
                                                afficher(510,430,"img/return_p.png",window,screenSurface);
                                            }else{
                                                afficher(510,430,"img/return.png",window,screenSurface);
                                            }
                                        break;

                                    case SDL_MOUSEBUTTONUP:
                                        //back button
                                        if((event.button.x>510&&event.button.x<800)&&(event.button.y>430&&event.button.y<520))
                                        {
                                            afficher(0,0,"img/bg.png",window,screenSurface);
                                            afficher(510,190,"img/play.png",window,screenSurface);
                                            afficher(510,310,"img/rules.png",window,screenSurface);
                                            afficher(510,430,"img/options.png",window,screenSurface);
                                            afficher(510,550,"img/exit.png",window,screenSurface);
                                            continuer2 = 0;
                                        }
                                        //2players clicked
                                        if((event.button.x>510&&event.button.x<800)&&(event.button.y>190&&event.button.y<280))
                                        {
                                            afficher(0,0,"img/goban.png",window,screenSurface);
                afficher_score(window,screenSurface,120,250,1,player1_score);
                afficher_score(window,screenSurface,1120,250,1,player2_score);
                afficher_score(window,screenSurface,1145,520,0,white_stones);
                afficher_score(window,screenSurface,1145,380,0,player2_territory);
                afficher_score(window,screenSurface,140,520,0,black_stones);
                afficher_score(window,screenSurface,140,380,0,player1_territory);
                afficher3(40,600,"img/pass.png",window,screenSurface);
SDL_UpdateWindowSurface( window );
int one_player=1;
old[0]=9;
old2[0]=9;
old3[0]=9;      //to prevent ko from first play
SDL_Surface *play = NULL;
while(one_player)
{
SDL_WaitEvent(&event);
switch(event.type)
{
    case SDL_QUIT:
        //Destroy window
        SDL_DestroyWindow( window );
        //Quit SDL subsystems
        SDL_Quit();
        break;
    case SDL_MOUSEMOTION:
        if(player==1)
        {
            if((event.button.x>1030&&event.button.x<1260)&&(event.button.y>600&&event.button.y<670))
            {
                afficher(1030,600,"img/pass_p.png",window,screenSurface);
            }else{
                afficher(1030,600,"img/pass.png",window,screenSurface);
            }
        }
        if(player==0)
        {
            if((event.button.x>40&&event.button.x<270)&&(event.button.y>600&&event.button.y<670))
            {
                afficher(40,600,"img/pass_p.png",window,screenSurface);
            }else{
                afficher(40,600,"img/pass.png",window,screenSurface);
            }
        }
        break;
    case SDL_MOUSEBUTTONUP:
        joueur_joueur(event.button.x, event.button.y,window,screenSurface,play,event,&one_player);
        if(end_game==2)
            continuer3=0;
        break;
}//fermeture de switch pour continuer3 1 player

} //fermeture de while continuer 3

                                        } //fermeture de if two players clicked

//if 1 player was clicked
if((event.button.x>510&&event.button.x<800)&&(event.button.y>310&&event.button.y<400))
{
    afficher(0,0,"img/bg.png",window,screenSurface);
    afficher(510,190,"img/easy.png",window,screenSurface);
    afficher(510,310,"img/hard.png",window,screenSurface);
    afficher(510,430,"img/return.png",window,screenSurface);

    continuer3=1;
    while(continuer3)
    {
    SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                //Destroy window
                SDL_DestroyWindow( window );
                //Quit SDL subsystems
                SDL_Quit();
                break;
            case SDL_MOUSEMOTION:
                if((event.button.x>510&&event.button.x<800)&&(event.button.y>190&&event.button.y<280))
                    {
                        afficher(510,190,"img/easy_p.png",window,screenSurface);
                    }else{
                        afficher(510,190,"img/easy.png",window,screenSurface);
                    }
                if((event.button.x>510&&event.button.x<800)&&(event.button.y>310&&event.button.y<400))
                    {
                        afficher(510,310,"img/hard_p.png",window,screenSurface);
                    }else{
                        afficher(510,310,"img/hard.png",window,screenSurface);
                    }
                if((event.button.x>510&&event.button.x<800)&&(event.button.y>430&&event.button.y<510))
                    {
                        afficher(510,430,"img/return_p.png",window,screenSurface);
                    }else{
                        afficher(510,430,"img/return.png",window,screenSurface);
                    }
                break;
                case SDL_MOUSEBUTTONUP:
                    //back button
                    if((event.button.x>510&&event.button.x<800)&&(event.button.y>430&&event.button.y<520))
                    {
                            afficher(0,0,"img/bg.png",window,screenSurface);
                            afficher(510,190,"img/1player.png",window,screenSurface);
                            afficher(510,310,"img/2players.png",window,screenSurface);
                            afficher(510,430,"img/return.png",window,screenSurface);
                            continuer3=0;
                            SDL_UpdateWindowSurface( window );
                    }
                    if((event.button.x>510&&event.button.x<800)&&(event.button.y>190&&event.button.y<280))
                    {
                        SDL_Surface *play = NULL;
                        srand(time(NULL));
                        int who_plays_first=0;
                        int randome_AI=0;
                        who_plays_first=rand()%2;
                         //who_plays_first=0; //if i want to force the role of playing



                        continuer3=1;
                        for(int j=0;j<10;j++)
                        {
                            if(j%2==0)
                            afficher(0,0,"img/draw1.png",window,screenSurface);
                            if(j%2==1)
                            afficher(0,0,"img/draw2.png",window,screenSurface);
                            SDL_Delay( 200 );
                        }

                            if(who_plays_first==1)
                                afficher(0,0,"img/start_first.png",window,screenSurface);
                            if(who_plays_first==0)
                                afficher(0,0,"img/start_second.png",window,screenSurface);
                        afficher(520,560,"img/start.png",window,screenSurface);
                                        continuer3=1;

                                        while(continuer3)
                                            {
                                            SDL_WaitEvent(&event);
                                                switch(event.type)
                                                {
                                                    case SDL_QUIT:
                                                        //Destroy window
                                                        SDL_DestroyWindow( window );
                                                        //Quit SDL subsystems
                                                        SDL_Quit();
                                                        break;
                                                   case SDL_MOUSEMOTION:
                                                            if((event.button.x>520&&event.button.x<810)&&(event.button.y>560&&event.button.y<645))
                                                            {
                                                                afficher(520,560,"img/start_p.png",window,screenSurface);
                                                            }else{
                                                                afficher(520,560,"img/start.png",window,screenSurface);
                                                            }
                                                            break;
                                                   case SDL_MOUSEBUTTONUP:
                                                        if((event.button.x>520&&event.button.x<810)&&(event.button.y>560&&event.button.y<645))
                                                            {
                                                                //here starts the game with the computer

                                            afficher(0,0,"img/goban.png",window,screenSurface);
                                            afficher_score(window,screenSurface,120,250,1,player1_score);
                                            afficher_score(window,screenSurface,1120,250,1,player2_score);
                                            afficher_score(window,screenSurface,1145,520,0,white_stones);
                                            afficher_score(window,screenSurface,1145,380,0,player2_territory);
                                            afficher_score(window,screenSurface,140,520,0,black_stones);
                                            afficher_score(window,screenSurface,140,380,0,player1_territory);
                                                     while(who_plays_first==player)
                                                {
                                                        srand(time(NULL));
                                                        randome_AI=rand()%81;
                                                        joueur_ordinateur(randome_AI, window,screenSurface,play,event,&randome_AI);

                                                }
                                                                                    SDL_UpdateWindowSurface( window );
                                                                                int one_player=1;
                                                                                old[0]=9;
                                                                                old2[0]=9;
                                                                                old3[0]=9;      //to prevent ko from first play
                                                                                SDL_Surface *play = NULL;
                                                                                while(one_player)
                                                                                {
                                                                                SDL_WaitEvent(&event);
                                                                                switch(event.type)
                                                                                {
                                                                                    case SDL_QUIT:
                                                                                        //Destroy window
                                                                                        SDL_DestroyWindow( window );
                                                                                        //Quit SDL subsystems
                                                                                        SDL_Quit();
                                                                                        break;
                                                                                    case SDL_MOUSEMOTION:
                                                                                        if(player==1)
                                                                                        {
                                                                                            if((event.button.x>1030&&event.button.x<1260)&&(event.button.y>600&&event.button.y<670))
                                                                                            {
                                                                                                afficher(1030,600,"img/pass_p.png",window,screenSurface);
                                                                                            }else{
                                                                                                afficher(1030,600,"img/pass.png",window,screenSurface);
                                                                                            }
                                                                                        }
                                                                                        if(player==0)
                                                                                        {
                                                                                            if((event.button.x>40&&event.button.x<270)&&(event.button.y>600&&event.button.y<670))
                                                                                            {
                                                                                                afficher(40,600,"img/pass_p.png",window,screenSurface);
                                                                                            }else{
                                                                                                afficher(40,600,"img/pass.png",window,screenSurface);
                                                                                            }
                                                                                        }
                                                                                        break;
                                                                                    case SDL_MOUSEBUTTONUP:

                                                                                        joueur_joueur(event.button.x, event.button.y,window,screenSurface,play,event,&one_player);

                                                                                        int AI_must_pass=0;
                                                                                            AI_must_pass=0;
                                                                                        while(player==((who_plays_first))&&one_player)
                                                                                        {
                                                                                            AI_must_pass++;
                                                                                            srand(time(NULL));
                                                                                            randome_AI=rand()%81;

                                                                                            if(AI_must_pass<100)
                                                                                                joueur_ordinateur(randome_AI, window,screenSurface,play,event,&one_player);
                                                                                            if(AI_must_pass>100)
                                                                                                joueur_ordinateur(80, window,screenSurface,play,event,&one_player);
                                                                                        }


                                                                                        if(one_player==0)
                                                                                        {
                                                                                            SDL_UpdateWindowSurface( window );
                                                                                            continuer3=0;
                                                                                            player=0;
                                                                                            for(int j=0;j<81;j++)
                                                                                            {
                                                                                                data[j]=0;
                                                                                                terr2[j]=0;
                                                                                                terr3[j]=0;
                                                                                            }


                                                                                        }


                                                                                        break;
                                                                                }//fermeture de switch pour continuer3 1 player

                                                                                } //fermeture de while continuer 3






                                                            }//end of easy

                                                    break;
                                            }
                        }

                    }
                    //haaaaaaaaaaaard button clicked
                    //the game starts here
                    if((event.button.x>510&&event.button.x<800)&&(event.button.y>310&&event.button.y<400))
                    {
                        SDL_Surface *play = NULL;
                      //  srand(time(NULL));
                        int who_plays_first=0;
                        int randome_AI=0;
                        who_plays_first=rand()%2;
                         //who_plays_first=0; //if i want to force the role of playing



                        continuer3=1;
                        for(int j=0;j<10;j++)
                        {
                            if(j%2==0)
                            afficher(0,0,"img/draw1.png",window,screenSurface);
                            if(j%2==1)
                            afficher(0,0,"img/draw2.png",window,screenSurface);
                            SDL_Delay( 200 );
                        }

                            if(who_plays_first==1)
                                afficher(0,0,"img/start_first.png",window,screenSurface);
                            if(who_plays_first==0)
                                afficher(0,0,"img/start_second.png",window,screenSurface);
                        afficher(520,560,"img/start.png",window,screenSurface);
                                        continuer3=1;

                                        while(continuer3)
                                            {
                                            SDL_WaitEvent(&event);
                                                switch(event.type)
                                                {
                                                    case SDL_QUIT:
                                                        //Destroy window
                                                        SDL_DestroyWindow( window );
                                                        //Quit SDL subsystems
                                                        SDL_Quit();
                                                        break;
                                                   case SDL_MOUSEMOTION:
                                                            if((event.button.x>520&&event.button.x<810)&&(event.button.y>560&&event.button.y<645))
                                                            {
                                                                afficher(520,560,"img/start_p.png",window,screenSurface);
                                                            }else{
                                                                afficher(520,560,"img/start.png",window,screenSurface);
                                                            }
                                                            break;
                                                   case SDL_MOUSEBUTTONUP:
                                                        if((event.button.x>520&&event.button.x<810)&&(event.button.y>560&&event.button.y<645))
                                                            {
                                                                //here starts the game with the computer

                                            afficher(0,0,"img/goban.png",window,screenSurface);
                                            afficher_score(window,screenSurface,120,250,1,player1_score);
                                            afficher_score(window,screenSurface,1120,250,1,player2_score);
                                            afficher_score(window,screenSurface,1145,520,0,white_stones);
                                            afficher_score(window,screenSurface,1145,380,0,player2_territory);
                                            afficher_score(window,screenSurface,140,520,0,black_stones);
                                            afficher_score(window,screenSurface,140,380,0,player1_territory);
                                                     while(who_plays_first==player)
                                                {
                                                       // srand(time(NULL));
                                                        randome_AI=rand()%81;
                                                        joueur_ordinateur(randome_AI, window,screenSurface,play,event,&randome_AI);

                                                }
                                                                                    SDL_UpdateWindowSurface( window );
                                                                                int one_player=1;
                                                                                old[0]=9;
                                                                                old2[0]=9;
                                                                                old3[0]=9;      //to prevent ko from first play
                                                                                SDL_Surface *play = NULL;
                                                                                while(one_player)
                                                                                {
                                                                                SDL_WaitEvent(&event);
                                                                                switch(event.type)
                                                                                {
                                                                                    case SDL_QUIT:
                                                                                        //Destroy window
                                                                                        SDL_DestroyWindow( window );
                                                                                        //Quit SDL subsystems
                                                                                        SDL_Quit();
                                                                                        break;
                                                                                    case SDL_MOUSEMOTION:
                                                                                        if(player==1)
                                                                                        {
                                                                                            if((event.button.x>1030&&event.button.x<1260)&&(event.button.y>600&&event.button.y<670))
                                                                                            {
                                                                                                afficher(1030,600,"img/pass_p.png",window,screenSurface);
                                                                                            }else{
                                                                                                afficher(1030,600,"img/pass.png",window,screenSurface);
                                                                                            }
                                                                                        }
                                                                                        if(player==0)
                                                                                        {
                                                                                            if((event.button.x>40&&event.button.x<270)&&(event.button.y>600&&event.button.y<670))
                                                                                            {
                                                                                                afficher(40,600,"img/pass_p.png",window,screenSurface);
                                                                                            }else{
                                                                                                afficher(40,600,"img/pass.png",window,screenSurface);
                                                                                            }
                                                                                        }
                                                                                        break;
                                                                                    case SDL_MOUSEBUTTONUP:
                                                                                             ////////////////////////////////////////////////////
                                                                                                                if(player==who_plays_first)
                                                                                                                {
                                                                                                                        int adverse=0;
                                                                                                                            int ai_decision=15;

                                                                                                                            for(int i=0;i<81;i++)
                                                                                                                            {
                                                                                                                                if(data[i]==who_plays_first+1)
                                                                                                                                if(lib[i]==1)
                                                                                                                                    ai_decision=i;

                                                                                                                            }
                                                                                                                            printf("\niiiiiiiiiiiiiiiiii",ai_decision);
                                                                                                                            if(lib[ai_decision]==1)
                                                                                                                                                    {


                                                                                                                                                    calcul(ai_decision);
                                                                                                                                                    for(int i=0;i<81;i++)
                                                                                                                                                    {
                                                                                                                                                        if(ami[i]==1)
                                                                                                                                                            ai_decision=i;
                                                                                                                                                    }

                                                                                                                                                    if(data[ai_decision]==0&&interdit[ai_decision]!=1)
                                                                                                                                                    {
                                                                                                                                                        joueur_ordinateur(ai_decision, window,screenSurface,play,event,&one_player);


                                                                                                                                                    joueur_ordinateur(ai_decision, window,screenSurface,play,event,&one_player);
                                                                                                                                                    for(int j=0;j<81;j++)
                                                                                                                                                    {
                                                                                                                                                            if(j%9==0)
                                                                                                                                                                printf("\n");
                                                                                                                                                        printf(" %d",data[j]);
                                                                                                                                                    }
                                                                                                                                        }
                                                                                                                }
                                                                                                                }
                                                                                                                ////////////////////////////////////////////////////
                                                                                                            ////////////////////////////////////////////////////
                                                                                                                if(player==who_plays_first)
                                                                                                                {
                                                                                                                        int adverse=0;
                                                                                                                        if(who_plays_first==0)
                                                                                                                            adverse=2;
                                                                                                                        if(who_plays_first==1)
                                                                                                                            adverse=1;
                                                                                                                        if(player==((who_plays_first))&&one_player)
                                                                                                                        {
                                                                                                                            int ai_decision=15;

                                                                                                                            for(int i=0;i<81;i++)
                                                                                                                            {
                                                                                                                                if(lib[i]<=2)
                                                                                                                                if(lib[i]<lib[ai_decision]&&data[i]==adverse)
                                                                                                                                    ai_decision=i;
                                                                                                                            }
                                                                                                                            calcul(ai_decision);
                                                                                                                            for(int i=0;i<81;i++)
                                                                                                                            {
                                                                                                                                if(ami[i]==1)
                                                                                                                                    ai_decision=i;
                                                                                                                            }

                                                                                                                            if(data[ai_decision]==0&&interdit[ai_decision]!=1)
                                                                                                                            {
                                                                                                                                joueur_ordinateur(ai_decision, window,screenSurface,play,event,&one_player);
                                                                                                                            }

                                                                                                                            joueur_ordinateur(ai_decision, window,screenSurface,play,event,&one_player);
                                                                                                                            for(int j=0;j<81;j++)
                                                                                                                            {
                                                                                                                                    if(j%9==0)
                                                                                                                                        printf("\n");
                                                                                                                                printf(" %d",data[j]);
                                                                                                                            }

                                                                                                                }
                                                                                                                }
                                                                                                                ////////////////////////////////////////////////////
                                                                                        joueur_joueur(event.button.x, event.button.y,window,screenSurface,play,event,&one_player);
                                                                                        int AI_must_pass=0;
                                                                                         ////////////////////////////////////////////////////
                                                                                                                if(player==who_plays_first)
                                                                                                                {
                                                                                                                        int adverse=0;
                                                                                                                            int ai_decision=15;

                                                                                                                            for(int i=0;i<81;i++)
                                                                                                                            {
                                                                                                                                if(data[i]==who_plays_first+1)
                                                                                                                                if(lib[i]==1)
                                                                                                                                    ai_decision=i;

                                                                                                                            }
                                                                                                                            printf("\niiiiiiiiiiiiiiiiii",ai_decision);
                                                                                                                            if(lib[ai_decision]==1)
                                                                                                                                                    {


                                                                                                                                                    calcul(ai_decision);
                                                                                                                                                    for(int i=0;i<81;i++)
                                                                                                                                                    {
                                                                                                                                                        if(ami[i]==1)
                                                                                                                                                            ai_decision=i;
                                                                                                                                                    }

                                                                                                                                                    if(data[ai_decision]==0&&interdit[ai_decision]!=1)
                                                                                                                                                    {
                                                                                                                                                        joueur_ordinateur(ai_decision, window,screenSurface,play,event,&one_player);


                                                                                                                                                    joueur_ordinateur(ai_decision, window,screenSurface,play,event,&one_player);
                                                                                                                                                    for(int j=0;j<81;j++)
                                                                                                                                                    {
                                                                                                                                                            if(j%9==0)
                                                                                                                                                                printf("\n");
                                                                                                                                                        printf(" %d",data[j]);
                                                                                                                                                    }
                                                                                                                                        }
                                                                                                                }
                                                                                                                }
                                                                                                                ////////////////////////////////////////////////////
                                                                                                            ////////////////////////////////////////////////////
                                                                                                                if(player==who_plays_first)
                                                                                                                {
                                                                                                                        int adverse=0;
                                                                                                                        if(who_plays_first==0)
                                                                                                                            adverse=2;
                                                                                                                        if(who_plays_first==1)
                                                                                                                            adverse=1;
                                                                                                                        if(player==((who_plays_first))&&one_player)
                                                                                                                        {
                                                                                                                            int ai_decision=15;

                                                                                                                            for(int i=0;i<81;i++)
                                                                                                                            {
                                                                                                                                if(lib[i]<=2)
                                                                                                                                if(lib[i]<lib[ai_decision]&&data[i]==adverse)
                                                                                                                                    ai_decision=i;
                                                                                                                            }
                                                                                                                            calcul(ai_decision);
                                                                                                                            for(int i=0;i<81;i++)
                                                                                                                            {
                                                                                                                                if(ami[i]==1)
                                                                                                                                    ai_decision=i;
                                                                                                                            }

                                                                                                                            if(data[ai_decision]==0&&interdit[ai_decision]!=1)
                                                                                                                            {
                                                                                                                                joueur_ordinateur(ai_decision, window,screenSurface,play,event,&one_player);
                                                                                                                            }

                                                                                                                            joueur_ordinateur(ai_decision, window,screenSurface,play,event,&one_player);
                                                                                                                            for(int j=0;j<81;j++)
                                                                                                                            {
                                                                                                                                    if(j%9==0)
                                                                                                                                        printf("\n");
                                                                                                                                printf(" %d",data[j]);
                                                                                                                            }

                                                                                                                }
                                                                                                                }
                                                                                                                ////////////////////////////////////////////////////

                                                                                        while(player==((who_plays_first))&&one_player)
                                                                                        {
                                                                                            AI_must_pass++;
                                                                                         //   srand(time(NULL));
                                                                                            randome_AI=rand()%81;


                                                                                                if(data[randome_AI]==0)
                                                                                                {
                                                                                                if(AI_must_pass<100)
                                                                                                joueur_ordinateur(randome_AI, window,screenSurface,play,event,&one_player);

                                                                                                }
                                                                                            if(AI_must_pass>40)
                                                                                                joueur_ordinateur(80, window,screenSurface,play,event,&one_player);
                                                                                        }
                                                                                        AI_must_pass=0;

                                                                                        if(one_player==0)
                                                                                        {
                                                                                            SDL_UpdateWindowSurface( window );
                                                                                            continuer3=0;
                                                                                            player=0;
                                                                                            for(int j=0;j<81;j++)
                                                                                            {
                                                                                                data[j]=0;
                                                                                                terr2[j]=0;
                                                                                                terr3[j]=0;
                                                                                            }


                                                                                        }


                                                                                        break;
                                                                                }//fermeture de switch pour continuer3 1 player

                                                                                } //fermeture de while continuer 3






                                                            }//end of easy

                                                    break;
                                            }
                        }

                    }

        }
    }

}
                                    }
                                }
                            }
                            if((event.button.x>510&&event.button.x<800)&&(event.button.y>550&&event.button.y<640))
                            {
                                //Destroy window
                                SDL_DestroyWindow( window );
                                //Quit SDL subsystems
                                SDL_Quit();
                                break;
                            }

                }
            }
	}//Create window

	//Destroy window
	SDL_DestroyWindow( window );

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}	//Initialize SDL

} //main
