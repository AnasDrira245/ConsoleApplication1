#pragma warning(disable : 4996)
#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0) //, cout.tie(0)
#define ll long long
#define ld long double
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
//#define all(x) (x).begin(), (x).end()
#define alll(x) ((x).begin()+1), (x).end()
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
#define endl "\n"
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define karr(x) cout<<(#x)<<": ";_print(x);cout<<endl;
#define F first
#define S second
#define kar trace
#define wow cout<<"YES"<<endl;
#define INF 1e18
// old template
void _print(int x) { cout << x; }
void _print(long x) { cout << x; }
void _print(long long x) { cout << x; }
void _print(unsigned x) { cout << x; }
void _print(unsigned long x) { cout << x; }
void _print(unsigned long long x) { cout << x; }
void _print(float x) { cout << x; }
void _print(double x) { cout << x; }
void _print(long double x) { cout << x; }
void _print(char x) { cout << '\'' << x << '\''; }
void _print(const char* x) { cout << '\"' << x << '\"'; }
void _print(const string& x) { cout << '\"' << x << '\"'; }
void _print(bool x) { cout << (x ? "True" : "False"); }
//
//
template<typename T, typename V>
void _print(const pair<T, V>& x) {
    cout << '{';
    _print(x.first);
    cout << ',';
    _print(x.second);
    cout << '}';
}
template<typename T>
void _print(const T& x) {
    int f = 0;
    cout << '[';
    for (auto& i : x) cout << (f++ ? " " : ""), _print(i);
    cout << "]";
}
void _print() { cout << "]\n"; }
template<typename T, typename... V>
void _print(T t, V... v) {
    _print(t);
    if (sizeof...(v)) cout << ", ";
    _print(v...);
}

#include<fstream>

void PrintFileContent(string FileName) {

	fstream file;
	file.open(FileName, ios::in);
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			cout << line << endl;
		}
		file.close();
	}
	else {
		cout << "Error in opening file" << endl;
	}
}

void LoadDataFromFileToVector(string FileName,vector<string>&v) {
	fstream file;
	file.open(FileName, ios::in);
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			v.pb(line);
		}
		file.close();
	}
	else {
		cout << "Error in opening file" << endl;
	}
}

void SaveFileToVector(string FileName, vector<string>& v) {
	fstream file;
	file.open(FileName, ios::out);
	if (file.is_open()) {
		for (string& i : v) {
			file << i << endl;
		}
		file.close();
	}
	else {
		cout << "Error in opening file" << endl;
	}
}

void DeleteRecordFromFile(string FileName, int LineNumber) {
	vector<string>v;
	LoadDataFromFileToVector(FileName, v);
	v.erase(v.begin() + LineNumber);
	SaveFileToVector(FileName, v);
}

void UpdateRecordFromFile(string FileName, int LineNumber, string NewData) {
	vector<string>v;
	LoadDataFromFileToVector(FileName, v);
	v[LineNumber] = NewData;
	SaveFileToVector(FileName, v);
}

struct Client {
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	string AccountBalance;
};
string ReadBackClientDataRecord(string AccountNumber="") {

	Client c;
	if (AccountNumber == "") {
		cout << "Enter Account Number: ";
		getline(cin >> ws, c.AccountNumber);
	}
	else {
		c.AccountNumber = AccountNumber;
		cin.ignore();
	}
	cout << "Enter Pin Code: ";
	getline(cin, c.PinCode);
	cout << "Enter Name: ";
	getline(cin, c.Name);
	cout << "Enter Phone: ";
	getline(cin, c.Phone);
	cout << "Enter Account Balance: ";
	getline(cin, c.AccountBalance);

	cout << "Client Record for Saving : " << endl;
	string s = c.AccountNumber + "#//#" + c.PinCode + "#//#" + c.Name + "#//#" + c.Phone + "#//#" + c.AccountBalance;	
	return s;
}

