// AllCodes.cpp:
//

#include "stdafx.h"
#include <gtest/gtest.h>

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "");
	if (argc == 1)
	{
		// 提示输入过滤
		std::cout << "Please enter a filter string or run all test cases." << std::endl;
		std::string input;
		getline(std::cin, input);
		//std::cin >> input;
		if (!input.empty())
		{
			testing::GTEST_FLAG(filter) = input;
		}
	}

	testing::InitGoogleTest(&argc, argv);
	
	
	RUN_ALL_TESTS();
    return 0;
}

