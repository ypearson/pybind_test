#include <string>

class SomeObject {
 public:
  SomeObject(const std::string &name, const std::string &type)
      : name(name), type(type) {}
  ~SomeObject() {}

  void setName(const std::string &name) { this->name = name; }

  std::string getName() const { return name; }

  void setType(const std::string &type) { this->type = type; }

  std::string getType() const { return type; }

 private:
  std::string name;
  std::string type;
};
