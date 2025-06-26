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
mfloat_t *mat4(mfloat_t *result, mfloat_t m11, mfloat_t m12, mfloat_t m13, mfloat_t m14, mfloat_t m21, mfloat_t m22, mfloat_t m23, mfloat_t m24, mfloat_t m31, mfloat_t m32, mfloat_t m33, mfloat_t m34, mfloat_t m41, mfloat_t m42, mfloat_t m43, mfloat_t m44) {
    result[0] = m11;
    result[1] = m21;
    result[2] = m31;
    result[3] = m41;
    result[4] = m12;
    result[5] = m22;
    result[6] = m32;
    result[7] = m42;
    result[8] = m13;
    result[9] = m23;
    result[10] = m33;
    result[11] = m43;
    result[12] = m14;
    result[13] = m24;
    result[14] = m34;
    result[15] = m44;
    return result;
}

mfloat_t *mat4_zero(mfloat_t *result) {
    result[0] = MZERO;
    result[1] = MZERO;
    result[2] = MZERO;
    result[3] = MZERO;
    result[4] = MZERO;
    result[5] = MZERO;
    result[6] = MZERO;
    result[7] = MZERO;
    result[8] = MZERO;
    result[9] = MZERO;
    result[10] = MZERO;
    result[11] = MZERO;
    result[12] = MZERO;
    result[13] = MZERO;
    result[14] = MZERO;
    result[15] = MZERO;
    return result;
}

mfloat_t *mat4_identity(mfloat_t *result) {
    result[0] = MONE;
    result[1] = MZERO;
    result[2] = MZERO;
    result[3] = MZERO;
    result[4] = MZERO;
    result[5] = MONE;
    result[6] = MZERO;
    result[7] = MZERO;
    result[8] = MZERO;
    result[9] = MZERO;
    result[10] = MONE;
    result[11] = MZERO;
    result[12] = MZERO;
    result[13] = MZERO;
    result[14] = MZERO;
    result[15] = MONE;
    return result;
}

mfloat_t mat4_determinant(const mfloat_t *m0) {
    mfloat_t m11 = m0[0];
    mfloat_t m21 = m0[1];
    mfloat_t m31 = m0[2];
    mfloat_t m41 = m0[3];
    mfloat_t m12 = m0[4];
    mfloat_t m22 = m0[5];
    mfloat_t m32 = m0[6];
    mfloat_t m42 = m0[7];
    mfloat_t m13 = m0[8];
    mfloat_t m23 = m0[9];
    mfloat_t m33 = m0[10];
    mfloat_t m43 = m0[11];
    mfloat_t m14 = m0[12];
    mfloat_t m24 = m0[13];
    mfloat_t m34 = m0[14];
    mfloat_t m44 = m0[15];
    mfloat_t determinant = m14 * m23 * m32 * m41 - m13 * m24 * m32 * m41
        - m14 * m22 * m33 * m41 + m12 * m24 * m33 * m41
        + m13 * m22 * m34 * m41 - m12 * m23 * m34 * m41
        - m14 * m23 * m31 * m42 + m13 * m24 * m31 * m42
        + m14 * m21 * m33 * m42 - m11 * m24 * m33 * m42
        - m13 * m21 * m34 * m42 + m11 * m23 * m34 * m42
        + m14 * m22 * m31 * m43 - m12 * m24 * m31 * m43
        - m14 * m21 * m32 * m43 + m11 * m24 * m32 * m43
        + m12 * m21 * m34 * m43 - m11 * m22 * m34 * m43
        - m13 * m22 * m31 * m44 + m12 * m23 * m31 * m44
        + m13 * m21 * m32 * m44 - m11 * m23 * m32 * m44
        - m12 * m21 * m33 * m44 + m11 * m22 * m33 * m44;
    return determinant;
}

mfloat_t *mat4_assign(mfloat_t *result, const mfloat_t *m0) {
    result[0] = m0[0];
    result[1] = m0[1];
    result[2] = m0[2];
    result[3] = m0[3];
    result[4] = m0[4];
    result[5] = m0[5];
    result[6] = m0[6];
    result[7] = m0[7];
    result[8] = m0[8];
    result[9] = m0[9];
    result[10] = m0[10];
    result[11] = m0[11];
    result[12] = m0[12];
    result[13] = m0[13];
    result[14] = m0[14];
    result[15] = m0[15];
    return result;
}

mfloat_t *mat4_negative(mfloat_t *result, const mfloat_t *m0) {
    result[0] = -m0[0];
    result[1] = -m0[1];
    result[2] = -m0[2];
    result[3] = -m0[3];
    result[4] = -m0[4];
    result[5] = -m0[5];
    result[6] = -m0[6];
    result[7] = -m0[7];
    result[8] = -m0[8];
    result[9] = -m0[9];
    result[10] = -m0[10];
    result[11] = -m0[11];
    result[12] = -m0[12];
    result[13] = -m0[13];
    result[14] = -m0[14];
    result[15] = -m0[15];
    return result;
}

mfloat_t *mat4_transpose(mfloat_t *result, const mfloat_t *m0) {
    mfloat_t transposed[MAT4_SIZE];
    transposed[0] = m0[0];
    transposed[1] = m0[4];
    transposed[2] = m0[8];
    transposed[3] = m0[12];
    transposed[4] = m0[1];
    transposed[5] = m0[5];
    transposed[6] = m0[9];
    transposed[7] = m0[13];
    transposed[8] = m0[2];
    transposed[9] = m0[6];
    transposed[10] = m0[10];
    transposed[11] = m0[14];
    transposed[12] = m0[3];
    transposed[13] = m0[7];
    transposed[14] = m0[11];
    transposed[15] = m0[15];
    result[0] = transposed[0];
    result[1] = transposed[1];
    result[2] = transposed[2];
    result[3] = transposed[3];
    result[4] = transposed[4];
    result[5] = transposed[5];
    result[6] = transposed[6];
    result[7] = transposed[7];
    result[8] = transposed[8];
    result[9] = transposed[9];
    result[10] = transposed[10];
    result[11] = transposed[11];
    result[12] = transposed[12];
    result[13] = transposed[13];
    result[14] = transposed[14];
    result[15] = transposed[15];
    return result;
}

