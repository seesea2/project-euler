#include "big_number_class.h"
#include "debug_header.h"

BigNumberC::BigNumberC(const BigNumberC &kInit) {
	positive_number_ = kInit.positive_number_;
	integer_part_ = kInit.integer_part_;
	decimal_part_ = kInit.decimal_part_;
}

BigNumberC::BigNumberC(const string &kInit) {
	string init = kInit;
	TidyString(init);

	if(init[0] != '-')
	{
		positive_number_ = true;
		integer_part_ = init;
	}
	else
	{
		positive_number_ = false;
		integer_part_ = init.erase(0);
	}

	decimal_part_ = "0";
}

BigNumberC::BigNumberC(const char *kInit) {
	*this = BigNumberC(string(kInit));
}

BigNumberC::BigNumberC(const double kInit) {
	*this = BigNumberC(to_string(kInit));
}

BigNumberC::BigNumberC(const int kInit) {
	*this = BigNumberC(to_string(kInit));
}

BigNumberC::~BigNumberC() {
	positive_number_ = true;
	integer_part_.clear();
	decimal_part_.clear();
}

ostream& operator<< (ostream &out, BigNumberC kObj) {
	kObj.Print(out); 
	
	return out;
}

BigNumberC BigNumberC::operator+ (const BigNumberC& kObj) {
	DebugFunctionBegin("operator+");

	BigNumberC big_num = *this;
	big_num.Plus(kObj);

	DebugFunctionEnd("operator+");
	return big_num;
}
BigNumberC BigNumberC::operator- (const BigNumberC& kObj) {
	DebugFunctionBegin("operator-");

	BigNumberC big_num = *this;
	big_num.Minus(kObj);

	DebugFunctionEnd("operator-");

	return big_num;
}
BigNumberC BigNumberC::operator* (const BigNumberC& kObj) {
	DebugFunctionBegin("operator*");

	BigNumberC big_num = *this;
	big_num.Multiply(kObj);

	DebugFunctionEnd("operator*");
	return big_num;
}
BigNumberC& BigNumberC::operator= (const BigNumberC& kObj) {
	positive_number_ = kObj.positive_number_;
	integer_part_ = kObj.integer_part_;
	decimal_part_ = kObj.decimal_part_;
	return *this;
}

BigNumberC& BigNumberC::operator+= (const BigNumberC& kObj) {
	DebugFunctionBegin("operator+=");

	this->Plus(kObj);

	DebugFunctionEnd("operator+=");

	return *this;
}
BigNumberC& BigNumberC::operator-= (const BigNumberC& kObj) {
	DebugFunctionBegin("operator-=");

	Minus(kObj);

	DebugFunctionEnd("operator-=");

	return *this;
}
BigNumberC& BigNumberC::operator*= (const BigNumberC& kObj) {
	DebugFunctionBegin("operator*=");

	Multiply(kObj);

	DebugFunctionEnd("operator*=");

	return *this;
}
bool BigNumberC::operator== (const BigNumberC& kObj) const {
	DebugFunctionBegin("operator==");

	bool rslt = IsEqual(kObj);

	DebugFunctionEnd("operator==");
	return rslt;
}
bool BigNumberC::operator!= (const BigNumberC& kObj) const {
	DebugFunctionBegin("operator!=");

	bool rslt = !IsEqual(kObj);

	DebugFunctionEnd("operator!=");
	return rslt;
}

bool BigNumberC::operator> (const BigNumberC& kObj) const {
	DebugFunctionBegin("operator>");

	bool rslt = false;

	if(*this == kObj)
		rslt = false;
	else if(*this >= kObj)
		rslt = true;
	else
		rslt = false;

	DebugFunctionEnd("operator>");
	return rslt;
}
bool BigNumberC::operator>= (const BigNumberC& kObj) const {
	DebugFunctionBegin("operator>=");

	BigNumberC temp = *this;
	temp -= kObj;

	DebugFunctionEnd("operator>=");
	return temp.positive_number_;
}
bool BigNumberC::operator< (const BigNumberC& kObj) const {
	DebugFunctionBegin("operator<");

	bool rslt = !(*this >= kObj);
	
	DebugFunctionEnd("operator<");
	return rslt;
}
bool BigNumberC::operator<= (const BigNumberC& kObj) const {
	DebugFunctionBegin("operator<=");

	bool rslt = !(*this > kObj);
	
	DebugFunctionEnd("operator<=");
	return rslt;
}

