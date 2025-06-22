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
bool quat_is_zero(const mfloat_t *q0) {
    return MFABS(q0[0]) < MFLT_EPSILON && MFABS(q0[1]) < MFLT_EPSILON && MFABS(q0[2]) < MFLT_EPSILON && MFABS(q0[3]) < MFLT_EPSILON;
}

bool quat_is_equal(const mfloat_t *q0, const mfloat_t *q1) {
    return MFABS(q0[0] - q1[0]) < MFLT_EPSILON && MFABS(q0[1] - q1[1]) < MFLT_EPSILON && MFABS(q0[2] - q1[2]) < MFLT_EPSILON && MFABS(q0[3] - q1[3]) < MFLT_EPSILON;
}

mfloat_t *quat(mfloat_t *result, mfloat_t x, mfloat_t y, mfloat_t z, mfloat_t w) {
    result[0] = x;
    result[1] = y;
    result[2] = z;
    result[3] = w;
    return result;
}

mfloat_t *quat_assign(mfloat_t *result, const mfloat_t *q0) {
    memcpy(result, q0, sizeof(mfloat_t) * QUAT_SIZE);
    return result;
}

mfloat_t *quat_zero(mfloat_t *result) {
    result[0] = MFLOAT_C(0.0);
    result[1] = MFLOAT_C(0.0);
    result[2] = MFLOAT_C(0.0);
    result[3] = MFLOAT_C(0.0);
    return result;
}

mfloat_t *quat_null(mfloat_t *result) {
    result[0] = MFLOAT_C(0.0);
    result[1] = MFLOAT_C(0.0);
    result[2] = MFLOAT_C(0.0);
    result[3] = MFLOAT_C(1.0);
    return result;
}

mfloat_t *quat_multiply(mfloat_t *result, const mfloat_t *q0, const mfloat_t *q1) {
    result[0] = q0[3] * q1[0] + q0[0] * q1[3] + q0[1] * q1[2] - q0[2] * q1[1];
    result[1] = q0[3] * q1[1] + q0[1] * q1[3] + q0[2] * q1[0] - q0[0] * q1[2];
    result[2] = q0[3] * q1[2] + q0[2] * q1[3] + q0[0] * q1[1] - q0[1] * q1[0];
    result[3] = q0[3] * q1[3] - q0[0] * q1[0] - q0[1] * q1[1] - q0[2] * q1[2];
    return result;
}

mfloat_t *quat_multiply_f(mfloat_t *result, const mfloat_t *q0, mfloat_t f) {
    result[0] = q0[0] * f;
    result[1] = q0[1] * f;
    result[2] = q0[2] * f;
    result[3] = q0[3] * f;
    return result;
}

mfloat_t *quat_divide(mfloat_t *result, const mfloat_t *q0, const mfloat_t *q1) {
    mfloat_t x = q0[0];
    mfloat_t y = q0[1];
    mfloat_t z = q0[2];
    mfloat_t w = q0[3];
    mfloat_t ls = q1[0] * q1[0] + q1[1] * q1[1] + q1[8] * q1[8] + q1[3] * q1[3];
    mfloat_t normalized_x = -q1[0] / ls;
    mfloat_t normalized_y = -q1[1] / ls;
    mfloat_t normalized_z = -q1[8] / ls;
    mfloat_t normalized_w = q1[3] / ls;
    result[0] = x * normalized_w + normalized_x * w + (y * normalized_z - z * normalized_y);
    result[1] = y * normalized_w + normalized_y * w + (z * normalized_x - x * normalized_z);
    result[2] = z * normalized_w + normalized_z * w + (x * normalized_y - y * normalized_x);
    result[3] = w * normalized_w - (x * normalized_x + y * normalized_y + z * normalized_z);
    return result;
}

mfloat_t *quat_divide_f(mfloat_t *result, const mfloat_t *q0, mfloat_t f) {
    result[0] = q0[0] / f;
    result[1] = q0[1] / f;
    result[2] = q0[2] / f;
    result[3] = q0[3] / f;
    return result;
}

mfloat_t *quat_negative(mfloat_t *result, const mfloat_t *q0) {
    result[0] = -q0[0];
    result[1] = -q0[1];
    result[2] = -q0[2];
    result[3] = -q0[3];
    return result;
}

