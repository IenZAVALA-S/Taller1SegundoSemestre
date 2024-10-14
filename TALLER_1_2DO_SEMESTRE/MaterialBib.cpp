#include "MaterialBib.h"
#include <iostream>
#include <string>
using namespace std;

MaterialBib::MaterialBib() {
	textName = "Blank";
	authorName = "Blank";
	isbn = 0;
	borrow = false;
}
MaterialBib::MaterialBib(string textName, string authorName, int isbn, bool borrow) {
	this->textName = textName;
	this->authorName = authorName;
	this->isbn = isbn;
	this->borrow = borrow;
}

string MaterialBib::MostrarInformacion() {
	string info;
	info = "Nombre de la obra: " + textName + "\n" +
		"Escrito por: " + authorName + "\n" +
		"Código: " + to_string(isbn) + "\n" +
		"Disponibilidad: " + (borrow ? "prestado" : "disponible") + "\n"; // Mensaje cambia dependiendo del estado de borrow

	return info;
}
string MaterialBib::getTextName() {
	return textName;
}
string MaterialBib::getAuthorName() {
	return authorName;
}
int MaterialBib::getCode() {
	return isbn;
}
bool MaterialBib::getStatus() {
	return borrow;
}
string MaterialBib::getType() {
	return type;
}
void MaterialBib::setStatus(bool status) {
	this->borrow = status;
}