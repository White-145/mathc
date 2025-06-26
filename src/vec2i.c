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

#if defined(MATHC_USE_INT)
bool vec2i_is_zero(const mint_t *v0) {
    return v0[0] == 0 && v0[1] == 0;
}

bool vec2i_is_equal(const mint_t *v0, const mint_t *v1) {
    return v0[0] == v1[0] && v0[1] == v1[1];
}

mint_t *vec2i(mint_t *result, mint_t x, mint_t y) {
    result[0] = x;
    result[1] = y;
    return result;
}

mint_t *vec2i_assign(mint_t *result, const mint_t *v0) {
    result[0] = v0[0];
    result[1] = v0[1];
    return result;
}

mint_t *vec2i_reduce_vec3i(mint_t *result, const mint_t *v0) {
    result[0] = v0[0];
    result[1] = v0[1];
    return result;
}

mint_t *vec2i_reduce_vec4i(mint_t *result, const mint_t *v0) {
    result[0] = v0[0];
    result[1] = v0[1];
    return result;
}

mint_t *vec2i_zero(mint_t *result) {
    result[0] = 0;
    result[1] = 0;
    return result;
}

mint_t *vec2i_one(mint_t *result) {
    result[0] = 1;
    result[1] = 1;
    return result;
}

mint_t *vec2i_sign(mint_t *result, const mint_t *v0) {
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
    return result;
}

mint_t *vec2i_add(mint_t *result, const mint_t *v0, const mint_t *v1) {
    result[0] = v0[0] + v1[0];
    result[1] = v0[1] + v1[1];
    return result;
}

mint_t *vec2i_add_i(mint_t *result, const mint_t *v0, mint_t i) {
    result[0] = v0[0] + i;
    result[1] = v0[1] + i;
    return result;
}

mint_t *vec2i_subtract(mint_t *result, const mint_t *v0, const mint_t *v1) {
    result[0] = v0[0] - v1[0];
    result[1] = v0[1] - v1[1];
    return result;
}

mint_t *vec2i_subtract_i(mint_t *result, const mint_t *v0, mint_t i) {
    result[0] = v0[0] - i;
    result[1] = v0[1] - i;
    return result;
}

mint_t *vec2i_multiply(mint_t *result, const mint_t *v0, const mint_t *v1) {
    result[0] = v0[0] * v1[0];
    result[1] = v0[1] * v1[1];
    return result;
}

mint_t *vec2i_multiply_i(mint_t *result, const mint_t *v0, mint_t i) {
    result[0] = v0[0] * i;
    result[1] = v0[1] * i;
    return result;
}

mint_t *vec2i_divide(mint_t *result, const mint_t *v0, const mint_t *v1) {
    result[0] = v0[0] / v1[0];
    result[1] = v0[1] / v1[1];
    return result;
}

mint_t *vec2i_divide_i(mint_t *result, const mint_t *v0, mint_t i) {
    result[0] = v0[0] / i;
    result[1] = v0[1] / i;
    return result;
}

mint_t *vec2i_snap(mint_t *result, const mint_t *v0, const mint_t *v1) {
    result[0] = (v0[0] / v1[0]) * v1[0];
    result[1] = (v0[1] / v1[1]) * v1[1];
    return result;
}

mint_t *vec2i_snap_i(mint_t *result, const mint_t *v0, mint_t i) {
    result[0] = (v0[0] / i) * i;
    result[1] = (v0[1] / i) * i;
    return result;
}

mint_t *vec2i_negative(mint_t *result, const mint_t *v0) {
    result[0] = -v0[0];
    result[1] = -v0[1];
    return result;
}

mint_t *vec2i_abs(mint_t *result, const mint_t *v0) {
    result[0] = v0[0];
    if (result[0] < 0) {
        result[0] = -result[0];
    }
    result[1] = v0[1];
    if (result[1] < 0) {
        result[1] = -result[1];
    }
    return result;
}

mint_t *vec2i_max(mint_t *result, const mint_t *v0, const mint_t *v1) {
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
    return result;
}

