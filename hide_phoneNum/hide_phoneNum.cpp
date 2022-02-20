#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string phone_number) {
	int		i;
	string	answer;
    int		len = phone_number.length();
	
	i = 0;
	while (i < len-4) {
		answer.push_back('*');
		i++;
	}
	while (i < len) {
		answer.push_back(phone_number[i]);
		i++;
	}

    return answer;
}

int	main() 
{
	std::cout << solution("01033334444") << std::endl;
}