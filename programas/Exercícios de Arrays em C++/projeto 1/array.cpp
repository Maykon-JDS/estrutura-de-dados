// Exercícios de Arrays em C++.cpp 
/*
01. Escreva um programa que vai receber e armazenar 10 números em um array. 
Em seguida, você deve criar duas funções que vão achar o maior e o menor valor desse array.
*/


#include <iostream>
#include <climits>

using namespace std;

int higherNumber(int arraynumbers[]);
int lowerNumber(int arraynumbers[]);

int main()
{
    int numbers[10];
	for ( int i = 0; i < 10; i++)
	{
		cout << "Escreva o " << i << " numero: ";
		cin >> numbers[i];
	}

	cout << higherNumber(numbers) << endl;
	cout << lowerNumber(numbers);
}

int higherNumber(int arraynumbers[]) {
	int higherNumberV{ INT_MIN };

	for (int i = 0; i < 10; i++){
		if (higherNumberV < arraynumbers[i]) {
			higherNumberV = arraynumbers[i];
		}
	}

	return higherNumberV;
}

int lowerNumber(int arraynumbers[]) 
{
	int lowerNumberV{ INT_MAX };

	for (int i = 0; i < 10; i++) {
		if (lowerNumberV > arraynumbers[i]) {
			lowerNumberV = arraynumbers[i];
		}
	}

	return lowerNumberV;
}
