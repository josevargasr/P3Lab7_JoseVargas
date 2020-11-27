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
using std::string;

class Persona {
public:
    Persona();
    Persona(string , string , string , int );
    Persona(const Persona& orig);
    string getNombre() const;
    string getPass() const;
    int getLlave() const;
    virtual ~Persona();
private:
    string nombre, apellido, pass;
    int llave;
};

#endif /* PERSONA_H */

