#include "include/libs.h"

SCREEN rule;

void mainRule(){
	rule.id = 3;
	rule.scene = mainRuleScene;
	rule.assets = mainRuleLoadAssets;
	rule.initButton = initRuleButton;
	rule.btnNbr = 1;
	rule.btntab = malloc(sizeof(Button) * rule.btnNbr);
	rule.initButton(rule.btntab);
	rule.astab = rule.assets();
}

void initRuleButton(Button *btn){
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


}

void mainRuleScene(){
	SDL_QueryTexture(rule.astab[0].img, NULL, NULL, &rule.astab[0].width, &rule.astab[0].height); //TO CROP TO IMAGE
	SDL_Rect logoRect; 
	logoRect.x = 0; 
	logoRect.y = 0; 
	logoRect.w = 900; 
	logoRect.h = 900; 

	for (int i = 0; i < rule.btnNbr; ++i){

		Button *btn = &rule.btntab[i];

		if (btn -> textFont == NULL){
			printf("Font Error %s \n", TTF_GetError());
		}
		prepareBtnRendering(btn);
	}

	SDL_SetRenderDrawColor(app.renderer, blue.r, blue.g, blue.b, blue.a);
	SDL_RenderClear(app.renderer);

	SDL_RenderCopy(app.renderer, rule.astab[0].img, NULL, &logoRect);

	for (int i = 0; i < rule.btnNbr; ++i){

		Button *btn = &rule.btntab[i];
		renderBtn(btn);
	}
 	
}

Image* mainRuleLoadAssets(){
	Image *tab, bg;
	tab = malloc( 2 * sizeof(Image));

	bg.img = IMG_LoadTexture(app.renderer,"src/img/rules.png");
	
	if(!bg.img){
		printf("IMG_Load: %s\n", IMG_GetError());
	}
	*(tab) = bg;

	return tab;

}

