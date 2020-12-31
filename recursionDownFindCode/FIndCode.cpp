#include"FindCode.h"

string input_string;//输入串
int i = 0;//输入串的当前字符下标
//输入要匹配的输入串
void input()
{
	cin >> input_string;

}

void ParseE()
{
	if (input_string[i] == '(' || input_string[i] == 'i')
	{
		cout << "E->TE'" << endl;
		ParseT();
		ParseE2();
	}
	else
	{
		cout << "syntax error" << endl;
		exit(0);
	}
}

void ParseT()
{
	if (input_string[i] == '(' || input_string[i] == 'i')
	{
		cout << "T->FT'" << endl;
		ParseF();
		ParseT2();
	}
	else
	{
		cout << "syntax error" << endl;
		exit(0);
	}
}

void ParseE2()
{
	switch (input_string[i])
	{
		case '+':
			cout << "E'->+TE'" << endl;
			MatchToken('+');
			ParseT();
			ParseE2();
			break;
		case ')':
			cout << "E->e" << endl;
			MatchToken(')');
			break;
		case '#':
			cout << "E->e" << endl;
			MatchToken('#');
			break;
		default:
			cout << "syntax error" << endl;
			exit(0);
	}
}

void ParseT2()
{
	switch (input_string[i])
	{
		case '*':
			cout << "T'->*FT'" << endl;
			MatchToken('*');
			ParseF();
			ParseT2();
			break;
		case '+':
			cout << "T'->e" << endl;
			MatchToken('+');
			break;
		case ')':
			cout << "T'->e" << endl;
			MatchToken(')');
			break;
		case '#':
			cout << "T'->e" << endl;
			MatchToken('#');
			break;
		default:
			cout << "syntax error" << endl;
			exit(0);
	}
}

void ParseF()
{
	switch (input_string[i])
	{
		case 'i':
			cout << "F->i" << endl;
			MatchToken('i');
			break;
		case '(':
			cout << "F->(E)" << endl;
			MatchToken('(');
			ParseE();
			MatchToken(')');
			break;
		default:
			cout << "syntax error" << endl;
			exit(0);
	}
}

void MatchToken(char ch)
{
	i++;
	if (ch == '#')
	{
		cout << "success!" << endl;
		exit(0);
	}
}