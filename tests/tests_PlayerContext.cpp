#include <gtest/gtest.h>
#include "PlayerContext.hpp"

 
TEST(PlayerContextTest, InitialState) {
    PlayerContext context;
    EXPECT_FALSE(context.is_paused());
    EXPECT_TRUE(context.is_subtitles_enabled());
}

TEST(PlayerContextTest, toggle_pause) {
    PlayerContext context;
    EXPECT_FALSE(context.is_paused());

    context.toggle_pause();
    EXPECT_TRUE(context.is_paused());

    context.toggle_pause();
    EXPECT_FALSE(context.is_paused());
}

TEST(PlayerContextTest, toggle_subtitles) {
    PlayerContext context;
    EXPECT_TRUE(context.is_subtitles_enabled());

    context.toggle_subtitles();
    EXPECT_FALSE(context.is_subtitles_enabled());

    context.toggle_subtitles();
    EXPECT_TRUE(context.is_subtitles_enabled());
}

TEST(PlayerContextTest, Multipletoggle_pause) {
    PlayerContext context;

    for (int i = 0; i < 10; ++i) {
        context.toggle_pause();
    }

    EXPECT_FALSE(context.is_paused());
}