int BigNumberC::GetDigitsSum() const {
	DebugFunctionBegin("GetDigitsSum");

	int sum = 0;

	for(string::const_iterator it = integer_part_.begin(); it != integer_part_.end(); ++it)
		sum += *it - '0';

	DebugFunctionEnd("GetDigitsSum");
	return sum;
}
string BigNumberC::GetDigitsSumString() const {
	DebugFunctionBegin("GetDigitsSumString");

	BigNumberC sum(0);

	int digit = 0;
	for(string::const_iterator it = integer_part_.begin(); it != integer_part_.end(); ++it)
	{
		digit = *it - '0';
		sum += BigNumberC(digit);
	}

	DebugFunctionEnd("GetDigitsSumString");
	return sum.integer_part_;
}

bool BigNumberC::HasSameDigitsQty(const BigNumberC& kToCompare) const {
	DebugFunctionBegin("HasSameDigitsQty");

	bool rslt = true;
	double digits_qty1[11] = {0.0};
	double digits_qty2[11] = {0.0};
	int temp;

	if(integer_part_.length() != kToCompare.integer_part_.length())
		rslt = false;
	else if(positive_number_ != kToCompare.positive_number_)
		rslt = false;
	else
	{
		for(string::const_iterator it = integer_part_.begin(); it != integer_part_.end(); ++it)
		{
			temp = *it - '0';
			digits_qty1[temp] += 1;
		}
		for(string::const_iterator it = kToCompare.integer_part_.begin(); it != kToCompare.integer_part_.end(); ++it)
		{
			temp = *it - '0';
			digits_qty2[temp] += 1;
		}

		for(int i = 0; i < 11; ++i)
		{
			if(digits_qty1[i] != digits_qty2[i])
			{
				rslt = false;
				break;
			}
		}
	}

	DebugFunctionEnd("HasSameDigitsQty");
	return rslt;
}

bool BigNumberC::IsDecreasingNumber() const {
	bool rslt = true;

	size_t ind1 = 0, ind2 = integer_part_.length() - 1;
	for(; ind1 < ind2; ++ind1, --ind2)
	{
		if(integer_part_[ind1] < integer_part_[ind1 + 1] ||
			integer_part_[ind2 - 1] < integer_part_[ind2] || 
			integer_part_[ind1] < integer_part_[ind2])
		{
			rslt = false;
			break;
		}
	}

	return rslt;
}

bool BigNumberC::IsEqual(const BigNumberC& kToCompare) const {
	DebugFunctionBegin("IsEqual");

	bool rslt = false;
	if(positive_number_ != kToCompare.positive_number_)
		rslt = false;
	else if(integer_part_ != kToCompare.integer_part_)
		rslt = false;
	else if(decimal_part_ != kToCompare.decimal_part_)
		rslt = false;
	else rslt = true;

	DebugFunctionEnd("IsEqual");
	return rslt;
}

bool BigNumberC::IsIncreasingNumber() const {
	DebugFunctionBegin("IsIncreasingNumber");

	bool rslt = true;

	size_t ind1 = 0, ind2 = integer_part_.length() - 1;
	for(; ind1 < ind2; ++ind1, --ind2)
	{
		if(integer_part_[ind1] > integer_part_[ind1 + 1] ||
			integer_part_[ind2 - 1] > integer_part_[ind2] || 
			integer_part_[ind1] > integer_part_[ind2])
		{
			rslt = false;
			break;
		}
	}

	DebugFunctionEnd("IsIncreasingNumber");
	return rslt;
}

BigNumberC& BigNumberC::SetToPowerOfInt(const int kBase, const int kPower) {
	DebugFunctionBegin("SetToPowerOfInt");

	*this = BigNumberC(1);
	for(int i = 1; i <= kPower; ++i)
		Multiply(kBase);

	DebugFunctionEnd("SetToPowerOfInt");
	return *this;
}

BigNumberC& BigNumberC::Divide(const BigNumberC& kDividObj) {
	return *this;
}
BigNumberC& BigNumberC::Divide(const int& kDividInt) {
	return *this;
}

