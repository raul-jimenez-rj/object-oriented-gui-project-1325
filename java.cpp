#include "java.h"

Java::Java(std::string name, double price, double cost, int darkness) : Product(name, price, cost), _darkness{darkness} {}

int Java::darkness()
{
    return _darkness;
}
std::vector<Shot> Java::shots()
{
    return _shots;
}

void Java::add_shot(Shot shot)
{
    return shots().push_back(shot);
}

std::string Java::to_string()
{
    std::string darkness_string;
    switch (darkness())
    {
    case (1):
        darkness_string = "Blonde";
        break;
    case (2):
        darkness_string = "Light";
        break;
    case (3):
        darkness_string = "Medium";
        break;
    case (4):
        darkness_string = "Dark";
        break;
    case (5):
        darkness_string = "Extra Dark";
        break;
    default:
        darkness_string = "Extra Dark";
        break;
    }
    std::string shots_string;
    std::vector<int> shot_quantity; //count how many of each shots are inputted
    for (int i{0}; i < shots().size(); ++i)
    {
        switch (shots()[i])
        {
        case (Shot::None):
            shot_quantity[0]++;
            break;
        case (Shot::Chocolate):
            shot_quantity[1]++;
            break;
        case (Shot::Vanilla):
            shot_quantity[2]++;
            break;
        case (Shot::Peppermint):
            shot_quantity[3]++;
            break;
        case (Shot::Hazelnut):
            shot_quantity[4]++;
            break;
        }
    }
    shots_string = "\n\t\tNone = " + std::to_string(shot_quantity[0]) +
                   "\n\t\tChocolate = " + std::to_string(shot_quantity[1]) +
                   "\n\t\tVanilla = " + std::to_string(shot_quantity[2]) +
                   "\n\t\tPeppermint = " + std::to_string(shot_quantity[3]) +
                   "\n\t\tHazelnut = " + std::to_string(shot_quantity[4]);

    return name() + " $" + std::to_string(price()) + " $" + std::to_string(cost()) +
           "\n\t Darkeness: " + darkness_string +
           "\n\t Shots: " + shots_string;
}