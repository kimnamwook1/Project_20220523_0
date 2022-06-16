#include "Text.h"
#include "Engine.h"


AText::AText(int NewX, int NewY, string NewMessage, SDL_Color NewColor, int NewSize)
{
	X = NewX;
	Y = NewY;
	Message = NewMessage;
	Color = NewColor;
	Size = NewSize;
	SortOrder = 100;

	
	Font = TTF_OpenFont("data/NanumGothicCoding.ttf", Size);

	Image = TTF_RenderText_Solid(Font, Message.c_str(), Color);
	
	Texture = SDL_CreateTextureFromSurface(GEngine->MyRenderer, Image);
	
	SDL_QueryTexture(Texture, nullptr, nullptr, &Width, &Height);

	Destination = { X,Y, Width, Height };
}

AText::~AText()
{
	TTF_CloseFont(Font);
}

void AText::Render()
{
	SDL_RenderCopy(GEngine->MyRenderer, Texture, nullptr, &Destination); // 원본사이즈 그대로 텍스트 사이즈 그대로 == 화면에 꽉차게
}
