/**
 * \file
 * \brief Diese Datei definiert die Klasse CImage, welche dazu dient, Bilder zu laden
 * und zu zeichnen.
 *
 * Um sie zu nutzen ben�tigt man SDL.
 *
 * \author Bodo Akdeniz
 */

#ifndef IMAGE_H
#define IMAGE_H

#include <SDL/SDL.h>
#include <string>

#include "surfacechild.h"

//! Klasse zum laden/zeichnen von Bildern.
/**
 * Eine Klasse um ein Bild (Bitmap) zu laden, speichern und zu zeichnen.
 * Transparenz wird sowohl durch einen "Colorkey" als auch durch einen
 * Alphawert unterst�tzt.
 * 
 * \author Bodo Akdeniz
 * \date 01.04.05
 * \version 0.2
 */
class CImage : public CSurfaceChild
{
public:
	// Variables
	
	//! Zeigt auf das SDL_Surface des Bildes.
	SDL_Surface *image;
	//! Definiert eine Rechteckige Fl�che von \a image, die gezeichnet werden soll. Ist \a sourcerect NULL wird, bei einem Aufruf von Draw(), image komplett gezeichnet.
	SDL_Rect *sourcerect;
	//! Der Dateiname des geladenen Bildes. Kann auch leer sein, wenn \a image durch SetImage() gesetzt wurde.
	std::string filename;
	
	// Initiation, etc.
	
	//! Constructor
	/**
	 * Wird beim initiieren der Klasse aufgerufen und setzt das
	 * Surface auf dem gezeichnet werden soll.
	 *
	 * \param dest ist ein Zeiger auf das SDL_Surface, auf dem
	 * 	bei einem Aufruf von Draw(), gezeichnet werden soll.
	 * \sa SetDestinationSurface()
	*/
	CImage(SDL_Surface *dest);
	//! Destructor
	virtual ~CImage();

	// Input Functions
	
	//! L�d ein Bild.
	/**
	 * LoadFromFile() l�d ein Bitmap in image, das dann verwendet werden kann.
	 * Tritt ein Fehler auf ist \a image NULL und \a filename leer.
	 * \sa SetImage()
	 */
	virtual void LoadFromFile(std::string file);

	//! Setzt die Farbe die transparent dargestellt werden soll.
	/**
	 * Setzt die Farbe, die beim zeichnen mit Draw() nicht gezeichnet werden soll,
	 * also transparent dargestellt wird.
	 * \param r bestimmt den Rotanteil der Farbe. (0=kein Rot bis 255=Sehr Rot)
	 * \param g bestimmt den Gr�nanteil der Farbe. (0=kein Gr�n bis 255=Sehr Gr�n)
	 * \param b bestimmt den Blauanteil der Farbe. (0=kein Blau bis 255=Sehr Blau)
	 * \sa SetAlpha()
	 */
	virtual void SetColorKey(Uint8 r, Uint8 g, Uint8 b);

	//! Setzt den Grad der Transparenz.
	/**
	 * \param a bestimmt den Grad der Transparenz. (0=keine Transparenz bis 255=unsichtbar)
	 * \sa SetColorKey()
	 */
	virtual void SetAlpha(Uint8 a);

	//! Setzt \a image.
	/**
	 * Die Funktion kann verwendet werden, wenn direkt ein SDL_Surface �bergeben werden und
	 * kein Bild aus einer Datei geladen werden soll.
	 * Um ein Bild aus einer Datei zu laden verwenden sie bitte LoadFromFile().
	 * \param img ist ein Zeiger auf das SDL_Surface, das als \a image verwendet werden soll.
	 * \sa LoadFromFile()
	 */
	virtual void SetImage(SDL_Surface *img);

	//! Gibt ein Rechteck von \a image an, das gezeichnet werden soll.
	/**
	 * Diese Funktion kann verwendet werden, wenn nur ein Teil, von \a image
	 * gezeichnet werden soll.
	 * Soll \a image komplett gezeichnet werden, kann f�r \a src NULL �bergeben werden, das
	 * ist aber sofern es nicht manuell ge�ndert wurde, sowiso so.
	 * \param  src ist ein Zeiger auf ein SDL_Rect, und bestimmt ein Rechteck von \a image.
	 * \sa SetSourceRect(int, int, int, int)
	 */
	virtual void SetSourceRect(SDL_Rect *src);

	//! Gibt ein Rechteck von \a image an, das gezeichnet werden soll.
	/**
	 * Die Funktion hat die selbe Funktionalit�t wie SetSourceRect(SDL_Rect *),
	 * nur kann man hier die Koordinaten, L�nge und Breite direkt �bergeben.
	 * \param rx ist die x-Koordinate des Rechtecks innerhalb von \a image.
	 * \param ry ist die y-Koordinate des Rechtecks innerhalb von \a image.
	 * \param rw ist die Breite des Rechtecks.
	 * \param rh ist die H�he des Rechtecks.
	 * \sa SetSourceRect(SDL_Rect *)
	 */
	virtual void SetSourceRect(int rx, int ry, int rw, int rh);

	// Output Functions
	
	//! Zeichnet \a image.
	/**
	 * Die Funktion zeichnet den, mit SetSourceRect() angegebenen Teil, von \a image
	 * an die mit SetPosition() festgelegte Position in das SDL_Surface, das beim
	 * initialisieren mit CImage() oder manuell mit SetDestinationSurface(),
	 * angegeben wurde.
	 * \sa SetSourceRect()
	 * \sa SetPosition
	 * \sa CImage()
	 * \sa SetDestinationSurface()
	 * \sa Draw(int, int)
	 */
	virtual void Draw();

	//! Zeichnet \a image an die (\a xpos/\a ypos).
	/**
	 * Genauso wie Draw(), nur dass davor SetPosition(xpos, ypos) aufgerufen wird.
	 * \sa Draw()
	 * \sa SetPositino()
	 */
	virtual void Draw(int xpos, int ypos);

	//! Gibt \a image zur�ck.
	/**
	 * Gibt einen Zeiger auf das SDL_Surface zur�ck, das das zu zeichnende Bild enth�lt.
	 * \return Zeiger auf das SDL_Surface, das das Bild enth�lt (\a image).
	 */
	virtual SDL_Surface *GetSurface();
};

#endif
