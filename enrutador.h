#ifndef ENRUTADOR_H
#define ENRUTADOR_H
#include <iostream>
#include <map>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include<cmath>
#include <vector>

using namespace std;

class Enrutador
{
private:
    map<char,int> router;
    map<char,int>:: iterator it;
public:
    bool Agregar_Enlace(char nombre,int valor);
    bool Eliminar_Enlace(char nombre);
    bool Modificar_Enlace(char nombre,int value);
    void Imprimir();
    void Matriz_Ady();
    int DijKstra(int **matriz,char **Matriz2, int, int,char *definitivos);
};

#endif // ENRUTADOR_H
