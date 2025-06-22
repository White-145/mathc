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
mfloat_t *mat2(mfloat_t *result, mfloat_t m11, mfloat_t m12, mfloat_t m21, mfloat_t m22) {
    result[0] = m11;
    result[1] = m21;
    result[2] = m12;
    result[3] = m22;
    return result;
}

mfloat_t *mat2_zero(mfloat_t *result) {
    result[0] = MZERO;
    result[1] = MZERO;
    result[2] = MZERO;
    result[3] = MZERO;
    return result;
}

mfloat_t *mat2_identity(mfloat_t *result) {
    result[0] = MONE;
    result[1] = MZERO;
    result[2] = MZERO;
    result[3] = MONE;
    return result;
}

mfloat_t mat2_determinant(const mfloat_t *m0) {
    return m0[0] * m0[3] - m0[2] * m0[1];
}

mfloat_t *mat2_assign(mfloat_t *result, const mfloat_t *m0) {
    result[0] = m0[0];
    result[1] = m0[1];
    result[2] = m0[2];
    result[3] = m0[3];
    return result;
}

mfloat_t *mat2_negative(mfloat_t *result, const mfloat_t *m0) {
    result[0] = -m0[0];
    result[1] = -m0[1];
    result[2] = -m0[2];
    result[3] = -m0[3];
    return result;
}

mfloat_t *mat2_transpose(mfloat_t *result, const mfloat_t *m0) {
    mfloat_t transposed[MAT2_SIZE];
    transposed[0] = m0[0];
    transposed[1] = m0[2];
    transposed[2] = m0[1];
    transposed[3] = m0[3];
    result[0] = transposed[0];
    result[1] = transposed[1];
    result[2] = transposed[2];
    result[3] = transposed[3];
    return result;
}

mfloat_t *mat2_cofactor(mfloat_t *result, const mfloat_t *m0) {
    mfloat_t cofactor[MAT2_SIZE];
    cofactor[0] = m0[3];
    cofactor[1] = -m0[2];
    cofactor[2] = -m0[1];
    cofactor[3] = m0[0];
    result[0] = cofactor[0];
    result[1] = cofactor[1];
    result[2] = cofactor[2];
    result[3] = cofactor[3];
    return result;
}

mfloat_t *mat2_adjugate(mfloat_t *result, const mfloat_t *m0) {
    mfloat_t adjugate[MAT2_SIZE];
    adjugate[0] = m0[3];
    adjugate[1] = -m0[1];
    adjugate[2] = -m0[2];
    adjugate[3] = m0[0];
    result[0] = adjugate[0];
    result[1] = adjugate[1];
    result[2] = adjugate[2];
    result[3] = adjugate[3];
    return result;
}

mfloat_t *mat2_add(mfloat_t *result, const mfloat_t *m0, const mfloat_t *m1) {
    result[0] = m0[0] + m1[0];
    result[1] = m0[1] + m1[1];
    result[2] = m0[2] + m1[2];
    result[3] = m0[3] + m1[3];
    return result;
}

mfloat_t *mat2_add_f(mfloat_t *result, const mfloat_t *m0, mfloat_t f) {
    result[0] = m0[0] + f;
    result[1] = m0[1] + f;
    result[2] = m0[2] + f;
    result[3] = m0[3] + f;
    return result;
}

mfloat_t *mat2_subtract(mfloat_t *result, const mfloat_t *m0, const mfloat_t *m1) {
    result[0] = m0[0] - m1[0];
    result[1] = m0[1] - m1[1];
    result[2] = m0[2] - m1[2];
    result[3] = m0[3] - m1[3];
    return result;
}

mfloat_t *mat2_subtract_f(mfloat_t *result, const mfloat_t *m0, mfloat_t f) {
    result[0] = m0[0] - f;
    result[1] = m0[1] - f;
    result[2] = m0[2] - f;
    result[3] = m0[3] - f;
    return result;
}

mfloat_t *mat2_multiply(mfloat_t *result, const mfloat_t *m0, const mfloat_t *m1) {
    mfloat_t multiplied[MAT3_SIZE];
    multiplied[0] = m0[0] * m1[0] + m0[2] * m1[1];
    multiplied[1] = m0[1] * m1[0] + m0[3] * m1[1];
    multiplied[2] = m0[0] * m1[2] + m0[2] * m1[3];
    multiplied[3] = m0[1] * m1[2] + m0[3] * m1[3];
    result[0] = multiplied[0];
    result[1] = multiplied[1];
    result[2] = multiplied[2];
    result[3] = multiplied[3];
    return result;
}

mfloat_t *mat2_multiply_f(mfloat_t *result, const mfloat_t *m0, mfloat_t f) {
    result[0] = m0[0] * f;
    result[1] = m0[1] * f;
    result[2] = m0[2] * f;
    result[3] = m0[3] * f;
    return result;
}

mfloat_t *mat2_inverse(mfloat_t *result, const mfloat_t *m0) {
    mfloat_t inverse[MAT2_SIZE];
    mfloat_t det = mat2_determinant(m0);
    mat2_cofactor(inverse, m0);
    mat2_multiply_f(inverse, inverse, MONE / det);
    result[0] = inverse[0];
    result[1] = inverse[1];
    result[2] = inverse[2];
    result[3] = inverse[3];
    return result;
}

