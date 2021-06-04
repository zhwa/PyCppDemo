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