#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <map>
#include <string>
#include <vector>

#ifndef GDTF_META_HPP
#define GDTF_META_HPP

// The GDTF_Attribute class represents a device attribute
class GDTF_Attribute
{
public:
    // Getters and setters
    std::string GetName() const { return name_; }
    void SetName(const std::string &name) { name_ = name; }
    std::string GetValue() const { return value_; }
    void SetValue(const std::string &value) { value_ = value; }

private:
    std::string name_;
    std::string value_;
};

// The GDTF_Channel class represents a device channel
class GDTF_Channel
{
public:
    // Getters and setters
    std::string GetName() const { return name_; }
    void SetName(const std::string &name) { name_ = name; }
    int GetNumber() const { return number_; }
    void SetNumber(int number) { number_ = number; }
    std::string GetType() const { return type_; }
    void SetType(const std::string &type) { type_ = type; }
    std::string GetSubType() const { return sub_type_; }
    void SetSubType(const std::string &sub_type) { sub_type_ = sub_type; }

private:
    std::string name_;
    int number_;
    std::string type_;
    std::string sub_type_;
};

// The GDTF_Mode class represents a device mode
class GDTF_Mode
{
public:
    // Getters and setters
    std::string GetName() const { return name_; }
    void SetName(const std::string &name) { name_ = name; }
    std::string GetType() const { return type_; }
    void SetType(const std::string &type) { type_ = type; }
    std::map<std::string, GDTF_Channel> &GetChannels() { return channels_; }
    const std::map<std::string, GDTF_Channel> &GetChannels() const { return channels_; }
    void AddChannel(const std::string &name, const GDTF_Channel &channel) { channels_[name] = channel; }
    void RemoveChannel(const std::string &name) { channels_.erase(name); }

private:
    std::string name_;
    std::string type_;
    std::map<std::string, GDTF_Channel> channels_;
};

#endif