mfloat_t *mat4_cofactor(mfloat_t *result, const mfloat_t *m0) {
    mfloat_t cofactor[MAT4_SIZE];
    mfloat_t minor[MAT3_SIZE];
    minor[0] = m0[5];
    minor[1] = m0[6];
    minor[2] = m0[7];
    minor[3] = m0[9];
    minor[4] = m0[10];
    minor[5] = m0[11];
    minor[6] = m0[13];
    minor[7] = m0[14];
    minor[8] = m0[15];
    cofactor[0] = mat3_determinant(minor);
    minor[0] = m0[4];
    minor[1] = m0[6];
    minor[2] = m0[7];
    minor[3] = m0[8];
    minor[4] = m0[10];
    minor[5] = m0[11];
    minor[6] = m0[12];
    minor[7] = m0[14];
    minor[8] = m0[15];
    cofactor[1] = -mat3_determinant(minor);
    minor[0] = m0[4];
    minor[1] = m0[5];
    minor[2] = m0[7];
    minor[3] = m0[8];
    minor[4] = m0[9];
    minor[5] = m0[11];
    minor[6] = m0[12];
    minor[7] = m0[13];
    minor[8] = m0[15];
    cofactor[2] = mat3_determinant(minor);
    minor[0] = m0[4];
    minor[1] = m0[5];
    minor[2] = m0[6];
    minor[3] = m0[8];
    minor[4] = m0[9];
    minor[5] = m0[10];
    minor[6] = m0[12];
    minor[7] = m0[13];
    minor[8] = m0[14];
    cofactor[3] = -mat3_determinant(minor);
    minor[0] = m0[1];
    minor[1] = m0[2];
    minor[2] = m0[3];
    minor[3] = m0[9];
    minor[4] = m0[10];
    minor[5] = m0[11];
    minor[6] = m0[13];
    minor[7] = m0[14];
    minor[8] = m0[15];
    cofactor[4] = -mat3_determinant(minor);
    minor[0] = m0[0];
    minor[1] = m0[2];
    minor[2] = m0[3];
    minor[3] = m0[8];
    minor[4] = m0[10];
    minor[5] = m0[11];
    minor[6] = m0[12];
    minor[7] = m0[14];
    minor[8] = m0[15];
    cofactor[5] = mat3_determinant(minor);
    minor[0] = m0[0];
    minor[1] = m0[1];
    minor[2] = m0[3];
    minor[3] = m0[8];
    minor[4] = m0[9];
    minor[5] = m0[11];
    minor[6] = m0[12];
    minor[7] = m0[13];
    minor[8] = m0[15];
    cofactor[6] = -mat3_determinant(minor);
    minor[0] = m0[0];
    minor[1] = m0[1];
    minor[2] = m0[2];
    minor[3] = m0[8];
    minor[4] = m0[9];
    minor[5] = m0[10];
    minor[6] = m0[12];
    minor[7] = m0[13];
    minor[8] = m0[14];
    cofactor[7] = mat3_determinant(minor);
    minor[0] = m0[1];
    minor[1] = m0[2];
    minor[2] = m0[3];
    minor[3] = m0[5];
    minor[4] = m0[6];
    minor[5] = m0[7];
    minor[6] = m0[13];
    minor[7] = m0[14];
    minor[8] = m0[15];
    cofactor[8] = mat3_determinant(minor);
    minor[0] = m0[0];
    minor[1] = m0[2];
    minor[2] = m0[3];
    minor[3] = m0[4];
    minor[4] = m0[6];
    minor[5] = m0[7];
    minor[6] = m0[12];
    minor[7] = m0[14];
    minor[8] = m0[15];
    cofactor[9] = -mat3_determinant(minor);
    minor[0] = m0[0];
    minor[1] = m0[1];
    minor[2] = m0[3];
    minor[3] = m0[4];
    minor[4] = m0[5];
    minor[5] = m0[7];
    minor[6] = m0[12];
    minor[7] = m0[13];
    minor[8] = m0[15];
    cofactor[10] = mat3_determinant(minor);
    minor[0] = m0[0];
    minor[1] = m0[1];
    minor[2] = m0[2];
    minor[3] = m0[4];
    minor[4] = m0[5];
    minor[5] = m0[6];
    minor[6] = m0[12];
    minor[7] = m0[13];
    minor[8] = m0[14];
    cofactor[11] = -mat3_determinant(minor);
    minor[0] = m0[1];
    minor[1] = m0[2];
    minor[2] = m0[3];
    minor[3] = m0[5];
    minor[4] = m0[6];
    minor[5] = m0[7];
    minor[6] = m0[9];
    minor[7] = m0[10];
    minor[8] = m0[11];
    cofactor[12] = -mat3_determinant(minor);
    minor[0] = m0[0];
    minor[1] = m0[2];
    minor[2] = m0[3];
    minor[3] = m0[4];
    minor[4] = m0[6];
    minor[5] = m0[7];
    minor[6] = m0[8];
    minor[7] = m0[10];
    minor[8] = m0[11];
    cofactor[13] = mat3_determinant(minor);
    minor[0] = m0[0];
    minor[1] = m0[1];
    minor[2] = m0[3];
    minor[3] = m0[4];
    minor[4] = m0[5];
    minor[5] = m0[7];
    minor[6] = m0[8];
    minor[7] = m0[9];
    minor[8] = m0[11];
    cofactor[14] = -mat3_determinant(minor);
    minor[0] = m0[0];
    minor[1] = m0[1];
    minor[2] = m0[2];
    minor[3] = m0[4];
    minor[4] = m0[5];
    minor[5] = m0[6];
    minor[6] = m0[8];
    minor[7] = m0[9];
    minor[8] = m0[10];
    cofactor[15] = mat3_determinant(minor);
    result[0] = cofactor[0];
    result[1] = cofactor[1];
    result[2] = cofactor[2];
    result[3] = cofactor[3];
    result[4] = cofactor[4];
    result[5] = cofactor[5];
    result[6] = cofactor[6];
    result[7] = cofactor[7];
    result[8] = cofactor[8];
    result[9] = cofactor[9];
    result[10] = cofactor[10];
    result[11] = cofactor[11];
    result[12] = cofactor[12];
    result[13] = cofactor[13];
    result[14] = cofactor[14];
    result[15] = cofactor[15];
    return result;
}

mfloat_t *mat4_rotation_x(mfloat_t *result, mfloat_t f) {
    mfloat_t c = MCOS(f);
    mfloat_t s = MSIN(f);
    result[0] = MONE;
    result[1] = MZERO;
    result[2] = MZERO;
    result[3] = MZERO;
    result[4] = MZERO;
    result[5] = c;
    result[6] = s;
    result[7] = MZERO;
    result[8] = MZERO;
    result[9] = -s;
    result[10] = c;
    result[11] = MZERO;
    result[12] = MZERO;
    result[13] = MZERO;
    result[14] = MZERO;
    result[15] = MONE;
    return result;
}

mfloat_t *mat4_rotation_y(mfloat_t *result, mfloat_t f) {
    mfloat_t c = MCOS(f);
    mfloat_t s = MSIN(f);
    result[0] = c;
    result[1] = MZERO;
    result[2] = -s;
    result[3] = MZERO;
    result[4] = MZERO;
    result[5] = MONE;
    result[6] = MZERO;
    result[7] = MZERO;
    result[8] = s;
    result[9] = MZERO;
    result[10] = c;
    result[11] = MZERO;
    result[12] = MZERO;
    result[13] = MZERO;
    result[14] = MZERO;
    result[15] = MONE;
    return result;
}

