#include <cstring>
#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm> //remove

using namespace std;

string solution(string new_id) {
    int i=0;
	while(new_id[i]) {
		if (isupper(new_id[i])) //1
			new_id[i] += 32;
		if (!isalpha(new_id[i]) && !isdigit(new_id[i]) && !strchr("-_.", new_id[i])) //2
			new_id[i] = ' ';
		if (new_id[i] == '.') {
			if (new_id[i+1] == '.') { //3
				i++;
				while(new_id[i] == '.')
					new_id[i++] = ' ';
				i--;
			}
		}
		i++;
	}
	new_id.erase(remove(new_id.begin(), new_id.end(), ' '), new_id.end());
	if (new_id[0] == '.') //4
		new_id[0] = ' ';
	if (new_id[new_id.length()-1] == '.')
		new_id[new_id.length()-1] = ' ';
	new_id.erase(remove(new_id.begin(), new_id.end(), ' '), new_id.end());
	if (new_id == "") //5
		new_id.push_back('a');
	if (15 < new_id.length()) //6
		new_id.erase(new_id.begin()+15, new_id.end());
	if (*(new_id.end()-1) == '.')
		new_id.erase(new_id.end()-1, new_id.end());
	while (new_id.length() < 3) { //7
		new_id.push_back(*(new_id.end()-1));
	}
    return new_id;
}

int main()
{
	string str("...!@BaT#*..y.abcdefghijklm");
	cout << solution(str) << "  len:" << solution(str).length() << endl;
}