/// @file	main.cpp
/// @author	Masahiko Tsujita
/// @date	2015/09/22
/// @note	Copyright (c) 2015年 Masahiko Tsujita. All rights reserved.

//------------------------------------------------------------------------------
//	ファイル依存関係
//------------------------------------------------------------------------------
#include "stdafx.h"
#include <ostream>
#include <iostream>
#include "PRMGenerator.h"

namespace mst {
namespace Primes {

/**
@enum	PRMExitCode
@brief	終了コード
*/
enum class PRMExitCode : int {
	Success = 0,		///<	成功。
	InvalidArguments,	///<	引数が正しくない。
};

}
}

/**
コンソール アプリケーションのエントリ ポイントを定義します。
*/
int main(int argc, const char *pArgv[]) {
	using mst::Primes::PRMExitCode;

	if (argc != 3) {
		std::cerr << "引数の数が正しくありません。" << std::endl;
		return static_cast<int>(PRMExitCode::InvalidArguments);
	}

	mst::Primes::PRMGenerator generator;

	unsigned int num;
	try {
		num = atoi(pArgv[2]);
	} catch (...) {
		std::cerr << "引数を数値に変換できません。" << std::endl;
		return static_cast<int>(PRMExitCode::InvalidArguments);
	}

	const char *pOption = pArgv[1];
	if (0 == strcmp(pOption, "-le")) {
		auto primes = generator.GetPrimesLessThanOrEqual(num);
		std::cout << "[";
		for (auto p = std::get<0>(primes); p != std::get<1>(primes); ++p) {
			std::cout << " " << *p;
		}
		std::cout << " ]" << std::endl;
	} else if (0 == strcmp(pOption, "-at")) {
		if (!(num > 0)) {
			std::cerr << "インデックスは0より大きくなければなりません。" << std::endl;
			return static_cast<int>(PRMExitCode::InvalidArguments);
		}
		std::cout << generator.GetPrimeAtIndex(num-1) << std::endl;
	} else {
		std::cerr << "オプションが正しくありません。" << std::endl;
		return static_cast<int>(PRMExitCode::InvalidArguments);
	}

    return static_cast<int>(PRMExitCode::Success);
}
