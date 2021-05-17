#include "include/libs.h"

void prepareBtnRendering(Button *btn){
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(btn->textFont, btn->text, btn->textColor); 
	SDL_Texture* Message = SDL_CreateTextureFromSurface(app.renderer, surfaceMessage);
	btn->textTexture = Message;
	SDL_QueryTexture(btn->textTexture, NULL, NULL, &btn->textrect.w, &btn->textrect.h);
	SDL_FreeSurface(surfaceMessage);
}

void renderBtn(Button *btn){
	SDL_SetRenderDrawColor(app.renderer, btn->color.r, btn->color.g, btn->color.b, btn->color.a);
	SDL_RenderFillRect(app.renderer, &btn->rect);
	SDL_RenderCopy(app.renderer, btn->textTexture, NULL, &btn->textrect);
	SDL_DestroyTexture(btn->textTexture);
}