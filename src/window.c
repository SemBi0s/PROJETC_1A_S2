#include "include/libs.h"

#ifndef FRAMERATE
#define FRAMERATE 60
#endif

void windowMain(){
	memset(&app, 0, sizeof(App));

	windowConfig();
	initSDL();
	
	mainMenu();
	mainLevelSelector();
	mainGame();
	
	while(true){
		void (*prepareScene)();
		doInput();

		switch(app.currentSCREEN->id){
			case 0:
				prepareScene = menu.scene;
				break;
			case 1:
				prepareScene = levelSelection.scene;
				break;
			case 2:
				prepareScene = gameScreen.scene;
				break;
			default:
				printf("error\n");
				app.currentSCREEN->id = 0;
				break;

		}
		prepareScene();
		SDL_RenderPresent(app.renderer);
		SDL_Delay(FRAMERATE);
	}
}

void windowConfig(){
	app.name = "My Window !!!";
	app.SCREEN_WIDTH = 900;
	app.SCREEN_HEIGHT = 900;
	app.currentSCREEN = &menu;
}

void initSDL(){
	int rendererFlags, windowFlags, imgFlags;

	rendererFlags = SDL_RENDERER_ACCELERATED;

	windowFlags = SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_MOUSE_FOCUS | SDL_WINDOW_BORDERLESS ;

	imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;

	if (SDL_Init(SDL_INIT_VIDEO) < 0){
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	app.window = SDL_CreateWindow(app.name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, app.SCREEN_WIDTH, app.SCREEN_HEIGHT, windowFlags);

	if (!app.window){
		printf("Failed to open %d x %d window: %s\n", app.SCREEN_WIDTH, app.SCREEN_HEIGHT, SDL_GetError());
		exit(1);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

	if (!app.renderer){
		printf("Failed to create renderer: %s\n", SDL_GetError());
		exit(1);
	}
	if(!(IMG_Init(imgFlags)&imgFlags)){
		printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
    }
    if (TTF_Init() != 0){
    	printf("Couldn't init TTF %s\n", TTF_GetError());
    }

   // app.currentSCREENid = 0;
}

void doInput(){
	SDL_Event event;
	int mouseX, mouseY;

	while (SDL_PollEvent(&event)){
		switch (event.type){
			case SDL_QUIT:
				exit(0);
				break;

			case SDL_MOUSEBUTTONDOWN:
				SDL_GetMouseState(&mouseX,&mouseY);
				if (app.currentSCREEN->id == 2){
					if(mouseX > 0 && mouseY > 0 && mouseX < app.SCREEN_WIDTH && mouseY < app.SCREEN_HEIGHT){
					caseClick( mouseX ,mouseY);
					}
				}else{
					if(mouseX > 0 && mouseY > 0 && mouseX < app.SCREEN_WIDTH && mouseY < app.SCREEN_HEIGHT){
					buttonClick(*app.currentSCREEN, mouseX ,mouseY);
					}
				}
				
				break;

			case SDL_WINDOWEVENT:
				switch(event.window.event){
					case SDL_WINDOWEVENT_RESIZED:
						SDL_GetRendererOutputSize(app.renderer, &app.SCREEN_WIDTH, &app.SCREEN_HEIGHT);
						break;
				}

			default:
				break;
		}
	}
}

void buttonClick(SCREEN screen, int x, int y){
	void (*BTNFunc)();
	for (int i = 0; i < screen.btnNbr; ++i){
		if (x > screen.btntab[i].rect.x && y > screen.btntab[i].rect.y && x < (screen.btntab[i].rect.x + screen.btntab[i].width) && y < (screen.btntab[i].rect.y + screen.btntab[i].height) ){
			BTNFunc = screen.btntab[i].function;
			BTNFunc();
		}
	}
}

void caseClick(int x, int y){
	for (int i = 0; i < game.difficulty.caseNbr; ++i){
		if (x > game.tabCase[i].rect.x && y > game.tabCase[i].rect.y && x < (game.tabCase[i].rect.x + game.tabCase[i].width) && y < (game.tabCase[i].rect.y + game.tabCase[i].height) ){
			 gameClick(i);
		}
	}
	isSuccess();
}