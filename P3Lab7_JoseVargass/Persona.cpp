/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Persona.cpp
 * Author: josevargas
 * 
 * Created on November 27, 2020, 1:45 PM
 */

#include "Persona.h"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

Persona::Persona() {
}

Persona::Persona(string nombre, string apellido, string pass, int llave) {
    this->nombre = nombre;
    this->apellido = apellido;
    this-> pass= pass;
    this->llave = llave;
    
}

Persona::Persona(const Persona& orig) {
    this->nombre=orig.nombre;
    this->apellido=orig.apellido;
    this->pass=orig.pass;
    this->llave=orig.llave;
    
}

Persona::~Persona() {
}


string Persona::getNombre() const
{
	return nombre;
}

string Persona::getPass() const
{
	return pass;
}

int Persona::getLlave() const
{
	return llave;
}

vector<string> Persona::getMensajes() const
{
	return mensajes;
}

void Persona::setMensajes(string mensaje)
{
    mensajes.push_back(mensaje);
    
}

void Persona::printMensajes(){
    cout << "Bandeja: " << endl;
    for(int i = 0; i < mensajes.size(); i++)
        cout << "[" << i << "] " << mensajes[i] << endl;
}
