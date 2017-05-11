#pragma once
namespace BST {
	class Algorithm
	{
	public:
		Algorithm() {};
		template<class Iterator, class T>
		static Iterator find(Iterator begin, Iterator end, T& item);
		~Algorithm() {};
	};

	template<class Iterator, class T>
	inline Iterator Algorithm::find(Iterator first, Iterator last, T & value)
	{
		while (first != last && !((*first).second == value || (*first).first == value))
			++first;
		return first;
	}
}

