#include <iostream>

using namespace std;

int main() {
	char keyboard[10][4] = {	
		{'1', 'Q', 'A', 'Z'},
		{'2', 'W', 'S', 'X'},
		{'3', 'E', 'D', 'C'},
		{'4', 'R', 'F', 'V'},
		{'5', 'T', 'G', 'B'},
		{'6', 'Y', 'H', 'N'},
		{'7', 'U', 'J', 'M'},
		{'8', 'I', 'K', ','},
		{'9', 'O', 'L', '.'},
		{'0', 'P', ';', '/'}			
	};
	char specs[14][2] {
		{'!', '1'}, {'@', '2'}, {'#', '3'}, {'$', '4'}, {'%', '5'}, {'^', '6'}, {'&', '7'}, {'*', '8'}, {'(', '9'}, {')', '0'},
		{':', ';'},
		{'<', ','}, {'>', '.'}, {'?', '/'}
	};
	
	int surr[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
	
	int count;
	cin>>count;
	char arr[count] = {};
	int arr2[count] = {};
	for (int i = 0; i < count; i++) {
		char c;
		while((c = getchar()) != ' ') {
            	ungetc(c, stdin);
            	cin>>arr[i];
    	}
    	while((c = getchar()) != ' ' && c != '\n') {
            	ungetc(c, stdin);
            	cin>>arr2[i];       	
    	}
	}
	
	for (int i = 0; i < count; i++) {
		char ans;
		for (int s = 0; s < 14; s++) {
			if (specs[s][0] == arr[i]) {
				arr[i] = specs[s][1];
				break;
			}
		}
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 4; k++) {
				if (keyboard[j][k] == arr[i]) {
					int x = j + surr[arr2[i] - 1][0];
					int y = k + surr[arr2[i] - 1][1];
					if (x >= 10) {
						x = 0;
					} else if (x < 0) {
						x = 9;
					}
					if (y >= 4) {
						y = 0;
					} else if (y < 0) {
						y = 3;						
					}
					ans = keyboard[x][y];
				}
			}
		}
		cout<<ans<<endl;
	}
	
	
}
