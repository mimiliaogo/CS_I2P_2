#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include "function.h"
//AAASS--->QCABS
void RleCodec::encode()
{
    char c;
    char cnt = 'A';
    int i=0;
    std::string new_str;
    while (code_str[i]!='\0') {
        new_str.push_back('Q');
        c = code_str[i];
        i++;
        cnt = 'A';
        while (code_str[i]==c&&cnt<'Z') {
            cnt++;
            i++;
        }
        new_str.push_back(cnt);
        new_str.push_back(c);
    }
    code_str = new_str;
    encoded = true;
}

void RleCodec::decode()
{
	std::stringstream os;
	std::string int_str;
	char q = 'A';
	char number = ' ';
	int cnt = 0;
	for (auto c : code_str) {
        if (q=='A') {
            q = c;
		}else if(number == ' '){
            number = c;
		}
        else {
            int_str.push_back(c);
			int cnt = 0;
            cnt = number - 'A' +1;
            for (int i=0; i<cnt; ++i)
					os << c;
			int_str.clear();
			number = ' ';
			q = 'A';
		}
	}

	code_str = os.str();
	encoded = false;
}
