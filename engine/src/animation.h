/**
 * \file
 * \brief In dieser Datei wird die Klasse CAnimation definiert.
 *
 * \author Bodo Akdeniz
 */

/**
 * \page CAnimation_Usage Die Benutzung von CAnimation
 * blabla bla
 */


// Beispiele

/**
 * \example CAnimation1.cc
 * Ein Beispiel für die Benutzung von CAnimation.
 */

#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL/SDL.h>
#include <cmath>  // Linker -lm übergeben

#include "surfacechild.h"
#include "image.h"
#include "list.h"

//! Die Klasse CAnimation dient dazu Animationen darzustellen.
/**
 * Die einzelnen Frames sind Objekte vom Typ CImage, die in
 * einer CList abgelegt sind.
 * Informationen zur Benutzung der Klasse finden sie auf der Seite
 * \ref CAnimation_Usage
 *
 * \author Bodo Akdeniz
 * \date 05.04.05
 * \version 0.3
 */
class CAnimation : public CSurfaceChild
{
public:
	//! Die Liste mit den Bildern.
	CList<CImage*> ImageList;

	//! Die Zeit die zwischen den Frames gewartet werden soll in Milisekunden
	int delaytime;
	
	//! \c true wenn die Animation gerade läuft, ansonsten \c false.
	bool running;
	
	//! Die Zeit seit SDL initialisiert wurde in Milisekunden. Wird benötigt um \a playtime zu berechnen.
	long starttime;

	//! Die Zeit, die die Animation schon läuft in Milisekunden.
	long playtime;

	//! Mit \a animationspeed kann die Geschwindigkeit, mit der die Animation läuft beeinflusst werden.
	/**
	 * Der Wert von \a animationspeed wird mit \a delaytime multipliziert.
	 * D.h. je kleiner der Wert, umso schneller läuft die Animation, je größer der Wert
	 * umso langsamer läuft sie.
	 */
	float animationspeed;

	//! Der Frame wird gezeichnet, wenn die Animation nicht läuft.
	int defaultframe;

	//! Aktueller Frame
	int currentframe;



	//! Constructor
	/**
	 * siehe CSurfaceChild(SDL_Surface *dest).
	 * Zusätzlich setzt die Funktion noch einige Defaultwerte der Variablen.
	 */
	CAnimation(SDL_Surface *dest);

	//! Destructor
	virtual ~CAnimation();



	//! Setzt \a animationspeed auf \a s.
	/**
	 * \sa GetAnimationspeed()
	 */
	virtual void SetAnimationspeed(float s);

	//! Gibt \a animationspeed zurück.
	/**
	 * \sa SetAnimationspeed()
	 */
	virtual float GetAnimationspeed();

	//! Setzt \a defaultframe auf \a n.
	/**
	 * \sa GetDefaultFrame()
	 */
	virtual void SetDefaultFrame(int n);

	//! Gibt \a defaultframe zurück.
	/**
	 * \sa SetDefaultFrame()
	 */
	virtual int GetDefaultFrame();

	//! Gibt den Wert von \a running zurück.
	/**
	 * \return gibt \c true zurück, wenn die Animation gerade
	 * läuft, ansonsten \c false.
	 */
	virtual bool IsRunning();

	

	//! Startet die Animation
	/**
	 * Die Funktion bereitet die Variablen vor und startet die Animation.
	 */
	void Start();

	//! Die Funktion stoppt beendet die Animation
	void Stop();
	
	//! Berechnet den aktuellen Frame und setzt \a currentframe.
	/**
	 * Die Funktion berrechnet den aktuellen Frame aus \a delaytime,
	 * \a playtime und der Anzahl der frames. Zuvor wird SetPlaytime() aufgerufen. \n
	 * Läuft die Animation nicht, wird \a currentframe auf \a defaultframe gesetzt. \n
	 * Um den Frame zu berrechnen wird folgende Formel verwendet:
	 * \f[
	 * frameno. = {playtime \bmod \left( framecount \cdot delaytime \right) \over delaytime}
	 * \f]
	 */
	virtual void SetCurrentFrame();

	//! Berechnet die Spielzeit
	/**
	 * Die Funktion berechnet die aktuelle Spielzeit, der Animation und setzt
	 * \a playtime entsprechend.
	 */
	virtual void SetPlaytime();

	//! Zeichnet den aktuellen Frame
	/**
	 * Die Funktion ruft zuerst SetCurrentFrame() auf und zeichnet dann
	 * das Bild des errechneten Frame in das Ausgabe-Suface, das mit
	 * CSurfaceChild::SetDestinationSurface() gesetzt wurde.
	 */
	void Draw();
};

#endif
