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
	if (!game.isNumber){
		if(size > 9){
		for (int y = 0; y < size/6; ++y){
			for (int x = 0; x < size/6; ++x){
				char path[50];
				sprintf(path, "./src/img/%s/%d%d.jpg", name, y, x);
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
					sprintf(path, "./src/img/%s/%d%d.jpg", name, y, x);
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
	if (game.isNumber){
		
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
				int casetoswap = rand() % 35;
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
			printf("%d\n",success );
		}
	}
	
	if (success == 9 && game.difficulty.caseNbr == 9){
		gameScreen.scene();
		SDL_RenderPresent(app.renderer);
		SDL_Delay(2000);
		app.currentSCREEN = &menu;
	}else if (success == 36 && game.difficulty.caseNbr == 36){
		gameScreen.scene();
		SDL_RenderPresent(app.renderer);
		SDL_Delay(2000);
		app.currentSCREEN = &menu;
	}
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
		
	}else if (game.difficulty.isExtreme){
		CASE mycase = game.tabCase[i];
		printf("%d\n",mycase.id );
		if (mycase.xpos == game.tabCase[35].xpos+1 && mycase.ypos == game.tabCase[35].ypos || 
			mycase.xpos == game.tabCase[35].xpos-1 && mycase.ypos == game.tabCase[35].ypos ||
			mycase.ypos == game.tabCase[35].ypos+1 && mycase.xpos == game.tabCase[35].xpos ||
			mycase.ypos == game.tabCase[35].ypos-1 && mycase.xpos == game.tabCase[35].xpos ){
			swapCase(35, mycase.id);
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
	printf("%d\n",sortedLevel );
	if (sortedLevel%2 == 0) return true;
	else return false;
}