mfloat_t *mat2_scaling(mfloat_t *result, const mfloat_t *v0) {
    result[0] = v0[0];
    result[1] = MZERO;
    result[2] = MZERO;
    result[3] = v0[1];
    return result;
}

mfloat_t *mat2_scale(mfloat_t *result, const mfloat_t *m0, const mfloat_t *v0) {
    result[0] = m0[0] * v0[0];
    result[0] = m0[1];
    result[0] = m0[2];
    result[3] = m0[3] * v0[1];
    return result;
}

mfloat_t *mat2_rotation_z(mfloat_t *result, mfloat_t f) {
    mfloat_t c = MCOS(f);
    mfloat_t s = MSIN(f);
    result[0] = c;
    result[1] = s;
    result[2] = -s;
    result[3] = c;
    return result;
}

mfloat_t *mat2_lerp(mfloat_t *result, const mfloat_t *m0, const mfloat_t *m1, mfloat_t f) {
    result[0] = m0[0] + (m1[0] - m0[0]) * f;
    result[1] = m0[1] + (m1[1] - m0[1]) * f;
    result[2] = m0[2] + (m1[2] - m0[2]) * f;
    result[3] = m0[3] + (m1[3] - m0[3]) * f;
    return result;
}

#if defined(MATHC_USE_STRUCT_FUNCTIONS)
struct mat2 smat2(mfloat_t m11, mfloat_t m12, mfloat_t m21, mfloat_t m22) {
    struct mat2 result;
    mat2((mfloat_t *)&result, m11, m12, m21, m22);
    return result;
}

struct mat2 smat2_zero(void) {
    struct mat2 result;
    mat2_zero((mfloat_t *)&result);
    return result;
}

struct mat2 smat2_identity(void) {
    struct mat2 result;
    mat2_identity((mfloat_t *)&result);
    return result;
}

mfloat_t smat2_determinant(struct mat2 m0) {
    return mat2_determinant((const mfloat_t *)&m0);
}

struct mat2 smat2_assign(struct mat2 m0) {
    struct mat2 result;
    mat2_assign((mfloat_t *)&result, (const mfloat_t *)&m0);
    return result;
}

struct mat2 smat2_negative(struct mat2 m0) {
    struct mat2 result;
    mat2_negative((mfloat_t *)&result, (const mfloat_t *)&m0);
    return result;
}

struct mat2 smat2_transpose(struct mat2 m0) {
    struct mat2 result;
    mat2_transpose((mfloat_t *)&result, (const mfloat_t *)&m0);
    return result;
}

struct mat2 smat2_cofactor(struct mat2 m0) {
    struct mat2 result;
    mat2_cofactor((mfloat_t *)&result, (const mfloat_t *)&m0);
    return result;
}

struct mat2 smat2_adjugate(struct mat2 m0) {
    struct mat2 result;
    mat2_adjugate((mfloat_t *)&result, (const mfloat_t *)&m0);
    return result;
}

struct mat2 smat2_add(struct mat2 m0, struct mat2 m1) {
    struct mat2 result;
    mat2_add((mfloat_t *)&result, (const mfloat_t *)&m0, (const mfloat_t *)&m1);
    return result;
}

struct mat2 smat2_add_f(struct mat2 m0, mfloat_t f) {
    struct mat2 result;
    mat2_add_f((mfloat_t *)&result, (const mfloat_t *)&m0, f);
    return result;
}

struct mat2 smat2_subtract(struct mat2 m0, struct mat2 m1) {
    struct mat2 result;
    mat2_subtract((mfloat_t *)&result, (const mfloat_t *)&m0, (const mfloat_t *)&m1);
    return result;
}

struct mat2 smat2_subtract_f(struct mat2 m0, mfloat_t f) {
    struct mat2 result;
    mat2_subtract_f((mfloat_t *)&result, (const mfloat_t *)&m0, f);
    return result;
}

struct mat2 smat2_multiply(struct mat2 m0, struct mat2 m1) {
    struct mat2 result;
    mat2_multiply((mfloat_t *)&result, (const mfloat_t *)&m0, (const mfloat_t *)&m1);
    return result;
}

struct mat2 smat2_multiply_f(struct mat2 m0, mfloat_t f) {
    struct mat2 result;
    mat2_multiply_f((mfloat_t *)&result, (const mfloat_t *)&m0, f);
    return result;
}

struct mat2 smat2_inverse(struct mat2 m0) {
    struct mat2 result;
    mat2_inverse((mfloat_t *)&result, (const mfloat_t *)&m0);
    return result;
}

struct mat2 smat2_scaling(struct vec2 v0) {
    struct mat2 result;
    mat2_identity((mfloat_t *)&result);
    mat2_scaling((mfloat_t *)&result, (const mfloat_t *)&v0);
    return result;
}

