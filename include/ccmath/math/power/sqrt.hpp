/*
 * Copyright (c) 2024-Present Ian Pike
 * Copyright (c) 2024-Present ccmath contributors
 *
 * This library is provided under the MIT License.
 * See LICENSE for more information.
 */

#pragma once

#if !(defined(__GNUC__) && (__GNUC__ > 6 || (__GNUC__ == 6 && __GNUC_MINOR__ >= 1)) && !defined(__clang__))
	#include "ccmath/internal/compiletime/functions/power/sqrt_ct.hpp"
	#include "ccmath/internal/runtime/functions/power/sqrt_rt.hpp"
	#include "ccmath/internal/support/is_constant_evaluated.hpp"
#endif

#include <type_traits>

namespace ccm
{

	/**
	 * @brief Calculates the square root of a number.
	 * @tparam T Floating-point type or integer type.
	 * @param num Floating-point or integer number.
	 * @return If no errors occur, square root of num (√num), is returned.
	 */
	template <typename T, std::enable_if_t<std::is_floating_point_v<T>, bool> = true>
	constexpr T sqrt(T num)
	{
#if defined(__GNUC__) && (__GNUC__ > 6 || (__GNUC__ == 6 && __GNUC_MINOR__ >= 1)) && !defined(__clang__) // GCC 6.1+ has constexpr sqrt builtins.
		if constexpr (std::is_same_v<T, float>) { return __builtin_sqrtf(num); }
		if constexpr (std::is_same_v<T, double>) { return __builtin_sqrt(num); }
		if constexpr (std::is_same_v<T, long double>) { return __builtin_sqrtl(num); }
		return static_cast<T>(__builtin_sqrtl(num));
#else
		if constexpr (ccm::support::is_constant_evaluated()) { return ccm::ct::sqrt_ct<T>(num); }
		else { return ccm::rt::sqrt_rt<T>(num); }
#endif
	}

	/**
	 * @brief Calculates the square root of a number.
	 * @tparam Integer Integer type.
	 * @param num Integer number.
	 * @return If no errors occur, square root of num (√num), is returned.
	 */
	template <typename Integer, std::enable_if_t<!std::is_floating_point_v<Integer>, bool> = true>
	constexpr double sqrt(Integer num)
	{
		return ccm::sqrt<double>(static_cast<double>(num));
	}

	/**
	 * @brief Calculates the square root of a number.
	 * @param num Floating-point number.
	 * @return If no errors occur, square root of num (√num), is returned.
	 */
	constexpr float sqrtf(float num)
	{
		return ccm::sqrt<float>(num);
	}

	/**
	 * @brief Calculates the square root of a number.
	 * @param num Floating-point number.
	 * @return If no errors occur, square root of num (√num), is returned.
	 */
	constexpr long double sqrtl(long double num)
	{
		return ccm::sqrt<long double>(num);
	}
} // namespace ccm

/// @ingroup power