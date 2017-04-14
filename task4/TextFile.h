#pragma once
#include "File.cpp"
namespace file {
	template<class T>
	class TextFile :
		public File<T>
	{
	public:
		TextFile(std::string name) : File<T>(name) { };

		void write(T&);
		void read(T &);

		~TextFile()
		{
			if (descriptor.is_open())
				this->descriptor.close();
		};
	};
}

