// TALLER_1_2DO_SEMESTRE.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
#include "Libro.h"
#include "MaterialBib.h"
#include "Revista.h"
#include "Usuario.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
void cargarBiblioteca(MaterialBib* biblioteca[], int& contLibros) {
	// Abrir archivo para cargar los datos de la biblioteca
	ifstream archivo("biblioteca.txt");

	// Verificar si el archivo se abrió correctamente
	if (!archivo) {
		cout << "Error: No se abrió correctamente el archivo de la biblioteca" << endl;
		return;
	}

	// Definir variables para almacenar los valores leídos
	string linea, tipo, nombre, autor, variable1, variable2;
	int isbn;
	bool prestado;

	// Leer línea por línea del archivo
	while (getline(archivo, linea)) {
		// Convertir la línea en un flujo para procesar con comas
		stringstream ss(linea);

		// Leer el tipo de material (Libro o Revista)
		getline(ss, tipo, ',');
		getline(ss, nombre, ',');
		getline(ss, autor, ',');
		ss >> isbn;
		ss.ignore(1, ',');  // Ignorar la coma después del ISBN
		ss >> prestado;
		ss.ignore(1, ',');  // Ignorar la coma después del estado de préstamo

		// Dependiendo del tipo de material, cambiar las últimas 2 variables
		// Si es "Libro", se leen fecha de publicación y resumen
		if (tipo == "Libro") {
			getline(ss, variable1, ',');  // Leer fecha de publicación
			getline(ss, variable2);       // Leer resumen hasta el final de la línea
			biblioteca[contLibros] = new Libro(nombre, autor, isbn, variable1, variable2);
		}
		// Si es "Revista", se leen número de edición y mes de publicación
		else if (tipo == "Revista") {
			getline(ss, variable1, ',');  // Leer número de edición
			getline(ss, variable2);       // Leer mes de publicación hasta el final de la línea
			biblioteca[contLibros] = new Revista(nombre, autor, isbn, variable1, variable2);
		}

		// Establecer el estado de préstamo del material
		biblioteca[contLibros]->setStatus(prestado);

		// Incrementar el contador de libros en la biblioteca
		contLibros++;
	}

	// Cerrar el archivo después de cargar todos los materiales
	archivo.close();
}
void cargarUsuarios(Usuario* listaUser[], int& contUsuarios, MaterialBib* biblioteca[], int contLibros) {
	ifstream archivo("usuarios.txt");

	if (!archivo) {
		cerr << "Error al abrir el archivo de usuarios." << endl;
		return;
	}

	string nombre, id, materialName;
	int numMateriales;

	while (getline(archivo, nombre)) {
		getline(archivo, id);
		Usuario* user = new Usuario(nombre, id);

		// Se lee la cantidad de materiales prestados al usuario
		archivo >> numMateriales;
		archivo.ignore();  // Ignora el salto de línea después del número de materiales

		// Se leen solo los materiales prestados
		for (int j = 0; j < numMateriales; j++) {
			getline(archivo, materialName);
			for (int k = 0; k < contLibros; k++) {
				if (biblioteca[k]->getTextName() == materialName) {
					user->prestarMaterial(biblioteca[k]); // Agregra material a la lista del usuario
					break;
				}
			}
		}

		listaUser[contUsuarios] = user;
		contUsuarios++;
	}

	archivo.close();
}
bool agregarMaterial(int &contLibros, MaterialBib* biblioteca[]) {
	if (contLibros >= 100) {  // Capacidad máxima de 100
		cout << "Error: Capacidad máxima de la biblioteca alcanzada." << endl;
		return false;
	}

		int choice = 0;

		while (choice != 1 && choice != 2) {
			cout << "Por favor elija formato de material." << endl;
			cout << "1) Libro" << endl;
			cout << "2) Revista" << endl;
			cin >> choice;

			if (choice != 1 && choice != 2) {
				cout << "Error. Debe elegir solo 1 o 2." << endl;
			}
		}
		string bookName, authorName, variable1, variable2; //Inicializo vabriables fuera del switch, con variables que ambos formatos poseen como nombres de libro y autor
		//Y 2 variables no especificas para albergar aquellas que varían entre formatos.
		int isbn;
		switch (choice) {
		case 1:
		{

			cout << "Inserte nombre de la obra: " << endl;
			cin >> bookName;
			cout << "Inserte nombre del autor(a): " << endl;
			cin >> authorName;
			cout << "Inserte fecha de publicación, formato DD/MM/AAAA" << endl;
			cin >> variable1;
			cout << "Ingrese resumen del libro: " << endl;
			cin >> variable2;
			cout << "Ingrese isbn (solo números): " << endl;
			cin >> isbn;

			MaterialBib* libro = new Libro(bookName, authorName, isbn, variable1, variable2);
			biblioteca[contLibros] = libro;
			contLibros++;
			break;
		}
		case 2: {
			cout << "Inserte nombre de la obra: " << endl;
			cin >> bookName;
			cout << "Inserte nombre del autor(a): " << endl;
			cin >> authorName;
			cout << "Inserte edición, formato 1ra,2da,3ra, etc: " << endl;
			cin >> variable1;
			cout << "Ingrese més de lanzamiento: " << endl;
			cin >> variable2;
			cout << "Ingrese isbn (solo números): " << endl;
			cin >> isbn;

			MaterialBib* revista = new Revista(bookName, authorName, isbn, variable1, variable2);
			biblioteca[contLibros] = revista;
			contLibros++;
			break;
		 }
		}
		return true;

}
bool agregarUsuario(int &contUsuario, Usuario* listaUser[]) {
	if (contUsuario >= 100) {  // Capacidad máxima de 100
		cout << "Error: Capacidad máxima de usuarios alcanzada." << endl;
		return false;
	}
		cout << "Registrar Usuario" << "\n";
		string name, id;
		cout << "Ingrese nombre: " << "\n";
		cin >> name;
		cout << "Ingrese id: " << "\n";
		cin >> id;

		Usuario* user = new Usuario(name, id);
		listaUser[contUsuario] = user;
		contUsuario++;
		return true;

}
void mostrarMateriales(int contLibros, MaterialBib* biblioteca[]) {
	if (contLibros != 0) {
		for (int i = 0; i < contLibros; i++) {
			biblioteca[i]->MostrarInformacion();
		}
	}
	else {
		cout << "Error: Biblioteca actualmente vacía" << "\n";
	}
}
void showInfoOfTitleByAuthor(int contLibros, MaterialBib* biblioteca[], string name) {
	bool found = false;
	for (int i = 0; i < contLibros; i++) {
		if (biblioteca[i]->getAuthorName() == name) {
			biblioteca[i]->MostrarInformacion(); //He decidido mostrar la información a traves de la función para que no sea tan complejo
			found = true;
		}
	}
	if (!found) {
		cout << "Error: No se ha encontrado ningún libro por este autor. " << endl;
	}
}
int lookupByBookName(int contLibros, MaterialBib* biblioteca[], string name) {
	for (int i = 0; i < contLibros; i++) {
		if (biblioteca[i]->getTextName() == name) {
			return i;
		}
	}
	return -1;
}
int lookupUserByID(int contUsuario, Usuario* listaUser[], string id) {
	for (int i = 0; i < contUsuario; i++) {
		if (listaUser[i]->getID() == id) {
			return i;
		}
	}
	return -1;
}
bool borrowBook(int placeUser, Usuario* listaUser[], int placeBook, MaterialBib* biblioteca[]) {
	if (!biblioteca[placeBook]->getStatus()) {
		listaUser[placeUser]->prestarMaterial(biblioteca[placeBook]);
		return true;
	}
	return false;
}
bool returnBook(int placeUser, Usuario* listaUser[], int placeBook, MaterialBib* biblioteca[]) {
	if (biblioteca[placeBook]->getStatus()) {
		return listaUser[placeUser]->devolverMaterial(biblioteca[placeBook]->getCode());
	}
	return false;
}
bool eliminateUser(int& contUsuario, Usuario* listaUser[]) {
	string userID;
	cout << "Ingrese ID del Usuario: " << endl;
	cin >> userID;
	int userPos = lookupUserByID(contUsuario, listaUser, userID);
	if (userPos < 0) {
		return false;
	}
	Usuario* aux = listaUser[userPos];
	aux->eliminarTodoMaterial();
	for (int i = userPos; i < contUsuario; i++) {
		listaUser[i] = listaUser[i + 1];
	}
	contUsuario--;
	delete aux;
	return true;
}
void liberarMemoria(MaterialBib* biblioteca[], int contLibros, Usuario* listaUser[], int contUsuarios) {
	for (int i = 0; i < contLibros; i++) {
		delete biblioteca[i];
	}
	for (int i = 0; i < contUsuarios; i++) {
		delete listaUser[i];
	}
}
void guardarBiblioteca(MaterialBib* biblioteca[], int contLibros) {
	// Abrir archivo para guardar los datos de la biblioteca
	ofstream archivo("biblioteca.txt");

	// Verificar si el archivo se abrió correctamente
	if (!archivo) {
		cout << "Error: No se pudo abrir el archivo para guardar la biblioteca" << endl;
		return;
	}

	// Iterar sobre cada libro o revista en la biblioteca
	for (int i = 0; i < contLibros; i++) {
		// Guardar tipo de material: "Libro" o "Revista"
		archivo << biblioteca[i]->getType() << ",";

		// Guardar atributos comunes: nombre, autor, ISBN, estado de préstamo
		archivo << biblioteca[i]->getTextName() << ","
			<< biblioteca[i]->getAuthorName() << ","
			<< biblioteca[i]->getCode() << ","
			<< biblioteca[i]->getStatus() << ",";  // Estado de préstamo (0 = no prestado, 1 = prestado)

		// Si es un "Libro", guardar fecha de publicación y resumen
		if (biblioteca[i]->getType() == "Libro") {
			Libro* libro = static_cast<Libro*>(biblioteca[i]);
			archivo << libro->getPublishDate() << "," << libro->getSummary();
		}
		// Si es una "Revista", guardar número de edición y mes de publicación
		else if (biblioteca[i]->getType() == "Revista") {
			Revista* revista = static_cast<Revista*>(biblioteca[i]);
			archivo << revista->getEdition() << "," << revista->getReleaseMonth();
		}

		// Finalizar la línea para el siguiente material
		archivo << endl;
	}

	// Cerrar el archivo después de guardar todos los materiales
	archivo.close();
}
void guardarUsuarios(Usuario* listaUser[], int contUsuarios) {
	// Abrir archivo para guardar los datos de los usuarios
	ofstream archivo("usuarios.txt");

	// Verificar si el archivo se abrió correctamente
	if (!archivo) {
		cout << "Error al abrir el archivo de usuarios." << endl;
		return;
	}

	// Iterar sobre cada usuario en la lista
	for (int i = 0; i < contUsuarios; i++) {
		// Guardar el nombre y el ID del usuario
		archivo << listaUser[i]->getName() << "," << listaUser[i]->getID() << ",";

		// Guardar la cantidad de materiales prestados por el usuario
		int numMateriales = listaUser[i]->getMaterialCount();
		archivo << numMateriales << ",";

		// Guardar los nombres de los materiales prestados
		for (int j = 0; j < numMateriales; j++) {
			MaterialBib* material = listaUser[i]->getBorrowedMaterials(j);
			if (material) {
				archivo << material->getTextName();
				if (j < numMateriales - 1) {
					archivo << ",";  // Añadir una coma si no es el último material
				}
			}
		}

		// Finalizar la línea para el siguiente usuario
		archivo << endl;
	}

	// Cerrar el archivo después de guardar todos los usuarios
	archivo.close();
}