Client fromLineToData(string line , string seperator) {
	Client c;
	string s;
	int sz_seperator = seperator.size();
	c.AccountNumber = line.substr(0, line.find(seperator));
	s = line.substr(line.find(seperator) + sz_seperator);
	c.PinCode = s.substr(0, s.find(seperator));
	s = s.substr(s.find(seperator) + sz_seperator);
	c.Name = s.substr(0, s.find(seperator));
	s = s.substr(s.find(seperator) + sz_seperator);
	c.Phone = s.substr(0, s.find(seperator));
	s = s.substr(s.find(seperator) + sz_seperator);
	c.AccountBalance = s;
	/*cout << "Account Number: " << c.AccountNumber << endl;
	cout << "Pin Code: " << c.PinCode << endl;
	cout << "Name: " << c.Name << endl;
	cout << "Phone: " << c.Phone << endl;
	cout << "Account Balance: " << c.AccountBalance << endl;*/

	return c;


}

void PrintClient(Client c) {
	cout << "Account Number: " << c.AccountNumber << endl;
	cout << "Pin Code: " << c.PinCode << endl;
	cout << "Name: " << c.Name << endl;
	cout << "Phone: " << c.Phone << endl;
	cout << "Account Balance: " << c.AccountBalance << endl;
}

void PrintIntoFile(string FileName,string data) {
	fstream file;
	file.open(FileName, ios::out | ios::app);
	if (file.is_open()) {
		file << data << endl;
		file.close();
	}
	else {
		cout << "Error in opening file" << endl;
	}

}

Client addNewClient() {
	string s = ReadBackClientDataRecord();
	PrintIntoFile("ClientData.txt", s);
	Client c = fromLineToData(s, "#//#");
	return c;
}

void ShowAllClientFromFile(string fileName) {
	vector<string>v;
	LoadDataFromFileToVector(fileName, v);
	for (string& i : v) {
		Client c = fromLineToData(i, "#//#");
		PrintClient(c);
		cout << endl;
	}
}

void ShowAllClientFromFileInaFancyWay(string fileName) {
	// with adding setw
	vector<string>v;
	LoadDataFromFileToVector(fileName, v);
	//clients in the center
	int numberOfClients = v.size();
	cout <<setw(50)<< "Client List of " << numberOfClients << " Clients"<< endl;
	cout << "_____________________________________________________________________________________________________________________" << endl;
	cout << setw(20) << "Account Number" << setw(20) << "Pin Code" << setw(20) << "Name" << setw(20) << "Phone" << setw(20) << "Account Balance" << endl;
	cout << "_____________________________________________________________________________________________________________________" << endl;
		for (string& i : v) {
		Client c = fromLineToData(i, "#//#");
		cout << setw(20) << c.AccountNumber << setw(20) << c.PinCode << setw(20) << c.Name << setw(20) << c.Phone << setw(20) << c.AccountBalance << endl;
	}


}

void FindClientByAccountName(string fileName, string AccountNumber) {
	vector<string>v;
	LoadDataFromFileToVector(fileName, v);
	for (string& i : v) {
		Client c = fromLineToData(i, "#//#");
		if (c.AccountNumber == AccountNumber) {
			PrintClient(c);
			return;
		}
	}
	cout << "Client Not Found" << endl;
}

void DeleteClientByAccountName(string fileName, string AccountNumber) {
	vector<string>v;
	Client c;
	LoadDataFromFileToVector(fileName, v);
	int index = -1;
	for (int i = 0; i < v.size(); i++) {
		c = fromLineToData(v[i], "#//#");
		if (c.AccountNumber == AccountNumber) {
			index = i;
			break;
		}
	}
	if (index != -1) {
		PrintClient(c);
		char x;
		cout << "Are you sure you want to delete (y/n)" << endl;
		cin >> x;
		if (x == 'y') {
			DeleteRecordFromFile(fileName, index);
			cout << "Client Deleted" << endl;
		}
		else {
			cout << "Client Not Deleted" << endl;
		}

	}
	else {
		cout << "Client Not Found" << endl;
	}
}

