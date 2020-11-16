#include <iostream>
#include <time.h>
#include <fstream>
#include "header\TableauDynamique.h"
#include "header/ElementTD.h"

using namespace std;

int main(void)
{
	clock_t TE = clock();

	ofstream ofD("C:/Users/Basti/Desktop/dataDyn.txt");
	if (ofD.is_open())
	{
		for (int n = 0; n < 20000000; n+=100000)
		{
			TableauDynamique *test = new TableauDynamique();
			ElementTD* E = new ElementTD[n];
			clock_t TE = clock();
			for (int i = 0; i < n; i++)
			{
				test->ajouterElement(i);
				
			}
			ofD << (clock() - ((float)TE)) / CLOCKS_PER_SEC << ";";
			TE = clock();
			for (int i = 0; i < n; i++)
			{
				E[i] = i;
			}
			ofD << (clock() - ((float)TE))/CLOCKS_PER_SEC<< ";" << endl;

			delete[] E;
			test->~TableauDynamique();
			

		}
		
	}
	else
	{
		cout << "erreur" << endl;
	}
	

	
	return 0;
}