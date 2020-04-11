#include "number.h"

BigNumber::BigNumber()
{
  number_.clear();
  positive_ = true;
}

BigNumber::BigNumber(const uint64_t kUint)
{
  *this = BigNumber(to_string(kUint));
}

BigNumber::BigNumber(const string kStr)
{
  string str = kStr;
  if (str[0] == '-')
  {
    positive_ = false;
    str = str.substr(1);
  }
  else if (str[0] == '+')
  {
    positive_ = true;
    str = str.substr(1);
  }
  else
    positive_ = true;

  for (auto &digit : str)
  {
    number_.push_back(digit - '0');
  }
}

BigNumber::BigNumber(const BigNumber &kBn)
{
  number_ = kBn.number_;
  positive_ = kBn.positive_;
}

BigNumber::~BigNumber()
{
  positive_ = true;
  number_.clear();
}

BigNumber BigNumber::operator+(const BigNumber &kBn)
{
  BigNumber temp_num;

  auto ind1 = number_.rbegin();
  auto ind2 = kBn.number_.rbegin();
  int carry_forward = 0;
  for (; ind1 != number_.rend() && ind2 != kBn.number_.rend(); ++ind1, ++ind2)
  {
    if (carry_forward + *ind1 + *ind2 < 10)
    {
      temp_num.number_.push_back(carry_forward + *ind1 + *ind2);
      carry_forward = 0;
    }
    else
    {
      temp_num.number_.push_back(carry_forward + *ind1 + *ind2 - 10);
      carry_forward = 1;
    }
  }

  for (; ind1 != number_.rend(); ++ind1)
  {
    if (carry_forward + *ind1 < 10)
    {
      temp_num.number_.push_back(carry_forward + *ind1);
      carry_forward = 0;
    }
    else
    {
      temp_num.number_.push_back(carry_forward + *ind1 - 10);
      carry_forward = 1;
    }
  }
  for (; ind2 != kBn.number_.rend(); ++ind2)
  {
    if (carry_forward + *ind2 < 10)
    {
      temp_num.number_.push_back(carry_forward + *ind2);
      carry_forward = 0;
    }
    else
    {
      temp_num.number_.push_back(carry_forward + *ind2 - 10);
      carry_forward = 1;
    }
  }
  if (carry_forward)
  {
    temp_num.number_.push_back(carry_forward);
    carry_forward = 0;
  }

  reverse(temp_num.number_.begin(), temp_num.number_.end());
  return temp_num;
}

BigNumber BigNumber::operator-(const BigNumber &kBn)
{
  BigNumber temp_num;

  auto ind1 = number_.rbegin();
  auto ind2 = kBn.number_.rbegin();
  int borrow_forward = 0;
  for (; ind1 != number_.rend() && ind2 != kBn.number_.rend(); ++ind1, ++ind2)
  {
    if (*ind1 - *ind2 - borrow_forward < 0)
    {
      temp_num.number_.push_back(*ind1 + 10 - *ind2 - borrow_forward);
      borrow_forward = 1;
    }
    else
    {
      temp_num.number_.push_back(*ind1 - *ind2 - borrow_forward);
      borrow_forward = 0;
    }
  }
  for (; ind1 != number_.rend(); ++ind1)
  {
    if (*ind1 - borrow_forward < 0)
    {
      temp_num.number_.push_back(*ind1 + 10 - borrow_forward);
      borrow_forward = 1;
    }
    else
    {
      temp_num.number_.push_back(*ind1 - borrow_forward);
      borrow_forward = 0;
    }
  }
  for (; ind2 != kBn.number_.rend(); ++ind2)
  {
    temp_num.number_.push_back(borrow_forward + *ind2);
    borrow_forward = 0;
  }
  if (borrow_forward)
  {
    temp_num.number_.push_back(borrow_forward);
    borrow_forward = 0;
  }

  reverse(temp_num.number_.begin(), temp_num.number_.end());
  return temp_num;
}

