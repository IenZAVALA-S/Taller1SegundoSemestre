#include "MaterialBibliogr�fico.h"
#include <iostream>

using namespace std;
MaterialBibliogr�fico::MaterialBibliogr�fico(string textName, string authorName, int isbn, bool borrow){
	this->textName = textName;
	this->authorName = authorName;
	this->isbn = isbn;
	this->borrow = borrow;
}

void MaterialBibliogr�fico::MostrarInformacion() {
	cout << "Nombre de la obra: " + textName << "\n"
		<< "Escrito por: " + authorName << "\n"
		<< "Codigo: " + isbn << "\n"
		<< "Disponibilidad: " << (borrow ? "prestado" : "disponible") << endl; //Mensaje cambia dependiendo si borrow es true (prestado) o false (disponible)
};
string MaterialBibliogr�fico::getTextName() {
	return textName;
}
string MaterialBibliogr�fico::getAuthorName() {
	return authorName;
}
int MaterialBibliogr�fico::getCode() {
	return isbn;
}
bool MaterialBibliogr�fico::getStatus() {
	return borrow;
}
void MaterialBibliogr�fico::setStatus(bool status) {
	this->borrow = status;
}