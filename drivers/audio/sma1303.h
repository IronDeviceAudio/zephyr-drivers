/*
 * Copyright 2025 Iron Device Corporation
 * Copyright (C) 2025 Atmosic
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_DRIVERS_AUDIO_SMA1303_H_
#define ZEPHYR_DRIVERS_AUDIO_SMA1303_H_

#include <zephyr/types.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/audio/codec.h>
#include <zephyr/sys/util.h>

/*
 * SMA1303 Register Definition
 */

/* SMA1303 Register Addresses */
#define  SMA1303_00_SYSTEM_CTRL		0x00
#define  SMA1303_01_INPUT1_CTRL1	0x01
#define  SMA1303_02_INPUT1_CTRL2	0x02
#define  SMA1303_0A_SPK_VOL		0x0a
#define  SMA1303_0C_BST_TEST1		0x0c
#define  SMA1303_0E_MUTE_VOL_CTRL	0x0e
#define  SMA1303_10_SYSTEM_CTRL1	0x10
#define	 SMA1303_8B_PLL_POST_N		0x8b
#define	 SMA1303_8C_PLL_N		0x8c
#define	 SMA1303_8D_PLL_A_SETTING	0x8d
#define	 SMA1303_8E_PLL_CTRL		0x8e
#define	 SMA1303_8F_PLL_P_CP		0x8f
#define	 SMA1303_A2_TOP_MAN1		0xa2
#define	 SMA1303_A4_TOP_MAN3		0xa4
#define	 SMA1303_FA_STATUS1		0xfa
#define	 SMA1303_FB_STATUS2		0xfb
#define	 SMA1303_FF_DEVICE_INDEX	0xff

/* SMA1303 Registers Bit Fields */
#define SMA1303_RESETBYI2C_MASK (1<<1)
#define SMA1303_RESETBYI2C_RESET (1<<1)
#define SMA1303_POWER_MASK (1<<0)
#define SMA1303_POWER_OFF (0<<0)
#define SMA1303_POWER_ON (1<<0)
#define SMA1303_I2S_MODE_MASK	(7<<4)
#define SMA1303_STANDARD_I2S	(0<<4)
#define SMA1303_LEFTPOL_MASK	(1<<3)
#define SMA1303_LOW_FIRST_CH	(0<<3)
#define SMA1303_HIGH_FIRST_CH	(1<<3)
#define SMA1303_SCK_RISING_MASK	(1<<2)
#define SMA1303_SCK_FALLING_EDGE	(0<<2)
#define SMA1303_SCK_RISING_EDGE	(1<<2)
#define SMA1303_IMODE_MASK (3<<6)
#define SMA1303_I2S	(0<<6)
#define SMA1303_EN_SH_PRT_MASK (1<<3)
#define SMA1303_EN_SH_PRT_DISABLE (0<<3)
#define SMA1303_SPK_MUTE_MASK (1<<0)
#define SMA1303_SPK_UNMUTE (0<<0)
#define SMA1303_SPK_MUTE (1<<0)
#define SMA1303_SPK_MODE_MASK (7<<2)
#define SMA1303_SPK_OFF (0<<2)
#define SMA1303_SPK_STEREO (4<<2)
#define SMA1303_PLL_PD2_MASK (7<<0)
#define SMA1303_PLL_PD2 (7<<0)
#define SMA1303_PLL_OPERATION2 (0<<0)
#define SMA1303_PLL_PD_MASK (1<<6)
#define SMA1303_PLL_OPERATION (0<<6)
#define SMA1303_PLL_PD (1<<6)
#define SMA1303_PLL_REF_CLK_MASK (1<<3)
#define SMA1303_PLL_REF_CLK1 (0<<3)
#define SMA1303_PLL_SCK (1<<3)
#define SMA1303_DAC_DN_CONV_MASK (1<<2)
#define SMA1303_DAC_DN_CONV_DISABLE (0<<2)
#define SMA1303_DAC_DN_CONV_ENABLE (1<<2)
#define SMA1303_O_FORMAT_MASK (7<<5)
#define SMA1303_O_FMT_I2S (2<<5)
#define SMA1303_SCK_RATE_MASK (1<<3)
#define SMA1303_SCK_64FS (0<<3)
#define SMA1303_SCK_32FS (2<<3)
#define SMA1303_OT1_OK_STATUS (1<<7)
#define SMA1303_OT2_OK_STATUS (1<<6)
#define SMA1303_OCP_SPK_STATUS (1<<5)
#define SMA1303_OCP_BST_STATUS (1<<4)
#define SMA1303_OTP_STAT_OK_0 (5<<1)
#define SMA1303_OTP_STAT_OK_1 (2<<2)
#define SMA1303_CLK_MON_STATUS (1<<0)
#define SMA1303_DEVICE_ID (2<<3)
#define SMA1303_UVLO_BST_STATUS (1<<2)
#define SMA1303_REV_NUM_STATUS (3<<0)
#define SMA1303_REV_NUM_TV0 (0<<0)
#define SMA1303_REV_NUM_TV1 (1<<0)

struct reg_default {
	unsigned int reg;
	unsigned int def;
};

#endif
