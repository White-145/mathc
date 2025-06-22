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

#include "mathc.h"

#if defined(MATHC_USE_INT)
bool vec4i_is_zero(const mint_t *v0) {
    return v0[0] == 0 && v0[1] == 0 && v0[2] == 0 && v0[3] == 0;
}

bool vec4i_is_equal(const mint_t *v0, const mint_t *v1) {
    return v0[0] == v1[0] && v0[1] == v1[1] && v0[2] == v1[2] && v0[3] == v1[3];
}

mint_t *vec4i(mint_t *result, mint_t x, mint_t y, mint_t z, mint_t w) {
    result[0] = x;
    result[1] = y;
    result[2] = z;
    result[3] = w;
    return result;
}

mint_t *vec4i_assign(mint_t *result, const mint_t *v0) {
    memcpy(result, v0, sizeof(mint_t) * VEC4_SIZE);
    return result;
}

mint_t *vec4i_zero(mint_t *result) {
    memset(result, 0, sizeof(mint_t) * VEC4_SIZE);
    return result;
}

mint_t *vec4i_one(mint_t *result) {
    memset(result, 1, sizeof(mint_t) * VEC4_SIZE);
    return result;
}

mint_t *vec4i_sign(mint_t *result, const mint_t *v0) {
    if (v0[0] > 0) {
        result[0] = 1;
    } else if (v0[0] < 0) {
        result[0] = -1;
    } else {
        result[0] = 0;
    }
    if (v0[1] > 0) {
        result[1] = 1;
    } else if (v0[1] < 0) {
        result[1] = -1;
    } else {
        result[1] = 0;
    }
    if (v0[2] > 0) {
        result[2] = 1;
    } else if (v0[2] < 0) {
        result[2] = -1;
    } else {
        result[2] = 0;
    }
    if (v0[3] > 0) {
        result[3] = 1;
    } else if (v0[3] < 0) {
        result[3] = -1;
    } else {
        result[3] = 0;
    }
    return result;
}

mint_t *vec4i_add(mint_t *result, const mint_t *v0, const mint_t *v1) {
    result[0] = v0[0] + v1[0];
    result[1] = v0[1] + v1[1];
    result[2] = v0[2] + v1[2];
    result[3] = v0[3] + v1[3];
    return result;
}

mint_t *vec4i_add_i(mint_t *result, const mint_t *v0, mint_t i) {
    result[0] = v0[0] + i;
    result[1] = v0[1] + i;
    result[2] = v0[2] + i;
    result[3] = v0[3] + i;
    return result;
}

mint_t *vec4i_subtract(mint_t *result, const mint_t *v0, const mint_t *v1) {
    result[0] = v0[0] - v1[0];
    result[1] = v0[1] - v1[1];
    result[2] = v0[2] - v1[2];
    result[3] = v0[3] - v1[3];
    return result;
}

mint_t *vec4i_subtract_i(mint_t *result, const mint_t *v0, mint_t i) {
    result[0] = v0[0] - i;
    result[1] = v0[1] - i;
    result[2] = v0[2] - i;
    result[3] = v0[3] - i;
    return result;
}

mint_t *vec4i_multiply(mint_t *result, const mint_t *v0, const mint_t *v1) {
    result[0] = v0[0] * v1[0];
    result[1] = v0[1] * v1[1];
    result[2] = v0[2] * v1[2];
    result[3] = v0[3] * v1[3];
    return result;
}

mint_t *vec4i_multiply_i(mint_t *result, const mint_t *v0, mint_t i) {
    result[0] = v0[0] * i;
    result[1] = v0[1] * i;
    result[2] = v0[2] * i;
    result[3] = v0[3] * i;
    return result;
}

mint_t *vec4i_divide(mint_t *result, const mint_t *v0, const mint_t *v1) {
    result[0] = v0[0] / v1[0];
    result[1] = v0[1] / v1[1];
    result[2] = v0[2] / v1[2];
    result[3] = v0[3] / v1[3];
    return result;
}

mint_t *vec4i_divide_i(mint_t *result, const mint_t *v0, mint_t i) {
    result[0] = v0[0] / i;
    result[1] = v0[1] / i;
    result[2] = v0[2] / i;
    result[3] = v0[3] / i;
    return result;
}

mint_t *vec4i_snap(mint_t *result, const mint_t *v0, const mint_t *v1) {
    result[0] = (v0[0] / v1[0]) * v1[0];
    result[1] = (v0[1] / v1[1]) * v1[1];
    result[2] = (v0[2] / v1[2]) * v1[2];
    result[3] = (v0[3] / v1[3]) * v1[3];
    return result;
}

