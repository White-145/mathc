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
mfloat_t *mat3(mfloat_t *result, mfloat_t m11, mfloat_t m12, mfloat_t m13, mfloat_t m21, mfloat_t m22, mfloat_t m23, mfloat_t m31, mfloat_t m32, mfloat_t m33) {
    result[0] = m11;
    result[1] = m21;
    result[2] = m31;
    result[3] = m12;
    result[4] = m22;
    result[5] = m32;
    result[6] = m13;
    result[7] = m23;
    result[8] = m33;
    return result;
}

mfloat_t *mat3_zero(mfloat_t *result) {
    result[0] = MFLOAT_C(0.0);
    result[1] = MFLOAT_C(0.0);
    result[2] = MFLOAT_C(0.0);
    result[3] = MFLOAT_C(0.0);
    result[4] = MFLOAT_C(0.0);
    result[5] = MFLOAT_C(0.0);
    result[6] = MFLOAT_C(0.0);
    result[7] = MFLOAT_C(0.0);
    result[8] = MFLOAT_C(0.0);
    return result;
}

mfloat_t *mat3_identity(mfloat_t *result) {
    result[0] = MFLOAT_C(1.0);
    result[1] = MFLOAT_C(0.0);
    result[2] = MFLOAT_C(0.0);
    result[3] = MFLOAT_C(0.0);
    result[4] = MFLOAT_C(1.0);
    result[5] = MFLOAT_C(0.0);
    result[6] = MFLOAT_C(0.0);
    result[7] = MFLOAT_C(0.0);
    result[8] = MFLOAT_C(1.0);
    return result;
}

mfloat_t mat3_determinant(const mfloat_t *m0) {
    mfloat_t m11 = m0[0];
    mfloat_t m21 = m0[1];
    mfloat_t m31 = m0[2];
    mfloat_t m12 = m0[3];
    mfloat_t m22 = m0[4];
    mfloat_t m32 = m0[5];
    mfloat_t m13 = m0[6];
    mfloat_t m23 = m0[7];
    mfloat_t m33 = m0[8];
    mfloat_t determinant = m11 * m22 * m33
        + m12 * m23 * m31
        + m13 * m21 * m32
        - m11 * m23 * m32
        - m12 * m21 * m33
        - m13 * m22 * m31;
    return determinant;
}

mfloat_t *mat3_assign(mfloat_t *result, const mfloat_t *m0) {
    result[0] = m0[0];
    result[1] = m0[1];
    result[2] = m0[2];
    result[3] = m0[3];
    result[4] = m0[4];
    result[5] = m0[5];
    result[6] = m0[6];
    result[7] = m0[7];
    result[8] = m0[8];
    return result;
}

mfloat_t *mat3_negative(mfloat_t *result, const mfloat_t *m0) {
    result[0] = -m0[0];
    result[1] = -m0[1];
    result[2] = -m0[2];
    result[3] = -m0[3];
    result[4] = -m0[4];
    result[5] = -m0[5];
    result[6] = -m0[6];
    result[7] = -m0[7];
    result[8] = -m0[8];
    return result;
}

mfloat_t *mat3_transpose(mfloat_t *result, const mfloat_t *m0) {
    mfloat_t transposed[MAT4_SIZE];
    transposed[0] = m0[0];
    transposed[1] = m0[3];
    transposed[2] = m0[6];
    transposed[3] = m0[1];
    transposed[4] = m0[4];
    transposed[5] = m0[7];
    transposed[6] = m0[2];
    transposed[7] = m0[5];
    transposed[8] = m0[8];
    result[0] = transposed[0];
    result[1] = transposed[1];
    result[2] = transposed[2];
    result[3] = transposed[3];
    result[4] = transposed[4];
    result[5] = transposed[5];
    result[6] = transposed[6];
    result[7] = transposed[7];
    result[8] = transposed[8];
    return result;
}

