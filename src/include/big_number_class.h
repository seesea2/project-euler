#ifndef __BIGNUMBERCLASS_H__
#define __BIGNUMBERCLASS_H__

#include "header.h"

class BigNumberC
{
public:
	BigNumberC() : integer_part_(string("0")), decimal_part_(string("0")), positive_number_(true) {}
	BigNumberC(const BigNumberC &kInit);
	BigNumberC(const string &kInit);
	BigNumberC(const char *kInit);
	BigNumberC(const double kInit);
	BigNumberC(const int kInit);
	~BigNumberC();

	friend ostream &operator<<(ostream &out, BigNumberC kObj);

	BigNumberC operator+(const BigNumberC &kObj);
	BigNumberC operator-(const BigNumberC &kObj);
	BigNumberC operator*(const BigNumberC &kObj);
	BigNumberC &operator=(const BigNumberC &kObj);
	BigNumberC &operator+=(const BigNumberC &kObj);
	BigNumberC &operator-=(const BigNumberC &kObj);
	BigNumberC &operator*=(const BigNumberC &kObj);
	bool operator==(const BigNumberC &kObj) const;
	bool operator!=(const BigNumberC &kObj) const;
	bool operator>(const BigNumberC &kObj) const;
	bool operator>=(const BigNumberC &kObj) const;
	bool operator<(const BigNumberC &kObj) const;
	bool operator<=(const BigNumberC &kObj) const;

	int GetDigitsCount() const { return integer_part_.length(); }
	string GetIntegerPart() const { return integer_part_; }
	int GetDigitsSum() const;
	string GetDigitsSumString() const;
	bool HasSameDigitsQty(const BigNumberC &kToCompare) const;
	bool IsEqual(const BigNumberC &kToCompare) const;
	bool IsPositiveNumber() const { return positive_number_; }
	BigNumberC &Divide(const BigNumberC &kToDivid);
	BigNumberC &Divide(const int &kDividInt);
	BigNumberC &Minus(const BigNumberC &kToDeduct);
	BigNumberC &Multiply(const BigNumberC &kMultiplyObj);
	BigNumberC &Multiply(const int kMultiplyInt);
	BigNumberC &MultiplySingleDigit(const int kDigit);
	BigNumberC &Plus(const BigNumberC &kToAdd);
	BigNumberC &SetToPowerOfInt(const int kBase, const int kPower);

	ostream &Print(ostream &out = std::cout) const;
	ostream &PrintFrontDigits(const int kPrintDigitsQty = 0, ostream &out = std::cout) const;
	ostream &PrintRearDigits(const int kPrintDigitsQty = 0, ostream &out = std::cout) const;

private:
	void TidyString(string &str);
	void TidyBigNumber();

	string decimal_part_;
	string integer_part_;
	bool positive_number_;
};

#endif