mfloat_t *mat4_rotation_z(mfloat_t *result, mfloat_t f) {
    mfloat_t c = MCOS(f);
    mfloat_t s = MSIN(f);
    result[0] = c;
    result[1] = s;
    result[2] = MZERO;
    result[3] = MZERO;
    result[4] = -s;
    result[5] = c;
    result[6] = MZERO;
    result[7] = MZERO;
    result[8] = MZERO;
    result[9] = MZERO;
    result[10] = MONE;
    result[11] = MZERO;
    result[12] = MZERO;
    result[13] = MZERO;
    result[14] = MZERO;
    result[15] = MONE;
    return result;
}

mfloat_t *mat4_rotation_axis(mfloat_t *result, const mfloat_t *v0, mfloat_t f) {
#if defined(MATHC_PRECISE_TRIGONOMETRY)
    sincos1cos sc1c = sncs1cs(f);
    mfloat_t c = sc1c.cos, s = sc1c.sin, one_c = sc1c.omc;
#else
    mfloat_t c = MCOS(f);
    mfloat_t s = MSIN(f);
    mfloat_t one_c = MONE - c;
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
    result[3] = MZERO;
    result[4] = (xy * one_c - v0[2] * sqrt_l * s) / l;
    result[5] = (yy + (xx + zz) * c) / l;
    result[6] = (yz * one_c + v0[0] * sqrt_l * s) / l;
    result[7] = MZERO;
    result[8] = (xz * one_c + v0[1] * sqrt_l * s) / l;
    result[9] = (yz * one_c - v0[0] * sqrt_l * s) / l;
    result[10] = (zz + (xx + yy) * c) / l;
    result[11] = MZERO;
    result[12] = MZERO;
    result[13] = MZERO;
    result[14] = MZERO;
    result[15] = MONE;
    return result;
}

mfloat_t *mat4_rotation_quat(mfloat_t *result, const mfloat_t *q0) {
    mfloat_t xx = q0[0] * q0[0];
    mfloat_t yy = q0[1] * q0[1];
    mfloat_t zz = q0[2] * q0[2];
    mfloat_t xy = q0[0] * q0[1];
    mfloat_t zw = q0[2] * q0[3];
    mfloat_t xz = q0[0] * q0[2];
    mfloat_t yw = q0[1] * q0[3];
    mfloat_t yz = q0[1] * q0[2];
    mfloat_t xw = q0[0] * q0[3];
    result[0] = MONE - MTWO * (yy + zz);
    result[1] = MTWO * (xy + zw);
    result[2] = MTWO * (xz - yw);
    result[3] = MZERO;
    result[4] = MTWO * (xy - zw);
    result[5] = MONE - MTWO * (xx + zz);
    result[6] = MTWO * (yz + xw);
    result[7] = MZERO;
    result[8] = MTWO * (xz + yw);
    result[9] = MTWO * (yz - xw);
    result[10] = MONE - MTWO * (xx + yy);
    result[11] = MZERO;
    result[12] = MZERO;
    result[13] = MZERO;
    result[14] = MZERO;
    result[15] = MONE;
    return result;
}

mfloat_t *mat4_rotate_x(mfloat_t *result, const mfloat_t *m0, mfloat_t f) {
    mfloat_t rotation[MAT4_SIZE];
    mat4_rotation_x(rotation, f);
    mat4_multiply(result, m0, rotation);
    return result;
}

mfloat_t *mat4_rotate_y(mfloat_t *result, const mfloat_t *m0, mfloat_t f) {
    mfloat_t rotation[MAT4_SIZE];
    mat4_rotation_y(rotation, f);
    mat4_multiply(result, m0, rotation);
    return result;
}

mfloat_t *mat4_rotate_z(mfloat_t *result, const mfloat_t *m0, mfloat_t f) {
    mfloat_t rotation[MAT4_SIZE];
    mat4_rotation_z(rotation, f);
    mat4_multiply(result, m0, rotation);
    return result;
}

mfloat_t *mat4_rotate_axis(mfloat_t *result, const mfloat_t *m0, const mfloat_t *v0, mfloat_t f) {
    mfloat_t rotation[MAT4_SIZE];
    mat4_rotation_axis(rotation, v0, f);
    mat4_multiply(result, m0, rotation);
    return result;
}

mfloat_t *mat4_rotate_quat(mfloat_t *result, const mfloat_t *m0, const mfloat_t *q0) {
    mfloat_t rotation[MAT4_SIZE];
    mat4_rotation_quat(rotation, q0);
    mat4_multiply(result, m0, rotation);
    return result;
}

mfloat_t *mat4_translation(mfloat_t *result, const mfloat_t *m0, const mfloat_t *v0) {
    result[0] = m0[0];
    result[1] = m0[1];
    result[2] = m0[2];
    result[3] = m0[3];
    result[4] = m0[4];
    result[5] = m0[5];
    result[6] = m0[6];
    result[7] = m0[7];
    result[8] = m0[8];
    result[9] = m0[9];
    result[10] = m0[10];
    result[11] = m0[11];
    result[12] = v0[0];
    result[13] = v0[1];
    result[14] = v0[2];
    result[15] = m0[15];
    return result;
}

mfloat_t *mat4_translate(mfloat_t *result, const mfloat_t *m0, const mfloat_t *v0) {
    result[0] = m0[0];
    result[1] = m0[1];
    result[2] = m0[2];
    result[3] = m0[3];
    result[4] = m0[4];
    result[5] = m0[5];
    result[6] = m0[6];
    result[7] = m0[7];
    result[8] = m0[8];
    result[9] = m0[9];
    result[10] = m0[10];
    result[11] = m0[11];
    result[12] = m0[12] + v0[0];
    result[13] = m0[13] + v0[1];
    result[14] = m0[14] + v0[2];
    result[15] = m0[15];
    return result;
}

mfloat_t *mat4_scaling(mfloat_t *result, const mfloat_t *m0, const mfloat_t *v0) {
    result[0] = v0[0];
    result[1] = m0[1];
    result[2] = m0[2];
    result[3] = m0[3];
    result[4] = m0[4];
    result[5] = v0[1];
    result[6] = m0[6];
    result[7] = m0[7];
    result[8] = m0[8];
    result[9] = m0[9];
    result[10] = v0[2];
    result[11] = m0[11];
    result[12] = m0[12];
    result[13] = m0[13];
    result[14] = m0[14];
    result[15] = m0[15];
    return result;
}

mfloat_t *mat4_scale(mfloat_t *result, const mfloat_t *m0, const mfloat_t *v0) {
    result[0] = m0[0] * v0[0];
    result[1] = m0[1];
    result[2] = m0[2];
    result[3] = m0[3];
    result[4] = m0[4];
    result[5] = m0[5] * v0[1];
    result[6] = m0[6];
    result[7] = m0[7];
    result[8] = m0[8];
    result[9] = m0[9];
    result[10] = m0[10] * v0[2];
    result[11] = m0[11];
    result[12] = m0[12];
    result[13] = m0[13];
    result[14] = m0[14];
    result[15] = m0[15];
    return result;
}

