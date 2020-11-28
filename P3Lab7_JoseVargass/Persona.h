/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Persona.h
 * Author: josevargas
 *
 * Created on November 27, 2020, 1:45 PM
 */

#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

class Persona {
public:
    Persona();
    Persona(string , string , string , int );
    Persona(const Persona& orig);
    string getNombre() const;
    string getPass() const;
    int getLlave() const;
    vector<string> getMensajes() const;
    void setMensajes(string);
    void printMensajes();
    virtual ~Persona();
private:
    vector<string> mensajes;
    string nombre, apellido, pass;
    int llave;
};

#endif /* PERSONA_H */

