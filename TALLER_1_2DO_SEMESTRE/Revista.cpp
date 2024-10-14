#include "Revista.h"
#include "MaterialBib.h"
#include <iostream>
#include <string>

using namespace std;
Revista::Revista(string bookName, string authorName, int isbn, string edition, string releaseMonth) {
	this->textName = textName;
	this->authorName = authorName;
	this->isbn = isbn;
	borrow = false;
	this->releaseMonth = releaseMonth;
	this->edition = edition;
    type = "Revista";
}
string Revista::MostrarInformacion() {
    string info = "Nombre de la revista: " + textName + "\n" +
        "Escrito por: " + authorName + "\n" +
        "Código: " + to_string(isbn) + "\n" +
        "Disponibilidad: " + (borrow ? "prestado" : "disponible") + "\n" +
        "Edición n°: " + edition + "\n" +
        "Publicada durante: " + releaseMonth + "\n";

    return info;
}
string Revista::getEdition() {
    return edition;
}
string Revista::getReleaseMonth() {
    return releaseMonth;
}