mfloat_t *mat4_add(mfloat_t *result, const mfloat_t *m0, const mfloat_t *m1) {
    result[0] = m0[0] + m1[0];
    result[1] = m0[1] + m1[1];
    result[2] = m0[2] + m1[2];
    result[3] = m0[3] + m1[3];
    result[4] = m0[4] + m1[4];
    result[5] = m0[5] + m1[5];
    result[6] = m0[6] + m1[6];
    result[7] = m0[7] + m1[7];
    result[8] = m0[8] + m1[8];
    result[9] = m0[9] + m1[9];
    result[10] = m0[10] + m1[10];
    result[11] = m0[11] + m1[11];
    result[12] = m0[12] + m1[12];
    result[13] = m0[13] + m1[13];
    result[14] = m0[14] + m1[14];
    result[15] = m0[15] + m1[15];
    return result;
}

mfloat_t *mat4_add_f(mfloat_t *result, const mfloat_t *m0, mfloat_t f) {
    result[0] = m0[0] + f;
    result[1] = m0[1] + f;
    result[2] = m0[2] + f;
    result[3] = m0[3] + f;
    result[4] = m0[4] + f;
    result[5] = m0[5] + f;
    result[6] = m0[6] + f;
    result[7] = m0[7] + f;
    result[8] = m0[8] + f;
    result[9] = m0[9] + f;
    result[10] = m0[10] + f;
    result[11] = m0[11] + f;
    result[12] = m0[12] + f;
    result[13] = m0[13] + f;
    result[14] = m0[14] + f;
    result[15] = m0[15] + f;
    return result;
}

mfloat_t *mat4_subtract(mfloat_t *result, const mfloat_t *m0, const mfloat_t *m1) {
    result[0] = m0[0] - m1[0];
    result[1] = m0[1] - m1[1];
    result[2] = m0[2] - m1[2];
    result[3] = m0[3] - m1[3];
    result[4] = m0[4] - m1[4];
    result[5] = m0[5] - m1[5];
    result[6] = m0[6] - m1[6];
    result[7] = m0[7] - m1[7];
    result[8] = m0[8] - m1[8];
    result[9] = m0[9] - m1[9];
    result[10] = m0[10] - m1[10];
    result[11] = m0[11] - m1[11];
    result[12] = m0[12] - m1[12];
    result[13] = m0[13] - m1[13];
    result[14] = m0[14] - m1[14];
    result[15] = m0[15] - m1[15];
    return result;
}

mfloat_t *mat4_subtract_f(mfloat_t *result, const mfloat_t *m0, mfloat_t f) {
    result[0] = m0[0] - f;
    result[1] = m0[1] - f;
    result[2] = m0[2] - f;
    result[3] = m0[3] - f;
    result[4] = m0[4] - f;
    result[5] = m0[5] - f;
    result[6] = m0[6] - f;
    result[7] = m0[7] - f;
    result[8] = m0[8] - f;
    result[9] = m0[9] - f;
    result[10] = m0[10] - f;
    result[11] = m0[11] - f;
    result[12] = m0[12] - f;
    result[13] = m0[13] - f;
    result[14] = m0[14] - f;
    result[15] = m0[15] - f;
    return result;
}

mfloat_t *mat4_multiply(mfloat_t *result, const mfloat_t *m0, const mfloat_t *m1) {
    mfloat_t multiplied[MAT4_SIZE];
    multiplied[0] = m0[0] * m1[0] + m0[4] * m1[1] + m0[8] * m1[2] + m0[12] * m1[3];
    multiplied[1] = m0[1] * m1[0] + m0[5] * m1[1] + m0[9] * m1[2] + m0[13] * m1[3];
    multiplied[2] = m0[2] * m1[0] + m0[6] * m1[1] + m0[10] * m1[2] + m0[14] * m1[3];
    multiplied[3] = m0[3] * m1[0] + m0[7] * m1[1] + m0[11] * m1[2] + m0[15] * m1[3];
    multiplied[4] = m0[0] * m1[4] + m0[4] * m1[5] + m0[8] * m1[6] + m0[12] * m1[7];
    multiplied[5] = m0[1] * m1[4] + m0[5] * m1[5] + m0[9] * m1[6] + m0[13] * m1[7];
    multiplied[6] = m0[2] * m1[4] + m0[6] * m1[5] + m0[10] * m1[6] + m0[14] * m1[7];
    multiplied[7] = m0[3] * m1[4] + m0[7] * m1[5] + m0[11] * m1[6] + m0[15] * m1[7];
    multiplied[8] = m0[0] * m1[8] + m0[4] * m1[9] + m0[8] * m1[10] + m0[12] * m1[11];
    multiplied[9] = m0[1] * m1[8] + m0[5] * m1[9] + m0[9] * m1[10] + m0[13] * m1[11];
    multiplied[10] = m0[2] * m1[8] + m0[6] * m1[9] + m0[10] * m1[10] + m0[14] * m1[11];
    multiplied[11] = m0[3] * m1[8] + m0[7] * m1[9] + m0[11] * m1[10] + m0[15] * m1[11];
    multiplied[12] = m0[0] * m1[12] + m0[4] * m1[13] + m0[8] * m1[14] + m0[12] * m1[15];
    multiplied[13] = m0[1] * m1[12] + m0[5] * m1[13] + m0[9] * m1[14] + m0[13] * m1[15];
    multiplied[14] = m0[2] * m1[12] + m0[6] * m1[13] + m0[10] * m1[14] + m0[14] * m1[15];
    multiplied[15] = m0[3] * m1[12] + m0[7] * m1[13] + m0[11] * m1[14] + m0[15] * m1[15];
    result[0] = multiplied[0];
    result[1] = multiplied[1];
    result[2] = multiplied[2];
    result[3] = multiplied[3];
    result[4] = multiplied[4];
    result[5] = multiplied[5];
    result[6] = multiplied[6];
    result[7] = multiplied[7];
    result[8] = multiplied[8];
    result[9] = multiplied[9];
    result[10] = multiplied[10];
    result[11] = multiplied[11];
    result[12] = multiplied[12];
    result[13] = multiplied[13];
    result[14] = multiplied[14];
    result[15] = multiplied[15];
    return result;
}

mfloat_t *mat4_multiply_f(mfloat_t *result, const mfloat_t *m0, mfloat_t f) {
    result[0] = m0[0] * f;
    result[1] = m0[1] * f;
    result[2] = m0[2] * f;
    result[3] = m0[3] * f;
    result[4] = m0[4] * f;
    result[5] = m0[5] * f;
    result[6] = m0[6] * f;
    result[7] = m0[7] * f;
    result[8] = m0[8] * f;
    result[9] = m0[9] * f;
    result[10] = m0[10] * f;
    result[11] = m0[11] * f;
    result[12] = m0[12] * f;
    result[13] = m0[13] * f;
    result[14] = m0[14] * f;
    result[15] = m0[15] * f;
    return result;
}

