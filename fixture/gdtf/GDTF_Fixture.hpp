#include "GDTF_Meta.hpp"

#include <map>
#include <string>
#include <vector>

using namespace std;

// Forward declarations of the GDTF_Attribute, GDTF_Channel, and GDTF_Mode classes
class GDTF_Attribute;
class GDTF_Channel;
class GDTF_Mode;

// The GDTF_Device class represents a lighting device
class GDTF_Device {
 public:
  // Getters and setters
  std::string GetManufacturer() const;
  void SetManufacturer(const std::string& manufacturer);
  std::string GetModel() const;
  void SetModel(const std::string& model);
  std::map<std::string, GDTF_Attribute>& GetAttributes();
  const std::map<std::string, GDTF_Attribute>& GetAttributes() const;
  void AddAttribute(const std::string& name, const GDTF_Attribute& attribute);
  void RemoveAttribute(const std::string& name);
  std::map<std::string, GDTF_Mode>& GetModes();
  const std::map<std::string, GDTF_Mode>& GetModes() const;
  void AddMode(const std::string& name, const GDTF_Mode& mode);
  void RemoveMode(const std::string& name);

 private:
  std::string manufacturer_;
  std::string model_;
  std::map<std::string, GDTF_Attribute> attributes_;
  std::map<std::string, GDTF_Mode> modes_;
};
