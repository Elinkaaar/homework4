#include <iostream>
#include <memory>
void printReserve(const std::unique_ptr<int>& reserve)
{
    if (!reserve)
    {
        std::cout << "No reserve\n";
        return;
    }
    std::cout << "Reserve: " << *reserve << "%\n";
}
std::unique_ptr<int> makeReserve()
{
    return std::make_unique<int>(20);
}
int main()
{
    int battery{0};
    int flag{0};
    std::unique_ptr<int> reserve{};
    std::cout << "Battery (0-100): ";
    std::cin >> battery;
    std::cout << "Need reserve (0 or 1): ";
    std::cin >> flag;
    if (battery < 0 || battery > 100 || (flag != 0 && flag != 1))
    {
        std::cout << "Input error\n";
        return 1;
    }
    std::cout << "Battery: " << battery << "%\n";
    if (flag == 1)
    {
        reserve = makeReserve();
        if (battery + *reserve > 100)
        {
            std::cout << "Input error\n";
            return 1;
        }
        std::unique_ptr<int> target = std::move(reserve);
        std::cout << "After move source:\n";
        printReserve(reserve);
        std::cout << "After move target:\n";
        printReserve(target);
        std::cout << "Total: " << battery + *target << "%\n";
    }
    else
    {
        printReserve(reserve);
    }
    return 0;
}
