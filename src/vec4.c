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

#if defined(MATHC_USE_FLOATING_POINT)
bool vec4_is_zero(const mfloat_t *v0) {
    return MFABS(v0[0]) < MFLT_EPSILON && MFABS(v0[1]) < MFLT_EPSILON && MFABS(v0[2]) < MFLT_EPSILON && MFABS(v0[3]) < MFLT_EPSILON;
}

bool vec4_is_equal(const mfloat_t *v0, const mfloat_t *v1) {
    return MFABS(v0[0] - v1[0]) < MFLT_EPSILON && MFABS(v0[1] - v1[1]) < MFLT_EPSILON && MFABS(v0[2] - v1[2]) < MFLT_EPSILON && MFABS(v0[3] - v1[3]) < MFLT_EPSILON;
}

bool vec4_is_collinear(const mfloat_t *v0, const mfloat_t *v1) {
    return MFABS(v0[0] * v1[1] - v0[1] * v1[0]) < MFLT_EPSILON && MFABS(v0[0] * v1[2] - v0[2] * v1[0]) < MFLT_EPSILON && MFABS(v0[0] * v1[3] - v0[3] * v1[0]) < MFLT_EPSILON && MFABS(v0[1] * v1[2] - v0[2] * v1[1]) < MFLT_EPSILON && MFABS(v0[1] * v1[3] - v0[3] * v1[1]) < MFLT_EPSILON && MFABS(v0[2] * v1[3] - v0[3] * v1[2]) < MFLT_EPSILON;
}

mfloat_t *vec4(mfloat_t *result, mfloat_t x, mfloat_t y, mfloat_t z, mfloat_t w) {
    result[0] = x;
    result[1] = y;
    result[2] = z;
    result[3] = w;
    return result;
}

mfloat_t *vec4_assign(mfloat_t *result, const mfloat_t *v0) {
    result[0] = v0[0];
    result[1] = v0[1];
    result[2] = v0[2];
    result[3] = v0[3];
    return result;
}

mfloat_t *vec4_expand_vec2(mfloat_t *result, const mfloat_t *v0, mfloat_t z, mfloat_t w) {
    result[0] = v0[0];
    result[1] = v0[1];
    result[2] = z;
    result[3] = w;
    return result;
}

mfloat_t *vec4_expand_vec3(mfloat_t *result, const mfloat_t *v0, mfloat_t w) {
    result[0] = v0[0];
    result[1] = v0[1];
    result[2] = v0[2];
    result[3] = w;
    return result;
}

mfloat_t *vec4_zero(mfloat_t *result) {
    result[0] = MZERO;
    result[1] = MZERO;
    result[2] = MZERO;
    result[3] = MZERO;
    return result;
}

mfloat_t *vec4_one(mfloat_t *result) {
    result[0] = MONE;
    result[1] = MONE;
    result[2] = MONE;
    result[3] = MONE;
    return result;
}

mfloat_t *vec4_sign(mfloat_t *result, const mfloat_t *v0) {
    if (v0[0] > MZERO) {
        result[0] = MONE;
    } else if (v0[0] < 0) {
        result[0] = -MONE;
    } else {
        result[0] = MZERO;
    }
    if (v0[1] > MZERO) {
        result[1] = MONE;
    } else if (v0[1] < 0) {
        result[1] = -MONE;
    } else {
        result[1] = MZERO;
    }
    if (v0[2] > MZERO) {
        result[2] = MONE;
    } else if (v0[2] < 0) {
        result[2] = -MONE;
    } else {
        result[2] = MZERO;
    }
    if (v0[3] > MZERO) {
        result[3] = MONE;
    } else if (v0[3] < 0) {
        result[3] = -MONE;
    } else {
        result[3] = MZERO;
    }
    return result;
}

mfloat_t *vec4_add(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1) {
    result[0] = v0[0] + v1[0];
    result[1] = v0[1] + v1[1];
    result[2] = v0[2] + v1[2];
    result[3] = v0[3] + v1[3];
    return result;
}

