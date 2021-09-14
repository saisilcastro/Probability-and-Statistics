#include "standard-of.h"

void detour_and_variance(DeltaSet ** a,int choice) {
	switch(choice) {
		case 0: {
			delta_next(a,delta_push(2, 6, 5));
			delta_next(a,delta_push(6, 10, 12));
			delta_next(a,delta_push(10, 14, 21));
			delta_next(a,delta_push(14, 18, 15));
			delta_next(a,delta_push(18, 22, 7));			
			break;
		}
		case 1: {
			delta_next(a,delta_push(91, 91, 1));
			delta_next(a,delta_push(93, 93, 1));
			delta_next(a,delta_push(95, 95, 1));
			delta_next(a,delta_push(89, 89, 1));
			
			break;
		}
		case 2: {
			delta_next(a,delta_push(96, 96, 1));
			delta_next(a,delta_push(88, 88, 1));
			delta_next(a,delta_push(98, 98, 1));
			delta_next(a,delta_push(86, 86, 1));
			break;
		}
		case 3: {
			printf("in reserved\n");
			delta_next(a,delta_push(2.9, 3.2, 1));
			delta_next(a,delta_push(3.2, 3.5, 1));
			delta_next(a,delta_push(3.5, 3.8, 2));
			delta_next(a,delta_push(3.8, 4.1, 5));
			delta_next(a,delta_push(4.1, 4.4, 11));
			delta_next(a,delta_push(4.4, 4.7, 8));
			break;
		}
		case 4:{
			delta_next(a,delta_push(18, 27, 38));
			delta_next(a,delta_push(27, 36, 147));
			delta_next(a,delta_push(36, 45, 74));
			delta_next(a,delta_push(45, 54, 121));
			delta_next(a,delta_push(54, 63, 20));
			break;
		}
		case 5:{
			delta_next(a,delta_push(4, 4, 1));
			delta_next(a,delta_push(5, 5, 1));
			delta_next(a,delta_push(5, 5, 1));
			delta_next(a,delta_push(8, 8, 1));
			break;
		}
		case 6:{
			delta_next(a,delta_push(2, 2, 1));
			delta_next(a,delta_push(8, 8, 1));
			delta_next(a,delta_push(5, 5, 1));
			delta_next(a,delta_push(6, 6, 1));
			break;
		}
		case 7:{
			delta_next(a,delta_push(3, 3, 1));
			delta_next(a,delta_push(7, 7, 1));
			delta_next(a,delta_push(6, 6, 1));
			delta_next(a,delta_push(5, 5, 1));
			delta_next(a,delta_push(4, 4, 1));
			break;
		}
	}
}

int main(int c, char ** v) {
	DeltaSet * a = NULL;
	detour_and_variance(&a, 4);
	StandardDetour ld = {0, 0, 0, 0, 0, 0, 0},* to = &ld;
	total_get(to, a, 0);
	//printf("begin[%.0f] mid[%.0f] end[%.0f] n[%.0f] to_n[%.0f] times_to_n[%.0f]\n",b->to->begin,b->to->mid,b->to->end,b->n,b->to_n,b->times_to_n);
	printf("%.2f %.2f\n",to->variance,to->detour);
	delta_pop(a);
	return 0;
}
