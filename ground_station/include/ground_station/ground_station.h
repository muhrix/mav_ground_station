/*
 *  Ground Station for ROS Fuerte/Ubuntu Precise
 *  Copyright (C) 2013, FEI University Centre
 *  Murilo Fernandes Martins <muhrix@gmail.com>
 *  http://www.fei.edu.br/~murilo
 *
 *  Originally implemented for CityFlyer CCNY project
 *  Copyright (C) 2010, CCNY Robotics Lab
 *  Gautier Dumonteil <gautier.dumonteil@gmail.com>
 *  http://robotics.ccny.cuny.edu
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file ground_station.h 
 * @brief Gtk GUI which subscribes to ROS topics and displays telemetry data
 * @author Gautier Dumonteil <gautier.dumonteil@gmail.com>
 * @author Murilo Fernandes Martins <muhrix@gmail.com>
 * @version 0.2
 * @date 22/06/2013
 *
 * Ground Station for ROS Fuerte/Ubuntu Precise
 * Copyright (C) 2013, FEI University Centre
 * Copyright (C) 2010, CCNY Robotics Lab
 *  
 */

#ifndef CCNY_GROUND_STATION_GROUND_STATION_H
#define CCNY_GROUND_STATION_GROUND_STATION_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <glib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <ros/ros.h>
#include <ros/package.h>
#include <tf/transform_datatypes.h>
#include <tf/transform_broadcaster.h>
#include <sensor_msgs/Imu.h>
#include <sensor_msgs/NavSatFix.h>
#include <asctec_hl_comm/mav_imu.h>
#include <asctec_hl_comm/mav_status.h>
#include <asctec_hl_comm/mav_rcdata.h>
#include <sensor_fusion_comm/ExtEkf.h>
#include <asctec_msgs/GPSData.h>
#include <asctec_msgs/IMUCalcData.h>
#include <asctec_msgs/LLStatus.h>
#include <mav_msgs/Height.h>
#include <gps_common/GPSFix.h>
#include <gps_common/GPSStatus.h>

#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

#include <ground_station/gui/ground_station_appdata.h>
#include <ground_station/gui/gtkaltimeter.h>
#include <ground_station/gui/gtkvariometer.h>
#include <ground_station/gui/gtkcompass.h>
#include <ground_station/gui/gtkgauge.h>
#include <ground_station/gui/gtkbargauge.h>
#include <ground_station/gui/gtkturncoordinator.h>
#include <ground_station/gui/gtkartificialhorizon.h>
#include <ground_station/gui/gpsd_viewer_osd.h>

const std::string imuTopic = "imu/data";
const std::string heightTopic = "/asctec_proc/pressure_height";
const std::string imuCalcDataTopic = "/autopilot/IMU_CALCDATA";
//const std::string gpsDataTopic = "/autopilot/GPS_DATA";
const std::string llStatusTopic = "/autopilot/LL_STATUS";

#define RAD2DEG(RAD) ((RAD)*((180.)/(M_PI)))

/**
 * @struct arg
 * @brief Allow to pass the arguments of the program to a pthread.<br>
 * Allow to use ROS params even ROS is in a child thread of Gtk.
 */
struct arg {
	int argc;
	char **argv;
};

ros::Subscriber imuSub;
ros::Subscriber heightSub;
ros::Subscriber imuCalcDataSub;
//ros::Subscriber gpsDataSub;
ros::Subscriber llStatusSub;
ros::Subscriber gpsFixSub;

sensor_msgs::Imu imuData_;
mav_msgs::Height heightData_;
asctec_msgs::IMUCalcData imuCalcData_;
//asctec_msgs::GPSData gpsData_;
asctec_msgs::LLStatus llStatus_;

void *startROS(void *);
void imuCalcDataCallback(const asctec_msgs::IMUCalcDataConstPtr &);
//void gpsDataCallback (const asctec_msgs::GPSDataConstPtr &);
void llStatusCallback(const asctec_msgs::LLStatusConstPtr &);
gboolean widgets_update(gpointer dat);

#endif
