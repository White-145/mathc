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
bool vec3_is_zero(const mfloat_t *v0) {
    return MFABS(v0[0]) < MFLT_EPSILON && MFABS(v0[1]) < MFLT_EPSILON && MFABS(v0[2]) < MFLT_EPSILON;
}

bool vec3_is_equal(const mfloat_t *v0, const mfloat_t *v1) {
    return MFABS(v0[0] - v1[0]) < MFLT_EPSILON && MFABS(v0[1] - v1[1]) < MFLT_EPSILON && MFABS(v0[2] - v1[2]) < MFLT_EPSILON;
}

mfloat_t *vec3(mfloat_t *result, mfloat_t x, mfloat_t y, mfloat_t z) {
    result[0] = x;
    result[1] = y;
    result[2] = z;
    return result;
}

mfloat_t *vec3_assign(mfloat_t *result, const mfloat_t *v0) {
    memcpy(result, v0, sizeof(mfloat_t) * VEC3_SIZE);
    return result;
}

mfloat_t *vec3_zero(mfloat_t *result) {
    result[0] = MZERO;
    result[1] = MZERO;
    result[2] = MZERO;
    return result;
}

mfloat_t *vec3_one(mfloat_t *result) {
    result[0] = MONE;
    result[1] = MONE;
    result[2] = MONE;
    return result;
}

mfloat_t *vec3_sign(mfloat_t *result, const mfloat_t *v0) {
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
    return result;
}

mfloat_t *vec3_add(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1) {
    result[0] = v0[0] + v1[0];
    result[1] = v0[1] + v1[1];
    result[2] = v0[2] + v1[2];
    return result;
}

mfloat_t *vec3_add_f(mfloat_t *result, const mfloat_t *v0, mfloat_t f) {
    result[0] = v0[0] + f;
    result[1] = v0[1] + f;
    result[2] = v0[2] + f;
    return result;
}

mfloat_t *vec3_subtract(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1) {
    result[0] = v0[0] - v1[0];
    result[1] = v0[1] - v1[1];
    result[2] = v0[2] - v1[2];
    return result;
}

mfloat_t *vec3_subtract_f(mfloat_t *result, const mfloat_t *v0, mfloat_t f) {
    result[0] = v0[0] - f;
    result[1] = v0[1] - f;
    result[2] = v0[2] - f;
    return result;
}

mfloat_t *vec3_multiply(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1) {
    result[0] = v0[0] * v1[0];
    result[1] = v0[1] * v1[1];
    result[2] = v0[2] * v1[2];
    return result;
}

mfloat_t *vec3_multiply_f(mfloat_t *result, const mfloat_t *v0, mfloat_t f) {
    result[0] = v0[0] * f;
    result[1] = v0[1] * f;
    result[2] = v0[2] * f;
    return result;
}

mfloat_t *vec3_multiply_mat3(mfloat_t *result, const mfloat_t *v0, const mfloat_t *m0) {
    mfloat_t x = v0[0];
    mfloat_t y = v0[1];
    mfloat_t z = v0[2];
    result[0] = m0[0] * x + m0[3] * y + m0[6] * z;
    result[1] = m0[1] * x + m0[4] * y + m0[7] * z;
    result[2] = m0[2] * x + m0[5] * y + m0[8] * z;
    return result;
}

mfloat_t *vec3_divide(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1) {
    result[0] = v0[0] / v1[0];
    result[1] = v0[1] / v1[1];
    result[2] = v0[2] / v1[2];
    return result;
}

mfloat_t *vec3_divide_f(mfloat_t *result, const mfloat_t *v0, mfloat_t f) {
    result[0] = v0[0] / f;
    result[1] = v0[1] / f;
    result[2] = v0[2] / f;
    return result;
}

mfloat_t *vec3_snap(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1) {
    result[0] = MFLOOR(v0[0] / v1[0]) * v1[0];
    result[1] = MFLOOR(v0[1] / v1[1]) * v1[1];
    result[2] = MFLOOR(v0[2] / v1[2]) * v1[2];
    return result;
}

mfloat_t *vec3_snap_f(mfloat_t *result, const mfloat_t *v0, mfloat_t f) {
    result[0] = MFLOOR(v0[0] / f) * f;
    result[1] = MFLOOR(v0[1] / f) * f;
    result[2] = MFLOOR(v0[2] / f) * f;
    return result;
}

