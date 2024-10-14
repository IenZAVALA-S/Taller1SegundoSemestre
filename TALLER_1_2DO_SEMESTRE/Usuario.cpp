#include "Usuario.h"
#include <iostream>

Usuario::Usuario(std::string name, std::string id) {
	this->name = name;
	this->id = id;
	this->contMaterial = 0;
	
	for (int i = 0; i < 5; ++i) {
		materialesPrestados[i] = nullptr;
	}
}
bool Usuario::prestarMaterial(MaterialBib* material) {
	if (contMaterial < 5) {
		materialesPrestados[contMaterial] = material;
		contMaterial++;
		material->setStatus(true);
		return true;
	}
	return false;
}
bool Usuario::devolverMaterial(int isbn) {
	if (contMaterial == 0) { 
		return false; 
	}
	for (int i = 0; i < contMaterial; i++) {
		if (materialesPrestados[i]->getCode() == isbn) {
			materialesPrestados[i]->setStatus(false);
			for (int j = i; j < contMaterial - 1; j++) {
				materialesPrestados[j] = materialesPrestados[j + 1];
			}
			materialesPrestados[contMaterial - 1] = nullptr;  // Borra el último
			contMaterial--;
			return true;
		}
	}
	// Si llegamos aquí, significa que no se encontró el ISBN
	return false;
}

std::string Usuario::mostrarMaterialPrestado() {
	std::string info;
	if (contMaterial != 0) {
		for (int i = 0; i < contMaterial; i++) {
			info += materialesPrestados[i]->MostrarInformacion();
		}
	}
	else {
		info = name + "no cuenta con material prestado \n";
	}
	return info;
}
void Usuario::eliminarTodoMaterial() {
	for (int i = 0; i < contMaterial; i++) {
		materialesPrestados[i]->setStatus(false);
		materialesPrestados[i] = nullptr;
	}

}
std::string Usuario::getID() {
	return id;
}
std::string Usuario::getName() {
	return name;
}
MaterialBib* Usuario::getBorrowedMaterials(int x) {
		if (x < contMaterial && x >= 0) {
			return materialesPrestados[x];
		}
		return nullptr;
	}
int Usuario::getMaterialCount() {
	return contMaterial;
}
