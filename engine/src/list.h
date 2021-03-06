/**
 * \file
 * \brief In dieser Datei wird die Klasse CList definiert \b und implementiert.
 *
 * Aus irgendwelchen mir bis jetzt nicht verst�ndlichen Gr�nden, k�nnen
 * Templateklassen wohl nicht (wie �blich) in zwei Dateien aufgeteilt werden.
 * Aus diesem Grund werden die Funktionen der Klasse CList in dieser Datei nicht
 * nur deklariert, sondern auch implementiert.
 * Die Datei list.cc ist nur vorhanden, um die Struktur einheitlich zu gestalten,
 * in ihr wird nur diese Datei includiert, dass man wie gewohnt kompilieren kann.
 * 
 * \author Bodo Akdeniz
 */

/**
 * \page clist_usage Die Benutzung von CList
 * CList ist von std::vector abgeleitet und hat deshalb auch genau die selben
 * Eigenschaften und Funktionen. Man kann CList genauso wie std::vector benutzen,
 * allerdings wurden auch neue Funktionen hinzugef�gt, die allerdings nur
 * dazu dienen, den Aufruf der Vektorklasse passender zu den restlichen Funktionen
 * zu gestalten.
 * 
 * \section einfacheliste Eine einfache Liste
 * Eine Neue Liste legt man mit
 * \code
 * CList<type> liste;
 * \endcode
 * an. \c type muss durch den Variablentyp ersetzt werden, von dem die Elemente
 * der Liste sein sollen.
 * Dann kann man mit
 * \code
 * liste.Add(object);
 * \endcode
 * Objekte (vom Typ \c type) in die List aufnehmen.\n
 * Der Aufruf der einzelnen Listenelemente erfolgt wie bei einem Array mit
 * \code
 * liste[elementnummer];
 * \endcode
 * \c elementnummer geht dabei von 0 bis \c liste.Count()-1.
 * \code
 * liste.Count();
 * \endcode
 * gibt die Anzahl der Elemente, die in der Liste gespeichert sind zur�ck.
 * Die Nummer des gr��en Elements ist folglich \c liste.Count()-1, da
 * das erste Element die Nummer \a 0 hat. \n
 * \n
 * Ein Beispiel befindet sich in der Datei \ref CList1.cc
 *
 * \section zeigerliste Eine Liste aus Zeigern
 * Eine Liste kann nat�rlich auch aus Zeigern bestehen. In diesem Fall kann man
 * der Liste auch \c NULL hinzuf�gen. D.h. das Objekt, das man der Liste hinzuf�gen
 * will muss noch nicht existieren und kann erst im nachhinein erstellt werden.
 * Au�erdem muss bei komplexen Objekten nicht das ganze Objekt kopiert werden,
 * da in der Liste ja nur ein Zeiger auf das Objekt gespeichert wird.
 * \code
 * myobject object1, *object2;
 * CList<myobject*> liste;
 * // Nullzeiger hinzuf�gen
 * liste.Add(NULL);
 * liste[liste.Count()-1] = new myobject;
 * //Zeiger auf Objekt hinzuf�gen
 * liste.Add(&object1);
 * liste.Add(object2);
 * \endcode
 * Ein Beispiel dazu befindet sich in der Datei \ref CList2.cc
 */


// Beispiele

/**
 * \example CList1.cc
 * Ein Beispiel f�r die Benutzung von CList.
 */

/**
 * \example CList2.cc
 * Ein Beispiel f�r die Benutzung von CList.
 */

#ifndef LIST_H
#define LIST_H

#include <vector>

// CList ist eine Vektorklasse.
/**
 * Die Klasse ist von std::vector abgeleitet und bietet dieselbe
 * Funktionalit�t. Sie wird nur definiert, um einen besser zu den anderen Klassen
 * passenderen Klassennamen und passendere Funktionsnamen zu haben.
 *
 * \author Bodo Akdeniz
 * \date 02.04.05
 * \version 0.1
 */
template <class T> class CList : public std::vector<T>
{
public:
	//! F�gt ein Objekt am Ende der Liste hinzu
	/**
	 * \param obj Ein Objekt vom Typ T
	 */
	inline void Add(T obj) {
		push_back(obj);
	}

	//! L�scht die gesamte Liste
	/**
	 */
	inline void Clear() {
		clear;
	}

	//! Gibt die Anzahl der Elemente zur�ck, die in der Liste gespeichert sind
	/**
	 * \return die Funktion gibt die Anzahl der Listenelemente zur�ck.
	 */
	inline int Count() {
		return size();
	}
};

#endif
