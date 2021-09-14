
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum{
	Off, On
}STATUS;

typedef struct WayTag{
	float begin,mid,end;
}WaySet;

typedef struct DeltaTag DeltaSet;
struct DeltaTag{
	WaySet to[1];
	float max;
	float balance_max;
	float balance_multiplied;
	DeltaSet * next;
};

typedef struct{
	float balance_add;
	float balance_multiplied;
	float max;
	float balance;
	float balance_total;
	float detour;
	float variance;
}StandardDetour;

extern DeltaSet * delta_push(float begin,float end,float n);
extern STATUS delta_next(DeltaSet ** set, DeltaSet * next);
extern void total_get(StandardDetour * to, DeltaSet * set, int sample);
extern void delta_zero(DeltaSet * set);
extern void delta_pop(DeltaSet * set);

