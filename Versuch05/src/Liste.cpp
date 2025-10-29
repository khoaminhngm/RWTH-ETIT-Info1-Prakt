//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, back, nullptr);

    if (front == nullptr)                                       // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        back->setNext(neuesElement);
        back = neuesElement;


    }
}


/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */

void Liste::pushFront(Student pData) {

	ListenElement* neuesElement = new ListenElement(pData, nullptr, front);

	if (back == nullptr) {
		front = neuesElement;
		back = neuesElement;
	}
	else {
		 front->setPrev(neuesElement);
		 front = neuesElement;
	}
}


/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
    ListenElement* cursor = front;

    if (front == back)                                       // Liste enth�lt nur ein Listenelement
    {
        delete front;                                        // Listenelement l�schen
        front = nullptr;
        back = nullptr;
    }
    else
    {
        front = front->getNext();
        front->setPrev(nullptr); // löscht Dangling Pointer
        delete cursor;
    }
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if(front == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataFront()
{
    return front->getData();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getNext();
    }
}


/**
 * @brief Ausgabe der Liste vom letzten bis zum ersten Element.
 *
 * @return void
 */
void Liste::ausgabeRueckwaerts() const {
	ListenElement* cursor = back;

	while (cursor != nullptr) {
		cursor->getData().ausgabe();
		cursor = cursor->getPrev();
	}
}


/**
 * @brief Sucht nach einem Listenelement mit einer bestimmten Matrikelnummer.
 *
 * @param matNrInput Die gesuchte Matrikelnummer.
 * @return Ein Zeiger auf das gefundene Listenelement, oder nullptr falls nicht gefunden.
 */
ListenElement* Liste::findByMatNr(unsigned int matNrInput) {

	for (ListenElement* current = front; current != nullptr; current = current->getNext()) {
		if (current->getData().getMatNr() == matNrInput) {
			return current;
		}
	}
	std::cout << "Ihre eingegebene Matrikelnummer ist nicht in unserer Datenbank." << std::endl << std::endl;
	return nullptr;
}


/**
 * @brief Sucht nach einem Studenten mit einer bestimmten Matrikelnummer.
 *
 * @param matNrInput Die gesuchte Matrikelnummer.
 * @return Das Student-Objekt mit der gesuchten Matrikelnummer.
 * @throws Ohne spezielle Fehlermeldung, falls die Matrikelnummer nicht gefunden wird.
 */
Student Liste::findMatNr(unsigned int matNrInput) {

	for (ListenElement* current = front; current != nullptr; current = current->getNext()) {
		if (current->getData().getMatNr() == matNrInput) {
			return current->getData();
		}
	}
	throw;
}


/**
 * @brief Löscht ein bestimmtes Listenelement aus der Liste.
 *
 * Entfernt das übergebene Listenelement aus der Liste und gibt den zugehörigen Speicher frei.
 *
 * @param loeschAdresse Zeiger auf das zu löschende Listenelement.
 */
void Liste::loeschen(ListenElement* loeschAdresse) {
	ListenElement* current = loeschAdresse;

	if (!current) {
		return;
	}

	if (current == front) {
		popFront();
		return;
	}

	if (current == back) {
		back = current->getPrev();
	}

	if (current->getPrev()) {
		current->getPrev()->setNext(current->getNext());
	}

	if (current->getNext()) {
		current->getNext()->setPrev(current->getPrev());
	}

	delete current;
}