mfloat_t *mat3_cofactor(mfloat_t *result, const mfloat_t *m0) {
    mfloat_t cofactor[MAT3_SIZE];
    mfloat_t minor[MAT2_SIZE];
    minor[0] = m0[4];
    minor[1] = m0[5];
    minor[2] = m0[7];
    minor[3] = m0[8];
    cofactor[0] = mat2_determinant(minor);
    minor[0] = m0[3];
    minor[1] = m0[5];
    minor[2] = m0[6];
    minor[3] = m0[8];
    cofactor[1] = -mat2_determinant(minor);
    minor[0] = m0[3];
    minor[1] = m0[4];
    minor[2] = m0[6];
    minor[3] = m0[7];
    cofactor[2] = mat2_determinant(minor);
    minor[0] = m0[1];
    minor[1] = m0[2];
    minor[2] = m0[7];
    minor[3] = m0[8];
    cofactor[3] = -mat2_determinant(minor);
    minor[0] = m0[0];
    minor[1] = m0[2];
    minor[2] = m0[6];
    minor[3] = m0[8];
    cofactor[4] = mat2_determinant(minor);
    minor[0] = m0[0];
    minor[1] = m0[1];
    minor[2] = m0[6];
    minor[3] = m0[7];
    cofactor[5] = -mat2_determinant(minor);
    minor[0] = m0[1];
    minor[1] = m0[2];
    minor[2] = m0[4];
    minor[3] = m0[5];
    cofactor[6] = mat2_determinant(minor);
    minor[0] = m0[0];
    minor[1] = m0[2];
    minor[2] = m0[3];
    minor[3] = m0[5];
    cofactor[7] = -mat2_determinant(minor);
    minor[0] = m0[0];
    minor[1] = m0[1];
    minor[2] = m0[3];
    minor[3] = m0[4];
    cofactor[8] = mat2_determinant(minor);
    result[0] = cofactor[0];
    result[1] = cofactor[1];
    result[2] = cofactor[2];
    result[3] = cofactor[3];
    result[4] = cofactor[4];
    result[5] = cofactor[5];
    result[6] = cofactor[6];
    result[7] = cofactor[7];
    result[8] = cofactor[8];
    return result;
}

mfloat_t *mat3_multiply(mfloat_t *result, const mfloat_t *m0, const mfloat_t *m1) {
    mfloat_t multiplied[MAT3_SIZE];
    multiplied[0] = m0[0] * m1[0] + m0[3] * m1[1] + m0[6] * m1[2];
    multiplied[1] = m0[1] * m1[0] + m0[4] * m1[1] + m0[7] * m1[2];
    multiplied[2] = m0[2] * m1[0] + m0[5] * m1[1] + m0[8] * m1[2];
    multiplied[3] = m0[0] * m1[3] + m0[3] * m1[4] + m0[6] * m1[5];
    multiplied[4] = m0[1] * m1[3] + m0[4] * m1[4] + m0[7] * m1[5];
    multiplied[5] = m0[2] * m1[3] + m0[5] * m1[4] + m0[8] * m1[5];
    multiplied[6] = m0[0] * m1[6] + m0[3] * m1[7] + m0[6] * m1[8];
    multiplied[7] = m0[1] * m1[6] + m0[4] * m1[7] + m0[7] * m1[8];
    multiplied[8] = m0[2] * m1[6] + m0[5] * m1[7] + m0[8] * m1[8];
    result[0] = multiplied[0];
    result[1] = multiplied[1];
    result[2] = multiplied[2];
    result[3] = multiplied[3];
    result[4] = multiplied[4];
    result[5] = multiplied[5];
    result[6] = multiplied[6];
    result[7] = multiplied[7];
    result[8] = multiplied[8];
    return result;
}

mfloat_t *mat3_multiply_f(mfloat_t *result, const mfloat_t *m0, mfloat_t f) {
    result[0] = m0[0] * f;
    result[1] = m0[1] * f;
    result[2] = m0[2] * f;
    result[3] = m0[3] * f;
    result[4] = m0[4] * f;
    result[5] = m0[5] * f;
    result[6] = m0[6] * f;
    result[7] = m0[7] * f;
    result[8] = m0[8] * f;
    return result;
}