mint_t *vec2i_min(mint_t *result, const mint_t *v0, const mint_t *v1) {
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
    return result;
}

mint_t *vec2i_clamp(mint_t *result, const mint_t *v0, const mint_t *v1, const mint_t *v2) {
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
    return result;
}

mint_t *vec2i_tangent(mint_t *result, const mint_t *v0) {
    mint_t a0 = v0[0];
    mint_t a1 = v0[1];
    result[0] = a1;
    result[1] = -a0;
    return result;
}

#if defined(MATHC_USE_FLOATING_POINT)
mint_t *vec2i_assign_vec2(mint_t *result, const mfloat_t *v0) {
    result[0] = (mint_t)v0[0];
    result[1] = (mint_t)v0[1];
    return result;
}
#endif

#if defined(MATHC_USE_STRUCT_FUNCTIONS)
bool svec2i_is_zero(struct vec2i v0) {
    return vec2i_is_zero((const mint_t *)&v0);
}

bool svec2i_is_equal(struct vec2i v0, struct vec2i v1) {
    return vec2i_is_equal((const mint_t *)&v0, (const mint_t *)&v1);
}

struct vec2i svec2i(mint_t x, mint_t y) {
    struct vec2i result;
    vec2i((mint_t *)&result, x, y);
    return result;
}

struct vec2i svec2i_assign(struct vec2i v0) {
    struct vec2i result;
    vec2i_assign((mint_t *)&result, (const mint_t *)&v0);
    return result;
}

struct vec2i svec2i_reduce_vec3i(struct vec3i v0) {
    struct vec2i result;
    vec2i_reduce_vec3i((mint_t *)&result, (const mint_t *)&v0);
    return result;
}

struct vec2i svec2i_reduce_vec4i(struct vec4i v0) {
    struct vec2i result;
    vec2i_reduce_vec4i((mint_t *)&result, (const mint_t *)&v0);
    return result;
}

struct vec2i svec2i_zero(void) {
    struct vec2i result;
    vec2i_zero((mint_t *)&result);
    return result;
}

struct vec2i svec2i_one(void) {
    struct vec2i result;
    vec2i_one((mint_t *)&result);
    return result;
}

struct vec2i svec2i_sign(struct vec2i v0) {
    struct vec2i result;
    vec2i_sign((mint_t *)&result, (const mint_t *)&v0);
    return result;
}

struct vec2i svec2i_add(struct vec2i v0, struct vec2i v1) {
    struct vec2i result;
    vec2i_add((mint_t *)&result, (const mint_t *)&v0, (const mint_t *)&v1);
    return result;
}

struct vec2i svec2i_add_i(struct vec2i v0, mint_t i) {
    struct vec2i result;
    vec2i_add_i((mint_t *)&result, (const mint_t *)&v0, i);
    return result;
}

struct vec2i svec2i_subtract(struct vec2i v0, struct vec2i v1) {
    struct vec2i result;
    vec2i_subtract((mint_t *)&result, (const mint_t *)&v0, (const mint_t *)&v1);
    return result;
}

struct vec2i svec2i_subtract_i(struct vec2i v0, mint_t i) {
    struct vec2i result;
    vec2i_subtract_i((mint_t *)&result, (const mint_t *)&v0, i);
    return result;
}

struct vec2i svec2i_multiply(struct vec2i v0, struct vec2i v1) {
    struct vec2i result;
    vec2i_multiply((mint_t *)&result, (const mint_t *)&v0, (const mint_t *)&v1);
    return result;
}

struct vec2i svec2i_multiply_i(struct vec2i v0, mint_t i) {
    struct vec2i result;
    vec2i_multiply_i((mint_t *)&result, (const mint_t *)&v0, i);
    return result;
}

struct vec2i svec2i_divide(struct vec2i v0, struct vec2i v1) {
    struct vec2i result;
    vec2i_divide((mint_t *)&result, (const mint_t *)&v0, (const mint_t *)&v1);
    return result;
}

