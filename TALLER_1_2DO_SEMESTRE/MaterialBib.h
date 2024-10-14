#pragma once
#include <iostream>

class MaterialBib
{
protected:
	std::string textName, authorName, type;
	int isbn;
	bool borrow; //true if borrowed, false if still in inventory.

public:
	MaterialBib();
	MaterialBib(std::string textName, std::string authorName, int isbn, bool borrow);
	std::string getTextName();
	std::string getAuthorName();
	std::string getType();
	int getCode();
	bool getStatus();
	virtual std::string MostrarInformacion();
	void setStatus(bool status);

};
