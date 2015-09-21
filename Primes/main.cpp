/// @file	main.cpp
/// @author	Masahiko Tsujita
/// @date	2015/09/22
/// @note	Copyright (c) 2015�N Masahiko Tsujita. All rights reserved.

//------------------------------------------------------------------------------
//	�t�@�C���ˑ��֌W
//------------------------------------------------------------------------------
#include "stdafx.h"
#include <ostream>
#include <iostream>
#include "PRMGenerator.h"

namespace mst {
namespace Primes {

/**
@enum	PRMExitCode
@brief	�I���R�[�h
*/
enum class PRMExitCode : int {
	Success = 0,		///<	�����B
	InvalidArguments,	///<	�������������Ȃ��B
};

}
}

/**
�R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
*/
int main(int argc, const char *pArgv[]) {
	using mst::Primes::PRMExitCode;

	if (argc != 3) {
		std::cerr << "�����̐�������������܂���B" << std::endl;
		return static_cast<int>(PRMExitCode::InvalidArguments);
	}

	mst::Primes::PRMGenerator generator;

	unsigned int num;
	try {
		num = atoi(pArgv[2]);
	} catch (...) {
		std::cerr << "�����𐔒l�ɕϊ��ł��܂���B" << std::endl;
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
			std::cerr << "�C���f�b�N�X��0���傫���Ȃ���΂Ȃ�܂���B" << std::endl;
			return static_cast<int>(PRMExitCode::InvalidArguments);
		}
		std::cout << generator.GetPrimeAtIndex(num-1) << std::endl;
	} else {
		std::cerr << "�I�v�V����������������܂���B" << std::endl;
		return static_cast<int>(PRMExitCode::InvalidArguments);
	}

    return static_cast<int>(PRMExitCode::Success);
}
