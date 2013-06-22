ccny_ground_station
===================

My own port of the ROS ground_station stack originally implemented by the folks from CCNY, forked from ccny-ros-pkg-pbouffard.
It is a work in progress to get it working with ROS Fuerte on Ubuntu 12.04 (Precise).
In order for the stack (i.e., the 3 packages within it) to compile, some system dependencies must be already installed.
The list of packages one should install (e.g., using apt-get install) are:
gnome-common
gtk-doc-tools
libsoup2.4-1
libsoup2.4-dev
libglade2-0
libglade2-dev

In addition, one should install the following ROS packages:
ros-fuerte-gps-drivers
ros-fuerte-gps-umd

DISCLAIMER:
I cannot guarantee there will not be any other dependency not met on systems other than mine.
I have installed Ubuntu 12.04.1 and ROS Fuerte (ros-fuerte-desktop-full).
I have also installed a handful of other packages, so please do pay attention to the output messages whislt running rosmake.

