#include "pch.h"
#include "MyModule.h"

std::vector<float> square(const std::vector<float>& input) noexcept
{
	std::vector<float> output;
	if (!input.empty())
	{
		output.reserve(input.size());
		for (const auto& i : input)
		{
			output.emplace_back(i * i);
		}
	}
	return output;
}

EigenMatrix inv(const EigenMatrix& input) noexcept
{
	return input.inverse();
}

double det(const EigenMatrix& input) noexcept
{
	return input.determinant();
}

std::set<int> unique(const std::vector<int>& input) noexcept
{
	std::set<int> result;
	for (const auto& i : input)
	{
		if (!result.contains(i))
		{
			result.emplace(i);
		}
	}
	return result;
}

std::map<int, int> counter(const std::vector<int>& input) noexcept
{
	std::map<int, int> result;
	for (const auto& i : input)
	{
		if (result.contains(i))
		{
			result[i] += 1;
		}
		else
		{
			result[i] = 1;
		}
	}
	return result;
}

std::unordered_map<wchar_t, size_t> char_count(const std::wstring& s) noexcept
{
	std::unordered_map<wchar_t, size_t> result;
	for (const auto& c : s)
	{
		if (result.contains(c))
		{
			result[c] += 1;
		}
		else
		{
			result[c] = 1;
		}
	}
	return result;
}