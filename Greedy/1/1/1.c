#include <stdio.h>

int coinCount(int n) {
	int change = n;
	int n500 = 0;
	int n100 = 0;
	int n50 = 0;
	int n10 = 0;

	while (change >= 500) {
		change = change - 500;
		n500++;
	}
	while (change >= 100) {
		change = change - 100;
		n100++;
	}
	while (change >= 50) {
		change = change - 50;
		n50++;
	}
	while (change >= 10) {
		change = change - 10;
		n10++;
	}
	
printf("500�� : %d��, 100�� : %d��, 50�� : %d��, 10�� : %d��", n500, n100, n50, n10);
}

int main() {
	coinCount(5420);

}