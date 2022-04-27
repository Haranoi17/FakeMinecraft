#include "Utilities.hpp"

std::filesystem::path relativePath(std::string_view path)
{
	return std::filesystem::current_path().concat(path);
}