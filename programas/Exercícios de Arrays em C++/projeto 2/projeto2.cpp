/*
02. Você foi contratado por uma emissora de TV para fazer um software em C++ pra trabalhar com os dados da chuva em sua cidade. 
Seu vetor de 7 posições deve armazenar quanto choveu em cada dia. Em seguida, deve dizer que dia choveu mais, o dia que choveu menos, 
o tanto que choveu na semana e a média, para exibir na TV.
*/

#include <iostream>

using namespace std;

int dayThatRainedTheMost(int rainWeek[]); //Returns the rainiest day

int dayThatRainedTheLeast(int rainWeek[]);

float averageRain(int rainWeek[]);

int totalRain(int rainWeek[]);

int main()
{
    int rainWeek[7];

	for (int i = 0; i < 7; i++)
	{
		cout << "Quanto chuveu no dia " << i + 1 << " da semana (em ml)?" << endl;
		cin >> rainWeek[i];
	}

	cout << "O dia que mais choveu foi o dia " << dayThatRainedTheMost(rainWeek) << endl;
	cout << "O dia que menos choveu foi o dia " << dayThatRainedTheLeast(rainWeek) << endl;
	cout << "Choveu " << totalRain(rainWeek) << "ml durante a semana" << endl;
	cout << "Choveu em media durante a semana " << averageRain(rainWeek)  << "ml" << endl;
}


int dayThatRainedTheMost(int rainWeek[]) {
	int rainyDay = rainWeek[0];
	int indexDay = 0;

	for (int i = 1; i < 7; i++)
	{
		if (rainyDay < rainWeek[i]) {
			rainyDay = rainWeek[i];
			indexDay = i;
		}
	}

	return indexDay + 1;
}


int dayThatRainedTheLeast(int rainWeek[]) {
	int rainyDay = rainWeek[0];
	int indexDay = 0;

	for (int i = 1; i < 7; i++)
	{
		if (rainyDay > rainWeek[i]) {
			rainyDay = rainWeek[i];
			indexDay = i;
		}
	}

	return indexDay + 1;
}


float averageRain(int rainWeek[]) {
	float average = 0;

	for (int i = 1; i < 7; i++)
	{
		average += rainWeek[i];
	}

	average /= 7;

	return average;
}

int totalRain(int rainWeek[]) {
	int totalRain = 0;

	for (int i = 1; i < 7; i++)
	{
		totalRain += rainWeek[i];
	}

	return totalRain;

}

