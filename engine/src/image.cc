/**
 * \file
 * \brief In dieser Datei werden die Funktionen der Klasse CImage implementiert.
 *
 * \author Bodo Akdeniz
 * \date 01.04.05
 */

#include "image.h"

CImage::CImage(SDL_Surface *dest) : CSurfaceChild(dest)
{
	SetSourceRect(NULL);
}

CImage::~CImage()
{
}

void CImage::LoadFromFile(std::string file)
{
	image = SDL_LoadBMP(file.c_str());
	if (image == NULL)
		filename = "";
	else
		filename = file;
}

void CImage::SetColorKey(Uint8 r, Uint8 g, Uint8 b)
{
	SDL_SetColorKey(image, SDL_SRCCOLORKEY, SDL_MapRGB(image->format, r, g, b));
}

void CImage::SetAlpha(Uint8 a)
{
	SDL_SetAlpha(image, SDL_SRCALPHA, a);
}

void CImage::SetImage(SDL_Surface *img)
{
	image = img;
}

void CImage::SetSourceRect(SDL_Rect *src)
{
	sourcerect = src;
}

void CImage::SetSourceRect(int rx, int ry, int rw, int rh)
{
	SDL_Rect src;
	src.x = rx;
	src.y = ry;
	src.w = rw;
	src.h = rh;
	SetSourceRect(&src);
}

void CImage::Draw()
{
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	SDL_BlitSurface(image, sourcerect, destination, &dest);
}

void CImage::Draw(int xpos, int ypos)
{
	SetPosition(xpos, ypos);
	Draw();
}

SDL_Surface *CImage::GetSurface()
{
	return image;
}
