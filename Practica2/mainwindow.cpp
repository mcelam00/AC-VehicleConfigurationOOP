#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vehiculo.h" //para poder utilizar los objetos de la clase vehiculo


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->hide(); //escondo la barra de progreso de la matricula nada mas salir el programa (ui puntero para acceder a la interfaz)
    this->contadorVehiculosConfigurados = 0; //inicializo a 0 el contador de vehiculos grafico
    ui->comboBox->addItem("");


}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_GenerarMatricula_clicked()   //cuando dé en generar la matrícula viene aquí
{

    //lo primero voy a mostrar la barra de progreso
    ui->progressBar->setValue(0);
    ui->progressBar->show();
    for(int i = 0; i <= 100; i++)
    {
        ui->progressBar->setValue(i);
    }


    //llamo a la funcion que genera cada digito aleatorio de la matricula
     srand(time(NULL));

    int digito1 = this->GenerarNumeroAleatorio(0,9); //Lo hago de uno en uno porque si no, si me genera el 3 no es 0003 sino 3
    int digito2 = this->GenerarNumeroAleatorio(0,9);
    int digito3 = this->GenerarNumeroAleatorio(0,9);
    int digito4 = this->GenerarNumeroAleatorio(0,9);

    //ahora creo las letras aleatorias

    string letras = CalcularLetrasAleatorias();

    string matricula = "";

    matricula = to_string(digito1) + to_string(digito2) + to_string(digito3) + to_string(digito4) + " " + letras;


    //la ponemos en el label, para eso hay que cambiar el formato a Qstring y empleo la conversion

    QString Qmatricula = QString::fromStdString(matricula);

    ui->MatriculaGenerada->setText(Qmatricula); //lo pongo en el label



}


int MainWindow::GenerarNumeroAleatorio(int min, int max)
{
    return rand() % (max-min+1) + min;
}



string MainWindow::CalcularLetrasAleatorias()
{
    //Defino un vector con las letras que me valen (salvo las vocales y la ñ, todas) y mi cadena retorno

    string letrasDisponibles = "BCDFGHJKLMNPQRSTVWXYZ";
    string cadenaADevolver = "";

    char letra1 = letrasDisponibles[GenerarNumeroAleatorio(0,20)];
    char letra2 = letrasDisponibles[GenerarNumeroAleatorio(0,20)];
    char letra3 = letrasDisponibles[GenerarNumeroAleatorio(0,20)];

    cadenaADevolver.push_back(letra1); //como son char para anexarlos a la cadena uso el pushback
    cadenaADevolver.push_back(letra2);
    cadenaADevolver.push_back(letra3);

    return cadenaADevolver;
}