BigNumberC& BigNumberC::Plus(const BigNumberC& kToAdd) {
	DebugFunctionBegin("Plus(const BigNumberC&) " + kToAdd.integer_part_);
	
	if(kToAdd.IsEqual(BigNumberC(0)))
	{
		;
	} 
	else if(positive_number_ == true && kToAdd.positive_number_ == false)
	{
		BigNumberC temp = kToAdd;
		temp.positive_number_ = true;
		this->Minus(temp);
	}
	else if(positive_number_ == false && kToAdd.positive_number_ == true)
	{
		BigNumberC temp = *this;
		temp.positive_number_ = true;
		temp.Minus(kToAdd);

		*this = temp;
		positive_number_ = false;
	}
	else
	{
		string::reverse_iterator it1 = integer_part_.rbegin();
		string::const_reverse_iterator it2 = kToAdd.integer_part_.rbegin();

		string plus_rslt;
		int temp_val = 0;
		bool carry_over = false;
		while(1) {
			if(it1 != integer_part_.rend() && it2 != kToAdd.integer_part_.rend())
			{
				temp_val = (*it1 - '0') + (*it2 - '0');
				++it1;
				++it2;
			}
			else if(it1 == integer_part_.rend() && it2 != kToAdd.integer_part_.rend())
			{
				temp_val = *it2 - '0';
				++it2;
			}
			else if(it1 != integer_part_.rend() && it2 == kToAdd.integer_part_.rend())
			{
				temp_val = *it1 - '0';
				++it1;
			}
			else
			{
				if(carry_over == true)
				{
					carry_over = false;
					plus_rslt += to_string(1);
				}
				break;
			}
		
			if(carry_over == true)
			{
				temp_val += 1;
				carry_over = false;
			}
			if(temp_val >= 10)
			{
				temp_val -= 10;
				carry_over = true;
			}
			plus_rslt += to_string(temp_val);

		}

		integer_part_ = plus_rslt;
		reverse(integer_part_.begin(), integer_part_.end());
	}
	
	DebugFunctionEnd("Plus");
	return *this;
}

BigNumberC& BigNumberC::Minus(const BigNumberC& kToDeduct) {
	DebugFunctionBegin("Minus(const BigNumberC&) " + kToDeduct.integer_part_);

	if(kToDeduct.IsEqual(BigNumberC(0)) == true || this->IsEqual(kToDeduct))
	{
		;
	}
	else if(positive_number_ == true && kToDeduct.positive_number_ == false)
	{
		BigNumberC temp = kToDeduct;
		temp.positive_number_ = true;
		Plus(temp);
	} 
	else if (positive_number_ == false && kToDeduct.positive_number_ == true)
	{
		BigNumberC temp = *this;
		temp.positive_number_ = true;
		temp.Plus(kToDeduct);

		*this = temp;
		positive_number_ = false;
	}
	else
	{
		//assign bigger number to num1 and smaller number to num2 for deduction.
		BigNumberC num1, num2;
		if(integer_part_.length() < kToDeduct.integer_part_.length())
		{
			num1 = kToDeduct, num2 = *this;
			positive_number_ = !positive_number_;
		}
		else if(integer_part_.length() > kToDeduct.integer_part_.length())
		{
			num1 = *this, num2 = kToDeduct;
			positive_number_ = positive_number_;
		}
		else
		{
			string::iterator it1 = integer_part_.begin(); 
			string::const_iterator it2 = kToDeduct.integer_part_.begin(); 

			while(1)
			{
				if(*it1 > *it2)
				{
					num1 = *this, num2 = kToDeduct;
					positive_number_ = positive_number_;
					break;
				}
				else if(*it1 < *it2)
				{
					num1 = kToDeduct, num2 = *this;
					positive_number_ = !positive_number_;
					break;
				}

				++it1;
				++it2;
			}
		}

		if(num1 != num2)
		{
			//calculate num1 - num2.
			bool borrow_higher_digit = false;
			string::reverse_iterator it1 = num1.integer_part_.rbegin();
			string::reverse_iterator it2 = num2.integer_part_.rbegin();
			while(1)
			{
				if(borrow_higher_digit == true)
				{
					if(*it1 == '0')
					{
						*it1 = '9';
						borrow_higher_digit = true;
					}
					else
					{
						*it1 -= 1;
						borrow_higher_digit = false;
					}
				}

				if(it2 == num2.integer_part_.rend())
				{
					if(borrow_higher_digit == true)
						++it1;
					else
						break;
				}
				else if(*it1 >= *it2)
				{
					*it1 = *it1 - *it2 + '0';
					++it1;
					++it2;
				}
				else
				{
					*it1 = 10 + (*it1 - '0') - (*it2 - '0') + '0';
					borrow_higher_digit = true;

					++it1;
					++it2;
				}

				if(it1 == num1.integer_part_.rend())
					break;
			}
			num1.positive_number_ = positive_number_;
			num1.TidyBigNumber();
			*this = num1;
		}
	}

	DebugFunctionEnd("Minus");
	return *this;
}

