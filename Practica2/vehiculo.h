#ifndef VEHICULO_H
#define VEHICULO_H

#include "QString" //para que no salte fallo en los tipos que vienen de la interfaz
#include <iostream>
#include <string>
using namespace std;

class Vehiculo
{
private:

    QString nombreVehiculo;
    QString numeroRuedas;
    double cv;
    string motor;
    string combustible;
    string color;
    QString tipoCombustible;
    string alas;
    string reactores;
    string locomotora;
    string trenDeAterrizaje;
    int vagones;
    QString placaDeMatricula;
    string Tipo;
    string pinchazo;




public:
    Vehiculo(QString nombreVehiculo, QString numeroRuedas, int cv, string motor, string combustible, string color, QString tipoCombustible, string alas
             , string reactores, string locomotora, string trenDeAterrizaje, int  vagones, QString placaDeMatricula, string pinchazo);

        /* GETTERS */

    string getTipoVehiculo(); //para ponerlo en el JLabel, puesto que el TipoDeVehiculo lo settea internamente
    QString getNombreVehiculo();
    QString getNumeroRuedas();
    int getCv();
    string getMotor();
    string getCombustible();
    string getColor();
    QString getTipoCombustible();
    string getAlas();
    string getReactores();
    string getLocomotora();
    string getTrenDeAterrizaje();
    int getVagones();
    QString getPlacaDeMatricula();
    string getTipo();
    string getPinchazo();


         /* OTRAS FUNCIONES */

    bool TipoDeVehiculo();

    bool esBicicleta();
    bool esTriciclo();
    bool esMotocicleta();
    bool esCoche();
    bool esCocheDeportivo();
    bool esAvion();
    bool esTren();

};

#endif // VEHICULO_H
