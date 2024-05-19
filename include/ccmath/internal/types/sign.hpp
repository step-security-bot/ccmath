/*
 * Copyright (c) 2024-Present Ian Pike
 * Copyright (c) 2024-Present ccmath contributors
 *
 * This library is provided under the MIT License.
 * See LICENSE for more information.
 */

#pragma once

namespace ccm::types
{
	// A type to interact with signed arithmetic types.
	struct Sign {
		[[nodiscard]] constexpr bool is_pos() const { return !is_negative; }
		[[nodiscard]] constexpr bool is_neg() const { return is_negative; }

		friend constexpr bool operator==(Sign a, Sign b) {
			return a.is_negative == b.is_negative;
		}

		friend constexpr bool operator!=(Sign a, Sign b) {
			return !(a == b);
		}

		static const Sign POS;
		static const Sign NEG;

	private:
		constexpr explicit Sign(bool is_negative)
			: is_negative(is_negative) {}

		bool is_negative;
	};

	constexpr Sign Sign::NEG = Sign(true);
	constexpr Sign Sign::POS = Sign(false);
} // namespace ccm::types
