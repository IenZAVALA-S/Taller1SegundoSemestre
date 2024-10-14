#pragma once
#include <string>
#include <iostream>

class MaterialBibliográfico
{
protected:
	std::string textName, authorName;
	int isbn;
	bool borrow; //true if borrowed, false if still in inventory.

public:
	MaterialBibliográfico(std::string textName, std::string authorName, int isbn, bool borrow);
	std::string getTextName();
	std::string getAuthorName();
	int getCode();
	bool getStatus();
	virtual void MostrarInformacion();
	void setStatus(bool status);

};

