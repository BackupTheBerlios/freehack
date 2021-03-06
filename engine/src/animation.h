/**
 * \file
 * \brief In dieser Datei wird die Klasse CAnimation definiert.
 *
 * \author Bodo Akdeniz
 */

/**
 * \page CAnimation_Usage Die Benutzung von CAnimation
 * Mit einem Objekt vom Typ CAnimation k�nnen Animationen erstellt,
 * und dargestellt werden. Es ist von CSurfaceChild abgeleitet und
 * kann somit in einem SDL_Surface positionniert werden. \n
 * Der grobe Ablaut bei der Benutzung von CAnimatin d�rfte ungef�hr
 * so aussehen:
 *
 * -# Anlegen eines Objekts
 * -# Hinzuf�gen von Einzelbildern
 * -# ggf. noch ein paar "Feineinstellungen" (Geschwindigkeit etc.)
 * -# ggf. Play() oder Stop() ausf�hren (in der Spielschleife)
 * -# Zeichnen (in der Spielschleife)
 *  
 * Durch den Aufruf von Draw() wird automatisch der Frame
 * ermittelt der gezeichnet werden soll, somit muss man sich als
 * Benutzer der Klasse mit solchen dingen nicht mehr rum�rgern. \n
 * Ein Beispielprogramm gibts in der Datei \ref CAnimation1.cc \n
 * Das Programm l�d 2 Bilder in die Animation und startet bzw. stoppt
 * sie mit einem Druck auf die Leertaste.\n
 * Die Bilder werden erst in CImage-Objekte geladen und dann CAnimation
 * hinzugef�gt.
 * Das muss man nicht unbedingt so machen. Folgender Codeausschnitt l�d
 * die Bilder direkt �ber CAnimation.
 * \code
 * CAnimation *anim;
 * anim->ImageList.Add(NULL);
 * anim->ImageList[0]->LoadFromFile("pic1.bmp");
 * anim->ImageList.Add(NULL);
 * anim->ImageList[1]->LoadFromFile("pic2.bmp");
 * \endcode
 * \todo Das kleine Code-Beispiel sollte man vllt. noch testen.
 */


// Beispiele

/**
 * \example CAnimation1.cc
 * Ein Beispiel f�r die Benutzung von CAnimation.
 */

#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL/SDL.h>
#include <cmath>  // Linker -lm �bergeben

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
	
	//! \c true wenn die Animation gerade l�uft, ansonsten \c false.
	bool running;
	
	//! Die Zeit seit SDL initialisiert wurde in Milisekunden. Wird ben�tigt um \a playtime zu berechnen.
	long starttime;

	//! Die Zeit, die die Animation schon l�uft in Milisekunden.
	long playtime;

	//! Mit \a animationspeed kann die Geschwindigkeit, mit der die Animation l�uft beeinflusst werden.
	/**
	 * Der Wert von \a animationspeed wird mit \a delaytime multipliziert.
	 * D.h. je kleiner der Wert, umso schneller l�uft die Animation, je gr��er der Wert
	 * umso langsamer l�uft sie.
	 */
	float animationspeed;

	//! Der Frame wird gezeichnet, wenn die Animation nicht l�uft.
	int defaultframe;

	//! Aktueller Frame
	int currentframe;



	//! Constructor
	/**
	 * siehe CSurfaceChild(SDL_Surface *dest).
	 * Zus�tzlich setzt die Funktion noch einige Defaultwerte der Variablen.
	 */
	CAnimation(SDL_Surface *dest);

	//! Destructor
	virtual ~CAnimation();



	//! Setzt \a animationspeed auf \a s.
	/**
	 * \sa GetAnimationspeed()
	 */
	virtual void SetAnimationspeed(float s);

	//! Gibt \a animationspeed zur�ck.
	/**
	 * \sa SetAnimationspeed()
	 */
	virtual float GetAnimationspeed();

	//! Setzt \a defaultframe auf \a n.
	/**
	 * \sa GetDefaultFrame()
	 */
	virtual void SetDefaultFrame(int n);

	//! Gibt \a defaultframe zur�ck.
	/**
	 * \sa SetDefaultFrame()
	 */
	virtual int GetDefaultFrame();

	//! Gibt den Wert von \a running zur�ck.
	/**
	 * \return gibt \c true zur�ck, wenn die Animation gerade
	 * l�uft, ansonsten \c false.
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
	 * L�uft die Animation nicht, wird \a currentframe auf \a defaultframe gesetzt. \n
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
