#pragma once

namespace file {
	template <class T>
	class File
	{
	protected:
		std::string filename;
		std::fstream descriptor;
	public:
		File(std::string);

		void write(T&);
		void read(T&);

		bool exists();
		bool empty();

		virtual ~File();
	};
}

