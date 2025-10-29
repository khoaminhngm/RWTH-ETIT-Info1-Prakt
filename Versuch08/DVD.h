
#ifndef DVD_H_
#define DVD_H_

#include "Medium.h"

class DVD : public Medium {
public:
	DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);

	void ausgabe() const override;
	bool ausleihen(Person person, Datum ausleihedatum) override;

protected:
	int altersFreigabe;
	std::string genre;
};
#endif /* DVD_H_ */
