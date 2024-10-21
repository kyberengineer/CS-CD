#include <iostream>
class Location {
private:
    std::string country;
    std::string city;
    std::string address;
    std::string corp;
public:
    Location(std::string country, std::string city, std::string address, std::string corp)
        : country(std::move(country)),
          city(std::move(city)),
          address(std::move(address)),
          corp(std::move(corp)) {
    }

    [[nodiscard]] std::string country1() const {
        return country;
    }

    void set_country(std::string country) {
        this->country = std::move(country);
    }

    [[nodiscard]] std::string city1() const {
        return city;
    }

    void set_city(std::string city) {
        this->city = std::move(city);
    }

    [[nodiscard]] std::string address1() const {
        return address;
    }

    void set_address(std::string address) {
        this->address = std::move(address);
    }

    [[nodiscard]] std::string corp1() const {
        return corp;
    }

    void set_corp(std::string corp) {
        this->corp = std::move(corp);
    }
};

class AbsctractCluster {
private:
    std::string name;
    Location* location;
    int count{};

public:
    AbsctractCluster(std::string name, Location* location, const int count)
        : name(std::move(name)),
          location(location),
          count(count) {
    }

    [[nodiscard]] std::string name1() const {
        return name;
    }

    void set_name(std::string name) {
        this->name = std::move(name);
    }

    [[nodiscard]] Location* location1() const {
        return location;
    }

    void set_location(Location* location) {
        this->location = location;
    }

    [[nodiscard]] int count1() const {
        return count;
    }

    void set_count(const int count) {
        this->count = count;
    }
};

class AbsctractDrone {
private:
    std::string name;
    AbsctractCluster* cluster;
    float velocity = 0;
    float oX{}, oY{}, oZ{};

public:
    AbsctractDrone(std::string name, AbsctractCluster* cluster, const float velocity)
        : name(std::move(name)),
          cluster(cluster),
          velocity(velocity) {
    }

    [[nodiscard]] std::string name1() const {
        return name;
    }

    [[nodiscard]] AbsctractCluster* cluster1() const {
        return cluster;
    }

    [[nodiscard]] float velocity1() const {
        return velocity;
    }

    [[nodiscard]] float o_x() const {
        return oX;
    }

    [[nodiscard]] float o_y() const {
        return oY;
    }

    [[nodiscard]] float o_z() const {
        return oZ;
    }

    void set_name(std::string name) {
        this->name = std::move(name);
    }

    void set_cluster(AbsctractCluster* cluster) {
        this->cluster = cluster;
    }

    void set_velocity(const float velocity) {
        this->velocity = velocity;
    }

    void set_o_x(const float o_x) {
        oX = o_x;
    }

    void set_o_y(const float o_y) {
        oY = o_y;
    }

    void set_o_z(const float o_z) {
        oZ = o_z;
    }
};
int main() {
    auto location = new Location("Russia", "Moscow", "Arbatskaya Street, 1A", "1T");
    auto cluster = new AbsctractCluster("1T Drone Cluster", location, 0);
    auto droneA = new AbsctractDrone("Typical drone model", cluster, 0);
    cluster->set_count(1);
    droneA->set_velocity(0.75);

    std::cout << "Drone velocity is: " << droneA->velocity1() << std::endl;
    std::cout << "Drone maintainer is: " << droneA->cluster1()->location1()->corp1() << std::endl;

    // free memory we allocated
    delete location;
    delete cluster;
    delete droneA;
    // some change in the code
    return 0;
}