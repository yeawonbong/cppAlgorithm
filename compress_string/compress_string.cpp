/* FAILED */

#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer=0, count=1;
	int one=0, two=0, three=0;
    char	oneChar=0;
	char	*twoChar=strdup("");
	char	*threeChar=strdup("");
	int 	i = 0;

	//1
	for(i=0; s[i]; i++) {
		if (oneChar == s[i]) {
			count++;
		}
		else {
			oneChar = s[i];
			one += 1; //이전 char
			if (1 < count) {
				one++; // 숫자부분 1의자리
				while (count /= 10) {
					one++;
				}
			}
			count = 1;
		}
	}

	//2
	count=1;
	for(i=0; s[i+2]; i+=2) {
	
		if (strncmp(twoChar, &s[i], 2) == 0) {
			count++;
		}
		else {
			free(twoChar);
			twoChar = strndup(&s[i], 2);
			two += 2;
			if (1 < count) {
				two++;
				while (count /= 10) {
					two++;
				}
			}
			count = 1;
		}
	}
	free(twoChar);
	if (s[i])
		two += strlen(&s[i]);

	//3
	count=1;
	for(i=0; s[i+3]; i+=3) {
	
		if (strncmp(threeChar, &s[i], 3) == 0) {
			count++;
		}
		else {
			free(threeChar);
			threeChar = strndup(&s[i], 3);
			three += 3;
			if (1 < count) {
				three++;
				while (count /= 10) {
					three++;
				}
			}
			count = 1;
		}
	}
	if (s[i])
		three += strlen(&s[i]);
	free(threeChar);

	cout << "1: " << one << ", 2: " << two << ", 3: " << three << endl;
	answer = one < two? one : two;
	answer = three < answer? three : answer;

	return answer;
}

int main(void)
{
	cout << solution("aabbaccc"); //1:7
}