mint_t *vec4i_snap_i(mint_t *result, const mint_t *v0, mint_t i) {
    result[0] = (v0[0] / i) * i;
    result[1] = (v0[1] / i) * i;
    result[2] = (v0[2] / i) * i;
    result[3] = (v0[3] / i) * i;
    return result;
}

mint_t *vec4i_negative(mint_t *result, const mint_t *v0) {
    result[0] = -v0[0];
    result[1] = -v0[1];
    result[2] = -v0[2];
    result[3] = -v0[3];
    return result;
}

mint_t *vec4i_abs(mint_t *result, const mint_t *v0) {
    result[0] = v0[0];
    if (result[0] < 0) {
        result[0] = -result[0];
    }
    result[1] = v0[1];
    if (result[1] < 0) {
        result[1] = -result[1];
    }
    result[2] = v0[2];
    if (result[2] < 0) {
        result[2] = -result[2];
    }
    result[3] = v0[3];
    if (result[3] < 0) {
        result[3] = -result[3];
    }
    return result;
}

mint_t *vec4i_max(mint_t *result, const mint_t *v0, const mint_t *v1) {
    if (v0[0] > v1[0]) {
        result[0] = v0[0];
    } else {
        result[0] = v1[0];
    }
    if (v0[1] > v1[1]) {
        result[1] = v0[1];
    } else {
        result[1] = v1[1];
    }
    if (v0[2] > v1[2]) {
        result[2] = v0[2];
    } else {
        result[2] = v1[2];
    }
    if (v0[3] > v1[3]) {
        result[3] = v0[3];
    } else {
        result[3] = v1[3];
    }
    return result;
}

mint_t *vec4i_min(mint_t *result, const mint_t *v0, const mint_t *v1) {
    if (v0[0] < v1[0]) {
        result[0] = v0[0];
    } else {
        result[0] = v1[0];
    }
    if (v0[1] < v1[1]) {
        result[1] = v0[1];
    } else {
        result[1] = v1[1];
    }
    if (v0[2] < v1[2]) {
        result[2] = v0[2];
    } else {
        result[2] = v1[2];
    }
    if (v0[3] < v1[3]) {
        result[3] = v0[3];
    } else {
        result[3] = v1[3];
    }
    return result;
}

mint_t *vec4i_clamp(mint_t *result, const mint_t *v0, const mint_t *v1, const mint_t *v2) {
    if (v0[0] < v1[0]) {
        result[0] = v1[0];
    } else if (v0[0] > v2[0]) {
        result[0] = v2[0];
    } else {
        result[0] = v0[0];
    }
    if (v0[1] < v1[1]) {
        result[1] = v1[1];
    } else if (v0[1] > v2[1]) {
        result[1] = v2[1];
    } else {
        result[1] = v0[1];
    }
    if (v0[2] < v1[2]) {
        result[2] = v1[2];
    } else if (v0[2] > v2[2]) {
        result[2] = v2[2];
    } else {
        result[2] = v0[2];
    }
    if (v0[3] < v1[3]) {
        result[3] = v1[3];
    } else if (v0[3] > v2[3]) {
        result[3] = v2[3];
    } else {
        result[3] = v0[3];
    }
    return result;
}

#if defined(MATHC_USE_FLOATING_POINT)
mint_t *vec4i_assign_vec4(mint_t *result, const mfloat_t *v0) {
    result[0] = (mint_t)v0[0];
    result[1] = (mint_t)v0[1];
    result[2] = (mint_t)v0[2];
    result[3] = (mint_t)v0[3];
    return result;
}
#endif

#if defined(MATHC_USE_STRUCT_FUNCTIONS)
bool svec4i_is_zero(struct vec4i v0) {
    return vec4i_is_zero((const mint_t *)&v0);
}

bool svec4i_is_equal(struct vec4i v0, struct vec4i v1) {
    return vec4i_is_equal((const mint_t *)&v0, (const mint_t *)&v1);
}

struct vec4i svec4i(mint_t x, mint_t y, mint_t z, mint_t w) {
    struct vec4i result;
    vec4i((mint_t *)&result, x, y, z, w);
    return result;
}

struct vec4i svec4i_assign(struct vec4i v0) {
    struct vec4i result;
    vec4i_assign((mint_t *)&result, (const mint_t *)&v0);
    return result;
}

struct vec4i svec4i_zero(void) {
    struct vec4i result;
    vec4i_zero((mint_t *)&result);
    return result;
}

