#pragma once
#include <filesystem>
#include <vector>
#include <tuple>

std::filesystem::path relativePath(std::string_view path);

template <typename T>
std::vector<std::tuple<size_t, T>> enumerate(const std::vector<T> &vector)
{
	std::vector<std::tuple<size_t, T>> tuples;
	for (size_t i = 0; i < vector.size(); i++)
	{
		tuples.emplace_back(i, vector[i]);
	}

	return tuples;
}
