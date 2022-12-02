#include <iostream>
#include <string.h>
#include <list>
#include "Family.h"
#include "ChildFamilyMember.h"
#include "WorkingFamilyMember.h"
#include "JsonFamilyFactory.h"
#include "MemoryUserRepository.h"

using namespace std;

int main()
{
	/*Family* family = new Family();
	family->LoadFromFile("file.txt");
	*/
	//Family* family = nullptr;
	/*cout << "Create family(y/n): ";
	char ch;
	cin >> ch;
	if (ch == 'y')
	{
		family = new Family();
		bool flag = true;
		while (flag)
		{
			cout << "(1)Add member" << endl;
			cout << "(2)Remove member" << endl;
			cout << "(3)Create family" << endl;
			char choice;
			cin >> choice;
			switch (choice)
			{
				case '1':
				{
					FamilyMember* member = nullptr;
					string name = "";
					string surname = "";
					cout << "Is family member an adult or not?(y/n): ";
					char choice;
					cin >> choice;
					if (choice == 'y')
					{
						cout << "Enter name: ";
						cin >> name;
						cout << "Enter surname: ";
						cin >> surname;
						member = new WorkingFamilyMember(name, surname, 0);
					}
					else
					{
						cout << "Enter name: ";
						cin >> name;
						cout << "Enter surname: ";
						cin >> surname;
						member = new ChildFamilyMember(name, surname, 0);
					}
					family->AddMember(member);
					break;
				}
				case '2' :
				{
					break;
				}
				case '3':
					flag = false;
					break;
				default:
					break;
			}
		}

	}
	else
	{
		cout << "Do you wanna load family from file?(y/n): ";
		char choice;
		cin >> choice;
		if (choice == 'y')
		{

		}
	}
	family->showAll();*/

	//Family* family = new Family();
	FamilyMember* member1 = new ChildFamilyMember("tikhon", "Tikhon", "Grek", 0);
	FamilyMember* member2 = new WorkingFamilyMember("stepaa", "Stepan", "Grek", 0);
	FamilyMember* member3 = new WorkingFamilyMember("dad", "Dad", "Grek", 0);
	FamilyMember* member4 = new WorkingFamilyMember("mam", "Mam", "Grek", 0);
	//family->AddMember(member1);
	//family->AddMember(member2);
	//static_cast<WorkingFamilyMember*>(member1)->AddJob(new Job("AOA ALENA", "KONDITER", 1500));
	//static_cast<WorkingFamilyMember*>(member1)->AddJob(new Job("AOA ALENA2", "KONDITER2", 3000));
	//static_cast<WorkingFamilyMember*>(member2)->AddJob(new Job("AOA ALENA3", "KONDITER3", 1000));
	//static_cast<WorkingFamilyMember*>(member2)->AddJob(new Job("AOA ALENA3", "KONDITER3", 1000));
	//static_cast<WorkingFamilyMember*>(member2)->AddJob(new Job("AOA ALENA3", "KONDITER3", 1000));
	//static_cast<WorkingFamilyMember*>(member2)->AddJob(new Job("AOA ALENA3", "KONDITER3", 1000));
	//static_cast<WorkingFamilyMember*>(member2)->AddJob(new Job("AOA ALENA3", "KONDITER3", 1000));
	//static_cast<WorkingFamilyMember*>(member2)->AddJob(new Job("AOA ALENA3", "KONDITER3", 1000));
	//static_cast<WorkingFamilyMember*>(member2)->AddJob(new Job("AOA ALENA3", "KONDITER3", 1000));
	//static_cast<WorkingFamilyMember*>(member2)->AddJob(new Job("AOA ALENA3", "KONDITER3", 1000));
	//member1->AddPurchase(new Purchase("Bread",member1->GetId(),15,2022));
	//member1->AddPurchase(new Purchase("Milk",member1->GetId(),62,2022));
	//member1->AddPurchase(new Purchase("Meat",member1->GetId(),74,2022));
	//member2->AddPurchase(new Purchase("Sweet",member1->GetId(),150,2022));
	//member2->AddPurchase(new Purchase("Potato",member1->GetId(),10,2022));
	//family->SaveToFile("family.json");

	list<User*> users = { member1,member2, member3, member4 };

	UserService* service = new UserService(new MemoryUserRepository(users));

	string username;
	string password;

	cout << "Enter username: " << endl;
	rewind(stdin);
	getline(cin, username);
	cout << "Enter password: " << endl;
	rewind(stdin);
	getline(cin, password);
	service->Authenticate(username, password);

	for (auto u : users)
	{
		if (u->IsAuthenticated())
			cout << u->GetUsername() << endl;
	}

	//family->SetFactory(new JsonFamilyFactory());
	//family->LoadFromFile("data.json");
	//family->showAll();
	return 0;
}






