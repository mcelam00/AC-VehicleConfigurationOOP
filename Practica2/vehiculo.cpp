#include "vehiculo.h"

Vehiculo::Vehiculo(QString nombreVehiculo, QString numeroRuedas, int cv, string motor, string combustible, string color, QString tipoCombustible, string alas
                   , string reactores, string locomotora, string trenDeAterrizaje, int  vagones, QString placaDeMatricula, string pinchazo)
{
        /* ASIGNO LOS PARAMETROS QUE VIENEN DE LA INTERFAZ A LOS ATRIBUTOS DEL OBJETO*/


    this->nombreVehiculo = nombreVehiculo;
    this->numeroRuedas = numeroRuedas;
    this->cv = cv;
    this->motor = motor;
    this->combustible = combustible;
    this->color = color;
    this->tipoCombustible = tipoCombustible;
    this->alas = alas;
    this->reactores = reactores;
    this->locomotora = locomotora;
    this->trenDeAterrizaje = trenDeAterrizaje;
    this->vagones = vagones;
    this->placaDeMatricula = placaDeMatricula;
    this->pinchazo = pinchazo;

}


string Vehiculo::getTipoVehiculo()
{
    return this->Tipo;
}

QString Vehiculo::getNombreVehiculo()
{
    return this->nombreVehiculo;
}

QString Vehiculo::getNumeroRuedas()
{
    return this->numeroRuedas;
}

int Vehiculo::getCv()
{
    return this->cv;
}

string Vehiculo::getMotor()
{
    return this->motor;
}

string Vehiculo::getCombustible()
{
    return this->combustible;
}

string Vehiculo::getColor()
{
    return this->color;
}

QString Vehiculo::getTipoCombustible()
{
    return this->tipoCombustible;
}

string Vehiculo::getAlas()
{
    return this->alas;
}

string Vehiculo::getReactores()
{
    return this->reactores;
}

string Vehiculo::getLocomotora()
{
    return this->locomotora;
}

string Vehiculo::getTrenDeAterrizaje()
{
    return this->trenDeAterrizaje;
}

int Vehiculo::getVagones()
{
    return this->vagones;
}

QString Vehiculo::getPlacaDeMatricula()
{
    return this->placaDeMatricula;
}

string Vehiculo::getTipo()
{
    return this->Tipo;
}

string Vehiculo::getPinchazo()
{
    return this->pinchazo;
}


bool Vehiculo::TipoDeVehiculo() //si la configuracion de vehiculo corresponde a otro, no se guardara el vehiculo, por lo tanto retornamos false y se borrara el objeto y se mostrara una alerta
{
    bool seGuarda = true;


    if (esBicicleta() == true)
    {

        this->Tipo = "Bicicleta";

    }
    else if(esTriciclo() == true)
    {

        this->Tipo = "Triciclo";

    }
    else if(esMotocicleta() == true)
    {

        this->Tipo = "Motocicleta";

    }
    else if(esCoche() == true)
    {

        this->Tipo = "Coche";

    }
    else if(esCocheDeportivo() == true)
    {

        this->Tipo = "Coche Deportivo";

    }
    else if(esAvion() == true)
    {

        this->Tipo = "Avion";

    }
    else if(esTren() == true)
    {

        this->Tipo = "Tren";

    }
    else
    {
      seGuarda = false;
    }

    return seGuarda;

}

bool Vehiculo::esBicicleta()
{
    bool bicicleta = false;

    if(this->numeroRuedas.compare("2") == 0 && this->motor.compare("No") == 0 && this->combustible.compare("No") == 0 && this->alas.compare("No") == 0 && this->reactores.compare("No") == 0 && this->trenDeAterrizaje.compare("No") == 0 && this->locomotora.compare("No") == 0 && this->vagones == 0 && this->pinchazo.compare("Kit Repara Pinchazos") == 0)
    {
        bicicleta = true;
    }

    return bicicleta;
}

