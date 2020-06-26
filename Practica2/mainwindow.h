#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vehiculo.h"

#include "QMessageBox" //para poder lanzar los mensajes

#include <cstdlib> //para los numeros aleatorios

#include <iostream> //para los string
#include <string>
using namespace std;

#include <vector>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE




class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_GenerarMatricula_clicked();
    int GenerarNumeroAleatorio(int min, int max);
    string CalcularLetrasAleatorias();
    void ResetearInterfaz();
    void on_GuardarVehiculo_clicked();

    void on_Blanco_clicked();

    void on_Negro_clicked();

    void on_Rojo_clicked();

    void on_Azul_clicked();

    void on_Amarillo_clicked();

    void on_Verde_clicked();

    void on_Reset_clicked();

    void RepresentarVehiculo(int indiceDeLaCombo);

    void on_comboBox_currentIndexChanged(int index);

    void on_Motor_Si_stateChanged(int arg1);

    void on_Comb_Si_stateChanged(int arg1);

    void on_Vagones_Si_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    vector<string> colorSeleccionado; //vector que representa en el orden que se muestra en la interfaz los colores, al presionar uno, se marcara a true
    vector<Vehiculo *> listaVehiculosConfigurados;
    int contadorVehiculosConfigurados;

};
#endif // MAINWINDOW_H
