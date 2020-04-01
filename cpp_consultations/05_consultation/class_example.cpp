#include <iostream>
#include <string>
#include <vector>

using u16 = uint16_t;

class Group {
public:
    Group() = default;

    explicit Group(const std::string& name, u16 count = 0)
        : name_{name}, count_{count} {
            std::cout << "Group " << GetName() << " created!\n";
        }

    explicit Group(const Group& other)
        : name_{other.GetName()}, count_{other.GetCount()} {
            std::cout << "Group " << other.GetName() << " copied!\n";
        }

    ~Group() {
        std::cout << "Group " << GetName() << " expelled!\n";
        // Destructor for name_ and count_ will called here.
    }

    Group& operator=(const Group& other) {
        if (this != &other) {  // Not necessarily in this class.
            name_ = other.GetName();
            count_ = other.GetCount();
        }
        return *this;
    }

    const std::string& GetName() const {
        return name_;
    }

    u16 GetCount() const {
        return count_;
    }

    void SetName(const std::string& newName);
    // void SetName(std::string newName) {  // other realization
    //     name_ = std::move(newName);
    // }

    void SetCount(u16 newCount) {
        count_ = newCount;
    }

    friend std::ostream& operator<<(std::ostream& output, const Group& group) {
        if (group.GetCount()) {
            output << group.GetCount() << (group.GetCount() == 1 ? " person" : " people");
        } else {
            output << "No one";
        }

        return output << " study in group " << group.GetName() << ".\n";
    }

    friend std::istream& operator>>(std::istream& input, Group& group) {
        return input >> group.name_ >> group.count_;
        // Also can be realized using SetName and SetCount.
    }

private:
    std::string name_;
    u16 count_{};
};

void Group::SetName(const std::string& newName) {
    name_ = newName;
}


int main() {
    Group group("198");  // count_ == 0 as default
    std::cout << group;

    Group otherGroup(group);
    otherGroup.SetName("196");
    otherGroup.SetCount(28);
    std::cout << otherGroup;

    otherGroup = group;
    group.SetName("1912");
}
