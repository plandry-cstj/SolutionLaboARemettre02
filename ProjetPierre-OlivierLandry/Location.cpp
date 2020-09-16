// But : �crire un programme pour calculer le montant qu'un individu devra d�bourser pour faire un voyage dans une voiture lou�e. Le programme tient compte du
//		 kilom�trage parcouru et de la dur�e du voyage qui sont soumises par l'utilisateur.
// Auteur : Pierre-Olivier Landry
// Date : 2020-09-15

#include <iostream>

int main()
{
	setlocale(LC_ALL, "");

	// D�finir les variables
	float nbKM;					// Le nombre de kilom�tres que l'utilisateur a fait
	float locationVoiture = 45;	// 45$ Par jour et 250km gratuits par jour
	float consoVoiture = 7.6;	// 7.6L aux 100 km
	float essence = 1.25;		// 1.25$ le litre
	float kmSupp;				// Nombre de km suppl�mentaire
	float prixKMSupp;			// 0.05$/km pour chaque km suppl�mentaire
	float prixTotal;			// Le prix total

	// Le programme demande le nombre de kilom�tre � l'utilisateur
	std::cout << "Bonjour et bienvenue dans le calculateur de voyage.\nVeuillez entrer le nombre de kilom�tre � parcourir: ";
	std::cin >> nbKM;

	// Prix de base si l'utilisateur entre 250km
	if (nbKM <= 250 && nbKM >= 0)
	{
		prixTotal = nbKM / 100 * consoVoiture * essence + locationVoiture;
		std::cout << "\nVotre voyage vous co�tera " << prixTotal << "$\n";
	}
	else if (nbKM > 250) // Si l'utilisateur fait plus que 250km
	{
		kmSupp = nbKM - 250;
		prixKMSupp = kmSupp * 0.05;
		prixTotal = nbKM / 100 * consoVoiture * essence + locationVoiture + prixKMSupp;
		std::cout << "\nLe prix est de: " << prixTotal << "$\n";
	}
	else if (nbKM < 0) // Si l'utilisateur entre 0 km ou moins
	{
		std::cout << "\nC'est impossible\n";
	}

	return 0;
}

/*
Plan de tests
Kilom�tres					R�sultat

450							97.75$
250							68.75$
10							45.95$
-12							C'est impossible.
1250						190$
0							45$
*/