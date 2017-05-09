#pragma once
namespace BST {
	class Algorithm
	{
	public:
		Algorithm() {};
		template<class Iterator>
		static Iterator copy(Iterator begin, Iterator end, Iterator outputBegin);

		template<class Iterator, class T>
		static Iterator find(Iterator begin, Iterator end, T& item);
		~Algorithm() {};
	};
	template<class Iterator>
	inline Iterator Algorithm::copy(Iterator first, Iterator last, Iterator outputFirst)
	{
		for (; first != last; ++outputFirst, ++first)
			*outputFirst = *first;
		return outputFirst;
	}
	template<class Iterator, class T>
	inline Iterator Algorithm::find(Iterator first, Iterator last, T & value)
	{
		while (first != last && !((*first).second == value))
			++first;
		return first;
	}
}

