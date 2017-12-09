#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

void main() {
	string input;
	cin >> input;
	int sum = 0;
	int temp = 0;
	int prior = 0;
	int p_prior = 0;
	char d;


	for (int i = 0; input[i] != NULL; i++) {
		char c = input[i];
		if (c != NULL) {
			if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' ) {
				temp = c - 48;
				if (c == '1') {
					if (input[i + 1] == '0') {
						temp = 10;
						i = i + 1;
					}
				}
			}
			else if (c == 'S' || c == 'D' || c == 'T') {
				if (c == 'S')
					temp = pow(temp,1);
				else if (c == 'D')
					temp = pow(temp, 2);
				else
					temp = pow(temp, 3);
				prior = temp;
				if (sum != NULL)
					p_prior = sum;
				sum += prior;
				temp = 0;
			}
			else
				if (c == '*' || c == '#') {
					sum -= prior;
					if (c == '*') {
						sum -= p_prior;
						p_prior *= 2;
						prior *= 2;
						sum += p_prior + prior;
					}
					else
						sum -= prior;
				}
		}
		else
			break;
	}
	cout << sum << endl;
	system("pause");
}