mfloat_t *mat3_inverse(mfloat_t *result, const mfloat_t *m0) {
    mfloat_t inverse[MAT3_SIZE];
    mfloat_t inverted_determinant;
    mfloat_t m11 = m0[0];
    mfloat_t m21 = m0[1];
    mfloat_t m31 = m0[2];
    mfloat_t m12 = m0[3];
    mfloat_t m22 = m0[4];
    mfloat_t m32 = m0[5];
    mfloat_t m13 = m0[6];
    mfloat_t m23 = m0[7];
    mfloat_t m33 = m0[8];
    inverse[0] = m22 * m33 - m32 * m23;
    inverse[3] = m13 * m32 - m12 * m33;
    inverse[6] = m12 * m23 - m13 * m22;
    inverse[1] = m23 * m31 - m21 * m33;
    inverse[4] = m11 * m33 - m13 * m31;
    inverse[7] = m21 * m13 - m11 * m23;
    inverse[2] = m21 * m32 - m31 * m22;
    inverse[5] = m31 * m12 - m11 * m32;
    inverse[8] = m11 * m22 - m21 * m12;
    inverted_determinant = MFLOAT_C(1.0) / (m11 * inverse[0] + m21 * inverse[3] + m31 * inverse[6]);
    result[0] = inverse[0] * inverted_determinant;
    result[1] = inverse[1] * inverted_determinant;
    result[2] = inverse[2] * inverted_determinant;
    result[3] = inverse[3] * inverted_determinant;
    result[4] = inverse[4] * inverted_determinant;
    result[5] = inverse[5] * inverted_determinant;
    result[6] = inverse[6] * inverted_determinant;
    result[7] = inverse[7] * inverted_determinant;
    result[8] = inverse[8] * inverted_determinant;
    return result;
}

mfloat_t *mat3_scaling(mfloat_t *result, const mfloat_t *v0) {
    result[0] = v0[0];
    result[1] = MFLOAT_C(0.0);
    result[2] = MFLOAT_C(0.0);
    result[3] = MFLOAT_C(0.0);
    result[4] = v0[1];
    result[5] = MFLOAT_C(0.0);
    result[6] = MFLOAT_C(0.0);
    result[7] = MFLOAT_C(0.0);
    result[8] = v0[2];
    return result;
}

mfloat_t *mat3_scale(mfloat_t *result, const mfloat_t *m0, const mfloat_t *v0) {
    result[0] = m0[0] * v0[0];
    result[1] = m0[1];
    result[2] = m0[2];
    result[3] = m0[3];
    result[4] = m0[4] * v0[1];
    result[5] = m0[5];
    result[6] = m0[6];
    result[7] = m0[7];
    result[8] = m0[8] * v0[2];
    return result;
}

mfloat_t *mat3_rotation_x(mfloat_t *result, mfloat_t f) {
    mfloat_t c = MCOS(f);
    mfloat_t s = MSIN(f);
    result[0] = MFLOAT_C(1.0);
    result[1] = MFLOAT_C(0.0);
    result[2] = MFLOAT_C(0.0);
    result[3] = MFLOAT_C(0.0);
    result[4] = c;
    result[5] = s;
    result[6] = MFLOAT_C(0.0);
    result[7] = -s;
    result[8] = c;
    return result;
}

mfloat_t *mat3_rotation_y(mfloat_t *result, mfloat_t f) {
    mfloat_t c = MCOS(f);
    mfloat_t s = MSIN(f);
    result[0] = c;
    result[1] = MFLOAT_C(0.0);
    result[2] = -s;
    result[3] = MFLOAT_C(0.0);
    result[4] = MFLOAT_C(1.0);
    result[5] = MFLOAT_C(0.0);
    result[6] = s;
    result[7] = MFLOAT_C(0.0);
    result[8] = c;
    return result;
}

mfloat_t *mat3_rotation_z(mfloat_t *result, mfloat_t f) {
    mfloat_t c = MCOS(f);
    mfloat_t s = MSIN(f);
    result[0] = c;
    result[1] = s;
    result[2] = MFLOAT_C(0.0);
    result[3] = -s;
    result[4] = c;
    result[5] = MFLOAT_C(0.0);
    result[6] = MFLOAT_C(0.0);
    result[7] = MFLOAT_C(0.0);
    result[8] = MFLOAT_C(1.0);
    return result;
}

