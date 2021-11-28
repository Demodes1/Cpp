/* C++ proyect with sqlite 
Referecia tomada de Coding with Chapa https://www.youtube.com/watch?v=L-hnA82JsEM&t=1629s

Guillermo Esquivel Ortiz */

#include <iostream>
#include <stdio.h>
//#include "sqlite3.h"
#include <sqlite3.h>

using namespace std;

// Funciones para la creacion de la db y tablas

static int createDB(const char* s);
static int createTable(const char* s);
static int insertData(const char* s); 
static int updateData(const char* s); 
static int selectData(const char* s);
static int callback(void* NotUsed, int argc, char** argv, char** azColName);
 
int main(){
    const char* dir = "./databaseCpp.db";
    sqlite3* DB;

    createDB(dir);
    //createTable(dir);
    insertData(dir);
    selectData(dir);
    //updateData(dir);

    return 0;
}

// Abrir/Crear la base de datos
static int createDB(const char* s){
    sqlite3* DB;
    int exit = 0;

    exit = sqlite3_open(s, &DB);

    sqlite3_close(DB);
    return 0;
}

// Creamos tablas
static int createTable(const char* s){
    sqlite3* DB;

    // ********************** Error al crear la tabla *****************************
    string sql = "CREATE TABLE IF NOT EXIST ESTUDIANTE("
        "ID_A INTEGER PRIMARY KEY AUTOINCREMENT, "
        "NOMBRE     TEXT NOT NULL, "
        "CARRERA    TEXT NOT NULL, "
        "GUSTOS     TEXT NOT NULL, "
        "CALIF      INT NOT NULL);";

    // Checamos si hay algun error en la creacion de la tabla
    try {
        int exit = 0;
        exit = sqlite3_open(s, &DB);

        char* messageError;
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

        if (exit != SQLITE_OK){
            cerr << "Error al crear la tabla" << endl;
            sqlite3_free(messageError);
        } else {
            cout << "Se creo la tabla" << endl;
        }
        sqlite3_close(DB);
    } catch (const exception & e){
        cerr << e.what();
    }
    return 0;
}

// Agregamos la información
static int insertData(const char* s){
    sqlite3* DB;
    char* messageError;

    int exit = sqlite3_open(s, &DB);

    string sql(
        "INSERT INTO ESTUDIANTE (NOMBRE, CARRERA, GUSTO, CALIF) VALUES('Guillermo','IDM','Deporte', 9);"
        );

    exit = sqlite3_exec(DB,sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK){
        cerr << "Error al insertar los datos" << endl;
        sqlite3_free(messageError);
    } else {
        cout << "Se registraron los datos" << endl;
    }
    return 0;
}

// Seleccionamos la informacion para imprimirla 
static int selectData(const char* s){
    sqlite3* DB;
    int exit = sqlite3_open(s, &DB);

    string sql = "SELECT * FROM GRADES;";

    /* Se ejecuta la sentencia anterior llamando a la callback*/
    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);
    
    return 0;
}

// Recupera contenidos de la db usando selectData()
// argc: contiene el numero de resultados, azColName: contiene cada columna regresada en array, 
// argv: contiene cada valor en el array
static int callback(void* NotUsed, int argc, char** argv, char** azColName){
    for (int i = 0; i < argc; i++){
        // Nombre de la columna y valor
        cout << azColName[i] << ": " << argv[i] << endl;
    }
    cout << endl;
    return 0;
}

static int updateData(const char* s){
    sqlite3* DB;
    char* messageError;

    int exit = sqlite3_open(s, &DB);

    string sql("UPDATE ESTUDIANTE SET CARRERA = 'IDM' WHERE NOMBRE = 'Guillermo'");

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK) {
        cerr << "Error en el ingreso de datos" << endl;
        sqlite3_free(messageError);
    } else {
        cout << "Se edito correctamente!" << endl;
    }
    return 0;
}