void MainWindow::on_GuardarVehiculo_clicked() //cuando dé un toque en el boton de guardar entramos en este método
{

   bool erroresEntrada = false;

       /* RECOLECCION DE DATOS DE LA INTERFAZ*/

                /* Si el nombre se deja vacio que salte el mensaje de advertencia y no se guarde */

        QString nombreVehiculo = "";

        if(ui->IntroducirNombre->text().compare("") == 0)
        {
            erroresEntrada = true;
        }
        else
        {
            nombreVehiculo = ui->IntroducirNombre->text();
        }


    QString numeroRuedas = ui->NumRuedasCombo->currentText();

    int cv = 0;  //si no tiene motor la potencia queda en 0
    string motor = "No";

        if(ui->Motor_Si->isChecked() == true)
        {
            //si tiene motor se mira el LCD
            cv = ui->Pantallita->value();
            motor = "Si";
        }


    QString tipoCombustible = ""; //si no tiene combustible no se puede seleccionar el tipo
    string combustible = "No";

        if(ui->Comb_Si->isChecked() == true)
        {
            tipoCombustible = ui->TipoCombustibleCombo->currentText();
            combustible = "Si";
        }


    string alas = "No";

        if(ui->Alas_Si->isChecked() == true)
        {

            alas = "Si";

        }


    string reactores = "No";

        if(ui->Reactores_Si->isChecked() == true)
        {

            reactores = "Si";

        }

    string locomotora = "No";

        if(ui->Loco_Si->isChecked() == true)
        {

            locomotora = "Si";

        }

    string trenDeAterrizaje = "No";

        if(ui->TrenDeAt_Si->isChecked() == true)
        {

            trenDeAterrizaje = "Si";

        }

    int numVagones = 0;

        if(ui->Vagones_Si->isChecked() == true)
        {

            numVagones = ui->SeleccionDeVagones->value();

        }

            /* Si la matricula no se genera que salte el mensaje y no se guarde */

        QString placaDeMatricula = "";

        if(ui->MatriculaGenerada->text().compare("") == 0)
        {
            erroresEntrada = true;
        }
        else
        {
            placaDeMatricula = ui->MatriculaGenerada->text();

        }



    string pinchazo = "Rueda De Recambio";

        if(ui->KRP->isChecked() == true)
        {

            pinchazo = "Kit Repara Pinchazos";

        }


    string color = "";


            /* Si el color no se ha pinchado que salte el mensaje y no se guarde */

        if(colorSeleccionado.size() == 0) //vector vacio porque no se ha pinchado ningun boton
        {

            erroresEntrada = true;

        }
        else  //hay un color seleccionado
        {
            color = colorSeleccionado[0];
        }

        /* CREACIÓN DEL VEHÍCULO */

    Vehiculo *vehiculoConfigurado = new Vehiculo(nombreVehiculo, numeroRuedas, cv, motor, combustible, color, tipoCombustible, alas
                                      , reactores, locomotora, trenDeAterrizaje, numVagones, placaDeMatricula, pinchazo);

       //llamo a un método de la clase vehiculo que establecera el tipo en el vehiculo

        bool esPosibleCrearlo = vehiculoConfigurado->TipoDeVehiculo();

            if(esPosibleCrearlo == true && erroresEntrada == false) // si la configuracion corresponde a una de las posibles
            {

               //Lo añado a la lista local de vehículos, a la combo e incremento el contador LCD

                this->listaVehiculosConfigurados.push_back(vehiculoConfigurado);

                ui->comboBox->addItem(placaDeMatricula);

                this->contadorVehiculosConfigurados++;

                ui->NumVehCreados->display(this->contadorVehiculosConfigurados);



                //getteo el tipo para pintarlo

                QString Tipo = QString::fromStdString(vehiculoConfigurado->getTipoVehiculo()); //lo convierto

                //Escribo un mensaje para informar de que todo se ha salvado correctamente

                QMessageBox mensajeEmergente;
                mensajeEmergente.setText("Vehiculo guardado correctamente en el sistema.\n\n     El tipo de vehiculo es : " + Tipo + "\n\n\nLa interfaz se reseteara y podra acceder al vehiculo creado seleccionandolo en el desplagable de la parte inferior de la pantalla.\nLa informacion se mostrara en el panel de la derecha\n");
                mensajeEmergente.setButtonText(1, "Entendido");
                mensajeEmergente.setWindowTitle("Informacion");
                mensajeEmergente.exec();


                //Finalmente Reseteo La interfaz

                ResetearInterfaz();


            }
            else
            {
                QMessageBox mensajeEmergente;
                mensajeEmergente.setText("ERROR en la configuracion del vehiculo.\n\nPor favor, revise los parametros introducidos.");
                mensajeEmergente.setButtonText(1, "Entendido");
                mensajeEmergente.setWindowTitle("Advertencia");
                mensajeEmergente.exec();

                delete vehiculoConfigurado;


            }


}

void MainWindow::ResetearInterfaz()
{


    ui->IntroducirNombre->clear();

    ui->NumRuedasCombo->setCurrentIndex(0);

    ui->Motor_Si->setChecked(true);
    ui->PotenciaPanel->show();

    ui->Potenciometro->setValue(0);
    ui->Pantallita->display(0);

    ui->Comb_Si->setChecked(true);
    ui->CombustiblePanel->show();

    ui->TipoCombustibleCombo->setCurrentIndex(0);

    ui->Alas_Si->setCheckable(false);
    ui->Alas_No->setCheckable(false);
    ui->Alas_Si->setCheckable(true);
    ui->Alas_No->setCheckable(true);

    ui->Reactores_Si->setCheckable(false);
    ui->Reactores_No->setCheckable(false);
    ui->Reactores_Si->setCheckable(true);
    ui->Reactores_No->setCheckable(true);

    ui->Loco_Si->setCheckable(false); /*TRUCO PARA QUE NO QUEDE NINGUNO SIN TICKAR EN EL GROUPBOX, DESHABILITARLOS Y REHABILITARLOS*/
    ui->Loco_No->setCheckable(false);
    ui->Loco_Si->setCheckable(true);
    ui->Loco_No->setCheckable(true);

    ui->TrenDeAt_Si->setCheckable(false);
    ui->TrenDeAt_No->setCheckable(false);
    ui->TrenDeAt_Si->setCheckable(true);
    ui->TrenDeAt_No->setCheckable(true);

    ui->Vagones_Si->setChecked(true);
    ui->VagonesPanel->show();

    ui->SeleccionDeVagones->setValue(0);

    ui->NumeroCorrespondiente->setNum(0);

    ui->MatriculaGenerada->setText("");
    ui->progressBar->hide();

    ui->KRP->setCheckable(false);
    ui->RDR->setCheckable(false);
    ui->KRP->setCheckable(true);
    ui->RDR->setCheckable(true);

    ui->Reset->click(); //resetea la tabla de colores

}


void MainWindow::on_Blanco_clicked()
{
    //Cuando se seleccione blanco se guarda
    colorSeleccionado.push_back("Blanco");
}