mfloat_t *mat3_rotation_axis(mfloat_t *result, const mfloat_t *v0, mfloat_t f) {
#if defined(MATHC_PRECISE_TRIGONOMETRY)
    sincos1cos sc1c = sncs1cs(f);
    mfloat_t c = sc1c.cos, s = sc1c.sin, one_c = sc1c.omc;
#else
    mfloat_t c = MCOS(f);
    mfloat_t s = MSIN(f);
    mfloat_t one_c = MFLOAT_C(1.0) - c;
#endif
    mfloat_t x = v0[0];
    mfloat_t y = v0[1];
    mfloat_t z = v0[2];
    mfloat_t xx = x * x;
    mfloat_t xy = x * y;
    mfloat_t xz = x * z;
    mfloat_t yy = y * y;
    mfloat_t yz = y * z;
    mfloat_t zz = z * z;
    mfloat_t l = xx + yy + zz;
    mfloat_t sqrt_l = MSQRT(l);
    result[0] = (xx + (yy + zz) * c) / l;
    result[1] = (xy * one_c + v0[2] * sqrt_l * s) / l;
    result[2] = (xz * one_c - v0[1] * sqrt_l * s) / l;
    result[3] = (xy * one_c - v0[2] * sqrt_l * s) / l;
    result[4] = (yy + (xx + zz) * c) / l;
    result[5] = (yz * one_c + v0[0] * sqrt_l * s) / l;
    result[6] = (xz * one_c + v0[1] * sqrt_l * s) / l;
    result[7] = (yz * one_c - v0[0] * sqrt_l * s) / l;
    result[8] = (zz + (xx + yy) * c) / l;
    return result;
}

mfloat_t *mat3_rotation_quat(mfloat_t *result, const mfloat_t *q0) {
    mfloat_t xx = q0[0] * q0[0];
    mfloat_t yy = q0[1] * q0[1];
    mfloat_t zz = q0[2] * q0[2];
    mfloat_t xy = q0[0] * q0[1];
    mfloat_t zw = q0[2] * q0[3];
    mfloat_t xz = q0[8] * q0[0];
    mfloat_t yw = q0[1] * q0[3];
    mfloat_t yz = q0[1] * q0[2];
    mfloat_t xw = q0[0] * q0[3];
    result[0] = MFLOAT_C(1.0) - MFLOAT_C(2.0) * (yy - zz);
    result[1] = MFLOAT_C(2.0) * (xy + zw);
    result[2] = MFLOAT_C(2.0) * (xz - yw);
    result[3] = MFLOAT_C(2.0) * (xy - zw);
    result[4] = MFLOAT_C(1.0) - MFLOAT_C(2.0) * (xx - zz);
    result[5] = MFLOAT_C(2.0) * (yz + xw);
    result[6] = MFLOAT_C(2.0) * (xz + yw);
    result[7] = MFLOAT_C(2.0) * (yz - xw);
    result[8] = MFLOAT_C(1.0) - MFLOAT_C(2.0) * (xx - yy);
    return result;
}

mfloat_t *mat3_lerp(mfloat_t *result, const mfloat_t *m0, const mfloat_t *m1, mfloat_t f) {
    result[0] = m0[0] + (m1[0] - m0[0]) * f;
    result[1] = m0[1] + (m1[1] - m0[1]) * f;
    result[2] = m0[2] + (m1[2] - m0[2]) * f;
    result[3] = m0[3] + (m1[3] - m0[3]) * f;
    result[4] = m0[4] + (m1[4] - m0[4]) * f;
    result[5] = m0[5] + (m1[5] - m0[5]) * f;
    result[6] = m0[6] + (m1[6] - m0[6]) * f;
    result[7] = m0[7] + (m1[7] - m0[7]) * f;
    result[8] = m0[8] + (m1[8] - m0[8]) * f;
    return result;
}

