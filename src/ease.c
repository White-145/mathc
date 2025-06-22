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

#if defined(MATHC_USE_FLOATING_POINT) && defined(MATHC_USE_EASING_FUNCTIONS)
mfloat_t quadratic_ease_out(mfloat_t f) {
    return -f * (f - MFLOAT_C(2.0));
}

mfloat_t quadratic_ease_in(mfloat_t f) {
    return f * f;
}

mfloat_t quadratic_ease_in_out(mfloat_t f) {
    mfloat_t a = MFLOAT_C(0.0);
    if (f < MFLOAT_C(0.5)) {
        a = MFLOAT_C(2.0) * f * f;
    } else {
        a = -MFLOAT_C(2.0) * f * f + MFLOAT_C(4.0) * f - MFLOAT_C(1.0);
    }
    return a;
}

mfloat_t cubic_ease_out(mfloat_t f) {
    mfloat_t a = f - MFLOAT_C(1.0);
    return a * a * a + MFLOAT_C(1.0);
}

mfloat_t cubic_ease_in(mfloat_t f) {
    return f * f * f;
}

mfloat_t cubic_ease_in_out(mfloat_t f) {
    mfloat_t a = MFLOAT_C(0.0);
    if (f < MFLOAT_C(0.5)) {
        a = MFLOAT_C(4.0) * f * f * f;
    } else {
        a = MFLOAT_C(2.0) * f - MFLOAT_C(2.0);
        a = MFLOAT_C(0.5) * a * a * a + MFLOAT_C(1.0);
    }
    return a;
}

mfloat_t quartic_ease_out(mfloat_t f) {
    mfloat_t a = f - MFLOAT_C(1.0);
    return a * a * a * (MFLOAT_C(1.0) - f) + MFLOAT_C(1.0);
}

mfloat_t quartic_ease_in(mfloat_t f) {
    return f * f * f * f;
}

mfloat_t quartic_ease_in_out(mfloat_t f) {
    mfloat_t a = MFLOAT_C(0.0);
    if (f < MFLOAT_C(0.5)) {
        a = MFLOAT_C(8.0) * f * f * f * f;
    } else {
        a = f - MFLOAT_C(1.0);
        a = -MFLOAT_C(8.0) * a * a * a * a + MFLOAT_C(1.0);
    }
    return a;
}

mfloat_t quintic_ease_out(mfloat_t f) {
    mfloat_t a = f - MFLOAT_C(1.0);
    return a * a * a * a * a + MFLOAT_C(1.0);
}

mfloat_t quintic_ease_in(mfloat_t f) {
    return f * f * f * f * f;
}

mfloat_t quintic_ease_in_out(mfloat_t f) {
    mfloat_t a = MFLOAT_C(0.0);
    if (f < MFLOAT_C(0.5)) {
        a = MFLOAT_C(16.0) * f * f * f * f * f;
    } else {
        a = MFLOAT_C(2.0) * f - MFLOAT_C(2.0);
        a = MFLOAT_C(0.5) * a * a * a * a * a + MFLOAT_C(1.0);
    }
    return a;
}

mfloat_t sine_ease_out(mfloat_t f) {
    return MSIN(f * MPI_2);
}

mfloat_t sine_ease_in(mfloat_t f) {
    return MSIN((f - MFLOAT_C(1.0)) * MPI_2) + MFLOAT_C(1.0);
}

mfloat_t sine_ease_in_out(mfloat_t f) {
#if defined(MATHC_PRECISE_TRIGONOMETRY)
    sincos1cos sc1c = sncs1cs(f * MPI);
    return MFLOAT_C(0.5) * sc1c.omc;
#else
    return MFLOAT_C(0.5) * (MFLOAT_C(1.0) - MCOS(f * MPI));
#endif
}

mfloat_t circular_ease_out(mfloat_t f) {
    return MSQRT((MFLOAT_C(2.0) - f) * f);
}

mfloat_t circular_ease_in(mfloat_t f) {
    return MFLOAT_C(1.0) - MSQRT(MFLOAT_C(1.0) - (f * f));
}

mfloat_t circular_ease_in_out(mfloat_t f) {
    mfloat_t a = MFLOAT_C(0.0);
    if (f < MFLOAT_C(0.5)) {
        a = MFLOAT_C(0.5) * (MFLOAT_C(1.0) - MSQRT(MFLOAT_C(1.0) - MFLOAT_C(4.0) * f * f));
    } else {
        a = MFLOAT_C(0.5) * (MSQRT(-(MFLOAT_C(2.0) * f - MFLOAT_C(3.0)) * (MFLOAT_C(2.0) * f - MFLOAT_C(1.0))) + MFLOAT_C(1.0));
    }
    return a;
}

mfloat_t exponential_ease_out(mfloat_t f) {
    mfloat_t a = f;
    if (MFABS(a) > MFLT_EPSILON) {
        a = MFLOAT_C(1.0) - MPOW(MFLOAT_C(2.0), -MFLOAT_C(10.0) * f);
    }
    return a;
}

mfloat_t exponential_ease_in(mfloat_t f) {
    mfloat_t a = f;
    if (MFABS(a) > MFLT_EPSILON) {
        a = MPOW(MFLOAT_C(2.0), MFLOAT_C(10.0) * (f - MFLOAT_C(1.0)));
    }
    return a;
}

