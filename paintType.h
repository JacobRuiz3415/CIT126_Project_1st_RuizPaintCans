
#ifndef Paint_h
#define Paint_h

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
class paintType
{
public:

	int getStock();
	double getPrice();
	string getPaintName();
	void setPrice(double p);
	void setStock(int sNum);
	void displayPaint();
	void outFilePaint(ostream& op);
	double getTotal();
	void setPaintinfo(string n, string b, double price, int stock);

private:
	string id;
	string paintName;
	string paintBrand;
	double price = 0.0;
	int stock = 0;
	//
};
#endif // !Paint_h




