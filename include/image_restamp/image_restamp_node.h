#ifndef IMAGE_RESTAMP_HEADER_GUARD
#define IMAGE_RESTAMP_HEADER_GUARD

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/CameraInfo.h>

class ImageRestampper
{
public:
	ImageRestampper();
	~ImageRestampper();
	void imageCallback(const sensor_msgs::ImageConstPtr& msg);
	void cameraInfoCallback(const sensor_msgs::CameraInfoConstPtr& msg);


private:
	ros::NodeHandle nh;
	image_transport::ImageTransport it;
	image_transport::Subscriber image_sub;
	image_transport::Publisher image_pub;

	ros::Subscriber camera_info_sub;
	ros::Publisher  camera_info_pub;
};

#endif