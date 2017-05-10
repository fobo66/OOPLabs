#pragma once
#include "File.h"

namespace file {
	template<class T>
	class BinaryFile :
		public File<T>
	{
	public:
		BinaryFile(std::string name) : File(name) { };

		void write(T&);
		void read(T&);

		~BinaryFile() { };
	};
}
