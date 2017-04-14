#pragma once
#define DEFAULT_STRLEN 1024
/** (c) 2016 Andrey Mukamolow <fobo66@protonmail.com>
 *      String object custom realisation
 *Task: Реализовать класс String, 
 *      в котором надо перегрузить операции =, +, +=, -, >, <, [], ()(int, int) - подстрока, ++, --.
 */
namespace str 
{
	class String
	{
	private:
		char* instanse;
	public:
		String(int size = DEFAULT_STRLEN)
		{
			this->instanse = new char[size];
			ZeroMemory(this->instanse, size); //fill memory with '\0'
		};

		/**
		 * Construct an object with null-terminated string
		 */
		explicit String(const char* str)
		{
			this->instanse = new char[DEFAULT_STRLEN];
			ZeroMemory(this->instanse, DEFAULT_STRLEN);
			strcpy_s(this->instanse, DEFAULT_STRLEN, str);
		};

		/**
		 * Copy constructor
		 */
		String(const String& str)
		{
			this->instanse = new char[DEFAULT_STRLEN];
			ZeroMemory(this->instanse, DEFAULT_STRLEN);
			strcpy_s(this->instanse, DEFAULT_STRLEN, str.instanse);
		};

		/**
		 * + overloading
		 */
		String operator+(String&);
		String operator+(const char*);
		friend String operator+(const char*, String&);

		/**
		* - overloading
		*/
		String operator-(String&);
		String operator-(const char*);
		friend String operator-(const char*, String&);

		/**
		* = and += and -= overloading
		*/
		String operator=(const String&);
		String operator=(const char *);
		void operator+=(String&);
		void operator+=(const char *);
		void operator-=(String&);
		void operator-=(const char *);

		/**
		* Comparison operators overloading
		*/
		bool operator<(const String&);
		bool operator>(const String&);
		bool operator==(const String&);

		/**
		* Get symbol at index
		*/
		char operator[](int);

		/**
		* Substring
		*/
		String operator()(int, int); // from a to b
		String operator()(int); // from index to end

		/**
		* ++ overloading for obfuscating strings
		*/
		String operator++(int);
		String operator++();

		/**
		* -- overloading for deobfuscating
		*/
		String operator--(int);
		String operator--();

		/**
		* Overloading << and >> for direct objects IO
		*/
		friend std::ostream& operator<<(std::ostream& os, const String& str);
		friend std::istream& operator>>(std::istream& is, const String& str);

		/**
		* Destructor
		*/
		~String()
		{
			delete[](this->instanse);
		};
	};
}
