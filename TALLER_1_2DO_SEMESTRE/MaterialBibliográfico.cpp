#include "MaterialBibliográfico.h"
#include <iostream>

using namespace std;
MaterialBibliográfico::MaterialBibliográfico(string textName, string authorName, int isbn, bool borrow){
	this->textName = textName;
	this->authorName = authorName;
	this->isbn = isbn;
	this->borrow = borrow;
}

void MaterialBibliográfico::MostrarInformacion() {
	cout << "Nombre de la obra: " + textName << "\n"
		<< "Escrito por: " + authorName << "\n"
		<< "Codigo: " + isbn << "\n"
		<< "Disponibilidad: " << (borrow ? "prestado" : "disponible") << endl; //Mensaje cambia dependiendo si borrow es true (prestado) o false (disponible)
};
string MaterialBibliográfico::getTextName() {
	return textName;
}
string MaterialBibliográfico::getAuthorName() {
	return authorName;
}
int MaterialBibliográfico::getCode() {
	return isbn;
}
bool MaterialBibliográfico::getStatus() {
	return borrow;
}
void MaterialBibliográfico::setStatus(bool status) {
	this->borrow = status;
}