#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
	int map1[n][n];
	int map2[n][n];

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			map1[i][n-1-j] = arr1[i] & 1;
			arr1[i] >>= 1;
		}
	}
	cout << endl;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			map2[i][n-1-j] = arr2[i] & 1;
			arr2[i] >>= 1;
		}
	}
	cout << endl;
	for(int i=0; i<n; i++) {
		string tempStr = "";
		for(int j=0; j<n; j++) {
			if (map1[i][j] == 1 || map2[i][j] == 1) {
				tempStr.append("#");
			}
			else {
				tempStr.append(" ");
			}
		}
		answer.push_back(tempStr);
	}
    return answer;
}

int main(void) {
	vector<int> arr1, arr2;

	arr1.push_back(9);
	arr1.push_back(20);
	arr1.push_back(28);
	arr1.push_back(18);
	arr1.push_back(11);

	arr2.push_back(30);
	arr2.push_back(1);
	arr2.push_back(21);
	arr2.push_back(17);
	arr2.push_back(28);

	vector<string> res;
	res = solution(5, arr1, arr2);
	for(int i=0; i<5; i++) {
		cout << "|" << res[i] << "|" << endl;
	}
}