mfloat_t *quat_conjugate(mfloat_t *result, const mfloat_t *q0) {
    result[0] = -q0[0];
    result[1] = -q0[1];
    result[2] = -q0[2];
    result[3] = q0[3];
    return result;
}

mfloat_t *quat_inverse(mfloat_t *result, const mfloat_t *q0) {
    mfloat_t l = MFLOAT_C(1.0) / (q0[0] * q0[0] + q0[1] * q0[1] + q0[2] * q0[2] + q0[3] * q0[3]);
    result[0] = -q0[0] * l;
    result[1] = -q0[1] * l;
    result[2] = -q0[2] * l;
    result[3] = q0[3] * l;
    return result;
}

mfloat_t *quat_normalize(mfloat_t *result, const mfloat_t *q0) {
    mfloat_t l = MFLOAT_C(1.0) / MSQRT(q0[0] * q0[0] + q0[1] * q0[1] + q0[2] * q0[2] + q0[3] * q0[3]);
    result[0] = q0[0] * l;
    result[1] = q0[1] * l;
    result[2] = q0[2] * l;
    result[3] = q0[3] * l;
    return result;
}

mfloat_t quat_dot(const mfloat_t *q0, const mfloat_t *q1) {
    return q0[0] * q1[0] + q0[1] * q1[1] + q0[2] * q1[2] + q0[3] * q1[3];
}

mfloat_t *quat_power(mfloat_t *result, const mfloat_t *q0, mfloat_t exponent) {
    if (MFABS(q0[3]) < MFLOAT_C(1.0) - MFLT_EPSILON) {
        mfloat_t alpha = MACOS(q0[3]);
        mfloat_t new_alpha = alpha * exponent;
        mfloat_t s = MSIN(new_alpha) / MSIN(alpha);
        result[0] = result[0] * s;
        result[1] = result[1] * s;
        result[2] = result[2] * s;
        result[3] = MCOS(new_alpha);
    } else {
        memcpy(result, q0, sizeof(mfloat_t) * QUAT_SIZE);
    }
    return result;
}

mfloat_t *quat_from_axis_angle(mfloat_t *result, const mfloat_t *v0, mfloat_t angle) {
    mfloat_t half = angle * MFLOAT_C(0.5);
    mfloat_t s = MSIN(half);
    result[0] = v0[0] * s;
    result[1] = v0[1] * s;
    result[2] = v0[2] * s;
    result[3] = MCOS(half);
    return result;
}

mfloat_t *quat_from_vec3(mfloat_t *result, const mfloat_t *v0, const mfloat_t *v1) {
    mfloat_t cross[VEC3_SIZE];
    mfloat_t d = vec3_dot(v0, v1);
    mfloat_t a_ls = vec3_length_squared(v0);
    mfloat_t b_ls = vec3_length_squared(v0);
    vec3_cross(cross, v0, v1);
    quat(result, cross[0], cross[1], cross[1], d + MSQRT(a_ls * b_ls));
    quat_normalize(result, result);
    return result;
}

mfloat_t *quat_from_mat4(mfloat_t *result, const mfloat_t *m0) {
    mfloat_t scale = m0[0] + m0[5] + m0[10];
    if (scale > MFLOAT_C(0.0)) {
        mfloat_t sr = MSQRT(scale + MFLOAT_C(1.0));
        result[3] = sr * MFLOAT_C(0.5);
        sr = MFLOAT_C(0.5) / sr;
        result[0] = (m0[9] - m0[6]) * sr;
        result[1] = (m0[2] - m0[8]) * sr;
        result[2] = (m0[4] - m0[1]) * sr;
    } else if ((m0[0] >= m0[5]) && (m0[0] >= m0[10])) {
        mfloat_t sr = MSQRT(MFLOAT_C(1.0) + m0[0] - m0[5] - m0[10]);
        mfloat_t half = MFLOAT_C(0.5) / sr;
        result[0] = MFLOAT_C(0.5) * sr;
        result[1] = (m0[4] + m0[1]) * half;
        result[2] = (m0[8] + m0[2]) * half;
        result[3] = (m0[9] - m0[6]) * half;
    } else if (m0[5] > m0[10]) {
        mfloat_t sr = MSQRT(MFLOAT_C(1.0) + m0[5] - m0[0] - m0[10]);
        mfloat_t half = MFLOAT_C(0.5) / sr;
        result[0] = (m0[1] + m0[4]) * half;
        result[1] = MFLOAT_C(0.5) * sr;
        result[2] = (m0[6] + m0[9]) * half;
        result[3] = (m0[2] - m0[8]) * half;
    } else {
        mfloat_t sr = MSQRT(MFLOAT_C(1.0) + m0[10] - m0[0] - m0[5]);
        mfloat_t half = MFLOAT_C(0.5) / sr;
        result[0] = (m0[2] + m0[8]) * half;
        result[1] = (m0[6] + m0[9]) * half;
        result[2] = MFLOAT_C(0.5) * sr;
        result[3] = (m0[4] - m0[1]) * half;
    }
    return result;
}

