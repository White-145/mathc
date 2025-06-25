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
bool vec3i_is_zero(const mint_t *v0) {
    return v0[0] == 0 && v0[1] == 0 && v0[2] == 0;
}

bool vec3i_is_equal(const mint_t *v0, const mint_t *v1) {
    return v0[0] == v1[0] && v0[1] == v1[1] && v0[2] == v1[2];
}

mint_t *vec3i(mint_t *result, mint_t x, mint_t y, mint_t z) {
    result[0] = x;
    result[1] = y;
    result[2] = z;
    return result;
}

mint_t *vec3i_assign(mint_t *result, const mint_t *v0) {
    result[0] = v0[0];
    result[1] = v0[1];
    result[2] = v0[2];
    return result;
}

mint_t *vec3i_expand_vec2i(mint_t *result, const mint_t *v0, mint_t z) {
    result[0] = v0[0];
    result[1] = v0[1];
    result[2] = z;
    return result;
}

mint_t *vec3i_reduce_vec4i(mint_t *result, const mint_t *v0) {
    result[0] = v0[0];
    result[1] = v0[1];
    result[2] = v0[2];
    return result;
}

mint_t *vec3i_zero(mint_t *result) {
    result[0] = 0;
    result[1] = 0;
    result[2] = 0;
    return result;
}

mint_t *vec3i_one(mint_t *result) {
    result[0] = 1;
    result[1] = 1;
    result[2] = 1;
    return result;
}

mint_t *vec3i_sign(mint_t *result, const mint_t *v0) {
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
    return result;
}

mint_t *vec3i_add(mint_t *result, const mint_t *v0, const mint_t *v1) {
    result[0] = v0[0] + v1[0];
    result[1] = v0[1] + v1[1];
    result[2] = v0[2] + v1[2];
    return result;
}

mint_t *vec3i_add_i(mint_t *result, const mint_t *v0, mint_t i) {
    result[0] = v0[0] + i;
    result[1] = v0[1] + i;
    result[2] = v0[2] + i;
    return result;
}

mint_t *vec3i_subtract(mint_t *result, const mint_t *v0, const mint_t *v1) {
    result[0] = v0[0] - v1[0];
    result[1] = v0[1] - v1[1];
    result[2] = v0[2] - v1[2];
    return result;
}

mint_t *vec3i_subtract_i(mint_t *result, const mint_t *v0, mint_t i) {
    result[0] = v0[0] - i;
    result[1] = v0[1] - i;
    result[2] = v0[2] - i;
    return result;
}

mint_t *vec3i_multiply(mint_t *result, const mint_t *v0, const mint_t *v1) {
    result[0] = v0[0] * v1[0];
    result[1] = v0[1] * v1[1];
    result[2] = v0[2] * v1[2];
    return result;
}

mint_t *vec3i_multiply_i(mint_t *result, const mint_t *v0, mint_t i) {
    result[0] = v0[0] * i;
    result[1] = v0[1] * i;
    result[2] = v0[2] * i;
    return result;
}

mint_t *vec3i_divide(mint_t *result, const mint_t *v0, const mint_t *v1) {
    result[0] = v0[0] / v1[0];
    result[1] = v0[1] / v1[1];
    result[2] = v0[2] / v1[2];
    return result;
}

mint_t *vec3i_divide_i(mint_t *result, const mint_t *v0, mint_t i) {
    result[0] = v0[0] / i;
    result[1] = v0[1] / i;
    result[2] = v0[2] / i;
    return result;
}

mint_t *vec3i_snap(mint_t *result, const mint_t *v0, const mint_t *v1) {
    result[0] = (v0[0] / v1[0]) * v1[0];
    result[1] = (v0[1] / v1[1]) * v1[1];
    result[2] = (v0[2] / v1[2]) * v1[2];
    return result;
}

mint_t *vec3i_snap_i(mint_t *result, const mint_t *v0, mint_t i) {
    result[0] = (v0[0] / i) * i;
    result[1] = (v0[1] / i) * i;
    result[2] = (v0[2] / i) * i;
    return result;
}

