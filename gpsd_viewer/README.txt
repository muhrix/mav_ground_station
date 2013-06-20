Read me for gpsd_viewer package
===============================

Contents:
---------
About this package.
Requirements.
Basic Usage.

------------------------------------------------------------
------------------------------------------------------------
About this package:
------------------------------------------------------------
gpsd_viewer is a package for ROS (adapted for Fuerte/Precise)
that typicaly subscribes to gpsd odometry topic and, using
osmgpsmap, draws the gps pose in a map (default: Open Street Map).
gpsd_viewer is released under the GNU General Public License (GPL). 
Please read the file COPYING.txt.

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
Requirements:
------------------------------------------------------------
gpsd_viewer requires osmgpsmap libraries and include files.
The osmgpsmap ROS package bundled with this version of
ccny_ground_station is a dependency of this package.
This package was modified to work with ROS Fuerte on Ubuntu
12.04.

This is currently compatible with the UMD gpsd_client:
http://www.ros.org/wiki/gpsd_client
ROS Fuerte has a package called ros-fuerte-gps-umd, which
should be installed.
------------------------------------------------------------
------------------------------------------------------------
Basic Usage:
------------------------------------------------------------
NOTICE: currently, this modified version of gpsd_viewer is
bundled with ccny_ground_station.
(https://github.com/muhrix/ccny_ground_station/)

To install dependencies and compile, run in a shell:
	roscd osmgpsmap/
	rosdep install osmgpsmap
	rosmake
	
Run the example (untested under Fuerte/Precise as of yet):
	roscd gpsd_viewer/
	cd demo/
	./setup.sh
	roslaunch demo.launch
