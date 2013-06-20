Read me for osmgpsmap package
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
osmgpsmap is a package providing a local installation of
osm-gps-map for ROS Fuerte running on Ubuntu 12.04.
osm-gps-map is released under the GNU General Public License (GPL).
Please read the file COPYING.txt.

Copyright (C) 2013, FEI University Centre
This package was modified by:
	Murilo Fernandes Martins <muhrix@gmail.com>
	http://www.fei.edu.br/~murilo

Copyright (C) 2010, CCNY Robotics Lab
This pkg was originally assembled by:
	Gautier Dumonteil <gautier.dumonteil@gmail.com>
	http://robotics.ccny.cuny.edu

------------------------------------------------------------
------------------------------------------------------------
Requirements:
------------------------------------------------------------
osmgpsmap requires libsoup2.4 (more specifically, Ubuntu packages
libsoup2.4-1 and libsoup2.4-dev). 
It is advisable to install such dependencies prior to building
this package (ideally, rosdep should take care of dependencies).
This package was modified to work with ROS Fuerte on Ubuntu 12.04.

This is currently compatible with the UMD gpsd_client:
http://www.ros.org/wiki/gpsd_client
ROS Fuerte has a package called ros-fuerte-gps-umd, which
should be installed.
------------------------------------------------------------
------------------------------------------------------------
Basic Usage:
------------------------------------------------------------
NOTICE: currently, this modified version of osmgpsmap is
bundled with ccny_ground_station.
(https://github.com/muhrix/ccny_ground_station/)

To install dependencies and compile, run in a shell:
	roscd osmgpsmap/
	rosdep install osmgpsmap
	rosmake