mfloat_t *mat4_inverse(mfloat_t *result, const mfloat_t *m0) {
    mfloat_t inverse[MAT4_SIZE];
    mfloat_t inverted_determinant;
    mfloat_t m11 = m0[0];
    mfloat_t m21 = m0[1];
    mfloat_t m31 = m0[2];
    mfloat_t m41 = m0[3];
    mfloat_t m12 = m0[4];
    mfloat_t m22 = m0[5];
    mfloat_t m32 = m0[6];
    mfloat_t m42 = m0[7];
    mfloat_t m13 = m0[8];
    mfloat_t m23 = m0[9];
    mfloat_t m33 = m0[10];
    mfloat_t m43 = m0[11];
    mfloat_t m14 = m0[12];
    mfloat_t m24 = m0[13];
    mfloat_t m34 = m0[14];
    mfloat_t m44 = m0[15];
    inverse[0] = m22 * m33 * m44
        - m22 * m43 * m34
        - m23 * m32 * m44
        + m23 * m42 * m34
        + m24 * m32 * m43
        - m24 * m42 * m33;
    inverse[4] = -m12 * m33 * m44
        + m12 * m43 * m34
        + m13 * m32 * m44
        - m13 * m42 * m34
        - m14 * m32 * m43
        + m14 * m42 * m33;
    inverse[8] = m12 * m23 * m44
        - m12 * m43 * m24
        - m13 * m22 * m44
        + m13 * m42 * m24
        + m14 * m22 * m43
        - m14 * m42 * m23;
    inverse[12] = -m12 * m23 * m34
        + m12 * m33 * m24
        + m13 * m22 * m34
        - m13 * m32 * m24
        - m14 * m22 * m33
        + m14 * m32 * m23;
    inverse[1] = -m21 * m33 * m44
        + m21 * m43 * m34
        + m23 * m31 * m44
        - m23 * m41 * m34
        - m24 * m31 * m43
        + m24 * m41 * m33;
    inverse[5] = m11 * m33 * m44
        - m11 * m43 * m34
        - m13 * m31 * m44
        + m13 * m41 * m34
        + m14 * m31 * m43
        - m14 * m41 * m33;
    inverse[9] = -m11 * m23 * m44
        + m11 * m43 * m24
        + m13 * m21 * m44
        - m13 * m41 * m24
        - m14 * m21 * m43
        + m14 * m41 * m23;
    inverse[13] = m11 * m23 * m34
        - m11 * m33 * m24
        - m13 * m21 * m34
        + m13 * m31 * m24
        + m14 * m21 * m33
        - m14 * m31 * m23;
    inverse[2] = m21 * m32 * m44
        - m21 * m42 * m34
        - m22 * m31 * m44
        + m22 * m41 * m34
        + m24 * m31 * m42
        - m24 * m41 * m32;
    inverse[6] = -m11 * m32 * m44
        + m11 * m42 * m34
        + m12 * m31 * m44
        - m12 * m41 * m34
        - m14 * m31 * m42
        + m14 * m41 * m32;
    inverse[10] = m11 * m22 * m44
        - m11 * m42 * m24
        - m12 * m21 * m44
        + m12 * m41 * m24
        + m14 * m21 * m42
        - m14 * m41 * m22;
    inverse[14] = -m11 * m22 * m34
        + m11 * m32 * m24
        + m12 * m21 * m34
        - m12 * m31 * m24
        - m14 * m21 * m32
        + m14 * m31 * m22;
    inverse[3] = -m21 * m32 * m43
        + m21 * m42 * m33
        + m22 * m31 * m43
        - m22 * m41 * m33
        - m23 * m31 * m42
        + m23 * m41 * m32;
    inverse[7] = m11 * m32 * m43
        - m11 * m42 * m33
        - m12 * m31 * m43
        + m12 * m41 * m33
        + m13 * m31 * m42
        - m13 * m41 * m32;
    inverse[11] = -m11 * m22 * m43
        + m11 * m42 * m23
        + m12 * m21 * m43
        - m12 * m41 * m23
        - m13 * m21 * m42
        + m13 * m41 * m22;
    inverse[15] = m11 * m22 * m33
        - m11 * m32 * m23
        - m12 * m21 * m33
        + m12 * m31 * m23
        + m13 * m21 * m32
        - m13 * m31 * m22;
    inverted_determinant = MONE / (m11 * inverse[0] + m21 * inverse[4] + m31 * inverse[8] + m41 * inverse[12]);
    result[0] = inverse[0] * inverted_determinant;
    result[1] = inverse[1] * inverted_determinant;
    result[2] = inverse[2] * inverted_determinant;
    result[3] = inverse[3] * inverted_determinant;
    result[4] = inverse[4] * inverted_determinant;
    result[5] = inverse[5] * inverted_determinant;
    result[6] = inverse[6] * inverted_determinant;
    result[7] = inverse[7] * inverted_determinant;
    result[8] = inverse[8] * inverted_determinant;
    result[9] = inverse[9] * inverted_determinant;
    result[10] = inverse[10] * inverted_determinant;
    result[11] = inverse[11] * inverted_determinant;
    result[12] = inverse[12] * inverted_determinant;
    result[13] = inverse[13] * inverted_determinant;
    result[14] = inverse[14] * inverted_determinant;
    result[15] = inverse[15] * inverted_determinant;
    return result;
}

mfloat_t *mat4_lerp(mfloat_t *result, const mfloat_t *m0, const mfloat_t *m1, mfloat_t f) {
    result[0] = m0[0] + (m1[0] - m0[0]) * f;
    result[1] = m0[1] + (m1[1] - m0[1]) * f;
    result[2] = m0[2] + (m1[2] - m0[2]) * f;
    result[3] = m0[3] + (m1[3] - m0[3]) * f;
    result[4] = m0[4] + (m1[4] - m0[4]) * f;
    result[5] = m0[5] + (m1[5] - m0[5]) * f;
    result[6] = m0[6] + (m1[6] - m0[6]) * f;
    result[7] = m0[7] + (m1[7] - m0[7]) * f;
    result[8] = m0[8] + (m1[8] - m0[8]) * f;
    result[9] = m0[9] + (m1[9] - m0[9]) * f;
    result[10] = m0[10] + (m1[10] - m0[10]) * f;
    result[11] = m0[11] + (m1[11] - m0[11]) * f;
    result[12] = m0[12] + (m1[12] - m0[12]) * f;
    result[13] = m0[13] + (m1[13] - m0[13]) * f;
    result[14] = m0[14] + (m1[14] - m0[14]) * f;
    result[15] = m0[15] + (m1[15] - m0[15]) * f;
    return result;
}

