#include <ros/ros.h>
#include <tf/transform_datatypes.h>
#include <asctec_hl_comm/mav_imu.h>
#include <cmath>

int main(int argc, char **argv) {
	asctec_hl_comm::mav_imu imu;
	ros::init(argc, argv, "fake_data");
	ros::NodeHandle n;
	ros::Publisher pub = n.advertise<asctec_hl_comm::mav_imu>("fake_imu", 1);

	int rate = 10; // Hz
	// 20 Hz means the loop runs every 50 milliseconds
	ros::Rate loop_rate(rate);

	const double max_height = 1000.0; // metres
	double alt = max_height/2.0;
	double c = 0.5;
	double inc = 0.001;
	double prev_height = alt;
	double delta_height;

	double s = 0, s_prev = 0, v = 0, v_prev = 0;
	double a = 10;
	double t = 1.0/(double)rate;

	double turning_t = std::sqrt(max_height/a);
	double turning_v = a * turning_t;

	double roll = 0, pitch = 0, yaw = 0;
	tf::Quaternion orientation;
	orientation.setRPY(roll, pitch, yaw);

	//ROS_INFO_STREAM("t_t = " << turning_t << "\tt_v = " << turning_v);

	while (ros::ok()) {
		v = v_prev + a*t;
		s = s_prev + v_prev * t + 0.5 * a * t*t;
		v_prev = v;
		s_prev = s;

		if (v >= turning_v) {
			a = -10.0;
		}
		else if (v <= -turning_v) {
			a = 10.0;
		}

		//ROS_INFO_STREAM("v = " << v);
		//ROS_INFO_STREAM("a = " << a);
		//ROS_INFO_STREAM("s = " << s);
		//ROS_INFO_STREAM("t = " << t);

		/*
		if (c > 1.0) {
			c = 1.0;
			inc = -0.001;
		}
		if (c < 0.0) {
			c = 0.0;
			inc = 0.001;
		}
		alt = c*max_height;
		c += inc;
		*/
		alt = s;

		delta_height = alt - prev_height;
		prev_height = alt;

		imu.height = alt; // * 1000.0; // must be in [mm]
		imu.differential_height = delta_height * (double)rate; // * 1000.0; // must be in [mm/s]
		imu.orientation.x = orientation.getX();
		imu.orientation.y = orientation.getY();
		imu.orientation.w = orientation.getW();
		imu.orientation.z = orientation.getZ();
		pub.publish(imu);
		ros::spinOnce();
		loop_rate.sleep();
	}
}
