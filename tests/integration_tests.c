#include "unity.h"
#include "save_grid_tests.h"
#include "read_grid_tests.h"
#include "game_of_life_tests.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(get_size_should_return_zero_when_grid_is_empty);
    RUN_TEST(get_size_test);
    RUN_TEST(is_stable_should_return_true_when_called_first);
    RUN_TEST(is_stable_should_return_true_when_called_on_clear_grid);
    RUN_TEST(get_next_state_should_return_clear_grid);
    return UNITY_END();
}