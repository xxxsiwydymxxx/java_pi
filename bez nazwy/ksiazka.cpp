#include <iostream>
#include <string>

struct PersonalData {
	std::string FirstName;
	char LastName[50];
	int age;
};

void ReadPd(PersonalData *pd)
{
	std::cout << "Podaj imie" << std::endl;
	std::cin >> pd->FirstName;

	std::cout << "Podaj imie" << std::endl;
	std::cin >> pd->FirstName;

	std::cout << "Podaj imie" << std::endl;
	std::cin >> pd->FirstName;
}

void ShowPersonalData(PersonalData *pd)
{
	std::cout << pd->FirstName << "" << pd->LastName << std::endl;
}

int main()
{	
	const int maxSize = 100;
	PersonalData pd[maxSize];
	for (int i = 0; i < 100; i++)
	{
		ReadPd(pd+1);
		
	}
	for (int i = 0; i < 100; i++)
	{
		ShowPersonalData(pd); //ShowPersonalData(%pd[i]);
	}

	//ReadPd(&pd);
	//ShowPersonalData(&pd);
	

	
}
