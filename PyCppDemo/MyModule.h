#pragma once
#include "pch.h"
#include <vector>
#include <set>
#include <map>
#include <string>

std::vector<float> square(const std::vector<float>& input) noexcept;
std::set<int> unique(const std::vector<int>& input) noexcept;
std::map<int, int> counter(const std::vector<int>& input) noexcept;
std::unordered_map<wchar_t, size_t> char_count(const std::wstring& s) noexcept;

EigenMatrix inv(const EigenMatrix& input) noexcept;
double det(const EigenMatrix& input) noexcept;

class Fraction
{
public:
	Fraction(double n, double d);
	Fraction(const Fraction&) = default;
	void mul(double c) noexcept;
	std::string str() const noexcept;
	void print() const noexcept;

private:
	double m_numerator{ 0 };
	double m_denominator{ 1 };
};

std::vector<Fraction> mul_fraction(const std::vector<Fraction>& input, double c) noexcept;