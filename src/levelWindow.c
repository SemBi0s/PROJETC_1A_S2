#include "include/libs.h"

SCREEN levelSelection;

void mainGame(){
	levelSelection.id = 1;
	levelSelection.scene = mainGameScene;
	levelSelection.assets = mainGameLoadAssets;
	levelSelection.initButton = initGameButton;
	levelSelection.btnNbr = 4;
	levelSelection.btntab = malloc(sizeof(Button) * levelSelection.btnNbr);
	levelSelection.initButton(levelSelection.btntab);
	levelSelection.astab = levelSelection.assets();
}

void initGameButton(Button *btn){
	Button btn1;
	btn1.xpos = 10;
	btn1.ypos = 10;
	btn1.width = 20;
	btn1.height = 20;
	btn1.color = red;
	btn1.textSize = 21;
	btn1.text = "X";
	btn1.textFont = TTF_OpenFont("src/font/arial.ttf", btn1.textSize);
	btn1.textColor = white;
	btn1.rect.x = btn1.xpos;
	btn1.rect.y = btn1.ypos;
	btn1.rect.w = btn1.width; 
	btn1.rect.h = btn1.height; 
	btn1.textrect.x = btn1.rect.x + 3;
	btn1.textrect.y = btn1.rect.y - 2;
	btn1.function = btnCloseFunc;

	*(btn) = btn1;

	Button btn2;
	btn2.xpos = 100;
	btn2.ypos = 100;
	btn2.width = 220;
	btn2.height = 80;
	btn2.color = grey;
	btn2.textSize = 50;
	btn2.text = "2";
	btn2.textFont = TTF_OpenFont("src/font/arial.ttf", btn2.textSize);
	btn2.textColor = white;
	btn2.rect.x = btn2.xpos;
	btn2.rect.y = btn2.ypos;
	btn2.rect.w = btn2.width; 
	btn2.rect.h = btn2.height; 
	btn2.textrect.x = btn2.rect.x + 30;
	btn2.textrect.y = btn2.rect.y + 10;
	btn2.function = LevelSelectFunc;

	*(btn + 1) = btn2;

	Button btn3;
	btn3.xpos = 200;
	btn3.ypos = 200;
	btn3.width = 220;
	btn3.height = 80;
	btn3.color = grey;
	btn3.textSize = 50;
	btn3.text = "3";
	btn3.textFont = TTF_OpenFont("src/font/arial.ttf", btn3.textSize);
	btn3.textColor = white;
	btn3.rect.x = btn3.xpos;
	btn3.rect.y = btn3.ypos;
	btn3.rect.w = btn3.width; 
	btn3.rect.h = btn3.height; 
	btn3.textrect.x = btn3.rect.x + 30;
	btn3.textrect.y = btn3.rect.y + 10;
	btn3.function = LevelSelectFunc;

	*(btn + 2) = btn3;

	Button btn4;
	btn4.xpos = 300;
	btn4.ypos = 300;
	btn4.width = 220;
	btn4.height = 80;
	btn4.color = grey;
	btn4.textSize = 50;
	btn4.text = "4";
	btn4.textFont = TTF_OpenFont("src/font/arial.ttf", btn4.textSize);
	btn4.textColor = white;
	btn4.rect.x = btn4.xpos;
	btn4.rect.y = btn4.ypos;
	btn4.rect.w = btn4.width; 
	btn4.rect.h = btn4.height; 
	btn4.textrect.x = btn4.rect.x + 30;
	btn4.textrect.y = btn4.rect.y + 10;
	btn4.function = LevelSelectFunc;

	*(btn + 3) = btn4;

}

void mainGameScene(){
	for (int i = 0; i < levelSelection.btnNbr; ++i){

		Button *btn = &levelSelection.btntab[i];

		if (btn -> textFont == NULL){
			printf("Font Error %s \n", TTF_GetError());
		}
		prepareBtnRendering(btn);
	}

	SDL_SetRenderDrawColor(app.renderer, blue.r, blue.g, blue.b, blue.a);
	SDL_RenderClear(app.renderer);

	for (int i = 0; i < levelSelection.btnNbr; ++i){

		Button *btn = &levelSelection.btntab[i];
		renderBtn(btn);
	}
 	
}

Image* mainGameLoadAssets(){
	Image *tab, logo;
	tab = malloc( 2 * sizeof(Image));

	/*
	*
	* LOAD ASSETS HERE
	*
	*/
	
	return tab;

}

void btnCloseFunc(){
	mainMenu();
	app.currentSCREEN = &menu;
}

void LevelSelectFunc(Button btn){
	btn.xpos += 20;
	printf("toto\n");
}