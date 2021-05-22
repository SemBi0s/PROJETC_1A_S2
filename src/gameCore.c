#include "include/libs.h"

GAME game;

void Game(DIFFICULTY difficulty){
	game.screen = gameScreen;
	game.difficulty = difficulty;
	game.initCase = initCase;
	game.tabCase = malloc(sizeof(CASE) * game.difficulty.caseNbr);
	game.initCase(game.tabCase, game.difficulty.caseNbr, game.difficulty.name);
	gameFunction();
}

void initCase(CASE *tab, int size, char *name){
	int id = 0;
	printf("%d\n", game.isNumber );
		if(size > 9){
			for (int y = 0; y < size/6; ++y){
				for (int x = 0; x < size/6; ++x){
					char path[50];
					if (!game.isNumber){
						sprintf(path, "./src/img/%s/%d%d.jpg", name, y, x);
					}else if (game.isNumber){
						sprintf(path, "./src/img/%s/%d%d.png", "number/extreme", y, x);
					}
					
					SDL_Texture *img = IMG_LoadTexture(app.renderer,path);
					if(!img){
						printf("IMG_Load: %s\n", IMG_GetError());
						return;
					}
					SDL_Rect rect;
					CASE mycase = {id,id, 150, 150, x, y, img, rect , false};
					tab[id] = mycase;
					id++;
				}
			}	
		}else{
			for (int y = 0; y < size/3; ++y){
				for (int x = 0; x < size/3; ++x){
					char path[50];
					
					if (!game.isNumber){
						sprintf(path, "./src/img/%s/%d%d.jpg", name, y, x);
					}else if (game.isNumber){
						sprintf(path, "./src/img/%s/%d%d.png", "number/normal", y, x);
					}
					SDL_Texture *img = IMG_LoadTexture(app.renderer,path);
					if(!img){
						printf("IMG_Load: %s\n", IMG_GetError());
						return;
					}
					SDL_Rect rect;
					CASE mycase = {id,id, 300, 300, x, y, img, rect, false};
					tab[id] = mycase;
					id++;
				}
			}	
		}
	
}

void gameFunction(){
	int currentNull = game.difficulty.caseNbr - 1;
	SDL_DestroyTexture(game.tabCase[currentNull].img);
	game.tabCase[currentNull].isNull = true;

	if (!game.difficulty.isExtreme){
		for (int i = 0; i < 100; ++i){
			int casetoswap = rand() % 8;
			swapCase(currentNull, casetoswap);
			printf("\n");
		}

	}else if (game.difficulty.isExtreme){
		do{
			for (int i = 0; i < 500; ++i){
				int casetoswap = rand() % currentNull;
				swapCase(currentNull, casetoswap);
				printf("\n");
			}
		}while(!isSorted());
	}
	
}

void swapCase(int case1, int case2){
	int tempx = game.tabCase[case1].xpos;
	int tempy = game.tabCase[case1].ypos;
	int tempPlace = game.tabCase[case1].place;

	game.tabCase[case1].xpos = game.tabCase[case2].xpos;
	game.tabCase[case1].ypos = game.tabCase[case2].ypos;
	game.tabCase[case1].place = game.tabCase[case2].place;

	game.tabCase[case2].xpos = tempx;
	game.tabCase[case2].ypos = tempy;
	game.tabCase[case2].place = tempPlace;

}

void isSuccess(){
	int success = 0;
	for (int i = 0; i < game.difficulty.caseNbr; ++i){
		if (game.tabCase[i].id == game.tabCase[i].place){
			success++;
			//printf("%d\n",success ); //THIS IS FOR DEBUGGING
		}
	}
	
	if (success == 9 && game.difficulty.caseNbr == 9){
		displaySuccess();
		app.currentSCREEN = &menu;
		SDL_Delay(1000);
	}else if (success == 36 && game.difficulty.caseNbr == 36){
		displaySuccess();
		app.currentSCREEN = &menu;
		SDL_Delay(1000);
	}
}

void displaySuccess(){
	
	gameScreen.scene();
	SDL_RenderPresent(app.renderer);
	char path[50];
	if (!game.isNumber){
		sprintf(path, "./src/img/%s/full.jpg", game.difficulty.name);
	}else if (game.isNumber){
		if (game.difficulty.caseNbr > 9){
		sprintf(path, "./src/img/%s/full.png", "number/extreme");
		}else{
			sprintf(path, "./src/img/%s/full.png", "number/normal");
		}
	}
	SDL_Texture *img = IMG_LoadTexture(app.renderer,path);
	SDL_Rect logoRect; 
	logoRect.x = 0; 
	logoRect.y = 0; 
	logoRect.w = 900; 
	logoRect.h = 900;
	SDL_SetRenderDrawColor(app.renderer, grey.r, grey.g, grey.b, grey.a);
	SDL_RenderClear(app.renderer);
	SDL_RenderCopy(app.renderer, img, NULL, &logoRect);
	SDL_Delay(1000);
	SDL_RenderPresent(app.renderer);
	SDL_Delay(3000);
 	 
}

void gameClick(int i){
	if (game.difficulty.isEasy){
		CASE mycase = game.tabCase[i]; 
		swapCase(8, mycase.id);
	}else if (!game.difficulty.isEasy && !game.difficulty.isExtreme){
		CASE mycase = game.tabCase[i];
		if (mycase.xpos == game.tabCase[8].xpos || mycase.ypos == game.tabCase[8].ypos ){
			swapCase(8, mycase.id);
		}
		
	}else if (game.difficulty.isExtreme && game.difficulty.caseNbr == 36){
		CASE mycase = game.tabCase[i];
		if (mycase.xpos == game.tabCase[35].xpos+1 && mycase.ypos == game.tabCase[35].ypos || 
			mycase.xpos == game.tabCase[35].xpos-1 && mycase.ypos == game.tabCase[35].ypos ||
			mycase.ypos == game.tabCase[35].ypos+1 && mycase.xpos == game.tabCase[35].xpos ||
			mycase.ypos == game.tabCase[35].ypos-1 && mycase.xpos == game.tabCase[35].xpos ){
			swapCase(35, mycase.id);
		}
	}else if (game.difficulty.isExtreme && game.difficulty.caseNbr == 9){
		CASE mycase = game.tabCase[i];
		if (mycase.xpos == game.tabCase[8].xpos+1 && mycase.ypos == game.tabCase[8].ypos || 
			mycase.xpos == game.tabCase[8].xpos-1 && mycase.ypos == game.tabCase[8].ypos ||
			mycase.ypos == game.tabCase[8].ypos+1 && mycase.xpos == game.tabCase[8].xpos ||
			mycase.ypos == game.tabCase[8].ypos-1 && mycase.xpos == game.tabCase[8].xpos ){
			swapCase(8, mycase.id);
		}
	}
	
}

bool isSorted(){
	int sortedLevel = 0;
	for (int i = 0; i < game.difficulty.caseNbr; ++i){
		for (int j = 0; j < game.difficulty.caseNbr; ++j){
			if (game.tabCase[i].place > game.tabCase[j].place && game.tabCase[i].id < game.tabCase[j].id){
				sortedLevel++;
			}
		}
	}
	if (sortedLevel%2 == 0) return true;
	else return false;
}