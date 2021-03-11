#include <iostream>

using namespace std;

int main() {
	int surr[9][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
	int playfield[10][10] = {};
	int bombs[10] = {};
	
    char c;
    int i=0;
    while((c = getchar()) != '\n') {
        if(c != ' ') {
            ungetc(c, stdin);
            cin>>bombs[i++];
        }
    }
	
	for (int i = 0; i < 10; i++) {
		int ten = bombs[i] / 10;
		int num = bombs[i] - 10 * ten;
		playfield[ten][num] = -1;
		//cout<<ten<<", "<<num<<endl;
	}
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			
			for (int k = 0; k < 9; k++) {
				if (i + surr[k][0] >= 10 || i + surr[k][0] < 0 || j + surr[k][1] >= 10 || j + surr[k][1] < 0) {
					continue;
				}
				if (playfield[i + surr[k][0]][j + surr[k][1]] == -1) {
					
				}
			}
		}
	}
}


