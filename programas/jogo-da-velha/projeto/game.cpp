#include <iostream>

using namespace std;

int main() {
	int player1, player2, v1, v2, v3, c1, c2, c3, parar, play1pos, play2pos, partidas, parti, placar1, placar2;
	
	bool jogada, vez, pos1oc, pos2oc, pos3oc, pos4oc, pos5oc, pos6oc, pos7oc, pos8oc, pos9oc, empate;
	
	bool pos1play1, pos2play1, pos3play1, pos4play1, pos5play1, pos6play1, pos7play1, pos8play1, pos9play1, win1play1, win2play1, win3play1, win4play1, win5play1, win6play1, win7play1, win8play1;

	bool pos1play2, pos2play2, pos3play2, pos4play2, pos5play2, pos6play2, pos7play2, pos8play2, pos9play2, win1play2, win2play2, win3play2, win4play2, win5play2, win6play2, win7play2, win8play2;
	
	partidas = 0;
	placar1 = 0;
	placar2 = 0;

	
	
	while (partidas != 1)
	{
		
		player1 = 1;
		player2 = 2;
		play1pos = 0;
		play2pos = 0;
		v1 = 0;
		v2 = 0;
		v3 = 0;
		c1 = 0;
		c2 = 0;
		c3 = 0;
		parar = 0;
		parti = 0;
		vez = true;

		pos1play1 = false;
		pos2play1 = false;
		pos3play1 = false;
		pos4play1 = false;
		pos5play1 = false;
		pos6play1 = false;
		pos7play1 = false;
		pos8play1 = false;
		pos9play1 = false;

		pos1play2 = false;
		pos2play2 = false;
		pos3play2 = false;
		pos4play2 = false;
		pos5play2 = false;
		pos6play2 = false;
		pos7play2 = false;
		pos8play2 = false;
		pos9play2 = false;

		empate = false;

		win1play1 = false;
		win2play1 = false;
		win3play1 = false;
		win4play1 = false;
		win5play1 = false;
		win6play1 = false;
		win7play1 = false;
		win8play1 = false;

		win1play2 = false;
		win2play2 = false;
		win3play2 = false;
		win4play2 = false;
		win5play2 = false;
		win6play2 = false;
		win7play2 = false;
		win8play2 = false;

		cout << "\n Jogador 1: " << placar1 << " | Jogador 2: " << placar2 << "\n";

		cout << "\n  1 | 2 | 3 ";
		cout << "\n ---|---|---";
		cout << "\n  4 | 5 | 6 ";
		cout << "\n ---|---|---";
		cout << "\n  7 | 8 | 9 ";

		while (parar != 1)
		{
			pos1oc = pos1play1 || pos1play2; 
			pos2oc = pos2play1 || pos2play2; 
			pos3oc = pos3play1 || pos3play2; 
			pos4oc = pos4play1 || pos4play2; 
			pos5oc = pos5play1 || pos5play2; 
			pos6oc = pos6play1 || pos6play2; 
			pos7oc = pos7play1 || pos7play2; 
			pos8oc = pos8play1 || pos8play2; 
			pos9oc = pos9play1 || pos9play2; 

			empate = pos1oc && pos2oc && pos3oc && pos4oc && pos5oc && pos6oc && pos7oc && pos8oc && pos9oc;

			win1play1 = pos1play1 == true && pos2play1 == true && pos3play1 == true;
			win2play1 = pos4play1 == true && pos5play1 == true && pos6play1 == true;
			win3play1 = pos7play1 == true && pos8play1 == true && pos9play1 == true;
			win4play1 = pos1play1 == true && pos4play1 == true && pos7play1 == true;
			win5play1 = pos2play1 == true && pos5play1 == true && pos8play1 == true;
			win6play1 = pos3play1 == true && pos6play1 == true && pos9play1 == true;
			win7play1 = pos1play1 == true && pos5play1 == true && pos9play1 == true;
			win8play1 = pos3play1 == true && pos5play1 == true && pos7play1 == true;

			win1play2 = pos1play2 == true && pos2play2 == true && pos3play2 == true;
			win2play2 = pos4play2 == true && pos5play2 == true && pos6play2 == true;
			win3play2 = pos7play2 == true && pos8play2 == true && pos9play2 == true;
			win4play2 = pos1play2 == true && pos4play2 == true && pos7play2 == true;
			win5play2 = pos2play2 == true && pos5play2 == true && pos8play2 == true;
			win6play2 = pos3play2 == true && pos6play2 == true && pos9play2 == true;
			win7play2 = pos1play2 == true && pos5play2 == true && pos9play2 == true;
			win8play2 = pos3play2 == true && pos5play2 == true && pos7play2 == true;

			cout << "\n";
			
			cout << "\n";

			if (win1play1 || win2play1 || win3play1 || win4play1 || win5play1 || win6play1 || win7play1 || win8play1) {
				cout << "\nJogador 1 Ganhou!!!";
				cout << "\n";
				parar = 1;
				placar1 += 1;
			}
			else if (win1play2 || win2play2 || win3play2 || win4play2 || win5play2 || win6play2 || win7play2 || win8play2) {
				cout << "\nJogador 2 Ganhou!!!";
				cout << "\n";
				placar2 += 1;
				parar = 1;
			}
			else if (empate) {
				cout << "\nEmpate!!!";
				parar = 1;
			}
			else {
				if (vez == true) {
					jogada = false;

					cout << "\n Vez do jogador 1: ";
					cin >> play1pos;
					while (!jogada)
					{
						if (play1pos == 1) {
							if (!pos1oc) {
								c1 = player1;
								v1 = player1;
								jogada = true;
								vez = false;
								pos1play1 = true;
							}
							else
							{
								cout << "\n escolha outra: ";
								cin >> play1pos;
							}
						}

						if (play1pos == 2) {
							if (!pos2oc) {
								c2 = player1;
								v1 = player1;
								jogada = true;
								vez = false;
								pos2play1 = true;

							}
							else
							{
								cout << "\n escolha outra: ";
								cin >> play1pos;
							}
						}

						if (play1pos == 3) {
							if (!pos3oc) {
								c3 = player1;
								v1 = player1;
								jogada = true;
								vez = false;
								pos3play1 = true;
							}
							else
							{
								cout << "\n escolha outra: ";
								cin >> play1pos;
							}
						}

						if (play1pos == 4) {
							if (!pos4oc) {
								c1 = player1;
								v2 = player1;
								jogada = true;
								vez = false;
								pos4play1 = true;

							}
							else
							{
								cout << "\n escolha outra: ";
								cin >> play1pos;
							}
						}

						if (play1pos == 5) {
							if (!pos5oc) {
								c2 = player1;
								v2 = player1;
								jogada = true;
								vez = false;
								pos5play1 = true;
							}
							else
							{
								cout << "\n escolha outra: ";
								cin >> play1pos;
							}
						}

						if (play1pos == 6) {
							if (!pos6oc) {
								c3 = player1;
								v2 = player1;
								jogada = true;
								vez = false;
								pos6play1 = true;

							}
							else
							{
								cout << "\n escolha outra: ";
								cin >> play1pos;
							}
						}

						if (play1pos == 7) {
							if (!pos7oc) {
								c1 = player1;
								v3 = player1;
								jogada = true;
								vez = false;
								pos7play1 = true;

							}
							else
							{
								cout << "\n escolha outra: ";
								cin >> play1pos;
							}
						}

						if (play1pos == 8) {
							if (!pos8oc) {
								c2 = player1;
								v3 = player1;
								jogada = true;
								pos8play1 = true;
								vez = false;
							}
							else
							{
								cout << "\n escolha outra: ";
								cin >> play1pos;
							}
						}

						if (play1pos == 9) {
							if (!pos9oc) {
								c3 = player1;
								v3 = player1;
								jogada = true;
								vez = false;
								pos9play1 = true;

							}
							else
							{
								cout << "\n escolha outra: ";
								cin >> play1pos;
							}
						}

					}
				}
				else if (vez == false) {
					jogada = false;
					cout << "\n Vez do jogador 2: ";
					cin >> play2pos;
					while (!jogada)
					{
						if (play2pos == 1) {
							if (!pos1oc) {
								c1 = player2;
								v1 = player2;
								jogada = true;
								vez = true;
								pos1play2 = true;
							}
							else
							{
								cout << "\n escolha outra: ";
								cin >> play2pos;
							}
						}

						if (play2pos == 2) {
							if (!pos2oc) {
								c2 = player2;
								v1 = player2;
								jogada = true;
								vez = true;
								pos2play2 = true;
							}
							else
							{
								cout << "\n escolha outra: ";
								cin >> play2pos;
							}
						}

						if (play2pos == 3) {
							if (!pos3oc) {
								c3 = player2;
								v1 = player2;
								jogada = true;
								vez = true;
								pos3play2 = true;
							}
							else
							{
								cout << "\n escolha outra: ";
								cin >> play2pos;
							}
						}

						if (play2pos == 4) {
							if (!pos4oc) {
								c1 = player2;
								v2 = player2;
								jogada = true;
								vez = true;
								pos4play2 = true;

							}
							else
							{
								cout << "\n escolha outra: ";
								cin >> play2pos;
							}
						}

						if (play2pos == 5) {
							if (!pos5oc) {
								c2 = player2;
								v2 = player2;
								jogada = true;
								vez = true;
								pos5play2 = true;
							}
							else
							{
								cout << "\n escolha outra: ";
								cin >> play2pos;
							}
						}

						if (play2pos == 6) {
							if (!pos6oc) {
								c3 = player2;
								v2 = player2;
								vez = true;
								jogada = true;
								pos6play2 = true;

							}
							else
							{
								cout << "\n escolha outra: ";
								cin >> play2pos;
							}
						}

						if (play2pos == 7) {
							if (!pos7oc) {
								c1 = player2;
								v3 = player2;
								jogada = true;
								vez = true;
								pos7play2 = true;
							}
							else
							{
								cout << "\n escolha outra: ";
								cin >> play2pos;
							}
						}

						if (play2pos == 8) {
							if (!pos8oc) {
								c2 = player2;
								v3 = player2;
								jogada = true;
								vez = true;
								pos8play2 = true;

							}
							else
							{
								cout << "\n escolha outra: ";
								cin >> play2pos;
							}
						}

						if (play2pos == 9) {
							if (!pos9oc) {
								c3 = player2;
								v3 = player2;
								jogada = true;
								vez = true;
								pos9play2 = true;

							}
							else
							{
								cout << "\n escolha outra: ";
								cin >> play2pos;
							}
						}

					}

				}
			}
			
			if (pos1play1) {
				cout << "\n  O |";
			}
			else if (pos1play2)
			{
				cout << "\n  X |";
			}
			else {
				cout << "\n  1 |";
			}

			if (pos2play1) {
				cout << " O |";
			}
			else if (pos2play2)
			{
				cout << " X |";
			}
			else {
				cout << " 2 |";
			}
			if (pos3play1) {
				cout << " O ";
			}
			else if(pos3play2) {
				cout << " X ";
			}
			else
			{
				cout << " 3 ";
			}
			cout << "\n ---|---|---";
			cout << "\n";
			if (pos4play1) {
				cout << "  O |";
			}
			else if (pos4play2)
			{
				cout << "  X |";
			}
			else {
				cout << "  4 |";
			}

			if (pos5play1) {
				cout << " O |";
			}
			else if (pos5play2)
			{
				cout << " X |";
			}
			else {
				cout << " 5 |";
			}

			if (pos6play1) {
				cout << " O ";
			}
			else if (pos6play2)
			{
				cout << " X ";
			}
			else {
				cout << " 6 ";
			}
			cout << "\n ___|___|___";
			cout << "\n";

			if (pos7play1) {
				cout << "  O |";
			}
			else if (pos7play2)
			{
				cout << "  X |";
			}
			else {
				cout << "  7 |";
			}

			if (pos8play1) {
				cout << " O |";
			}
			else if (pos8play2)
			{
				cout << " X |";
			}
			else {
				cout << " 8 |";
			}

			if (pos9play1) {
				cout << " O ";
			}
			else if (pos9play2)
			{
				cout << " X ";
			}
			else {
				cout << " 9 ";
			}

			cout << "\n";
		}
	
		cout << "\n1 - Jogar Novamente" << "\n2 - Sair\n";
		cin >> parti;
		switch (parti)
		{
		case 1:
			parar = 0;
			break;
		case 2:
			partidas = 1;
		default:
			break;
		}
	}
}
