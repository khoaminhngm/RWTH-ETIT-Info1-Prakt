
#ifndef MAGAZIN_H_
#define MAGAZIN_H_

#include "Medium.h"
#include "Datum.h"

class Magazin : public Medium {
public:
	Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);

	void ausgabe() const override;
	bool ausleihen(Person person, Datum ausleihedatum) override;

protected:
	Datum datumAusgabe;
	std::string sparte;
};




#endif /* MAGAZIN_H_ */
