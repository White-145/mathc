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
bool vec2_is_zero(const mfloat_t *v0) {
    return MFABS(v0[0]) < MFLT_EPSILON && MFABS(v0[1]) < MFLT_EPSILON;
}

bool vec2_is_equal(const mfloat_t *v0, const mfloat_t *v1) {
    return MFABS(v0[0] - v1[0]) < MFLT_EPSILON && MFABS(v0[1] - v1[1]) < MFLT_EPSILON;
}

mfloat_t *vec2(mfloat_t *result, mfloat_t x, mfloat_t y) {
    result[0] = x;
    result[1] = y;
    return result;
}

mfloat_t *vec2_assign(mfloat_t *result, const mfloat_t *v0) {
    result[0] = v0[0];
    result[1] = v0[1];
    return result;
}

mfloat_t *vec2_zero(mfloat_t *result) {
    result[0] = MZERO;
    result[1] = MZERO;
    return result;
}

mfloat_t *vec2_one(mfloat_t *result) {
    result[0] = MONE;
    result[1] = MONE;
    return result;
}

mfloat_t *vec2_sign(mfloat_t *result, const mfloat_t *v0) {
    if (v0[0] > MZERO) {
        result[0] = MONE;
    } else if (v0[0] < MZERO) {
        result[0] = -MONE;
    } else {
        result[0] = MZERO;
    }
    if (v0[1] > MZERO) {
        result[1] = MONE;
    } else if (v0[1] < MZERO) {
        result[1] = -MONE;
    } else {
        result[1] = MZERO;
    }
    return result;
}

mfloat_t *vec2_add(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1) {
    result[0] = v0[0] + v1[0];
    result[1] = v0[1] + v1[1];
    return result;
}

mfloat_t *vec2_add_f(mfloat_t *result, const mfloat_t *v0, mfloat_t f) {
    result[0] = v0[0] + f;
    result[1] = v0[1] + f;
    return result;
}

mfloat_t *vec2_subtract(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1) {
    result[0] = v0[0] - v1[0];
    result[1] = v0[1] - v1[1];
    return result;
}

mfloat_t *vec2_subtract_f(mfloat_t *result, const mfloat_t *v0, mfloat_t f) {
    result[0] = v0[0] - f;
    result[1] = v0[1] - f;
    return result;
}

mfloat_t *vec2_multiply(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1) {
    result[0] = v0[0] * v1[0];
    result[1] = v0[1] * v1[1];
    return result;
}

mfloat_t *vec2_multiply_f(mfloat_t *result, const mfloat_t *v0, mfloat_t f) {
    result[0] = v0[0] * f;
    result[1] = v0[1] * f;
    return result;
}

mfloat_t *vec2_multiply_mat2(mfloat_t *result, const mfloat_t *v0, const mfloat_t *m0) {
    mfloat_t x = v0[0];
    mfloat_t y = v0[1];
    result[0] = m0[0] * x + m0[2] * y;
    result[1] = m0[1] * x + m0[3] * y;
    return result;
}

mfloat_t *vec2_divide(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1) {
    result[0] = v0[0] / v1[0];
    result[1] = v0[1] / v1[1];
    return result;
}

mfloat_t *vec2_divide_f(mfloat_t *result, const mfloat_t *v0, mfloat_t f) {
    result[0] = v0[0] / f;
    result[1] = v0[1] / f;
    return result;
}

mfloat_t *vec2_snap(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1) {
    result[0] = MFLOOR(v0[0] / v1[0]) * v1[0];
    result[1] = MFLOOR(v0[1] / v1[1]) * v1[1];
    return result;
}

mfloat_t *vec2_snap_f(mfloat_t *result, const mfloat_t *v0, mfloat_t f) {
    result[0] = MFLOOR(v0[0] / f) * f;
    result[1] = MFLOOR(v0[1] / f) * f;
    return result;
}

