#include "Libro.h"
#include "MaterialBib.h"
#include <iostream>
#include <string>
using namespace std;

Libro::Libro(string bookName, string authorName, int isbn, string publishDate, string summary) {
	this->textName = textName;
	this->authorName = authorName;
	this->isbn = isbn;
	borrow = false;
	this->publishDate = publishDate;
	this->summary = summary;
    type = "Libro";
}

string Libro::MostrarInformacion() {
    std::string info;
    info = "Nombre del libro: " + textName + "\n" +
        "Escrito por: " + authorName + "\n" +
        "Código: " + to_string(isbn) + "\n" +
        "Disponibilidad: " + (borrow ? "prestado" : "disponible") + "\n" +
        "Fecha de publicación: " + publishDate + "\n" +
        "Resumen: " + summary + "\n";

    return info;
}
string Libro::getPublishDate() {
    return publishDate;
}
string Libro::getSummary() {
    return summary;
}