mint_t *vec3i_cross(mint_t *result, const mint_t *v0, const mint_t *v1) {
    result[0] = v0[1] * v1[2] - v0[2] * v1[1];
    result[1] = v0[2] * v1[0] - v0[0] * v1[2];
    result[2] = v0[0] * v1[1] - v0[1] * v1[0];
    return result;
}

mint_t *vec3i_negative(mint_t *result, const mint_t *v0) {
    result[0] = -v0[0];
    result[1] = -v0[1];
    result[2] = -v0[2];
    return result;
}

mint_t *vec3i_abs(mint_t *result, const mint_t *v0) {
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
    return result;
}

mint_t *vec3i_max(mint_t *result, const mint_t *v0, const mint_t *v1) {
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
    return result;
}

mint_t *vec3i_min(mint_t *result, const mint_t *v0, const mint_t *v1) {
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
    return result;
}

mint_t *vec3i_clamp(mint_t *result, const mint_t *v0, const mint_t *v1, const mint_t *v2) {
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
    return result;
}

#if defined(MATHC_USE_FLOATING_POINT)
mint_t *vec3i_assign_vec3(mint_t *result, const mfloat_t *v0) {
    result[0] = (mint_t)v0[0];
    result[1] = (mint_t)v0[1];
    result[2] = (mint_t)v0[2];
    return result;
}
#endif

#if defined(MATHC_USE_STRUCT_FUNCTIONS)
bool svec3i_is_zero(struct vec3i v0) {
    return vec3i_is_zero((const mint_t *)&v0);
}

bool svec3i_is_equal(struct vec3i v0, struct vec3i v1) {
    return vec3i_is_equal((const mint_t *)&v0, (const mint_t *)&v1);
}

struct vec3i svec3i(mint_t x, mint_t y, mint_t z) {
    struct vec3i result;
    vec3i((mint_t *)&result, x, y, z);
    return result;
}

struct vec3i svec3i_assign(struct vec3i v0) {
    struct vec3i result;
    vec3i_assign((mint_t *)&result, (const mint_t *)&v0);
    return result;
}

struct vec3i svec3i_expand_vec2i(struct vec2i v0, mint_t z) {
    struct vec3i result;
    vec3i_expand_vec2i((mint_t *)&result, (mint_t *)&v0, z);
    return result;
}

struct vec3i svec3i_reduce_vec4i(struct vec4i v0) {
    struct vec3i result;
    vec3i_reduce_vec4i((mint_t *)&result, (mint_t *)&v0);
    return result;
}

struct vec3i svec3i_zero(void) {
    struct vec3i result;
    vec3i_zero((mint_t *)&result);
    return result;
}

struct vec3i svec3i_one(void) {
    struct vec3i result;
    vec3i_one((mint_t *)&result);
    return result;
}

struct vec3i svec3i_sign(struct vec3i v0) {
    struct vec3i result;
    vec3i_sign((mint_t *)&result, (const mint_t *)&v0);
    return result;
}

struct vec3i svec3i_add(struct vec3i v0, struct vec3i v1) {
    struct vec3i result;
    vec3i_add((mint_t *)&result, (const mint_t *)&v0, (const mint_t *)&v1);
    return result;
}

struct vec3i svec3i_add_i(struct vec3i v0, mint_t i) {
    struct vec3i result;
    vec3i_add_i((mint_t *)&result, (const mint_t *)&v0, i);
    return result;
}

struct vec3i svec3i_subtract(struct vec3i v0, struct vec3i v1) {
    struct vec3i result;
    vec3i_subtract((mint_t *)&result, (const mint_t *)&v0, (const mint_t *)&v1);
    return result;
}

struct vec3i svec3i_subtract_i(struct vec3i v0, mint_t i) {
    struct vec3i result;
    vec3i_subtract_i((mint_t *)&result, (const mint_t *)&v0, i);
    return result;
}

struct vec3i svec3i_multiply(struct vec3i v0, struct vec3i v1) {
    struct vec3i result;
    vec3i_multiply((mint_t *)&result, (const mint_t *)&v0, (const mint_t *)&v1);
    return result;
}

struct vec3i svec3i_multiply_i(struct vec3i v0, mint_t i) {
    struct vec3i result;
    vec3i_multiply_i((mint_t *)&result, (const mint_t *)&v0, i);
    return result;
}