void UpdateClientByAccountName(string fileName, string AccountNumber) {
	vector<string>v;
	LoadDataFromFileToVector(fileName, v);
	int index = -1;
	for (int i = 0; i < v.size(); i++) {
		Client c = fromLineToData(v[i], "#//#");
		if (c.AccountNumber == AccountNumber) {
			index = i;
			break;
		}
	}
	if (index != -1) {
		string s = ReadBackClientDataRecord(AccountNumber);
		UpdateRecordFromFile(fileName, index, s);
		cout << "Client Updated" << endl;
	}
	else {
		cout << "Client Not Found" << endl;
	}
}

void ShowMenuScreen() {
	cout << "1. Add New Client" << endl;
	cout << "2. Show All Clients" << endl;
	cout << "3. Find Client By Account Number" << endl;
	cout << "4. Delete Client By Account Number" << endl;
	cout << "5. Update Client By Account Number" << endl;
	cout << "6.Transactions" << endl;
	cout << "7. Exit" << endl;
	
}

void ShowTransactionMenu() {
	cout << "1. Deposit" << endl;
	cout << "2. Withdraw" << endl;
	cout << "3. Show Total Balances" << endl;
	cout << "4. Go Back to Main Menu" << endl;
}
void ShowTotalBalances() {
		
	//printing the balance of each client then the total balance

	vector<string>v;
	LoadDataFromFileToVector("ClientData.txt", v);
	cout << "_____________________________________________________________________________________________________________________" << endl;
	cout << setw(20) << "Account Number" << setw(20) << "Pin Code" << setw(20) << "Name" << setw(20) << "Phone" << setw(20) << "Account Balance" << endl;
	cout << "_____________________________________________________________________________________________________________________" << endl;
	for (string& i : v) {
		Client c = fromLineToData(i, "#//#");
		cout << setw(20) << c.AccountNumber << setw(20) << c.PinCode << setw(20) << c.Name << setw(20) << c.Phone << setw(20) << c.AccountBalance << endl;
	}
	//calculating the total balance
	ll totalBalance = 0;
	for (string& i : v) {
		Client c = fromLineToData(i, "#//#");
		totalBalance += stoll(c.AccountBalance);
	}
	cout << "_____________________________________________________________________________________________________________________" << endl;
	cout << "Total Balance: " << totalBalance << endl;
}

void UpdateClientBalanceByAccountName(string fileName, string AccountNumber, long long balance) {
	vector<string>v;
	LoadDataFromFileToVector(fileName, v);
	int index = -1;
	for (int i = 0; i < v.size(); i++) {
		Client c = fromLineToData(v[i], "#//#");
		if (c.AccountNumber == AccountNumber) {
			index = i;
			break;
		}
	}
	if (index != -1) {
		Client c = fromLineToData(v[index], "#//#");
		c.AccountBalance = to_string(balance);
		string s = c.AccountNumber + "#//#" + c.PinCode + "#//#" + c.Name + "#//#" + c.Phone + "#//#" + c.AccountBalance;
		UpdateRecordFromFile(fileName, index, s);
		cout << "Client Updated" << endl;
	}
	else {
		cout << "Client Not Found" << endl;
	}
}

void WithDrawFromClient() {
	string AccountNumber;
	cout << "Enter Account Number: ";
	cin >> AccountNumber;
	vector<string>v;
	LoadDataFromFileToVector("ClientData.txt", v);
	int index = -1;
	for (int i = 0; i < v.size(); i++) {
		Client c = fromLineToData(v[i], "#//#");
		if (c.AccountNumber == AccountNumber) {
			index = i;
			break;
		}
	}
	if (index != -1) {
		Client c = fromLineToData(v[index], "#//#");
		cout << "Account Number: " << c.AccountNumber << endl;
		cout << "Pin Code: " << c.PinCode << endl;
		cout << "Name: " << c.Name << endl;
		cout << "Phone: " << c.Phone << endl;
		cout << "Account Balance: " << c.AccountBalance << endl;
		ll amount;
		cout << "Enter Amount to Withdraw: ";
		cin >> amount;
		if (amount > stoll(c.AccountBalance)) {
			cout << "Insufficient Balance" << endl;
			return;
		}
		c.AccountBalance = to_string(stoll(c.AccountBalance) - amount);
		UpdateClientBalanceByAccountName("ClientData.txt", c.AccountNumber, stoll(c.AccountBalance));

	}
	else {
		cout << "Client Not Found" << endl;
	}

}

