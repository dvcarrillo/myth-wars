//***************************************************************************//
//				      				            							 //
//							SHELL: Mythological Wars			    		 //
//							 github.com/dvcarrillo 	 		                 //
//									    									 //
//		              				-2015-			        	     		 //
//			  						  									     //
//***************************************************************************//

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;


///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Generador de nÃºmeros aleatorios. 
// Los objetos de esta clase sirven para generar nÃºmeros aleatorios a demanda 
// con el metodo "Next" entre los valores "min" y "max". 

class MyRandom
{
	
private:
	
	// PRE: minVal <= MaxVal
	
    int minVal;	// MÃ­nimo Valor
    int maxVal;	// MÃ¡ximo valor

	/***********************************************************************/
	// Inicializa el generador de nÃºmeros aleatorios 
	// Es un mÃ©todo privado que se invoca solo al actuar el constructor.
	
	void InitMyRandom (void)
    {
        time_t t;
        srand ((int) time(&t));     // Inicializa el generador
                                    // con el reloj del sistema
    }
    
public:
	
	/***********************************************************************/	
	// Constructor
	
    MyRandom (int el_minimo, int el_maximo) :
        minVal(el_minimo), maxVal(el_maximo)
    {
        InitMyRandom();

        int no_lo_uso = Next(); // Desecho el primero
    }

	/***********************************************************************/	
	// Calcula y devuelve un nÃºmero aleatorio en el rango prefijado.
	
    int Next (void) {
    	
        int rango = (maxVal - minVal)+1;
        int v1 = rango * (rand() / (RAND_MAX*1.0));
        int v2 = minVal + (v1 % rango);

        return (v2);
    }

	/***********************************************************************/
	
    int Min (void) 
	{
        return (minVal);
    }

	/***********************************************************************/
	
    int Max (void) 
	{
        return (maxVal);
    }

	/***********************************************************************/
};
 

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Dios.
// Contiene informacion sobre un personaje y los mÃ©todos correspondientes

class Dios
{
private:
	
	string nombre;
	int id;
	
	int vida;			// MAX: 100
	
	double ataque;		// MAX: 100 (15) - MIN: 50 (7.5)
	double defensa;		// MAX: 100 (0.55) - MIN: 55 (1)
	
	double superataque;
	double aumento_ataque;
	double reduccion_defensa;
	
public:
	
	// CONSTRUCTOR
	// Recibe un numero
	
	Dios (int entrada_id)
	{
		if (entrada_id == 1)	{
			nombre = "ZEUS";
			id = 1;
			
			vida = 70;
			ataque = 12.75;
			defensa = 0.75;
			
			superataque = 17;
			aumento_ataque = 0.65;
			reduccion_defensa = 0.05;
		}
		
		else if (entrada_id == 2)	{
			nombre = "HADES";
			id = 2;
			
			vida = 100;
			ataque = 10.5;
			defensa = 0.89;
			
			superataque = 15;
			aumento_ataque = 0.7;
			reduccion_defensa = 0.07;
		}
		
		else if (entrada_id == 3)	{
			nombre = "POSEIDON";
			id = 3;
			
			vida = 90;
			ataque = 12;
			defensa = 0.89;
			
			superataque = 14;
			aumento_ataque = 0.9;
			reduccion_defensa = 0.03;
		}
		
		else if (entrada_id == 4)	{
			nombre = "ATENEA";
			id = 4;
			
			vida = 75;
			ataque = 14.25;
			defensa = 0.89;
			
			superataque = 16;
			aumento_ataque = 0.75;
			reduccion_defensa = 0.04;
		}
	}
	
	/**************************************************************************/
	// MÃ‰TODOS GET
	
	string GetNombre (void)
	{
		return (nombre);
	}
	
	int GetId (void)
	{
		return(id);
	}
	
	int GetVida (void)
	{
		return (vida);
	}
	
	// Retorna el ataque en puntos de ataque
	double GetAtaque (void)
	{
		return (ataque);
	}
	
	// Retorna el porcentaje de absorcion de daÃ±os
	double GetDefensa (void)
	{
		return (defensa);
	}
	
	// Devuelve los puntos de daÃ±o del superataque
	double GetSuperataque (void)
	{
		return (superataque);
	}
	
	double GetAumentoAtaque (void)
	{
		return (aumento_ataque);
	}
	
