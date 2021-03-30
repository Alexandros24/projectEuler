#include <iostream>
#include <vector>

int main()
{
    const int grid_size = 20;
    std::vector< uint64_t > grid((grid_size+1)*(grid_size+1),1);

    for (int x = grid_size-1; 0 <= x ; x--) 
    {
        for (int y = grid_size-1; 0 <= y; y--) 
        {
        int pos = (y * (grid_size + 1)) + x;
        grid.at(pos) = grid.at(pos + 1) + grid.at(pos + (grid_size + 1));
        }
    }
  std::cout << "Answer: " << grid.at(0) << std::endl;
}
