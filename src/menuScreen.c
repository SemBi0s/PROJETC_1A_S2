#include "include/libs.h"

SCREEN menu;

void mainMenu(){
	menu.id = 0;
	menu.scene = mainMenuScene;
	menu.assets = mainMenuLoadAssets;
	menu.initButton = initButton;
	menu.btnNbr = 3;
	menu.btntab = malloc(sizeof(Button) * menu.btnNbr);
	menu.initButton(menu.btntab);
	menu.astab = menu.assets();
}

void initButton(Button *btn){
	Button btn1;
	btn1.xpos = 300;
	btn1.ypos = 420;
	btn1.width = 300;
	btn1.height = 80;
	btn1.color = grey;
	btn1.textSize = 50;
	btn1.text = "PLAY !";
	btn1.textFont = TTF_OpenFont("src/font/arial.ttf", btn1.textSize);
	btn1.textColor = white;
	btn1.rect.x = btn1.xpos;
	btn1.rect.y = btn1.ypos;
	btn1.rect.w = btn1.width; 
	btn1.rect.h = btn1.height; 
	btn1.textrect.x = btn1.rect.x + 80;
	btn1.textrect.y = btn1.rect.y + 10;
	btn1.function = PlayBtnFunc;

	*(btn) = btn1;

	Button btn2;
	btn2.xpos = 300;
	btn2.ypos = 540;
	btn2.width = 300;
	btn2.height = 80;
	btn2.color = grey;
	btn2.textSize = 50;
	btn2.text = "RULES";
	btn2.textFont = TTF_OpenFont("src/font/arial.ttf", btn2.textSize);
	btn2.textColor = white;
	btn2.rect.x = btn2.xpos;
	btn2.rect.y = btn2.ypos;
	btn2.rect.w = btn2.width; 
	btn2.rect.h = btn2.height; 
	btn2.textrect.x = btn2.rect.x + 70;
	btn2.textrect.y = btn2.rect.y + 10;
	btn2.function = RuleBtnFunc;

	*(btn + 1) = btn2;

	Button btn3;
	btn3.xpos = 300;
	btn3.ypos = 660;
	btn3.width = 300;
	btn3.height = 80;
	btn3.color = grey;
	btn3.textSize = 50;
	btn3.text = "QUIT";
	btn3.textFont = TTF_OpenFont("src/font/arial.ttf", btn3.textSize);
	btn3.textColor = white;
	btn3.rect.x = btn3.xpos;
	btn3.rect.y = btn3.ypos;
	btn3.rect.w = btn3.width; 
	btn3.rect.h = btn3.height; 
	btn3.textrect.x = btn3.rect.x + 90;
	btn3.textrect.y = btn3.rect.y + 10;
	btn3.function = QuitButtonFunc;

	*(btn + 2) = btn3;
}

void mainMenuScene(){
	SDL_QueryTexture(menu.astab[0].img, NULL, NULL, &menu.astab[0].width, &menu.astab[0].height); //TO CROP TO IMAGE
	SDL_Rect logoRect; 
	logoRect.x = app.SCREEN_WIDTH /8; 
	logoRect.y = app.SCREEN_HEIGHT /6; 
	logoRect.w = menu.astab[0].width; 
	logoRect.h = menu.astab[0].height; 

	SDL_QueryTexture(menu.astab[1].img, NULL, NULL, &menu.astab[1].width, &menu.astab[1].height); //TO CROP TO IMAGE
	SDL_Rect logoRect2; 
	logoRect2.x = 0; 
	logoRect2.y = 0; 
	logoRect2.w = 900; 
	logoRect2.h = 900; 

	for (int i = 0; i < menu.btnNbr; ++i){

		Button *btn = &menu.btntab[i];

		if (btn -> textFont == NULL){
			printf("Font Error %s \n", TTF_GetError());
		}
		prepareBtnRendering(btn);
	}

	SDL_SetRenderDrawColor(app.renderer, blue.r, blue.g, blue.b, blue.a);
	SDL_RenderClear(app.renderer);

	SDL_RenderCopy(app.renderer, menu.astab[1].img, NULL, &logoRect2);

	for (int i = 0; i < menu.btnNbr; ++i){

		Button *btn = &menu.btntab[i];
		renderBtn(btn);
	}

	SDL_RenderCopy(app.renderer, menu.astab[0].img, NULL, &logoRect);
 	
}

Image* mainMenuLoadAssets(){
	Image *tab, logo, bg;
	tab = malloc( 2 * sizeof(Image));

	logo.img = IMG_LoadTexture(app.renderer,"src/img/logo.png");
	if(!logo.img){
		printf("IMG_Load: %s\n", IMG_GetError());
	}
	*(tab) = logo;
	
	bg.img = IMG_LoadTexture(app.renderer,"src/img/Arriere_plan.png");
	
	if(!logo.img){
		printf("IMG_Load: %s\n", IMG_GetError());
	}
	*(tab + 1) = bg;

	return tab;

}


void PlayBtnFunc(){
	mainGame();
	app.currentSCREEN = &levelSelection;
}

void QuitButtonFunc(){
	SDL_Event event;
	event.type =  SDL_QUIT;

	SDL_PushEvent(&event);
}
void RuleBtnFunc(){
	mainRule();
	app.currentSCREEN = &rule;
}