mfloat_t *vec2_negative(mfloat_t *result, const mfloat_t *v0) {
    result[0] = -v0[0];
    result[1] = -v0[1];
    return result;
}

mfloat_t *vec2_abs(mfloat_t *result, const mfloat_t *v0) {
    result[0] = MFABS(v0[0]);
    result[1] = MFABS(v0[1]);
    return result;
}

mfloat_t *vec2_floor(mfloat_t *result, const mfloat_t *v0) {
    result[0] = MFLOOR(v0[0]);
    result[1] = MFLOOR(v0[1]);
    return result;
}

mfloat_t *vec2_ceil(mfloat_t *result, const mfloat_t *v0) {
    result[0] = MCEIL(v0[0]);
    result[1] = MCEIL(v0[1]);
    return result;
}

mfloat_t *vec2_round(mfloat_t *result, const mfloat_t *v0) {
    result[0] = MROUND(v0[0]);
    result[1] = MROUND(v0[1]);
    return result;
}

mfloat_t *vec2_max(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1) {
    result[0] = MFMAX(v0[0], v1[0]);
    result[1] = MFMAX(v0[1], v1[1]);
    return result;
}

mfloat_t *vec2_min(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1) {
    result[0] = MFMIN(v0[0], v1[0]);
    result[1] = MFMIN(v0[1], v1[1]);
    return result;
}

mfloat_t *vec2_clamp(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1, const mfloat_t *v2) {
    result[0] = MFMIN(MFMAX(v0[0], v1[0]), v2[0]);
    result[1] = MFMIN(MFMAX(v0[1], v1[1]), v2[1]);
    return result;
}

mfloat_t *vec2_normalize(mfloat_t *result, const mfloat_t *v0) {
    mfloat_t l = MSQRT(v0[0] * v0[0] + v0[1] * v0[1]);
    result[0] = v0[0] / l;
    result[1] = v0[1] / l;
    return result;
}

mfloat_t vec2_dot(const mfloat_t *v0, const mfloat_t *v1) {
    return v0[0] * v1[0] + v0[1] * v1[1];
}

mfloat_t *vec2_project(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1) {
    mfloat_t d = vec2_dot(v1, v1);
    mfloat_t s = vec2_dot(v0, v1) / d;
    result[0] = v1[0] * s;
    result[1] = v1[1] * s;
    return result;
}

mfloat_t *vec2_slide(mfloat_t *result, const mfloat_t *v0, const mfloat_t *normal) {
    mfloat_t d = vec2_dot(v0, normal);
    result[0] = v0[0] - normal[0] * d;
    result[1] = v0[1] - normal[1] * d;
    return result;
}

mfloat_t *vec2_reflect(mfloat_t *result, const mfloat_t *v0, const mfloat_t *normal) {
    mfloat_t d = MTWO * vec2_dot(v0, normal);
    result[0] = normal[0] * d - v0[0];
    result[1] = normal[1] * d - v0[1];
    return result;
}

mfloat_t *vec2_tangent(mfloat_t *result, const mfloat_t *v0) {
    mfloat_t a0 = v0[0];
    mfloat_t a1 = v0[1];
    result[0] = a1;
    result[1] = -a0;
    return result;
}

mfloat_t *vec2_rotate(mfloat_t *result, const mfloat_t *v0, mfloat_t f) {
    mfloat_t cs = MCOS(f);
    mfloat_t sn = MSIN(f);
    mfloat_t x = v0[0];
    mfloat_t y = v0[1];
    result[0] = x * cs - y * sn;
    result[1] = x * sn + y * cs;
    return result;
}

mfloat_t *vec2_lerp(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1, mfloat_t f) {
    result[0] = v0[0] + (v1[0] - v0[0]) * f;
    result[1] = v0[1] + (v1[1] - v0[1]) * f;
    return result;
}