struct vec2i svec2i_divide_i(struct vec2i v0, mint_t i) {
    struct vec2i result;
    vec2i_divide_i((mint_t *)&result, (const mint_t *)&v0, i);
    return result;
}

struct vec2i svec2i_snap(struct vec2i v0, struct vec2i v1) {
    struct vec2i result;
    vec2i_snap((mint_t *)&result, (const mint_t *)&v0, (const mint_t *)&v1);
    return result;
}

struct vec2i svec2i_snap_i(struct vec2i v0, mint_t i) {
    struct vec2i result;
    vec2i_snap_i((mint_t *)&result, (const mint_t *)&v0, i);
    return result;
}

struct vec2i svec2i_negative(struct vec2i v0) {
    struct vec2i result;
    vec2i_negative((mint_t *)&result, (const mint_t *)&v0);
    return result;
}

struct vec2i svec2i_abs(struct vec2i v0) {
    struct vec2i result;
    vec2i_abs((mint_t *)&result, (const mint_t *)&v0);
    return result;
}

struct vec2i svec2i_max(struct vec2i v0, struct vec2i v1) {
    struct vec2i result;
    vec2i_max((mint_t *)&result, (const mint_t *)&v0, (const mint_t *)&v1);
    return result;
}

struct vec2i svec2i_min(struct vec2i v0, struct vec2i v1) {
    struct vec2i result;
    vec2i_min((mint_t *)&result, (const mint_t *)&v0, (const mint_t *)&v1);
    return result;
}

struct vec2i svec2i_clamp(struct vec2i v0, struct vec2i v1, struct vec2i v2) {
    struct vec2i result;
    vec2i_clamp((mint_t *)&result, (const mint_t *)&v0, (const mint_t *)&v1, (const mint_t *)&v2);
    return result;
}

struct vec2i svec2i_tangent(struct vec2i v0) {
    struct vec2i result;
    vec2i_tangent((mint_t *)&result, (const mint_t *)&v0);
    return result;
}

#if defined(MATHC_USE_FLOATING_POINT)
struct vec2i svec2i_assign_vec2(struct vec2 v0) {
    struct vec2i result;
    vec2i_assign_vec2((mint_t *)&result, (const mfloat_t *)&v0);
    return result;
}
#endif
#endif

#if defined(MATHC_USE_POINTER_STRUCT_FUNCTIONS)
bool psvec2i_is_zero(const struct vec2i *v0) {
    return vec2i_is_zero((const mint_t *)v0);
}

bool psvec2i_is_equal(const struct vec2i *v0, const struct vec2i *v1) {
    return vec2i_is_equal((const mint_t *)v0, (const mint_t *)v1);
}

struct vec2i *psvec2i(struct vec2i *result, mint_t x, mint_t y) {
    return (struct vec2i *)vec2i((mint_t *)result, x, y);
}

struct vec2i *psvec2i_assign(struct vec2i *result, const struct vec2i *v0) {
    return (struct vec2i *)vec2i_assign((mint_t *)result, (const mint_t *)v0);
}

struct vec2i *psvec2i_reduce_vec3i(struct vec2i *result, const struct vec3i *v0) {
    return (struct vec2i *)vec2i_reduce_vec3i((mint_t *)result, (const mint_t *)v0);
}

struct vec2i *psvec2i_reduce_vec4i(struct vec2i *result, const struct vec4i *v0) {
    return (struct vec2i *)vec2i_reduce_vec4i((mint_t *)result, (const mint_t *)v0);
}

struct vec2i *psvec2i_zero(struct vec2i *result) {
    return (struct vec2i *)vec2i_zero((mint_t *)result);
}

struct vec2i *psvec2i_one(struct vec2i *result) {
    return (struct vec2i *)vec2i_one((mint_t *)result);
}

struct vec2i *psvec2i_sign(struct vec2i *result, const struct vec2i *v0) {
    return (struct vec2i *)vec2i_sign((mint_t *)result, (const mint_t *)v0);
}