mfloat_t *vec4_add_f(mfloat_t *result, const mfloat_t *v0, mfloat_t f) {
    result[0] = v0[0] + f;
    result[1] = v0[1] + f;
    result[2] = v0[2] + f;
    result[3] = v0[3] + f;
    return result;
}

mfloat_t *vec4_subtract(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1) {
    result[0] = v0[0] - v1[0];
    result[1] = v0[1] - v1[1];
    result[2] = v0[2] - v1[2];
    result[3] = v0[3] - v1[3];
    return result;
}

mfloat_t *vec4_subtract_f(mfloat_t *result, const mfloat_t *v0, mfloat_t f) {
    result[0] = v0[0] - f;
    result[1] = v0[1] - f;
    result[2] = v0[2] - f;
    result[3] = v0[3] - f;
    return result;
}

mfloat_t *vec4_multiply(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1) {
    result[0] = v0[0] * v1[0];
    result[1] = v0[1] * v1[1];
    result[2] = v0[2] * v1[2];
    result[3] = v0[3] * v1[3];
    return result;
}

mfloat_t *vec4_multiply_f(mfloat_t *result, const mfloat_t *v0, mfloat_t f) {
    result[0] = v0[0] * f;
    result[1] = v0[1] * f;
    result[2] = v0[2] * f;
    result[3] = v0[3] * f;
    return result;
}

mfloat_t *vec4_multiply_mat4(mfloat_t *result, const mfloat_t *v0, const mfloat_t *m0) {
    mfloat_t x = v0[0];
    mfloat_t y = v0[1];
    mfloat_t z = v0[2];
    mfloat_t w = v0[3];
    result[0] = m0[0] * x + m0[4] * y + m0[8] * z + m0[12] * w;
    result[1] = m0[1] * x + m0[5] * y + m0[9] * z + m0[13] * w;
    result[2] = m0[2] * x + m0[6] * y + m0[10] * z + m0[14] * w;
    result[3] = m0[3] * x + m0[7] * y + m0[11] * z + m0[15] * w;
    return result;
}

mfloat_t *vec4_divide(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1) {
    result[0] = v0[0] / v1[0];
    result[1] = v0[1] / v1[1];
    result[2] = v0[2] / v1[2];
    result[3] = v0[3] / v1[3];
    return result;
}

mfloat_t *vec4_divide_f(mfloat_t *result, const mfloat_t *v0, mfloat_t f) {
    result[0] = v0[0] / f;
    result[1] = v0[1] / f;
    result[2] = v0[2] / f;
    result[3] = v0[3] / f;
    return result;
}

mfloat_t *vec4_snap(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1) {
    result[0] = MFLOOR(v0[0] / v1[0]) * v1[0];
    result[1] = MFLOOR(v0[1] / v1[1]) * v1[1];
    result[2] = MFLOOR(v0[2] / v1[2]) * v1[2];
    result[3] = MFLOOR(v0[3] / v1[3]) * v1[3];
    return result;
}

mfloat_t *vec4_snap_f(mfloat_t *result, const mfloat_t *v0, mfloat_t f) {
    result[0] = MFLOOR(v0[0] / f) * f;
    result[1] = MFLOOR(v0[1] / f) * f;
    result[2] = MFLOOR(v0[2] / f) * f;
    result[3] = MFLOOR(v0[3] / f) * f;
    return result;
}

mfloat_t *vec4_negative(mfloat_t *result, const mfloat_t *v0) {
    result[0] = -v0[0];
    result[1] = -v0[1];
    result[2] = -v0[2];
    result[3] = -v0[3];
    return result;
}

mfloat_t *vec4_abs(mfloat_t *result, const mfloat_t *v0) {
    result[0] = MFABS(v0[0]);
    result[1] = MFABS(v0[1]);
    result[2] = MFABS(v0[2]);
    result[3] = MFABS(v0[3]);
    return result;
}

