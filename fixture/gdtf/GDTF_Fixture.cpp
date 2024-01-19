#include "GDTF_Fixture.hpp"
    
std::string GDTF_Device::GetManufacturer() const {
  return manufacturer_;
}

void GDTF_Device::SetManufacturer(const std::string& manufacturer) {
  manufacturer_ = manufacturer;
}

std::string GDTF_Device::GetModel() const {
  return model_;
}

void GDTF_Device::SetModel(const std::string& model) {
  model_ = model;
}

std::map<std::string, GDTF_Attribute>& GDTF_Device::GetAttributes() {
  return attributes_;
}

const std::map<std::string, GDTF_Attribute>& GDTF_Device::GetAttributes() const {
  return attributes_;
}

void GDTF_Device::AddAttribute(const std::string& name, const GDTF_Attribute& attribute) {
  attributes_.emplace(name, attribute);
}

void GDTF_Device::RemoveAttribute(const std::string& name) {
  attributes_.erase(name);
}

std::map<std::string, GDTF_Mode>& GDTF_Device::GetModes() {
  return modes_;
}

const std::map<std::string, GDTF_Mode>& GDTF_Device::GetModes() const {
  return modes_;
}

void GDTF_Device::AddMode(const std::string& name, const GDTF_Mode& mode) {
  modes_.emplace(name, mode);
}

void GDTF_Device::RemoveMode(const std::string& name) {
  modes_.erase(name);
}
