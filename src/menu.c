#include "include/libs.h"

SCREEN menu;

void mainMenu(){
	menu.id = 0;
	menu.scene = mainMenuScene;
	menu.assets = mainMenuLoadAssets;
	menu.astab = menu.assets();
}

void mainMenuScene(){
	SDL_QueryTexture(menu.astab[0].img, NULL, NULL, &menu.astab[0].width, &menu.astab[0].height);
	SDL_Rect logoRect; 
	logoRect.x = 160; 
	logoRect.y = 20; 
	logoRect.w = menu.astab[0].width; 
	logoRect.h = menu.astab[0].height; 

	Button btn1;
	btn1.xpos = 290;
	btn1.ypos = 230;
	btn1.width = 220;
	btn1.height = 80;
	btn1.color = red;
	btn1.text = "JOUER";
	btn1.rect.x = btn1.xpos;
	btn1.rect.y = btn1.ypos;
	btn1.rect.w = btn1.width; 
	btn1.rect.h = btn1.height; 

	Button btn2;
	btn2.xpos = 290;
	btn2.ypos = 350;
	btn2.width = 220;
	btn2.height = 80;
	btn2.color = red;
	btn2.text = "Quitter";
	btn2.rect.x = btn2.xpos;
	btn2.rect.y = btn2.ypos;
	btn2.rect.w = btn2.width; 
	btn2.rect.h = btn2.height; 
	

	TTF_Font* arial = TTF_OpenFont("src/font/arial.ttf", 100); 

	if (arial == NULL){
		printf("Font Error %s \n", TTF_GetError());
	}

	SDL_Color White = {255, 255, 255};  
	SDL_Surface* surfaceMessage1 = TTF_RenderText_Solid(arial, btn1.text, White); 
	SDL_Texture* Message1 = SDL_CreateTextureFromSurface(app.renderer, surfaceMessage1);

	SDL_Surface* surfaceMessage2 = TTF_RenderText_Solid(arial, btn2.text, White); 
	SDL_Texture* Message2 = SDL_CreateTextureFromSurface(app.renderer, surfaceMessage2);

	SDL_SetRenderDrawColor(app.renderer, blue.r, blue.g, blue.b, blue.o);
	SDL_RenderClear(app.renderer);

	SDL_SetRenderDrawColor(app.renderer, grey.r, grey.g, grey.b, grey.o);
	SDL_RenderFillRect(app.renderer, &btn1.rect);
	SDL_RenderFillRect(app.renderer, &btn2.rect);

	SDL_RenderCopy(app.renderer, Message1, NULL, &btn1.rect);
	SDL_RenderCopy(app.renderer, Message2, NULL, &btn2.rect);
	SDL_RenderCopy(app.renderer, menu.astab[0].img, NULL, &logoRect);

	SDL_FreeSurface(surfaceMessage1);
	SDL_DestroyTexture(Message1);
	SDL_FreeSurface(surfaceMessage2);
	SDL_DestroyTexture(Message2);
	TTF_CloseFont(arial);
	
}

Image* mainMenuLoadAssets(){
	Image *tab, logo;
	tab = malloc( 2 * sizeof(Image));

	logo.img = IMG_LoadTexture(app.renderer,"src/img/logo.png");
	logo.width = 470;
	logo.height = 128;
	if(!logo.img){
		printf("IMG_Load: %s\n", IMG_GetError());
	}
	*(tab) = logo;

	return tab;

}