BigNumberC& BigNumberC::Multiply(const BigNumberC& kMultiplyObj) {
	DebugFunctionBegin("Multiply");

	if(kMultiplyObj.IsEqual(BigNumberC(1)) == true)
	{
		;
	}
	else if(kMultiplyObj.IsEqual(BigNumberC(0)) == true)
	{
		*this = BigNumberC(0);
	}
	else
	{
		int single_digit = 0, digit_ind = 0;
		BigNumberC multiply_rslt, temp_rslt;
		string::const_reverse_iterator it = kMultiplyObj.integer_part_.rbegin();

		while(it != kMultiplyObj.integer_part_.rend())
		{
			single_digit = *it - '0';

			if(single_digit != 0)
			{
				temp_rslt = *this;
				temp_rslt.MultiplySingleDigit(single_digit);

				for(int i = 0; i < digit_ind; ++i)
					temp_rslt.integer_part_ += '0'; //means to times 10

				multiply_rslt.Plus(temp_rslt);
			}

			++digit_ind;
			++it;
		}

		*this = multiply_rslt;
	}

	DebugFunctionEnd("Multiply");
	return *this;
}

BigNumberC&  BigNumberC::Multiply(const int kMultiplyInt) {
	DebugFunctionBegin("Multiply(const int kMultiplyInt)");

	Multiply(BigNumberC(kMultiplyInt));

	DebugFunctionEnd("Multiply(const int kMultiplyInt)");
	return *this;
}

BigNumberC& BigNumberC::MultiplySingleDigit(const int kDigit) {
	DebugFunctionBegin("MultiplySingleDigit()");

	if(IsEqual(BigNumberC(0)) || kDigit == 1)
	{
	}
	else if(kDigit == 0)
	{
		*this = BigNumberC(0);
	}
	else
	{
		string multiply_rslt;
		int temp_carry_over = 0, temp_val = 0;
		string::reverse_iterator it = integer_part_.rbegin(); 

		while(it != integer_part_.rend()) {
			temp_val = *it - '0';
			temp_val *= kDigit;
			temp_val += temp_carry_over, temp_carry_over = 0;
		
			if(temp_val >= 10)
			{
				temp_carry_over	= temp_val / 10;
				temp_val -= temp_carry_over * 10;
			}
			multiply_rslt += to_string(temp_val);

			++it;
			if(it == integer_part_.rend())
			{
				if(temp_carry_over != 0)
				{
					multiply_rslt += to_string(temp_carry_over);
					temp_carry_over = 0;
				}
				break;
			}
		}

		reverse(multiply_rslt.begin(), multiply_rslt.end());
		*this = multiply_rslt;
	}

	DebugFunctionEnd("MultiplySingleDigit()");
	return *this;
}

ostream& BigNumberC::Print(ostream &out) const {
	if(positive_number_ == false)
		out << "-";

	out << integer_part_;
	if(decimal_part_ != "0")
		out << decimal_part_;

	return out;
}

ostream& BigNumberC::PrintFrontDigits(const int kPrintDigitsQty, ostream &out) const {
	if(size_t(kPrintDigitsQty) >= integer_part_.length())
		out << integer_part_;
	else
		out << integer_part_.substr(0, kPrintDigitsQty);
	
	return out;
}

ostream& BigNumberC::PrintRearDigits(const int kPrintDigitsQty, ostream &out) const {
	if(size_t(kPrintDigitsQty) >= integer_part_.length())
		out << integer_part_;
	else
		out << integer_part_.substr(integer_part_.length() - kPrintDigitsQty);

	return out;
}

void BigNumberC::TidyString(string &str) {
	return; //lych ?

	str.erase(remove_if(str.begin(), str.end(), isspace));
}

void BigNumberC::TidyBigNumber() {
	return; //lych ?

	while(1)
	{
		if(integer_part_[0] == '0')
			integer_part_.erase(0);
		else
			break;
	}
}