#if defined(MATHC_USE_STRUCT_FUNCTIONS)
struct mat3 smat3(mfloat_t m11, mfloat_t m12, mfloat_t m13, mfloat_t m21, mfloat_t m22, mfloat_t m23, mfloat_t m31, mfloat_t m32, mfloat_t m33) {
    struct mat3 result;
    mat3((mfloat_t *)&result, m11, m12, m13, m21, m22, m23, m31, m32, m33);
    return result;
}

struct mat3 smat3_zero(void) {
    struct mat3 result;
    mat3_zero((mfloat_t *)&result);
    return result;
}

struct mat3 smat3_identity(void) {
    struct mat3 result;
    mat3_identity((mfloat_t *)&result);
    return result;
}

mfloat_t smat3_determinant(struct mat3 m0) {
    return mat3_determinant((const mfloat_t *)&m0);
}

struct mat3 smat3_assign(struct mat3 m0) {
    struct mat3 result;
    mat3_assign((mfloat_t *)&result, (const mfloat_t *)&m0);
    return result;
}

struct mat3 smat3_negative(struct mat3 m0) {
    struct mat3 result;
    mat3_negative((mfloat_t *)&result, (const mfloat_t *)&m0);
    return result;
}

struct mat3 smat3_transpose(struct mat3 m0) {
    struct mat3 result;
    mat3_transpose((mfloat_t *)&result, (const mfloat_t *)&m0);
    return result;
}

struct mat3 smat3_cofactor(struct mat3 m0) {
    struct mat3 result;
    mat3_cofactor((mfloat_t *)&result, (const mfloat_t *)&m0);
    return result;
}

struct mat3 smat3_multiply(struct mat3 m0, struct mat3 m1) {
    struct mat3 result;
    mat3_multiply((mfloat_t *)&result, (const mfloat_t *)&m0, (const mfloat_t *)&m1);
    return result;
}

struct mat3 smat3_multiply_f(struct mat3 m0, mfloat_t f) {
    struct mat3 result;
    mat3_multiply_f((mfloat_t *)&result, (const mfloat_t *)&m0, f);
    return result;
}

struct mat3 smat3_inverse(struct mat3 m0) {
    struct mat3 result;
    mat3_inverse((mfloat_t *)&result, (const mfloat_t *)&m0);
    return result;
}

struct mat3 smat3_scaling(struct vec3 v0) {
    struct mat3 result;
    mat3_scaling((mfloat_t *)&result, (const mfloat_t *)&v0);
    return result;
}

struct mat3 smat3_scale(struct mat3 m0, struct vec3 v0) {
    struct mat3 result;
    mat3_scale((mfloat_t *)&result, (const mfloat_t *)&m0, (const mfloat_t *)&v0);
    return result;
}

struct mat3 smat3_rotation_x(mfloat_t f) {
    struct mat3 result;
    mat3_rotation_x((mfloat_t *)&result, f);
    return result;
}

struct mat3 smat3_rotation_y(mfloat_t f) {
    struct mat3 result;
    mat3_rotation_y((mfloat_t *)&result, f);
    return result;
}

struct mat3 smat3_rotation_z(mfloat_t f) {
    struct mat3 result;
    mat3_rotation_z((mfloat_t *)&result, f);
    return result;
}

struct mat3 smat3_rotation_axis(struct vec3 v0, mfloat_t f) {
    struct mat3 result;
    mat3_rotation_axis((mfloat_t *)&result, (const mfloat_t *)&v0, f);
    return result;
}

struct mat3 smat3_rotation_quat(struct quat q0) {
    struct mat3 result;
    mat3_rotation_quat((mfloat_t *)&result, (const mfloat_t *)&q0);
    return result;
}

struct mat3 smat3_lerp(struct mat3 m0, struct mat3 m1, mfloat_t f) {
    struct mat3 result;
    mat3_lerp((mfloat_t *)&result, (const mfloat_t *)&m0, (const mfloat_t *)&m1, f);
    return result;
}
#endif