bool Vehiculo::esTriciclo()
{
    bool triciclo = false;

    if(this->numeroRuedas.compare("3") == 0 && this->motor.compare("No") == 0 && this->combustible.compare("No") == 0 && this->alas.compare("No") == 0 && this->reactores.compare("No") == 0 && this->trenDeAterrizaje.compare("No") == 0 && this->locomotora.compare("No") == 0 && this->vagones == 0 && this->pinchazo.compare("Kit Repara Pinchazos") == 0)
    {
        triciclo = true;
    }

    return triciclo;
}

bool Vehiculo::esMotocicleta()
{
    bool motocicleta = false;

    if(this->numeroRuedas.compare("2") == 0 && this->motor.compare("Si") == 0 && (this->cv >= 80 && this->cv <= 450) && this->combustible.compare("Si") == 0 && (this->tipoCombustible.compare("Electrico") == 0 || this->tipoCombustible.compare("Gasolina") == 0 || this->tipoCombustible.compare("Gasoleo") == 0 || this->tipoCombustible.compare("Hibrido") == 0) && this->alas.compare("No") == 0 && this->reactores.compare("No") == 0 && this->trenDeAterrizaje.compare("No") == 0 && this->locomotora.compare("No") == 0 && this->vagones == 0 && this->pinchazo.compare("Kit Repara Pinchazos") == 0)
    {
        motocicleta = true;
    }

    return motocicleta;
}

bool Vehiculo::esCoche()
{
    bool coche = false;

    if(this->numeroRuedas.compare("4") == 0 && this->motor.compare("Si") == 0 && (this->cv >= 80 && this->cv <= 250) && this->combustible.compare("Si") == 0 && (this->tipoCombustible.compare("Electrico") == 0 || this->tipoCombustible.compare("Gasolina") == 0 || this->tipoCombustible.compare("Gasoleo") == 0 || this->tipoCombustible.compare("Hibrido") == 0) && this->alas.compare("No") == 0 && this->reactores.compare("No") == 0 && this->trenDeAterrizaje.compare("No") == 0 && this->locomotora.compare("No") == 0 && this->vagones == 0 && this->pinchazo.compare("Rueda De Recambio") == 0)
    {
        coche = true;
    }

    return coche;
}

bool Vehiculo::esCocheDeportivo()
{
    bool cocheDeportivo = false;

    if(this->numeroRuedas.compare("4") == 0 && this->motor.compare("Si") == 0 && (this->cv >= 250 && this->cv <= 450) && this->combustible.compare("Si") == 0 && (this->tipoCombustible.compare("Electrico") == 0 || this->tipoCombustible.compare("Gasolina") == 0) && this->alas.compare("No") == 0 && this->reactores.compare("No") == 0 && this->trenDeAterrizaje.compare("No") == 0 && this->locomotora.compare("No") == 0 && this->vagones == 0 && this->pinchazo.compare("Kit Repara Pinchazos") == 0)
    {
        cocheDeportivo = true;
    }

    return cocheDeportivo;
}

bool Vehiculo::esAvion()
{
    bool avion = false;

    if(this->numeroRuedas.compare("6") == 0 && this->motor.compare("Si") == 0 && this->cv == 450 && this->combustible.compare("Si") == 0 && this->tipoCombustible.compare("Queroseno") == 0 && this->color.compare("Blanco") == 0 && this->alas.compare("Si") == 0 && this->reactores.compare("Si") == 0 && this->trenDeAterrizaje.compare("Si") == 0 && this->locomotora.compare("No") == 0 && this->vagones == 0 && this->pinchazo.compare("Rueda De Recambio") == 0)
    {
        avion = true;
    }

    return avion;
}

bool Vehiculo::esTren()
{
    bool tren = false;

    if(this->numeroRuedas.compare("40") == 0 && this->motor.compare("Si") == 0 && this->cv == 450 && this->combustible.compare("Si") == 0 && (this->tipoCombustible.compare("Electrico") == 0 || this->tipoCombustible.compare("Gasoleo") == 0) && this->color.compare("Negro") == 0 && this->alas.compare("No") == 0 && this->reactores.compare("No") == 0 && this->trenDeAterrizaje.compare("No") == 0 && this->locomotora.compare("Si") == 0 && (this->vagones >= 5 && this->vagones <= 20) && this->pinchazo.compare("Rueda De Recambio") == 0)
    {
        tren = true;
    }

    return tren;
}