enum TransactionType {
	Deposit = 1,
	Withdraw = 2,
	TotalBalance=3,
	MainMenu = 4
};


void DipositFromClient() {
	string AccountNumber;
	cout << "Enter Account Number: ";
	cin >> AccountNumber;
	vector<string>v;
	LoadDataFromFileToVector("ClientData.txt", v);
	int index = -1;
	for (int i = 0; i < v.size(); i++) {
		Client c = fromLineToData(v[i], "#//#");
		if (c.AccountNumber == AccountNumber) {
			index = i;
			break;
		}
	}
	if (index != -1) {
		Client c = fromLineToData(v[index], "#//#");
		cout << "Account Number: " << c.AccountNumber << endl;
		cout << "Pin Code: " << c.PinCode << endl;
		cout << "Name: " << c.Name << endl;
		cout << "Phone: " << c.Phone << endl;
		cout << "Account Balance: " << c.AccountBalance << endl;
		ll amount;
		cout << "Enter Amount to Deposit: ";
		cin >> amount;
		c.AccountBalance = to_string(stoll(c.AccountBalance) + amount);
		UpdateClientBalanceByAccountName("ClientData.txt", c.AccountNumber, stoll(c.AccountBalance));
		cout << "New Balance: " << c.AccountBalance << endl;
	}
	else {
		cout << "Client Not Found" << endl;
	}
}

void solve() {
	while (1) {
		ShowMenuScreen();
		int choice;
		cout << "Enter Your Choice: ";
		cin >> choice;
		cin.ignore();
		system("cls");
		if (choice == 1) {
			char x = 'y';
			while(x=='y' || x=='Y') {
				system("cls");
				Client c = addNewClient();
				cout << "Do you want to add more clients? (y/n): ";
				//cin.ignore();
				cin >> x;
			
			}
			cout << "Clients Added Successfully" << endl;
			system("pause");
		}
		else if (choice == 2) {
			ShowAllClientFromFileInaFancyWay("ClientData.txt");
			system("pause");
		}
		else if (choice == 3) {
			string AccountNumber;
			cout << "Enter Account Number: ";
			cin >> AccountNumber;
			FindClientByAccountName("ClientData.txt", AccountNumber);
			system("pause");
		}
		else if (choice == 4) {
			string AccountNumber;
			cout << "Enter Account Number: ";
			cin >> AccountNumber;
			DeleteClientByAccountName("ClientData.txt", AccountNumber);
			system("pause");
		}
		else if (choice == 5) {
			string AccountNumber;
			cout << "Enter Account Number: ";
			cin >> AccountNumber;
			UpdateClientByAccountName("ClientData.txt", AccountNumber);
			system("pause");
		}
		else if (choice == 6) {
			while (1) {
				system("cls");
				ShowTransactionMenu();
				int choice;
				cout << "Enter Your Choice: ";
				cin >> choice;
				cin.ignore();
				system("cls");
				if (choice == 1) {
					// Deposit
					cout << "Deposit" << endl;
					DipositFromClient();
					system("pause");
				}
				else if (choice == 2) {
					// Withdraw
					cout << "Withdraw" << endl;
					WithDrawFromClient();
					system("pause");
				}
				else if (choice == 3) {
					// Show Total Balances
					cout << "Show Total Balances" << endl;
					ShowTotalBalances();
					system("pause");
				}
				else if (choice == 4) {
					break;
				}
				else {
					cout << "Invalid Choice" << endl;
				}
			}
		
		}
		else if (choice == 7) {
			break;
		}
		else {
			cout << "Invalid Choice" << endl;
		}
		system("cls");
	}
	
}

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    FAST;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}