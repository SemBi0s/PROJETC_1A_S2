/*
*
* GLOBAL
*
*/

typedef struct{
	int r;
	int g;
	int b;
	int o;
} COLOR;


/*
*
*	WINDOW RELATED
*
*/

typedef struct {
	char *name;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	SDL_Renderer *renderer;
	SDL_Window *window;
} App;
extern App app;

typedef struct{
	int width;
	int height;
	SDL_Texture *img;
} Image;

typedef struct{
	int id;
	void (*scene)();
	Image* (*assets)();
	Image *astab;
} SCREEN;
extern SCREEN menu;

typedef struct{
	int xpos;
	int ypos;
	int height;
	int width;
	char *text;
	COLOR color;
	SDL_Rect rect;
} Button;


/*
*
*	GAME RELATED
*
*/



typedef struct{
	int id;
	int height;
	int width;
} CASE;
