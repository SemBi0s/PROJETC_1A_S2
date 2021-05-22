#include "include/libs.h"

SCREEN gameScreen;

void mainGame(){
	gameScreen.id = 2;
	gameScreen.scene = mainGameScene;
}

void mainGameScene(){

	for (int i = 0; i < game.difficulty.caseNbr; ++i){
		CASE *mycase = &game.tabCase[i];
		
		if (game.difficulty.caseNbr > 9){
			mycase->rect.x = (app.SCREEN_WIDTH / (game.difficulty.caseNbr/6) ) * mycase->xpos ; 
			mycase->rect.y = (app.SCREEN_HEIGHT / (game.difficulty.caseNbr/6) ) * mycase->ypos ; 
		}else{
			mycase->rect.x = (app.SCREEN_WIDTH / (game.difficulty.caseNbr/3) ) * mycase->xpos ; 
			mycase->rect.y = (app.SCREEN_HEIGHT / (game.difficulty.caseNbr/3) ) * mycase->ypos ; 
		}
		mycase->rect.w = mycase->width; 
		mycase->rect.h = mycase->height; 

	}

	SDL_SetRenderDrawColor(app.renderer, grey.r, grey.g, grey.b, grey.a);
	SDL_RenderClear(app.renderer);

	for (int i = 0; i < game.difficulty.caseNbr; ++i){
		CASE *mycase = &game.tabCase[i];
		SDL_RenderCopy(app.renderer, mycase->img, NULL, &mycase->rect);
	}

}


