#pragma once
#include "pch.h"
#include <vector>
#include <set>
#include <map>
#include <string>

std::vector<float> square(const std::vector<float>& input) noexcept;
EigenMatrix inv(const EigenMatrix& input) noexcept;
double det(const EigenMatrix& input) noexcept;

std::set<int> unique(const std::vector<int>& input) noexcept;
std::map<int, int> counter(const std::vector<int>& input) noexcept;
std::unordered_map<wchar_t, size_t> char_count(const std::wstring& s) noexcept;