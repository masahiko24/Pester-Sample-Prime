/// @file	PRMGenerator.cpp
/// @author	Masahiko Tsujita
/// @date	2015/09/22
/// @note	Copyright (c) 2015年 Masahiko Tsujita. All rights reserved.

#include "stdafx.h"
#include <vector>
#include "PRMGenerator.h"

namespace mst {
namespace Primes {

PRMGenerator::PRMGenerator() : m_primes(), m_number(1) {
	
}

std::tuple<PRMGenerator::Iterator, PRMGenerator::Iterator> PRMGenerator::GetPrimesLessThanOrEqual(unsigned number) const {
	this->_EnsurePrimesAreGenerated(number);
	return make_tuple(this->m_primes.begin(), this->m_primes.end());
}


unsigned int PRMGenerator::GetPrimeAtIndex(unsigned int index) const {
	while (!(index < this->m_primes.size())) {
		this->_EnsurePrimesAreGenerated(this->m_number * 2);
	}
	auto iterator = this->m_primes.begin();
	for (int i = 0; i < index; ++i) {
		++iterator;
	}
	return *iterator;
}

void PRMGenerator::_EnsurePrimesAreGenerated(unsigned number) const {
	if (!(this->m_number < number)) {
		return;
	}

	struct PrimeInfo {
		unsigned int number;
		bool isPrime;
	};

	std::vector<PrimeInfo> primesToAdd;

	for (unsigned int n = this->m_number + 1; n <= number; ++n) {
		PrimeInfo info = { n, true };
		primesToAdd.push_back(info);
	}

	for (auto i = this->m_primes.begin(); i != this->m_primes.end(); ++i) {
		for (auto j = primesToAdd.begin(); j != primesToAdd.end(); ++j) {
			if (j->number % *i == 0) {
				j->isPrime = false;
			}
		}
	}

	for (auto i = primesToAdd.begin(); i != primesToAdd.end(); ++i) {
		for (auto j = i+1; j != primesToAdd.end(); ++j) {
			if (j->number % i->number == 0) {
				j->isPrime = false;
			}
		}
	}

	for (auto i = primesToAdd.begin(); i != primesToAdd.end(); ++i) {
		if (i->isPrime) {
			this->m_primes.push_back(i->number);
		}
	}

	this->m_number = number;
}

}
}
