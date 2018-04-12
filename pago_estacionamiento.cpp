#include <iostream>
using namespace std;

/*
Funcion que calcula la cantidad a pagar por concepto de estacionamiento
    de 1 a 5 horas, la hora cuesta $10
    de 6 a 10 horas, la hora cuesta $9
    por mas de 10 horas el costo es de $7
*/
float pago_estacionamiento(int horas)
{
	int cant(0);
	if (horas>=0 && horas<=5)
		cant = horas*10;
	if (horas>=6 && horas<=10)
		cant = horas*9;
	if (horas>11)
		cant = horas*7;

	return cant;
}

string passValidation(int cant, int expectR){
	string response = "falló";
	if( cant == expectR ) {
		return response = "Pasó";
  }
	else {
		return response;
	}
}

void casos_de_prueba(){

    cout << "TEST CASES" << endl;
		int Nhoras, cantR, expectR;
		string pass_fail, expectRS;
		string line = "";

		cantR = pago_estacionamiento(Nhoras);
		cout << "Particion de equivalencia" << endl;
		for (int i = 0; i < 3; i++) {
			Nhoras = cantR = expectR = 0;
			pass_fail = expectRS = "";
			cin >> Nhoras;
			if(Nhoras < 0){
				cin >> expectRS;
				pass_fail = "falló";
				line +=  to_string(Nhoras) + "       " + expectRS + "       " + to_string(cantR) + "       " + pass_fail + "\n\r";
			}
			else
			{
				cin >> expectR;
				cantR = pago_estacionamiento(Nhoras);
				pass_fail = passValidation(cantR, expectR);
				line +=  to_string(Nhoras) + "       " + to_string(expectR) + "       " + to_string(cantR) + "       " + pass_fail + "\n\r";
			}
		}
		cout << "test data     expected result      actual result         pass/fail" << endl;
		cout << line <<endl;

		cantR = pago_estacionamiento(Nhoras);
		int limites[] = {
			-1,
			0,
			5,
			6,
			10,
			12
		};
		cout << "Análisis de valores límite" << endl;
		for (int i = 0; i < 6; i++) {
			Nhoras = limites[i];
			cantR = expectR = 0;
			pass_fail = expectRS = "";
			cout << Nhoras;
			if(Nhoras < 0){
				cin >> expectRS;
				pass_fail = "falló";
				line +=  to_string(Nhoras) + "       " + expectRS + "       " + to_string(cantR) + "       " + pass_fail + "\n\r";
			}
			else
			{
				cin >> expectR;
				cantR = pago_estacionamiento(Nhoras);
				pass_fail = passValidation(cantR, expectR);
				line +=  to_string(Nhoras) + "       " + to_string(expectR) + "       " + to_string(cantR) + "       " + pass_fail + "\n\r";
			}
		}
		cout << "test data     expected result      actual result         pass/fail" << endl;
		cout << line <<endl;
}

int main()
{

    casos_de_prueba();

	return 0;
}
