/*
* Copyright (c) 2024-Present Ian Pike
* Copyright (c) 2024-Present ccmath contributors
*
* This library is provided under the MIT License.
* See LICENSE for more information.
*/

#include <gtest/gtest.h>

#include "ccmath/ccmath.hpp"

#include <cmath>
#include <limits>

TEST(CcmathPowerTests, Pow_Unsigned_Integral)
{
	constexpr unsigned int x = 2;
	constexpr unsigned int y = 2;
	EXPECT_EQ(ccm::internal::impl::pow_expo_by_sqr(x, y), std::pow(x, y));
}

TEST(CcmathPowerTests, Pow_Double)
{
	static_assert(ccm::pow(2.0, 2.0) == 4, "ccm::pow is not working with static_assert!");

	EXPECT_EQ(std::pow(14.0, 2.0), std::exp2(2.0 * std::log2(14.0)));


	// Test for a base of 2
	EXPECT_EQ(ccm::pow(2.0, 0.5), std::pow(2.0, 0.5));
	EXPECT_EQ(ccm::pow(2.0, 1.0), std::pow(2.0, 1.0));
	EXPECT_EQ(ccm::pow(2.0, 2.0), std::pow(2.0, 2.0));
	EXPECT_EQ(ccm::pow(2.0, 3.0), std::pow(2.0, 3.0));
	EXPECT_EQ(ccm::pow(2.0, 4.0), std::pow(2.0, 4.0));
	EXPECT_EQ(ccm::pow(2.0, 5.0), std::pow(2.0, 5.0));
	EXPECT_EQ(ccm::pow(2.0, 6.0), std::pow(2.0, 6.0));
	EXPECT_EQ(ccm::pow(2.0, 7.0), std::pow(2.0, 7.0));
	EXPECT_EQ(ccm::pow(2.0, 8.0), std::pow(2.0, 8.0));

	// Test for a even base that is not a multiple of 2^n
	EXPECT_EQ(ccm::pow(14.0, 0.5), std::pow(14.0, 0.5));
	EXPECT_EQ(ccm::pow(14.0, 1.0), std::pow(14.0, 1.0));
	EXPECT_EQ(ccm::pow(14.0, 2.0), std::pow(14.0, 2.0));
	EXPECT_EQ(ccm::pow(14.0, 3.0), std::pow(14.0, 3.0));
	EXPECT_EQ(ccm::pow(14.0, 4.0), std::pow(14.0, 4.0));
	EXPECT_EQ(ccm::pow(14.0, 5.0), std::pow(14.0, 5.0));
	EXPECT_EQ(ccm::pow(14.0, 6.0), std::pow(14.0, 6.0));
	EXPECT_EQ(ccm::pow(14.0, 7.0), std::pow(14.0, 7.0));
	EXPECT_EQ(ccm::pow(14.0, 8.0), std::pow(14.0, 8.0));

	// Test for an odd base
	EXPECT_EQ(ccm::pow(3.0, 0.5), std::pow(3.0, 0.5));
	EXPECT_EQ(ccm::pow(3.0, 1.0), std::pow(3.0, 1.0));
	EXPECT_EQ(ccm::pow(3.0, 2.0), std::pow(3.0, 2.0));
	EXPECT_EQ(ccm::pow(3.0, 3.0), std::pow(3.0, 3.0));
	EXPECT_EQ(ccm::pow(3.0, 4.0), std::pow(3.0, 4.0));
	EXPECT_EQ(ccm::pow(3.0, 5.0), std::pow(3.0, 5.0));
	EXPECT_EQ(ccm::pow(3.0, 6.0), std::pow(3.0, 6.0));
	EXPECT_EQ(ccm::pow(3.0, 7.0), std::pow(3.0, 7.0));
	EXPECT_EQ(ccm::pow(3.0, 8.0), std::pow(3.0, 8.0));

	// Test for negative base
	EXPECT_EQ(ccm::pow(-4.0, 0.5), std::pow(-4.0, 0.5));
	EXPECT_EQ(ccm::pow(-4.0, 1.0), std::pow(-4.0, 1.0));
	EXPECT_EQ(ccm::pow(-4.0, 2.0), std::pow(-4.0, 2.0));
	EXPECT_EQ(ccm::pow(-4.0, 3.0), std::pow(-4.0, 3.0));
	EXPECT_EQ(ccm::pow(-4.0, 4.0), std::pow(-4.0, 4.0));
	EXPECT_EQ(ccm::pow(-4.0, 5.0), std::pow(-4.0, 5.0));
	EXPECT_EQ(ccm::pow(-4.0, 6.0), std::pow(-4.0, 6.0));
	EXPECT_EQ(ccm::pow(-4.0, 7.0), std::pow(-4.0, 7.0));
	EXPECT_EQ(ccm::pow(-4.0, 8.0), std::pow(-4.0, 8.0));

	// Test for negative base and exponent
	EXPECT_EQ(ccm::pow(-4.0, -0.5), std::pow(-4.0, -0.5));
	EXPECT_EQ(ccm::pow(-4.0, -1.0), std::pow(-4.0, -1.0));
	EXPECT_EQ(ccm::pow(-4.0, -2.0), std::pow(-4.0, -2.0));
	EXPECT_EQ(ccm::pow(-4.0, -3.0), std::pow(-4.0, -3.0));
	EXPECT_EQ(ccm::pow(-4.0, -4.0), std::pow(-4.0, -4.0));
	EXPECT_EQ(ccm::pow(-4.0, -5.0), std::pow(-4.0, -5.0));
	EXPECT_EQ(ccm::pow(-4.0, -6.0), std::pow(-4.0, -6.0));
	EXPECT_EQ(ccm::pow(-4.0, -7.0), std::pow(-4.0, -7.0));
	EXPECT_EQ(ccm::pow(-4.0, -8.0), std::pow(-4.0, -8.0));

	// Test for positive base and negative exponent
	EXPECT_EQ(ccm::pow(20.0, -0.5), std::pow(20.0, -0.5));
	EXPECT_EQ(ccm::pow(20.0, -1.0), std::pow(20.0, -1.0));
	EXPECT_EQ(ccm::pow(20.0, -2.0), std::pow(20.0, -2.0));
	EXPECT_EQ(ccm::pow(20.0, -3.0), std::pow(20.0, -3.0));
	EXPECT_EQ(ccm::pow(20.0, -4.0), std::pow(20.0, -4.0));
	EXPECT_EQ(ccm::pow(20.0, -5.0), std::pow(20.0, -5.0));
	EXPECT_EQ(ccm::pow(20.0, -6.0), std::pow(20.0, -6.0));
	EXPECT_EQ(ccm::pow(20.0, -7.0), std::pow(20.0, -7.0));
	EXPECT_EQ(ccm::pow(20.0, -8.0), std::pow(20.0, -8.0));

	// Test for large base and small exponent
	EXPECT_EQ(ccm::pow(123456.7, 0.5), std::pow(123456.7, 0.5));
	EXPECT_EQ(ccm::pow(123456.7, 1.0), std::pow(123456.7, 1.0));
	EXPECT_EQ(ccm::pow(123456.7, 2.0), std::pow(123456.7, 2.0));
	EXPECT_EQ(ccm::pow(123456.7, 3.0), std::pow(123456.7, 3.0));
	EXPECT_EQ(ccm::pow(123456.7, 4.0), std::pow(123456.7, 4.0));
	EXPECT_EQ(ccm::pow(123456.7, 5.0), std::pow(123456.7, 5.0));
	EXPECT_EQ(ccm::pow(123456.7, 6.0), std::pow(123456.7, 6.0));
	EXPECT_EQ(ccm::pow(123456.7, 7.0), std::pow(123456.7, 7.0));
	EXPECT_EQ(ccm::pow(123456.7, 8.0), std::pow(123456.7, 8.0));

	// Test for small base and large exponent
	EXPECT_EQ(ccm::pow(0.1, 123456.7), std::pow(0.1, 123456.7));
	EXPECT_EQ(ccm::pow(0.2, 123456.7), std::pow(0.2, 123456.7));
	EXPECT_EQ(ccm::pow(0.3, 123456.7), std::pow(0.3, 123456.7));
	EXPECT_EQ(ccm::pow(0.4, 123456.7), std::pow(0.4, 123456.7));
	EXPECT_EQ(ccm::pow(0.5, 123456.7), std::pow(0.5, 123456.7));
	EXPECT_EQ(ccm::pow(0.6, 123456.7), std::pow(0.6, 123456.7));
	EXPECT_EQ(ccm::pow(0.7, 123456.7), std::pow(0.7, 123456.7));
	EXPECT_EQ(ccm::pow(0.8, 123456.7), std::pow(0.8, 123456.7));



}