mfloat_t *vec3_negative(mfloat_t *result, const mfloat_t *v0) {
    result[0] = -v0[0];
    result[1] = -v0[1];
    result[2] = -v0[2];
    return result;
}

mfloat_t *vec3_abs(mfloat_t *result, const mfloat_t *v0) {
    result[0] = MFABS(v0[0]);
    result[1] = MFABS(v0[1]);
    result[2] = MFABS(v0[2]);
    return result;
}

mfloat_t *vec3_floor(mfloat_t *result, const mfloat_t *v0) {
    result[0] = MFLOOR(v0[0]);
    result[1] = MFLOOR(v0[1]);
    result[2] = MFLOOR(v0[2]);
    return result;
}

mfloat_t *vec3_ceil(mfloat_t *result, const mfloat_t *v0) {
    result[0] = MCEIL(v0[0]);
    result[1] = MCEIL(v0[1]);
    result[2] = MCEIL(v0[2]);
    return result;
}

mfloat_t *vec3_round(mfloat_t *result, const mfloat_t *v0) {
    result[0] = MROUND(v0[0]);
    result[1] = MROUND(v0[1]);
    result[2] = MROUND(v0[2]);
    return result;
}

mfloat_t *vec3_max(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1) {
    result[0] = MFMAX(v0[0], v1[0]);
    result[1] = MFMAX(v0[1], v1[1]);
    result[2] = MFMAX(v0[2], v1[2]);
    return result;
}

mfloat_t *vec3_min(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1) {
    result[0] = MFMIN(v0[0], v1[0]);
    result[1] = MFMIN(v0[1], v1[1]);
    result[2] = MFMIN(v0[2], v1[2]);
    return result;
}

mfloat_t *vec3_clamp(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1, const mfloat_t *v2) {
    result[0] = MFMIN(MFMAX(v0[0], v1[0]), v2[0]);
    result[1] = MFMIN(MFMAX(v0[1], v1[1]), v2[1]);
    result[2] = MFMIN(MFMAX(v0[2], v1[2]), v2[2]);
    return result;
}

mfloat_t *vec3_cross(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1) {
    mfloat_t cross[VEC3_SIZE];
    cross[0] = v0[1] * v1[2] - v0[2] * v1[1];
    cross[1] = v0[2] * v1[0] - v0[0] * v1[2];
    cross[2] = v0[0] * v1[1] - v0[1] * v1[0];
    memcpy(result, cross, sizeof(mfloat_t) * VEC3_SIZE);
    return result;
}

mfloat_t *vec3_normalize(mfloat_t *result, const mfloat_t *v0) {
    mfloat_t l = MSQRT(v0[0] * v0[0] + v0[1] * v0[1] + v0[2] * v0[2]);
    result[0] = v0[0] / l;
    result[1] = v0[1] / l;
    result[2] = v0[2] / l;
    return result;
}

mfloat_t vec3_dot(const mfloat_t *v0, const mfloat_t *v1) {
    return v0[0] * v1[0] + v0[1] * v1[1] + v0[2] * v1[2];
}

mfloat_t *vec3_project(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1) {
    mfloat_t d = vec3_dot(v1, v1);
    mfloat_t s = vec3_dot(v0, v1) / d;
    result[0] = v1[0] * s;
    result[1] = v1[1] * s;
    result[2] = v1[2] * s;
    return result;
}

mfloat_t *vec3_slide(mfloat_t *result, const mfloat_t *v0, const mfloat_t *normal) {
    mfloat_t d = vec3_dot(v0, normal);
    result[0] = v0[0] - normal[0] * d;
    result[1] = v0[1] - normal[1] * d;
    result[2] = v0[2] - normal[2] * d;
    return result;
}

mfloat_t *vec3_reflect(mfloat_t *result, const mfloat_t *v0, const mfloat_t *normal) {
    mfloat_t d = MTWO * vec3_dot(v0, normal);
    result[0] = normal[0] * d - v0[0];
    result[1] = normal[1] * d - v0[1];
    result[2] = normal[2] * d - v0[2];
    return result;
}