struct vec4i svec4i_one(void) {
    struct vec4i result;
    vec4i_one((mint_t *)&result);
    return result;
}

struct vec4i svec4i_sign(struct vec4i v0) {
    struct vec4i result;
    vec4i_sign((mint_t *)&result, (const mint_t *)&v0);
    return result;
}

struct vec4i svec4i_add(struct vec4i v0, struct vec4i v1) {
    struct vec4i result;
    vec4i_add((mint_t *)&result, (const mint_t *)&v0, (const mint_t *)&v1);
    return result;
}

struct vec4i svec4i_add_i(struct vec4i v0, mint_t i) {
    struct vec4i result;
    vec4i_add_i((mint_t *)&result, (const mint_t *)&v0, i);
    return result;
}

struct vec4i svec4i_subtract(struct vec4i v0, struct vec4i v1) {
    struct vec4i result;
    vec4i_subtract((mint_t *)&result, (const mint_t *)&v0, (const mint_t *)&v1);
    return result;
}

struct vec4i svec4i_subtract_i(struct vec4i v0, mint_t i) {
    struct vec4i result;
    vec4i_subtract_i((mint_t *)&result, (const mint_t *)&v0, i);
    return result;
}

struct vec4i svec4i_multiply(struct vec4i v0, struct vec4i v1) {
    struct vec4i result;
    vec4i_multiply((mint_t *)&result, (const mint_t *)&v0, (const mint_t *)&v1);
    return result;
}

struct vec4i svec4i_multiply_i(struct vec4i v0, mint_t i) {
    struct vec4i result;
    vec4i_multiply_i((mint_t *)&result, (const mint_t *)&v0, i);
    return result;
}

struct vec4i svec4i_divide(struct vec4i v0, struct vec4i v1) {
    struct vec4i result;
    vec4i_divide((mint_t *)&result, (const mint_t *)&v0, (const mint_t *)&v1);
    return result;
}

struct vec4i svec4i_divide_i(struct vec4i v0, mint_t i) {
    struct vec4i result;
    vec4i_divide_i((mint_t *)&result, (const mint_t *)&v0, i);
    return result;
}

struct vec4i svec4i_snap(struct vec4i v0, struct vec4i v1) {
    struct vec4i result;
    vec4i_snap((mint_t *)&result, (const mint_t *)&v0, (const mint_t *)&v1);
    return result;
}

struct vec4i svec4i_snap_i(struct vec4i v0, mint_t i) {
    struct vec4i result;
    vec4i_snap_i((mint_t *)&result, (const mint_t *)&v0, i);
    return result;
}

struct vec4i svec4i_negative(struct vec4i v0) {
    struct vec4i result;
    vec4i_negative((mint_t *)&result, (const mint_t *)&v0);
    return result;
}

struct vec4i svec4i_abs(struct vec4i v0) {
    struct vec4i result;
    vec4i_abs((mint_t *)&result, (const mint_t *)&v0);
    return result;
}

struct vec4i svec4i_max(struct vec4i v0, struct vec4i v1) {
    struct vec4i result;
    vec4i_max((mint_t *)&result, (const mint_t *)&v0, (const mint_t *)&v1);
    return result;
}

struct vec4i svec4i_min(struct vec4i v0, struct vec4i v1) {
    struct vec4i result;
    vec4i_min((mint_t *)&result, (const mint_t *)&v0, (const mint_t *)&v1);
    return result;
}

struct vec4i svec4i_clamp(struct vec4i v0, struct vec4i v1, struct vec4i v2) {
    struct vec4i result;
    vec4i_clamp((mint_t *)&result, (const mint_t *)&v0, (const mint_t *)&v1, (const mint_t *)&v2);
    return result;
}

#if defined(MATHC_USE_FLOATING_POINT)
struct vec4i svec4i_assign_vec4(struct vec4 v0) {
    struct vec4i result;
    vec4i_assign_vec4((mint_t *)&result, (const mfloat_t *)&v0);
    return result;
}
#endif
#endif

#if defined(MATHC_USE_POINTER_STRUCT_FUNCTIONS)
bool psvec4i_is_zero(struct vec4i *v0) {
    return vec4i_is_zero((const mint_t *)v0);
}

bool psvec4i_is_equal(struct vec4i *v0, struct vec4i *v1) {
    return vec4i_is_equal((const mint_t *)v0, (const mint_t *)v1);
}

struct vec4i *psvec4i(struct vec4i *result, mint_t x, mint_t y, mint_t z, mint_t w) {
    return (struct vec4i *)vec4i((mint_t *)result, x, y, z, w);
}

