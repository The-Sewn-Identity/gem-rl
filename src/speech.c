#include <stdlib.h>
#include <time.h>
#include "nother.h"
#include "speech.h"

char* DEFAULT_DIALOGUE[] = {
    "Hey there!",
    "Nice day we have today",
    "Hey"
};

char* ChooseDefaultDialogue() {
    int r = rand() % ARR_LENGTH(DEFAULT_DIALOGUE, char*);
    return DEFAULT_DIALOGUE[r];
}