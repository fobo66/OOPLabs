#pragma once
namespace util
{
	void extractFileName(std::string & filename)
	{
		filename = filename.substr(12, filename.length() - 12);
	}
}