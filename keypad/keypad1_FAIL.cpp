#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
	string answer = "";
	string majorHand = hand.compare("right") == 0 ? "R" : "L";
	string tempHand;
	int left = 10;
	int right = 12;
	int lcmp=0;
	int rcmp=0;

	for (int i=0; numbers[i]; i++) {
		if (numbers[i] == 0) {
			numbers[i] = 11;
			cout << "HERE: " << numbers[i] << endl;
		}
		if (numbers[i] % 3 == 0) {
			answer += "R";
			right = numbers[i];
		}
		else if ((numbers[i] - 1) % 3 == 0) {
			answer += "L";
			left = numbers[i];
		}
		else {
			if ((right - 2) % 3 == 0) {
				rcmp = abs((right-numbers[i])/3);
			}
			else {
				if (abs(right-numbers[i]) < 3) {
					rcmp = abs(right-numbers[i]);
					if (rcmp % 2 == 0) {
						rcmp += rcmp/2;
					}
				}
				else
					rcmp = abs(right-numbers[i]) < abs((right-numbers[i])/3)? abs(right-numbers[i]) : abs((right-numbers[i])/3);
			}
			if ((left - 2) % 3 == 0) {
				lcmp = abs((left-numbers[i])/3);
			}
			else {
				if (abs(left-numbers[i]) < 3) {
					lcmp = abs(left-numbers[i]);
					if (lcmp % 2 == 0) {
						lcmp += lcmp/2;
					}
				}
				else
					lcmp = abs(left-numbers[i]) < abs((left-numbers[i])/3)? abs(left-numbers[i]) : abs((left-numbers[i])/3);
			}
			if (lcmp == rcmp)
				answer += majorHand;
			else
				answer += rcmp < lcmp ? "R" : "L";
		}
	}
	return answer;
}

int main (void) {
	vector<int>arr;

	arr.push_back(1);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(8);
	arr.push_back(2);
	arr.push_back(1);
	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(9);
	arr.push_back(5);
	cout << solution(arr, "right");

}
