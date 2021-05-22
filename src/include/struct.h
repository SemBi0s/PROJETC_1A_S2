/*
*
* GLOBAL
*
*/

typedef struct{
	int xpos;
	int ypos;
	int height;
	int width;
	int textSize;
	char *text;
	TTF_Font* textFont;
	SDL_Color textColor;
	SDL_Color color;
	SDL_Rect rect;
	SDL_Rect textrect;
	SDL_Texture* textTexture;
	void (*function)();
} Button;

typedef struct{
	int width;
	int height;
	SDL_Texture *img;
} Image;

/*
*
*	WINDOW RELATED
*
*/

typedef struct{
	int id;
	void (*scene)();
	void (*initButton)(Button *btn);
	int btnNbr;
	Button *btntab;
	Image* (*assets)();
	Image *astab;

} SCREEN;



extern SCREEN menu;
extern SCREEN levelSelection;
extern SCREEN gameScreen;
extern SCREEN rule;

typedef struct {
	char *name;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	SCREEN *currentSCREEN;
	SDL_Renderer *renderer;
	SDL_Window *window;
} App;
extern App app;





/*
*
*	GAME RELATED
*
*/

typedef struct{
	int id, place;
	int height;
	int width;
	int xpos, ypos;
	SDL_Texture *img;
	SDL_Rect rect;
	bool isNull;
} CASE;

typedef struct{
	char *name;
	int caseNbr;
	bool isEasy;
	bool isExtreme;

} DIFFICULTY;
extern DIFFICULTY easy;
extern DIFFICULTY medium;
extern DIFFICULTY hard;
extern DIFFICULTY extreme;

typedef struct{
	CASE *tabCase;
	DIFFICULTY difficulty;
	SCREEN screen;
	bool isNumber;
	void (*initCase)();

} GAME;
extern GAME game;
