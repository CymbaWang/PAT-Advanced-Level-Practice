﻿//1035 Password(20分)
//To prepare for PAT, the judge sometimes has to generate random passwords for the users.The problem is that there are always some confusing passwords since it is hard to distinguish 1 (one)from l(L in lowercase), or 0 (zero)from O(o in uppercase).One solution is to replace 1 (one)by @, 0 (zero)by%, l by L, and O by o.Now it is your job to write a program to check the accounts generated by the judge, and to help the juge modify the confusing passwords.
//
//Input Specification :
//Each input file contains one test case.Each case contains a positive integer N(≤1000), followed by N lines of accounts.Each account consists of a user nameand a password, both are strings of no more than 10 characters with no space.
//
//Output Specification :
//For each test case, first print the number M of accounts that have been modified, then print in the following M lines the modified accounts info, that is, the user namesand the corresponding modified passwords.The accounts must be printed in the same order as they are read in.If no account is modified, print in one line There are N accountsand no account is modified where N is the total number of accounts.However, if N is one, you must print There is 1 account and no account is modified instead.
//
//Sample Input 1:
//	3
//		Team000002 Rlsp0dfa
//		Team000003 perfectpwd
//		Team000001 R1spOdfa
//		Sample Output 1 :
//		2
//		Team000002 RLsp % dfa
//		Team000001 R@spodfa
//		Sample Input 2:
//	1
//		team110 abcdefg332
//		Sample Output 2 :
//		There is 1 account and no account is modified
//		Sample Input 3 :
//		2
//		team110 abcdefg222
//		team220 abcdefg333
//		Sample Output 3 :
//		There are 2 accounts and no account is modified
//
//

#include<vector>
#include<iostream>
using namespace std;

class node
{
public:
	string acc;
	string pwd;
};

int main()
{
	int N = 0;
	cin >> N;
	vector<node> vec;
	for (int i = 0; i < N; i++)
	{
		node nod;
		cin >> nod.acc >> nod.pwd;

		bool flag = false;
		for (int j = 0; j < nod.pwd.size(); j++)
		{
			switch (nod.pwd[j])
			{
			case 'O':
				nod.pwd[j] = 'o';
				flag = true;
				break;
			case 'l':
				nod.pwd[j] = 'L';
				flag = true;
				break;
			case '0':
				nod.pwd[j] = '%';
				flag = true;
				break;
			case '1':
				nod.pwd[j] = '@';
				flag = true;
				break;
			default:
				break;
			}
		}

		if (flag)
			vec.push_back(nod);
	}

	if (vec.size() == 0&&N==1)
		cout << "There is "<<N<<" account and no account is modified";
	else if (vec.size() == 0 && N != 1)
		cout << "There are " << N << " accounts and no account is modified";
	else
	{
		cout << vec.size() << endl;
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i].acc << " " << vec[i].pwd;
			if (i != vec.size() - 1)
				cout << endl;
		}
	}


	return 0;
}