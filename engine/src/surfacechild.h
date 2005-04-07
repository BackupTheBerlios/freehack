/**
 * \file surfacechild.h
 * \brief In dieser Datei wird die Klasse CSurfaceChild definiert.
 *
 * \author Bodo Akdeniz
 */
#ifndef SURFACECHILD_H
#define SURFACECHILD_H

#include <SDL/SDL.h>
#include <string>

//! CSurfaceChild ist ein, in einem SDL_Surface,  positionnierbares Object.
/**
 * Von dieser Klasse werden alle anderen Objekte abgeleitet, die in ein SDL_Surface
 * (auch der Bildschirm ist in SDL ein SDL_Surface) gezeichnet werden und eine bestimmte
 * Position haben. Das dürfte auf alle Objekte zutreffen, die irgendwann auf dem
 * Bildschirm zu sehen sind.
 *
 * \author Bodo Akdeniz
 * \date 01.04.05
 * \version 0.1
 */
class CSurfaceChild
{
public:
	//! Das SDL_Surface in dem die Ausgabe stattfinden bzw. in dem gezeichnet wird.
	SDL_Surface *destination;
	
	//! Die x-Position des Objekts relativ zu \a destination.
	int x;
	
	//! Die y-Position des Objekts relativ zu \a destination.
	int y;

	
	//! Constuctor
	/**
	 * Initiert das Objekt und setzt \a destination auf \a surface.
	 * \param surface ist ein Zeiger auf das SDL_Surface auf dem dann gezeichnet werden soll.
	 */
	CSurfaceChild(SDL_Surface *surface);

	//! Destructor
	virtual ~CSurfaceChild();

	//! Setzt \a destination auf \a dest.
	/**
	 * Diese Funktion wird automatisch vom Constructor aufgerufen, und muss so,
	 * nur manuell aufgerufen werden, wenn \a destination nachträglich geändert werden soll.
	 * \sa CSurfaceChild()
	 */
	virtual void SetDestinationSurface(SDL_Surface *dest);

	//! Gibt die Position an, an der das Bild gespeichert werden soll.
	/**
	 * Die angegebene Position ist relativ zu der Position von \a destination.
	 * D.h, wenn \a destination auf dem Bildschirm die Position (10/20) hat,
	 * und SetPosition(5, 5) aufgerufen wird, wird auf dem Bildschirm (bei einem Aufruf von
	 * Draw()) an der Position (15/25) gezeichnet.
	 * \param newx ist die relative x-Position.
	 * \param newy ist die relative y-Position.
	 * \sa SetDestinationSurface()
	 */
	virtual void SetPosition(int newx, int newy);

	//! Gibt \a x zurück.
	/**
	 * \return Gibt die x-Position des Objekts zurück.
	 * \sa GetY()
	 */
	virtual int GetX();

	//! Gibt \a y zurück.
	/**
	 * \return Gibt die y-Position des Objekts zurück.
	 * \sa GetX()
	 */
	virtual int GetY();

	//! Gibt \a destination zurück.
	/**
	 * \return Gibt einen Zeiger auf das SDL_Surface zurück auf dem gezeichnet werden soll.
	 */
	virtual SDL_Surface *GetDestinationSurface();
};

#endif
