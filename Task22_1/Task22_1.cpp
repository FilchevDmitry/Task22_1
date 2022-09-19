#include <iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

int main()
{
	int number = 0;
	bool exit = true;
	string phone;
	string names_phone;
	map <string, vector <string>> name;
	map <string, string> call;

	while (exit)
	{
		cout << "\nWhat do you want to do :\n1 - add a new contact,\n2 - find out the name of the subscriber,\n3 - find out the phone number\n4-exit\n";
		cin >> number;
		if (number == 1)
		{
			cout << "Enter your phone number : ";
			cin >> phone;
			cout << "Enter name : ";
			cin >> names_phone;
			if (name.find(names_phone) != name.end())
			{
				name[names_phone].push_back(phone);
				call.insert(pair<string, string>(phone, names_phone));
			}
			else
			{
				call.insert(pair<string, string>(phone, names_phone));
				name[names_phone].push_back(phone);
			}
			
		}
		else if (number == 2)
		{
			cout << "\nEnter your phone number : ";
			cin >> phone;
			auto find_map = call.find(phone);
			if (find_map != call.end()) {
				cout << "Name - " << find_map->second<<"\n";
			}
			else {
				cout << "This number is not in the database!" << endl;
			}
		
		}
		else if (number == 3)
		{
			cout << "\nEnter name : ";
			cin >> names_phone;
			auto find_map = name.find(names_phone);
			if (find_map != name.end()) 
			{
				cout << find_map->first << "\n";
				for (auto n : name[names_phone])
					cout << n << endl;
			}
			else {
				cout << "This name is not in the database!" << endl;
			}
		}
		else if (number == 4)
		{
			exit = false;
		}
		else
			cout << "\nInvalid input" << endl;
	}
}

