/**
 * \file
 * \brief In dieser Datei werden die Funktionen der Klasse CSurfaceChild implementiert.
 *
 * \author Bodo Akdeniz
 * \date 01.04.05
 */

#include "surfacechild.h"

CSurfaceChild::CSurfaceChild(SDL_Surface *surface)
{
	SetDestinationSurface(surface);
}

CSurfaceChild::~CSurfaceChild()
{
}

void CSurfaceChild::SetDestinationSurface(SDL_Surface *dest)
{
	destination = dest;
}

void CSurfaceChild::SetPosition(int newx, int newy)
{
	x = newx;
	y = newy;
}

int CSurfaceChild::GetX()
{
	return x;
}

int CSurfaceChild::GetY()
{
	return y;
}

SDL_Surface *CSurfaceChild::GetDestinationSurface()
{
	return destination;
}