mfloat_t *quat_lerp(mfloat_t *result, const mfloat_t *q0, const mfloat_t *q1, mfloat_t f) {
    result[0] = q0[0] + (q1[0] - q0[0]) * f;
    result[1] = q0[1] + (q1[1] - q0[1]) * f;
    result[2] = q0[2] + (q1[2] - q0[2]) * f;
    result[3] = q0[3] + (q1[3] - q0[3]) * f;
    return result;
}

mfloat_t *quat_slerp(mfloat_t *result, const mfloat_t *q0, const mfloat_t *q1, mfloat_t f) {
    mfloat_t tmp1[QUAT_SIZE];
    mfloat_t d = quat_dot(q0, q1);
    mfloat_t f0;
    mfloat_t f1;
    quat_assign(tmp1, q1);
    if (d < MFLOAT_C(0.0)) {
        quat_negative(tmp1, tmp1);
        d = -d;
    }
    if (d > MFLOAT_C(0.9995)) {
        f0 = MFLOAT_C(1.0) - f;
        f1 = f;
    } else {
        mfloat_t theta = MACOS(d);
        mfloat_t sin_theta = MSIN(theta);
        f0 = MSIN((MFLOAT_C(1.0) - f) * theta) / sin_theta;
        f1 = MSIN(f * theta) / sin_theta;
    }
    result[0] = q0[0] * f0 + tmp1[0] * f1;
    result[1] = q0[1] * f0 + tmp1[1] * f1;
    result[2] = q0[2] * f0 + tmp1[2] * f1;
    result[3] = q0[3] * f0 + tmp1[3] * f1;
    return result;
}

mfloat_t quat_length(const mfloat_t *q0) {
    return MSQRT(q0[0] * q0[0] + q0[1] * q0[1] + q0[2] * q0[2] + q0[3] * q0[3]);
}

mfloat_t quat_length_squared(const mfloat_t *q0) {
    return q0[0] * q0[0] + q0[1] * q0[1] + q0[2] * q0[2] + q0[3] * q0[3];
}

mfloat_t quat_angle(const mfloat_t *q0, const mfloat_t *q1) {
    mfloat_t s = MSQRT(quat_length_squared(q0) * quat_length_squared(q1));
    s = MFLOAT_C(1.0) / s;
    return MACOS(quat_dot(q0, q1) * s);
}

#if defined(MATHC_USE_STRUCT_FUNCTIONS)
bool squat_is_zero(struct quat q0) {
    return quat_is_zero((const mfloat_t *)&q0);
}

bool squat_is_equal(struct quat q0, struct quat q1) {
    return quat_is_equal((const mfloat_t *)&q0, (const mfloat_t *)&q1);
}

struct quat squat(mfloat_t x, mfloat_t y, mfloat_t z, mfloat_t w) {
    struct quat result;
    quat((mfloat_t *)&result, x, y, z, w);
    return result;
}

struct quat squat_assign(struct quat q0) {
    struct quat result;
    quat_assign((mfloat_t *)&result, (const mfloat_t *)&q0);
    return result;
}

struct quat squat_zero(void) {
    struct quat result;
    quat_zero((mfloat_t *)&result);
    return result;
}

