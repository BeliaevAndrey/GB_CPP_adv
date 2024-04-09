
class Toy {
private:
    std::string name;
public:
    Toy(std::string inName) : name(inName) {};
    Toy() : name("SomeToy") {};
    std::string getName() { return name; }
};
