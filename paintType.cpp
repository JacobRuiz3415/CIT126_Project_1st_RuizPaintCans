#include "paintType.h"

int paintType::getStock()
{
	return stock;
}

double paintType::getPrice()
{
	return price;
}

string paintType::getPaintName()
{
	return paintName;
}

void paintType::setPrice(double p)
{
	price = p;
}

void paintType::setStock(int sNum)
{
	stock = sNum;
}

void paintType::displayPaint()
{
	cout << " " << paintName << setw(19) << paintBrand << setw(13) << price << setw(9) << stock << endl;
}

void paintType::outFilePaint(ostream& op)
{
	op << " " << paintName << setw(19) << paintBrand << setw(13) << price << setw(9) << stock << endl;
}

double paintType::getTotal()
{
	return price * stock;
}

void paintType::setPaintinfo(string n, string b, double p, int sNum)
{
	paintName = n;
	paintBrand = b;
	price = p;
	stock = sNum;
}