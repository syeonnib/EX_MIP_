// Generated by gencpp from file autoware_config_msgs/ConfigRingGroundFilter.msg
// DO NOT EDIT!


#ifndef AUTOWARE_CONFIG_MSGS_MESSAGE_CONFIGRINGGROUNDFILTER_H
#define AUTOWARE_CONFIG_MSGS_MESSAGE_CONFIGRINGGROUNDFILTER_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace autoware_config_msgs
{
template <class ContainerAllocator>
struct ConfigRingGroundFilter_
{
  typedef ConfigRingGroundFilter_<ContainerAllocator> Type;

  ConfigRingGroundFilter_()
    : sensor_model()
    , sensor_height(0.0)
    , max_slope(0.0)
    , vertical_thres(0.0)  {
    }
  ConfigRingGroundFilter_(const ContainerAllocator& _alloc)
    : sensor_model(_alloc)
    , sensor_height(0.0)
    , max_slope(0.0)
    , vertical_thres(0.0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _sensor_model_type;
  _sensor_model_type sensor_model;

   typedef float _sensor_height_type;
  _sensor_height_type sensor_height;

   typedef float _max_slope_type;
  _max_slope_type max_slope;

   typedef float _vertical_thres_type;
  _vertical_thres_type vertical_thres;





  typedef boost::shared_ptr< ::autoware_config_msgs::ConfigRingGroundFilter_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::autoware_config_msgs::ConfigRingGroundFilter_<ContainerAllocator> const> ConstPtr;

}; // struct ConfigRingGroundFilter_

typedef ::autoware_config_msgs::ConfigRingGroundFilter_<std::allocator<void> > ConfigRingGroundFilter;

typedef boost::shared_ptr< ::autoware_config_msgs::ConfigRingGroundFilter > ConfigRingGroundFilterPtr;
typedef boost::shared_ptr< ::autoware_config_msgs::ConfigRingGroundFilter const> ConfigRingGroundFilterConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::autoware_config_msgs::ConfigRingGroundFilter_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::autoware_config_msgs::ConfigRingGroundFilter_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::autoware_config_msgs::ConfigRingGroundFilter_<ContainerAllocator1> & lhs, const ::autoware_config_msgs::ConfigRingGroundFilter_<ContainerAllocator2> & rhs)
{
  return lhs.sensor_model == rhs.sensor_model &&
    lhs.sensor_height == rhs.sensor_height &&
    lhs.max_slope == rhs.max_slope &&
    lhs.vertical_thres == rhs.vertical_thres;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::autoware_config_msgs::ConfigRingGroundFilter_<ContainerAllocator1> & lhs, const ::autoware_config_msgs::ConfigRingGroundFilter_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace autoware_config_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::autoware_config_msgs::ConfigRingGroundFilter_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::autoware_config_msgs::ConfigRingGroundFilter_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::autoware_config_msgs::ConfigRingGroundFilter_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::autoware_config_msgs::ConfigRingGroundFilter_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::autoware_config_msgs::ConfigRingGroundFilter_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::autoware_config_msgs::ConfigRingGroundFilter_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::autoware_config_msgs::ConfigRingGroundFilter_<ContainerAllocator> >
{
  static const char* value()
  {
    return "35af9608c7f7db50fdce10fd09cce39f";
  }

  static const char* value(const ::autoware_config_msgs::ConfigRingGroundFilter_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x35af9608c7f7db50ULL;
  static const uint64_t static_value2 = 0xfdce10fd09cce39fULL;
};

template<class ContainerAllocator>
struct DataType< ::autoware_config_msgs::ConfigRingGroundFilter_<ContainerAllocator> >
{
  static const char* value()
  {
    return "autoware_config_msgs/ConfigRingGroundFilter";
  }

  static const char* value(const ::autoware_config_msgs::ConfigRingGroundFilter_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::autoware_config_msgs::ConfigRingGroundFilter_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string sensor_model\n"
"float32 sensor_height\n"
"float32 max_slope\n"
"float32 vertical_thres\n"
;
  }

  static const char* value(const ::autoware_config_msgs::ConfigRingGroundFilter_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::autoware_config_msgs::ConfigRingGroundFilter_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.sensor_model);
      stream.next(m.sensor_height);
      stream.next(m.max_slope);
      stream.next(m.vertical_thres);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ConfigRingGroundFilter_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::autoware_config_msgs::ConfigRingGroundFilter_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::autoware_config_msgs::ConfigRingGroundFilter_<ContainerAllocator>& v)
  {
    s << indent << "sensor_model: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.sensor_model);
    s << indent << "sensor_height: ";
    Printer<float>::stream(s, indent + "  ", v.sensor_height);
    s << indent << "max_slope: ";
    Printer<float>::stream(s, indent + "  ", v.max_slope);
    s << indent << "vertical_thres: ";
    Printer<float>::stream(s, indent + "  ", v.vertical_thres);
  }
};

} // namespace message_operations
} // namespace ros

#endif // AUTOWARE_CONFIG_MSGS_MESSAGE_CONFIGRINGGROUNDFILTER_H
