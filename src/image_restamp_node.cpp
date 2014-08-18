#include <image_restamp/image_restamp_node.h>

ImageRestampper::ImageRestampper() : it(nh)	
{
	image_sub = it.subscribe("camera/image_raw_old", 1, boost::bind(&ImageRestampper::imageCallback, this, _1));
	image_pub = it.advertise("camera/image_raw", 1);

	camera_info_sub = nh.subscribe<sensor_msgs::CameraInfo>("camera/camera_info_old", 1, boost::bind(&ImageRestampper::cameraInfoCallback, this, _1));
	camera_info_pub = nh.advertise<sensor_msgs::CameraInfo>("camera/camera_info", 1);
}

ImageRestampper::~ImageRestampper()
{

}

void ImageRestampper::imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
	sensor_msgs::Image new_msg = *msg;
	new_msg.header.stamp = ros::Time::now();
	image_pub.publish(new_msg);
}

void ImageRestampper::cameraInfoCallback(const sensor_msgs::CameraInfoConstPtr& msg)
{
	sensor_msgs::CameraInfo new_msg = *msg;
	new_msg.header.stamp = ros::Time::now();
	camera_info_pub.publish(new_msg);
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "image_restamp");
	ImageRestampper ir;
	ros::spin();
	return 0;
}

