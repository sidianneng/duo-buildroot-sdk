/******************************************************************************
 *
 * Copyright(c) 2013 - 2017 Realtek Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 *****************************************************************************/
#include <drv_types.h>
#include <linux/gpio.h>

extern int cvi_get_wifi_pwr_on_gpio(void);
/*
 * Return:
 *	0:	power on successfully
 *	others:	power on failed
 */
int platform_wifi_power_on(void)
{
	int ret = 0;

	int pwr_pin = cvi_get_wifi_pwr_on_gpio();

	gpio_direction_output(pwr_pin, 1);
	udelay(100);
	gpio_direction_output(pwr_pin, 1);
	udelay(1500);
	gpio_direction_output(pwr_pin, 1);
	udelay(100);
	printk("xiongjian rtl8189fs power on ok\n");

	return ret;
}

void platform_wifi_power_off(void)
{
        int pwr_pin = cvi_get_wifi_pwr_on_gpio();

        gpio_direction_output(pwr_pin, 0);
        udelay(100);
        printk("xiongjian rtl8189fs power off ok\n");
}

