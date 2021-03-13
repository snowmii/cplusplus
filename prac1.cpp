#include <iostream>
#include <string>

using namespace std;
int main() {
	char alphabets[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	int arr[26] = {}; 
	string str;
	getline(cin, str, '\n');
	
	for(int i = 0; i < str.size(); i++) {
		for(int j = 0; j < 26; j++) {
			if(alphabets[j] == str[i]) {
				arr[j] = arr[j] + 1;
				break;
			}
		}
	}
	for(int i = 0; i < 26; i++) {
		if(arr[i] != 0)
			cout<<alphabets[i]<<": "<<arr[i]<<endl;
	}
} 
