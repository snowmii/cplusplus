#include <iostream>
#include <sstream>	
#include <string>

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
		string line = "";
		for (int j = 0; j < 10; j++) {
			if (playfield[i][j] != -1) {
				for (int k = 0; k < 9; k++) {
					if (i + surr[k][0] >= 10 || i + surr[k][0] < 0 || j + surr[k][1] >= 10 || j + surr[k][1] < 0) {
						continue;
					}
					if (playfield[i + surr[k][0]][j + surr[k][1]] == -1) {
						playfield[i][j] = playfield[i][j] + 1;	
					}
				}
				string count;
				if(playfield[i][j] == 0) {
					count = " ";
				} else {
					stringstream ss;
					ss << playfield[i][j];
					count = ss.str();
				}
				line = line + count + " ";
			} else {
				line = line + "* ";
			}
		}
		cout<<line<<endl;
	}
}


