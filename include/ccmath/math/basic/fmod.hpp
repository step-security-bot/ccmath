/*
 * Copyright (c) Ian Pike
 * Copyright (c) CCMath contributors
 *
 * CCMath is provided under the Apache-2.0 License WITH LLVM-exception.
 * See LICENSE for more information.
 *
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 */

#pragma once

#include "ccmath/internal/predef/unlikely.hpp"
#include "ccmath/internal/support/fp/fp_bits.hpp"
#include "ccmath/math/nearest/trunc.hpp"

#include <limits>

namespace ccm
{
	/// @cond CCMATH_INTERNAL
	namespace internal::impl
	{
		template <typename T>
		constexpr T fmod_impl_check(T x, T y) noexcept
		{
			// Special edge cases for floating-point types.
			if constexpr (std::numeric_limits<T>::is_iec559)
			{
				using FPBits_t = typename ccm::support::fp::FPBits<T>;
				const FPBits_t x_bits(x);
				const FPBits_t y_bits(y);

				// If x is ±0 and y is not zero, ±0 is returned.
				if (CCM_UNLIKELY(x_bits.is_zero() && !y_bits.is_zero()))
				{
					// The standard specifies that plus or minus 0 is returned depending on the sign of x.
					return x;
				}

				// If x is ±∞ and y is not NaN OR if y is ±0 and x is not NaN, -NaN is returned
				if (CCM_UNLIKELY((x_bits.is_inf() && !y_bits.is_nan()) || (y_bits.is_zero() && !x_bits.is_nan())))
				{
					// For some reason, all the major compilers return a negative NaN
					// even though I can't find anywhere in the standard that specifies this.
					// I'm going to follow suit and return a negative NaN for now.
					// Overall, this has little effect on checking for NaN.
					// We only really care for conformance with the standard.
					return -std::numeric_limits<T>::quiet_NaN();
				}

				// If y is ±∞ and x is finite, x is returned.
				if (CCM_UNLIKELY(y_bits.is_inf() && x_bits.is_finite())) { return x; }

				// If either argument is NaN, NaN is returned.
				if (CCM_UNLIKELY(x_bits.is_nan() || y_bits.is_nan()))
				{
					// Same problem as before, but this time all major compilers return a positive NaN.
					return std::numeric_limits<T>::quiet_NaN();
				}
			}

			// Calculate the remainder of the division of x by y.
			// Static_cast is required to prevent the compiler from complaining about narrowing with integer types.
			return static_cast<T>(x - (ccm::trunc<T>(x / y) * y));
		}

		template <typename T, typename U, typename TC = std::common_type_t<T, U>>
		constexpr TC fmod_impl_type_check(T x, U y) noexcept
		{
			return fmod_impl_check(static_cast<TC>(x), static_cast<TC>(y));
		}
	} // namespace internal::impl
	/// @endcond

	/**
	 * @brief Returns the floating-point remainder of the division operation x/y.
	 * @note Some edge cases where NaN is returned are different from std::fmod due to the standard allowing implementation based returns.
	 * @tparam T A floating-point type.
	 * @param x A floating-point value.
	 * @param y A floating-point value.
	 * @return The floating-point remainder of the division operation x/y.
	 */
	template <typename Real, std::enable_if_t<std::is_floating_point_v<Real>, bool> = true>
	constexpr Real fmod(Real x, Real y)
	{
		return internal::impl::fmod_impl_check(x, y);
	}

	/**
	 * @brief Returns the floating-point remainder of the division operation x/y.
	 * @tparam Integer An integral type.
	 * @param x An integral value.
	 * @param y An integral value.
	 * @return The floating-point remainder of the division operation x/y.
	 */
	template <typename Integer, std::enable_if_t<std::is_integral_v<Integer>, bool> = true>
	constexpr double fmod(Integer x, Integer y)
	{
		return internal::impl::fmod_impl_type_check(x, y);
	}

	/**
	 * @brief Returns the floating-point remainder of the division operation x/y.
	 * @tparam T A floating-point or integral type.
	 * @tparam U A floating-point or integral type.
	 * @param x A floating-point or integral value.
	 * @param y A floating-point or integral value.
	 * @return The floating-point remainder of the division operation x/y.
	 */
	template <typename T, typename U>
	constexpr auto fmod(T x, T y)
	{
		return internal::impl::fmod_impl_type_check(x, y);
	}

	/**
	 * @brief Returns the floating-point remainder of the division operation x/y.
	 * @param x A floating-point value.
	 * @param y A floating-point value.
	 * @return The floating-point remainder of the division operation x/y.
	 */
	constexpr float fmodf(float x, float y)
	{
		return fmod<float>(x, y);
	}

	/**
	 * @brief Returns the floating-point remainder of the division operation x/y.
	 * @param x A floating-point value.
	 * @param y A floating-point value.
	 * @return The floating-point remainder of the division operation x/y.
	 */
	constexpr long double fmodl(long double x, long double y)
	{
		return fmod<long double>(x, y);
	}
} // namespace ccm

/// @ingroup basic