	double GetReduccionDefensa (void)
	{
		return(reduccion_defensa);
	}
	
	/**************************************************************************/
	// AUMENTAR - DISMINUIR ATAQUE
	
	void AumentaAtaque (void)
	{
		ataque = ataque + aumento_ataque;
	}
	
	/**************************************************************************/
	// AUMENTAR - DISMINUIR DEFENSA
	
	void DisminuyeDefensa (double disminucion)
	{
		defensa = defensa + disminucion;
	}
	
	/**************************************************************************/
	// DISMINUIR VIDA AL RECIBIR UN ATAQUE
	
	void AtaqueRecibido (int ataque_caracteristico)
	{
		vida = vida - (ataque_caracteristico * defensa) - 5;
	}
	
	void SuperataqueRecibido (int puntos_superataque)
	{
		vida = vida - (superataque * 1.5);
	}
	
};


///////////////////////////////////////////////////////////////////////////////

/*****************************************************************************/

///////////////////////////////////////////////////////////////////////////////

int main (void)
{
	system ("color 0F");
	cout << "Bienvenido a:" << endl;
   cout << endl;
   
   cout << "\t\t" << "     _____ _       _ _   _ " 	<< endl;
	cout << "\t\t" << "    |   __| |_ ___| | | |_|" << endl;
 	cout << "\t\t" << "   _|__   |   | -_| | |  _ " << endl;
	cout << "\t\t" << "  |_|_____|_|_|___|_|_| |_|" << endl;

	cout << "                      _   _       __    __                 " << endl;
	cout << "          /\\/\\  _   _| |_| |__   / / /\\ \\ \\__ _ _ __ ___   " << endl;
	cout << "	 /    \\| | | | __| '_ \\  \\ \\/  \\/ / _` | '__/ __|  " << endl;
	cout << "	/ /\\/\\ \\ |_| | |_| | | |  \\  /\\  / (_| | |  \\__ \\  " << endl;
	cout << "	\\/    \\/\\__, |\\__|_| |_|   \\/  \\/ \\__,_|_|  |___/  " << endl;
	cout << "	        |___/                  					   " << endl;
	cout << endl << endl << endl;
			
	
	
	
	
	
	cout << "Desarrollado en 2015 por @davidvargas996" << endl;
	cout << "v1.2" << endl;
	cout << endl << endl;
	
	system ("pause");
	system ("cls");
	
	string nombre_usuario;
	
	cout << "Introduce tu nombre: ";
	cin >> nombre_usuario;
	
	cout << endl << endl;
	
	system ("cls");
	
	/**************************************************************************/
	
	cout << "Hola, " << nombre_usuario
	<< ". Escoge a tu dios griego favorito:" << endl << endl;
	
	cout << "1. ZEUS:" << endl;
	cout << "Vida  " << '\t' << setw(4) << "70" << endl;
	cout << "Ataque   " << setw(3) << "85" << endl;
	cout << "Defensa  " << setw(3) << "95" << endl;
	cout << endl;
	
	cout << "2. HADES:" << endl;
	cout << "Vida  " << '\t' << setw(4) << "100" << endl;
	cout << "Ataque   " << setw(3) << "70" << endl;
	cout << "Defensa  " << setw(3) << "80" << endl;
	cout << endl;
	
	cout << "3. POSEIDON:" << endl;
	cout << "Vida  " << '\t' << setw(4) << "90" << endl;
	cout << "Ataque   " << setw(3) << "80" << endl;
	cout << "Defensa  " << setw(3) << "80" << endl;
	cout << endl;
	
	cout << "4. ATENEA:" << endl;
	cout << "Vida  " << '\t' << setw(4) << "75" << endl;
	cout << "Ataque   " << setw(3) << "95" << endl;
	cout << "Defensa  " << setw(3) << "80" << endl;
	cout << endl;
	cout << endl;
	
	int identificador_yo;
	
	do{
		cout << "Introduce el numero de tu eleccion: ";
		cin >> identificador_yo;
	} while ((identificador_yo < 1) || (identificador_yo > 4));
	
	system ("cls");
	
	/**************************************************************************/
	
	Dios yo(identificador_yo);
	MyRandom random_personaje(1,4);
	
	cout << nombre_usuario << ", has elegido a "
	<< yo.GetNombre() << "!";
	cout << endl << endl << endl;
	
	switch (yo.GetId())
	{
		case 1:
			cout << "ZEUS, el padre de los dioses y los hombres, gobernaba " << endl;
			cout << "a los dioses del Olimpo como un padre a una familia." << endl;
			cout << "Supervisor del universo, era el dios del cielo y el trueno." << endl;
			cout << "Entre sus atributos, se incluyen el rayo, el aguila, el toro" << endl;
			cout << "y el roble." << endl;
			break;
		
		case 2:
			cout << "HADES, el dios del inframundo griego, hijo de Cronos y Rea." << endl;
			cout << "Junto con sus hermanos Zeus y Poseidon derrotaton a los Titanes" << endl;
			cout << "y reclamaron el gobierno del cosmos, adjudicandose el inframundo," << endl;
			cout << "el cielo y el mar." << endl;
			break;
		
		case 3:
			cout << "POSEIDON, el dios de las aguas y de los terremotos. Ocupa el" << endl;
			cout << "panteon olimpico junto con sus hermanos Zeus y Hades. Se dice de" << endl;
			cout << "el que tuvo muchos hijos y fue protector de gran cantidad de" << endl;
			cout << "ciudades helenas, aunque perdio el concurso por Atenas contra Atenea" << endl;
			break;
		
		case 4:
			cout << "ATENEA, hija de Zeus, diosa de la guerra, civilizacion, sabiduria," << endl;
			cout << "de las artes, de la justicia y de la habilidad. Una de las principales" << endl;
			cout << "divinidades del panteon griego y una de los doce dioses olimpicos," << endl;
			cout << "Atenea recibio culto en toda la Grecia Antigua." << endl;
	}
	
	cout << endl << endl;
	
	int identificador_oponente = random_personaje.Next();
	
	while (identificador_oponente == identificador_yo)	{
		identificador_oponente = random_personaje.Next();
	}
	
	Dios oponente(identificador_oponente);
	
	cout << "Lucharas contra " << oponente.GetNombre() << ", PREPARATE!";
	cout << endl << endl << endl;
	
	system("pause");
	system("cls");
	
	/**************************************************************************/
	
	bool superataque_usado_yo = false;
	bool superataque_usado_oponente = false;
	int ganador;
	
	while ((yo.GetVida() > 0) && (oponente.GetVida() > 0))	{
		
		system ("color 0F");
		
		cout << "ESTADO ACTUAL: " << endl << endl;
		
		cout << nombre_usuario << ", con " << yo.GetNombre() << ":" << endl;
		cout << endl;
		cout << "Vida = " << '\t' << yo.GetVida() << endl;
		cout << "Ataque = " << yo.GetAtaque() / 0.15 << endl;
		cout << "Defensa = " << 1 - yo.GetDefensa() << "%" << endl;
		cout << "Superataque = ";
		
		if (superataque_usado_yo == true)
			cout << "usado" << endl;
		else
			cout << yo.GetSuperataque() << endl;
		
		cout << endl << endl;
		
		cout << "Ordenador, con " << oponente.GetNombre() << ":" << endl;
		cout << endl;
		cout << "Vida = " << '\t' << oponente.GetVida() << endl;
		cout << "Ataque = " << oponente.GetAtaque() / 0.15 << endl;
		cout << "Defensa = " << 1 - oponente.GetDefensa() << "%" << endl;
		cout << "Superataque = ";
		
		if (superataque_usado_oponente == true)
			cout << "usado" << endl;
		else
			cout << oponente.GetSuperataque() << endl;
		
		cout << endl << endl;
		
		system("pause");
		system("cls");
		
		/***********************************************************************/
		// TURNO DEL USUARIO
		
		cout << "Que deseas hacer, " << nombre_usuario << "?" << endl;
		cout << endl << endl;
		
		switch (yo.GetId())
		{
			case 1:
				cout << "1. Chispa electrica" << endl;
				cout << "2. Lanzar ejercito de toros" << endl;
				cout << "3. Invocar la fuerza de las aguilas" << endl;
				cout << "4. Ganar fortaleza de los robles" << endl;
				break;
			
			case 2:
				cout << "1. Lanzar bola de fuego" << endl;
				cout << "2. Furia del inframundo" << endl;
				cout << "3. Ganar fuerza de los muertos" << endl;
				cout << "4. Equiparse escudos de ebano" << endl;
				break;
			
			case 3:
				cout << "1. Causar terremoto" << endl;
				cout << "2. Producir tsunami devastador" << endl;
				cout << "3. Invocar la fuerza de los mares" << endl;
				cout << "4. Recibir ayuda de los marineros" << endl;
				break;
			
			case 4:
				cout << "1. Ataque medido" << endl;
				cout << "2. Enviar civilizaciones al ataque" << endl;
				cout << "3. Diseñar nueva estrategia de ataque" << endl;
				cout << "4. Ayudarse del pueblo" << endl;
				break;
		}
		
		cout << endl << endl;
		
		int eleccion;
		
		do{
			cout << "Eleccion: ";
			cin >> eleccion;
		}while ((eleccion < 1) || (eleccion > 4));
		
		system ("cls");
		
		cout << "Has elegido ";
		
		switch (yo.GetId())
		{
			case 1:
				
				if (eleccion == 1) {
					cout << "chispa electrica!" << endl;
					oponente.AtaqueRecibido(yo.GetAtaque());
					cout << endl;
					
					// (ataque_caracteristico * defensa) - 5
					double danio = (yo.GetAtaque() * oponente.GetDefensa()) + 5;
					
					cout << "Has causado " << danio << " puntos de daño al rival!";
					cout << endl << endl;
				}
				
				else if (eleccion == 2) {
					cout << "lanzar ejercito de toros!" << endl;
					
					if(superataque_usado_yo == false) {
						oponente.SuperataqueRecibido(yo.GetSuperataque());
						cout << endl;
						
						double danio = yo.GetSuperataque() * 1.5;
						
						cout << "Has causado " << danio << " puntos de daño al rival!";
						cout << endl << endl;
						
						superataque_usado_yo = true;
					}
					else {
						cout << endl << "Ya has usado el superataque! Pierdes el turno";
						cout << endl << endl;
					}
				}
				
				else if (eleccion == 3) {
					cout << "invocar la fuerza de las aguilas!" << endl;
					yo.AumentaAtaque();
					cout << endl;
					
					double puntos = yo.GetAumentoAtaque();
					
					cout << "Has aumentado tu ataque en " << (puntos / 0.15) << " puntos!" << endl;
					cout << endl;
				}
				
				else if (eleccion == 4) {
					cout << "ganar fortaleza de los robles!" << endl;
					oponente.DisminuyeDefensa(yo.GetReduccionDefensa());
					cout << endl;
					
					double puntos = yo.GetReduccionDefensa();
					
					cout << "¡La defensa rival ha disminuido un " << 1 - puntos << "%!" << endl;
					cout << endl;
				}
					
				break;
			
			case 2:
				
				if (eleccion == 1) {
					cout << "lanzar bola de fuego!" << endl;
					oponente.AtaqueRecibido(yo.GetAtaque());
					cout << endl;
					
					// (ataque_caracteristico * defensa) - 5
					double danio = (yo.GetAtaque() * oponente.GetDefensa()) + 5;
					
					cout << "Has causado " << danio << " puntos de daño al rival!";
					cout << endl << endl;
				}
				
				else if (eleccion == 2) {
					cout << "furia del inframundo!" << endl;
					
					if(superataque_usado_yo == false) {
						oponente.SuperataqueRecibido(yo.GetSuperataque());
						cout << endl;
						
						double danio = yo.GetSuperataque() * 1.5;
						
						cout << "Has causado " << danio << " puntos de daño al rival!";
						cout << endl << endl;
						
						superataque_usado_yo = true;
					}
					else {
						cout << endl << "Ya has usado el superataque! Pierdes el turno";
						cout << endl << endl;
					}
				}
				
				else if (eleccion == 3) {
					cout << "ganar fuerza de los muertos!" << endl;
					yo.AumentaAtaque();
					cout << endl;
					
					double puntos = yo.GetAumentoAtaque();
					
					cout << "Has aumentado tu ataque en " << (puntos / 0.15) << " puntos!" << endl;
					cout << endl;
				}
				
				else if (eleccion == 4) {
					cout << "equiparse escudos de ebano!" << endl;
					oponente.DisminuyeDefensa(yo.GetReduccionDefensa());
					cout << endl;
					
					double puntos = yo.GetReduccionDefensa();
					
					cout << "La defensa rival ha disminuido un " << 1 - puntos << "%!" << endl;
					cout << endl;
				}
					
				break;
				
			case 3:
				
				if (eleccion == 1) {
					cout << "causar terremoto!" << endl;
					oponente.AtaqueRecibido(yo.GetAtaque());
					cout << endl;
					
					// (ataque_caracteristico * defensa) - 5
					double danio = (yo.GetAtaque() * oponente.GetDefensa()) + 5;
					
					cout << "Has causado " << danio << " puntos de daño al rival!";
					cout << endl << endl;
				}
				
				else if (eleccion == 2) {
					cout << "producir tsunami devastador!" << endl;
					
					if(superataque_usado_yo == false) {
						oponente.SuperataqueRecibido(yo.GetSuperataque());
						cout << endl;
						
						double danio = yo.GetSuperataque() * 1.5;
						
						cout << "Has causado " << danio << " puntos de daño al rival!";
						cout << endl << endl;
						
						superataque_usado_yo = true;
					}
					else {
						cout << endl << "Ya has usado el superataque! Pierdes el turno";
						cout << endl << endl;	
					}
				}
				
				else if (eleccion == 3) {
					cout << "invocar la fuerza de los mares!" << endl;
					yo.AumentaAtaque();
					cout << endl;
					
					double puntos = yo.GetAumentoAtaque();
					
					cout << "Has aumentado tu ataque en " << (puntos / 0.15) << " puntos!" << endl;
					cout << endl;
				}
				
				else if (eleccion == 4) {
					cout << "recibir ayuda de los marineros!" << endl;
					oponente.DisminuyeDefensa(yo.GetReduccionDefensa());
					cout << endl;
					
					double puntos = yo.GetReduccionDefensa();
					
					cout << "La defensa rival ha disminuido un " << 1 - puntos << "%!" << endl;
					cout << endl;
				}
				
				break;
				
		
			case 4:
				
				if (eleccion == 1) {
					cout << "ataque medido!" << endl;
					oponente.AtaqueRecibido(yo.GetAtaque());
					cout << endl;
					
					// (ataque_caracteristico * defensa) - 5
					double danio = (yo.GetAtaque() * oponente.GetDefensa()) + 5;
					
					cout << "Has causado " << danio << " puntos de daño al rival!";
					cout << endl << endl;
				}
				
				else if (eleccion == 2) {
					cout << "enviar civilizaciones al ataque!" << endl;
					
					if(superataque_usado_yo == false) {
						oponente.SuperataqueRecibido(yo.GetSuperataque());
						cout << endl;
						
						double danio = yo.GetSuperataque() * 1.5;
						
						cout << "Has causado " << danio << " puntos de daño al rival!";
						cout << endl << endl;
						
						superataque_usado_yo = true;
					}
					else {
						cout << endl << "Ya has usado el superataque! Pierdes el turno";
						cout << endl << endl;	
					}
				}
				
				else if (eleccion == 3) {
					cout << "diseñar nueva estrategia de ataque!" << endl;
					yo.AumentaAtaque();
					cout << endl;
					
					double puntos = yo.GetAumentoAtaque();
					
					cout << "Has aumentado tu ataque en " << (puntos / 0.15) << " puntos!" << endl;
					cout << endl;
				}
				
				else if (eleccion == 4) {
					cout << "ayudarse del pueblo!" << endl;
					oponente.DisminuyeDefensa(yo.GetReduccionDefensa());
					cout << endl;
					
					double puntos = yo.GetReduccionDefensa();
					
					cout << "La defensa rival ha disminuido un " << 1 - puntos << "%!" << endl;
					cout << endl;
				}
				
				break;
		}
		
		system("color 4F");
		system("pause");
		system("cls");
		
		if ((oponente.GetVida() < 0) && (yo.GetVida() > 0)) {
			ganador = 0;
		}
		
		else {
			
			/***********************************************************************/
			// TURNO DEL ORDENADOR
			
			cout << "Turno de " << oponente.GetNombre() << endl << endl;
			
			system ("pause");
			
			cout << endl << endl;
			
			MyRandom ataque_oponente(1,8);
			
			int movimiento_oponente = ataque_oponente.Next();
			
			if (superataque_usado_oponente == true) {
				while ((movimiento_oponente == 5) || (movimiento_oponente == 6)) {
					movimiento_oponente = ataque_oponente.Next();
				}
			}
			
			cout << oponente.GetNombre() << " ha usado ";
			
			switch (oponente.GetId())
			{
				case 1:
					
					if ((movimiento_oponente == 1) || (movimiento_oponente == 2) ||
					(movimiento_oponente == 3) || (movimiento_oponente == 4)) {
						cout << "chispa electrica!" << endl;
						yo.AtaqueRecibido(oponente.GetAtaque());
						cout << endl;
						
						double danio = (oponente.GetAtaque() * yo.GetDefensa()) + 5;
						
						cout << "El oponente te ha causado " << danio << " puntos de daño!";
						cout << endl << endl;
					}
					
					else if ((movimiento_oponente == 5) || (movimiento_oponente == 6)) {
						cout << "lanzar ejercito de toros!" << endl;
						yo.SuperataqueRecibido(oponente.GetSuperataque());
						superataque_usado_oponente = true;
						cout << endl;
						
						double danio = oponente.GetSuperataque() * 1.5;
						
						cout << "El oponente te ha causado " << danio << " puntos de daño!";
						cout << endl << endl;
					}
					
					else if (movimiento_oponente == 7) {
						cout << "invocar la fuerza de las aguilas!" << endl;
						oponente.AumentaAtaque();
						cout << endl;
						
						double puntos = oponente.GetAumentoAtaque();
						
						cout << "El oponente ha aumentado su ataque en " << puntos << " puntos!"
						<< endl;
						cout << endl;
					}
					
					else if (movimiento_oponente == 8) {
						cout << "ganar fortaleza de los robles!" << endl;
						yo.DisminuyeDefensa(oponente.GetReduccionDefensa());
						
						double puntos = oponente.GetReduccionDefensa();
						
						cout << "Tu defensa ha disminuido un " << 1 - puntos << "%!" << endl;
						cout << endl;
					}
					
					else
						cout << " ERROR";
					
					break;
				
				case 2:
					
					if ((movimiento_oponente == 1) || (movimiento_oponente == 2) ||
					(movimiento_oponente == 3) || (movimiento_oponente == 4)) {
						cout << "lanzar bola de fuego!" << endl;
						yo.AtaqueRecibido(oponente.GetAtaque());
						cout << endl;
						
						double danio = (oponente.GetAtaque() * yo.GetDefensa()) + 5;
						
						cout << "El oponente te ha causado " << danio << " puntos de daño!";
						cout << endl << endl;
					}
					
					else if ((movimiento_oponente == 5) || (movimiento_oponente == 6)) {
						cout << "furia del inframundo!" << endl;
						yo.SuperataqueRecibido(oponente.GetSuperataque());
						superataque_usado_oponente = true;
						cout << endl;
						
						double danio = oponente.GetSuperataque() * 1.5;
						
						cout << "El oponente te ha causado " << danio << " puntos de daño!";
						cout << endl << endl;
					}
					
					else if (movimiento_oponente == 7) {
						cout << "ganar fuerza de los muertos!" << endl;
						oponente.AumentaAtaque();
						cout << endl;
						
						double puntos = oponente.GetAumentoAtaque();
						
						cout << "El oponente ha aumentado su ataque en " << puntos << " puntos!"
						<< endl;
						cout << endl;
					}
					
					else if (movimiento_oponente == 8) {
						cout << "equiparse escudos de ebano!" << endl;
						yo.DisminuyeDefensa(oponente.GetReduccionDefensa());
						
						double puntos = oponente.GetReduccionDefensa();
						
						cout << "Tu defensa ha disminuido un " << 1 - puntos << "%!" << endl;
						cout << endl;
					}
					
					else
						cout << " ERROR";
					
					break;
			
				case 3:
					
					if ((movimiento_oponente == 1) || (movimiento_oponente == 2) ||
					(movimiento_oponente == 3) || (movimiento_oponente == 4)) {
						cout << "causar terremoto!" << endl;
						yo.AtaqueRecibido(oponente.GetAtaque());
						cout << endl;
						
						double danio = (oponente.GetAtaque() * yo.GetDefensa()) + 5;
						
						cout << "El oponente te ha causado " << danio << " puntos de daño!";
						cout << endl << endl;
					}
					
					else if ((movimiento_oponente == 5) || (movimiento_oponente == 6)) {
						cout << "producir tsunami devastador!" << endl;
						yo.SuperataqueRecibido(oponente.GetSuperataque());
						superataque_usado_oponente = true;
						cout << endl;
						
						double danio = oponente.GetSuperataque() * 1.5;
						
						cout << "El oponente te ha causado " << danio << " puntos de daño!";
						cout << endl << endl;
					}
					
					else if (movimiento_oponente == 7) {
						cout << "invocar la fuerza de los mares!" << endl;
						oponente.AumentaAtaque();
						cout << endl;
						
						double puntos = oponente.GetAumentoAtaque();
						
						cout << "El oponente ha aumentado su ataque en " << puntos << " puntos!"
						<< endl;
						cout << endl;
					}
					
					else if (movimiento_oponente == 8) {
						cout << "recibir ayuda de los marineros!" << endl;
						yo.DisminuyeDefensa(oponente.GetReduccionDefensa());
						cout << endl;
						
						double puntos = oponente.GetReduccionDefensa();
						
						cout << "Tu defensa ha disminuido un " << 1 - puntos << "%!" << endl;
						cout << endl;
					}
					
					else
						cout << " ERROR";
					
					break;
				
				case 4:
					
					if ((movimiento_oponente == 1) || (movimiento_oponente == 2) ||
					(movimiento_oponente == 3) || (movimiento_oponente == 4)) {
						cout << "ataque medido!" << endl;
						yo.AtaqueRecibido(oponente.GetAtaque());
						cout << endl;
						
						double danio = (oponente.GetAtaque() * yo.GetDefensa()) + 5;
						
						cout << "El oponente te ha causado " << danio << " puntos de daño!";
						cout << endl << endl;
					}
					
					else if ((movimiento_oponente == 5) || (movimiento_oponente == 6)) {
						cout << "enviar civilizaciones al ataque!" << endl;
						yo.SuperataqueRecibido(oponente.GetSuperataque());
						superataque_usado_oponente = true;
						cout << endl;
						
						double danio = oponente.GetSuperataque() * 1.5;
						
						cout << "El oponente te ha causado " << danio << " puntos de daño!";
						cout << endl << endl;
					}
					
					else if (movimiento_oponente == 7) {
						cout << "diseñar nueva estrategia de ataque!" << endl;
						oponente.AumentaAtaque();
						cout << endl;
						
						double puntos = oponente.GetAumentoAtaque();
						
						cout << "El oponente ha aumentado su ataque en " << puntos << " puntos!"
						<< endl;
						cout << endl;
					}
					
					else if (movimiento_oponente == 8) {
						cout << "ayudarse del pueblo!" << endl;
						yo.DisminuyeDefensa(oponente.GetReduccionDefensa());
						
						double puntos = oponente.GetReduccionDefensa();
						
						cout << "Tu defensa ha disminuido un " << 1 - puntos << "%!" << endl;
						cout << endl;
					}
					
					else
						cout << " ERROR";
					
					break;
			}	// switch
			
			cout << endl;
			
			if (yo.GetVida() < 0) {
				ganador = 1;
			}
			else if (oponente.GetVida() < 0) {
				ganador = 0;
			}
			
		}
		
		system ("pause");
		system ("cls");
			
	} //while
	
	/**************************************************************************/
	// MUESTRA DEL GANADOR
   
   
   
    cout << "                  ______________________________________			";
	cout <<	"	  ________|                                      |_______	" << endl;
	cout <<	"	  \\       |          FIN DE LA PARTIDA           |      /	" << endl;
	cout <<	"	   \\      |                                      |     /	" << endl;
	cout <<	"	   /      |______________________________________|     \\	" << endl;
	cout <<	"	  /__________)                                (_________\\	" << endl;
	cout << endl << endl;
	
	cout << "El ganador es: " << endl << endl;
	
	if (ganador == 0) {
		cout << yo.GetNombre() << endl;
		cout << "Enhorabuena, " << nombre_usuario << "!";
	}
	
	else {
		cout << oponente.GetNombre() << endl;
		cout << "Has perdido, " << nombre_usuario << "!";
	}
	
	cout << endl << endl;
	
	system("pause");
		
	return (0);
}	
