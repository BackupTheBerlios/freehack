/* Beispiel zur Benutzung von CAnimation.
 *
 * Es werden 2 Bilder geladen und der Animation hinzugef�gt, und die
 * Spielschleife wird gestartet.
 * jetzt kann durch dr�cken der Leertaste die Animation gestartet und gestoppt
 * werden. Beendet wird das Programm mit [ESC].
 * Es wird davon ausgegangen, dass der grunds�tzliche Umgang mit SDL
 * bekonnt ist.
 */

#include <SDL/SDL.h>
#include <iostream>

#include "../src/animation.h"		// f�r CAnimation
#include "../src/image.h"	// f�r CAnimationImage

int main()
{
	SDL_Surface *screen;
	int done=0;
	CAnimation *animation;		// Unsere Animation
	CImage *pic1, *pic2;	// Die 2 Bilder f�r die Animation
	
	// SDL stuff
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_NOPARACHUTE) < 0)
	{
		std::cout << "Unable to init SDL: " << SDL_GetError() << std::endl;
		return 1;
	}
	atexit(SDL_Quit);

	if ((screen=SDL_SetVideoMode(200, 200, 32, SDL_HWSURFACE|SDL_DOUBLEBUF)) == NULL)
	{
		std::cout << "Unable to set videomode: " << SDL_GetError() << std::endl;
		return 1;
	}
	
	
	// Bilder laden
	
	/* Was hier als Ausgabe �bergeben wird ist egal, da es sowiso von
	 * CAnimation �berschrieben wird, wenn man das Bild hinzuf�gt.
	 * Man darf nur nicht  versuchen das Bild selbst zu zeichnen.
	 */
	pic1 = new CImage(NULL);  
	pic1->LoadFromFile("../images/examples/zahnrad1.bmp");

	pic2 = new CImage(NULL);
	pic2->LoadFromFile("../images/examples/zahnrad2.bmp");

	
	// Animation vorbereiten
	animation = new CAnimation(screen);  // initialisierung; Ausgabe soll auf screen stattfinden
	animation->ImageList.Add(pic1);
	animation->ImageList.Add(pic2);
	animation->SetAnimationspeed(0.8);
	animation->SetPosition(0, 0);

	while (done == 0)  // Spielschleife
	{
		SDL_Event event;
		// Events abarbeiten
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				done = 1;
			
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
					done = 1;
				if (event.key.keysym.sym == SDLK_SPACE)
				{
					if (animation->IsRunning())
						animation->Stop();
					else
						animation->Start();
				}
			}
		}
	
		animation->Draw();  // aktuelles Bild der Animation zeichnen
		
		SDL_Flip(screen);  // Bild aktualisieren
	}
}
