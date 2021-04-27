#include "include/libs.h"


void windowMain(){
	memset(&app, 0, sizeof(App));

	windowConfig();
	initSDL();

	
	int id = 0;
	
	mainMenu();
	
	while(true){
		void (*prepareScene)();
		doInput();

		switch(id){
			case 0:
				
				prepareScene = menu.scene;
				break;
			
			default:
				printf("error\n");
				id = 0;

		}

		prepareScene();
		SDL_RenderPresent(app.renderer);
	}
}

void windowConfig(){
	app.name = "My Window !!!";
	app.SCREEN_WIDTH = 800;
	app.SCREEN_HEIGHT = 600;
}

void initSDL(){
	int rendererFlags, windowFlags, imgFlags;

	rendererFlags = SDL_RENDERER_ACCELERATED;

	windowFlags = SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_MOUSE_FOCUS | SDL_WINDOW_RESIZABLE;

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
}

void doInput(){
	SDL_Event event;

	while (SDL_PollEvent(&event)){
		switch (event.type){
			case SDL_QUIT:
				exit(0);
				break;

			default:
				break;
		}
	}
}