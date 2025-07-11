/*
Copyright © 2018 Felipe Ferreira da Silva

This software is provided 'as-is', without any express or implied warranty. In
no event will the authors be held liable for any damages arising from the use of
this software.

Permission is granted to anyone to use this software for any purpose, including
commercial applications, and to alter it and redistribute it freely, subject to
the following restrictions:

  1. The origin of this software must not be misrepresented; you must not claim
     that you wrote the original software. If you use this software in a
     product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

/*
The following code has been altered by White_145, stated as per license agreement.
https://github.com/White-145/mathc
*/

#include "mathc.h"

#if defined(MATHC_USE_FLOATING_POINT)
bool nearly_equal(mfloat_t a, mfloat_t b, mfloat_t epsilon) {
    bool result = false;
    if (a == b) {
        result = true;
    } else if (MFABS(a - b) <= epsilon) {
        result = true;
    }
    return result;
}

mfloat_t to_radians(mfloat_t degrees) {
    return MRADIANS(degrees);
}

mfloat_t to_degrees(mfloat_t radians) {
    return MDEGREES(radians);
}

mfloat_t clampf(mfloat_t value, mfloat_t min, mfloat_t max) {
    if (value < min) {
        value = min;
    } else if (value > max) {
        value = max;
    }
    return value;
}
#endif