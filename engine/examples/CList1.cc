/* Beispielprogramm f�r CList.
 *
 * Es werden Eingaben entgegen genommen, die in der Liste gespeichert werden.
 * Bei der Eingabe eines Punktes wird die Liste ausgegeben und das Programm
 * beendet.
 */

#include <string>
#include <iostream>
#include "../src/list.h"  // Enth�lt CList

int main()
{
	CList<std::string> liste;  // Ein Liste aus std::string-Elementen
	std::string temp;
	unsigned int i;

	while (1)
	{
		std::cout << "Eingabe: ";
		std::cin >> temp;
		if (temp == ".")
			break;
		liste.Add(temp);
	}

	for (i=0; i<liste.Count(); i++)  // von 0 bis [Anzahl der Listenelemente]
	{
		std::cout << (i+1) << ": " << liste[i] << std::endl;
	}

	return 0;

}
