#include <iostream>
#include <algorithm>
#include <forward_list>
#include <functional>



template <typename ForwardIterator, typename Compare>
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {
	for (auto sorted = first; first != last; last = sorted) {
		sorted = first;
		for (auto cur = first, prev = first; ++cur != last; ++prev) {
			if (comp(*cur, *prev)) {
				std::iter_swap(cur, prev);
				sorted = cur;
			}
		}
	}
}
//Fuctor인 compGreater를 구현하세요. (힌트: 1. 두 정수 비교 결과를 bool 타입을 리턴한다. 2. operator() 를 구현한다. 3. Fuctor는 클래스 형태와 비슷하다.)
struct compLess
{
	int operator()(int a, int b) {
		return a > b ? 0 : 1;
	}
};
struct compGreater
{
	int operator()(int a, int b) {
		return a < b ? 0 : 1;
	}
};

int main() {
	std::forward_list<int> values{ 7, 0, 6, 1, 5, 2, 4, 3 };

	std::cout << "오름차순 정렬" << std::endl;
	compLess compLess; //Functor compLess
	bubble_sort(values.begin(), values.end(), compLess);
	//��� ����Ʈ
	for (auto it = values.begin(); it != values.end(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;


	std::cout << "내림차순 정렬" << std::endl;
	compGreater compGreater; //Functor ����
	bubble_sort(values.begin(), values.end(), compGreater);
	//��� ����Ʈ
	for (auto it = values.begin(); it != values.end(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;

	getchar();
}
