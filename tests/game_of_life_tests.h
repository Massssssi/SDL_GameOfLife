#pragma once
#include "unity.h"
#include "./game_of_life_tests.h"


void get_size_should_return_zero_when_grid_is_empty(void);

void get_size_test(void);

void is_stable_should_return_true_when_called_first(void);

void is_stable_should_return_true_when_called_on_clear_grid(void);

void get_next_state_should_return_clear_grid(void);