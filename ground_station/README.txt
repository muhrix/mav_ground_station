Read me for ground_station package
===============================

Contents:
---------
About this package.
Basic Usage.

------------------------------------------------------------
------------------------------------------------------------
About this package:
------------------------------------------------------------
ground_station is a ROS package for ROS Fuerte/Ubuntu 12.04
which typicaly subscribes to several topics and updates a
Gtk+ based GUI.
The GUI contains several widgets made to look like real
flight instruments in order to allow easy feedback to the
user/pilot.

The original ground_station package was a part of CCNY CityFlyer
research project.
ground_station package was released under the GNU General
Public License (GPL). Please read the file COPYING.txt.

The current version of ground_station is also under GPL.

Copyright (C) 2013, FEI University Centre
This package was modified by:
	Murilo Fernandes Martins <muhrix@gmail.com>
	http://www.fei.edu.br/~murilo
 
Copyright (C) 2010, CCNY Robotics Lab
This package was originally assembled by:
	Gautier Dumonteil <gautier.dumonteil@gmail.com>
	http://robotics.ccny.cuny.edu

------------------------------------------------------------
------------------------------------------------------------
Basic Usage:
------------------------------------------------------------
To build the ccny_ground_station ROS package for Fuerte/12.04,
run:
	roscd ground_station/
	rosdep install ccny_ground_station
	rosmake
For usage, please refer to http://www.ros.org/wiki/ground_station.