mfloat_t exponential_ease_in_out(mfloat_t f) {
    mfloat_t a = f;
    if (f < MFLOAT_C(0.5)) {
        a = MFLOAT_C(0.5) * MPOW(MFLOAT_C(2.0), (MFLOAT_C(20.0) * f) - MFLOAT_C(10.0));
    } else {
        a = -MFLOAT_C(0.5) * MPOW(MFLOAT_C(2.0), -MFLOAT_C(20.0) * f + MFLOAT_C(10.0)) + MFLOAT_C(1.0);
    }
    return a;
}

mfloat_t elastic_ease_out(mfloat_t f) {
    return MSIN(-MFLOAT_C(13.0) * MPI_2 * (f + MFLOAT_C(1.0))) * MPOW(MFLOAT_C(2.0), -MFLOAT_C(10.0) * f) + MFLOAT_C(1.0);
}

mfloat_t elastic_ease_in(mfloat_t f) {
    return MSIN(MFLOAT_C(13.0) * MPI_2 * f) * MPOW(MFLOAT_C(2.0), MFLOAT_C(10.0) * (f - MFLOAT_C(1.0)));
}

mfloat_t elastic_ease_in_out(mfloat_t f) {
    mfloat_t a = MFLOAT_C(0.0);
    if (f < MFLOAT_C(0.5)) {
        a = MFLOAT_C(0.5) * MSIN(MFLOAT_C(13.0) * MPI_2 * (MFLOAT_C(2.0) * f)) * MPOW(MFLOAT_C(2.0), MFLOAT_C(10.0) * ((MFLOAT_C(2.0) * f) - MFLOAT_C(1.0)));
    } else {
        a = MFLOAT_C(0.5) * (MSIN(-MFLOAT_C(13.0) * MPI_2 * ((MFLOAT_C(2.0) * f - MFLOAT_C(1.0)) + MFLOAT_C(1.0))) * MPOW(MFLOAT_C(2.0), -MFLOAT_C(10.0) * (MFLOAT_C(2.0) * f - MFLOAT_C(1.0))) + MFLOAT_C(2.0));
    }
    return a;
}

mfloat_t back_ease_out(mfloat_t f) {
    mfloat_t a = MFLOAT_C(1.0) - f;
    return MFLOAT_C(1.0) - (a * a * a - a * MSIN(a * MPI));
}

mfloat_t back_ease_in(mfloat_t f) {
    return f * f * f - f * MSIN(f * MPI);
}

mfloat_t back_ease_in_out(mfloat_t f) {
    mfloat_t a = MFLOAT_C(0.0);
    if (f < MFLOAT_C(0.5)) {
        a = MFLOAT_C(2.0) * f;
        a = MFLOAT_C(0.5) * (a * a * a - a * MSIN(a * MPI));
    } else {
        a = (MFLOAT_C(1.0) - (MFLOAT_C(2.0) * f - MFLOAT_C(1.0)));
        a = MFLOAT_C(0.5) * (MFLOAT_C(1.0) - (a * a * a - a * MSIN(f * MPI))) + MFLOAT_C(0.5);
    }
    return a;
}

mfloat_t bounce_ease_out(mfloat_t f) {
    mfloat_t a = MFLOAT_C(0.0);
    if (f < MFLOAT_C(4.0) / MFLOAT_C(11.0)) {
        a = (MFLOAT_C(121.0) * f * f) / MFLOAT_C(16.0);
    } else if (f < MFLOAT_C(8.0) / MFLOAT_C(11.0)) {
        a = (MFLOAT_C(363.0) / MFLOAT_C(40.0) * f * f) - (MFLOAT_C(99.0) / MFLOAT_C(10.0) * f) + MFLOAT_C(17.0) / MFLOAT_C(5.0);
    } else if (f < MFLOAT_C(9.0) / MFLOAT_C(10.0)) {
        a = (MFLOAT_C(4356.0) / MFLOAT_C(361.0) * f * f) - (MFLOAT_C(35442.0) / MFLOAT_C(1805.0) * f) + MFLOAT_C(16061.0) / MFLOAT_C(1805.0);
    } else {
        a = (MFLOAT_C(54.0) / MFLOAT_C(5.0) * f * f) - (MFLOAT_C(513.0) / MFLOAT_C(25.0) * f) + MFLOAT_C(268.0) / MFLOAT_C(25.0);
    }
    return a;
}

mfloat_t bounce_ease_in(mfloat_t f) {
    return MFLOAT_C(1.0) - bounce_ease_out(MFLOAT_C(1.0) - f);
}

mfloat_t bounce_ease_in_out(mfloat_t f) {
    mfloat_t a = MFLOAT_C(0.0);
    if (f < MFLOAT_C(0.5)) {
        a = MFLOAT_C(0.5) * bounce_ease_in(f * MFLOAT_C(2.0));
    } else {
        a = MFLOAT_C(0.5) * bounce_ease_out(f * MFLOAT_C(2.0) - MFLOAT_C(1.0)) + MFLOAT_C(0.5);
    }
    return a;
}
#endif