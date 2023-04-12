// Copyright 2022 Michael McCoyd (@mmccoyd)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Some boards have issues detecting handedness using the vbus voltage.
// Such as Elite-C v3, but not v3.1 on. Also apparently some ProMicro boards.
// For those boands, use usb detection instead.
#undef SPLIT_HAND_MATRIX_GRID
#define EE_HANDS

#define TAPPING_TERM 275
#define AUTO_SHIFT_TIMEOUT 250

#define RGBLIGHT_ANIMATIONS
#define RETRO_SHIFT
#define AUTO_SHIFT_MODIFIERS
#define AUTO_SHIFT_REPEAT
#define AUTO_SHIFT_NO_AUTO_REPEAT

#undef MOUSEKEY_DELAY
#undef MOUSEKEY_INTERVAL
#undef MOUSEKEY_MOVE_DELTA
#undef MOUSEKEY_MAX_SPEED
#undef MOUSEKEY_TIME_TO_MAX
#undef MOUSEKEY_WHEEL_DELAY
#undef MOUSEKEY_WHEEL_INTERVAL
#undef MOUSEKEY_WHEEL_MAX_SPEED
#undef MOUSEKEY_WHEEL_TIME_TO_MAX

//#define MK_KINETIC_SPEED
#ifdef MK_KINETIC_SPEED
#define MOUSEKEY_DELAY 5
#define MOUSEKEY_INTERVAL 8
#define MOUSEKEY_MOVE_DELTA 16
#define MOUSEKEY_INITIAL_SPEED 25
#define MOUSEKEY_BASE_SPEED 5000
#define MOUSEKEY_DECELERATED_SPEED 400
#define MOUSEKEY_ACCELERATED_SPEED 1800
#else
#define MOUSEKEY_DELAY 25
#define MOUSEKEY_INTERVAL 8
#define MOUSEKEY_MOVE_DELTA 1
#define MOUSEKEY_MAX_SPEED 20
#define MOUSEKEY_TIME_TO_MAX 90

#define MOUSEKEY_WHEEL_DELAY 10
#define MOUSEKEY_WHEEL_INTERVAL 80
#define MOUSEKEY_WHEEL_MAX_SPEED 8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40
#endif