mfloat_t *mat4_look_at(mfloat_t *result, const mfloat_t *position, const mfloat_t *target, const mfloat_t *up) {
    mfloat_t tmp_forward[VEC3_SIZE];
    mfloat_t tmp_side[VEC3_SIZE];
    mfloat_t tmp_up[VEC3_SIZE];
    vec3_subtract(tmp_forward, target, position);
    vec3_normalize(tmp_forward, tmp_forward);
    vec3_cross(tmp_side, tmp_forward, up);
    vec3_normalize(tmp_side, tmp_side);
    vec3_cross(tmp_up, tmp_side, tmp_forward);
    result[0] = tmp_side[0];
    result[1] = tmp_up[0];
    result[2] = -tmp_forward[0];
    result[3] = MZERO;
    result[4] = tmp_side[1];
    result[5] = tmp_up[1];
    result[6] = -tmp_forward[1];
    result[7] = MZERO;
    result[8] = tmp_side[2];
    result[9] = tmp_up[2];
    result[10] = -tmp_forward[2];
    result[11] = MZERO;
    result[12] = -vec3_dot(tmp_side, position);
    result[13] = -vec3_dot(tmp_up, position);
    result[14] = vec3_dot(tmp_forward, position);
    result[15] = MONE;
    return result;
}

mfloat_t *mat4_ortho(mfloat_t *result, mfloat_t l, mfloat_t r, mfloat_t b, mfloat_t t, mfloat_t n, mfloat_t f) {
    result[0] = MTWO / (r - l);
    result[1] = MZERO;
    result[2] = MZERO;
    result[3] = MZERO;
    result[4] = MZERO;
    result[5] = MTWO / (t - b);
    result[6] = MZERO;
    result[7] = MZERO;
    result[8] = MZERO;
    result[9] = MZERO;
    result[10] = -MTWO / (f - n);
    result[11] = MZERO;
    result[12] = -((r + l) / (r - l));
    result[13] = -((t + b) / (t - b));
    result[14] = -((f + n) / (f - n));
    result[15] = MONE;
    return result;
}

mfloat_t *mat4_perspective(mfloat_t *result, mfloat_t fov_y, mfloat_t aspect, mfloat_t n, mfloat_t f) {
    mfloat_t tan_half_fov_y = MONE / MTAN(fov_y * MHALF);
    result[0] = MONE / aspect * tan_half_fov_y;
    result[1] = MZERO;
    result[2] = MZERO;
    result[3] = MZERO;
    result[4] = MZERO;
    result[5] = MONE / tan_half_fov_y;
    result[6] = MZERO;
    result[7] = MZERO;
    result[8] = MZERO;
    result[9] = MZERO;
    result[10] = f / (n - f);
    result[11] = -MONE;
    result[12] = MZERO;
    result[13] = MZERO;
    result[14] = -(f * n) / (f - n);
    result[15] = MZERO;
    return result;
}

mfloat_t *mat4_perspective_fov(mfloat_t *result, mfloat_t fov, mfloat_t w, mfloat_t h, mfloat_t n, mfloat_t f) {
    mfloat_t h2 = MCOS(fov * MHALF) / MSIN(fov * MHALF);
    mfloat_t w2 = h2 * h / w;
    result[0] = w2;
    result[1] = MZERO;
    result[2] = MZERO;
    result[3] = MZERO;
    result[4] = MZERO;
    result[5] = h2;
    result[6] = MZERO;
    result[7] = MZERO;
    result[8] = MZERO;
    result[9] = MZERO;
    result[10] = f / (n - f);
    result[11] = -MONE;
    result[12] = MZERO;
    result[13] = MZERO;
    result[14] = -(f * n) / (f - n);
    result[15] = MZERO;
    return result;
}

mfloat_t *mat4_perspective_infinite(mfloat_t *result, mfloat_t fov_y, mfloat_t aspect, mfloat_t n) {
    mfloat_t range = MTAN(fov_y * MHALF) * n;
    mfloat_t left = -range * aspect;
    mfloat_t right = range * aspect;
    mfloat_t top = range;
    mfloat_t bottom = -range;
    result[0] = MTWO * n / (right - left);
    result[1] = MZERO;
    result[2] = MZERO;
    result[3] = MZERO;
    result[4] = MZERO;
    result[5] = MTWO * n / (top - bottom);
    result[6] = MZERO;
    result[7] = MZERO;
    result[8] = MZERO;
    result[9] = MZERO;
    result[10] = -MONE;
    result[11] = -MONE;
    result[12] = MZERO;
    result[13] = MZERO;
    result[14] = -MTWO * n;
    result[15] = MZERO;
    return result;
}

#if defined(MATHC_USE_STRUCT_FUNCTIONS)
struct mat4 smat4(mfloat_t m11, mfloat_t m12, mfloat_t m13, mfloat_t m14, mfloat_t m21, mfloat_t m22, mfloat_t m23, mfloat_t m24, mfloat_t m31, mfloat_t m32, mfloat_t m33, mfloat_t m34, mfloat_t m41, mfloat_t m42, mfloat_t m43, mfloat_t m44) {
    struct mat4 result;
    mat4((mfloat_t *)&result, m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44);
    return result;
}

struct mat4 smat4_zero(void) {
    struct mat4 result;
    mat4_zero((mfloat_t *)&result);
    return result;
}

struct mat4 smat4_identity(void) {
    struct mat4 result;
    mat4_identity((mfloat_t *)&result);
    return result;
}

mfloat_t smat4_determinant(struct mat4 m0) {
    return mat4_determinant((const mfloat_t *)&m0);
}

struct mat4 smat4_assign(struct mat4 m0) {
    struct mat4 result;
    mat4_assign((mfloat_t *)&result, (const mfloat_t *)&m0);
    return result;
}

struct mat4 smat4_negative(struct mat4 m0) {
    struct mat4 result;
    mat4_negative((mfloat_t *)&result, (const mfloat_t *)&m0);
    return result;
}

struct mat4 smat4_transpose(struct mat4 m0) {
    struct mat4 result;
    mat4_transpose((mfloat_t *)&result, (const mfloat_t *)&m0);
    return result;
}

struct mat4 smat4_cofactor(struct mat4 m0) {
    struct mat4 result;
    mat4_cofactor((mfloat_t *)&result, (const mfloat_t *)&m0);
    return result;
}

struct mat4 smat4_rotation_x(mfloat_t f) {
    struct mat4 result;
    mat4_rotation_x((mfloat_t *)&result, f);
    return result;
}

struct mat4 smat4_rotation_y(mfloat_t f) {
    struct mat4 result;
    mat4_rotation_y((mfloat_t *)&result, f);
    return result;
}

struct mat4 smat4_rotation_z(mfloat_t f) {
    struct mat4 result;
    mat4_rotation_z((mfloat_t *)&result, f);
    return result;
}

struct mat4 smat4_rotation_axis(struct vec3 v0, mfloat_t f) {
    struct mat4 result;
    mat4_rotation_axis((mfloat_t *)&result, (const mfloat_t *)&v0, f);
    return result;
}

struct mat4 smat4_rotation_quat(struct quat q0) {
    struct mat4 result;
    mat4_rotation_quat((mfloat_t *)&result, (const mfloat_t *)&q0);
    return result;
}

struct mat4 smat4_rotate_x(struct mat4 m0, mfloat_t f) {
    struct mat4 result;
    mat4_rotate_x((mfloat_t *)&result, (const mfloat_t *)&m0, f);
    return result;
}