mfloat_t *vec3_rotate(mfloat_t *result, const mfloat_t *v0, const mfloat_t *ra, mfloat_t f) {
    mfloat_t cs;
    mfloat_t sn;
    mfloat_t x;
    mfloat_t y;
    mfloat_t z;
    mfloat_t rx;
    mfloat_t ry;
    mfloat_t rz;
    cs = MCOS(f);
    sn = MSIN(f);
    x = v0[0];
    y = v0[1];
    z = v0[2];
    struct vec3 norm;
    vec3_normalize((mfloat_t *)&norm, ra);
    rx = norm.x;
    ry = norm.y;
    rz = norm.z;
    result[0] = x * (cs + rx * rx * (1 - cs)) + y * (rx * ry * (1 - cs) - rz * sn) + z * (rx * rz * (1 - cs) + ry * sn);
    result[1] = x * (ry * rx * (1 - cs) + rz * sn) + y * (cs + ry * ry * (1 - cs)) + z * (ry * rz * (1 - cs) - rx * sn);
    result[2] = x * (rz * rx * (1 - cs) - ry * sn) + y * (rz * ry * (1 - cs) + rx * sn) + z * (cs + rz * rz * (1 - cs));
    return result;
}

mfloat_t *vec3_lerp(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1, mfloat_t f) {
    result[0] = v0[0] + (v1[0] - v0[0]) * f;
    result[1] = v0[1] + (v1[1] - v0[1]) * f;
    result[2] = v0[2] + (v1[2] - v0[2]) * f;
    return result;
}

mfloat_t *vec3_bezier3(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1, const mfloat_t *v2, mfloat_t f) {
    mfloat_t tmp0[VEC3_SIZE];
    mfloat_t tmp1[VEC3_SIZE];
    vec3_lerp(tmp0, v0, v1, f);
    vec3_lerp(tmp1, v1, v2, f);
    vec3_lerp(result, tmp0, tmp1, f);
    return result;
}

mfloat_t *vec3_bezier4(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1, const mfloat_t *v2, const mfloat_t *v3, mfloat_t f) {
    mfloat_t tmp0[VEC3_SIZE];
    mfloat_t tmp1[VEC3_SIZE];
    mfloat_t tmp2[VEC3_SIZE];
    mfloat_t tmp3[VEC3_SIZE];
    mfloat_t tmp4[VEC3_SIZE];
    vec3_lerp(tmp0, v0, v1, f);
    vec3_lerp(tmp1, v1, v2, f);
    vec3_lerp(tmp2, v2, v3, f);
    vec3_lerp(tmp3, tmp0, tmp1, f);
    vec3_lerp(tmp4, tmp1, tmp2, f);
    vec3_lerp(result, tmp3, tmp4, f);
    return result;
}

mfloat_t vec3_length(const mfloat_t *v0) {
    return MSQRT(v0[0] * v0[0] + v0[1] * v0[1] + v0[2] * v0[2]);
}

mfloat_t vec3_length_squared(const mfloat_t *v0) {
    return v0[0] * v0[0] + v0[1] * v0[1] + v0[2] * v0[2];
}

mfloat_t vec3_distance(const mfloat_t *v0, const mfloat_t *v1) {
    return MSQRT((v0[0] - v1[0]) * (v0[0] - v1[0]) + (v0[1] - v1[1]) * (v0[1] - v1[1]) + (v0[2] - v1[2]) * (v0[2] - v1[2]));
}

mfloat_t vec3_distance_squared(const mfloat_t *v0, const mfloat_t *v1) {
    return (v0[0] - v1[0]) * (v0[0] - v1[0]) + (v0[1] - v1[1]) * (v0[1] - v1[1]) + (v0[2] - v1[2]) * (v0[2] - v1[2]);
}

bool vec3_linear_independent(const mfloat_t *v0, const mfloat_t *v1, const mfloat_t *v2) {
    return v0[0] * v1[1] * v2[2] + v0[1] * v1[2] * v2[0] + v0[2] * v1[0] * v2[1] - v0[2] * v1[1] * v2[0] - v0[1] * v1[0] * v2[2] - v0[0] * v1[2] * v2[1];
}

