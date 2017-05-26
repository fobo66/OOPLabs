#pragma once
namespace BST {
	class Algorithm
	{
	public:
		Algorithm() {};
		template<class Iterator, class T>
		static Iterator find(Iterator begin, Iterator end, T& item);

		template<class Iterator, class T>
		static void filter(Iterator begin, Iterator end, std::function<bool(T)> predicate);

		template<class Iterator>
		static void show(Iterator begin, Iterator end);
		~Algorithm() {};
	};

	template<class Iterator, class T>
	inline Iterator Algorithm::find(Iterator first, Iterator last, T & value)
	{
		while (first != last && !(((*first).first == value) || ((*first).second == value)))
			++first;
		return first;
	}
	template<class Iterator, class T>
	inline void Algorithm::filter(Iterator begin, Iterator end, std::function<bool(T)> predicate)
	{
		for (Iterator i = begin; i != end; ++i)
			if (predicate((*i).second))
				std::cout << (*i).second << std::endl;
	}
	template<class Iterator>
	inline void Algorithm::show(Iterator begin, Iterator end)
	{
		for (; begin != end; ++begin)
			std::cout << (*begin).second << std::endl;
	}
}