mfloat_t *vec2_bezier3(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1, const mfloat_t *v2, mfloat_t f) {
    mfloat_t tmp0[VEC2_SIZE];
    mfloat_t tmp1[VEC2_SIZE];
    vec2_lerp(tmp0, v0, v1, f);
    vec2_lerp(tmp1, v1, v2, f);
    vec2_lerp(result, tmp0, tmp1, f);
    return result;
}

mfloat_t *vec2_bezier4(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1, const mfloat_t *v2, const mfloat_t *v3, mfloat_t f) {
    mfloat_t tmp0[VEC2_SIZE];
    mfloat_t tmp1[VEC2_SIZE];
    mfloat_t tmp2[VEC2_SIZE];
    mfloat_t tmp3[VEC2_SIZE];
    mfloat_t tmp4[VEC2_SIZE];
    vec2_lerp(tmp0, v0, v1, f);
    vec2_lerp(tmp1, v1, v2, f);
    vec2_lerp(tmp2, v2, v3, f);
    vec2_lerp(tmp3, tmp0, tmp1, f);
    vec2_lerp(tmp4, tmp1, tmp2, f);
    vec2_lerp(result, tmp3, tmp4, f);
    return result;
}

mfloat_t vec2_angle(const mfloat_t *v0) {
    return MATAN2(v0[1], v0[0]);
}

mfloat_t vec2_length(const mfloat_t *v0) {
    return MSQRT(v0[0] * v0[0] + v0[1] * v0[1]);
}

mfloat_t vec2_length_squared(const mfloat_t *v0) {
    return v0[0] * v0[0] + v0[1] * v0[1];
}

mfloat_t vec2_distance(const mfloat_t *v0, const mfloat_t *v1) {
    return MSQRT((v0[0] - v1[0]) * (v0[0] - v1[0]) + (v0[1] - v1[1]) * (v0[1] - v1[1]));
}

mfloat_t vec2_distance_squared(const mfloat_t *v0, const mfloat_t *v1) {
    return (v0[0] - v1[0]) * (v0[0] - v1[0]) + (v0[1] - v1[1]) * (v0[1] - v1[1]);
}

bool vec2_linear_independent(const mfloat_t *v0, const mfloat_t *v1) {
    return (v0[0] * v1[1] - v1[0] * v0[1]) != 0;
}

mfloat_t **vec2_orthonormalization(mfloat_t result[2][2], mfloat_t basis[2][2]) {
    mfloat_t v0[2];
    mfloat_t v1[2];

    for(int32_t i = 0; i < 2; ++i) {
        v0[i] = basis[0][i];
        v1[i] = basis[1][i];
    }

    if (!vec2_linear_independent(v0, v1)) {
        return (mfloat_t **)result;
    }

    mfloat_t proju1[2];
    mfloat_t u0[2];
    mfloat_t u1[2];

    for(int32_t i = 0; i < 2; ++i) {
        u0[i] = v0[i];
    }

    vec2_project(proju1, v1, v0);
    vec2_subtract(u1, v1, proju1);
    vec2_normalize(result[0], u0);
    vec2_normalize(result[1], u1);

    return (mfloat_t **)result;
}

#if defined(MATHC_USE_INT)
mfloat_t *vec2_assign_vec2i(mfloat_t *result, const mint_t *v0) {
    result[0] = v0[0];
    result[1] = v0[1];
    return result;
}
#endif

#if defined(MATHC_USE_STRUCT_FUNCTIONS)
bool svec2_is_zero(struct vec2 v0) {
    return vec2_is_zero((const mfloat_t *)&v0);
}

bool svec2_is_equal(struct vec2 v0, struct vec2 v1) {
    return vec2_is_equal((const mfloat_t *)&v0, (const mfloat_t *)&v1);
}

struct vec2 svec2(mfloat_t x, mfloat_t y) {
    struct vec2 result;
    vec2((mfloat_t *)&result, x, y);
    return result;
}