struct vec4i *psvec4i_assign(struct vec4i *result, struct vec4i *v0) {
    return (struct vec4i *)vec4i_assign((mint_t *)result, (const mint_t *)v0);
}

struct vec4i *psvec4i_zero(struct vec4i *result) {
    return (struct vec4i *)vec4i_zero((mint_t *)result);
}

struct vec4i *psvec4i_one(struct vec4i *result) {
    return (struct vec4i *)vec4i_one((mint_t *)result);
}

struct vec4i *psvec4i_sign(struct vec4i *result, struct vec4i *v0) {
    return (struct vec4i *)vec4i_sign((mint_t *)result, (const mint_t *)v0);
}

struct vec4i *psvec4i_add(struct vec4i *result, struct vec4i *v0, struct vec4i *v1) {
    return (struct vec4i *)vec4i_add((mint_t *)result, (const mint_t *)v0, (const mint_t *)v1);
}

struct vec4i *psvec4i_add_i(struct vec4i *result, struct vec4i *v0, mint_t i) {
    return (struct vec4i *)vec4i_add_i((mint_t *)result, (const mint_t *)v0, i);
}

struct vec4i *psvec4i_subtract(struct vec4i *result, struct vec4i *v0, struct vec4i *v1) {
    return (struct vec4i *)vec4i_subtract((mint_t *)result, (const mint_t *)v0, (const mint_t *)v1);
}

struct vec4i *psvec4i_subtract_i(struct vec4i *result, struct vec4i *v0, mint_t i) {
    return (struct vec4i *)vec4i_subtract_i((mint_t *)result, (const mint_t *)v0, i);
}

struct vec4i *psvec4i_multiply(struct vec4i *result, struct vec4i *v0, struct vec4i *v1) {
    return (struct vec4i *)vec4i_multiply((mint_t *)result, (const mint_t *)v0, (const mint_t *)v1);
}

struct vec4i *psvec4i_multiply_i(struct vec4i *result, struct vec4i *v0, mint_t i) {
    return (struct vec4i *)vec4i_multiply_i((mint_t *)result, (const mint_t *)v0, i);
}

struct vec4i *psvec4i_divide(struct vec4i *result, struct vec4i *v0, struct vec4i *v1) {
    return (struct vec4i *)vec4i_divide((mint_t *)result, (const mint_t *)v0, (const mint_t *)v1);
}

struct vec4i *psvec4i_divide_i(struct vec4i *result, struct vec4i *v0, mint_t i) {
    return (struct vec4i *)vec4i_divide_i((mint_t *)result, (const mint_t *)v0, i);
}

struct vec4i *psvec4i_snap(struct vec4i *result, struct vec4i *v0, struct vec4i *v1) {
    return (struct vec4i *)vec4i_snap((mint_t *)result, (const mint_t *)v0, (const mint_t *)v1);
}

struct vec4i *psvec4i_snap_i(struct vec4i *result, struct vec4i *v0, mint_t i) {
    return (struct vec4i *)vec4i_snap_i((mint_t *)result, (const mint_t *)v0, i);
}

struct vec4i *psvec4i_negative(struct vec4i *result, struct vec4i *v0) {
    return (struct vec4i *)vec4i_negative((mint_t *)result, (const mint_t *)v0);
}

struct vec4i *psvec4i_abs(struct vec4i *result, struct vec4i *v0) {
    return (struct vec4i *)vec4i_abs((mint_t *)result, (const mint_t *)v0);
}

struct vec4i *psvec4i_max(struct vec4i *result, struct vec4i *v0, struct vec4i *v1) {
    return (struct vec4i *)vec4i_max((mint_t *)result, (const mint_t *)v0, (const mint_t *)v1);
}

struct vec4i *psvec4i_min(struct vec4i *result, struct vec4i *v0, struct vec4i *v1) {
    return (struct vec4i *)vec4i_min((mint_t *)result, (const mint_t *)v0, (const mint_t *)v1);
}

struct vec4i *psvec4i_clamp(struct vec4i *result, struct vec4i *v0, struct vec4i *v1, struct vec4i *v2) {
    return (struct vec4i *)vec4i_clamp((mint_t *)result, (const mint_t *)v0, (const mint_t *)v1, (const mint_t *)v2);
}

#if defined(MATHC_USE_FLOATING_POINT)
struct vec4i *psvec4i_assign_vec4(struct vec4i *result, struct vec4 *v0) {
    return (struct vec4i *)vec4i_assign_vec4((mint_t *)result, (const mfloat_t *)v0);
}
#endif
#endif
#endif