struct vec2i *psvec2i_add(struct vec2i *result, const struct vec2i *v0, const struct vec2i *v1) {
    return (struct vec2i *)vec2i_add((mint_t *)result, (const mint_t *)v0, (const mint_t *)v1);
}

struct vec2i *psvec2i_add_i(struct vec2i *result, const struct vec2i *v0, mint_t i) {
    return (struct vec2i *)vec2i_add_i((mint_t *)result, (const mint_t *)v0, i);
}

struct vec2i *psvec2i_subtract(struct vec2i *result, const struct vec2i *v0, const struct vec2i *v1) {
    return (struct vec2i *)vec2i_subtract((mint_t *)result, (const mint_t *)v0, (const mint_t *)v1);
}

struct vec2i *psvec2i_subtract_i(struct vec2i *result, const struct vec2i *v0, mint_t i) {
    return (struct vec2i *)vec2i_subtract_i((mint_t *)result, (const mint_t *)v0, i);
}

struct vec2i *psvec2i_multiply(struct vec2i *result, const struct vec2i *v0, const struct vec2i *v1) {
    return (struct vec2i *)vec2i_multiply((mint_t *)result, (const mint_t *)v0, (const mint_t *)v1);
}

struct vec2i *psvec2i_multiply_i(struct vec2i *result, const struct vec2i *v0, mint_t i) {
    return (struct vec2i *)vec2i_multiply_i((mint_t *)result, (const mint_t *)v0, i);
}

struct vec2i *psvec2i_divide(struct vec2i *result, const struct vec2i *v0, const struct vec2i *v1) {
    return (struct vec2i *)vec2i_divide((mint_t *)result, (const mint_t *)v0, (const mint_t *)v1);
}

struct vec2i *psvec2i_divide_i(struct vec2i *result, const struct vec2i *v0, mint_t i) {
    return (struct vec2i *)vec2i_divide_i((mint_t *)result, (const mint_t *)v0, i);
}

struct vec2i *psvec2i_snap(struct vec2i *result, const struct vec2i *v0, const struct vec2i *v1) {
    return (struct vec2i *)vec2i_snap((mint_t *)result, (const mint_t *)v0, (const mint_t *)v1);
}

struct vec2i *psvec2i_snap_i(struct vec2i *result, const struct vec2i *v0, mint_t i) {
    return (struct vec2i *)vec2i_snap_i((mint_t *)result, (const mint_t *)v0, i);
}

struct vec2i *psvec2i_negative(struct vec2i *result, const struct vec2i *v0) {
    return (struct vec2i *)vec2i_negative((mint_t *)result, (const mint_t *)v0);
}

struct vec2i *psvec2i_abs(struct vec2i *result, const struct vec2i *v0) {
    return (struct vec2i *)vec2i_abs((mint_t *)result, (const mint_t *)v0);
}

struct vec2i *psvec2i_max(struct vec2i *result, const struct vec2i *v0, const struct vec2i *v1) {
    return (struct vec2i *)vec2i_max((mint_t *)result, (const mint_t *)v0, (const mint_t *)v1);
}

struct vec2i *psvec2i_min(struct vec2i *result, const struct vec2i *v0, const struct vec2i *v1) {
    return (struct vec2i *)vec2i_min((mint_t *)result, (const mint_t *)v0, (const mint_t *)v1);
}

struct vec2i *psvec2i_clamp(struct vec2i *result, const struct vec2i *v0, const struct vec2i *v1, struct vec2i *v2) {
    return (struct vec2i *)vec2i_clamp((mint_t *)result, (const mint_t *)v0, (const mint_t *)v1, (const mint_t *)v2);
}

struct vec2i *psvec2i_tangent(struct vec2i *result, const struct vec2i *v0) {
    return (struct vec2i *)vec2i_tangent((mint_t *)result, (const mint_t *)v0);
}

#if defined(MATHC_USE_FLOATING_POINT)
struct vec2i *psvec2i_assign_vec2(struct vec2i *result, const struct vec2 *v0) {
    return (struct vec2i *)vec2i_assign_vec2((mint_t *)result, (const mfloat_t *)v0);
}
#endif
#endif
#endif