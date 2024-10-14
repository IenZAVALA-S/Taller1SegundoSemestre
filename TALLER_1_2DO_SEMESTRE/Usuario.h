#pragma once
#include "MaterialBib.h"
#include <iostream>

class Usuario
{
private:
	std::string name,id;
	MaterialBib* materialesPrestados[5];
	int contMaterial;
public:
	Usuario(std::string name, std::string id);
	bool prestarMaterial(MaterialBib* material);
	bool devolverMaterial(int isbn);
	std::string mostrarMaterialPrestado();
	std::string getName();
	std::string getID();
	MaterialBib* getBorrowedMaterials(int x);
	int getMaterialCount();
	void eliminarTodoMaterial();
};

