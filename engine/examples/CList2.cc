/* Ein weiteres Beispiel f�r CList.
 * 
 * Hier werden wie bei dem ersten Beispiel Eingaben entgegengenommen,
 * und in der Liste gespeichert. Wenn "." eingegeben wird wird die Eingabe-
 * schleife beendet und die Liste wird ausgegeben.
 * Der Unterschied zu dem ersten Beispielprogramm besteht darin, dass
 * die Liste aus Zeigern auf eine Klasse besteht.
 * In dem Fall kann man auch NULL zur Liste hinzuf�gen, und den das
 * Objekt erst sp�ter anlegen, was in diesem Beispiel gezeigt wird.
 */

#include <string>
#include <iostream>
#include "../src/list.h"

class contact {
public:
	std::string name;
	std::string phonenumber;

	contact() {
	}

	contact(std::string n, std::string p) {
		name = n;
		phonenumber = p;
	}
};

int main()
{
	CList<contact*> contacts;
	std::string name, phone;
	unsigned int i;

	while (1)
	{
		std::cout << "Name: ";
		std::cin >> name;

		if (name == ".")
			break;
		
		std::cout << "Phone: ";
		std::cin >> phone;
		contacts.Add(NULL);
		contacts[contacts.Count()-1] = new contact(name, phone);
	}

	for (i=0; i<contacts.Count(); i++)  // von 0 bis [Anzahl der Listenelemente]
	{
		std::cout << (i+1) << ". Name: " << contacts[i]->name << std::endl;
		std::cout << (i+1) << ". Phone: " << contacts[i]->phonenumber << std::endl << std::endl;;
	}
}