struct mat2 smat2_scale(struct mat2 m0, struct vec2 v0) {
    struct mat2 result;
    mat2_scale((mfloat_t *)&result, (const mfloat_t *)&m0, (const mfloat_t *)&v0);
    return result;
}

struct mat2 smat2_rotation_z(mfloat_t f) {
    struct mat2 result;
    mat2_rotation_z((mfloat_t *)&result, f);
    return result;
}

struct mat2 smat2_lerp(struct mat2 m0, struct mat2 m1, mfloat_t f) {
    struct mat2 result;
    mat2_lerp((mfloat_t *)&result, (const mfloat_t *)&m0, (const mfloat_t *)&m1, f);
    return result;
}
#endif

#if defined(MATHC_USE_POINTER_STRUCT_FUNCTIONS)
struct mat2 *psmat2(struct mat2 *result, mfloat_t m11, mfloat_t m12, mfloat_t m21, mfloat_t m22) {
    return (struct mat2 *)mat2((mfloat_t *)result, m11, m12, m21, m22);
}

struct mat2 *psmat2_zero(struct mat2 *result) {
    return (struct mat2 *)mat2_zero((mfloat_t *)result);
}

struct mat2 *psmat2_identity(struct mat2 *result) {
    return (struct mat2 *)mat2_identity((mfloat_t *)result);
}

mfloat_t psmat2_determinant(const struct mat2 *m0) {
    return mat2_determinant((const mfloat_t *)m0);
}

struct mat2 *psmat2_assign(struct mat2 *result, const struct mat2 *m0) {
    return (struct mat2 *)mat2_assign((mfloat_t *)result, (const mfloat_t *)m0);
}

struct mat2 *psmat2_negative(struct mat2 *result, const struct mat2 *m0) {
    return (struct mat2 *)mat2_negative((mfloat_t *)result, (const mfloat_t *)m0);
}

struct mat2 *psmat2_transpose(struct mat2 *result, const struct mat2 *m0) {
    return (struct mat2 *)mat2_transpose((mfloat_t *)result, (const mfloat_t *)m0);
}

struct mat2 *psmat2_cofactor(struct mat2 *result, const struct mat2 *m0) {
    return (struct mat2 *)mat2_cofactor((mfloat_t *)result, (const mfloat_t *)m0);
}

struct mat2 *psmat2_adjugate(struct mat2 *result, const struct mat2 *m0) {
    return (struct mat2 *)mat2_adjugate((mfloat_t *)result, (const mfloat_t *)m0);
}

struct mat2 *psmat2_add(struct mat2 *result, const struct mat2 *m0, const struct mat2 *m1) {
    return (struct mat2 *)mat2_add((mfloat_t *)result, (const mfloat_t *)m0, (const mfloat_t *)m1);
}

struct mat2 *psmat2_add_f(struct mat2 *result, const struct mat2 *m0, mfloat_t f) {
    return (struct mat2 *)mat2_add_f((mfloat_t *)result, (const mfloat_t *)m0, f);
}

struct mat2 *psmat2_subtract(struct mat2 *result, const struct mat2 *m0, const struct mat2 *m1) {
    return (struct mat2 *)mat2_subtract((mfloat_t *)result, (const mfloat_t *)m0, (const mfloat_t *)m1);
}

struct mat2 *psmat2_subtract_f(struct mat2 *result, const struct mat2 *m0, mfloat_t f) {
    return (struct mat2 *)mat2_subtract_f((mfloat_t *)result, (const mfloat_t *)m0, f);
}

struct mat2 *psmat2_multiply(struct mat2 *result, const struct mat2 *m0, const struct mat2 *m1) {
    return (struct mat2 *)mat2_multiply((mfloat_t *)result, (const mfloat_t *)m0, (const mfloat_t *)m1);
}

struct mat2 *psmat2_multiply_f(struct mat2 *result, const struct mat2 *m0, mfloat_t f) {
    return (struct mat2 *)mat2_multiply_f((mfloat_t *)result, (const mfloat_t *)m0, f);
}

struct mat2 *psmat2_inverse(struct mat2 *result, const struct mat2 *m0) {
    return (struct mat2 *)mat2_inverse((mfloat_t *)result, (const mfloat_t *)m0);
}

struct mat2 *psmat2_scaling(struct mat2 *result, struct vec2 *v0) {
    return (struct mat2 *)mat2_scaling((mfloat_t *)result, (const mfloat_t *)v0);
}

struct mat2 *psmat2_scale(struct mat2 *result, const struct mat2 *m0, struct vec2 *v0) {
    return (struct mat2 *)mat2_scale((mfloat_t *)result, (const mfloat_t *)m0, (const mfloat_t *)v0);
}

struct mat2 *psmat2_rotation_z(struct mat2 *result, mfloat_t f) {
    return (struct mat2 *)mat2_rotation_z((mfloat_t *)result, f);
}

struct mat2 *psmat2_lerp(struct mat2 *result, const struct mat2 *m0, const struct mat2 *m1, mfloat_t f) {
    return (struct mat2 *)mat2_lerp((mfloat_t *)result, (const mfloat_t *)m0, (const mfloat_t *)m1, f);
}
#endif
#endif