struct mat4 smat4_rotate_y(struct mat4 m0, mfloat_t f) {
    struct mat4 result;
    mat4_rotate_y((mfloat_t *)&result, (const mfloat_t *)&m0, f);
    return result;
}

struct mat4 smat4_rotate_z(struct mat4 m0, mfloat_t f) {
    struct mat4 result;
    mat4_rotate_z((mfloat_t *)&result, (const mfloat_t *)&m0, f);
    return result;
}

struct mat4 smat4_rotate_axis(struct mat4 m0, struct vec3 v0, mfloat_t f) {
    struct mat4 result;
    mat4_rotate_axis((mfloat_t *)&result, (const mfloat_t *)&m0, (const mfloat_t *)&v0, f);
    return result;
}

struct mat4 smat4_rotate_quat(struct mat4 m0, struct quat q0) {
    struct mat4 result;
    mat4_rotate_quat((mfloat_t *)&result, (const mfloat_t *)&m0, (const mfloat_t *)&q0);
    return result;
}

struct mat4 smat4_translation(struct mat4 m0, struct vec3 v0) {
    struct mat4 result;
    mat4_translation((mfloat_t *)&result, (const mfloat_t *)&m0, (const mfloat_t *)&v0);
    return result;
}

struct mat4 smat4_translate(struct mat4 m0, struct vec3 v0) {
    struct mat4 result;
    mat4_translate((mfloat_t *)&result, (const mfloat_t *)&m0, (const mfloat_t *)&v0);
    return result;
}

struct mat4 smat4_scaling(struct mat4 m0, struct vec3 v0) {
    struct mat4 result;
    mat4_scaling((mfloat_t *)&result, (const mfloat_t *)&m0, (const mfloat_t *)&v0);
    return result;
}

struct mat4 smat4_scale(struct mat4 m0, struct vec3 v0) {
    struct mat4 result;
    mat4_scale((mfloat_t *)&result, (const mfloat_t *)&m0, (const mfloat_t *)&v0);
    return result;
}

struct mat4 smat4_add(struct mat4 m0, struct mat4 m1) {
    struct mat4 result;
    mat4_add((mfloat_t *)&result, (const mfloat_t *)&m0, (const mfloat_t *)&m1);
    return result;
}

struct mat4 smat4_add_f(struct mat4 m0, mfloat_t f) {
    struct mat4 result;
    mat4_add_f((mfloat_t *)&result, (const mfloat_t *)&m0, f);
    return result;
}

struct mat4 smat4_subtract(struct mat4 m0, struct mat4 m1) {
    struct mat4 result;
    mat4_subtract((mfloat_t *)&result, (const mfloat_t *)&m0, (const mfloat_t *)&m1);
    return result;
}

struct mat4 smat4_subtract_f(struct mat3 m0, mfloat_t f) {
    struct mat4 result;
    mat4_subtract_f((mfloat_t *)&result, (const mfloat_t *)&m0, f);
    return result;
}

struct mat4 smat4_multiply(struct mat4 m0, struct mat4 m1) {
    struct mat4 result;
    mat4_multiply((mfloat_t *)&result, (const mfloat_t *)&m0, (const mfloat_t *)&m1);
    return result;
}

struct mat4 smat4_multiply_f(struct mat4 m0, mfloat_t f) {
    struct mat4 result;
    mat4_multiply_f((mfloat_t *)&result, (const mfloat_t *)&m0, f);
    return result;
}

struct mat4 smat4_inverse(struct mat4 m0) {
    struct mat4 result;
    mat4_inverse((mfloat_t *)&result, (const mfloat_t *)&m0);
    return result;
}

struct mat4 smat4_lerp(struct mat4 m0, struct mat4 m1, mfloat_t f) {
    struct mat4 result;
    mat4_lerp((mfloat_t *)&result, (const mfloat_t *)&m0, (const mfloat_t *)&m1, f);
    return result;
}

struct mat4 smat4_look_at(struct vec3 position, struct vec3 target, struct vec3 up) {
    struct mat4 result;
    mat4_look_at((mfloat_t *)&result, (const mfloat_t *)&position, (const mfloat_t *)&target, (const mfloat_t *)&up);
    return result;
}

struct mat4 smat4_ortho(mfloat_t l, mfloat_t r, mfloat_t b, mfloat_t t, mfloat_t n, mfloat_t f) {
    struct mat4 result;
    mat4_ortho((mfloat_t *)&result, l, r, b, t, n, f);
    return result;
}

struct mat4 smat4_perspective(mfloat_t fov_y, mfloat_t aspect, mfloat_t n, mfloat_t f) {
    struct mat4 result;
    mat4_perspective((mfloat_t *)&result, fov_y, aspect, n, f);
    return result;
}

struct mat4 smat4_perspective_fov(mfloat_t fov, mfloat_t w, mfloat_t h, mfloat_t n, mfloat_t f) {
    struct mat4 result;
    mat4_perspective_fov((mfloat_t *)&result, fov, w, h, n, f);
    return result;
}

struct mat4 smat4_perspective_infinite(mfloat_t fov_y, mfloat_t aspect, mfloat_t n) {
    struct mat4 result;
    mat4_perspective_infinite((mfloat_t *)&result, fov_y, aspect, n);
    return result;
}
#endif

#if defined(MATHC_USE_POINTER_STRUCT_FUNCTIONS)
struct mat4 *psmat4(struct mat4 *result, mfloat_t m11, mfloat_t m12, mfloat_t m13, mfloat_t m14, mfloat_t m21, mfloat_t m22, mfloat_t m23, mfloat_t m24, mfloat_t m31, mfloat_t m32, mfloat_t m33, mfloat_t m34, mfloat_t m41, mfloat_t m42, mfloat_t m43, mfloat_t m44) {
    return (struct mat4 *)mat4((mfloat_t *)result, m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44);
}

struct mat4 *psmat4_zero(struct mat4 *result) {
    return (struct mat4 *)mat4_zero((mfloat_t *)result);
}

struct mat4 *psmat4_identity(struct mat4 *result) {
    return (struct mat4 *)mat4_identity((mfloat_t *)result);
}

mfloat_t psmat4_determinant(const struct mat4 *m0) {
    return mat4_determinant((const mfloat_t *)m0);
}

struct mat4 *psmat4_assign(struct mat4 *result, const struct mat4 *m0) {
    return (struct mat4 *)mat4_assign((mfloat_t *)result, (const mfloat_t *)m0);
}

struct mat4 *psmat4_negative(struct mat4 *result, const struct mat4 *m0) {
    return (struct mat4 *)mat4_negative((mfloat_t *)result, (const mfloat_t *)m0);
}

struct mat4 *psmat4_transpose(struct mat4 *result, const struct mat4 *m0) {
    return (struct mat4 *)mat4_transpose((mfloat_t *)result, (const mfloat_t *)m0);
}

