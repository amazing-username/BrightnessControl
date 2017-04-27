#!/bin/sh
you=$1

sudo chown $you /sys/class/backlight/intel_backlight/brightness
#ls -l /sys/class/backlight/intel_backlight/
