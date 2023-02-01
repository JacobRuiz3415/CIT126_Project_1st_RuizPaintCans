//this is a program for managing paint Inventory
#include <iostream>//preprocessing directives
#include <string>
#include <fstream>
#include "paintType.h"

using namespace std;

//function prototype
void getPaintList(ifstream& input, paintType paintlist[], int size);//get the paintlist from the input file
bool searchPaintName(string t, paintType pt[], int size);//checking a paint with a name exist in the list
int findPaintLocation(string n, paintType pt[], int size);//return the index of  a paint with a name exist in the list
void displayPaintList(paintType pt[], int size);//display the paintlist
void displayMenu();//display the options
void sortPaintByStock(paintType pt[], int size);
void printReport(ostream& output, paintType[], int size);//output the paint list in a report file

int main()
{
	//variable declarations
	int choice;
	ifstream infile;	
	ofstream report;
	string name;
	double newPrice;
	int newStock;

	const int  INVENTORY_SIZE = 5;
	paintType paintList[INVENTORY_SIZE];
	infile.open("Paints.txt");
	
	cout << "opening application............." << endl;
	cout << "checking file..................." << endl;
	cout << endl;

	if (!infile)
	{
		cout << "file does to not exist" << endl;
		return 1;
	}


	report.open("report.txt");
	
	//get paints info from the input file
	getPaintList(infile, paintList, INVENTORY_SIZE);


	displayPaintList(paintList, INVENTORY_SIZE);
	//selection
	do
	{
		displayMenu();
		cout << "enter your choice: ";
		cin >> choice;
		cout << endl;
		switch (choice)
			{
				case 1:
					displayPaintList(paintList,INVENTORY_SIZE);
					break;
				case 2:
					//sort list in ordered
					sortPaintByStock(paintList, INVENTORY_SIZE);
					break;
				case 3:
					//update the price of a paint
					

					cout << "Enter the name of the paint you want to change price" << endl;
					cout << "use - for spaces" << endl;
					cout << "name: ";
					cin >> name;
					cout << endl;

					if (searchPaintName(name, paintList, INVENTORY_SIZE))
					{

						do
						{
							cout << "enter new price: ";
							cin >> newPrice;

							if (newPrice < 0.0)
							{
								cout << "incorrect input" << endl;
								cout << "please enter the price again" << endl;
							}
						} while (newPrice < 0);
						

						paintList[findPaintLocation(name, paintList, INVENTORY_SIZE)].setPrice(newPrice);
						cout << "the price for Paint Name: " << paintList[findPaintLocation(name, paintList, INVENTORY_SIZE)].getPaintName() << " is now $" << paintList[findPaintLocation(name, paintList, INVENTORY_SIZE)].getPrice() << endl;
					}
					else
					{
						cout << "sorry, please enter again" << endl;
					}
					cout << endl;
					break;

				case 4:
					//find and calculate the total cost of stock with specific paint; 
					cout << "Enter the name of the paint you want to change price" << endl;
					cout << "use - for spaces" << endl;
					cout << "name: ";
					cin >> name;
					cout << endl;

					if (searchPaintName(name, paintList, INVENTORY_SIZE))
					{
						cout << "given a stock of " << paintList[findPaintLocation(name, paintList, INVENTORY_SIZE)].getStock() << " with the price of $" << paintList[findPaintLocation(name, paintList, INVENTORY_SIZE)].getPrice() << endl;
						cout << paintList[findPaintLocation(name, paintList, INVENTORY_SIZE)].getTotal();
					}
					else
					{
						cout << "Sorry the name does not exist in the list" << endl;
					}

					cout << endl;
					break;
				case 5:
					//update stock
					cout << "Enter the name of the paint you want to change price" << endl;
					cin >> name;
					cout << endl;

					if (searchPaintName(name, paintList, INVENTORY_SIZE))
					{
						cout << "enter the upadated stock for that paint";
						cin >> newStock;


						paintList[findPaintLocation(name, paintList, INVENTORY_SIZE)].setStock(newStock);
						cout << "number of the name" << "given a stock of " << paintList[findPaintLocation(name, paintList, INVENTORY_SIZE)].getStock() << "  in stock is now " << "given a stock of " << paintList[findPaintLocation(name, paintList, INVENTORY_SIZE)].getPaintName();
					}
					else
					{
						cout << "sorry, please enter again" << endl;
					}

					break;
				case 6:
					//ouput list to a output file
					printReport(report, paintList, INVENTORY_SIZE);
					
					cout << "Report created " << endl;
					cout << endl;
					break;
				case -1:
					//exit
					cout << "closing application......." << endl;
					break;
				default:
					cout << "incorrect input" << endl;
					break;
			}
		
		
	}while (choice != -1);



	infile.close();
	report.close();

	return 0;
}


//function definitions
void getPaintList(ifstream& input, paintType paintlist[], int size)
{
	string name;
	string brand;
	double price;
	int stock;
	for (int index = 0; index < size; index++)
	{
		input >> name >> brand >> price >> stock ;
		paintlist[index].setPaintinfo(name, brand, price, stock);

	}
	
}

bool searchPaintName(string t, paintType pt[],int size)
{
	bool found = false;


	for (int i = 0; i < size; i++)
	{
	

		if (pt[i].getPaintName() == t)
		{
			found = true;
		}
	}


	return found;
}
int findPaintLocation(string n, paintType pt[], int size)
{
	int index = 0;
	int location = 0;
	
	for (int i = 0; i < size; i++)
	{
		if (pt[i].getPaintName() == n)
		{
			location = i;

		}
	}

	return location;
}

void displayPaintList(paintType pt[], int size)
{
	cout << "******** Paint Inventory *******" << endl;
	cout << " Name" << setw(17) << "Brand" << setw(13) << "Price" << "      " << "Stock" << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < size; i++)
	{
		pt[i].displayPaint();
	}
	cout << endl;
}

void displayMenu()
{
	cout << "Enter a number to pick a action or enter -1 to exit" << endl;
	cout << "Type 1 to display the current list" << endl;
	cout << "Type 2 to sort paint by the of number cans in stock" << endl;
	cout << "Type 3 to change a price of a paint" << endl;
	cout << "Type 4 to calculate the total cost of stock" << endl;
	cout << "Type 5 to update a paint's stock " << endl;
	cout << "Type 6 to output a report file" << endl;
	cout << endl;


}

void sortPaintByStock(paintType pt[], int size)
{
	paintType temp;

	for ( int j =  0;  j < size ; j++)
	{
		if (pt[j].getStock() < pt[j + 1].getStock())
		{
			temp = pt[j];
			pt[j] = pt[j + 1];
			pt[j + 1] = temp;
		}
	}
}

void printReport(ostream& output, paintType pt[], int size)
{
	output << "******** Paint Inventory *******" << endl;
	output << " Name" << setw(17) << "Brand" << setw(13) << "Price" << "      " << "Stock" << endl;
	output  << "----------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < size - 1; i++)
	{
		pt[i].outFilePaint(output);
	}

	cout << endl;
}
