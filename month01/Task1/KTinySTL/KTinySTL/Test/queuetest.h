#ifndef _QUEUE_TEST_H_
#define _QUEUE_TEST_H_

#include "test_util.h"

#include "../kqueue.h"
#include <queue>

#include <cassert>
#include <string>

namespace TinySTL
{
	namespace QueueTest
	{
		template<class T>
		using stdQ = std::queue < T > ;
		template<class T>
		using tsQ = TinySTL::KQueue < T > ;

		void testCase1();
		void testCase2();
		void testCase3();
		void testCase4();
		void testCase5();

		void testAllCases();
	}
}

#endif