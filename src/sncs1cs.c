#include "mathc.h"

#if defined(MATHC_PRECISE_TRIGONOMETRY) && defined(MATHC_USE_FLOATING_POINT)
/* The following code (sincos1cos and float and double versions of
 * sncs1cs) is Copyright © 1985, 1995, 2000 Stephen L. Moshier and
 * Copyright © 2020 Neven Sajko. The intention is to get accurate
 * 1-cosine, while also getting the sine and cosine as a bonus. The
 * implementation is derived from the Cephes Math Library's sin.c and
 * sinf.c. To be more specific, I took Stephen Moshier's sin, cos, sinf
 * and cosf (without changing the polynomials) and adapted them to give
 * all three required function values (in double and float versions),
 * without unnecessary accuracy losses.
 *
 * sncs1cs is not correct for values of x of huge magnitude. That can
 * be fixed by more elaborate range reduction.
 */

typedef struct {
    /* Sine, cosine, 1-cosine */
    mfloat_t sin, cos, omc;
} sincos1cos;

static
sincos1cos sncs1cs(mfloat_t x)
{
    const mfloat_t fourOverPi = 1.27323954473516268615;

    mfloat_t y, z, zz;
    mint_t j, sign = 1, csign = 1;
    sincos1cos r;

    /* Handle +-0. */
    if (x == (mfloat_t)0) {
        r.sin = x;
        r.cos = 1;
        r.omc = 0;
        return r;
    }
    if (isnan(x)) {
        r.sin = r.cos = r.omc = x;
        return r;
    }
    if (isinf(x)) {
        r.sin = r.cos = r.omc = x - x;
        return r;
    }
    if (x < 0) {
        sign = -1;
        x = -x;
    }
    j = (mint_t)(x * fourOverPi);
    y = (mfloat_t)j;
    /* map zeros to origin */
    if ((j & 1)) {
        j += 1;
        y += 1;
    }
    j = j & 7; /* octant modulo one turn */
    /* reflect in x axis */
    if (j > 3) {
        sign = -sign;
        csign = -csign;
        j -= 4;
    }
    if (j > 1) {
        csign = -csign;
    }

# if defined(MATHC_USE_SINGLE_FLOATING_POINT)
    const float sc[] = {-1.9515295891E-4, 8.3321608736E-3, -1.6666654611E-1};

    const float cc[] = {2.443315711809948E-5, -1.388731625493765E-3, 4.166664568298827E-2};

    /* These are for a 24-bit significand: */
    const float DP1 = 0.78515625;
    const float DP2 = 2.4187564849853515625e-4;
    const float DP3 = 3.77489497744594108e-8;

    /* Extended precision modular arithmetic */
    z = ((x - y * DP1) - y * DP2) - y * DP3;
    zz = z * z;
    r.sin = z + zz*z*((sc[0]*zz + sc[1])*zz + sc[2]);
    r.omc = (mfloat_t)0.5*zz - zz*zz*((cc[0]*zz + cc[1])*zz + cc[2]);
# elif defined(MATHC_USE_DOUBLE_FLOATING_POINT)
    const double sc[] = {
        1.58962301576546568060E-10,
        -2.50507477628578072866E-8,
        2.75573136213857245213E-6,
        -1.98412698295895385996E-4,
        8.33333333332211858878E-3,
        -1.66666666666666307295E-1,
    };

    const double cc[] = {
        -1.13585365213876817300E-11,
        2.08757008419747316778E-9,
        -2.75573141792967388112E-7,
        2.48015872888517045348E-5,
        -1.38888888888730564116E-3,
        4.16666666666665929218E-2,
    };

    const double DP1 = 7.85398125648498535156E-1;
    const double DP2 = 3.77489470793079817668E-8;
    const double DP3 = 2.69515142907905952645E-15;

    /* Extended precision modular arithmetic */
    z = ((x - y * DP1) - y * DP2) - y * DP3;
    zz = z * z;
    r.sin = z + zz*z*(((((sc[0]*zz + sc[1])*zz + sc[2])*zz + sc[3])*zz + sc[4])*zz + sc[5]);
    r.omc = (mfloat_t)0.5*zz - zz*zz*(((((cc[0]*zz + cc[1])*zz + cc[2])*zz + cc[3])*zz + cc[4])*zz + cc[5]);
# else
#  error "Unknown preprocessing configuration."
# endif
    if (j == 1 || j == 2) {
        if (csign < 0) {
            r.sin = -r.sin;
        }
        r.cos = r.sin;
        r.sin = 1 - r.omc;
        r.omc = 1 - r.cos;
    } else {
        if (csign < 0) {
            r.cos = r.omc - 1;
            r.omc = 1 - r.cos;
        } else {
            r.cos = 1 - r.omc;
        }
    }
    if (sign < 0) {
        r.sin = -r.sin;
    }
    return r;
}
#endif