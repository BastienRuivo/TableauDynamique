#include "header/TableauDynamique.h"
#include "header/ElementTD.h"
#include <iostream>
using namespace std;

TableauDynamique::TableauDynamique()
{
	capacite = 1;
	taille_utilisee = 0;
	ad = new ElementTD[capacite];
}

TableauDynamique::~TableauDynamique()
{
	delete[] ad;
	capacite = 0;
	taille_utilisee = 0;
}

void TableauDynamique::vider()
{
	delete[] ad;
	capacite = 1;
	taille_utilisee = 0;
	ad = new ElementTD[capacite];
}

void TableauDynamique::ajouterElement(ElementTD e)
{
	taille_utilisee++;

	if (taille_utilisee >= capacite)
	{
		unsigned int c = capacite * 2;
		
		unsigned int tu = taille_utilisee;
		ElementTD* Tab = new ElementTD[c];
		for (int i = 0; i < capacite; i++)
		{
			Tab[i] = ad[i];
		}
		
		delete[] ad;
		capacite = c;
		taille_utilisee = tu;
		ad = Tab;
	}

	ad[taille_utilisee-1] = e;
	
}

ElementTD TableauDynamique::valeurIemeElement(unsigned int indice) const
{
	return ad[indice];
}

void TableauDynamique::modifierValeurIemeElement(ElementTD e, unsigned int indice)
{
	ad[indice] = e;
}

void TableauDynamique::afficher() const
{
	for (int i = 0; i < taille_utilisee; i++)
	{
		std::cout << "tab["<<i<<"]"<< " = "<< ad[i] << std::endl;
	}
}

void TableauDynamique::supprimerElement(unsigned int indice)
{
	taille_utilisee--;
	for (int i = indice; i < taille_utilisee; i++)
	{
		ad[i] = ad[i + 1];
	}
	if (taille_utilisee < capacite / 3.f)
	{
		unsigned int c = capacite / 3.f;
		unsigned int tu = taille_utilisee;
		ElementTD* Tab = new ElementTD[c];
		for (int i = 0; i < capacite; i++)
		{
			Tab[i] = ad[i];
		}

		vider();
		capacite = c;
		taille_utilisee = tu;
		ad = Tab;
	}
}
