
#ifndef BUCH_H_
#define BUCH_H_

#include "Medium.h"

class Buch : public Medium {
public:
	// Konstruktor
	Buch(std::string initTitel, std::string initAutor);

	void ausgabe() const override;

protected:
	std::string autor;
};
#endif