struct vec2 svec2_assign(struct vec2 v0) {
    struct vec2 result;
    vec2_assign((mfloat_t *)&result, (const mfloat_t *)&v0);
    return result;
}

struct vec2 svec2_zero(void) {
    struct vec2 result;
    vec2_zero((mfloat_t *)&result);
    return result;
}

struct vec2 svec2_one(void) {
    struct vec2 result;
    vec2_one((mfloat_t *)&result);
    return result;
}

struct vec2 svec2_sign(struct vec2 v0) {
    struct vec2 result;
    vec2_sign((mfloat_t *)&result, (const mfloat_t *)&v0);
    return result;
}

struct vec2 svec2_add(struct vec2 v0, struct vec2 v1) {
    struct vec2 result;
    vec2_add((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1);
    return result;
}

struct vec2 svec2_add_f(struct vec2 v0, mfloat_t f) {
    struct vec2 result;
    vec2_add_f((mfloat_t *)&result, (const mfloat_t *)&v0, f);
    return result;
}

struct vec2 svec2_subtract(struct vec2 v0, struct vec2 v1) {
    struct vec2 result;
    vec2_subtract((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1);
    return result;
}

struct vec2 svec2_subtract_f(struct vec2 v0, mfloat_t f) {
    struct vec2 result;
    vec2_subtract_f((mfloat_t *)&result, (const mfloat_t *)&v0, f);
    return result;
}

struct vec2 svec2_multiply(struct vec2 v0, struct vec2 v1) {
    struct vec2 result;
    vec2_multiply((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1);
    return result;
}

struct vec2 svec2_multiply_f(struct vec2 v0, mfloat_t f) {
    struct vec2 result;
    vec2_multiply_f((mfloat_t *)&result, (const mfloat_t *)&v0, f);
    return result;
}

struct vec2 svec2_multiply_mat2(struct vec2 v0, struct mat2 m0) {
    struct vec2 result;
    vec2_multiply_mat2((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&m0);
    return result;
}

struct vec2 svec2_divide(struct vec2 v0, struct vec2 v1) {
    struct vec2 result;
    vec2_divide((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1);
    return result;
}

struct vec2 svec2_divide_f(struct vec2 v0, mfloat_t f) {
    struct vec2 result;
    vec2_divide_f((mfloat_t *)&result, (const mfloat_t *)&v0, f);
    return result;
}

struct vec2 svec2_snap(struct vec2 v0, struct vec2 v1) {
    struct vec2 result;
    vec2_snap((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1);
    return result;
}

struct vec2 svec2_snap_f(struct vec2 v0, mfloat_t f) {
    struct vec2 result;
    vec2_snap_f((mfloat_t *)&result, (const mfloat_t *)&v0, f);
    return result;
}

struct vec2 svec2_negative(struct vec2 v0) {
    struct vec2 result;
    vec2_negative((mfloat_t *)&result, (const mfloat_t *)&v0);
    return result;
}

struct vec2 svec2_abs(struct vec2 v0) {
    struct vec2 result;
    vec2_abs((mfloat_t *)&result, (const mfloat_t *)&v0);
    return result;
}

struct vec2 svec2_floor(struct vec2 v0) {
    struct vec2 result;
    vec2_floor((mfloat_t *)&result, (const mfloat_t *)&v0);
    return result;
}

struct vec2 svec2_ceil(struct vec2 v0) {
    struct vec2 result;
    vec2_ceil((mfloat_t *)&result, (const mfloat_t *)&v0);
    return result;
}

struct vec2 svec2_round(struct vec2 v0) {
    struct vec2 result;
    vec2_round((mfloat_t *)&result, (const mfloat_t *)&v0);
    return result;
}

struct vec2 svec2_max(struct vec2 v0, struct vec2 v1) {
    struct vec2 result;
    vec2_max((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1);
    return result;
}

struct vec2 svec2_min(struct vec2 v0, struct vec2 v1) {
    struct vec2 result;
    vec2_min((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1);
    return result;
}

struct vec2 svec2_clamp(struct vec2 v0, struct vec2 v1, struct vec2 v2) {
    struct vec2 result;
    vec2_clamp((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1, (const mfloat_t *)&v2);
    return result;
}

struct vec2 svec2_normalize(struct vec2 v0) {
    struct vec2 result;
    vec2_normalize((mfloat_t *)&result, (const mfloat_t *)&v0);
    return result;
}

mfloat_t svec2_dot(struct vec2 v0, struct vec2 v1) {
    return vec2_dot((const mfloat_t *)&v0, (const mfloat_t *)&v1);
}

struct vec2 svec2_project(struct vec2 v0, struct vec2 v1) {
    struct vec2 result;
    vec2_project((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1);
    return result;
}

struct vec2 svec2_slide(struct vec2 v0, struct vec2 normal) {
    struct vec2 result;
    vec2_slide((mfloat_t *)&result, (const mfloat_t *)&v0, (mfloat_t *)&normal);
    return result;
}

struct vec2 svec2_reflect(struct vec2 v0, struct vec2 normal) {
    struct vec2 result;
    vec2_reflect((mfloat_t *)&result, (const mfloat_t *)&v0, (mfloat_t *)&normal);
    return result;
}

struct vec2 svec2_tangent(struct vec2 v0) {
    struct vec2 result;
    vec2_tangent((mfloat_t *)&result, (const mfloat_t *)&v0);
    return result;
}

struct vec2 svec2_rotate(struct vec2 v0, mfloat_t f) {
    struct vec2 result;
    vec2_rotate((mfloat_t *)&result, (const mfloat_t *)&v0, f);
    return result;
}

struct vec2 svec2_lerp(struct vec2 v0, struct vec2 v1, mfloat_t f) {
    struct vec2 result;
    vec2_lerp((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1, f);
    return result;
}

struct vec2 svec2_bezier3(struct vec2 v0, struct vec2 v1, struct vec2 v2, mfloat_t f) {
    struct vec2 result;
    vec2_bezier3((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1, (const mfloat_t *)&v2, f);
    return result;
}

struct vec2 svec2_bezier4(struct vec2 v0, struct vec2 v1, struct vec2 v2, struct vec2 v3, mfloat_t f) {
    struct vec2 result;
    vec2_bezier4((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1, (const mfloat_t *)&v2, (const mfloat_t *)&v3, f);
    return result;
}

mfloat_t svec2_angle(struct vec2 v0) {
    return vec2_angle((const mfloat_t *)&v0);
}

mfloat_t svec2_length(struct vec2 v0) {
    return vec2_length((const mfloat_t *)&v0);
}

mfloat_t svec2_length_squared(struct vec2 v0) {
    return vec2_length_squared((const mfloat_t *)&v0);
}

mfloat_t svec2_distance(struct vec2 v0, struct vec2 v1) {
    return vec2_distance((const mfloat_t *)&v0, (const mfloat_t *)&v1);
}

mfloat_t svec2_distance_squared(struct vec2 v0, struct vec2 v1) {
    return vec2_distance_squared((const mfloat_t *)&v0, (const mfloat_t *)&v1);
}

#if defined(MATHC_USE_INT)
struct vec2 svec2_assign_vec2i(struct vec2i v0) {
    struct vec2 result;
    vec2_assign_vec2i((mfloat_t *)&result, (const mint_t *)&v0);
    return result;
}
#endif
#endif

#if defined(MATHC_USE_POINTER_STRUCT_FUNCTIONS)bool psvec2_is_zero(struct vec2 *v0) {
    return vec2_is_zero((const mfloat_t *)v0);
}

bool psvec2_is_equal(struct vec2 *v0, struct vec2 *v1) {
    return vec2_is_equal((const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec2 *psvec2(struct vec2 *result, mfloat_t x, mfloat_t y) {
    return (struct vec2 *)vec2((mfloat_t *)result, x, y);
}

struct vec2 *psvec2_assign(struct vec2 *result, struct vec2 *v0) {
    return (struct vec2 *)vec2_assign((mfloat_t *)result, (const mfloat_t *)v0);
}

struct vec2 *psvec2_zero(struct vec2 *result) {
    return (struct vec2 *)vec2_zero((mfloat_t *)result);
}

struct vec2 *psvec2_one(struct vec2 *result) {
    return (struct vec2 *)vec2_one((mfloat_t *)result);
}

struct vec2 *psvec2_sign(struct vec2 *result, struct vec2 *v0) {
    return (struct vec2 *)vec2_sign((mfloat_t *)result, (const mfloat_t *)v0);
}

struct vec2 *psvec2_add(struct vec2 *result, struct vec2 *v0, struct vec2 *v1) {
    return (struct vec2 *)vec2_add((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec2 *psvec2_add_f(struct vec2 *result, struct vec2 *v0, mfloat_t f) {
    return (struct vec2 *)vec2_add_f((mfloat_t *)result, (const mfloat_t *)v0, f);
}

struct vec2 *psvec2_subtract(struct vec2 *result, struct vec2 *v0, struct vec2 *v1) {
    return (struct vec2 *)vec2_subtract((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec2 *psvec2_subtract_f(struct vec2 *result, struct vec2 *v0, mfloat_t f) {
    return (struct vec2 *)vec2_subtract_f((mfloat_t *)result, (const mfloat_t *)v0, f);
}

struct vec2 *psvec2_multiply(struct vec2 *result, struct vec2 *v0, struct vec2 *v1) {
    return (struct vec2 *)vec2_multiply((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec2 *psvec2_multiply_f(struct vec2 *result, struct vec2 *v0, mfloat_t f) {
    return (struct vec2 *)vec2_multiply_f((mfloat_t *)result, (const mfloat_t *)v0, f);
}

struct vec2 *psvec2_multiply_mat2(struct vec2 *result, struct vec2 *v0, const struct mat2 *m0) {
    return (struct vec2 *)vec2_multiply_mat2((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)m0);
}

struct vec2 *psvec2_divide(struct vec2 *result, struct vec2 *v0, struct vec2 *v1) {
    return (struct vec2 *)vec2_divide((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec2 *psvec2_divide_f(struct vec2 *result, struct vec2 *v0, mfloat_t f) {
    return (struct vec2 *)vec2_divide_f((mfloat_t *)result, (const mfloat_t *)v0, f);
}

struct vec2 *psvec2_snap(struct vec2 *result, struct vec2 *v0, struct vec2 *v1) {
    return (struct vec2 *)vec2_snap((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec2 *psvec2_snap_f(struct vec2 *result, struct vec2 *v0, mfloat_t f) {
    return (struct vec2 *)vec2_snap_f((mfloat_t *)result, (const mfloat_t *)v0, f);
}

struct vec2 *psvec2_negative(struct vec2 *result, struct vec2 *v0) {
    return (struct vec2 *)vec2_negative((mfloat_t *)result, (const mfloat_t *)v0);
}

struct vec2 *psvec2_abs(struct vec2 *result, struct vec2 *v0) {
    return (struct vec2 *)vec2_abs((mfloat_t *)result, (const mfloat_t *)v0);
}

struct vec2 *psvec2_floor(struct vec2 *result, struct vec2 *v0) {
    return (struct vec2 *)vec2_floor((mfloat_t *)result, (const mfloat_t *)v0);
}

struct vec2 *psvec2_ceil(struct vec2 *result, struct vec2 *v0) {
    return (struct vec2 *)vec2_ceil((mfloat_t *)result, (const mfloat_t *)v0);
}

struct vec2 *psvec2_round(struct vec2 *result, struct vec2 *v0) {
    return (struct vec2 *)vec2_round((mfloat_t *)result, (const mfloat_t *)v0);
}

struct vec2 *psvec2_max(struct vec2 *result, struct vec2 *v0, struct vec2 *v1) {
    return (struct vec2 *)vec2_max((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec2 *psvec2_min(struct vec2 *result, struct vec2 *v0, struct vec2 *v1) {
    return (struct vec2 *)vec2_min((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec2 *psvec2_clamp(struct vec2 *result, struct vec2 *v0, struct vec2 *v1, struct vec2 *v2) {
    return (struct vec2 *)vec2_clamp((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1, (const mfloat_t *)v2);
}

struct vec2 *psvec2_normalize(struct vec2 *result, struct vec2 *v0) {
    return (struct vec2 *)vec2_normalize((mfloat_t *)result, (const mfloat_t *)v0);
}

mfloat_t psvec2_dot(struct vec2 *v0, struct vec2 *v1) {
    return vec2_dot((const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec2 *psvec2_project(struct vec2 *result, struct vec2 *v0, struct vec2 *v1) {
    return (struct vec2 *)vec2_project((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec2 *psvec2_slide(struct vec2 *result, struct vec2 *v0, struct vec2 *normal) {
    return (struct vec2 *)vec2_slide((mfloat_t *)result, (const mfloat_t *)v0, (mfloat_t *)normal);
}

struct vec2 *psvec2_reflect(struct vec2 *result, struct vec2 *v0, struct vec2 *normal) {
    return (struct vec2 *)vec2_reflect((mfloat_t *)result, (const mfloat_t *)v0, (mfloat_t *)normal);
}

struct vec2 *psvec2_tangent(struct vec2 *result, struct vec2 *v0) {
    return (struct vec2 *)vec2_tangent((mfloat_t *)result, (const mfloat_t *)v0);
}

struct vec2 *psvec2_rotate(struct vec2 *result, struct vec2 *v0, mfloat_t f) {
    return (struct vec2 *)vec2_rotate((mfloat_t *)result, (const mfloat_t *)v0, f);
}

struct vec2 *psvec2_lerp(struct vec2 *result, struct vec2 *v0, struct vec2 *v1, mfloat_t f) {
    return (struct vec2 *)vec2_lerp((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1, f);
}

struct vec2 *psvec2_bezier3(struct vec2 *result, struct vec2 *v0, struct vec2 *v1, struct vec2 *v2, mfloat_t f) {
    return (struct vec2 *)vec2_bezier3((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1, (const mfloat_t *)v2, f);
}

struct vec2 *psvec2_bezier4(struct vec2 *result, struct vec2 *v0, struct vec2 *v1, struct vec2 *v2, struct vec2 *v3, mfloat_t f) {
    return (struct vec2 *)vec2_bezier4((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1, (const mfloat_t *)v2, (const mfloat_t *)v3, f);
}

mfloat_t psvec2_angle(struct vec2 *v0) {
    return vec2_angle((const mfloat_t *)v0);
}

mfloat_t psvec2_length(struct vec2 *v0) {
    return vec2_length((const mfloat_t *)v0);
}

mfloat_t psvec2_length_squared(struct vec2 *v0) {
    return vec2_length_squared((const mfloat_t *)v0);
}

mfloat_t psvec2_distance(struct vec2 *v0, struct vec2 *v1) {
    return vec2_distance((const mfloat_t *)v0, (const mfloat_t *)v1);
}

mfloat_t psvec2_distance_squared(struct vec2 *v0, struct vec2 *v1) {
    return vec2_distance_squared((const mfloat_t *)v0, (const mfloat_t *)v1);
}

#if defined(MATHC_USE_INT)
struct vec2 *psvec2_assign_vec2i(struct vec2 *result, const struct vec2i *v0) {
    return (struct vec2 *)vec2_assign_vec2i((mfloat_t *)result, (const mint_t *)v0);
}
#endif
#endif
#endif