mfloat_t *vec4_floor(mfloat_t *result, const mfloat_t *v0) {
    result[0] = MFLOOR(v0[0]);
    result[1] = MFLOOR(v0[1]);
    result[2] = MFLOOR(v0[2]);
    result[3] = MFLOOR(v0[3]);
    return result;
}

mfloat_t *vec4_ceil(mfloat_t *result, const mfloat_t *v0) {
    result[0] = MCEIL(v0[0]);
    result[1] = MCEIL(v0[1]);
    result[2] = MCEIL(v0[2]);
    result[3] = MCEIL(v0[3]);
    return result;
}

mfloat_t *vec4_round(mfloat_t *result, const mfloat_t *v0) {
    result[0] = MROUND(v0[0]);
    result[1] = MROUND(v0[1]);
    result[2] = MROUND(v0[2]);
    result[3] = MROUND(v0[3]);
    return result;
}

mfloat_t *vec4_max(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1) {
    result[0] = MFMAX(v0[0], v1[0]);
    result[1] = MFMAX(v0[1], v1[1]);
    result[2] = MFMAX(v0[2], v1[2]);
    result[3] = MFMAX(v0[3], v1[3]);
    return result;
}

mfloat_t *vec4_min(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1) {
    result[0] = MFMIN(v0[0], v1[0]);
    result[1] = MFMIN(v0[1], v1[1]);
    result[2] = MFMIN(v0[2], v1[2]);
    result[3] = MFMIN(v0[3], v1[3]);
    return result;
}

mfloat_t *vec4_clamp(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1, const mfloat_t *v2) {
    result[0] = MFMIN(MFMAX(v0[0], v1[0]), v2[0]);
    result[1] = MFMIN(MFMAX(v0[1], v1[1]), v2[1]);
    result[2] = MFMIN(MFMAX(v0[2], v1[2]), v2[2]);
    result[3] = MFMIN(MFMAX(v0[3], v1[3]), v2[3]);
    return result;
}

mfloat_t *vec4_normalize(mfloat_t *result, const mfloat_t *v0) {
    mfloat_t l = MSQRT(v0[0] * v0[0] + v0[1] * v0[1] + v0[2] * v0[2] + v0[3] * v0[3]);
    result[0] = v0[0] / l;
    result[1] = v0[1] / l;
    result[2] = v0[2] / l;
    result[3] = v0[3] / l;
    return result;
}

mfloat_t vec4_dot(const mfloat_t *v0, const mfloat_t *v1) {
    return v0[0] * v1[0] + v0[1] * v1[1] + v0[2] * v1[2] + v0[3] * v1[3];
}

mfloat_t *vec4_lerp(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1, mfloat_t f) {
    result[0] = v0[0] + (v1[0] - v0[0]) * f;
    result[1] = v0[1] + (v1[1] - v0[1]) * f;
    result[2] = v0[2] + (v1[2] - v0[2]) * f;
    result[3] = v0[3] + (v1[3] - v0[3]) * f;
    return result;
}

#if defined(MATHC_USE_INT)
mfloat_t *vec4_assign_vec4i(mfloat_t *result, const mint_t *v0) {
    result[0] = (mfloat_t)v0[0];
    result[1] = (mfloat_t)v0[1];
    result[2] = (mfloat_t)v0[2];
    result[3] = (mfloat_t)v0[3];
    return result;
}
#endif

#if defined(MATHC_USE_STRUCT_FUNCTIONS)
bool svec4_is_zero(struct vec4 v0) {
    return vec4_is_zero((const mfloat_t *)&v0);
}

bool svec4_is_equal(struct vec4 v0, struct vec4 v1) {
    return vec4_is_equal((const mfloat_t *)&v0, (const mfloat_t *)&v1);
}

bool svec4_is_collinear(struct vec4 v0, struct vec4 v1) {
    return vec4_is_collinear((const mfloat_t *)&v0, (const mfloat_t *)&v1);
}

struct vec4 svec4(mfloat_t x, mfloat_t y, mfloat_t z, mfloat_t w) {
    struct vec4 result;
    vec4((mfloat_t *)&result, x, y, z, w);
    return result;
}