mfloat_t **vec3_orthonormalization(mfloat_t result[3][3], mfloat_t basis[3][3]) {
    mfloat_t v0[3];
    mfloat_t v1[3];
    mfloat_t v2[3];

    for(int32_t i = 0; i < 3; ++i) {
        v0[i] = basis[0][i];
        v1[i] = basis[1][i];
        v2[i] = basis[2][i];
    }

    if (!vec3_linear_independent(v0, v1, v2)) {
        return (mfloat_t **)result;
    }

    mfloat_t proj[3];
    mfloat_t u0[3];
    mfloat_t u1[3];
    mfloat_t u2[3];

    for(int32_t i = 0; i < 3; ++i) {
        u0[i] = v0[i];
    }

    vec3_project(proj, v1, u0);
    vec3_subtract(u1, v1, proj);

    vec3_project(proj, v2, u0);
    vec3_subtract(u2, v2, proj);
    vec3_project(proj, v2, u1);
    vec3_subtract(u2, u2, proj);

    vec3_normalize(result[0], u0);
    vec3_normalize(result[1], u1);
    vec3_normalize(result[2], u2);

    return (mfloat_t **)result;
}

#if defined(MATHC_USE_INT)
mfloat_t *vec3_assign_vec3i(mfloat_t *result, const mint_t *v0) {
    result[0] = v0[0];
    result[1] = v0[1];
    result[2] = v0[2];
    return result;
}
#endif

#if defined(MATHC_USE_STRUCT_FUNCTIONS)
bool svec3_is_zero(struct vec3 v0) {
    return vec3_is_zero((const mfloat_t *)&v0);
}

bool svec3_is_equal(struct vec3 v0, struct vec3 v1) {
    return vec3_is_equal((const mfloat_t *)&v0, (const mfloat_t *)&v1);
}

struct vec3 svec3(mfloat_t x, mfloat_t y, mfloat_t z) {
    struct vec3 result;
    vec3((mfloat_t *)&result, x, y, z);
    return result;
}

struct vec3 svec3_assign(struct vec3 v0) {
    struct vec3 result;
    vec3_assign((mfloat_t *)&result, (const mfloat_t *)&v0);
    return result;
}

struct vec3 svec3_zero(void) {
    struct vec3 result;
    vec3_zero((mfloat_t *)&result);
    return result;
}

struct vec3 svec3_one(void) {
    struct vec3 result;
    vec3_one((mfloat_t *)&result);
    return result;
}

struct vec3 svec3_sign(struct vec3 v0) {
    struct vec3 result;
    vec3_sign((mfloat_t *)&result, (const mfloat_t *)&v0);
    return result;
}