BigNumber &BigNumber::operator=(const BigNumber &kObj)
{
  number_.clear();
  number_ = kObj.number_;
  positive_ = kObj.positive_;
  return *this;
}

BigNumber &BigNumber::operator+=(const BigNumber &kObj)
{
  *this = (*this) + kObj;
  return *this;
}
BigNumber &BigNumber::operator-=(const BigNumber &kObj)
{
  *this = *this - kObj;
  return *this;
}

BigNumber &BigNumber::operator*=(const BigNumber &kMultiplier)
{
  // for (auto ind = kMultiplier.number_.rbegin(); ind != kMultiplier.number_.rend(); ++i)
  // {
  // }
  // reverse(number_.begin(), number_.end());
  // for(auto number_.
  return *this;
}

BigNumber BigNumber::operator*(const int kMultiplier)
{
  BigNumber rslt;

  int multiplier = kMultiplier;
  int digit = 0;
  int decimals = 0;
  while (multiplier)
  {
    digit = multiplier - multiplier / 10 * 10;

    // calculate number_ * digit
    int carry_forward = 0;
    BigNumber temp_num;
    for (auto ind = number_.rbegin(); ind != number_.rend(); ++ind)
    {
      int temp = carry_forward + *ind * digit;
      carry_forward = temp / 10;
      temp_num.number_.push_back(temp - carry_forward * 10);
    }

    if (carry_forward)
    {
      temp_num.number_.push_back(carry_forward);
      carry_forward = 0;
    }
    reverse(temp_num.number_.begin(), temp_num.number_.end());
    if (decimals)
    {
      for (int i = 0; i < decimals; ++i)
        temp_num.number_.push_back(0);
    }

    rslt += temp_num;
    multiplier = multiplier / 10;
    ++decimals;
  }
  return rslt;
}

BigNumber &BigNumber::operator*=(const int kMultiplier)
{
  *this = (*this) * kMultiplier;
  return *this;
}

ostream &operator<<(ostream &out, const BigNumber kObj)
{
  for (auto &i : kObj.number_)
    out << i;
  return out;
}

bool BigNumber::operator!=(const BigNumber kObj) const
{
  return !(*this == kObj);
}

bool BigNumber::operator==(const BigNumber kObj) const
{
  if (positive_ != kObj.positive_)
    return false;
  if (number_.size() != kObj.number_.size())
    return false;

  for (auto a1 = number_.begin(), a2 = kObj.number_.begin();
       a1 != number_.end() && a2 != kObj.number_.end();
       ++a1, ++a2)
  {
    if (*a1 != *a2)
      return false;
  }
  return true;
}

bool BigNumber::operator>(const BigNumber kObj) const
{
  if (number_.size() > kObj.number_.size())
    return true;
  if (number_.size() < kObj.number_.size())
    return false;

  for (auto a1 = number_.begin(), a2 = kObj.number_.begin();
       a1 != number_.end() && a2 != kObj.number_.end();
       ++a1, ++a2)
  {
    if (*a1 > *a2)
      return true;
    if (*a1 < *a2)
      return false;
  }
  return false;
}

bool BigNumber::operator<(const BigNumber kObj) const
{
  if (number_.size() < kObj.number_.size())
    return true;
  if (number_.size() > kObj.number_.size())
    return false;

  for (auto a1 = number_.begin(), a2 = kObj.number_.begin();
       a1 != number_.end() && a2 != kObj.number_.end();
       ++a1, ++a2)
  {
    if (*a1 < *a2)
      return true;
    if (*a1 > *a2)
      return false;
  }
  return false;
}

BigNumber &BigNumber::Power(const int kPower)
{
  if (kPower == 0)
  {
    *this = BigNumber(1);
    return *this;
  }

  uint64_t v = 0;
  int for_decimal = 1;
  for (auto a = number_.rbegin(); a != number_.rend(); ++a)
  {
    v += *a * for_decimal;
    for_decimal *= 10;
  }
  for (int i = 0; i < kPower - 1; ++i)
  {
    *this *= v;
  }
  return *this;
}
