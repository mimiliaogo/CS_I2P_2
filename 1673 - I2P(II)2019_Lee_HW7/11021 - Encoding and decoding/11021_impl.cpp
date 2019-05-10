#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include "11021_function.h"
//AAAAAEEEE
void RleCodec::encode()
{
    char number='A';
    char c;
    std::string encode_str;
    int i=0;
    while (code_str[i]!='\0') {
        c = code_str[i];
        i++;
        while (code_str[i]==c&&number!='Z') {
            number++;
            i++;
        }
        encode_str.push_back('Q');
        encode_str.push_back(number);
        encode_str.push_back(c);
        number = 'A';
    }
    code_str = encode_str;
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
