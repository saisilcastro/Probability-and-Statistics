#include "standard-of.h"

DeltaSet * delta_push(float begin, float end, float max){
	DeltaSet * set = (DeltaSet *)malloc(sizeof(DeltaSet));
	delta_zero(set); 
	set->to->begin = begin;
	set->to->end = end; 
	set->to->mid = set->to->begin + ((set->to->end - set->to->begin) * .5);
	set->max = max;
	set->balance_max = set->to->mid * set->max;
	set->balance_multiplied = set->to->mid * set->balance_max;
	return set;
}

STATUS delta_next(DeltaSet ** set, DeltaSet * next){
	if(!next)return Off;
	if (*set) {
		DeltaSet * update = *set;
		while (update->next != NULL) {
			update = update->next;
		}
		update->next = next;
		return On;
	}
	*set = next;
	return On;
}

void total_get(StandardDetour * to, DeltaSet * set, int sample){
	if(!to || !set)return;
	DeltaSet * update = set;
	while(update){
		to->balance_add += update->balance_max;
		to->balance_multiplied += update->balance_multiplied;
		to->max += update->max;
		update = update->next;
	}
	to->balance = to->balance_multiplied / to->max;
	/*
	update = set;
	while(update){
		to->balance_total += update->max * pow(update->balance_max - to->balance, 2);
		update = update->next;
	}
	*/
	to->variance = to->balance - pow(to->balance_add / to->max ,2);
	to->detour = sqrt(to->variance); 
}

void delta_pop(DeltaSet * set){
	if(!set)return;
	free(set);
	set = NULL;
}

void delta_zero(DeltaSet * set){
	if(!set)return;
	set->to->begin = 0;
	set->to->mid = 0;
	set->to->end = 0;
	set->max = 1;
	set->balance_max = 1;
	set->balance_multiplied = 1;
	set->next = NULL;
}