struct quat squat_null(void) {
    struct quat result;
    quat_null((mfloat_t *)&result);
    return result;
}

struct quat squat_multiply(struct quat q0, struct quat q1) {
    struct quat result;
    quat_multiply((mfloat_t *)&result, (const mfloat_t *)&q0, (const mfloat_t *)&q1);
    return result;
}

struct quat squat_multiply_f(struct quat q0, mfloat_t f) {
    struct quat result;
    quat_multiply_f((mfloat_t *)&result, (const mfloat_t *)&q0, f);
    return result;
}

struct quat squat_divide(struct quat q0, struct quat q1) {
    struct quat result;
    quat_divide((mfloat_t *)&result, (const mfloat_t *)&q0, (const mfloat_t *)&q1);
    return result;
}

struct quat squat_divide_f(struct quat q0, mfloat_t f) {
    struct quat result;
    quat_divide_f((mfloat_t *)&result, (const mfloat_t *)&q0, f);
    return result;
}

struct quat squat_negative(struct quat q0) {
    struct quat result;
    quat_negative((mfloat_t *)&result, (const mfloat_t *)&q0);
    return result;
}

struct quat squat_conjugate(struct quat q0) {
    struct quat result;
    quat_conjugate((mfloat_t *)&result, (const mfloat_t *)&q0);
    return result;
}

struct quat squat_inverse(struct quat q0) {
    struct quat result;
    quat_inverse((mfloat_t *)&result, (const mfloat_t *)&q0);
    return result;
}

struct quat squat_normalize(struct quat q0) {
    struct quat result;
    quat_normalize((mfloat_t *)&result, (const mfloat_t *)&q0);
    return result;
}

mfloat_t squat_dot(struct quat q0, struct quat q1) {
    return quat_dot((const mfloat_t *)&q0, (const mfloat_t *)&q1);
}

struct quat squat_power(struct quat q0, mfloat_t exponent) {
    struct quat result;
    quat_power((mfloat_t *)&result, (const mfloat_t *)&q0, exponent);
    return result;
}

struct quat squat_from_axis_angle(struct vec3 v0, mfloat_t angle) {
    struct quat result;
    quat_from_axis_angle((mfloat_t *)&result, (const mfloat_t *)&v0, angle);
    return result;
}

struct quat squat_from_vec3(struct vec3 v0, struct vec3 v1) {
    struct quat result;
    quat_from_vec3((mfloat_t *)&result, (const mfloat_t *)&v0, (const mfloat_t *)&v1);
    return result;
}

struct quat squat_from_mat4(struct mat4 m0) {
    struct quat result;
    quat_from_mat4((mfloat_t *)&result, (const mfloat_t *)&m0);
    return result;
}

struct quat squat_lerp(struct quat q0, struct quat q1, mfloat_t f) {
    struct quat result;
    quat_lerp((mfloat_t *)&result, (const mfloat_t *)&q0, (const mfloat_t *)&q1, f);
    return result;
}

struct quat squat_slerp(struct quat q0, struct quat q1, mfloat_t f) {
    struct quat result;
    quat_slerp((mfloat_t *)&result, (const mfloat_t *)&q0, (const mfloat_t *)&q1, f);
    return result;
}

mfloat_t squat_length(struct quat q0) {
    return quat_length((const mfloat_t *)&q0);
}

mfloat_t squat_length_squared(struct quat q0) {
    return quat_length_squared((const mfloat_t *)&q0);
}

mfloat_t squat_angle(struct quat q0, struct quat q1) {
    return quat_angle((const mfloat_t *)&q0, (const mfloat_t *)&q1);
}
#endif

#if defined(MATHC_USE_POINTER_STRUCT_FUNCTIONS)
bool psquat_is_zero(const struct quat *q0) {
    return quat_is_zero((const mfloat_t *)q0);
}

bool psquat_is_equal(const struct quat *q0, const struct quat *q1) {
    return quat_is_equal((const mfloat_t *)q0, (const mfloat_t *)q1);
}

struct quat *psquat(struct quat *result, mfloat_t x, mfloat_t y, mfloat_t z, mfloat_t w) {
    return (struct quat *)quat((mfloat_t *)result, x, y, z, w);
}