struct vec3i svec3i_divide(struct vec3i v0, struct vec3i v1) {
    struct vec3i result;
    vec3i_divide((mint_t *)&result, (const mint_t *)&v0, (const mint_t *)&v1);
    return result;
}

struct vec3i svec3i_divide_i(struct vec3i v0, mint_t i) {
    struct vec3i result;
    vec3i_divide_i((mint_t *)&result, (const mint_t *)&v0, i);
    return result;
}

struct vec3i svec3i_snap(struct vec3i v0, struct vec3i v1) {
    struct vec3i result;
    vec3i_snap((mint_t *)&result, (const mint_t *)&v0, (const mint_t *)&v1);
    return result;
}

struct vec3i svec3i_snap_i(struct vec3i v0, mint_t i) {
    struct vec3i result;
    vec3i_snap_i((mint_t *)&result, (const mint_t *)&v0, i);
    return result;
}

struct vec3i svec3i_cross(struct vec3i v0, struct vec3i v1) {
    struct vec3i result;
    vec3i_cross((mint_t *)&result, (const mint_t *)&v0, (const mint_t *)&v1);
    return result;
}

struct vec3i svec3i_negative(struct vec3i v0) {
    struct vec3i result;
    vec3i_negative((mint_t *)&result, (const mint_t *)&v0);
    return result;
}

struct vec3i svec3i_abs(struct vec3i v0) {
    struct vec3i result;
    vec3i_abs((mint_t *)&result, (const mint_t *)&v0);
    return result;
}

struct vec3i svec3i_max(struct vec3i v0, struct vec3i v1) {
    struct vec3i result;
    vec3i_max((mint_t *)&result, (const mint_t *)&v0, (const mint_t *)&v1);
    return result;
}

struct vec3i svec3i_min(struct vec3i v0, struct vec3i v1) {
    struct vec3i result;
    vec3i_min((mint_t *)&result, (const mint_t *)&v0, (const mint_t *)&v1);
    return result;
}

struct vec3i svec3i_clamp(struct vec3i v0, struct vec3i v1, struct vec3i v2) {
    struct vec3i result;
    vec3i_clamp((mint_t *)&result, (const mint_t *)&v0, (const mint_t *)&v1, (const mint_t *)&v2);
    return result;
}

#if defined(MATHC_USE_FLOATING_POINT)
struct vec3i svec3i_assign_vec3(struct vec3 v0) {
    struct vec3i result;
    vec3i_assign_vec3((mint_t *)&result, (const mfloat_t *)&v0);
    return result;
}
#endif
#endif

#if defined(MATHC_USE_POINTER_STRUCT_FUNCTIONS)
bool psvec3i_is_zero(const struct vec3i *v0) {
    return vec3i_is_zero((const mint_t *)v0);
}

bool psvec3i_is_equal(const struct vec3i *v0, const struct vec3i *v1) {
    return vec3i_is_equal((const mint_t *)v0, (const mint_t *)v1);
}

struct vec3i *psvec3i(struct vec3i *result, mint_t x, mint_t y, mint_t z) {
    return (struct vec3i *)vec3i((mint_t *)result, x, y, z);
}

struct vec3i *psvec3i_assign(struct vec3i *result, const struct vec3i *v0) {
    return (struct vec3i *)vec3i_assign((mint_t *)result, (const mint_t *)v0);
}

struct vec3i *psvec3i_expand_vec2i(struct vec3i *result, const struct vec2i *v0, mint_t z) {
    return (struct vec3i *)vec3i_expand_vec2i((mint_t *)result, (const mint_t *)v0, z);
}

struct vec3i *psvec3i_reduce_vec4i(struct vec3i *result, const struct vec4i *v0) {
    return (struct vec3i *)vec3i_reduce_vec4i((mint_t *)result, (const mint_t *)v0);
}

struct vec3i *psvec3i_zero(struct vec3i *result) {
    return (struct vec3i *)vec3i_zero((mint_t *)result);
}

struct vec3i *psvec3i_one(struct vec3i *result) {
    return (struct vec3i *)vec3i_one((mint_t *)result);
}

struct vec3i *psvec3i_sign(struct vec3i *result, const struct vec3i *v0) {
    return (struct vec3i *)vec3i_sign((mint_t *)result, (const mint_t *)v0);
}

