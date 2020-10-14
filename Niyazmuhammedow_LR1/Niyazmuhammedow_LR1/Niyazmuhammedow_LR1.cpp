// Niyazmuhammedow_LR1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <type_traits>
#include <fstream>

using namespace std;

template <typename n_type>
n_type proverka(n_type min, n_type max) {
	n_type a;
	while (!(cin >> a) || (a > max) || (a < min))
	{
		cin.clear();
		cin.ignore();
		cout << "Povtori, please" << endl;
	}
	return a;
}

struct Pipe {
	 int id;
	 int length;
	 int diametr;
	 bool isRepair;

	 bool isExist;
	 Pipe() { isExist = false; };

	 void Input()
	 {
		 cout << "Vvedite id of trumpt\n";
		 id = proverka(1, 1000000);
		 cout << "Vvedite length of trumpt\n";
		 length = proverka(1, 1000000);
		 cout << "Vvedite diametr\n";
		 diametr = proverka(0, 1000000);
		 cout << "Trumpt is repair?(no-0,yes-1)\n";
		 isRepair = proverka(0,1);
		 isExist = true;
	 }

	 void Output()
	 {
		 cout << "\n";
		 cout << " id of truby:";cout<< id << endl;
		 cout << " length:";cout<< length << endl;
		 cout << " diametr";cout<< diametr << endl;
			 if (isRepair) cout << " Trumpt is repair\n";
			 else cout << " Trumpt is not repair\n";
	 }

	 void OutputF()
	 {

		 ofstream fout("outTRUBA.txt");
		 fout << id << endl;
		 fout << length << endl;
		 fout << diametr << endl;
		 fout << isRepair << endl;
		 fout << isExist;
		 fout.close(); 

	 }

	 void InputF()
	 {
		 ifstream fin("outTRUBA.txt"); // открыли файл для чтения
		 if (!fin.is_open()) // если файл не открыт
			 cout << "Ne otcryvaetsya\n"; // сообщить об этом
		 else
		 {
			 fin >> id;
			 fin >> length;
			 fin >> diametr;
			 fin >> isRepair;
			 fin >> isExist;
		 }
		 fin.close();
	 }
};

struct KS {
	int id;
	string name;
	int quantity;
	int quantityCanWork;
	int efficiency;
	bool isExist;
	KS() { isExist = false; }


	void Input()
	{
		cout << "Vvedite id KS\n";
		id = proverka(1, 1000000);
		cout << "Vvedite quantity\n";
		cin >> name;
		cout << "Vvedite quantity\n";
		quantity = proverka(1, 1000000);
		cout << "Vvedite quantityCanWork\n";
		quantityCanWork = proverka(1, quantity);
		cout << "Vvedite efficiency\n";
		efficiency = proverka(1, 1000000);
		isExist = true;
	}

	 void Output()
	{
		cout << "\n";
		cout << "id of KS:"; cout << id << endl;
		cout << "name:";cout<<name<< endl;
		cout << "quantity";cout<<quantity<< endl;
		cout << "quantity can work:";cout<< quantityCanWork << endl;
		cout << "efficiency:";cout<< efficiency << endl;

	}

	 void OutputF()
	 {
		 
		 ofstream fout("outKS.txt"); 
		 fout << id << endl;
		 fout << name << endl;;
		 fout << quantity << endl;
		 fout << quantityCanWork << endl;
		 fout << efficiency << endl;
		 fout << isExist;
		 fout.close(); // закрываем файл
	
	}

	 void InputF()
	 {
		 ifstream fin("outKS.txt"); // открыли файл для чтения
		 if (!fin.is_open()) // если файл не открыт
			 cout << "Ne otcryvaetsya\n"; // сообщить об этом
		 else
		 {
			 fin >> id;
			 fin >> name;
			 fin >> quantity;
			 fin >> quantityCanWork;
			 fin >> efficiency;
			 fin >> isExist;
			
		 }
		 fin.close();
	 }

};



void menu()
{
	cout << "1. Dobavit trubu\n";
	cout << "2. Dobavit KS\n";
	cout << "3. Prosmotr vseh obectov\n";
	cout << "4. Redaktirovat trubu\n";
	cout << "5. Redaktirovat KS\n";
	cout << "6. Sohranit v fail\n";
	cout << "7. Zagruzit\n";
	cout << "0. exit\n";
}

int main()
{
	int x;
	Pipe truba;
	KS ks;
	
	while (true)
	{
		menu();
		x = proverka(0, 7);
		switch (x)
		{
		case 1: {
		
			truba.Input();
			break;
		}
		case 2: {
			ks.Input();
			break;
		}
		case 3: {
			
			if (ks.isExist) ks.Output();
			else cout << "net dannyh o KS\n";

			if (truba.isExist) truba.Output();
			else cout << "net dannyh o trube\n";
			break;
		}
		case 4: {
			truba.isRepair = !truba.isRepair;
			if (truba.isRepair) cout << "truba teper rabotaet\n";
			else cout << "truba ushla v remont\n";
		}
		case 5: {
			cout << "Kol-vo cehov v rabote:" + ks.quantityCanWork << endl;
			cout << "Hotite uvelichit ili umenshit (1-uvelichit,0 umenshit)\n";
			bool isUvel;
			isUvel = proverka(0, 1);
			int cehs;
			if (isUvel) {
				cout << "Slolko cehov gotovo na4at rabotat:";
				cehs = proverka(1, ks.quantity - ks.quantityCanWork);
				ks.quantityCanWork += cehs;
				
			}
			else {
				cout << "Slolko cehov perestayut rabotat:";
				cehs = proverka(1, ks.quantityCanWork);
				ks.quantityCanWork -= cehs;
				
			}
		}
		case 6: {
			if (ks.isExist) ks.OutputF();
			else cout << "net dannyh o KS\n";

			if (truba.isExist) truba.OutputF();
			else cout << "net dannyh o trube\n";
		
			break;
		}
		case 7: {
			ks.InputF();
			truba.InputF();
			break;
		}
		case 0: {
			return 0;
		}
		default:
			break;
		}
    }
	return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