struct mat4 *psmat4_cofactor(struct mat4 *result, const struct mat4 *m0) {
    return (struct mat4 *)mat4_cofactor((mfloat_t *)result, (const mfloat_t *)m0);
}

struct mat4 *psmat4_rotation_x(struct mat4 *result, mfloat_t f) {
    return (struct mat4 *)mat4_rotation_x((mfloat_t *)result, f);
}

struct mat4 *psmat4_rotation_y(struct mat4 *result, mfloat_t f) {
    return (struct mat4 *)mat4_rotation_y((mfloat_t *)result, f);
}

struct mat4 *psmat4_rotation_z(struct mat4 *result, mfloat_t f) {
    return (struct mat4 *)mat4_rotation_z((mfloat_t *)result, f);
}

struct mat4 *psmat4_rotation_axis(struct mat4 *result, const struct vec3 *v0, mfloat_t f) {
    return (struct mat4 *)mat4_rotation_axis((mfloat_t *)result, (const mfloat_t *)v0, f);
}

struct mat4 *psmat4_rotation_quat(struct mat4 *result, const struct quat *q0) {
    return (struct mat4 *)mat4_rotation_quat((mfloat_t *)result, (const mfloat_t *)q0);
}

struct mat4 *psmat4_rotate_x(struct mat4 *result, const struct mat4 *m0, mfloat_t f) {
    return (struct mat4 *)mat4_rotate_x((mfloat_t *)result, (const mfloat_t *)m0, f);
}

struct mat4 *psmat4_rotate_y(struct mat4 *result, const struct mat4 *m0, mfloat_t f) {
    return (struct mat4 *)mat4_rotate_y((mfloat_t *)result, (const mfloat_t *)m0, f);
}

struct mat4 *psmat4_rotate_z(struct mat4 *result, const struct mat4 *m0, mfloat_t f) {
    return (struct mat4 *)mat4_rotate_z((mfloat_t *)result, (const mfloat_t *)m0, f);
}

struct mat4 *psmat4_rotate_axis(struct mat4 *result, const struct mat4 *m0, const struct vec3 *v0, mfloat_t f) {
    return (struct mat4 *)mat4_rotate_axis((mfloat_t *)result, (const mfloat_t *)m0, (const mfloat_t *)v0, f);
}

struct mat4 *psmat4_rotate_quat(struct mat4 *result, const struct mat4 *m0, const struct quat *q0) {
    return (struct mat4 *)mat4_rotate_quat((mfloat_t *)result, (const mfloat_t *)m0, (const mfloat_t *)q0);
}

struct mat4 *psmat4_translation(struct mat4 *result, const struct mat4 *m0, const struct vec3 *v0) {
    return (struct mat4 *)mat4_translation((mfloat_t *)result, (const mfloat_t *)m0, (const mfloat_t *)v0);
}

struct mat4 *psmat4_translate(struct mat4 *result, const struct mat4 *m0, const struct vec3 *v0) {
    return (struct mat4 *)mat4_translate((mfloat_t *)result, (const mfloat_t *)m0, (const mfloat_t *)v0);
}

struct mat4 *psmat4_scaling(struct mat4 *result, const struct mat4 *m0, const struct vec3 *v0) {
    return (struct mat4 *)mat4_scaling((mfloat_t *)result, (const mfloat_t *)m0, (const mfloat_t *)v0);
}

struct mat4 *psmat4_scale(struct mat4 *result, const struct mat4 *m0, const struct vec3 *v0) {
    return (struct mat4 *)mat4_scale((mfloat_t *)result, (const mfloat_t *)m0, (const mfloat_t *)v0);
}

struct mat4 *psmat4_add(struct mat4 *result, const struct mat3 *m0, const struct mat3 *m1) {
    return (struct mat4 *)mat4_add((mfloat_t *)result, (const mfloat_t *)m0, (const mfloat_t *)m1);
}

struct mat4 *psmat4_add_f(struct mat4 *result, const struct mat4 *m0, mfloat_t f) {
    return (struct mat4 *)mat4_add_f((mfloat_t *)result, (const mfloat_t *)m0, f);
}

struct mat4 *psmat4_subtract(struct mat4 *result, const struct mat4 *m0, const struct mat4 *m1) {
    return (struct mat4 *)mat4_subtract((mfloat_t *)result, (const mfloat_t *)m0, (const mfloat_t *)m1);
}

struct mat4 *psmat4_subtract_f(struct mat4 *result, const struct mat4 *m0, mfloat_t f) {    
    return (struct mat4 *)mat4_subtract_f((mfloat_t *)result, (const mfloat_t *)m0, f);
}

struct mat4 *psmat4_multiply(struct mat4 *result, const struct mat4 *m0, const struct mat4 *m1) {
    return (struct mat4 *)mat4_multiply((mfloat_t *)result, (const mfloat_t *)m0, (const mfloat_t *)m1);
}

struct mat4 *psmat4_multiply_f(struct mat4 *result, const struct mat4 *m0, mfloat_t f) {
    return (struct mat4 *)mat4_multiply_f((mfloat_t *)result, (const mfloat_t *)m0, f);
}

struct mat4 *psmat4_inverse(struct mat4 *result, const struct mat4 *m0) {
    return (struct mat4 *)mat4_inverse((mfloat_t *)result, (const mfloat_t *)m0);
}

struct mat4 *psmat4_lerp(struct mat4 *result, const struct mat4 *m0, const struct mat4 *m1, mfloat_t f) {
    return (struct mat4 *)mat4_lerp((mfloat_t *)result, (const mfloat_t *)m0, (const mfloat_t *)m1, f);
}

struct mat4 *psmat4_look_at(struct mat4 *result,const struct vec3 *position, const struct vec3 *target, const struct vec3 *up) {
    return (struct mat4 *)mat4_look_at((mfloat_t *)result, (const mfloat_t *)position, (const mfloat_t *)target, (const mfloat_t *)up);
}

struct mat4 *psmat4_ortho(struct mat4 *result, mfloat_t l, mfloat_t r, mfloat_t b, mfloat_t t, mfloat_t n, mfloat_t f) {
    return (struct mat4 *)mat4_ortho((mfloat_t *)result, l, r, b, t, n, f);
}

struct mat4 *psmat4_perspective(struct mat4 *result, mfloat_t fov_y, mfloat_t aspect, mfloat_t n, mfloat_t f) {
    return (struct mat4 *)mat4_perspective((mfloat_t *)result, fov_y, aspect, n, f);
}

struct mat4 *psmat4_perspective_fov(struct mat4 *result, mfloat_t fov, mfloat_t w, mfloat_t h, mfloat_t n, mfloat_t f) {
    return (struct mat4 *)mat4_perspective_fov((mfloat_t *)result, fov, w, h, n, f);
}

struct mat4 *psmat4_perspective_infinite(struct mat4 *result, mfloat_t fov_y, mfloat_t aspect, mfloat_t n) {
    return (struct mat4 *)mat4_perspective_infinite((mfloat_t *)result, fov_y, aspect, n);
}
#endif
#endif