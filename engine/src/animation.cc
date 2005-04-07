/**
 * \file
 * \brief In dieser Dateien werden die Funktionen von CAnimation implementiert.
 *
 * \author Bodo Akdeniz
 */

#include "animation.h"
#include <iostream>

CAnimation::CAnimation(SDL_Surface *dest) : CSurfaceChild(dest)
{
	running = false;
	defaultframe = 0;
	animationspeed = 1;
	delaytime = 500;
}

CAnimation::~CAnimation()
{
}

void CAnimation::SetAnimationspeed(float s)
{
	animationspeed = s;
}

float CAnimation::GetAnimationspeed()
{
	return animationspeed;
}

void CAnimation::SetDefaultFrame(int n)
{
	defaultframe = n;
}

int CAnimation::GetDefaultFrame()
{
	return defaultframe;
}

bool CAnimation::IsRunning()
{
	return running;
}

void CAnimation::Start()
{
	starttime = SDL_GetTicks();
	running = true;
}

void CAnimation::Stop()
{
	running = false;
}

void CAnimation::SetCurrentFrame()
{
	if (IsRunning())
	{
		SetPlaytime();
		currentframe = (int)(playtime%((int)round((float)delaytime*(float)ImageList.Count()*animationspeed))/delaytime);
	}
	else
	{
		currentframe = GetDefaultFrame();
	}
}

void CAnimation::SetPlaytime()
{
	playtime = SDL_GetTicks()-starttime;
}

void CAnimation::Draw()
{
	SetCurrentFrame();
	std::cout << "Aktueller Frame: " << currentframe << std::endl;
	ImageList[currentframe]->SetDestinationSurface(GetDestinationSurface());
	ImageList[currentframe]->SetPosition(GetX(), GetY());
	ImageList[currentframe]->Draw();
}