struct vec3 svec3_add(struct vec3 v0, struct vec3 v1) {
    struct vec3 result;
    vec3_add((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1);
    return result;
}

struct vec3 svec3_add_f(struct vec3 v0, mfloat_t f) {
    struct vec3 result;
    vec3_add_f((mfloat_t *)&result, (const mfloat_t *)&v0, f);
    return result;
}

struct vec3 svec3_subtract(struct vec3 v0, struct vec3 v1) {
    struct vec3 result;
    vec3_subtract((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1);
    return result;
}

struct vec3 svec3_subtract_f(struct vec3 v0, mfloat_t f) {
    struct vec3 result;
    vec3_subtract_f((mfloat_t *)&result, (const mfloat_t *)&v0, f);
    return result;
}

struct vec3 svec3_multiply(struct vec3 v0, struct vec3 v1) {
    struct vec3 result;
    vec3_multiply((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1);
    return result;
}

struct vec3 svec3_multiply_f(struct vec3 v0, mfloat_t f) {
    struct vec3 result;
    vec3_multiply_f((mfloat_t *)&result, (const mfloat_t *)&v0, f);
    return result;
}

struct vec3 svec3_multiply_mat3(struct vec3 v0, struct mat3 m0) {
    struct vec3 result;
    vec3_multiply_mat3((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&m0);
    return result;
}

struct vec3 svec3_divide(struct vec3 v0, struct vec3 v1) {
    struct vec3 result;
    vec3_divide((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1);
    return result;
}

struct vec3 svec3_divide_f(struct vec3 v0, mfloat_t f) {
    struct vec3 result;
    vec3_divide_f((mfloat_t *)&result, (const mfloat_t *)&v0, f);
    return result;
}

struct vec3 svec3_snap(struct vec3 v0, struct vec3 v1) {
    struct vec3 result;
    vec3_snap((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1);
    return result;
}

struct vec3 svec3_snap_f(struct vec3 v0, mfloat_t f) {
    struct vec3 result;
    vec3_snap_f((mfloat_t *)&result, (const mfloat_t *)&v0, f);
    return result;
}

struct vec3 svec3_negative(struct vec3 v0) {
    struct vec3 result;
    vec3_negative((mfloat_t *)&result, (const mfloat_t *)&v0);
    return result;
}

struct vec3 svec3_abs(struct vec3 v0) {
    struct vec3 result;
    vec3_abs((mfloat_t *)&result, (const mfloat_t *)&v0);
    return result;
}

struct vec3 svec3_floor(struct vec3 v0) {
    struct vec3 result;
    vec3_floor((mfloat_t *)&result, (const mfloat_t *)&v0);
    return result;
}

struct vec3 svec3_ceil(struct vec3 v0) {
    struct vec3 result;
    vec3_ceil((mfloat_t *)&result, (const mfloat_t *)&v0);
    return result;
}

struct vec3 svec3_round(struct vec3 v0) {
    struct vec3 result;
    vec3_round((mfloat_t *)&result, (const mfloat_t *)&v0);
    return result;
}

struct vec3 svec3_max(struct vec3 v0, struct vec3 v1) {
    struct vec3 result;
    vec3_max((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1);
    return result;
}

struct vec3 svec3_min(struct vec3 v0, struct vec3 v1) {
    struct vec3 result;
    vec3_min((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1);
    return result;
}

struct vec3 svec3_clamp(struct vec3 v0, struct vec3 v1, struct vec3 v2) {
    struct vec3 result;
    vec3_clamp((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1, (const mfloat_t *)&v2);
    return result;
}

struct vec3 svec3_cross(struct vec3 v0, struct vec3 v1) {
    struct vec3 result;
    vec3_cross((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1);
    return result;
}

struct vec3 svec3_normalize(struct vec3 v0) {
    struct vec3 result;
    vec3_normalize((mfloat_t *)&result, (const mfloat_t *)&v0);
    return result;
}

mfloat_t svec3_dot(struct vec3 v0, struct vec3 v1) {
    return vec3_dot((const mfloat_t *)&v0, (const mfloat_t *)&v1);
}

struct vec3 svec3_project(struct vec3 v0, struct vec3 v1) {
    struct vec3 result;
    vec3_project((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1);
    return result;
}

struct vec3 svec3_slide(struct vec3 v0, struct vec3 normal) {
    struct vec3 result;
    vec3_slide((mfloat_t *)&result, (const mfloat_t *)&v0, (mfloat_t *)&normal);
    return result;
}

struct vec3 svec3_reflect(struct vec3 v0, struct vec3 normal) {
    struct vec3 result;
    vec3_reflect((mfloat_t *)&result, (const mfloat_t *)&v0, (mfloat_t *)&normal);
    return result;
}

struct vec3 svec3_rotate(struct vec3 v0, struct vec3 ra, mfloat_t f) {
    struct vec3 result;
    vec3_lerp((mfloat_t *)&result, (const mfloat_t *)&v0, (mfloat_t *)&ra, f);
    return result;
}

struct vec3 svec3_lerp(struct vec3 v0, struct vec3 v1, mfloat_t f) {
    struct vec3 result;
    vec3_lerp((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1, f);
    return result;
}

struct vec3 svec3_bezier3(struct vec3 v0, struct vec3 v1, struct vec3 v2, mfloat_t f) {
    struct vec3 result;
    vec3_bezier3((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1, (const mfloat_t *)&v2, f);
    return result;
}

struct vec3 svec3_bezier4(struct vec3 v0, struct vec3 v1, struct vec3 v2, struct vec3 v3, mfloat_t f) {
    struct vec3 result;
    vec3_bezier4((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1, (const mfloat_t *)&v2, (const mfloat_t *)&v3, f);
    return result;
}

mfloat_t svec3_length(struct vec3 v0) {
    return vec3_length((const mfloat_t *)&v0);
}

mfloat_t svec3_length_squared(struct vec3 v0) {
    return vec3_length_squared((const mfloat_t *)&v0);
}

mfloat_t svec3_distance(struct vec3 v0, struct vec3 v1) {
    return vec3_distance((const mfloat_t *)&v0, (const mfloat_t *)&v1);
}

mfloat_t svec3_distance_squared(struct vec3 v0, struct vec3 v1) {
    return vec3_distance_squared((const mfloat_t *)&v0, (const mfloat_t *)&v1);
}

#if defined(MATHC_USE_INT)
struct vec3 svec3_assign_vec3i(struct vec3i v0) {
    struct vec3 result;
    vec3_assign_vec3i((mfloat_t *)&result, (const mint_t *)&v0);
    return result;
}
#endif
#endif

#if defined(MATHC_USE_POINTER_STRUCT_FUNCTIONS)
bool psvec3_is_zero(const struct vec3 *v0) {
    return vec3_is_zero((const mfloat_t *)v0);
}

bool psvec3_is_equal(const struct vec3 *v0, struct vec3 *v1) {
    return vec3_is_equal((const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec3 *psvec3(struct vec3 *result, mfloat_t x, mfloat_t y, mfloat_t z) {
    return (struct vec3 *)vec3((mfloat_t *)result, x, y, z);
}

struct vec3 *psvec3_assign(struct vec3 *result, const struct vec3 *v0) {
    return (struct vec3 *)vec3_assign((mfloat_t *)result, (const mfloat_t *)v0);
}

struct vec3 *psvec3_zero(struct vec3 *result) {
    return (struct vec3 *)vec3_zero((mfloat_t *)result);
}

struct vec3 *psvec3_one(struct vec3 *result) {
    return (struct vec3 *)vec3_one((mfloat_t *)result);
}

struct vec3 *psvec3_sign(struct vec3 *result, const struct vec3 *v0) {
    return (struct vec3 *)vec3_sign((mfloat_t *)result, (const mfloat_t *)v0);
}

struct vec3 *psvec3_add(struct vec3 *result, const struct vec3 *v0, struct vec3 *v1) {
    return (struct vec3 *)vec3_add((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec3 *psvec3_add_f(struct vec3 *result, const struct vec3 *v0, mfloat_t f) {
    return (struct vec3 *)vec3_add_f((mfloat_t *)result, (const mfloat_t *)v0, f);
}

struct vec3 *psvec3_subtract(struct vec3 *result, const struct vec3 *v0, struct vec3 *v1) {
    return (struct vec3 *)vec3_subtract((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec3 *psvec3_subtract_f(struct vec3 *result, const struct vec3 *v0, mfloat_t f) {
    return (struct vec3 *)vec3_subtract_f((mfloat_t *)result, (const mfloat_t *)v0, f);
}

struct vec3 *psvec3_multiply(struct vec3 *result, const struct vec3 *v0, struct vec3 *v1) {
    return (struct vec3 *)vec3_multiply((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec3 *psvec3_multiply_f(struct vec3 *result, const struct vec3 *v0, mfloat_t f) {
    return (struct vec3 *)vec3_multiply_f((mfloat_t *)result, (const mfloat_t *)v0, f);
}

struct vec3 *psvec3_multiply_mat3(struct vec3 *result, const struct vec3 *v0, const struct mat3 *m0) {
    return (struct vec3 *)vec3_multiply_mat3((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)m0);
}

struct vec3 *psvec3_divide(struct vec3 *result, const struct vec3 *v0, struct vec3 *v1) {
    return (struct vec3 *)vec3_divide((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec3 *psvec3_divide_f(struct vec3 *result, const struct vec3 *v0, mfloat_t f) {
    return (struct vec3 *)vec3_divide_f((mfloat_t *)result, (const mfloat_t *)v0, f);
}

struct vec3 *psvec3_snap(struct vec3 *result, const struct vec3 *v0, struct vec3 *v1) {
    return (struct vec3 *)vec3_snap((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec3 *psvec3_snap_f(struct vec3 *result, const struct vec3 *v0, mfloat_t f) {
    return (struct vec3 *)vec3_snap_f((mfloat_t *)result, (const mfloat_t *)v0, f);
}

struct vec3 *psvec3_negative(struct vec3 *result, const struct vec3 *v0) {
    return (struct vec3 *)vec3_negative((mfloat_t *)result, (const mfloat_t *)v0);
}

struct vec3 *psvec3_abs(struct vec3 *result, const struct vec3 *v0) {
    return (struct vec3 *)vec3_abs((mfloat_t *)result, (const mfloat_t *)v0);
}

struct vec3 *psvec3_floor(struct vec3 *result, const struct vec3 *v0) {
    return (struct vec3 *)vec3_floor((mfloat_t *)result, (const mfloat_t *)v0);
}

struct vec3 *psvec3_ceil(struct vec3 *result, const struct vec3 *v0) {
    return (struct vec3 *)vec3_ceil((mfloat_t *)result, (const mfloat_t *)v0);
}

struct vec3 *psvec3_round(struct vec3 *result, const struct vec3 *v0) {
    return (struct vec3 *)vec3_round((mfloat_t *)result, (const mfloat_t *)v0);
}

struct vec3 *psvec3_max(struct vec3 *result, const struct vec3 *v0, struct vec3 *v1) {
    return (struct vec3 *)vec3_max((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec3 *psvec3_min(struct vec3 *result, const struct vec3 *v0, struct vec3 *v1) {
    return (struct vec3 *)vec3_min((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec3 *psvec3_clamp(struct vec3 *result, const struct vec3 *v0, struct vec3 *v1, struct vec3 *v2) {
    return (struct vec3 *)vec3_clamp((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1, (const mfloat_t *)v2);
}

struct vec3 *psvec3_cross(struct vec3 *result, const struct vec3 *v0, struct vec3 *v1) {
    return (struct vec3 *)vec3_cross((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec3 *psvec3_normalize(struct vec3 *result, const struct vec3 *v0) {
    return (struct vec3 *)vec3_normalize((mfloat_t *)result, (const mfloat_t *)v0);
}

mfloat_t psvec3_dot(const struct vec3 *v0, struct vec3 *v1) {
    return vec3_dot((const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec3 *psvec3_project(struct vec3 *result, const struct vec3 *v0, struct vec3 *v1) {
    return (struct vec3 *)vec3_project((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct vec3 *psvec3_slide(struct vec3 *result, const struct vec3 *v0, struct vec3 *normal) {
    return (struct vec3 *)vec3_slide((mfloat_t *)result, (const mfloat_t *)v0, (mfloat_t *)normal);
}

struct vec3 *psvec3_reflect(struct vec3 *result, const struct vec3 *v0, struct vec3 *normal) {
    return (struct vec3 *)vec3_reflect((mfloat_t *)result, (const mfloat_t *)v0, (mfloat_t *)normal);
}

struct vec3 *psvec3_rotate(struct vec3 *result, const struct vec3 *v0, struct vec3 *ra, mfloat_t f) {
    return (struct vec3 *)vec3_lerp((mfloat_t *)result, (const mfloat_t *)v0, (mfloat_t *)ra, f);
}

struct vec3 *psvec3_lerp(struct vec3 *result, const struct vec3 *v0, struct vec3 *v1, mfloat_t f) {
    return (struct vec3 *)vec3_lerp((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1, f);
}

struct vec3 *psvec3_bezier3(struct vec3 *result, const struct vec3 *v0, struct vec3 *v1, struct vec3 *v2, mfloat_t f) {
    return (struct vec3 *)vec3_bezier3((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1, (const mfloat_t *)v2, f);
}

struct vec3 *psvec3_bezier4(struct vec3 *result, const struct vec3 *v0, struct vec3 *v1, struct vec3 *v2, struct vec3 *v3, mfloat_t f) {
    return (struct vec3 *)vec3_bezier4((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1, (const mfloat_t *)v2, (const mfloat_t *)v3, f);
}

mfloat_t psvec3_length(const struct vec3 *v0) {
    return vec3_length((const mfloat_t *)v0);
}

mfloat_t psvec3_length_squared(const struct vec3 *v0) {
    return vec3_length_squared((const mfloat_t *)v0);
}

mfloat_t psvec3_distance(const struct vec3 *v0, struct vec3 *v1) {
    return vec3_distance((const mfloat_t *)v0, (const mfloat_t *)v1);
}

mfloat_t psvec3_distance_squared(const struct vec3 *v0, struct vec3 *v1) {
    return vec3_distance_squared((const mfloat_t *)v0, (const mfloat_t *)v1);
}

#if defined(MATHC_USE_INT)
struct vec3 *psvec3_assign_vec3i(struct vec3 *result, const struct vec3i *v0) {
    return (struct vec3 *)vec3_assign_vec3i((mfloat_t *)result, (const mint_t *)v0);
}
#endif
#endif
#endif