/*
 * Copyright (c) 2024-Present Ian Pike
 * Copyright (c) 2024-Present ccmath contributors
 *
 * This library is provided under the MIT License.
 * See LICENSE for more information.
 */

#pragma once

#include "ccmath/internal/support/fp_bits.hpp"

namespace ccm
{
	template <typename T, std::enable_if_t<std::is_floating_point_v<T>, int> = 0>
constexpr T frexp(T x, int &exp) {
		fputil::FPBits<T> bits(x);
		if (bits.is_inf_or_nan())
			return x;
		if (bits.is_zero()) {
			exp = 0;
			return x;
		}

		NormalFloat<T> normal(bits);
		exp = normal.exponent + 1;
		normal.exponent = -1;
		return normal;
	}

} // namespace ccm
