/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: josevargas
 *
 * Created on November 27, 2020, 1:18 PM
 */

#include <iostream>
#include <time.h> 
#include <string>
#include <vector>
#include "Persona.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

/*
 * 
 */
int main(int argc, char** argv) {
    srand(time(0));
    vector<Persona> usuarios;
    bool loop1 = true;
    while (loop1) {
        int opcion = 0;
        cout << "      MENU" << endl
                << "1. Registrarse" << endl
                << "2. Ingresar" << endl
                << "3. Salir" << endl
                << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
            {
                string nombre = "", apellido = "", pass = "";
                cout << "Ingrese su nombre: ";
                cin >> nombre;
                cout << "Ingrese su apellido: ";
                cin >> apellido;
                cout << "Ingrese su contraseña: ";
                cin >> pass;
                Persona persona(nombre, apellido, pass, rand() % 15 + 1);
                cout << "Su usuario es: \n"
                        "Nombre: " << persona.getNombre() << "\n" <<
                        "Apellido: " << apellido << "\n" <<
                        "Contraseña: " << persona.getPass() << endl;
                usuarios.push_back(persona);
                cout << endl;

                break;
            }
            case 2:
            {
                int posicion;
                bool logged = false;
                Persona p_logged;
                string log_nombre = "", log_pass = "";
                cout << "Ingrese su nombre: ";
                cin >> log_nombre;
                cout << "Ingrese su contraseña: ";
                cin >> log_pass;
                for (int i = 0; i < usuarios.size(); i++) {
                    Persona temporal = usuarios[i];
                    if (log_nombre == temporal.getNombre() && temporal.getPass() == log_pass) {
                        posicion = i;
                        p_logged = temporal;
                        logged = true;
                        break;
                    }

                }
                if (logged) {
                    cout << endl;
                    bool loop2 = true;
                    while (loop2) {
                        int opcion2 = 0;

                        cout << "Bienvenid@ " << p_logged.getNombre() << endl
                                << "1. Enviar mensaje" << endl
                                << "2. Ver mensajes" << endl
                                << "3. Ver mi llave" << endl
                                << "4. Salir" << endl
                                << "Ingrese una opcion: ";
                        cin >> opcion2;
                        switch (opcion2) {
                            case 1:
                            {
                                int pos_recibidor = 0;
                                string mensaje = "";
                                for (int i = 0; i < usuarios.size(); i++) {
                                    Persona temporal = usuarios[i];
                                    cout << "[" << i << "] " << temporal.getNombre() << endl;
                                }
                                cout << "Ingrese el numero del contacto a enviar: ";
                                cin >> pos_recibidor;
                                cout << "Ingrese su mensaje: ";
                                cin >> mensaje;
                                Persona temp2 = usuarios[pos_recibidor];
                                temp2.setMensajes(mensaje);
                                temp2.printMensajes();
                                vector<string> vtemp = temp2.getMensajes();
                                ((Persona)usuarios[pos_recibidor]).setMensajes(vtemp[0]);
                                cout << "El mensaje fue enviado con éxito" << endl;
                                cout << endl;
                                break;
                            }
                            case 2:
                            {
                                int pos_mensaje = 0;
                                usuarios[posicion].printMensajes();
                                cout << "Ingrese el mensaje que desea ver: ";
                                cin >> pos_mensaje;

                                cout << endl;
                                break;
                            }
                            case 3:
                            {
                                cout << "Su llave es: " << p_logged.getLlave() << endl;
                                cout << endl;
                                break;
                            }
                            case 4:
                            {
                                loop2 = false;
                                break;
                            }
                        }
                    }
                } else
                    cout << "Usuario o contraseña incorrecto" << endl;
                cout << endl;
                break;
            }
            case 3:
            {
                loop1 = false;
                break;
            }
        }
    }
    return 0;
}