void MainWindow::on_Negro_clicked()
{
    //Cuando se seleccione negro se guarda
    colorSeleccionado.push_back("Negro");
}

void MainWindow::on_Rojo_clicked()
{
    //Cuando se seleccione rojo se guarda
    colorSeleccionado.push_back("Rojo");
}

void MainWindow::on_Azul_clicked()
{
    //Cuando se seleccione azul se guarda
    colorSeleccionado.push_back("Azul");
}

void MainWindow::on_Amarillo_clicked()
{
    //Cuando se seleccione amarillo se guarda
    colorSeleccionado.push_back("Amarillo");
}

void MainWindow::on_Verde_clicked()
{
    //Cuando se seleccione verde se guarda
    colorSeleccionado.push_back("Verde");
}

void MainWindow::on_Reset_clicked()
{
    //se pone el vector vacio, se elimina el color que se había pinchado
    this->colorSeleccionado.clear();

}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    /* Voy a recibir el indice del combo que corresponde con el del vector +1 porque la 0 de la combo es vacia */

    if(index == 0)
    {
        ui->DesplegarInfo->hide(); //oculto la informacion del vehiculo si la hubiera
        ui->InfoVacia->show(); //muestro el texto por defecto para la combo valor 0

    }
    else
    {
        ui->InfoVacia->hide();

        /* Representamos el vehiculo */

        RepresentarVehiculo(index);

    }


}

void MainWindow::RepresentarVehiculo(int indiceDeLaCombo)
{

     //listaVehiculosConfigurados[indiceDeLaCombo-1]; es es vehiculo que corresponde por orden de pushback (se que mi vector en la 0 es la combo en la 1)


        /* Conversiones De String a QString */

    QString motor = QString::fromStdString(listaVehiculosConfigurados[indiceDeLaCombo-1]->getMotor());
    QString combustible = QString::fromStdString(listaVehiculosConfigurados[indiceDeLaCombo-1]->getCombustible());
    QString color = QString::fromStdString(listaVehiculosConfigurados[indiceDeLaCombo-1]->getColor());
    QString alas = QString::fromStdString(listaVehiculosConfigurados[indiceDeLaCombo-1]->getAlas());
    QString reactores = QString::fromStdString(listaVehiculosConfigurados[indiceDeLaCombo-1]->getReactores());
    QString trenDeAterrizaje = QString::fromStdString(listaVehiculosConfigurados[indiceDeLaCombo-1]->getTrenDeAterrizaje());
    QString locomotora = QString::fromStdString(listaVehiculosConfigurados[indiceDeLaCombo-1]->getLocomotora());
    QString pinchazo = QString::fromStdString(listaVehiculosConfigurados[indiceDeLaCombo-1]->getPinchazo());
    QString cv = QString::fromStdString(to_string(listaVehiculosConfigurados[indiceDeLaCombo-1]->getCv()));
    QString vagones = QString::fromStdString(to_string(listaVehiculosConfigurados[indiceDeLaCombo-1]->getVagones()));




    ui->DesplegarInfo->setText("Nombre Del Vehículo: " + listaVehiculosConfigurados[indiceDeLaCombo-1]->getNombreVehiculo() + "\n"
                             + "Placa De Matrícula: " + listaVehiculosConfigurados[indiceDeLaCombo-1]->getPlacaDeMatricula() + "\n"
                             + "Número De Ruedas: " + listaVehiculosConfigurados[indiceDeLaCombo-1]->getNumeroRuedas() + "\n"
                             + "Motor: " + motor + "\n"
                                    + "\tPotencia Del Motor: " + cv + "\n"
                             + "Combustible: " + combustible + "\n"
                                    + "\tTipo De Combustible: " + listaVehiculosConfigurados[indiceDeLaCombo-1]->getTipoCombustible() + "\n"
                             + "Color: " + color + "\n"
                             + "Alas: " + alas + "\n"
                             + "Reactores: " + reactores + "\n"
                             + "Tren De Aterrizaje: " + trenDeAterrizaje + "\n"
                             + "Locomotora: " + locomotora + "\n"
                             + "Vagones: " + vagones + "\n"
                             + pinchazo);

    ui->DesplegarInfo->show(); //muestro el label en caso de que se hubiera pinchado la primera opcion del combo


}



void MainWindow::on_Motor_Si_stateChanged(int arg1)
{
    if(arg1 == 0){ //si se destica que se oculte
         ui->PotenciaPanel->hide();
    }else {
         ui->PotenciaPanel->show();
    }

}

void MainWindow::on_Comb_Si_stateChanged(int arg1)
{
    if(arg1 == 0){
         ui->CombustiblePanel->hide();
    }else {
         ui->CombustiblePanel->show();
    }
}


void MainWindow::on_Vagones_Si_stateChanged(int arg1)
{
    if(arg1 == 0){
         ui->VagonesPanel->hide();
    }else {
         ui->VagonesPanel->show();
    }
}
