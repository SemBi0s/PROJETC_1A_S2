#include "include/libs.h"

SCREEN levelSelection;

void mainLevelSelector(){
	levelSelection.id = 1;
	levelSelection.scene = mainLevelScene;
	levelSelection.assets = mainLevelLoadAssets;
	levelSelection.initButton = initLevelButton;
	levelSelection.btnNbr = 7;
	levelSelection.btntab = malloc(sizeof(Button) * levelSelection.btnNbr);
	levelSelection.initButton(levelSelection.btntab);
	levelSelection.astab = levelSelection.assets();
}

void initLevelButton(Button *btn){
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
	btn2.xpos = 125;
	btn2.ypos = 450;
	btn2.width = 300;
	btn2.height = 80;
	btn2.color = grey;
	btn2.textSize = 40;
	btn2.text = "EASY";
	btn2.textFont = TTF_OpenFont("src/font/arial.ttf", btn2.textSize);
	btn2.textColor = white;
	btn2.rect.x = btn2.xpos;
	btn2.rect.y = btn2.ypos;
	btn2.rect.w = btn2.width; 
	btn2.rect.h = btn2.height; 
	btn2.textrect.x = btn2.rect.x + 95;
	btn2.textrect.y = btn2.rect.y + 17;
	btn2.function = LevelSelectEasyFunc;

	*(btn + 1) = btn2;

	Button btn3;
	btn3.xpos = 475;
	btn3.ypos = 450;
	btn3.width = 300;
	btn3.height = 80;
	btn3.color = grey;
	btn3.textSize = 40;
	btn3.text = "MEDIUM";
	btn3.textFont = TTF_OpenFont("src/font/arial.ttf", btn3.textSize);
	btn3.textColor = white;
	btn3.rect.x = btn3.xpos;
	btn3.rect.y = btn3.ypos;
	btn3.rect.w = btn3.width; 
	btn3.rect.h = btn3.height; 
	btn3.textrect.x = btn3.rect.x + 75;
	btn3.textrect.y = btn3.rect.y + 17;
	btn3.function = LevelSelectMediumFunc;

	*(btn + 2) = btn3;

	Button btn4;
	btn4.xpos = 125;
	btn4.ypos = 550;
	btn4.width = 300;
	btn4.height = 80;
	btn4.color = grey;
	btn4.textSize = 40;
	btn4.text = "HARD";
	btn4.textFont = TTF_OpenFont("src/font/arial.ttf", btn4.textSize);
	btn4.textColor = white;
	btn4.rect.x = btn4.xpos;
	btn4.rect.y = btn4.ypos;
	btn4.rect.w = btn4.width; 
	btn4.rect.h = btn4.height; 
	btn4.textrect.x = btn4.rect.x + 95;
	btn4.textrect.y = btn4.rect.y + 17;
	btn4.function = LevelSelectHardFunc;

	*(btn + 3) = btn4;

	Button btn5;
	btn5.xpos = 475;
	btn5.ypos = 550;
	btn5.width = 300;
	btn5.height = 80;
	btn5.color = grey;
	btn5.textSize = 40;
	btn5.text = "EXTREME";
	btn5.textFont = TTF_OpenFont("src/font/arial.ttf", btn5.textSize);
	btn5.textColor = white;
	btn5.rect.x = btn5.xpos;
	btn5.rect.y = btn5.ypos;
	btn5.rect.w = btn5.width; 
	btn5.rect.h = btn5.height; 
	btn5.textrect.x = btn5.rect.x + 55;
	btn5.textrect.y = btn5.rect.y + 17;
	btn5.function = LevelSelectExtremeFunc;

	*(btn + 4) = btn5;

	Button btn6;
	btn6.xpos = 450;
	btn6.ypos = 350;
	btn6.width = 150;
	btn6.height = 40;
	btn6.color = grey;
	btn6.textSize = 30;
	btn6.text = "NUMBER";
	btn6.textFont = TTF_OpenFont("src/font/arial.ttf", btn6.textSize);
	btn6.textColor = white;
	btn6.rect.x = btn6.xpos;
	btn6.rect.y = btn6.ypos;
	btn6.rect.w = btn6.width; 
	btn6.rect.h = btn6.height; 
	btn6.textrect.x = btn6.rect.x + 10;
	btn6.textrect.y = btn6.rect.y + 5;
	btn6.function = btnSwitchTwoFunc;

	*(btn + 5) = btn6;

	Button btn7;
	btn7.xpos = 300;
	btn7.ypos = 350;
	btn7.width = 150;
	btn7.height = 40;
	btn7.color = white;
	btn7.textSize = 30;
	btn7.text = "IMAGE";
	btn7.textFont = TTF_OpenFont("src/font/arial.ttf", btn7.textSize);
	btn7.textColor = grey;
	btn7.rect.x = btn7.xpos;
	btn7.rect.y = btn7.ypos;
	btn7.rect.w = btn7.width; 
	btn7.rect.h = btn7.height; 
	btn7.textrect.x = btn7.rect.x + 30;
	btn7.textrect.y = btn7.rect.y + 5;
	btn7.function = btnSwitchOneFunc;

	*(btn + 6) = btn7;

}

void mainLevelScene(){
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

Image* mainLevelLoadAssets(){
	//Image *tab, logo;
	//tab = malloc( 2 * sizeof(Image));

	/*
	*
	* LOAD ASSETS HERE
	*
	*/
	
	//return tab;

}


//BTN FUNCTiON

void btnCloseFunc(){
	mainMenu();
	app.currentSCREEN = &menu;
}

void btnSwitchOneFunc(){
	levelSelection.btntab[5].color = grey;
	levelSelection.btntab[5].textColor = white;
	levelSelection.btntab[6].color = white;
	levelSelection.btntab[6].textColor = grey;
	game.isNumber = false;
}
void btnSwitchTwoFunc(){
	levelSelection.btntab[6].color = grey;
	levelSelection.btntab[6].textColor = white;
	levelSelection.btntab[5].color = white;
	levelSelection.btntab[5].textColor = grey;
	game.isNumber = true;
}

void LevelSelectEasyFunc(){
	Game(easy);
	app.currentSCREEN = &game.screen;
}

void LevelSelectMediumFunc(){
	Game(medium);
	app.currentSCREEN = &game.screen;
}
void LevelSelectHardFunc(){
	Game(hard);
	app.currentSCREEN = &game.screen;
}
void LevelSelectExtremeFunc(){
	Game(extreme);
	app.currentSCREEN = &game.screen;
}