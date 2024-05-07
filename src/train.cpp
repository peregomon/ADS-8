// Copyright 2021 NNTU-CS
#include "train.h"

void Train::addCage(bool light)
{
	if (!first) {
        Cage* newCage = new Cage;
        newCage->light = light;
        newCage->next = newCage;
        newCage->prev = newCage;
        first = newCage;
    }
    else {
        
        Cage* newCage = new Cage;
        newCage->light = light;
        newCage->next = first;
        newCage->prev = first->prev;
        first->prev->next = newCage;
        first->prev = newCage;
    }
}

int Train::getLength()
{
    first->light = true;
    Cage* tmp;
    while (first->light == true) {
        countOp = 1;
        tmp = first;
        while (tmp->next->light == false) {
            countOp++;
            tmp = tmp->next;
        }
        tmp->next->light = 0;
    }
    return countOp;
}