struct vec3i *psvec3i_add(struct vec3i *result, const struct vec3i *v0, const struct vec3i *v1) {
    return (struct vec3i *)vec3i_add((mint_t *)result, (const mint_t *)v0, (const mint_t *)v1);
}

struct vec3i *psvec3i_add_i(struct vec3i *result, const struct vec3i *v0, mint_t i) {
    return (struct vec3i *)vec3i_add_i((mint_t *)result, (const mint_t *)v0, i);
}

struct vec3i *psvec3i_subtract(struct vec3i *result, const struct vec3i *v0, const struct vec3i *v1) {
    return (struct vec3i *)vec3i_subtract((mint_t *)result, (const mint_t *)v0, (const mint_t *)v1);
}

struct vec3i *psvec3i_subtract_i(struct vec3i *result, const struct vec3i *v0, mint_t i) {
    return (struct vec3i *)vec3i_subtract_i((mint_t *)result, (const mint_t *)v0, i);
}

struct vec3i *psvec3i_multiply(struct vec3i *result, const struct vec3i *v0, const struct vec3i *v1) {
    return (struct vec3i *)vec3i_multiply((mint_t *)result, (const mint_t *)v0, (const mint_t *)v1);
}

struct vec3i *psvec3i_multiply_i(struct vec3i *result, const struct vec3i *v0, mint_t i) {
    return (struct vec3i *)vec3i_multiply_i((mint_t *)result, (const mint_t *)v0, i);
}

struct vec3i *psvec3i_divide(struct vec3i *result, const struct vec3i *v0, const struct vec3i *v1) {
    return (struct vec3i *)vec3i_divide((mint_t *)result, (const mint_t *)v0, (const mint_t *)v1);
}

struct vec3i *psvec3i_divide_i(struct vec3i *result, const struct vec3i *v0, mint_t i) {
    return (struct vec3i *)vec3i_divide_i((mint_t *)result, (const mint_t *)v0, i);
}

struct vec3i *psvec3i_snap(struct vec3i *result, const struct vec3i *v0, const struct vec3i *v1) {
    return (struct vec3i *)vec3i_snap((mint_t *)result, (const mint_t *)v0, (const mint_t *)v1);
}

struct vec3i *psvec3i_snap_i(struct vec3i *result, const struct vec3i *v0, mint_t i) {
    return (struct vec3i *)vec3i_snap_i((mint_t *)result, (const mint_t *)v0, i);
}

struct vec3i *psvec3i_cross(struct vec3i *result, const struct vec3i *v0, const struct vec3i *v1) {
    return (struct vec3i *)vec3i_cross((mint_t *)result, (const mint_t *)v0, (const mint_t *)v1);
}

struct vec3i *psvec3i_negative(struct vec3i *result, const struct vec3i *v0) {
    return (struct vec3i *)vec3i_negative((mint_t *)result, (const mint_t *)v0);
}

struct vec3i *psvec3i_abs(struct vec3i *result, const struct vec3i *v0) {
    return (struct vec3i *)vec3i_abs((mint_t *)result, (const mint_t *)v0);
}

struct vec3i *psvec3i_max(struct vec3i *result, const struct vec3i *v0, const struct vec3i *v1) {
    return (struct vec3i *)vec3i_max((mint_t *)result, (const mint_t *)v0, (const mint_t *)v1);
}

struct vec3i *psvec3i_min(struct vec3i *result, const struct vec3i *v0, const struct vec3i *v1) {
    return (struct vec3i *)vec3i_min((mint_t *)result, (const mint_t *)v0, (const mint_t *)v1);
}

struct vec3i *psvec3i_clamp(struct vec3i *result, const struct vec3i *v0, const struct vec3i *v1, const struct vec3i *v2) {
    return (struct vec3i *)vec3i_clamp((mint_t *)result, (const mint_t *)v0, (const mint_t *)v1, (const mint_t *)v2);
}

#if defined(MATHC_USE_FLOATING_POINT)
struct vec3i *psvec3i_assign_vec3(struct vec3i *result, const struct vec3 *v0) {
    return (struct vec3i *)vec3i_assign_vec3((mint_t *)result, (const mfloat_t *)v0);
}
#endif
#endif
#endif