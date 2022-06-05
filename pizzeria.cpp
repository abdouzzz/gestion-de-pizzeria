#include<iostream>
using namespace std;
#include"groupeplat.h"
#include"plat.h"
#include"composant.h"
#include<string>
#include<fstream>




void nombredieses() {
	ifstream entree("PizzTemplate.html", ios::in);
	int cpt =0;
	char ligne[1000];
	
	string dieses;
	if (!entree) {
		cout << "problem d'ouverture";
	}
	while (!entree.eof()) {
		entree.getline(ligne, 1000, '\n');
		dieses += ligne;
		if (dieses.find("#")) {
			cpt++;
		}
	}
	cout << "NB(#) = "<<cpt;
}



int main() {
	
	plat* p1 = new plat("LE LIEU JAUNE EN GRAVLAX, MELON, CONCOMBRE ET CORIANDRE."
		"LE TARTARE DE BOEUF, RADIS, OSEILLE ET CREME FUMEE.","18");
	gplat* entree = new gplat("entree");
	entree->addplat(p1);
	//entree->affiche();

	plat* p2 = new plat("LES ENCORNETS, COURGE, YUZU VERT ET BEURRE A L'ENCRE."
		"LE SUPREME DE PINTADE, CELERI, CEPES ET SAUCE VIN JAUNE.", "15");
	gplat* plats = new gplat("plats");
	plats->addplat(p2);
	//plats->affiche();


	plat* p3 = new plat("COMME UN MONT BLANC, GANACHE VANILLE, MARRON ET MERINGUE."
		"LA FIGUE, en SORBET, PATE A CHOUX ET SESAME NOIR.", "17");
	plat* p4 = new plat("COMME UN MONT BLANC, GANACHE VANILLE, MARRON ET MERINGUE."
		"LA FIGUE, en SORBET, PATE A CHOUX ET SESAME NOIR.", "9");
	gplat* desserts = new gplat("desserts");
	desserts->addplat(p3);
	desserts->addplat(p4);
	//desserts->affiche();

	//desserts->exportHTML();
	//plats->exportHTML();

	nombredieses();

}