struct vec4 svec4_assign(struct vec4 v0) {
    struct vec4 result;
    vec4_assign((mfloat_t *)&result, (const mfloat_t *)&v0);
    return result;
}

struct vec4 svec4_expand_vec2(struct vec2 v0, mfloat_t z, mfloat_t w) {
    struct vec4 result;
    vec4_expand_vec2((mfloat_t *)&result, (const mfloat_t *)&v0, z, w);
    return result;
}

struct vec4 svec4_expand_vec3(struct vec3 v0, mfloat_t w) {
    struct vec4 result;
    vec4_expand_vec3((mfloat_t *)&result, (const mfloat_t *)&v0, w);
    return result;
}

struct vec4 svec4_zero(void) {
    struct vec4 result;
    vec4_zero((mfloat_t *)&result);
    return result;
}

struct vec4 svec4_one(void) {
    struct vec4 result;
    vec4_one((mfloat_t *)&result);
    return result;
}

struct vec4 svec4_sign(struct vec4 v0) {
    struct vec4 result;
    vec4_sign((mfloat_t *)&result, (const mfloat_t *)&v0);
    return result;
}

struct vec4 svec4_add(struct vec4 v0, struct vec4 v1) {
    struct vec4 result;
    vec4_add((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1);
    return result;
}

struct vec4 svec4_add_f(struct vec4 v0, mfloat_t f) {
    struct vec4 result;
    vec4_add_f((mfloat_t *)&result, (const mfloat_t *)&v0, f);
    return result;
}

struct vec4 svec4_subtract(struct vec4 v0, struct vec4 v1) {
    struct vec4 result;
    vec4_subtract((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1);
    return result;
}

struct vec4 svec4_subtract_f(struct vec4 v0, mfloat_t f) {
    struct vec4 result;
    vec4_subtract_f((mfloat_t *)&result, (const mfloat_t *)&v0, f);
    return result;
}

struct vec4 svec4_multiply(struct vec4 v0, struct vec4 v1) {
    struct vec4 result;
    vec4_multiply((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1);
    return result;
}

struct vec4 svec4_multiply_f(struct vec4 v0, mfloat_t f) {
    struct vec4 result;
    vec4_multiply_f((mfloat_t *)&result, (const mfloat_t *)&v0, f);
    return result;
}

struct vec4 svec4_multiply_mat4(struct vec4 v0, struct mat4 m0) {
    struct vec4 result;
    vec4_multiply_mat4((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&m0);
    return result;
}

struct vec4 svec4_divide(struct vec4 v0, struct vec4 v1) {
    struct vec4 result;
    vec4_divide((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1);
    return result;
}

struct vec4 svec4_divide_f(struct vec4 v0, mfloat_t f) {
    struct vec4 result;
    vec4_divide_f((mfloat_t *)&result, (const mfloat_t *)&v0, f);
    return result;
}

struct vec4 svec4_snap(struct vec4 v0, struct vec4 v1) {
    struct vec4 result;
    vec4_snap((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1);
    return result;
}

struct vec4 svec4_snap_f(struct vec4 v0, mfloat_t f) {
    struct vec4 result;
    vec4_snap_f((mfloat_t *)&result, (const mfloat_t *)&v0, f);
    return result;
}

struct vec4 svec4_negative(struct vec4 v0) {
    struct vec4 result;
    vec4_negative((mfloat_t *)&result, (const mfloat_t *)&v0);
    return result;
}

struct vec4 svec4_abs(struct vec4 v0) {
    struct vec4 result;
    vec4_abs((mfloat_t *)&result, (const mfloat_t *)&v0);
    return result;
}

struct vec4 svec4_floor(struct vec4 v0) {
    struct vec4 result;
    vec4_floor((mfloat_t *)&result, (const mfloat_t *)&v0);
    return result;
}

struct vec4 svec4_ceil(struct vec4 v0) {
    struct vec4 result;
    vec4_ceil((mfloat_t *)&result, (const mfloat_t *)&v0);
    return result;
}

struct vec4 svec4_round(struct vec4 v0) {
    struct vec4 result;
    vec4_round((mfloat_t *)&result, (const mfloat_t *)&v0);
    return result;
}

struct vec4 svec4_max(struct vec4 v0, struct vec4 v1) {
    struct vec4 result;
    vec4_max((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1);
    return result;
}

struct vec4 svec4_min(struct vec4 v0, struct vec4 v1) {
    struct vec4 result;
    vec4_min((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1);
    return result;
}

struct vec4 svec4_clamp(struct vec4 v0, struct vec4 v1, struct vec4 v2) {
    struct vec4 result;
    vec4_clamp((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1, (const mfloat_t *)&v2);
    return result;
}

struct vec4 svec4_normalize(struct vec4 v0) {
    struct vec4 result;
    vec4_normalize((mfloat_t *)&result, (const mfloat_t *)&v0);
    return result;
}

mfloat_t svec4_dot(struct vec4 v0, struct vec4 v1) {
    return vec4_dot((const mfloat_t *)&v0, (const mfloat_t *)&v1);
}

struct vec4 svec4_lerp(struct vec4 v0, struct vec4 v1, mfloat_t f) {
    struct vec4 result;
    vec4_lerp((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1, f);
    return result;
}

#if defined(MATHC_USE_INT)
struct vec4 svec4_assign_vec4i(struct vec4i v0) {
    struct vec4 result;
    vec4_assign_vec4i((mfloat_t *)&result, (const mint_t *)&v0);
    return result;
}
#endif
#endif

#if defined(MATHC_USE_POINTER_STRUCT_FUNCTIONS)
bool psvec4_is_zero(struct vec4 *v0) {
    return vec4_is_zero((const mfloat_t *)v0);
}

bool psvec4_is_equal(struct vec4 *v0, struct vec4 *v1) {
    return vec4_is_equal((const mfloat_t *)v0, (const mfloat_t *)v1);
}

bool psvec4_is_collinear(struct vec4 *v0, struct vec4 *v1) {
    return vec4_is_collinear((const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec4 *psvec4(struct vec4 *result, mfloat_t x, mfloat_t y, mfloat_t z, mfloat_t w) {
    return (struct vec4 *)vec4((mfloat_t *)result, x, y, z, w);
}

struct vec4 *psvec4_assign(struct vec4 *result, struct vec4 *v0) {
    return (struct vec4 *)vec4_assign((mfloat_t *)result, (const mfloat_t *)v0);
}

struct vec4 *psvec4_expand_vec2(struct vec4 *result, struct vec2 *v0, mfloat_t z, mfloat_t w) {
    return (struct vec4 *)vec4_expand_vec2((mfloat_t *)result, (const mfloat_t *)v0, z, w);
}

struct vec4 *psvec4_expand_vec3(struct vec4 *result, struct vec3 *v0, mfloat_t w) {
    return (struct vec4 *)vec4_expand_vec3((mfloat_t *)result, (const mfloat_t *)v0, w);
}

struct vec4 *psvec4_zero(struct vec4 *result) {
    return (struct vec4 *)vec4_zero((mfloat_t *)result);
}

struct vec4 *psvec4_one(struct vec4 *result) {
    return (struct vec4 *)vec4_one((mfloat_t *)result);
}

struct vec4 *psvec4_sign(struct vec4 *result, struct vec4 *v0) {
    return (struct vec4 *)vec4_sign((mfloat_t *)result, (const mfloat_t *)v0);
}

struct vec4 *psvec4_add(struct vec4 *result, struct vec4 *v0, struct vec4 *v1) {
    return (struct vec4 *)vec4_add((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec4 *psvec4_add_f(struct vec4 *result, struct vec4 *v0, mfloat_t f) {
    return (struct vec4 *)vec4_add_f((mfloat_t *)result, (const mfloat_t *)v0, f);
}

struct vec4 *psvec4_subtract(struct vec4 *result, struct vec4 *v0, struct vec4 *v1) {
    return (struct vec4 *)vec4_subtract((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec4 *psvec4_subtract_f(struct vec4 *result, struct vec4 *v0, mfloat_t f) {
    return (struct vec4 *)vec4_subtract_f((mfloat_t *)result, (const mfloat_t *)v0, f);
}

struct vec4 *psvec4_multiply(struct vec4 *result, struct vec4 *v0, struct vec4 *v1) {
    return (struct vec4 *)vec4_multiply((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec4 *psvec4_multiply_f(struct vec4 *result, struct vec4 *v0, mfloat_t f) {
    return (struct vec4 *)vec4_multiply_f((mfloat_t *)result, (const mfloat_t *)v0, f);
}

struct vec4 *psvec4_multiply_mat4(struct vec4 *result, struct vec4 *v0, const struct mat4 *m0) {
    return (struct vec4 *)vec4_multiply_mat4((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)m0);
}

struct vec4 *psvec4_divide(struct vec4 *result, struct vec4 *v0, struct vec4 *v1) {
    return (struct vec4 *)vec4_divide((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec4 *psvec4_divide_f(struct vec4 *result, struct vec4 *v0, mfloat_t f) {
    return (struct vec4 *)vec4_divide_f((mfloat_t *)result, (const mfloat_t *)v0, f);
}

struct vec4 *psvec4_snap(struct vec4 *result, struct vec4 *v0, struct vec4 *v1) {
    return (struct vec4 *)vec4_snap((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec4 *psvec4_snap_f(struct vec4 *result, struct vec4 *v0, mfloat_t f) {
    return (struct vec4 *)vec4_snap_f((mfloat_t *)result, (const mfloat_t *)v0, f);
}

struct vec4 *psvec4_negative(struct vec4 *result, struct vec4 *v0) {
    return (struct vec4 *)vec4_negative((mfloat_t *)result, (const mfloat_t *)v0);
}

struct vec4 *psvec4_abs(struct vec4 *result, struct vec4 *v0) {
    return (struct vec4 *)vec4_abs((mfloat_t *)result, (const mfloat_t *)v0);
}

struct vec4 *psvec4_floor(struct vec4 *result, struct vec4 *v0) {
    return (struct vec4 *)vec4_floor((mfloat_t *)result, (const mfloat_t *)v0);
}

struct vec4 *psvec4_ceil(struct vec4 *result, struct vec4 *v0) {
    return (struct vec4 *)vec4_ceil((mfloat_t *)result, (const mfloat_t *)v0);
}

struct vec4 *psvec4_round(struct vec4 *result, struct vec4 *v0) {
    return (struct vec4 *)vec4_round((mfloat_t *)result, (const mfloat_t *)v0);
}

struct vec4 *psvec4_max(struct vec4 *result, struct vec4 *v0, struct vec4 *v1) {
    return (struct vec4 *)vec4_max((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec4 *psvec4_min(struct vec4 *result, struct vec4 *v0, struct vec4 *v1) {
    return (struct vec4 *)vec4_min((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec4 *psvec4_clamp(struct vec4 *result, struct vec4 *v0, struct vec4 *v1, struct vec4 *v2) {
    return (struct vec4 *)vec4_clamp((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1, (const mfloat_t *)v2);
}

struct vec4 *psvec4_normalize(struct vec4 *result, struct vec4 *v0) {
    return (struct vec4 *)vec4_normalize((mfloat_t *)result, (const mfloat_t *)v0);
}

mfloat_t psvec4_dot(struct vec4 *v0, struct vec4 *v1) {
    return vec4_dot((const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec4 *psvec4_lerp(struct vec4 *result, struct vec4 *v0, struct vec4 *v1, mfloat_t f) {
    return (struct vec4 *)vec4_lerp((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1, f);
}

#if defined(MATHC_USE_INT)
struct vec4 *psvec4_assign_vec4i(struct vec4 *result, struct vec4i *v0) {
    return (struct vec4 *)vec4_assign_vec4i((mfloat_t *)result, (const mint_t *)v0);
}
#endif
#endif
#endif