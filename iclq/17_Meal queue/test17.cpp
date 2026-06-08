#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	//ifstream inputFile("in.txt");

	int T;
	cin >> T;
	cin.ignore();
	queue<string> pq;
	while(T--)
	{
		string str;
		//cin >> str;
		getline(cin,str);
		//cout << str << endl;
		if (str == "QueueHead")
		{
			if (!pq.empty())
			{
				cout << pq.front() << endl;
				continue;
			}
			cout << "Empty queue" << endl;
		}
		else if (str == "QueueTail")
		{
			if (!pq.empty())
			{
				cout << pq.back()<< endl;
				continue;

			}
			cout << "Empty queue" << endl;
		}
		else if (str == "Leave")
		{
			if (!pq.empty())//¹¦³ÉÍò¹Ç¿Ý
			{
				pq.pop();
			}
		}
		else 
		{
			string in = str.substr(str.find(" ")+1);
			pq.push(in);
			//cout << "push:"<<in << endl;
		}
	}
	return 0;
}