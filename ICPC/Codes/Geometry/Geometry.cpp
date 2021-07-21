const ld eps = 1e-20;
const ld pi = acos(-1.0);
const enum {ON = -1, OUT, IN, OVERLAP, INF};

#define eq(a, b) (abs((a) - (b)) <= +eps)
#define neq(a, b) (!eq(a, b))
#define geq(a, b) ((a) - (b) >= -eps)
#define leq(a, b) ((a) - (b) <= +eps)
#define ge(a, b) ((a) - (b) > +eps)
#define le(a, b) ((a) - (b) < -eps) 

int sgn(ld a) { 
  return (a > eps) - (a < -eps); 
}