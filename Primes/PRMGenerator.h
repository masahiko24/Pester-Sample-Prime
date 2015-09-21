/// @file   PRMGenerator.h
/// @author Masahiko Tsujita
/// @date   2015/09/22
/// @note   Copyright (c) 2015年 Masahiko Tsujita. All rights reserved.

#if !defined __Primes_Primes_PrimeGenerator_h__
#define __Primes_Primes_PrimeGenerator_h__

#include <tuple>
#include <list>

namespace mst {
namespace Primes {

/**
@class	PRMGenerator
@brief	素数を生成するクラス。
*/
class PRMGenerator {
public:

	/// イテレータの型。
	using Iterator = std::list<unsigned int>::const_iterator;

	/// コンストラクタ。
	PRMGenerator();

	///	指定した数値以下の素数をすべて取得します。
	std::tuple < Iterator, Iterator > GetPrimesLessThanOrEqual(unsigned int number) const;

	/// 指定したインデックスの素数を取得します。
	unsigned int GetPrimeAtIndex(unsigned int index) const;

private:

	void _EnsurePrimesAreGenerated(unsigned int number) const;

	mutable std::list<unsigned int> m_primes;

	mutable unsigned int m_number;

	PRMGenerator(const PRMGenerator& other) = delete;

	PRMGenerator(PRMGenerator&& other) = delete;

	PRMGenerator& operator=(const PRMGenerator& other) = delete;

	PRMGenerator& operator=(PRMGenerator&& other) = delete;

};
}
}

#endif // __Primes_Primes_PrimeGenerator_h__

