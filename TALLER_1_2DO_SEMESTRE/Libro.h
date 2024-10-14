#pragma once
#include <iostream>
#include "MaterialBib.h";


class Libro : public MaterialBib {
private:
	std::string publishDate, summary;
public:
	Libro(std::string bookName, std::string authorName, int isbn, std::string publishDate, std::string summary);
	std::string MostrarInformacion();
	std::string getPublishDate();
	std::string getSummary();
	
};

