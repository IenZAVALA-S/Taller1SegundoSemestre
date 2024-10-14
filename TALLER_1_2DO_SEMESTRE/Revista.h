#pragma once
#include "MaterialBib.h"

class Revista : public MaterialBib
{
private: 
	std::string edition, releaseMonth;
public:
	Revista(std::string bookName, std::string authorName, int isbn, std::string edition, std::string releaseMonth);
	std::string MostrarInformacion();
	std::string getEdition();
	std::string getReleaseMonth();

};

