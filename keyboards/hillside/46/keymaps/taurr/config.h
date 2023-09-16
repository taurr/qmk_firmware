// Copyright 2022 Michael McCoyd (@mmccoyd)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
// Some boards have issues detecting handedness using the vbus voltage.
// Such as Elite-C v3, but not v3.1 on. Also apparently some ProMicro boards.
// For those boands, use usb detection instead.
//#undef SPLIT_HAND_MATRIX_GRID
//#define EE_HANDS
//#define SPLIT_USB_DETECT

#define TAPPING_TERM 180
#define QUICK_TAP_TERM 150

#define DYNAMIC_MACRO_SIZE 512

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_TRANSPORT_MIRROR

#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_TWINKLE

#undef MOUSEKEY_DELAY
#undef MOUSEKEY_INTERVAL
#undef MOUSEKEY_MOVE_DELTA
#undef MOUSEKEY_MAX_SPEED
#undef MOUSEKEY_TIME_TO_MAX
#undef MOUSEKEY_WHEEL_DELAY
#undef MOUSEKEY_WHEEL_INTERVAL
#undef MOUSEKEY_WHEEL_MAX_SPEED
#undef MOUSEKEY_WHEEL_TIME_TO_MAX

#define MK_KINETIC_SPEED
#ifdef MK_KINETIC_SPEED
#define MOUSEKEY_DELAY 5
// time between cursor movements in milliseconds
#define MOUSEKEY_INTERVAL 10
// step size for accelerating from initial to base speed
#define MOUSEKEY_MOVE_DELTA 16
// initial speed in pixels per second
#define MOUSEKEY_INITIAL_SPEED 100
// final speed in pixels per second
#define MOUSEKEY_BASE_SPEED 3000

#define MOUSEKEY_DECELERATED_SPEED 400
#define MOUSEKEY_ACCELERATED_SPEED 3000

#define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS 16
#define MOUSEKEY_WHEEL_BASE_MOVEMENTS 24
#define MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS 48
#define MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS 8
#else
#define MOUSEKEY_DELAY 10
#define MOUSEKEY_INTERVAL 8
#define MOUSEKEY_MOVE_DELTA 1
#define MOUSEKEY_MAX_SPEED 20
#define MOUSEKEY_TIME_TO_MAX 60

#define MOUSEKEY_WHEEL_DELAY 10
#define MOUSEKEY_WHEEL_INTERVAL 64
#define MOUSEKEY_WHEEL_DELTA 1
#define MOUSEKEY_WHEEL_MAX_SPEED 8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 0
#endif