int main()
{
	int contLibros = 0;
	int contUsuario = 0;
	Usuario* listaUser[100] = {nullptr};
	MaterialBib* biblioteca[100] = {nullptr};
	cargarBiblioteca(biblioteca, contLibros);
	cargarUsuarios(listaUser, contUsuario, biblioteca, contLibros);
	int choice = 0;
	while (choice != 10) {

		cout << "Seleccione opción: " << "\n";
		cout << "1) Agregar material nuevo a biblioteca " << "\n";
		cout << "2) Agregar usuario a base de datos " << "\n";
		cout << "3) Mostrar información de materiales " << "\n";
		cout << "4) Buscar material por nombre " << "\n";
		cout << "5) Buscar material por autor " << "\n";
		cout << "6) Buscar usuario por ID y mostrar su material " << "\n";
		cout << "7) Prestar material a usuario " << "\n";
		cout << "8) Devolver material de usuario " << "\n";
		cout << "9) Eliminar usuario " << "\n";
		cout << "10) Guardar y cerrar programa " << "\n";
		cin >> choice;
		switch (choice) {

		case 1:
			if (agregarMaterial(contLibros, biblioteca)) {
				cout << "Material agregado con exito!" << "\n";
			}
			else {
				cout << "Error: Capacidad máxima alcanzada" << "\n";
			}
			break;
		case 2:
			if (agregarUsuario(contUsuario, listaUser)) {
				cout << "Usuario agregado con exito!" << "\n";
			}
			else {
				cout << "Error: Capacidad máxima alcanzada" << "\n";
			}
			break;
		case 3:
			mostrarMateriales(contLibros, biblioteca);
			break;
		case 4: {
			string name;
			cout << "Ingrese título del material a buscar: " << "\n";
			cin >> name;
			int x = lookupByBookName(contLibros, biblioteca, name);
			if (x >= 0) {
				biblioteca[x]->MostrarInformacion();
			}
			else {
				cout << "Error: Material no encontrado." << endl;
			}
			break;
		}
		case 5: {
			string name;
			cout << "Ingrese nombre del autor a buscar: " << "\n";
			cin >> name;
			showInfoOfTitleByAuthor(contLibros, biblioteca, name);
			break;
		}
		case 6: {
			string id;
			cout << "Ingrese ID del Usuario a buscar: " << "\n";
			cin >> id;
			int x = lookupUserByID(contUsuario, listaUser, id);
			if (x >= 0) {
				listaUser[x]->mostrarMaterialPrestado();
			}
			else {
				cout << "Error: Usuario no encontrado." << "\n";
			}
			break;
		}
		case 7: {
			string userID, bookName;
			cout << "Ingrese ID del Usuario: " << endl;
			cin >> userID;
			int userPos = lookupUserByID(contUsuario, listaUser, userID);
			if (userPos < 0) {
				cout << "Error: Usuario no encontrado." << endl;
				break;
			}

			cout << "Ingrese nombre del material a prestar: " << endl;
			cin >> bookName;
			int bookPos = lookupByBookName(contLibros, biblioteca, bookName);
			if (bookPos < 0) {
				cout << "Error: Material no encontrado." << endl;
				break;
			}

			if (borrowBook(userPos, listaUser, bookPos, biblioteca)) {
				cout << "Material prestado con éxito!" << endl;
			}
			else {
				cout << "Error: El material ya está prestado o no se puede prestar." << endl;
			}
			break;
		}
		case 8: {
			string userID, bookName;
			cout << "Ingrese ID del Usuario: " << endl;
			cin >> userID;
			int userPos = lookupUserByID(contUsuario, listaUser, userID);
			if (userPos < 0) {
				cout << "Error: Usuario no encontrado." << endl;
				break;
			}

			cout << "Ingrese nombre del material a devolver: " << endl;
			cin >> bookName;
			int bookPos = lookupByBookName(contLibros, biblioteca, bookName);
			if (bookPos < 0) {
				cout << "Error: Material no encontrado." << endl;
				break;
			}

			if (returnBook(userPos, listaUser, bookPos, biblioteca)) {
				cout << "Material devuelto con éxito!" << endl;
			}
			else {
				cout << "Error: El material no está prestado a este usuario." << endl;
			}
			break;
		}
		case 9:
			if (eliminateUser(contUsuario, listaUser)) {
				cout << "Usuario eliminado con éxito" << endl;
			}
			else {
				cout << "Error: Usuario no encontrado." << endl;
			}
			break;
		case 10:
			cout << "Muchas gracias por usar el servicio. Hasta luego!" << endl;
			break;
		default:
			cout << "Error: elija otra opción!" << endl;
		}
	}
	//Finalización del programa
	guardarBiblioteca(biblioteca, contLibros);
	guardarUsuarios(listaUser, contUsuario);
	liberarMemoria(biblioteca, contLibros, listaUser, contUsuario);
	
	return 0;

}

