#ifndef LAMBDA_ITERATOR_H
#define LAMBDA_ITERATOR_H

#pragma once

namespace lambda {

	enum Category {
		input_iterator_tag,
		output_iterator_tag,
		forward_iterator_tag,
		bidirectional_iterator_tag,
		random_access_iterator_tag
	};

	template <class T> class iterator {
	protected:
		T* item;

		iterator(T* x) :item(x) {} //copy-constructible

		iterator(const iterator<T>& it) : item(it.item) {} //copy-constructible

		//iterator<T>& operator=(const iterator<T>& rhs) = default;

		//iterator<T>& operator++() { //++a
		//	++item;
		//	return *this;
		//}

		//iterator<T> operator++(int) { //(void)a++
		//	iterator<T> tmp = *this;
		//	++*this;
		//	return tmp;
		//}

		virtual ~iterator<T>() {}
	};

	template <class T>
	class input_iterator : public iterator<T> {
	public:
		input_iterator(T* x) : iterator(x) {} //copy-constructible

		input_iterator(const input_iterator<T>& it) : iterator(it.item) {} //copy-constructible

		input_iterator<T>& operator=(const input_iterator<T>& rhs) = default;

		bool operator==(const input_iterator<T>& rhs) const { //a == b
			return item == rhs.item;
		}

		bool operator!=(const input_iterator<T>& rhs) const { //a != b
			return item != rhs.item;
		}
			
		const T& operator*() const { //*a
			return *item;
		}

		const T* operator->() const { //a->m
			return item;
		}

		input_iterator<T>& operator++() { //++a
			++item;
			return *this;
		}

		input_iterator<T> operator++(int) { //(void)a++
			input_iterator<T> tmp = *this;
			++*this;
			return tmp;
		}

		virtual ~input_iterator<T>() {}	//destructible
	};

	template <class T>
	class output_iterator : public iterator<T> {
	public:
		output_iterator(T* x) : iterator(x) {} //copy-constructible

		output_iterator(const output_iterator<T>& it) : iterator(it.item) {} //copy-constructible

		output_iterator<T>& operator=(const output_iterator<T>& rhs) = default;

		output_iterator<T>& operator=(const T &a) { //*a = t
			*item = a;
			return *this;
		}

		T& operator*() = delete { //*a
			return *item;
		}

		output_iterator<T>& operator++() {
			return *this;
		}

		output_iterator<T> operator++(int) {
			return *this;
		}

	};

	template <class T>
	class forward_iterator : public input_iterator<T>, public output_iterator<T> {
	public:
		forward_iterator() {}

		forward_iterator(T* x) : input_iterator(x), output_iterator(x) {} //copy-constructible

		forward_iterator(const forward_iterator<T>& it) : input_iterator(it.item), output_iterator(it.item) {} //copy-constructible

		forward_iterator<T>& operator=(const forward_iterator<T>& rhs) = default;

		forward_iterator<T>& operator=(const T &a) { //*a = t
			*item = a;
			return *this;
		}

		bool operator==(const forward_iterator<T>& rhs) const { //a == b
			return item == rhs.item;
		}

		bool operator!=(const forward_iterator<T>& rhs) const { //a != b
			return item != rhs.item;
		}

		T& operator*() { //*a
			return *item;
		}

		const T* operator->() const { //a->m
			return item;
		}

		forward_iterator<T>& operator++() { //++a
			++item;
			return *this;
		}

		forward_iterator<T> operator++(int) { //(void)a++
			forward_iterator<T> tmp = *this;
			++*this;
			return tmp;
		}

		virtual ~forward_iterator<T>() {}	//destructible
	};

	template <class T>
	class bidirectional_iterator : public forward_iterator<T> {
	public:
		bidirectional_iterator() {}

		bidirectional_iterator(T* x) : forward_iterator(x) {} //copy-constructible

		bidirectional_iterator(const bidirectional_iterator<T>& it) : forward_iterator(it.item) {} //copy-constructible

		bidirectional_iterator<T>& operator=(const bidirectional_iterator<T>& rhs) = default;

		bidirectional_iterator<T>& operator=(const T &a) { //*a = t
			*item = a;
			return *this;
		}

		bool operator==(const bidirectional_iterator<T>& rhs) const { //a == b
			return item == rhs.item;
		}

		bool operator!=(const bidirectional_iterator<T>& rhs) const { //a != b
			return item != rhs.item;
		}

		T& operator*() { //*a
			return *item;
		}

		const T* operator->() const { //a->m
			return item;
		}

		bidirectional_iterator<T>& operator++() { //++a
			++item;
			return *this;
		}

		bidirectional_iterator<T> operator++(int) { //(void)a++
			bidirectional_iterator<T> tmp = *this;
			++*this;
			return tmp;
		}

		bidirectional_iterator<T>& operator--() { //++a
			--item;
			return *this;
		}

		bidirectional_iterator<T> operator--(int) { //(void)a++
			bidirectional_iterator<T> tmp = *this;
			--*this;
			return tmp;
		}

		virtual ~bidirectional_iterator<T>() {}	//destructible
	};

	template <class T>
	class random_access_iterator : public bidirectional_iterator<T> {
	public:
		random_access_iterator() {}

		random_access_iterator(T* x) : forward_iterator(x) {} //copy-constructible

		random_access_iterator(const random_access_iterator<T>& it) : forward_iterator(it.item) {} //copy-constructible

		random_access_iterator<T>& operator=(const random_access_iterator<T>& rhs) = default;

		random_access_iterator<T>& operator=(const T &a) { //*a = t
			*item = a;
			return *this;
		}

		bool operator==(const random_access_iterator<T>& rhs) const { //a == b
			return item == rhs.item;
		}

		bool operator!=(const random_access_iterator<T>& rhs) const { //a != b
			return item != rhs.item;
		}

		T& operator*() { //*a
			return *item;
		}

		const T* operator->() const { //a->m
			return item;
		}

		random_access_iterator<T>& operator++() { //++a
			++item;
			return *this;
		}

		random_access_iterator<T> operator++(int) { //(void)a++
			random_access_iterator<T> tmp = *this;
			++*this;
			return tmp;
		}

		random_access_iterator<T>& operator--() { //++a
			--item;
			return *this;
		}

		random_access_iterator<T> operator--(int) { //(void)a++
			random_access_iterator<T> tmp = *this;
			--*this;
			return tmp;
		}

		random_access_iterator<T> operator+(const int &n) const {
			random_access_iterator<T> tmp = *this;
			item += n;
			return tmp;
		}

		friend random_access_iterator<T> operator-(const random_access_iterator<T> &a, const int &n) {
			random_access_iterator<T> tmp = *this;
			item -= n;
			return tmp;
		}

		random_access_iterator<T> operator-(const random_access_iterator<T> &rhs) const {
			return item - rhs.item;
		}

		bool operator<(const random_access_iterator<T> &n) const {
			return item < rhs.item;
		}

		bool operator>(const random_access_iterator<T> &n) const {
			return item > rhs.item;
		}

		bool operator<=(const random_access_iterator<T> &n) const {
			return item <= rhs.item;
		}

		bool operator>=(const random_access_iterator<T> &n) const {
			return item >= rhs.item;
		}

		random_access_iterator<T>& operator +=(const int& n) {
			item += n;
			return *this;
		}

		random_access_iterator<T>& operator -=(const int& n) {
			item -= n;
			return *this;
		}

		T& operator[](size_t n) {
			return *(item + n);
		}

		virtual ~random_access_iterator<T>() {}	//destructible
	};




}

#endif


