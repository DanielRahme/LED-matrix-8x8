#ifndef _ANIMATION_HPP
#define _ANIMATION_HPP

#include <array>
#include "pattern.hpp"

constexpr auto MAX_FRAMES = 8;

using frames_t = std::array<Pattern, MAX_FRAMES>;

struct Animation {
  frames_t frames = {};
  int frame_time;

  // TODO: make it variable length
  Animation(frames_t fs, int ft = 100) : frames(fs),frame_time(ft)  {};
};


#endif