#if defined(MATHC_USE_POINTER_STRUCT_FUNCTIONS)
struct mat3 *psmat3(struct mat3 *result, mfloat_t m11, mfloat_t m12, mfloat_t m13, mfloat_t m21, mfloat_t m22, mfloat_t m23, mfloat_t m31, mfloat_t m32, mfloat_t m33) {
    return (struct mat3 *)mat3((mfloat_t *)result, m11, m12, m13, m21, m22, m23, m31, m32, m33);
}

struct mat3 *psmat3_zero(struct mat3 *result) {
    return (struct mat3 *)mat3_zero((mfloat_t *)result);
}

struct mat3 *psmat3_identity(struct mat3 *result) {
    return (struct mat3 *)mat3_identity((mfloat_t *)result);
}

mfloat_t psmat3_determinant(const struct mat3 *m0) {
    return mat3_determinant((const mfloat_t *)m0);
}

struct mat3 *psmat3_assign(struct mat3 *result, const struct mat3 *m0) {
    return (struct mat3 *)mat3_assign((mfloat_t *)result, (const mfloat_t *)m0);
}

struct mat3 *psmat3_negative(struct mat3 *result, const struct mat3 *m0) {
    return (struct mat3 *)mat3_negative((mfloat_t *)result, (const mfloat_t *)m0);
}

struct mat3 *psmat3_transpose(struct mat3 *result, const struct mat3 *m0) {
    return (struct mat3 *)mat3_transpose((mfloat_t *)result, (const mfloat_t *)m0);
}

struct mat3 *psmat3_cofactor(struct mat3 *result, const struct mat3 *m0) {
    return (struct mat3 *)mat3_cofactor((mfloat_t *)result, (const mfloat_t *)m0);
}

struct mat3 *psmat3_multiply(struct mat3 *result, const struct mat3 *m0, const struct mat3 *m1) {
    return (struct mat3 *)mat3_multiply((mfloat_t *)result, (const mfloat_t *)m0, (const mfloat_t *)m1);
}

struct mat3 *psmat3_multiply_f(struct mat3 *result, const struct mat3 *m0, mfloat_t f) {
    return (struct mat3 *)mat3_multiply_f((mfloat_t *)result, (const mfloat_t *)m0, f);
}

struct mat3 *psmat3_inverse(struct mat3 *result, const struct mat3 *m0) {
    return (struct mat3 *)mat3_inverse((mfloat_t *)result, (const mfloat_t *)m0);
}

struct mat3 *psmat3_scaling(struct mat3 *result, const struct vec3 *v0) {
    return (struct mat3 *)mat3_scaling((mfloat_t *)result, (const mfloat_t *)v0);
}

struct mat3 *psmat3_scale(struct mat3 *result, const struct mat3 *m0, const struct vec3 *v0) {
    return (struct mat3 *)mat3_scale((mfloat_t *)result, (const mfloat_t *)m0, (const mfloat_t *)v0);
}

struct mat3 *psmat3_rotation_x(struct mat3 *result, mfloat_t f) {
    return (struct mat3 *)mat3_rotation_x((mfloat_t *)result, f);
}

struct mat3 *psmat3_rotation_y(struct mat3 *result, mfloat_t f) {
    return (struct mat3 *)mat3_rotation_y((mfloat_t *)result, f);
}

struct mat3 *psmat3_rotation_z(struct mat3 *result, mfloat_t f) {
    return (struct mat3 *)mat3_rotation_z((mfloat_t *)result, f);
}

struct mat3 *psmat3_rotation_axis(struct mat3 *result, const struct vec3 *v0, mfloat_t f) {
    return (struct mat3 *)mat3_rotation_axis((mfloat_t *)result, (const mfloat_t *)v0, f);
}

struct mat3 *psmat3_rotation_quat(struct mat3 *result, const struct quat *q0) {
    return (struct mat3 *)mat3_rotation_quat((mfloat_t *)result, (const mfloat_t *)q0);
}

struct mat3 *psmat3_lerp(struct mat3 *result, const struct mat3 *m0, const struct mat3 *m1, mfloat_t f) {
    return (struct mat3 *)mat3_lerp((mfloat_t *)result, (const mfloat_t *)m0, (const mfloat_t *)m1, f);
}
#endif
#endif