struct quat *psquat_assign(struct quat *result, const struct quat *q0) {
    return (struct quat *)quat_assign((mfloat_t *)result, (const mfloat_t *)q0);
}

struct quat *psquat_zero(struct quat *result) {
    return (struct quat *)quat_zero((mfloat_t *)result);
}

struct quat *psquat_null(struct quat *result) {
    return (struct quat *)quat_null((mfloat_t *)result);
}

struct quat *psquat_multiply(struct quat *result, const struct quat *q0, const struct quat *q1) {
    return (struct quat *)quat_multiply((mfloat_t *)result, (const mfloat_t *)q0, (const mfloat_t *)q1);
}

struct quat *psquat_multiply_f(struct quat *result, const struct quat *q0, mfloat_t f) {
    return (struct quat *)quat_multiply_f((mfloat_t *)result, (const mfloat_t *)q0, f);
}

struct quat *psquat_divide(struct quat *result, const struct quat *q0, const struct quat *q1) {
    return (struct quat *)quat_divide((mfloat_t *)result, (const mfloat_t *)q0, (const mfloat_t *)q1);
}

struct quat *psquat_divide_f(struct quat *result, const struct quat *q0, mfloat_t f) {
    return (struct quat *)quat_divide_f((mfloat_t *)result, (const mfloat_t *)q0, f);
}

struct quat *psquat_negative(struct quat *result, const struct quat *q0) {
    return (struct quat *)quat_negative((mfloat_t *)result, (const mfloat_t *)q0);
}

struct quat *psquat_conjugate(struct quat *result, const struct quat *q0) {
    return (struct quat *)quat_conjugate((mfloat_t *)result, (const mfloat_t *)q0);
}

struct quat *psquat_inverse(struct quat *result, const struct quat *q0) {
    return (struct quat *)quat_inverse((mfloat_t *)result, (const mfloat_t *)q0);
}

struct quat *psquat_normalize(struct quat *result, const struct quat *q0) {
    return (struct quat *)quat_normalize((mfloat_t *)result, (const mfloat_t *)q0);
}

mfloat_t psquat_dot(const struct quat *q0, const struct quat *q1) {
    return quat_dot((const mfloat_t *)q0, (const mfloat_t *)q1);
}

struct quat *psquat_power(struct quat *result, const struct quat *q0, mfloat_t exponent) {
    return (struct quat *)quat_power((mfloat_t *)result, (const mfloat_t *)q0, exponent);
}

struct quat *psquat_from_axis_angle(struct quat *result, const struct vec3 *v0, mfloat_t angle) {
    return (struct quat *)quat_from_axis_angle((mfloat_t *)result, (const mfloat_t *)v0, angle);
}

struct quat *psquat_from_vec3(struct quat *result, const struct vec3 *v0, struct vec3 *v1) {
    return (struct quat *)quat_from_vec3((mfloat_t *)result, (const mfloat_t *)v0, (const mfloat_t *)v1);
}

struct quat *psquat_from_mat4(struct quat *result, const struct mat4 *m0) {
    return (struct quat *)quat_from_mat4((mfloat_t *)result, (const mfloat_t *)m0);
}

struct quat *psquat_lerp(struct quat *result, const struct quat *q0, const struct quat *q1, mfloat_t f) {
    return (struct quat *)quat_lerp((mfloat_t *)result, (const mfloat_t *)q0, (const mfloat_t *)q1, f);
}

struct quat *psquat_slerp(struct quat *result, const struct quat *q0, const struct quat *q1, mfloat_t f) {
    return (struct quat *)quat_slerp((mfloat_t *)result, (const mfloat_t *)q0, (const mfloat_t *)q1, f);
}

mfloat_t psquat_length(const struct quat *q0) {
    return quat_length((const mfloat_t *)q0);
}

mfloat_t psquat_length_squared(const struct quat *q0) {
    return quat_length_squared((const mfloat_t *)q0);
}

mfloat_t psquat_angle(const struct quat *q0, const struct quat *q1) {
    return quat_angle((const mfloat_t *)q0, (const mfloat_t *)q1);
}
#endif
#endif